//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_Cigarette extends Edible_Base
{	
	static int m_SmokeState = 0;
	static Particle m_SmokeParticle;
	PortableGasLampLight m_light;	
	PlayerBase player;
	vector m_ParticleLocalPos = Vector(0.1, 0.5, 0);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_Cigarette() {		
		// set values from config to the player		
		PlayerBase.m_IsSmokeEffectActivated 		= CannabisPlus.getInstance().GetConfig().activateCigaretteSmokingEffect;
		PlayerBase.m_smokingCigaretteEffectDuration = CannabisPlus.getInstance().GetConfig().smokingCigaretteEffectDuration;
		PlayerBase.m_cigarettesToActivateEffect 	= CannabisPlus.getInstance().GetConfig().cigarettesToActivateEffect;
		
		RegisterNetSyncVariableInt("m_SmokeState");
	}
	void Init() {
		SetSmokingState(0);
		UpdateVisuals();
	}

	void ~CP_Cigarette()
	{
		Print("[DEBUG] ~CP_Cigarette")
		if (m_SmokeParticle) {
		 	m_SmokeParticle.Stop();
		 }
	}
	override void OnConsume(float amount, PlayerBase consumer) {
		super.OnConsume(amount, consumer);
		Print("[DEBUG] CP_Cigarette:OnConsume")
		if(CannabisPlus.getInstance().GetConfig().activateCigaretteSmokingEffect)
			//consumer.AddValueToJointValue(amount);

		if(this.GetQuantity() <= 0.0) 
			SetSmokingState(0);
			UpdateVisuals();
			GetGame().ObjectDelete(this);
			Print("[DEBUG] CP_Cigarette:OnConsume Delete Object")
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
		AddAction(ActionSmokeCigSelf);	// add action to smoke the joint
	}
}








