//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class JointBase extends Edible_Base {
	static int m_SmokeState = 0;
	static Particle m_SmokeParticle;
	PortableGasLampLight m_light;	
	PlayerBase player;
	vector m_ParticleLocalPos = Vector(0.1, 0.5, 0);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void JointBase() {
		PlayerBase.m_IsJointEffectActivated 	= CannabisPlus.getInstance().GetConfig().activateJointSmokingEffect;
		PlayerBase.m_smokingJointEffectDuration = CannabisPlus.getInstance().GetConfig().smokingJointEffectDuration;
		PlayerBase.m_jointsToActivateEffect 	= CannabisPlus.getInstance().GetConfig().jointsToActivateEffect;

		Init();
	}

	void Init() {
		SetSmokingState(0);
		UpdateVisuals();
	}

	void ~JointBase()
	{
		Print("[DEBUG] ~JointBase")
		if (m_SmokeParticle) {
		 	m_SmokeParticle.Stop();
		 }
	}
	override void OnConsume(float amount, PlayerBase consumer) {
		super.OnConsume(amount, consumer);
		Print("[DEBUG] JointBase:OnConsume")
		if(CannabisPlus.getInstance().GetConfig().activateJointSmokingEffect)
			consumer.AddValueToJointValue(amount);

		if(this.GetQuantity() <= 0.0) 
			SetSmokingState(0);
			UpdateVisuals();
			//possibly add delay for particle to stop before joint is deleted
			GetGame().ObjectDelete(this);
			Print("[DEBUG] JointBase:OnConsume Delete Object")
	}		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void UpdateVisuals() {
        super.UpdateVisuals();
        switch(m_SmokeState) {
            case 0:
				StopParticle();              
                break;
            case 1:
				if(!GetGame().IsServer()  ||  !GetGame().IsMultiplayer()) {
					m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, m_ParticleLocalPos, Vector(0,0,0), true);
				}
                break;				
        }
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// stops particle effect and disable the light/glow effect while player consume the joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void StopParticle() {
		 if (m_SmokeParticle) {
		 	Print("[DEBUG] Turning off smoke particle")
			m_SmokeParticle.Stop();
			m_SmokeParticle.Delete();
		 } 	
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		
	void SetSmokingState(int state_number) {
		m_SmokeState = state_number;	
	}
	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);	// add action to smoke the joint
	}
}