modded class CAContinuousFertilizeGardenSlot : CAContinuousQuantity
{
	override void Setup( ActionData action_data )
	{
		if ( Class.CastTo(target_GB,  action_data.m_Target.GetObject() ) )
		{
			m_SpentQuantity = 0;
			m_StartQuantity = action_data.m_MainItem.GetQuantity();
			
			if ( !m_SpentUnits )
			{
				m_SpentUnits = new Param1<float>(0);
			}
			else
			{	
				m_SpentUnits.param1 = 0;
			}
			
			if ( action_data.m_MainItem ) 
				m_ItemQuantity = action_data.m_MainItem.GetQuantity();
			
			if ( target_GB ) 
			{
				/*string selection = target_GB.GetActionComponentName(action_data.m_Target.GetComponentIndex());
			
				Slot slot = target_GB.GetSlotBySelection( selection );*/
			
				array<string> selections = new array<string>;
				target_GB.GetActionComponentNameList(action_data.m_Target.GetComponentIndex(), selections);
	
				for (int s = 0; s < selections.Count(); s++)
				{
					//string selection = selections[s];
					m_Selection = selections[s];
					m_Slot = target_GB.GetSlotBySelection( m_Selection );
					if (m_Slot)
						break;
				}
				
				string item_type = action_data.m_MainItem.GetType();
				float consumed_quantity = GetGame().ConfigGetFloat( "cfgVehicles " + item_type + " Horticulture ConsumedQuantity" );
				//float action_length = GetGame().ConfigGetFloat( "cfgVehicles " + item_type + " Horticulture FertilizeLength" );
				float action_length;

				if (item_type == "PlantMaterial") 
				{
					action_length = GetCPConfig().GetGeneralConfig().PlantMaterialUsage;
				} 
				else if (item_type == "GardenLime") 
				{
					action_length = GetCPConfig().GetGeneralConfig().GardenLimeUsage;
				}
				
				if (action_length == 0)
					action_length = 1;
				
				m_Slot.SetFertilizerQuantityMax(consumed_quantity);
				m_AlreadyFilledAmount = m_Slot.GetFertilizerQuantity();
				m_SlotFertilizerNeed = consumed_quantity - m_AlreadyFilledAmount;
			}

			float defaultTimeComplete = consumed_quantity/m_QuantityUsedPerSecond;
			float speedMultiplier = defaultTimeComplete / action_length;
			m_QuantityUsedPerSecond *= speedMultiplier;
		}
	}
};