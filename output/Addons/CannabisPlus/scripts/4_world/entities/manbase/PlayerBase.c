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
						
				if(m_jointValue >= GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect){	
					Print("Smoking joint effect" + GetDayZGame().GetCannabisPlusConfig().jointCyclesToActivateEffect);
					//Print("CannabisPlus: Starting Effect");			
					m_HasConsumedJoint = true;
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
		m_jointValue = 0;
		jointTimer.Stop();
	}
	
	override void Init()
      {
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
		GetDayZPlayerType().AddItemInHandsProfileIK("CP_Cigarette", "dz/anims/workspaces/player/player_main/player_main_1h.asi", onehand, "dz/anims/anm/player/ik/gear/thermometer.anm");
		
	  }

        super.Init();
    }
}