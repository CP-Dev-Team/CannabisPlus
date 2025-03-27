class CannabisPlusConfig
{
    int ConfigVersion;
    bool RemoveAfterHarvest;
    int SpoilTime;
    int CannabisDryTime;
    
    bool RequireBattery;
    float WorkbenchPowerUsed;
    float PlasticWrapUsage;
    int WorkbenchProcessingTime;

    int PlantMaterialUsage;
    int GardenLimeUsage;

    ref map<string, ref SmokingEffectConfig> SmokingEffects;
    ref WeedEffectsConfig WeedEffects;

    void LoadDefaultSettings()
    {
        ConfigVersion = GetModVersion();
        RemoveAfterHarvest = true;
        SpoilTime = 60;
        CannabisDryTime = 30;

        RequireBattery = true;
        WorkbenchPowerUsed = 1.0;
        PlasticWrapUsage = 10.0;
        WorkbenchProcessingTime = 5;

        PlantMaterialUsage = 5;
        GardenLimeUsage = 10;

        SmokingEffects = new map<string, ref SmokingEffectConfig>;
        SmokingEffects["Cigarette"] = new SmokingEffectConfig(false, 20, 8);
        SmokingEffects["Joint"] = new SmokingEffectConfig(true, 360, 10);

        WeedEffects = new WeedEffectsConfig(58.0, 2, 2, 10);

        SaveConfig();
    }

    void SaveConfig()
    {
        JsonFileLoader<CannabisPlusConfig>.JsonSaveFile("$profile:CannabisPlus/CannabisPlus.json", this);
    }

    static CannabisPlusConfig LoadConfig()
    {
        CannabisPlusConfig settings = new CannabisPlusConfig();

        if (FileExist("$profile:CannabisPlus/CannabisPlus.json"))
        {
            JsonFileLoader<CannabisPlusConfig>.JsonLoadFile("$profile:CannabisPlus/CannabisPlus.json", settings);
        }
        else
        {
            settings.LoadDefaultSettings();
        }

        return settings;
    }
    bool IsConfigOutdated() {
        if (this.ConfigVersion != GetModVersion())
            return true;
        return false;
    }

    protected int GetModVersion() { 
        string cfgversion = "CfgMods CannabisPlus version";
        string ModVersion;
        float modFloat;	
        GetGame().ConfigGetText(cfgversion, ModVersion);
        modFloat = ModVersion.ToFloat() * 100;	
        return (int)modFloat;
    }

    void SaveOldConfig() {
        local const string cfgbkpPath = "$profile:CannabisPlus/ConfigBackup";
        if (!FileExist(cfgbkpPath))
            MakeDirectory(cfgbkpPath);
        if (FileExist(m_CPConfigPath)) {
            CopyFile(m_CPConfigPath, cfgbkpPath + "/CannabisConfig_OLD_Version.json");
            DeleteFile(m_CPConfigPath);
        }
    }

    protected void SaveConfig() {
        if (!FileExist(m_CPProfileDir + m_CPProfileFolder + "/"))
            MakeDirectory(m_CPProfileDir + m_CPProfileFolder + "/");
        JsonFileLoader<CannabisPlusConfigManager>.JsonSaveFile(m_CPConfigPath, this);
    }

    static CannabisPlusConfigManager LoadConfig() {
        CannabisPlusConfigManager settings = new CannabisPlusConfigManager();
        if (!FileExist(m_CPProfileFolder))
            MakeDirectory(m_CPProfileFolder);
        if (FileExist(m_CPConfigPath)) {
            JsonFileLoader<CannabisPlusConfigManager>.JsonLoadFile(m_CPConfigPath, settings);
            if (settings.IsConfigOutdated()) {
                settings.SaveOldConfig();
                settings.LoadDefaultSettings();
            }
        } else {
            settings.LoadDefaultSettings();
        }
        return settings;
    }
};

class SmokingEffectConfig
{
    bool ActivateEffect;
    int EffectDuration;
    int CyclesToActivate;

    void SmokingEffectConfig(bool active, int duration, int cycles)
    {
        ActivateEffect = active;
        EffectDuration = duration;
        CyclesToActivate = cycles;
    }
};

class WeedEffectsConfig
{
    float HueIntensity;
    int RadialBlurX;
    int RadialBlurY;
    int RotationalBlur;

    void WeedEffectsConfig(float hue, int blurX, int blurY, int rotBlur)
    {
        HueIntensity = hue;
        RadialBlurX = blurX;
        RadialBlurY = blurY;
        RotationalBlur = rotBlur;
    }
};