
modded class ActionDeployObject
{
	override void OnEndServer(ActionData action_data)
	{
	      if( !action_data || !action_data.m_MainItem )
			return;
			
	      PlaceObjectActionData poActionData;
	      poActionData = PlaceObjectActionData.Cast(action_data);
	      if (!poActionData.m_AlreadyPlaced)
	      {
			EntityAI entity_for_placing = action_data.m_MainItem;
		    GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
		    action_data.m_MainItem.SetIsBeingPlaced(false);
	        
			if (GetGame().IsMultiplayer())
			{
				action_data.m_Player.PlacingCancelServer();
				action_data.m_MainItem.SoundSynchRemoteReset();
			}
			else
			{
				action_data.m_Player.PlacingCancelLocal();
				action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
			}
			GetGame().ClearJuncture( action_data.m_Player, action_data.m_MainItem );
            } else {
	            action_data.m_MainItem.SetIsDeploySound(false);
	            action_data.m_MainItem.SetIsPlaceSound(false);
	            action_data.m_MainItem.SoundSynchRemoteReset();
			if ( action_data.m_MainItem.IsKindOf( "CP_Workbench_Kit" )) {
				action_data.m_MainItem.Delete();
			} else {				
				super.OnEndServer(action_data);
			}
		}
	}
}
