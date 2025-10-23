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
            CPDebugPrint("[CP] Client RPC CONFIGRESPONSE registered.");
        }
    }

    override void OnMissionStart()
    {
        super.OnMissionStart();

        // Request the general config and strain configs from the server
        CPDebugPrint("[CP] Client requesting configs from server.");
        GetRPCManager().SendRPC("CP_scripts", "CLIENTCONFIGREQUEST", null, true);
    }

    /* Client-side RPC to receive the general config and strain configs */
    void CONFIGRESPONSE(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Client)
        {
            CPDebugPrint("[CP] Receiving general config and strain configs from the server...");

            // Expecting both general config and strain configs
            Param2<ref CannabisPlusConfigManager, ref map<string, ref CannabisStrainConfig>> data;

            if (!ctx.Read(data))
            {
                CPDebugPrint("[CP] ERROR: Failed to read RPC data.");
                return;
            }

            // Update client-side config references
            g_ClientCannabisPlusConfig = data.param1;  // General config
            g_ClientCannabisStrainConfigs = data.param2;  // Strain configs

            int strainsCount = 0;
            if (g_ClientCannabisStrainConfigs)
            {
                strainsCount = g_ClientCannabisStrainConfigs.Count();
            }
            CPDebugPrint("[CP] Successfully received all configs from the server. Strains count: " + strainsCount);

            // Debug Print General Config
            if (g_ClientCannabisPlusConfig)
            {
                CPDebugPrint("[CP] General Config Loaded.");
                CPDebugPrint("[CP] Workbench Power Used: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PowerUsed);
                CPDebugPrint("[CP] Plastic Wrap Usage: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PlasticWrapUsage);
                CPDebugPrint("[CP] Workbench Processing Time: " + g_ClientCannabisPlusConfig.WorkbenchSettings.ProcessingTime);
                CPDebugPrint("[CP] EnableDebugLogging: " + g_ClientCannabisPlusConfig.EnableDebugLogging);
            }
            else
            {
                CPDebugPrint("[CP] WARNING: General config is null.");
            }

            // Debug Print All Strain Configs
            if (g_ClientCannabisStrainConfigs && g_ClientCannabisStrainConfigs.Count() > 0)
            {
                CPDebugPrint("[CP] Strain Configs Loaded: " + g_ClientCannabisStrainConfigs.Count());
                foreach (string strainName, CannabisStrainConfig strainConfig : g_ClientCannabisStrainConfigs)
                {
                    bool hasWeedEffects = (strainConfig.WeedEffects != null);
                    CPDebugPrint("[CP] Strain: " + strainName + " | GrowTime: " + strainConfig.GrowTime + " | CropCount: " + strainConfig.CropCount + " | SeedCount: " + strainConfig.SeedCount + " | WeedEffects: " + hasWeedEffects);
                }
            }
            else
            {
                CPDebugPrint("[CP] WARNING: No strain configs received or map is null.");
            }
        }
    }
}
