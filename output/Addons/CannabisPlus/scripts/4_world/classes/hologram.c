modded class Hologram
{		
	override EntityAI PlaceEntity( EntityAI entity_for_placing )
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
		if (item_in_hands)
			return "CP_Workbench";
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
}	