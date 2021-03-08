class CP_Composter extends Container_Base
{

	bool m_IsLocked = false;
	EntityAI target;
	int CompostTick = 10000;   //tick checker every 10s to look for dry material
	int ProcessTime = 30000;  //2 mins to make compost
	int NumItems = 0;
	
      void CP_Composter()
	{
		Init();
	}
	
	void ~CP_Composter()
	{
		
	}
	
	void Init()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CheckCargoTick, CompostTick, true);
	}
	
	void CheckCargoTick()
	{
		CargoBase cargo = GetInventory().GetCargo();
		int NumPlantMaterial = 0;
		int NumRawPlant = 0;
		string ItemName;	
		ItemBase item;
		
		if (cargo != NULL && !m_IsLocked )
		{
			NumItems = 0;
			for (int i = 0; i < cargo.GetItemCount(); ++i)
			{
				if ( cargo.GetItemCount() != 0)
				{
					item = ItemBase.Cast(cargo.GetItem(i));
					ItemName  = item.GetType();
					if (ItemName.IndexOf("PlantMaterial") >= 0)
					{
						NumItems += 1;
						NumPlantMaterial += 1;
					} else if (ItemName.IndexOf("CP_Dried") >= 0)
					{
						NumItems += 1;
						NumRawPlant += 1;
					}
				}		
			}
		}
		if (NumItems >= GetCPConfig().PlantPerBag)
		//process compost if at least 9 material in bin
		{
			if (!m_IsLocked)
			{  
				ProcessCompost();
				Print("[CP] " + this + " processing compost with " + NumItems + " material");
			}	
		}
	
	}
	
	void ProcessCompost()
	{
		m_IsLocked = true;
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ProcessOutput, GetCPConfig().CompostTime*1000, false);	
	}
	
	void ProcessOutput()
	{
		vector output_position = this.GetPosition() + "-1 0 -1";
		string ItemName;
		ItemBase item;
		int j, NumCargo;
		
		if ( GetGame() && GetGame().IsServer() )
		{
			CargoBase cargo = GetInventory().GetCargo();
			NumCargo = cargo.GetItemCount();
			if (NumCargo >= 17)
			{
				for (j = 0; j < GetCPConfig().PlantPerBag; j++)
				{
					item = ItemBase.Cast(cargo.GetItem(j));
					if (item)
					{
						Print("[CP] " + this + " deleting " + item + " from compost bin");
						item.Delete();	
					}	
				}
				ItemBase output = ItemBase.Cast(GetGame().CreateObject("GardenLime", output_position, false ));
			}	
		}
		Syncronize();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(UnlockInventory, 1000, false);
	}
	
	void UnlockInventory()
	{
		m_IsLocked = false;
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);	
	}
	
	override bool CanPutIntoHands(EntityAI parent)
    	{
        	if ( m_IsLocked)
        	{
            	return false;
        	}
        	return super.CanPutIntoHands(parent);
    	}
	
	void Syncronize()
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
    
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}

}      