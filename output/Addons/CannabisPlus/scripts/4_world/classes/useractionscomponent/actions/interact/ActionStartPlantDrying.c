class ActionDryPlants: ActionInteractBase
{	
	void ActionDryPlants()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#Leave to Dry";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CP_DryPost DryingPost = CP_DryPost.Cast( target.GetObject() );
		
		if(DryingPost && DryingPost.CanStart())
		{
			return true;
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		CP_DryPost DryingProcess = CP_DryPost.Cast( action_data.m_Target.GetObject() );
		DryingProcess.StartDrying();
	}
}