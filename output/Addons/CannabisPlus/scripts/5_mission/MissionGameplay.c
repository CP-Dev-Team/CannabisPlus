modded class MissionGameplay extends MissionBase
{
    protected bool m_isModdedMissionInitialized = false;

    override void OnInit()
    {
        super.OnInit();

        if (!m_isModdedMissionInitialized)
        {
            // Register the client-side RPC to receive config data
            GetRPCManager().AddRPC("CP_scripts", "CONFIGRESPONSE", this, SingeplayerExecutionType.Client);
            m_isModdedMissionInitialized = true;
            CPDebugPrint("Client RPC CONFIGRESPONSE registered.");
        }
    }

    override void OnMissionStart()
    {
        super.OnMissionStart();

        // Request the general config and strain configs from the server
        CPDebugPrint("Client requesting configs from server.");
        GetRPCManager().SendRPC("CP_scripts", "CLIENTCONFIGREQUEST", null, true);
    }

    /* Client-side RPC to receive the general config and strain configs */
    void CONFIGRESPONSE(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Client)
        {
            CPClientDebugPrint("Receiving general config and strain configs from the server...");

            // Expecting both general config and strain configs
            Param2<ref CannabisPlusConfigManager, ref map<string, ref CannabisStrainConfig>> data;

            if (!ctx.Read(data))
            {
                CPClientDebugPrint("ERROR: Failed to read RPC data.");
                return;
            }

            // Update client-side config references because for whatever reason, the map won't f'ing pass to the client.
            g_ClientCannabisPlusConfig = data.param1;  // General config
            g_ClientCannabisStrainConfigs = new map<string, ref CannabisStrainConfig>();
            foreach (string strainKey, CannabisStrainConfig config : data.param2) {
                CannabisStrainConfig newConfig = new CannabisStrainConfig();
                newConfig.MinutesToGrow = config.MinutesToGrow;
                newConfig.CropCount = config.CropCount;
                newConfig.SeedCount = config.SeedCount;
                if (config.WeedEffects) {
                    newConfig.WeedEffects = new WeedEffectsConfig();
                    newConfig.WeedEffects.HueIntensity = config.WeedEffects.HueIntensity;
                    newConfig.WeedEffects.RadBlurXPower = config.WeedEffects.RadBlurXPower;
                    newConfig.WeedEffects.RadBlurYPower = config.WeedEffects.RadBlurYPower;
                    newConfig.WeedEffects.RotBlurPow = config.WeedEffects.RotBlurPow;
                }
                g_ClientCannabisStrainConfigs.Insert(strainKey, newConfig);
            }

            int strainsCount = 0;
            if (g_ClientCannabisStrainConfigs)
            {
                strainsCount = g_ClientCannabisStrainConfigs.Count();
            }
            CPClientDebugPrint("Successfully received all configs from the server. Strains count: " + strainsCount);

            // Debug Print General Config
            if (g_ClientCannabisPlusConfig)
            {
                CPClientDebugPrint("General Config Loaded.");
                CPClientDebugPrint("Workbench Power Used: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PowerUsed);
                CPClientDebugPrint("Plastic Wrap Usage: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PlasticWrapUsage);
                CPClientDebugPrint("Workbench Processing Time: " + g_ClientCannabisPlusConfig.WorkbenchSettings.ProcessingSeconds);
                CP_ClientDebug = g_ClientCannabisPlusConfig.EnableClientDebugLogging;
                CPClientDebugPrint("EnableServerDebugLogging: " + g_ClientCannabisPlusConfig.EnableServerDebugLogging);
                CPClientDebugPrint("EnableClientDebugLogging: " + g_ClientCannabisPlusConfig.EnableClientDebugLogging);
            }
            else
            {
                CPClientDebugPrint("WARNING: General config is null.");
            }

            // Debug Print All Strain Configs
            if (g_ClientCannabisStrainConfigs && g_ClientCannabisStrainConfigs.Count() > 0)
            {
                CPClientDebugPrint("Strain Configs Loaded: " + g_ClientCannabisStrainConfigs.Count());
                foreach (string strainName, CannabisStrainConfig strainConfig : g_ClientCannabisStrainConfigs)
                {
                    CPClientDebugPrint("Strain: " + strainName + " | MinutesToGrow: " + strainConfig.MinutesToGrow + " | CropCount: " + strainConfig.CropCount + " | SeedCount: " + strainConfig.SeedCount);
                }
            }
            else
            {
                CPClientDebugPrint("WARNING: No strain configs received or map is null.");
            }
        }
    }
}
