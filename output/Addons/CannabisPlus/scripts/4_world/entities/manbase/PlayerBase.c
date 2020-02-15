//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlayerBase {
	
	ref Timer swayTimer;								// timer that resets the values after the effect is over
	ref Timer jointTimer;								// timer that resets the values after the effect is over
	bool m_HasConsumedCigarette = false;				// has the player consumed a hole cigarette	
	int m_cigaretteValue = 0;							// the quantity of the cigarette, what the player consumed
	int m_jointValue = 0;								// the quantity of the cigarette, what the player consumed
	static bool m_IsSmokeEffectActivated = true;		// is the sway-effect on smoking a cigarette enabled
	static int m_smokingCigaretteEffectDuration = 600;	// Time in seconds for the effect to stop
	static int m_cigarettesToActivateEffect = 1;		// number of cigarettes consumed to activate the effect
	
	static bool m_IsJointEffectActivated = true;		//
	static bool m_HasConsumedJoint = false;
	static int m_smokingJointEffectDuration = 20;		// 
	static int m_jointsToActivateEffect = 1;			// 
	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToCigaretteValue(int value) {
		
		if(m_IsSmokeEffectActivated) {
			m_cigaretteValue += value;
					
			if(m_cigaretteValue >= 500 * m_jointsToActivateEffect){
				m_HasConsumedCigarette = true;
				swayTimer = new Timer();
				swayTimer.Run(m_smokingCigaretteEffectDuration, this, "ResetCigaretteValues", null, false);				
			}
		}		
	}
	
	
	void AddValueToJointValue(int value) {
		
		if(m_IsJointEffectActivated) {
			m_jointValue += value;
					
			if(m_jointValue >= 500 * m_cigarettesToActivateEffect){
				
				m_HasConsumedJoint = true;
				jointTimer = new Timer();
				jointTimer.Run(m_smokingJointEffectDuration, this, "ResetJointValues", null, false);				
			}
		}		
	}
	
	
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// called by timer if the effect is over, resets all values that the player "consume again"
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void ResetCigaretteValues() {
		
		m_cigaretteValue = 0;
		m_HasConsumedCigarette = false;
	}
	
	void ResetJointValues() {
		
		m_HasConsumedJoint = false;
		m_jointValue = 0;		
		
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/*
	void SetConsumedCigarette(bool state) {
		
		m_HasConsumedCigarette = state;
	}
	*/
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// returns if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/*
	bool HasPlayerConsumedCigarette() {
		
		return m_HasConsumedCigarette;
	}
	*/
}