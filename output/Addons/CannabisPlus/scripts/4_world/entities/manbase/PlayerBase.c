modded class PlayerBase {

	protected ref Timer jointTimer; // timer that resets the values after the effect is over
	protected const string SMOKE_SOUND  = "Smoking_SoundSet";

	protected EffectSound m_TurnOff;
    protected EffectSound m_TurnOn;
	
	bool m_HasConsumedJoint = false;
	int m_jointValue;						// the quantity of the joint, what the player consumed
	
	//getters for joint smoke state
	bool HasConsumedJoint () {
		return m_HasConsumedJoint; 
	}
	
	int GetJointCycles() {
		return m_jointValue;
	}
	
	override void Init() {
		super.Init();		
		RegisterNetSyncVariableInt("m_jointValue");
	}
	
	// set to true if the player consumed a joint
	void AddValueToJointValue(int value, string strainName = "") {
		if (GetCPConfig()) {
			if(GetCPConfig().ActivateJointSmokingEffect) {
				CPClientDebugPrint("CannabisPlus: AddValueToJointValue");
				m_jointValue += value;

				if((m_jointValue % GetCPConfig().JointCyclesToActivateEffect) == 0){
					CPClientDebugPrint("JointCyclesToActivateEffect " + GetCPConfig().JointCyclesToActivateEffect);
					CPClientDebugPrint("CannabisPlus: Starting Effect");
					m_HasConsumedJoint = true;
					CannabisEffectsTriggered(m_jointValue, strainName);
					if (!jointTimer) { jointTimer = new Timer()};
					jointTimer.Stop();
					jointTimer.Run(GetCPConfig().SmokingJointEffectSeconds, this, "ResetJointValues", null, false);
				}
				SetSynchDirty();
			}
		}
	}
	// called by timer if the effect is over, resets all values so the player can consume again
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

		counter = cycles / GetCPConfig().JointCyclesToActivateEffect;
		multiplier = 1 + (0.25 * counter);

		if(g_Game.IsClient())
		{
			CPClientDebugPrint("CannabisEffectsTriggered counter: " + counter + " multiplier: " + multiplier + " strain: " + strainName);

			CPClientDebugPrint("g_ClientCannabisStrainConfigs size: " + g_ClientCannabisStrainConfigs.Count());
			for (int i = 0; i < g_ClientCannabisStrainConfigs.Count(); i++) {
				string key = g_ClientCannabisStrainConfigs.GetKey(i);
				CPClientDebugPrint("Map key " + i + ": '" + key + "'");
			}

			CannabisStrainConfig strainConfig = g_ClientCannabisStrainConfigs.Get(strainName);
			if (strainConfig != null) {
				CPClientDebugPrint("Retrieved config for '" + strainName + "': found");
				if (strainConfig.WeedEffects != null) {
					CPClientDebugPrint("WeedEffects null check: not null");
					CPClientDebugPrint("WeedEffects values - Hue: " + strainConfig.WeedEffects.HueIntensity + " RadX: " + strainConfig.WeedEffects.RadBlurXPower);
				} else {
					CPClientDebugPrint("WeedEffects null check: null");
					strainConfig.WeedEffects = new WeedEffectsConfig();
					CPClientDebugPrint("Initialized default WeedEffects for strain: " + strainName);
				}
			} else {
				CPClientDebugPrint("Retrieved config for '" + strainName + "': null");
				strainConfig = new CannabisStrainConfig();
				strainConfig.WeedEffects = new WeedEffectsConfig();
				CPClientDebugPrint("Created default config and WeedEffects for strain: " + strainName);
			}

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
		if(g_Game.IsClient())
		{
			CameraEffects.changeHue(60);
			CameraEffects.changeRadBlurXEffect(0);
			CameraEffects.changeRadBlurYEffect(0);
			CameraEffects.changeRotationBlurPower(0);	
		}
	}
}