
class JointBase extends Edible_Base {
	
	static PortableGasLampLight m_light;
	static int m_SmokeState = 0;
	static Particle m_SmokeParticle;
	PlayerBase player;
	
		
	void JointBase() {
		RegisterNetSyncVariableInt("m_SmokeState");
	}
	
	
	override void EEDelete(EntityAI parent)	{
		super.EEDelete(parent);
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() ){
			if ( m_SmokeParticle )
				m_SmokeParticle.Stop();
		}
		m_SmokeParticle.Stop();
	}
	
	
	override void OnVariablesSynchronized() {
		super.OnVariablesSynchronized();
		Print("!!!!!!!!!!!!!!!! OnVariablesSynchronized");
		UpdateVisuals();
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnConsume(float amount, PlayerBase consumer) {
		Print("!!!!!!!!!!!!!!!! OnConsume");
		
		super.OnConsume(amount, consumer);
	
		if(CannabisPlus.getInstance().GetConfig().activateJointSmokingEffect){
			consumer.AddValueToJointValue(amount);
		}

		if(this.GetQuantity() <= 0.0) {
			GetGame().ObjectDelete(this);
			StopParticle();
		}		
		UpdateVisuals();
	}
		
	
	override void UpdateVisuals()
    {
        super.UpdateVisuals();
		Print("!!!!!!!!!!!!! Update Visuals");
		
        switch(m_SmokeState) {
            case 0:
                StopParticle();
				Print("!!!!!!!!!!!!! Stop Particles");
                break;

            case 1:
				if(!m_SmokeParticle) {
					Print("!!!!!!!!!!!!! Start Particles");
					m_SmokeParticle = Particle.PlayOnObject(ParticleList.JOINT_SMOKE, this, Vector(0, 0, 0));
				}
				if(this.GetQuantity() <= 0.0) {
					SetSmokingState(0);
				}
                break;				
        }
	}
		
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// stops particle effect and disable the light/glow effect while player consume the joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void StopParticle() {		
		m_SmokeParticle.Stop();
	}	

		
	override void OnWork(float consumed_energy) {		
		Print("ON WORK");
	}
		
	
	override void OnWorkStart() {
		Print("ON WORK START");
		SetSmokingState(1);
		UpdateVisuals();		
	}

	
	override void OnWorkStop() {
		Print("ON WORK STOP");
		SetSmokingState(0);
		UpdateVisuals();
	}
	
	
	void SetSmokingState(int state_number) {
		m_SmokeState = state_number;
	}	
}