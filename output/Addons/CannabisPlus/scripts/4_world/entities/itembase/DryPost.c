class CP_DryPost extends ItemBase
{	
	bool m_IsLocked = false;
	ref Timer m_PlantDryTime;
	bool RopeAttached = false;
	bool Plant1Attached = false;
	bool Plant2Attached = false;
	bool Plant3Attached = false;
	int NumPlants;
	int NumItems;
	string ItemName
	string NewPlantName;
	ref map<string, int> BudSpawn;
	ItemBase attachment;
	int i, j, k, p, dp
	EntityAI target
	protected float Lock;
	
	autoptr array<int> plant_slots = new array<int>;

	void CP_DryPost()
	{
		BudSpawn = new map<string, int>;
		BudSpawn.Clear();
		
		plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants2")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants3")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants4")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants5")); 
        plant_slots.Insert(InventorySlots.GetSlotIdFromString("HangingPlants6")); 
	}
	
	void ~CP_DryPost()
	{
		
		
	}
	bool IsLocked()
	{
		return m_IsLocked;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( AssemblePost );
		m_IsLocked = false;
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
			SetAnimationPhase ("Rope", 0);  // Shows the rope on the model when rope is attached.
			RopeAttached = true;
		} 
		if (slot_name == "DriedPlantPile")
		{    				
			SetAnimationPhase ("DryPile", 0);  // Shows the Pile when dried cannbis is put in dryed slot
		}
		if(item.IsKindOf("CP_RawPlantBase") && !item.IsKindOf("CP_DriedCannabisPlant"))
		{
			dp++;
			//Print("dp = " + dp);
		}
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
		
		if (item && slot_name == "Rope")
		{
			if (GetGame().IsServer())
			{
				DisassembleKit(ItemBase.Cast(item));
				Delete();
			}
		}
		if(item.IsKindOf("CP_RawPlantBase") && !item.IsKindOf("CP_DriedCannabisPlant"))
		{
			if(dp > 0)
			{
				dp--;
			}
			else if (dp < 0)
			{
			  dp = 0;
			}
			//Print("dp = " + dp);
		}
		LockRope();
	}
	
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		return false;
	};
	
	CP_RawSkunkCannabisPlant  GetCannabisBase()
    {
		return CP_RawSkunkCannabisPlant.Cast( GetAttachmentByType (CP_RawSkunkCannabisPlant) );
    };
	CP_DriedCannabisPlant  GetCannabisDried()
    {
		return CP_DriedCannabisPlant.Cast( GetAttachmentByType (CP_DriedCannabisPlant) );
    };
	
	void CheckStart()
	{
		if (!m_IsLocked)	
		{
			for ( k = 0; k < GetInventory().AttachmentCount(); k++ )
			{
				attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( k ) );
				ItemName  = attachment.GetType();
				if (ItemName.IndexOf("CP_Raw") >= 0)
				{
					NumPlants += 1;
				}	
			}	
			
			if (NumPlants>=1)
			{
				//Print("[CP] all items attached to post " + this + " ...starting to dry");
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FinishDrying, GetCPConfig().cannabis_drytime*1000, false);
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
		private int CurrentValue = 0;
		private int NewValue = 0;
		
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
		//Print("[CP] finished drying...");
		NumItems = GetInventory().AttachmentCount();
		LockDryingSlots(true);
		for ( j = 0; j < NumItems; j++ )
		{
			attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			ItemName  = attachment.GetType();
			//code to cast and get the amount of bud to spawn before deleting
			//plant                        Bud 
			//CP_RawSkunkCannabisPlant     CP_CannabisSkunk
			if (ItemName.IndexOf("CP_Raw") >= 0)
				switch(ItemName){
				      // cannabis skunk
					case "CP_RawSkunkCannabisPlant":
						CP_RawSkunkCannabisPlant skunkplant = CP_RawSkunkCannabisPlant.Cast(attachment);
						if (skunkplant)
						{
							AddToMap("CP_CannabisSkunk",	skunkplant.GetYield());

						}
						break;
					// cannabis blue
					case "CP_RawBlueCannabisPlant":
						CP_RawBlueCannabisPlant blueplant = CP_RawBlueCannabisPlant.Cast(attachment);
						if (blueplant)
						{
							AddToMap("CP_CannabisBlue",	blueplant.GetYield());
						}	
						break;
					// cannabis kush
					case "CP_RawKushCannabisPlant":
						CP_RawKushCannabisPlant kushplant = CP_RawKushCannabisPlant.Cast(attachment);
						if (kushplant)
						{
							AddToMap("CP_CannabisKush",	kushplant.GetYield());
						}
						break;
					// cannabis Stardawg
					case "CP_RawStardawgCannabisPlant":
						CP_RawStardawgCannabisPlant stardawgplant = CP_RawStardawgCannabisPlant.Cast(attachment);
						if (stardawgplant)
						{ 
							AddToMap("CP_CannabisStardawg",	stardawgplant.GetYield());
						}
						break;
					// cannabis Future
					case "CP_RawFutureCannabisPlant":
						CP_RawFutureCannabisPlant futureplant = CP_RawFutureCannabisPlant.Cast(attachment);
						if (futureplant)
						{ 
							AddToMap("CP_CannabisFuture",	futureplant.GetYield());
						}
						break;
					// cannabis S1
					case "CP_RawS1CannabisPlant":
						CP_RawS1CannabisPlant s1plant = CP_RawS1CannabisPlant.Cast(attachment);
						if (s1plant)
						{ 
							AddToMap("CP_CannabisS1",	s1plant.GetYield());
						}
						break;
					// cannabis Nomad
					case "CP_RawNomadCannabisPlant":
						CP_RawNomadCannabisPlant nomadplant = CP_RawNomadCannabisPlant.Cast(attachment);
						if (nomadplant)
						{ 
							AddToMap("CP_CannabisNomad",	nomadplant.GetYield());
						}	
						break;
					// cannabis BlackFrost
					case "CP_RawBlackFrostCannabisPlant":
						CP_RawBlackFrostCannabisPlant bfplant = CP_RawBlackFrostCannabisPlant.Cast(attachment);
						if (bfplant)
						{
							AddToMap("CP_CannabisBlackFrost",	bfplant.GetYield());
						}
						break;
					default:
						break;
			}			
		}			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnDried, 500, false);
	}
	
	void SpawnDried() 
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			NumItems = GetInventory().AttachmentCount();
			
			for (i = 0; i < NumItems; i++ )
			{
		        attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( i ) );
		        ItemName = attachment.GetType();
				if (ItemName.IndexOf("CP_Raw") >= 0)
		        {
					// spawn plant material for now 
					ItemBase plant = ItemBase.Cast(GetGame().CreateObjectEx("PlantMaterial",GetPosition(),ECE_PLACE_ON_SURFACE));

				}    
			}
			
			
			
			/*
			if( dp >= 1)
			{
				if ( GetCannabisDried() )
				{
					//GetIn	ventory().CreateAttachment("CP_DriedCannabisPlant");
					GetCannabisDried().AddQuantity( dp );
					//Print("[CP] " + this + " spawning "+ CP_DriedCannabisPlant );

					//Print("Created Dried plant = " + dp);
						
					dp = 0;
				} else {
					GetInventory().CreateAttachment("CP_DriedCannabisPlant");
					GetCannabisDried().SetQuantity( dp );
					//Print("[CP] " + this + " spawning "+ CP_DriedCannabisPlant );

					//Print("Created Dried plant = " + dp);
						
					dp = 0;

				}
			}
			*/
			//Print("[CP] The plant has " + BudSpawn.Count() + " items");
			
			for (j = 0; j < BudSpawn.Count(); j++)
			{
				string key = BudSpawn.GetKey(j);
				//Print("[CP] plant[" + j + "] is " + key + " with quantity " + BudSpawn.Get(key));
				int StackMax;
				StackMax = GetGame().ConfigGetInt("CfgVehicles " + key + " varStackMax");
				int stacks = Math.Floor(BudSpawn.Get(key) / StackMax);
				int remainder = BudSpawn.Get(key) - (stacks * StackMax);
				//Print("[CP] " + this + " spawning " + stacks + " stacks" );
				//Print("[CP] " + this + " spawning " + remainder + " singles" );
				for (k = 0; k <= stacks; k++)
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
			for ( i = 0; i < NumItems; ++i )
			{
				attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( i ) );
				ItemName = attachment.GetType();
	            	if (ItemName.IndexOf("CP_Raw") >= 0)
		            {
					//Print("[CP] deleting " + attachment);
					GetGame().ObjectDelete(attachment);	
				}	
	        }
	
			NumPlants = 0;
			BudSpawn.Clear();
		}
		LockDryingSlots(false);
		m_IsLocked = false;	
		syncronize();	
	}
	
	void syncronize()
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
                rope.LockToParent();
            } 

		}
		else if (rope)
		{
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
	override void EEInit()
	{
		super.EEInit();
		
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
			PlayerBase player_base = PlayerBase.Cast( player );

			CP_DryPost Dry_Post = CP_DryPost.Cast( GetGame().CreateObjectEx( "CP_DryPost", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			
			Dry_Post.SetPosition( position);
			Dry_Post.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			this.Delete();
			SetIsDeploySound( true );
		}	
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
	void AssembleKit()
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
	void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase Log = ItemBase.Cast(GetGame().CreateObjectEx("WoodenLog",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, Log);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}
	override void EEItemDetached(EntityAI item, string slot_name)
    {
		super.EEItemDetached( item, slot_name );
		
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if ( player && player.IsPlayerDisconnected() )
			return;
		
		if (item && slot_name == "Rope")
		{
			if (GetGame().IsServer())
			{
				DisassembleKit(ItemBase.Cast(item));
				Delete();
			}
		}
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
		
	}
}