class CP_DryPost extends ItemBase
{	
	bool m_IsLocked = false;
	bool RopeAttached = false;
	bool Plant1Attached = false;
	bool Plant2Attached = false;
	bool Plant3Attached = false;
	int NumPlants;
	int NumItems;
	string ItemName;
	string NewPlantName;
	ref map<string, int> BudSpawn;
	EntityAI target;
	protected float Lock;
	
	autoptr array<int> plant_slots = new array<int>;

	void CP_DryPost()
	{
		BudSpawn = new map<string, int>;
		
		plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants2")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants3")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants4")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants5")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants6")); 
	}
	
	bool IsLocked()
	{
		return m_IsLocked;
	}
	
	override void EEInit()
	{
		super.EEInit();
		m_IsLocked = false;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;

		// During active drying, block new attachments in hanging plant slots.
		if (m_IsLocked)
		{
			for (int i = 0; i < plant_slots.Count(); i++)
			{
				if (plant_slots.Get(i) == slotId)
					return false;
			}
		}
		
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return true;
	}
	
	void AssemblePost()
	{
		if (!IsHologram())
		{
			Rope rope = Rope.Cast(GetInventory().CreateAttachment("Rope"));
		}
	}
	void CreateRope(Rope rope)
	{
		if (!rope)
			return;
		
		InventoryLocation targetLoc = rope.GetTargetLocation();
		if (targetLoc && targetLoc.GetType() != InventoryLocationType.GROUND)
		{
			MiscGameplayFunctions.TransferItemProperties(this, rope);
			return;
		}
		
		EntityAI newRope = EntityAI.Cast(GetGame().CreateObjectEx(rope.GetType(), GetPosition(), ECE_PLACE_ON_SURFACE));
		
		if (newRope)
			MiscGameplayFunctions.TransferItemProperties(this, newRope);
		
		rope.Delete();
	}
	void DisassemblePosts(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase stick = ItemBase.Cast(GetGame().CreateObjectEx("WoodenLog",GetPosition(),ECE_PLACE_ON_SURFACE));
			stick.SetQuantity(1);
			MiscGameplayFunctions.TransferItemProperties(this, stick);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (slot_name == "Rope")
		{    				
			SetAnimationPhase ("Rope", 0);
			RopeAttached = true;
		} 
		if (slot_name == "DriedPlantPile")
		{    				
			SetAnimationPhase ("DryPile", 0);
		}

		if (GetGame() && GetGame().IsClient())		
			LockRope();
	}
    
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (slot_name == "Rope")
		{    				
			SetAnimationPhase ("Rope", 1);  // Hides the rope on the model when rope is attached.
			RopeAttached = false;
		}
		if (slot_name == "DriedPlantPile")
		{    				
			SetAnimationPhase ("DryPile", 1);  // Shows the Pile when dried cannbis is put in dryed slot
		}
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if ( player && player.IsPlayerDisconnected() )
			return;
		
		if (item && slot_name == "Rope" && GetGame().IsServer())
		{
			// Delay disassembly so rope swap operations can complete first.
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(HandleRopeDetachedServer, 1, false, ItemBase.Cast(item));
		}
		CPDebugPrint("EEItemDetached: LockRope");
		if (GetGame() && GetGame().IsClient())
			LockRope();
	}

	void HandleRopeDetachedServer(ItemBase detachedRope)
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		// If rope is present again, this was a swap/replace; do not disassemble.
		if (FindAttachmentBySlotName("Rope"))
			return;

		if (detachedRope)
			DisassembleKit(detachedRope);

		Delete();
	}
	
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		return false;
	};

	CP_DriedCannabisPlant GetCannabisDried()
    {
		return CP_DriedCannabisPlant.Cast( GetAttachmentByType (CP_DriedCannabisPlant) );
    }
	
	void CheckStart()
	{
		if (!GetGame().IsServer())
			return;
		
		if (!m_IsLocked)	
		{
			NumPlants = 0;
			for ( int k = 0; k < GetInventory().AttachmentCount(); k++ )
			{
				ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( k ) );
				if (!attachment)
					continue;
				ItemName  = attachment.GetType();
				if (ItemName.IndexOf("CP_Raw") >= 0)
				{
					NumPlants += 1;
				}	
			}	
			
			if (NumPlants>=1)
			{
				CPDebugPrint("all items attached to post " + this + " ...starting to dry");
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FinishDrying, GetCPConfig().TimeToDryCannabisPlant*1000, false);
				m_IsLocked = true;
				LockDryingSlots(true);
			}
		}		
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if ( m_IsLocked )
		{
			return false;
		}
		return super.CanReleaseAttachment(attachment);
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	};
	
	void AddToMap(string item, int value)
	{
		int CurrentValue = 0;
		int NewValue = 0;
		
		if (value < 1)
		{
			NewValue = 1;
		} else
		{
			NewValue = value;
		}	
		
 		if (BudSpawn.Find(item,CurrentValue))
		{
			//get current value, remove and re-add with updated value
			NewValue += CurrentValue;
			BudSpawn.Remove(item);
			BudSpawn.Insert(item,NewValue);
				
		} else {		
			BudSpawn.Insert(item,NewValue);
		}	
	}

	void FinishDrying()
	{
		CPDebugPrint("finished drying...");
		NumItems = GetInventory().AttachmentCount();
		LockDryingSlots(true);
		for ( int j = 0; j < NumItems; j++ )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			if (!attachment)
				continue;
			ItemName  = attachment.GetType();
			// To cast and get the amount of bud to spawn before deleting
			if (ItemName.IndexOf("CP_Raw") >= 0 && ItemName.IndexOf("CannabisPlant") >= 0)
			{
				// Extract strain name from ItemName (e.g., "Skunk" from "CP_RawSkunkCannabisPlant")
				string strainName = ItemName.Substring(6, ItemName.Length() - 19); // Remove "CP_Raw" (6 chars) and "CannabisPlant" (13 chars)
				CPDebugPrint("Extracted strain name for drying: " + strainName);

				if (g_CannabisStrainConfigs.Contains(strainName))
				{
					CP_RawPlantBase plant = CP_RawPlantBase.Cast(attachment);
					if (plant)
					{
						string driedType = "CP_Cannabis" + strainName;
						AddToMap(driedType, plant.GetYield());
						CPDebugPrint("Added to map: " + driedType + " with yield: " + plant.GetYield());
					}
					else
					{
						CPDebugPrint("Warning: Failed to cast attachment to CP_RawPlantBase for: " + ItemName);
					}
				}
				else
				{
					CPDebugPrint("Warning: Strain config for '" + strainName + "' not found. Skipping drying for: " + ItemName);
				}
			}
		}			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnDried, 500, false, GetPosition() );
	}
	
	void SpawnDried() 
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			CPDebugPrint("The plant has " + BudSpawn.Count() + " items");
			
			for ( int j = 0; j < BudSpawn.Count(); j++)
			{
				string key = BudSpawn.GetKey(j);
				CPDebugPrint("plant[" + j + "] is " + key + " with quantity " + BudSpawn.Get(key));
				int StackMax;
				StackMax = GetGame().ConfigGetInt("CfgVehicles " + key + " varStackMax");
				int stacks = Math.Floor(BudSpawn.Get(key) / StackMax);
				int remainder = BudSpawn.Get(key) - (stacks * StackMax);
				CPDebugPrint("" + this + " spawning " + stacks + " stacks" );
				CPDebugPrint("" + this + " spawning " + remainder + " singles" );
				for ( int k = 0; k <= stacks; k++)
				{
					CP_CannabisBud weed = CP_CannabisBud.Cast(this.GetInventory().CreateInInventory(key)); 					
					if (stacks == 0)  //less than 1 stack, break out of for
					{
						weed.SetQuantity(remainder);
						break;
					}
					else if ( k == stacks) // last stack	
					{
						weed.SetQuantity(remainder);
					} else 
					{
						weed.SetQuantity(StackMax);	
					}
				}
			}  	
		}	
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CleanUp, 500, false);
		LockDryingSlots(false);
    }
	

    void CleanUp()
	{	
		if ( GetGame() && GetGame().IsServer() )
		{
			NumItems = GetInventory().AttachmentCount();
			for ( int i = NumItems - 1; i >= 0; i-- )
			{
				ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( i ) );
				if (!attachment)
					continue;
				ItemName = attachment.GetType();
	            	if (ItemName.IndexOf("CP_Raw") >= 0)
		            {
					CPDebugPrint("deleting " + attachment);
					GetGame().ObjectDelete(attachment);	
				}	
	        }
	
			NumPlants = 0;
			BudSpawn.Clear();
		}
		LockDryingSlots(false);
		m_IsLocked = false;	
		synchronize();	
	}
	
	void synchronize()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}

	override string GetPlaceSoundset()
	{
		return "woodenlog_drop_SoundSet";
	}

    void LockRope()
    {
        Rope rope = Rope.Cast(GetAttachmentByType(Rope));

        if ( GetInventory().GetCargo().GetItemCount() > 0 || GetInventory().AttachmentCount() > 1 )
        {
            if (rope)
            {
                CPDebugPrint("LockRope: True");
                rope.LockToParent();
            } 

        }
        else if (rope)
        {
            CPDebugPrint("LockRope: False");
            rope.UnlockFromParent();
        }
    }
		
	override void EECargoIn(EntityAI item)
	{		
		super.EECargoIn(item);
		
		LockRope();
	}

	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);
		
		LockRope();
	}
	
	void LockDryingSlots(bool do_lock)
    {
		ItemBase item;
		
        if (do_lock)
        {
            for (int p = 0; p < plant_slots.Count(); p++)
            {
                if (Class.CastTo(item, GetInventory().FindAttachment(plant_slots.Get(p) )))
                {
                      item.LockToParent();  // ToDo: Need to lock ALL slots by SlotID, not just occupied slots.  See Issue#20
                }
            }
        }
        else
        {
            for (int j = 0; j < plant_slots.Count(); j++)
            {
                if (Class.CastTo(item, GetInventory().FindAttachment(plant_slots.Get(j) )))
                {
                      item.UnlockFromParent(); // ToDo: I don't think this is the right function.  >> Ice: I agree.  Can't UnlockFromParent since the RawCannabisPlant is deleted and thus you can't have a "Parent" of nothing.  Need to unlock by slotID.
                }
            }
        }
    };
	void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase Log = ItemBase.Cast(GetGame().CreateObjectEx("WoodenLog",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, Log);
			Log.SetQuantity(1);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDryPlants);
	}
}

class CP_DryPost_Kit extends ItemBase
{	
	protected bool m_SuppressRopeDetachDisassemble;

	override void EEInit()
	{
		super.EEInit();

		if (GetGame() && GetGame().IsServer())
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( AssembleKit );
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;
		
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return true;
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================	
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0"  )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			CP_DryPost Dry_Post = CP_DryPost.Cast( GetGame().CreateObjectEx( "CP_DryPost", position, ECE_PLACE_ON_SURFACE ) );
			if (!Dry_Post)
				return;
			
			Dry_Post.SetPosition( position );
			Dry_Post.SetOrientation( orientation );
			TransferRopeToPlacedPost( Dry_Post );
			
			//make the kit invisible, then delete it next frame so the deploy action can finish cleanly
			HideAllSelections();
			SetIsDeploySound( true );
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DeleteKit, 0, false);
		}	
	}

	void DeleteKit()
	{
		Delete();
	}

	override void OnPlacementStarted( Man player )
    	{
        	super.OnPlacementStarted( player );
        
		SetAnimationPhase ("Rope", 0);  // Shows the rope on the model when rope is attached.
    	}

	override string GetPlaceSoundset()
	{
		return "seachest_drop_SoundSet";
	}
	
	override bool IsDeployable()
	{
		return true;
	}

	override bool DoPlacingHeightCheck()
	{
		return false;
	}
	override float HeightCheckOverride()
	{
		return 20;
	}
	void TransferRopeToPlacedPost(CP_DryPost dry_post)
	{
		if (!dry_post)
			return;

		Rope rope = Rope.Cast(FindAttachmentBySlotName("Rope"));
		if (!rope)
		{
			dry_post.GetInventory().CreateAttachment("Rope");
			return;
		}

		m_SuppressRopeDetachDisassemble = true;

		int rope_slot = InventorySlots.GetSlotIdFromString("Rope");
		if (rope_slot != InventorySlots.INVALID && ServerTakeEntityToTargetAttachmentEx(dry_post, rope, rope_slot))
			return;

		// Fallback: create new rope on the post, delete the old one
		Rope placed_rope = Rope.Cast(dry_post.GetInventory().CreateAttachment("Rope"));
		if (placed_rope)
		{
			MiscGameplayFunctions.TransferItemProperties(rope, placed_rope);
			rope.Delete();
		}
	}

	void AssembleKit()
	{
		if (IsHologram())
			return;

		if (FindAttachmentBySlotName("Rope"))
			return;

		GetInventory().CreateAttachment("Rope");
	}
	void CreateRope(Rope rope)
	{
		if (!rope)
			return;
		
		InventoryLocation targetLoc = rope.GetTargetLocation();
		if (targetLoc && targetLoc.GetType() != InventoryLocationType.GROUND)
		{
			MiscGameplayFunctions.TransferItemProperties(this, rope);
			return;
		}
		
		EntityAI newRope = EntityAI.Cast(GetGame().CreateObjectEx(rope.GetType(), GetPosition(), ECE_PLACE_ON_SURFACE));
		
		if (newRope)
			MiscGameplayFunctions.TransferItemProperties(this, newRope);
		
		rope.Delete();
	}
	void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase Log = ItemBase.Cast(GetGame().CreateObjectEx("WoodenLog",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, Log);
			Log.SetQuantity(1);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
    {
		super.EEItemDetached( item, slot_name );

		if (m_SuppressRopeDetachDisassemble && slot_name == "Rope")
			return;
		
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if ( player && player.IsPlayerDisconnected() )
			return;
		
		if (item && slot_name == "Rope" && GetGame().IsServer())
		{
			// Delay disassembly so rope swap operations can complete first.
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(HandleKitRopeDetachedServer, 1, false, ItemBase.Cast(item));
		}
	}

	void HandleKitRopeDetachedServer(ItemBase detachedRope)
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		// If rope is present again, this was a swap/replace; do not disassemble.
		if (FindAttachmentBySlotName("Rope"))
			return;

		if (detachedRope)
			DisassembleKit(detachedRope);

		Delete();
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
		
	}
}