//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_JointBase extends ItemBase {

	static Particle m_SmokeParticle;
	vector m_ParticleLocalPos = Vector(0, 0.5, 0);
	protected int health;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_JointBase() {
		RegisterNetSyncVariableInt("health", 0, 100);
	}

	void ~CP_JointBase()
	{
		Print("[DEBUG] ~CP_JointBase")
		if (m_SmokeParticle) {
		 	StopSmoking();
		 }
	}

	override void AfterStoreLoad() {
        super.AfterStoreLoad();

        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            health = GetHealth();
        }
        Synchronize();
    }

	void Synchronize() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        SetSynchDirty();
    }

	void SetSynchronizedHealth(int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        health = amount;
        SetSynchDirty();
    }

    int GetSynchronizedHealth() {
        return health;
    }

	void StartSmoking() {
		if(!m_SmokeParticle && (!GetGame().IsServer()  ||  !GetGame().IsMultiplayer())) {
			Print("[DEBUG] CP_JointBase:StartSmoking");
			m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, m_ParticleLocalPos, Vector(0,0,0), true);
			m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 1.5);
			m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY, 0.8);
		}
	}

	void StopSmoking() {
		Print("[DEBUG] CP_JointBase:StopSmoking");
		if (m_SmokeParticle && (!GetGame().IsServer()  ||  !GetGame().IsMultiplayer()))
		  m_SmokeParticle.Stop();
		  m_SmokeParticle.Delete(); 	
	}

	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);	// add action to smoke the joint
	}
}