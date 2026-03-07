class CannabisPlusConfigManager
{
	int ConfigVersion;
	bool EnableDebugLogging;

	bool RemoveAfterHarvest;
	bool DisablePlantMaterialDrop;
	
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
	int ActivateCigaretteSmokingEffect; 	// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int SmokingCigaretteEffectDuration;		// Time in seconds for the effect to stop
	int CigaretteCyclesToActivateEffect;	// number of cigarettes consumed to activate the effect
	// joint smoke effect settings
	int ActivateJointSmokingEffect; 		// reduces the fluctuation/sway in aiming when a cigarette is smoked
	int SmokingJointEffectDuration;			// Time in seconds for the effect to stop
	int JointCyclesToActivateEffect;		// number of cigarettes consumed to activate the effect

	// Workbench
	ref WorkbenchConfig WorkbenchSettings;

	int TimeToPlantSpoiling;	// Time until fully matured plants will spoil.

    int TimeToDryCannabisPlant;	// Time for raw plants to dry on drying post.

	int TimeToHarvestPlantMaterial;
    int TimeToHarvestGardenLime;
	
	void CannabisPlusConfigManager() 
	{
		
	}	
	
	void LoadDefaultSettings() {
			ConfigVersion					= GetModVersion();
            EnableDebugLogging              = false;  // Default is off
			RemoveAfterHarvest 				= true;
			DisablePlantMaterialDrop		= false;

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

            ActivateCigaretteSmokingEffect 	= false;
            SmokingCigaretteEffectDuration 	= 20;
            CigaretteCyclesToActivateEffect = 8;

            ActivateJointSmokingEffect 		= true;
            SmokingJointEffectDuration 		= 360;
            JointCyclesToActivateEffect 	= 10;

			WorkbenchSettings = new WorkbenchConfig();

            TimeToPlantSpoiling						= 60;
            TimeToDryCannabisPlant            	= 30;
			
			TimeToHarvestPlantMaterial				= 2;
    		TimeToHarvestGardenLime					= 5;

		SaveConfig();
	};

	bool IsConfigOutdated() {
		if(this.ConfigVersion != GetModVersion())
			return true;
		return false;
	}

	protected int GetModVersion() { 
		string cfgversion = "CfgMods CannabisPlus version";
            string ModVersion;
	  	float modFloat;	
            GetGame().ConfigGetText(cfgversion, ModVersion);
            CPDebugPrint("ModConfig entry found Mod Version is: " + ModVersion);
            modFloat  = ModVersion.ToFloat()*100;	
            return (int)modFloat;
	}

	void ValidateConfig() {
		if (tobacco_growtime < 1) tobacco_growtime = 1;
		if (pepper_growtime < 1) pepper_growtime = 1;
		if (tomato_growtime < 1) tomato_growtime = 1;
		if (zucchini_growtime < 1) zucchini_growtime = 1;
		if (pumpkin_growtime < 1) pumpkin_growtime = 1;
		if (potato_growtime < 1) potato_growtime = 1;

		if (tobacco_cropcount < 1) tobacco_cropcount = 1;
		if (pepper_cropcount < 1) pepper_cropcount = 1;
		if (tomato_cropcount < 1) tomato_cropcount = 1;
		if (zucchini_cropcount < 1) zucchini_cropcount = 1;
		if (pumpkin_cropcount < 1) pumpkin_cropcount = 1;
		if (potato_cropcount < 1) potato_cropcount = 1;

		if (TimeToPlantSpoiling < 1) TimeToPlantSpoiling = 1;
		if (TimeToDryCannabisPlant < 1) TimeToDryCannabisPlant = 1;
		if (TimeToHarvestPlantMaterial < 1) TimeToHarvestPlantMaterial = 1;
		if (TimeToHarvestGardenLime < 1) TimeToHarvestGardenLime = 1;

		if (SmokingCigaretteEffectDuration < 1) SmokingCigaretteEffectDuration = 1;
		if (CigaretteCyclesToActivateEffect < 1) CigaretteCyclesToActivateEffect = 1;
		if (SmokingJointEffectDuration < 1) SmokingJointEffectDuration = 1;
		if (JointCyclesToActivateEffect < 1) JointCyclesToActivateEffect = 1;
	}
	
	void SaveOldConfig() {
		const string cfgbkpPath = "$profile:CannabisPlus/ConfigBackup";
		if (!FileExist(cfgbkpPath))
			MakeDirectory(cfgbkpPath);
		if(FileExist(m_CPConfigPath)) {
			CopyFile(m_CPConfigPath, cfgbkpPath + "/CannabisConfig_OLD_Version.json");
			DeleteFile(m_CPConfigPath);
		}
	}
	
	// Save the config to the json file.
	protected void SaveConfig() {
		if (!FileExist(m_CPProfileDir + m_CPProfileFolder + "/"))
			MakeDirectory(m_CPProfileDir + m_CPProfileFolder + "/");
            JsonFileLoader<CannabisPlusConfigManager>.JsonSaveFile(m_CPConfigPath, this);
	};

	static CannabisPlusConfigManager LoadConfig() 
    {
        CannabisPlusConfigManager settings = new CannabisPlusConfigManager();

        if(!FileExist(m_CPProfileDir + m_CPProfileFolder))
            MakeDirectory(m_CPProfileDir + m_CPProfileFolder);

        if(FileExist(m_CPConfigPath))
        {
            JsonFileLoader<CannabisPlusConfigManager>.JsonLoadFile(m_CPConfigPath, settings);
            settings.ValidateConfig();
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
        CP_Debug = settings.EnableDebugLogging;

        return settings;
    }
};

// Global Getter for Config.
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
        CPDebugPrint("Error: Null item passed to GetStrainConfigByType.");
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
            CPDebugPrint("Warning: Server could not find strain '" + strainName + "'. Using default values.");
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
            CPClientDebugPrint("Warning: Client could not find strain '" + strainName + "'. Using default values.");
            return new CannabisStrainConfig();
        }
    }
    
    return new CannabisStrainConfig();
}

bool CP_Debug = false;                  // Server-side debug toggle enabled via main config.

void CPDebugPrint(string msg)
{
    if (CP_Debug)
    {
        Print("[CP DEBUG] " + msg);
    }
}

bool CP_ClientDebug = true;             // Client-side debug toggle

void CPClientDebugPrint(string msg)
{
    if (CP_ClientDebug)
    {
        Print("[CP CLIENT DEBUG] " + msg);
    }
}

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