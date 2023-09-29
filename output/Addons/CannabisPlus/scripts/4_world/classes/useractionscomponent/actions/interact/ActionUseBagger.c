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
		float BatterPercentUsed = GetCPConfig().WorkBench_PowerUsed / 100;
		//int BudsToBagsUsage = GetCPConfig().Buds_To_Bags_Required;
		int BagsToBricksUsage = 16; //GetCPConfig().Bags_To_Bricks_Required;
		float PlaticWrap_Percent = GetCPConfig().Plastic_Wrap_Usage;
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CP_Workbench Bench = CP_Workbench.Cast( target_object );
		CP_CannabisBud Buds = CP_CannabisBud.Cast( target_entity.GetAttachmentByType(CP_CannabisBud) );
		CP_CannabisBags Bags = CP_CannabisBags.Cast( target_entity.GetAttachmentByType(CP_CannabisBags) );
		CP_PlasticRoll Plastic = CP_PlasticRoll.Cast( target_entity.GetAttachmentByType(CP_PlasticRoll) );
		VehicleBattery Batteries = VehicleBattery.Cast( target_entity.GetAttachmentByType(VehicleBattery) );
		
		if(BatteryRequired == 1)
		{
			if (Bench && Bench.Bagger_Attachments() && Buds && Buds.GetQuantity() >= 2 /* BudsToBagsUsage */ && Batteries && Batteries.GetCompEM().GetEnergy() >= BatterPercentUsed && !Bench.IsRunning())
			{
				TendancyText = Bench.GetBagTendancyText();
				return true;
			
			}
			else if (Bench && Bench.Wrapper_Attachments() && Bags &&  Bags.GetQuantity() >= BagsToBricksUsage && Batteries && Batteries.GetCompEM().GetEnergy() >= BatterPercentUsed && !Bench.IsRunning()  )
			{
				if(Plastic && Plastic.GetQuantity() > PlaticWrap_Percent)
				{
					TendancyText = Bench.GetBrickTendancyText();
					return true;
				};
			};	
		}
		else if(BatteryRequired == 0)
		{
		
			if (Bench && Bench.Bagger_Attachments() && Buds && Buds.GetQuantity() >= 2 /* BudsToBagsUsage */ && !Bench.IsRunning() )
			{
				TendancyText = Bench.GetBagTendancyText();
				return true;
			}
			else if (Bench && Bench.Wrapper_Attachments() && Bags && Bags.GetQuantity() >= BagsToBricksUsage  && !Bench.IsRunning() )
			{
				if(Plastic && Plastic.GetQuantity() > PlaticWrap_Percent)
				{
					TendancyText = Bench.GetBrickTendancyText();
					return true;
				};
			}	
		}
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		//Bench.CreateBricks(Bench.GetWrapperTendancyCreationType())
		Bench.StartProcessing();
	};
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Filled " + action_data.m_Target.GetObject().GetDisplayName();
	}
};