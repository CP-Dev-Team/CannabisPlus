// True when this start found no config or one from an older CannabisPlus version (new built-in strains get written).
static bool g_CPConfigUpdated = false;

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
	ref WorkbenchConfig CP_WorkbenchSettings;

    int SecondsToDryCannabisPlant;	// Time in seconds for raw plants to dry on drying post.

	void CannabisPlusConfigManager()
	{
		SetDefaults();
	}

	// Default values. Settings missing from the server's json keep these.
	protected void SetDefaults()
	{
		ConfigVersion					= 0;
		EnableServerDebugLogging        = false;
		EnableClientDebugLogging        = false;

		ActivateJointSmokingEffect 		= true;
		SmokingJointEffectSeconds 		= 360;
		JointCyclesToActivateEffect 	= 10;

		CP_WorkbenchSettings = new WorkbenchConfig();

		SecondsToDryCannabisPlant       = 30;
	}

	// Resets every general setting to its default and saves. Strain files are not touched.
	void LoadDefaultSettings() {
		SetDefaults();
		ConfigVersion = GetModVersion();
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

		if (!CP_WorkbenchSettings) CP_WorkbenchSettings = new WorkbenchConfig();
		CP_WorkbenchSettings.Validate();
	}

	// Called when the saved config comes from an older mod version, after it has been loaded
	// over the defaults. Add a step here when a setting changes meaning between versions,
	// e.g. if (fromVersion < 320) SecondsToDryCannabisPlant = SecondsToDryCannabisPlant * 60;
	// Renamed settings are handled in MigrateConfigKeys before loading.
	protected void MigrateConfig(int fromVersion)
	{
	}

	// Keeps copies of the server's config and strain files from before an update. The originals are not deleted.
	protected void BackupConfig(int fromVersion) {
		string bkpPath = m_CPProfileDir + m_CPProfileFolder + "/ConfigBackup";
		if (!FileExist(bkpPath))
			MakeDirectory(bkpPath);
		bkpPath = bkpPath + "/v" + fromVersion;
		if (!FileExist(bkpPath))
			MakeDirectory(bkpPath);

		if (FileExist(m_CPConfigPath))
			CopyFile(m_CPConfigPath, bkpPath + "/CannabisPlus.json");

		string strainsPath = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder + "/";
		if (!FileExist(strainsPath))
			return;

		string strainsBkpPath = bkpPath + "/" + m_CPStrainsFolder;
		if (!FileExist(strainsBkpPath))
			MakeDirectory(strainsBkpPath);

		string fileName;
		int fileAttr;
		FindFileHandle fileHandle = CP_StrainHelper.FindProfileFile(strainsPath + "*.json", fileName, fileAttr);
		if (fileHandle == 0)
		{
			// The folder can't be listed (DZEXP-134 on some hosts): back up the built-in strain files by name.
			array<string> strainNames = CannabisStrainConfig.GetDefaultStrainNames();
			foreach (string strainName : strainNames)
			{
				if (FileExist(strainsPath + strainName + ".json"))
					CopyFile(strainsPath + strainName + ".json", strainsBkpPath + "/" + strainName + ".json");
			}
			return;
		}

		while (fileName != "")
		{
			CopyFile(strainsPath + fileName, strainsBkpPath + "/" + fileName);
			fileName = "";
			FindNextFile(fileHandle, fileName, fileAttr);
		}
		CloseFindFile(fileHandle);
	}

	static void MigrateConfigKeys(string path) {
		FileHandle fileRead = OpenFile(path, FileMode.READ);
		if (fileRead == 0) return;

		string content = "";
		string line;
		while (FGets(fileRead, line) >= 0) {
			line.Replace("\"WorkbenchSettings\"", "\"CP_WorkbenchSettings\"");
			content = content + line + "\n";
		}
		CloseFile(fileRead);

		FileHandle fileWrite = OpenFile(path, FileMode.WRITE);
		if (fileWrite == 0) return;
		FPrint(fileWrite, content);
		CloseFile(fileWrite);
	}

	protected void SaveConfig() {
		if (!FileExist(m_CPProfileDir + m_CPProfileFolder + "/"))
			MakeDirectory(m_CPProfileDir + m_CPProfileFolder + "/");

		string error;
		if (!JsonFileLoader<CannabisPlusConfigManager>.SaveFile(m_CPConfigPath, this, error))
			Print("[CannabisPlus] ERROR: " + error);
	};

	static CannabisPlusConfigManager LoadConfig()
    {
        CannabisPlusConfigManager settings = new CannabisPlusConfigManager();

        if(!FileExist(m_CPProfileDir + m_CPProfileFolder))
            MakeDirectory(m_CPProfileDir + m_CPProfileFolder);

        if(!FileExist(m_CPConfigPath))
        {
            g_CPConfigUpdated = true;
            settings.LoadDefaultSettings();
            CP_Debug = settings.EnableServerDebugLogging;
            return settings;
        }

        MigrateConfigKeys(m_CPConfigPath);

        string error;
        if (!JsonFileLoader<CannabisPlusConfigManager>.LoadFile(m_CPConfigPath, settings, error))
        {
            // Broken json (e.g. a typo): leave the server's file untouched and run on defaults.
            Print("[CannabisPlus] ERROR: " + error);
            Print("[CannabisPlus] ERROR: Using default settings until " + m_CPConfigPath + " is fixed.");
            settings = new CannabisPlusConfigManager();
            settings.ConfigVersion = settings.GetModVersion();
            CP_Debug = settings.EnableServerDebugLogging;
            return settings;
        }

        int modVersion = settings.GetModVersion();
        if (settings.ConfigVersion != modVersion)
        {
            g_CPConfigUpdated = true;
            settings.BackupConfig(settings.ConfigVersion);
            settings.MigrateConfig(settings.ConfigVersion);
            settings.ConfigVersion = modVersion;
        }

        settings.ValidateConfig();
        // Rewrite the file so newly added settings appear and removed ones are dropped.
        settings.SaveConfig();
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

// The strain names sorted, identical on the server and on clients, so items can sync a strain as a small number.
static ref TStringArray g_CPStrainOrder = new TStringArray;

// The strain registry on this machine (server: loaded from the profile, client: received from the server).
static map<string, ref CannabisStrainConfig> CP_GetStrainMap()
{
    if (g_Game.IsServer())
        return g_CannabisStrainConfigs;
    return g_ClientCannabisStrainConfigs;
}

// A strain's settings, or null if this server has no such strain.
static CannabisStrainConfig CP_GetStrainConfig(string strainName)
{
    if (strainName == "")
        return null;
    return CP_GetStrainMap().Get(strainName);
}

static void CP_RebuildStrainOrder()
{
    g_CPStrainOrder = new TStringArray;
    map<string, ref CannabisStrainConfig> strains = CP_GetStrainMap();
    foreach (string strainName, CannabisStrainConfig strainConfig : strains)
    {
        g_CPStrainOrder.Insert(strainName);
    }
    g_CPStrainOrder.Sort();
}

static int CP_GetStrainIndex(string strainName)
{
    return g_CPStrainOrder.Find(strainName);
}

static string CP_GetStrainByIndex(int index)
{
    if (index < 0 || index >= g_CPStrainOrder.Count())
        return "";
    return g_CPStrainOrder[index];
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
    int BudsPerBag;
    int BagsPerBrick;
    
    void WorkbenchConfig(int reqBat = 1, int powerUsed = 1, int wrapUsage = 10, int procSeconds = 5)
    {
        RequireBattery = reqBat;
        PowerUsed = powerUsed;
        PlasticWrapUsage = wrapUsage;
        ProcessingSeconds = procSeconds;
        BudsPerBag = 2;
        BagsPerBrick = 16;
    }

    void Validate()
    {
        if (PowerUsed < 0) PowerUsed = 0;
        if (PowerUsed > 100) PowerUsed = 100;
        if (PlasticWrapUsage < 1) PlasticWrapUsage = 1;
        if (PlasticWrapUsage > 100) PlasticWrapUsage = 100;
        if (ProcessingSeconds < 1) ProcessingSeconds = 1;
        if (BudsPerBag < 1) BudsPerBag = 1;
        if (BagsPerBrick < 1) BagsPerBrick = 1;
    }
};
