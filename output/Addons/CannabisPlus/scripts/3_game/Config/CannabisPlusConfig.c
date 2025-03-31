class CannabisPlusConfigManager
{
	int configVersion;
	
	bool removeAfterHarvest;
	
	int tobacco_growtime;
	int tobacco_cropcount;
	int tobaccoSeed_count;
	
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

	int potato_growtime;
	int potato_cropcount;

	
	// smoke effect settings
	int activateCigaretteSmokingEffect; 	// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingCigaretteEffectDuration;		// Time in seconds for the effect to stop
	int cigaretteCyclesToActivateEffect;	// number of cigarettes consumed to activate the effect
	// joint smoke effect settings
	int activateJointSmokingEffect; 		// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingJointEffectDuration;			// Time in seconds for the effect to stop
	int jointCyclesToActivateEffect;		// number of cigarettes consumed to activate the effect

	// Weed Effects.
	ref WeedEffectsConfig WeedEffects;
	// Workbench
	ref WorkbenchConfig WorkbenchSettings;
    // Default strains
    ref array<string> StrainsUsed;

	int spoiltime;							// Time until fully matured plants will spoil.

    int cannabis_drytime;					// Time for raw plants to dry on drying post.


	//int    Buds_To_Bags_Required = 2;
	//int    Bags_To_Bricks_Required = 16;
	
	// Composting (Unused)
	//int PlantPerBag;
	//int CompostTime;

	int PlantMaterialUsage;
    int GardenLimeUsage;
	
	void CannabisPlusConfigManager() 
	{
		
	}	
	
	void LoadDefaultSettings() {
			configVersion					= GetModVersion();
		
			removeAfterHarvest 				= true;	

            tobacco_growtime 				= 8;
            tobacco_cropcount 				= 2;
            tobaccoSeed_count 				= 9;

            pepper_growtime 				= 8;
            pepper_cropcount 				= 2;
            pepperSeed_count 				= 9;		
            tomato_growtime 				= 8;
            tomato_cropcount 				= 2;
            tomatoSeed_count 				= 9;		
            zucchini_growtime 				= 8;
            zucchini_cropcount 				= 2;
            zucchiniSeed_count 				= 9;
            pumpkin_growtime 				= 8;
            pumpkin_cropcount 				= 2;
            pumpkinSeed_count 				= 9;
            potato_growtime 				= 8;
            potato_cropcount 				= 2;

            activateCigaretteSmokingEffect 	= false;
            smokingCigaretteEffectDuration 	= 20;
            cigaretteCyclesToActivateEffect = 8;

            activateJointSmokingEffect 		= true;
            smokingJointEffectDuration 		= 360;
            jointCyclesToActivateEffect 	= 10;

			WeedEffects = new WeedEffectsConfig();
			WorkbenchSettings = new WorkbenchConfig();
			//StrainsUsed = new StrainsConfig();

            spoiltime						= 60;
            cannabis_drytime            	= 30;
			
            //Buds_To_Bags_Required 		= 2;
			//Bags_To_Bricks_Required		= 16;
		
			//PlantPerBag					= 18;
			//CompostTime					= 360; 

			PlantMaterialUsage				= 2;
    		GardenLimeUsage					= 5;

            StrainsUsed = new array<string>;
            StrainsUsed.Insert("CannabisSkunk");
            StrainsUsed.Insert("CannabisBlue");
            StrainsUsed.Insert("CannabisKush");
            StrainsUsed.Insert("CannabisStardawg");
            StrainsUsed.Insert("CannabisS1");
            StrainsUsed.Insert("CannabisFuture");
            StrainsUsed.Insert("CannabisNomad");
            StrainsUsed.Insert("CannabisBlackFrost");

		SaveConfig();
	};

	bool IsConfigOutdated() {
		if(this.configVersion != GetModVersion())
			return true;
		return false;
	}

	protected int GetModVersion() { 
		string cfgversion = "CfgMods CannabisPlus version";
            string ModVersion;
	  	float modFloat;	
            GetGame().ConfigGetText(cfgversion, ModVersion);
            //Print("[CP->] ModConfig entry found Mod Version is: " + ModVersion);
            modFloat  = ModVersion.ToFloat()*100;	
            return (int)modFloat;
	}
	
	void SaveOldConfig() {
		local const string cfgbkpPath = "$profile:CannabisPlus/ConfigBackup";
		if (!FileExist(cfgbkpPath))
			MakeDirectory(cfgbkpPath);
		if(FileExist(m_CPConfigPath)) {
			CopyFile(m_CPConfigPath, cfgbkpPath + "/CannabisConfig_OLD_Version.json");
			DeleteFile(m_CPConfigPath);
		}
	}
	
	//this saves the config to the json file.
	protected void SaveConfig() {
		if (!FileExist(m_CPProfileDir + m_CPProfileFolder + "/"))
			MakeDirectory(m_CPProfileDir + m_CPProfileFolder + "/");
            JsonFileLoader<CannabisPlusConfigManager>.JsonSaveFile(m_CPConfigPath, this);
	};

	//Dont use that to load the config!
	static CannabisPlusConfigManager LoadConfig() {
            CannabisPlusConfigManager settings = new CannabisPlusConfigManager();

            if(!FileExist(m_CPProfileFolder))
                  MakeDirectory(m_CPProfileFolder);

            if(FileExist(m_CPConfigPath))
            {
                  JsonFileLoader<CannabisPlusConfigManager>.JsonLoadFile(m_CPConfigPath, settings);
                  if(settings.IsConfigOutdated())
                  {
                        settings.SaveOldConfig();
                        settings.LoadDefaultSettings();
                  }
            }
            else
            {
                  settings.LoadDefaultSettings();
            }
            return settings;
      }
};

/* Global Getter for Config */
static ref CannabisPlusConfigManager g_CannabisPlusConfig;
static ref CannabisPlusConfigManager g_ClientCannabisPlusConfig;
static ref map<string, ref CannabisStrainConfig> g_ClientCannabisStrainConfigs = new map<string, ref CannabisStrainConfig>();
static ref map<string, ref CannabisStrainConfig> g_CannabisStrainConfigs = new map<string, ref CannabisStrainConfig>();

static CannabisPlusConfigManager GetCPConfig()
{
    if (g_Game.IsServer() && !g_CannabisPlusConfig) 
    {
        g_CannabisPlusConfig = CannabisPlusConfigManager.LoadConfig();
    }
    else if (g_Game.IsClient())
    {
        return g_ClientCannabisPlusConfig; // Gets filled on mission start with an RPC.
    }
    return g_CannabisPlusConfig;
}

/* Utility Function to Retrieve Strain Configs */
static CannabisStrainConfig GetStrainConfigByType(EntityAI item)
{
    if (!item)
    {
        Print("[CP] Error: Null item passed to GetStrainConfigByType.");
        return new CannabisStrainConfig(); // Return default if something goes wrong
    }

    string strainName = item.GetType(); // Get the class name of the item

    // Check server-side map
    if (g_Game.IsServer())
    {
        if (g_CannabisStrainConfigs.Contains(strainName))
        {
            return g_CannabisStrainConfigs.Get(strainName);
        }
        else
        {
            Print("[CP] Warning: Server could not find strain '" + strainName + "'. Using default values.");
            return new CannabisStrainConfig();
        }
    }
    // Check client-side map
    else if (g_Game.IsClient())
    {
        if (g_ClientCannabisStrainConfigs.Contains(strainName))
        {
            return g_ClientCannabisStrainConfigs.Get(strainName);
        }
        else
        {
            Print("[CP] Warning: Client could not find strain '" + strainName + "'. Using default values.");
            return new CannabisStrainConfig();
        }
    }
    
    return new CannabisStrainConfig();
}

class WeedEffectsConfig
{
    float HueIntensity;
    int RadBlurXPower;
    int RadBlurYPower;
    int RotBlurPow;
    
    void WeedEffectsConfig(float hueIntensity = 58.0, int radBlurX = 2, int radBlurY = 2, int rotBlur = 10)
    {
        HueIntensity = hueIntensity;
        RadBlurXPower = radBlurX;
        RadBlurYPower = radBlurY;
        RotBlurPow = rotBlur;
    }
};

class WorkbenchConfig
{
    int RequireBattery;
    int PowerUsed;
    int PlasticWrapUsage;
    int ProcessingTime;
    
    void WorkbenchConfig(int reqBat = 1, int powerUsed = 1, int wrapUsage = 10, int processingTime = 5)
    {
        RequireBattery = reqBat;
        PowerUsed = powerUsed;
        PlasticWrapUsage = wrapUsage;
        ProcessingTime = processingTime;
    }
};