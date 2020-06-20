//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_JointBase extends ItemBase {

	static Particle m_SmokeParticle;
	vector m_ParticleLocalPos = Vector(0, 0.1, 0);
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
		 	m_SmokeParticle.Stop();
		    m_SmokeParticle = null;  
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
			//Print("[DEBUG] CP_JointBase:StartSmoking");
			m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, m_ParticleLocalPos, Vector(0,0,0), true);
		} 
		SetSynchDirty();
	}

	void StopSmoking() {
		//Print("[DEBUG] CP_JointBase:StopSmoking");
		if (m_SmokeParticle && (!GetGame().IsServer()  ||  !GetGame().IsMultiplayer()))
		  m_SmokeParticle.Stop();
		  //m_SmokeParticle.Delete(); 
		SetSynchDirty();  	
	}

	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);	// add action to smoke the joint
	}
}