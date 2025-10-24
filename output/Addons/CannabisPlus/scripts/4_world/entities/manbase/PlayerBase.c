modded class PlayerBase {

	protected ref Timer swayTimer; // timer that resets the values after the effect is over
	protected ref Timer jointTimer; // timer that resets the values after the effect is over
	protected const string SMOKE_SOUND  = "Smoking_SoundSet";

	protected EffectSound m_TurnOff;
    protected EffectSound m_TurnOn;
	
	bool m_HasConsumedCigarette = false;	// has the player consumed a hole cigarette	
	int m_cigaretteValue;					// the quantity of the cigarette, what the player consumed
	
	bool m_HasConsumedJoint = false;
	int m_jointValue;						// the quantity of the cigarette, what the player consumed
	
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
	
	override void Init() {
		super.Init();		
		RegisterNetSyncVariableInt("m_jointValue");
	}
	
	// set to true if the player consumed a cigarette
	void AddValueToCigaretteValue(int value) {
		if (GetCPConfig()) {	
			if(GetCPConfig().activateCigaretteSmokingEffect) {
				m_cigaretteValue += value;
						
				if(m_cigaretteValue >= GetCPConfig().cigaretteCyclesToActivateEffect){
					CPDebugPrint("Smoking cigarrette effect" + GetCPConfig().cigaretteCyclesToActivateEffect);
					m_HasConsumedCigarette = true;
					if (!swayTimer) { swayTimer = new Timer()};
					swayTimer.Stop();
					swayTimer.Run(GetCPConfig().smokingCigaretteEffectDuration, this, "ResetCigaretteValues", null, false);				
				}
			}
		}		
	}	
	// set to true if the player consumed a joint
	void AddValueToJointValue(int value, string strainName = "") {
		if (GetCPConfig()) {
			if(GetCPConfig().activateJointSmokingEffect) {
				CPClientDebugPrint("CannabisPlus: AddValueToJointValue");
				m_jointValue += value;

				if((m_jointValue % GetCPConfig().jointCyclesToActivateEffect) == 0){
					CPClientDebugPrint("jointCyclesToActivateEffect " + GetCPConfig().jointCyclesToActivateEffect);
					CPClientDebugPrint("CannabisPlus: Starting Effect");
					m_HasConsumedJoint = true;
					CannabisEffectsTriggered(m_jointValue, strainName);
					if (!jointTimer) { jointTimer = new Timer()};
					jointTimer.Stop();
					jointTimer.Run(GetCPConfig().smokingJointEffectDuration, this, "ResetJointValues", null, false);
				}
				SetSynchDirty();
			}
		}
	}
	// called by timer if the effect is over, resets all values that the player "consume again"
	void ResetCigaretteValues() {		
		m_cigaretteValue = 0;
		m_HasConsumedCigarette = false;
		swayTimer.Stop();
	}
	// called by timer if the effect is over, resets all values that the player "consume again"
	void ResetJointValues() {
		m_HasConsumedJoint = false;
		CannabisEffectsTriggeredOff();
		m_jointValue = 0;
		jointTimer.Stop();
		SetSynchDirty();
	}
	
	// Cannabis Visual Effect On.
	void CannabisEffectsTriggered(int cycles, string strainName = "")
	{
		float multiplier;
		int counter;

		counter = cycles / GetCPConfig().jointCyclesToActivateEffect;
		multiplier = 1 + (0.25 * counter);

		if(GetGame().IsClient())
		{
			CPClientDebugPrint("CannabisEffectsTriggered counter: " + counter + " multiplier: " + multiplier + " strain: " + strainName);

			CannabisStrainConfig strainConfig = g_ClientCannabisStrainConfigs.Get(strainName);
			if (strainConfig && strainConfig.WeedEffects)
			{
				CPClientDebugPrint("Applying weed effects for strain: " + strainName + " - Hue: " + strainConfig.WeedEffects.HueIntensity + " RadX: " + strainConfig.WeedEffects.RadBlurXPower + " RadY: " + strainConfig.WeedEffects.RadBlurYPower + " Rot: " + strainConfig.WeedEffects.RotBlurPow);

				CameraEffects.changeHue(strainConfig.WeedEffects.HueIntensity - counter);
				CameraEffects.changeRadBlurXEffect(strainConfig.WeedEffects.RadBlurXPower * multiplier);
				CameraEffects.changeRadBlurYEffect(strainConfig.WeedEffects.RadBlurYPower * multiplier);
				CameraEffects.changeRotationBlurPower(strainConfig.WeedEffects.RotBlurPow * multiplier);
			}
			else
			{
				CPClientDebugPrint("Strain config not found or WeedEffects null for strain: " + strainName);
			}
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