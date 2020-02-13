//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlayerBase {
	
	ref Timer swayTimer;								// timer that resets the values after the effect is over		
	bool m_HasConsumedCigarette = false;				// has the player consumed a hole cigarette	
	int m_cigaretteValue = 0;							// the quantity of the cigarette, what the player consumed
	static bool m_IsSmokeEffectActivated = true;		// is the sway-effect on smoking a cigarette enabled
	static int m_smokingCigaretteEffectDuration = 600;	// Time in seconds for the effect to stop
	static int m_cigarettesToActivateEffect = 1;		// number of cigarettes consumed to activate the effect
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// set to true if the player consumed a cigarette
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AddValueToCigaretteValue(int value) {
		
		if(m_IsSmokeEffectActivated) {
			m_cigaretteValue += value;
					
			if(m_cigaretteValue >= 500 * m_cigarettesToActivateEffect){
				
				m_HasConsumedCigarette = true;
				swayTimer = new Timer();
				swayTimer.Run(m_smokingCigaretteEffectDuration, this, "ResetCigaretteValues", null, false);				
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