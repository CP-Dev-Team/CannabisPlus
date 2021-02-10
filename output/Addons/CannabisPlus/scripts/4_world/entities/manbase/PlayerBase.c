//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlayerBase {

	protected ref Timer 										swayTimer;				// timer that resets the values after the effect is over
	protected ref Timer 										jointTimer;				// timer that resets the values after the effect is over
	protected const string 										SMOKE_SOUND  = "Smoking_SoundSet";

	protected EffectSound                                     	m_TurnOff;
    protected EffectSound                                     	m_TurnOn;
	
	bool 														m_HasConsumedCigarette = false;	// has the player consumed a hole cigarette	
	int 														m_cigaretteValue;					// the quantity of the cigarette, what the player consumed
	
	bool 														m_HasConsumedJoint = false;
	int 														m_jointValue;						// the quantity of the cigarette, what the player consumed
	
	//getters for cig/joint smoke state
	bool HasConsumedJoint () {
		return m_HasConsumedJoint; 
	}

	bool HasConsumedCigarette () {
		return m_HasConsumedCigarette; 
	} 
	
	int GetJointCycles() {
		return m_jointValue;
	}
	
	override void Init()
	{
		super.Init();
		
		//Reset effects on player spawn.
		//CameraEffects.changeHue(60);
		//CameraEffects.changeRadBlurXEffect(0);
		//CameraEffects.changeRadBlurYEffect(0);
		//CameraEffects.setExposure(60);
		//CameraEffects.changeRotationBlurPower(0);
		//CameraEffects.changeVignette(0);
		//CameraEffects.changeChromaX(0);
		//CameraEffects.changeChromaY(0);
		
		RegisterNetSyncVariableInt("m_jointValue");
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToCigaretteValue(int value) {
		if (GetCPConfig()) {	
			if(GetCPConfig().activateCigaretteSmokingEffect) {
				m_cigaretteValue += value;
						
				if(m_cigaretteValue >= GetCPConfig().cigaretteCyclesToActivateEffect){
					//Print("[CP] Smoking cigarrette effect" + GetDayZGame().GetCannabisPlusConfig().cigaretteCyclesToActivateEffect);
					m_HasConsumedCigarette = true;
					if (!swayTimer) { swayTimer = new Timer()};
					swayTimer.Stop();
					swayTimer.Run(GetCPConfig().smokingCigaretteEffectDuration, this, "ResetCigaretteValues", null, false);				
				}
			}
		}		
	}	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToJointValue(int value) {	
		if (GetCPConfig()) {	
			if(GetCPConfig().activateJointSmokingEffect) {
				//Print("[CP] CannabisPlus: AddValueToJointValue");
				m_jointValue += value;
						
				if((m_jointValue % GetCPConfig().jointCyclesToActivateEffect) == 0){	
					//Print("[CP] Smoking joint effect " + GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect);
					//Print("[CP] CannabisPlus: Starting Effect");			
					m_HasConsumedJoint = true;
					CannabisEffectsTriggered(m_jointValue);
					if (!jointTimer) { jointTimer = new Timer()};
					jointTimer.Stop();
					jointTimer.Run(GetCPConfig().smokingJointEffectDuration, this, "ResetJointValues", null, false);				
				}
				SetSynchDirty();
			}
		}
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// called by timer if the effect is over, resets all values that the player "consume again"
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void ResetCigaretteValues() {		
		m_cigaretteValue = 0;
		m_HasConsumedCigarette = false;
		swayTimer.Stop();
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// called by timer if the effect is over, resets all values that the player "consume again"
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void ResetJointValues() {
		m_HasConsumedJoint = false;
		CannabisEffectsTriggeredOff();
		m_jointValue = 0;
		jointTimer.Stop();
		SetSynchDirty();
	}
	
	// Cannabis Visual Effect On.
    void CannabisEffectsTriggered(int cycles)
    { 
	  float multiplier;
	  int counter;			
		
	  counter = cycles / GetCPConfig().jointCyclesToActivateEffect;
	  multiplier = 1 + (0.25 * counter);


        if(GetGame().IsClient())
        {
            //Reset effects on player before adding new ones.
            //CameraEffects.changeHue(60);
            //CameraEffects.changeRadBlurXEffect(0);
            //CameraEffects.changeRadBlurYEffect(0);
            //CameraEffects.changeRotationBlurPower(0);
            
            CameraEffects.changeHue(GetCPConfig().weedHueIntensity-counter);
			CameraEffects.changeRadBlurXEffect(GetCPConfig().weedRadBlurXPower*multiplier);
           	CameraEffects.changeRadBlurYEffect(GetCPConfig().weedRadBlurYPower*multiplier);
           	CameraEffects.changeRotationBlurPower(GetCPConfig().weedRotBlurPow*multiplier);
        }	
	  PlaySoundSet(m_TurnOn, SMOKE_SOUND, 0.0, 0.0);	

    }

    // Cannabis Effects Triggered Off.
    void CannabisEffectsTriggeredOff()
    {

        if(GetGame().IsClient())
        {
            CameraEffects.changeHue(60);
            CameraEffects.changeRadBlurXEffect(0);
            CameraEffects.changeRadBlurYEffect(0);
            CameraEffects.changeRotationBlurPower(0);	
        }
    }
}