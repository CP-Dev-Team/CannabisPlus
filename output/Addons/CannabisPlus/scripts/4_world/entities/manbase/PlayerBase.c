//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlayerBase {

	ref Timer swayTimer;				// timer that resets the values after the effect is over
	ref Timer jointTimer;				// timer that resets the values after the effect is over
	
	bool m_HasConsumedCigarette = false;	// has the player consumed a hole cigarette	
	int m_cigaretteValue = 0;			// the quantity of the cigarette, what the player consumed
	
	bool m_HasConsumedJoint = false;
	int m_jointValue = 0;				// the quantity of the cigarette, what the player consumed
	
	//protected ref CannabisPlusConfig m_CannabisPlusConfig
	
	//getters for cig/joint smoke state
	bool HasConsumedJoint () {
		return m_HasConsumedJoint; 
	}

	bool HasConsumedCigarette () {
		return m_HasConsumedCigarette; 
	}		 
   
	override void OnConnect()
	{
		super.OnConnect();
		if (GetIdentity()) {
			GetRPCManager().SendRPC( "CP_scripts", "RetreiveCannabisPlusConfig", new Param1 <CannabisPlusConfig> (GetDayZGame().GetCannabisPlusConfig()),true,GetIdentity());
			Print("Receiving CannabisPlusConfig info from server");
		}	
	}
	
	override void OnReconnect()
	{
		super.OnReconnect();
		if (GetIdentity()) {
			GetRPCManager().SendRPC( "CP_scripts", "RetreiveCannabisPlusConfig", new Param1 <CannabisPlusConfig> (GetDayZGame().GetCannabisPlusConfig()),true,GetIdentity());
			Print("Receiving CannabisPlusConfig info from server");
		}	
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToCigaretteValue(int value) {
		if (GetDayZGame().GetCannabisPlusConfig()) {	
			if(GetDayZGame().GetCannabisPlusConfig().activateCigaretteSmokingEffect) {
				m_cigaretteValue += value;
						
				if(m_cigaretteValue >= GetDayZGame().GetCannabisPlusConfig().cigaretteCyclesToActivateEffect){
					Print("Smoking cigarrette effect" + GetDayZGame().GetCannabisPlusConfig().cigaretteCyclesToActivateEffect);
					m_HasConsumedCigarette = true;
					if (!swayTimer) { swayTimer = new Timer()};
					swayTimer.Stop();
					swayTimer.Run(GetDayZGame().GetCannabisPlusConfig().smokingCigaretteEffectDuration, this, "ResetCigaretteValues", null, false);				
				}
			}
		}		
	}	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a joint
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToJointValue(int value) {	
		if (GetDayZGame().GetCannabisPlusConfig()) {	
			if(GetDayZGame().GetCannabisPlusConfig().activateJointSmokingEffect) {
				//Print("CannabisPlus: AddValueToJointValue");
				m_jointValue += value;
						
				if((m_jointValue % GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect) == 0){	
					//Print("Smoking joint effect " + GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect);
					//Print("CannabisPlus: Starting Effect");			
					m_HasConsumedJoint = true;
					CannabisEffectsTriggered(m_jointValue);
					if (!jointTimer) { jointTimer = new Timer()};
					jointTimer.Stop();
					jointTimer.Run(GetDayZGame().GetCannabisPlusConfig().smokingJointEffectDuration, this, "ResetJointValues", null, false);				
				}
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
	}
	
	// Cannabis Visual Effect On.
    void CannabisEffectsTriggered(int cycles)
    { 
	  float multiplier;
	  int counter;			
		
	  counter = cycles / GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect;
	  multiplier = 1 + (0.25 * counter);


        if(GetGame().IsClient())
        {
            //Reset effects on player before adding new ones.
            CameraEffects.changeHue(60);
            CameraEffects.changeRadBlurXEffect(0);
            CameraEffects.changeRadBlurYEffect(0);
            CameraEffects.changeRotationBlurPower(0);
            
            CameraEffects.changeHue(GetDayZGame().GetCannabisPlusConfig().weedHueIntensity-counter);
		CameraEffects.changeRadBlurXEffect(GetDayZGame().GetCannabisPlusConfig().weedRadBlurXPower*multiplier);
           	CameraEffects.changeRadBlurYEffect(GetDayZGame().GetCannabisPlusConfig().weedRadBlurYPower*multiplier);
           	CameraEffects.changeRotationBlurPower(GetDayZGame().GetCannabisPlusConfig().weedRotBlurPow*multiplier);		
		 	
        }	

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
	
	override void Init()
      {
        
		super.Init();
		
		//Reset effects on player spawn.
		CameraEffects.changeHue(60);
	      CameraEffects.changeRadBlurXEffect(0);
	      CameraEffects.changeRadBlurYEffect(0);
	      CameraEffects.setExposure(60);
	      CameraEffects.changeRotationBlurPower(0);
	      CameraEffects.changeVignette(0);
	      CameraEffects.changeChromaX(0);
	      CameraEffects.changeChromaY(0);
		CameraEffects.changeVignetteColorRGB(0,0,0);
		
		if ( GetGame().IsServer() || GetGame().IsMultiplayer() )
		{
	        	DayzPlayerItemBehaviorCfg     heavy = new DayzPlayerItemBehaviorCfg;
			DayzPlayerItemBehaviorCfg 	onehand = new DayzPlayerItemBehaviorCfg;
	
	        	heavy.SetHeavyItems();
			onehand.SetToolsOneHanded();
	
	    		GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointSkunk", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointBlue", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointKush", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointStardawg", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointFuture", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointS1", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointNomad", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_JointBlackFrost", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_Cigarette", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("CP_Relief_Balm", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/marmalade.anm");
		
	  	}
		
    }
}