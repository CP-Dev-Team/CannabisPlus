modded class Hologram
{		
	EntityAI PlaceEntity( EntityAI entity_for_placing )
	{
		if ( entity_for_placing.IsInherited( CP_Workbench_Kit ))
		{
			return entity_for_placing;
		}
		
		return super.PlaceEntity(entity_for_placing);
	}

	override string GetProjectionName(ItemBase item)
	{
		CP_Workbench_Kit item_in_hands = CP_Workbench_Kit.Cast( item );
		return super.GetProjectionName(item);
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{			
		ItemBase item_in_hands = m_Parent;

		if ( item_in_hands.IsInherited(CP_Workbench_Kit))
		{
			SetIsColliding(false);
			return;
		}
		super.EvaluateCollision();
	}
	
	override void RefreshVisual()
	{
		if ( m_Projection && m_Projection.IsKindOf("CP_Workbench"))
		{
			string config_material = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterial";
			string hologram_material = GetGame().ConfigGetTextOut( config_material );
			string config_model = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterialPath";
			string hologram_material_path = GetGame().ConfigGetTextOut( config_model ) + "\\" + hologram_material;
			string selection_to_refresh;
			int hidden_selection = 0;
			static const string textureName = "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)";
			
			string config_path = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hiddenSelections";
			ref array<string> hidden_selection_array = new array<string>;

			GetGame().ConfigGetTextArray( config_path, hidden_selection_array );	
			hologram_material_path += CorrectMaterialPathName();
				
			for (int i = 0; i < hidden_selection_array.Count(); ++i)
			{
				selection_to_refresh = hidden_selection_array.Get(i);
				hidden_selection = GetHiddenSelection( selection_to_refresh );
				m_Projection.SetObjectTexture( hidden_selection, textureName );
				m_Projection.SetObjectMaterial( hidden_selection, hologram_material_path );
			}
		}
		else
		{
			super.RefreshVisual();
		}
		
	}
}	