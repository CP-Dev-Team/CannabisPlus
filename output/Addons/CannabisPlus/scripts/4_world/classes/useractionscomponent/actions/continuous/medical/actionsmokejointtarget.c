class ActionSmokeJointTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.MEASURE_TEMP);	
	}
};

class ActionSmokeJointTarget : ActionContinuousBase
{
	void ActionSmokeJointTarget()
	{
		m_CallbackClass = ActionMeasureTemperatureTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAGTARGET;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
		
	override string GetText()
	{
		return "Let pull on Joint";
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		Thermometer thermometer = Thermometer.Cast(action_data.m_MainItem);

		if(thermometer)
		{
			ntarget.SetLastUAMessage(thermometer.GetTemperatureMessage(ntarget));
		}
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		Thermometer thermometer = Thermometer.Cast(action_data.m_MainItem);
		
		if(thermometer)
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(thermometer.GetTemperatureMessage(ntarget));
			rpc.Send(ntarget, ERPCs.RPC_SYNC_THERMOMETER, true, ntarget.GetIdentity() );
		}
	}
};