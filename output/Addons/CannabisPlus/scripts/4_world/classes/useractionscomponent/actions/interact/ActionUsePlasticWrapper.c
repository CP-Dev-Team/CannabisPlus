class ActionUsePlasticWrapper: ActionInteractBase
{	
	void ActionUsePlasticWrapper()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	};
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return  TendancyText;
    };

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CP_Workbench Bench = CP_Workbench.Cast( target_object );
		CP_CannabisBags Bags = CP_CannabisBags.Cast( target_entity.GetAttachmentByType(CP_CannabisBags) );
		
		if (Bench && Bench.Wrapper_Attached() && Bench.IsPowered() && Bags.GetQuantity() >= 1 )
		{
			TendancyText = Bench.GetBrickTendancyText()
			return true;
		}
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		Bench.CreateBricks();

	};
};
