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
	string NewPlantName;
	ref map<string, int> BudSpawn;
	
	void CP_DryPost()
	{
		BudSpawn = new map<string, int>;
		BudSpawn.Clear();
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
			//Print("[CP] all items attached to post...starting to dry");
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

	override bool CanPutIntoHands(EntityAI parent)
    	{
        	if ( m_IsLocked || GetNumberOfItems() > 0 )
        	{
            	return false;
        	}
        	return super.CanPutIntoHands(parent);
    	}
	
	void AddToMap(string item, int value)
	{
		private int CurrentValue;
		
		if (BudSpawn.Find(item,CurrentValue))
		{
			//get current value, remove and re-add with updated value
			CurrentValue = CurrentValue + value;
			BudSpawn.Remove(item);
			BudSpawn.Insert(item,value);
				
		} else {		
			BudSpawn.Insert(item,value);
		}	
	}

	void FinishDrying()
	{
		//Print("[CP] finished drying...");
		int NumItems = GetInventory().AttachmentCount();
		
		for ( int j = 0; j < NumItems; j++ )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			string ItemName  = attachment.GetType();
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
						GetGame().ObjectDelete(attachment);	
						break;
					// cannabis blue
					case "CP_RawBlueCannabisPlant":
						CP_RawBlueCannabisPlant blueplant = CP_RawBlueCannabisPlant.Cast(attachment);
						if (blueplant)
						{
							AddToMap("CP_CannabisBlue",	blueplant.GetYield());
						}	
						GetGame().ObjectDelete(attachment);
						break;
					// cannabis kush
					case "CP_RawKushCannabisPlant":
						CP_RawKushCannabisPlant kushplant = CP_RawKushCannabisPlant.Cast(attachment);
						if (kushplant)
						{
							AddToMap("CP_CannabisKush",	kushplant.GetYield());
						}
						GetGame().ObjectDelete(attachment);	
						break;
					// cannabis Stardawg
					case "CP_RawStardawgCannabisPlant":
						CP_RawStardawgCannabisPlant stardawgplant = CP_RawStardawgCannabisPlant.Cast(attachment);
						if (stardawgplant)
						{ 
							AddToMap("CP_CannabisStardawg",	stardawgplant.GetYield());
						}
						GetGame().ObjectDelete(attachment);	
						break;
					// cannabis Future
					case "CP_RawFutureCannabisPlant":
						CP_RawFutureCannabisPlant futureplant = CP_RawFutureCannabisPlant.Cast(attachment);
						if (futureplant)
						{ 
							AddToMap("CP_CannabisFuture",	futureplant.GetYield());
						}
						GetGame().ObjectDelete(attachment);	
						break;
					// cannabis S1
					case "CP_RawS1CannabisPlant":
						CP_RawS1CannabisPlant s1plant = CP_RawS1CannabisPlant.Cast(attachment);
						if (s1plant)
						{ 
							AddToMap("CP_CannabisS1",	s1plant.GetYield());
						}
						GetGame().ObjectDelete(attachment);	
						break;
					// cannabis Nomad
					case "CP_RawNomadCannabisPlant":
						CP_RawNomadCannabisPlant nomadplant = CP_RawNomadCannabisPlant.Cast(attachment);
						if (nomadplant)
						{ 
							AddToMap("CP_CannabisNomad",	nomadplant.GetYield());
						}	
						GetGame().ObjectDelete(attachment);
						break;
					// cannabis BlackFrost
					case "CP_RawBlackFrostCannabisPlant":
						CP_RawBlackFrostCannabisPlant bfplant = CP_RawBlackFrostCannabisPlant.Cast(attachment);
						if (bfplant)
						{
							AddToMap("CP_CannabisBlackFrost",	bfplant.GetYield());
						}
						GetGame().ObjectDelete(attachment);	
						break;
					default:
						break;
			}			
		}			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnDried, 1000, false);
		//SpawnDried();
	}
	
	void SpawnDried() 
	{
		for ( int i = 0; i < NumPlants; i++ )
		{
			this.GetInventory().CreateAttachment("CP_DriedCannabisPlant");
			//Print("[CP] Creating CP_DriedCannabisPlant");
		}
		Print("[CP] The BudSpawn has " + BudSpawn.Count() + " items");
		vector pos = this.GetPosition();
		for (i = 0; i < BudSpawn.Count(); i++)
		{
			string key = BudSpawn.GetKey(i);
			Print("[CP] BudSpawn[" + i + "] is " + key);
			for (int j = 0; j < BudSpawn.Get(key); j++)
			{
				ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( BudSpawn.GetKey(i), pos, ECE_PLACE_ON_SURFACE ) );
			}
		}
		NumPlants = 0;
		m_IsLocked = false;
		BudSpawn.Clear();
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
