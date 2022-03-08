class ActionCPUseBagger: ActionInteractBase
{	
	void ActionCPUseBagger()
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
		int BatteryRequired = GetCPConfig().RequireBattery;
		
		
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CP_Workbench Bench = CP_Workbench.Cast( target_object );
		CP_CannabisBud Buds = CP_CannabisBud.Cast( target_entity.GetAttachmentByType(CP_CannabisBud) );
		VehicleBattery Batteries = VehicleBattery.Cast( target_entity.GetAttachmentByType(VehicleBattery) );
		
		if(BatteryRequired == 1)
		{
		
			if (Bench && Bench.Bagger_Attachments() &&  Buds.GetQuantity() >= 2 && Batteries && Batteries.GetCompEM().GetEnergy() >= 10 && !Bench.RunningOrNot())
			{
				TendancyText = Bench.GetBagTendancyText();
				return true;
			}
		}
		else if(BatteryRequired == 0)
		{
		
			if (Bench && Bench.Bagger_Attachments() &&  Buds.GetQuantity() >= 2)
			{
				TendancyText = Bench.GetBagTendancyText();
				return true;
			}
		}
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		//Bench.CreateBricks(Bench.GetWrapperTendancyCreationType())
		Bench.start_processing();

	};
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Filled " + action_data.m_Target.GetObject().GetDisplayName();
	}
};