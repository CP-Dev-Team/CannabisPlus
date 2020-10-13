modded class GardenBase extends BuildingSuper
{
	// Plants the seed into slot (selection_component)
	override void PlantSeed( ItemBase seed, string selection_component )
	{
		int slot_index = GetSlotIndexBySelection( selection_component );
		
		if ( slot_index != -1 )
		{
			PluginHorticulture module_horticulture = PluginHorticulture.Cast( GetPlugin( PluginHorticulture ) );
			string plant_type = module_horticulture.GetPlantType( seed );
			
			Slot slot = m_Slots.Get( slot_index );
			slot.SetState(Slot.STATE_PLANTED);
			slot.m_PlantType = plant_type;
			slot.SetSeed(seed);
			slot.SetSlotComponent(selection_component);
			
/*			if ( !slot.NeedsWater() )
 *			{
 *				CreatePlant(slot);
 *			}
 */
 		}
	}
};