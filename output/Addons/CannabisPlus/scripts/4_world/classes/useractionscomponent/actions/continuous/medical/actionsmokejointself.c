class ActionSmokeJointSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		//m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.MEASURE_TEMP);
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
};

class ActionSmokeJointSelf: ActionContinuousBase
{
	void ActionSmokeJointSelf()
	{
		m_CallbackClass = ActionSmokeJointSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{		
        return "Smoke Joint";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		Thermometer thermometer = Thermometer.Cast(action_data.m_MainItem);
		
		if(thermometer)
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(thermometer.GetTemperatureMessage(action_data.m_Player));
			rpc.Send(action_data.m_Player, ERPCs.RPC_SYNC_THERMOMETER, true, action_data.m_Player.GetIdentity() );
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};