class CP_DryPost extends Container_Base
{	
	bool m_IsLocked = false;
	ref Timer m_PlantDryTime;
	float DryingTime = 15.0;
	bool RopeAttached = false;
	bool Plant1Attached = false;
	bool Plant2Attached = false;
	bool Plant3Attached = false;
	int NumPlants;
	string NewPlantName 
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
	        
		if (slot_name == "Rope")
		{    				
			SetAnimationPhase ("Rope", 0);  // Shows the rope on the model when rope is attached.+
			RopeAttached = true;
		} else if (slot_name == "HangingPlants") 
		{
			Plant1Attached = true;
		} else if (slot_name == "HangingPlants2") 
		{
			Plant2Attached = true;
		} else if (slot_name == "HangingPlants3") 
		{
			Plant3Attached = true;
		}
		if (RopeAttached && Plant1Attached && Plant2Attached && Plant3Attached ) 
		{	
			CheckStart();
		}		
	}
    
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (slot_name == "Rope")
		{    				
			SetAnimationPhase ("Rope", 1);  // Shows the rope on the model when rope is attached.+
			RopeAttached = false;
		} else if (slot_name == "HangingPlants") 
		{
			Plant1Attached = false;
		} else if (slot_name == "HangingPlants2") 
		{
			Plant2Attached = false;
		} else if (slot_name == "HangingPlants3") 
		{
			Plant3Attached = false;
		}	
	}
	
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		return false;
    	}
	
	CP_RawSkunkCannabisPlant  GetCannibisBase()
    	{
      	return CP_RawSkunkCannabisPlant.Cast( GetAttachmentByType (CP_RawSkunkCannabisPlant) );
    	};
	
	void CheckStart()
	{
		for ( int k = 0; k < GetInventory().AttachmentCount(); k++ )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( k ) );
			string ItemName  = attachment.GetType();
			if (ItemName.IndexOf("CP_Raw") >= 0)
			{
				NumPlants += 1;
			}	
		}	
		
		if (NumPlants==3)
		{
			Print("[CP] all items attached to post...starting to dry");
			//GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FinishDrying, DryingTime*1000, false);
			m_IsLocked = true;
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
	
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( m_IsLocked )
		{
			return false;
		}
		return super.CanReceiveAttachment(attachment, slotId);
	}	

	override bool CanPutIntoHands(EntityAI parent)
    	{
        	if( !super.CanPutIntoHands( parent ) )
        	{
            	return false;
        	}
        	if ( GetNumberOfItems() == 0 )
        	{
            	return false;
        	}
        	return true;
    	}

	void FinishDrying()
	{
		Print("[CP] finished drying...");
		//GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		int NumItems = GetInventory().AttachmentCount();
		
		for ( int j = 0; j < NumItems; j++ )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			string ItemName  = attachment.GetType();
			if (ItemName.IndexOf("CP_Raw") >= 0)
			{
				NewPlantName  = attachment.GetType();
				int rc = NewPlantName .Replace("Raw","Dried");
				Print("[CP] Deleting " + attachment);
				GetGame().ObjectDelete(attachment);
				
			}			
		}			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnDried, 1000, false);
	}
	
	void SpawnDried() 
	{
		for ( int i = 0; i < NumPlants; i++ )
		{
			this.GetInventory().CreateAttachment(NewPlantName);
			//this.GetInventory().CreateInInventory(NewPlantName);
			Print("[CP] Creating " + NewPlantName);
		}
		NumPlants = 0;
		m_IsLocked = false;
	}

	override void OnPlacementStarted( Man player )
    	{
        	super.OnPlacementStarted( player );
        
            SetAnimationPhase ("Rope", 0);  // Shows the rope on the model when rope is attached.
    	}
	
	override string GetPlaceSoundset()
	{
		return "woodenlog_drop_SoundSet";
	}
    
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}
