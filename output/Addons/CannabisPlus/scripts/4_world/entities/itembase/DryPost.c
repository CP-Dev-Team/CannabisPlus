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
	
	void CP_DryPost()
	{
		if (RopeAttached && Plant1Attached && Plant2Attached && Plant3Attached ) 
		{
			StartDrying();
		}
	}
	
	void ~CP_DryPost()
	{
	}
	
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
			Print("[CP] all items attached to post...");
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
			StartDrying();
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

	void StartDrying()
	{	
		Print("[CP] starting to dry...");
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FinishDrying, DryingTime*1000, false);
	}

	void FinishDrying()
	{
		Print("[CP] finished drying...");
		NumPlants = 0;
		
		for ( int j = 0; j < GetInventory().AttachmentCount(); ++j )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			string ItemName  = attachment.GetType();
			if (ItemName.IndexOf("CP_Raw") >= 0)
			{
				NumPlants += 1;
				NewPlantName  = attachment.GetType();
				int rc = NewPlantName .Replace("Raw","Dried");
				Print("[CP] Deleting " + attachment);
				GetGame().ObjectDelete(attachment);
			}			
		}	
		SpawnDried();
		
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		/*if ( IsItemTypeAttached ( CP_RawSkunkCannabisPlant ) ) // Checks if plant is attached
		{
			GetGame().ObjectDelete(GetCannibisBase()); // Deletes RawCannabisPlant after function is started.
			GetInventory().CreateAttachment("CP_DriedSkunkCannabisPlant"); // Creates dried plant in output slot.			
			GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		}*/
	}
	
	void SpawnDried() 
	{
		for ( int i = 0; i < NumPlants; ++i )
		{
			Print("[CP] Creating " + NewPlantName);
			GetInventory().CreateAttachment(NewPlantName);
		}
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
