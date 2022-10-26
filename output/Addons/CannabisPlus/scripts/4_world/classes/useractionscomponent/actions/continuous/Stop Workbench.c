class ActionStopCPWorkbenchCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2);
	}
};

class ActionStopCPWorkbench : ActionInteractBase
{

	void ActionStopCPWorkbench()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}
		
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}
		
    override string GetText()
	{
        return  "Stop Processing";
    };
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CP_Workbench Bench = CP_Workbench.Cast( target_object );
		
		if( Bench && Bench.RunningOrNot() == true)
		{
			return true;
		}
		
		return false;
	};

	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );

		Bench.CheckStopProductionCall();

	};
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Stoped " + action_data.m_Target.GetObject().GetDisplayName();
	}
};