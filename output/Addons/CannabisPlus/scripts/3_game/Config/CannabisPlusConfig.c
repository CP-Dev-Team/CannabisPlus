//preconfiguring the CannabisPlus.json
class CannabisPlusConfig
{
	int configVersion;
	
	bool removeAfterHarvest;
	
	int tobacco_growtime;
	int tobacco_cropcount;
	int tobaccoSeed_count;
	
	int cannabisSkunk_growtime;
	int cannabisSkunk_cropcount;
	int cannabisSkunkSeed_count;
	
	int cannabisKush_growtime;
	int cannabisKush_cropcount;
	int cannabisKushSeed_count;
	
	int cannabisBlue_growtime;
	int cannabisBlue_cropcount;
	int cannabisBlueSeed_count;

	int cannabisStardawg_growtime;
	int cannabisStardawg_cropcount;
	int cannabisStardawgSeed_count;

	int cannabisFuture_growtime;
	int cannabisFuture_cropcount;
	int cannabisFutureSeed_count;

	int cannabisS1_growtime;
	int cannabisS1_cropcount;
	int cannabisS1Seed_count;

	int cannabisNomad_growtime;
	int cannabisNomad_cropcount;
	int cannabisNomadSeed_count;

	int cannabisBlackFrost_growtime;
	int cannabisBlackFrost_cropcount;
	int cannabisBlackFrostSeed_count;
	
	int pepper_growtime;
	int pepper_cropcount;
	int pepperSeed_count;
	
	int tomato_growtime;
	int tomato_cropcount;
	int tomatoSeed_count;
	
	int zucchini_growtime;
	int zucchini_cropcount;
	int zucchiniSeed_count;
	
	int pumpkin_growtime;
	int pumpkin_cropcount;
	int pumpkinSeed_count;
	
	// smoke effect settings
	int activateCigaretteSmokingEffect; 	// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingCigaretteEffectDuration;		// Time in seconds for the effect to stop
	int cigaretteCyclesToActivateEffect;	// number of cigarettes consumed to activate the effect
	// joint smoke effect settings
	int activateJointSmokingEffect; 		// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingJointEffectDuration;			// Time in seconds for the effect to stop
	int jointCyclesToActivateEffect;		// number of cigarettes consumed to activate the effect

	// Weed Effects.
      float weedHueIntensity;
      int weedRadBlurXPower;
      int weedRadBlurYPower;
      int weedRotBlurPow;

      int cannabis_drytime;
	
	void CannabisPlusConfig() {
		
            configVersion				= 251;		
            removeAfterHarvest 			= true;		

            tobacco_growtime 				= 8;
            tobacco_cropcount 			= 2;
            tobaccoSeed_count 			= 9;

            cannabisSkunk_growtime 			= 8;
            cannabisSkunk_cropcount 		= 2;
            cannabisSkunkSeed_count 		= 9;	

            cannabisKush_growtime 			= 8;
            cannabisKush_cropcount 			= 2;
            cannabisKushSeed_count 			= 9;	

            cannabisBlue_growtime 			= 8;
            cannabisBlue_cropcount 			= 2;
            cannabisBlueSeed_count 			= 9;	

            cannabisStardawg_growtime 		= 8;
            cannabisStardawg_cropcount 		= 2;
            cannabisStardawgSeed_count 		= 9;

            cannabisFuture_growtime 		= 8;
            cannabisFuture_cropcount 		= 2;
            cannabisFutureSeed_count 		= 9;		

            cannabisS1_growtime 			= 8;
            cannabisS1_cropcount 			= 2;
            cannabisS1Seed_count 			= 9;

            cannabisNomad_growtime 			= 8;
            cannabisNomad_cropcount 		= 2;
            cannabisNomadSeed_count 		= 9;

            cannabisBlackFrost_growtime 		= 8;
            cannabisBlackFrost_cropcount 		= 2;
            cannabisBlackFrostSeed_count 		= 9;

            pepper_growtime 				= 8;
            pepper_cropcount 				= 2;
            pepperSeed_count 				= 9;		
            tomato_growtime 				= 8;
            tomato_cropcount 				= 2;
            tomatoSeed_count 				= 9;		
            zucchini_growtime 			= 8;
            zucchini_cropcount 			= 2;
            zucchiniSeed_count 			= 9;
            pumpkin_growtime 				= 8;
            pumpkin_cropcount 			= 2;
            pumpkinSeed_count 			= 9;
            activateCigaretteSmokingEffect 	= false;
            smokingCigaretteEffectDuration 	= 20;
            cigaretteCyclesToActivateEffect 	= 8;
            activateJointSmokingEffect 		= true;
            smokingJointEffectDuration 		= 360;
            jointCyclesToActivateEffect 		= 10;	
            weedHueIntensity 				= 58.0;
            weedRadBlurXPower 			= 2;
            weedRadBlurYPower 			= 2;
            weedRotBlurPow 				= 10;

            cannabis_drytime                  =60;
	};
	
	void Validate() {		
		
	};
};