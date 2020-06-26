//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_Cigarette extends ItemBase
{	
	protected Particle m_SmokeParticle;
	
	protected ESmokeState m_CigSmokeState;
	protected ESmokeState m_LastCigSmokeState;
	
	vector m_ParticleLocalPos = Vector(0, 0.1, 0);
	protected int health;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_Cigarette() {
		m_CigSmokeState = ESmokeState.NOT_SMOKING;
		RegisterNetSyncVariableInt("health", 0, 100);
		RegisterNetSyncVariableInt("m_CigSmokeState", ESmokeState.NOT_SMOKING, ESmokeState.COUNT); //only 2 states, 0 and 1
	}

	void ~CP_Cigarette()
	{
		if (m_SmokeParticle)
			m_SmokeParticle.Stop();
	}
	
	void SetSmokingState (ESmokeState state) {
		if( GetGame().IsServer() ) {
			if ( m_CigSmokeState != state ) {
				m_CigSmokeState = state;				
				//synchronize
				SetSynchDirty();
			}
		}		
	}
	
	ESmokeState GetSmokingState() {
		return m_CigSmokeState;
	}
	
	void UpdateParticles() {
		ESmokeState state = GetSmokingState();
		
		if( m_LastCigSmokeState != state )
		{
			if (state == ESmokeState.SMOKING) {
				m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, m_ParticleLocalPos, Vector(0,0,0), true);
				m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 0.5);
				m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY, 0.5);
			} else if (state == ESmokeState.NOT_SMOKING) {
				m_SmokeParticle.Stop();
			}	
		}	
		m_LastCigSmokeState = state;
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
		AddAction(ActionSmokeCigSelf);	// add action to smoke the joint
	}
}








