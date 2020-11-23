//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum ESmokeState {
	NOT_SMOKING = 0 
	SMOKING = 1
	COUNT = 2 
}

class CP_JointBase extends ItemBase {

	protected Particle m_SmokeParticle;
	
	protected ESmokeState m_JointSmokeState;
	protected ESmokeState m_LastJointSmokeState;
	
	vector m_ParticleLocalPos = Vector(0, 0.2, 0);
	protected int health;
	
	void CP_JointBase() {							
		m_JointSmokeState = ESmokeState.NOT_SMOKING;
		RegisterNetSyncVariableInt("health", 0, 100);
		RegisterNetSyncVariableInt("m_JointSmokeState", ESmokeState.NOT_SMOKING, ESmokeState.COUNT); //only 2 states, 0 and 1
	}

	void ~CP_JointBase() {
		if (m_SmokeParticle)
			m_SmokeParticle.Stop();
	};
	
	void SetSmokingState (ESmokeState state) {
		if( GetGame().IsServer() ) {
			if ( m_JointSmokeState != state ) {
				m_JointSmokeState = state;				
				//synchronize
				SetSynchDirty();
			}
		}		
	}
	
      ESmokeState GetSmokingState() {
		return m_JointSmokeState;
	}
	
	void MakeStoned(PlayerBase player)
	{
		//Print("[CP] Stoned modifier " + player.GetModifiersManager().IsModifierActive(99) + " on player: " + player);
		
		player.GetModifiersManager().AddModifier(new StonedMdfr);
		
		if( player.GetModifiersManager().IsModifierActive(99) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier(99);
		}
		player.GetModifiersManager().ActivateModifier(99);
	}
	
	void UpdateParticles() {
		ESmokeState state = GetSmokingState();
		
		if( m_LastJointSmokeState != state )
		{
			if (state == ESmokeState.SMOKING) {
				m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, m_ParticleLocalPos, Vector(0,0,0), true);
			} else if (state == ESmokeState.NOT_SMOKING) {
				m_SmokeParticle.Stop();
			}	
		}	
		m_LastJointSmokeState = state;
	}
	
	override void AfterStoreLoad() {
		super.AfterStoreLoad();

		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            	health = GetHealth();
		}
		Synchronize();			
	}
	
	void Synchronize() {
	      if (GetGame().IsServer()) 
			SetSynchDirty();
	  }
	
	void SetSynchronizedHealth(int amount) {
		if (GetGame().IsServer())
			health = amount;
	      	SetSynchDirty();
	}
	
	int GetSynchronizedHealth() {
		return health;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		UpdateParticles();
	}

	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);	// add action to smoke the joint
	}
}