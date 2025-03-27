
class CannabisPlusConfigManager
{
    private ref CannabisPlusConfig generalConfig;
    private ref map<string, ref CannabisStrainConfig> strainConfigs;

    void CannabisPlusConfigManager()
    {
        generalConfig = CannabisPlusConfig.LoadConfig();  // Load the general settings
        strainConfigs = new map<string, ref CannabisStrainConfig>();
    }

    CannabisPlusConfig GetGeneralConfig()
    {
        return generalConfig;
    }

    CannabisStrainConfig LoadStrain(string strainName)
    {
        if (!strainConfigs.Contains(strainName))
        {
            strainConfigs[strainName] = CannabisStrainConfig.LoadStrain(strainName);
        }
        return strainConfigs[strainName];
    }
};

/* Global Getter for config */
static ref CannabisPlusConfigManager g_CannabisPlusConfigManager;
static CannabisPlusConfigManager GetCPConfig()
{
    if (!g_CannabisPlusConfigManager)
    {
        g_CannabisPlusConfigManager = new CannabisPlusConfigManager();
    }
    return g_CannabisPlusConfigManager;
};
