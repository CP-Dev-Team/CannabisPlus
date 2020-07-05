//preconfiguring the CannabisPlus.json
class CannabisPlusConfig
{
	int configVersion;
	
	bool removeAfterHarvest;
	
	float tobacco_growtime;
	float tobacco_cropcount;
	float tobaccoSeed_count;
	
	float cannabis_growtime; //deprecated
	float cannabis_cropcount; //deprecated
	float cannabisSeed_count; //deprecated
	
	float cannabisSkunk_growtime;
	float cannabisSkunk_cropcount;
	float cannabisSkunkSeed_count;
	
	float cannabisKush_growtime;
	float cannabisKush_cropcount;
	float cannabisKushSeed_count;
	
	float cannabisBlue_growtime;
	float cannabisBlue_cropcount;
	float cannabisBlueSeed_count;

	float cannabisStardawg_growtime;
	float cannabisStardawg_cropcount;
	float cannabisStardawgSeed_count;
	
	float pepper_growtime;
	float pepper_cropcount;
	float pepperSeed_count;
	
	float tomato_growtime;
	float tomato_cropcount;
	float tomatoSeed_count;
	
	float zucchini_growtime;
	float zucchini_cropcount;
	float zucchiniSeed_count;
	
	float pumpkin_growtime;
	float pumpkin_cropcount;
	float pumpkinSeed_count;
	
	// smoke effect settings
	int activateCigaretteSmokingEffect; // reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingCigaretteEffectDuration;	// Time in seconds for the effect to stop
	int cigaretteCyclesToActivateEffect;	// number of cigarettes consumed to activate the effect
	// joint smoke effect settings
	int activateJointSmokingEffect; // reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingJointEffectDuration;	// Time in seconds for the effect to stop
	int jointCyclesToActivateEffect;	// number of cigarettes consumed to activate the effect

	float jointEffectRed;
	float jointEffectGreen;
	float jointEffectBlue;
	
	void CannabisPlusConfig() {
		
		configVersion				= 100;		
		removeAfterHarvest 		= true;		
		tobacco_growtime 			= 8;
		tobacco_cropcount 		= 2;
		tobaccoSeed_count 		= 9;		
		cannabis_growtime         = 8; //deprecated
		cannabis_cropcount        = 2; //deprecated
		cannabisSeed_count        = 9; //deprecated		
		cannabisSkunk_growtime 	= 8;
		cannabisSkunk_cropcount 	= 2;
		cannabisSkunkSeed_count 	= 9;		
		cannabisKush_growtime 	= 8;
		cannabisKush_cropcount 	= 2;
		cannabisKushSeed_count 	= 9;		
		cannabisBlue_growtime 	= 8;
		cannabisBlue_cropcount 	= 2;
		cannabisBlueSeed_count 	= 9;	
		cannabisStardawg_growtime 	= 8;
		cannabisStardawg_cropcount 	= 2;
		cannabisStardawgSeed_count 	= 9;		
		pepper_growtime 			= 8;
		pepper_cropcount 			= 2;
		pepperSeed_count 			= 9;		
		tomato_growtime 			= 8;
		tomato_cropcount 			= 2;
		tomatoSeed_count 			= 9;		
		zucchini_growtime 		= 8;
		zucchini_cropcount 		= 2;
		zucchiniSeed_count 		= 9;
		pumpkin_growtime 			= 8;
		pumpkin_cropcount 		= 2;
		pumpkinSeed_count 		= 9;
		activateCigaretteSmokingEffect = false;
		smokingCigaretteEffectDuration 	= 20;
		cigaretteCyclesToActivateEffect 		= 8;
		activateJointSmokingEffect 	= false;
		smokingJointEffectDuration 		= 20;
		jointCyclesToActivateEffect 			= 2;	
		jointEffectRed 			= 0.5;
		jointEffectGreen 			= 0.3;
		jointEffectBlue 			= 0.1;
	};
	
	void Validate() {		
		if (jointEffectRed > 1.0 || jointEffectGreen > 1.0 || jointEffectBlue > 1.0) {
			Print("[CannabisPlusConfig] Joint Effect r,g,b values must be <= 1.0");
			jointEffectRed = 1.0;
			jointEffectGreen = 1.0;
			jointEffectBlue = 1.0;
		}
	};
};