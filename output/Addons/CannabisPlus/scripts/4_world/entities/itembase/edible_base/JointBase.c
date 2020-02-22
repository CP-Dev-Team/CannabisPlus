class JointBase : Edible_Base {
	
	// member variable to get access on particle effect	
	static Particle m_SmokeParticle = null;	
	// member variable to get access on light emitter
	static PortableGasLampLight m_light;
	
	PlayerBase player;	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// spawn particle effect related to player position
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void SpwanSmokeParticle() {
		
		// as long as the joint has 'quantity' (quantity is configured in config file) , smoking is allowed
		if(this.GetQuantity() > 0.0) {
			
			// get reference to player object
			//PlayerBase player = action_data.m_Player;
			
			if(!GetGame().IsMultiplayer() || GetGame().IsClient()) {
				//m_SmokeParticle.OnCheckAutoDelete();
				//m_SmokeParticle.SetLifetime(5000);
				m_SmokeParticle = Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, Vector(0, 0.0, 0));
				m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 0.01);
				m_SmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY, 0.03);
				
				// spwan light stuff
				m_light = PortableGasLampLight.Cast(ScriptedLightBase.CreateLight( PortableGasLampLight, this.GetPosition()));
				m_light.FadeIn(2.0);
				m_light.SetFadeOutTime(1.0);				
				m_light.SetDiffuseColor(0.85,0.5,0.23);
				m_light.SetRadiusTo(1);
				m_light.SetBrightnessTo(2.0);
				//m_light.AttachOnObject(action_data.m_MainItem);
				m_light.AttachOnObject(player);
				m_light.SetEnabled(true);
			}			
		}
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// stops particle effect and disable the light/glow effect while player consume the joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void StopSmokeParticle() {		
		Print("Method: - StopSmokeParticle");
		// stop the particle effect
		this.m_SmokeParticle.Stop();
		this.m_SmokeParticle = null;
		// try to delete the object self
		//GetGame().ObjectDelete(this.m_SmokeParticle);
		// disable the light - it does have no effect in som cases
		m_light.SetEnabled(false);
		// delete the ligth-gameobject. If don´t delete the light is still visible after conume the joint
		GetGame().ObjectDelete(m_light);
	}
}