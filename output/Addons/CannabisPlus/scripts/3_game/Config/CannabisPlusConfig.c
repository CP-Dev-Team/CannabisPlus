class CannabisPlusConfigManager
{
	int ConfigVersion;
	bool EnableServerDebugLogging;
	bool EnableClientDebugLogging;

	// joint smoke effect settings
	int ActivateJointSmokingEffect; 		// reduces the fluctuation/sway in aiming when a joint is smoked
	int SmokingJointEffectSeconds;			// Time in seconds for the effect to stop
	int JointCyclesToActivateEffect;		// number of joints consumed to activate the effect

	// Workbench
	ref WorkbenchConfig WorkbenchSettings;

    int SecondsToDryCannabisPlant;	// Time in seconds for raw plants to dry on drying post.
	
	void CannabisPlusConfigManager() 
	{
		
	}	
	
	void LoadDefaultSettings() {
			ConfigVersion					= GetModVersion();
            EnableServerDebugLogging        = false;
            EnableClientDebugLogging        = false;

            ActivateJointSmokingEffect 		= true;
            SmokingJointEffectSeconds 		= 360;
            JointCyclesToActivateEffect 	= 10;

			WorkbenchSettings = new WorkbenchConfig();

            SecondsToDryCannabisPlant            	= 30;

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
		g_Game.ConfigGetText(cfgversion, ModVersion);
		CPDebugPrint("ModConfig entry found Mod Version is: " + ModVersion);
		return ParseVersionString(ModVersion);
	}

	protected int ParseVersionString(string version) {
		array<string> parts = new array<string>();
		version.Split(".", parts);
		int major = 0, minor = 0, patch = 0;
		if (parts.Count() > 0) major = parts[0].ToInt();
		if (parts.Count() > 1) minor = parts[1].ToInt();
		if (parts.Count() > 2) patch = parts[2].ToInt();
		return (major * 100) + (minor * 10) + patch;
	}

	void ValidateConfig() {
		if (SecondsToDryCannabisPlant < 1) SecondsToDryCannabisPlant = 1;

		if (SmokingJointEffectSeconds < 1) SmokingJointEffectSeconds = 1;
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
		BackupStrainConfigs(cfgbkpPath);
	}

	protected void BackupStrainConfigs(string cfgbkpPath) {
		string strainsPath = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder + "/";
		if (!FileExist(strainsPath))
			return;

		string strainsBkpPath = cfgbkpPath + "/" + m_CPStrainsFolder;
		if (!FileExist(strainsBkpPath))
			MakeDirectory(strainsBkpPath);

		string fileName;
		int fileAttr;
		FindFileHandle fileHandle = FindFile(strainsPath + "*.json", fileName, fileAttr, 0);
		if (fileHandle == 0)
			return;

		while (fileName != "")
		{
			CopyFile(strainsPath + fileName, strainsBkpPath + "/" + fileName);
			DeleteFile(strainsPath + fileName);
			fileName = "";
			FindNextFile(fileHandle, fileName, fileAttr);
		}
		CloseFindFile(fileHandle);
		DeleteFile(strainsPath);
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
        CP_Debug = settings.EnableServerDebugLogging;

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

bool CP_ClientDebug = false;            // Client-side debug toggle, set from config via RPC

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
    int ProcessingSeconds;
    
    void WorkbenchConfig(int reqBat = 1, int powerUsed = 1, int wrapUsage = 10, int procSeconds = 5)
    {
        RequireBattery = reqBat;
        PowerUsed = powerUsed;
        PlasticWrapUsage = wrapUsage;
        ProcessingSeconds = procSeconds;
    }
};