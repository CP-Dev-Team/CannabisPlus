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
		//CP_Workbench parent = CP_Workbench.Cast(Wrapper.GetParent());
		CP_CannabisBud Buds = CP_CannabisBud.Cast( target_entity.GetAttachmentByType(CP_CannabisBud) );
		
		if (Bench && Bench.IsPowered() && Buds.GetQuantity() >= 20 )
		{
			TendancyText = Bench.GetBrickTendancyText()
			return true;
		}
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		//Bench.CreateBricks(Bench.GetWrapperTendancyCreationType())
		Bench.CreateBricks();

	};
};
