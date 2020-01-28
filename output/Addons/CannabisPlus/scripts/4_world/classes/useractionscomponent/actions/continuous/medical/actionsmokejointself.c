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
	
	override void OnStartAnimationLoop(ActionData action_data) {

		//assuming 'this' is your gun object
		//vector worldSmokePos = this.ModelToWorld( GetMemoryPointPos("smokestart") );
 		//m_SmokeParticle = Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, worldSmokePos, Vector(0,0,0), true);

		super.OnStartAnimationLoop(action_data);

		Print("RAUCHPARTIKEL STARTEN");

		//Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, Vector(0, 0, 0), Vector(0, 0, 0), true);

		//Print("SMOKESTART: " + action_data);
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

	override void OnExecuteClient( ActionData action_data ) {

		super.OnExecuteClient( action_data );
		SpwanSmokeParticle( action_data );
	}

	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer( action_data );
		
		if ( !GetGame().IsMultiplayer() ) // Only in singleplayer
		{
			SpwanSmokeParticle( action_data );
		}
	}

	void SpwanSmokeParticle( ActionData action_data ) {

		PlayerBase player = action_data.m_Player;
		Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, player);
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