class JointBase : Edible_Base {
	
	// member variable to get access on particle effect	
	Particle m_SmokeParticle;
	// member variable to get access on light emitter
	static PortableGasLampLight m_light;
	
	PlayerBase player;	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// spawn particle effect related to player position
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	protected bool PlayParticle(out Particle particle, int particle_type, vector local_pos) {
		
		// as long as the joint has 'quantity' (quantity is configured in config file) , smoking is allowed
		if(this.GetQuantity() > 0.0) {
			
			// get reference to player object
			//PlayerBase player = action_data.m_Player;
			
			if(!particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient())) {
				//m_SmokeParticle.OnCheckAutoDelete();
				//m_SmokeParticle.SetLifetime(5000);
				particle = Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, Vector(0, 0, 0));
				particle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 0.01);
				particle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY, 0.03);
				
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
				
				return true;
			}			
		}
		return false;
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// stops particle effect and disable the light/glow effect while player consume the joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool StopParticle(out Particle particle) {
				
		if(particle && GetGame() && (!GetGame().IsMultiplayer() || GetGame().IsClient())){
		
			particle.Stop();
			particle = null;		
			m_light.SetEnabled(false);		
			GetGame().ObjectDelete(m_light);
			return true;
		}
		return false;
	}
}