class ActionCPResumeAndPause: ActionInteractBase
{	
	void ActionCPResumeAndPause()
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
		CP_CannabisBud Buds = CP_CannabisBud.Cast( target_entity.GetAttachmentByType(CP_CannabisBud) );
		VehicleBattery Batteries = VehicleBattery.Cast( target_entity.GetAttachmentByType(VehicleBattery) );
		
		if (Bench && Bench.IsRunning())
		{
			TendancyText = Bench.GetPauseOrResumeText();
			return true;
		}
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		//Print("Action Process " + Bench.IsRunning());
		//Print(TendancyText);
		Bench.PauseOrResume();
	};
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Filled " + action_data.m_Target.GetObject().GetDisplayName();
	}
};