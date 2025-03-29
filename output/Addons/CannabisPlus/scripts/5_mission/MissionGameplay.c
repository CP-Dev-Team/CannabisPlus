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
        }
    }

    override void OnMissionStart()
    {
        super.OnMissionStart();

        // Request the general config and strain configs from the server
        GetRPCManager().SendRPC("CP_scripts", "CLIENTCONFIGREQUEST", null, true);
    }

    /* Client-side RPC to receive the general config and strain configs */
    void CONFIGRESPONSE(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Client)
        {
            Print("[CP] Receiving general config and strain configs from the server...");

            // Expecting both general config and strain configs
            Param2<ref CannabisPlusConfigManager, ref map<string, ref CannabisStrainConfig>> data;

            if (!ctx.Read(data))
            {
                Print("[CP] ERROR: Failed to read RPC data.");
                return;
            }

            // Update client-side config references
            g_ClientCannabisPlusConfig = data.param1;  // General config
            g_ClientCannabisStrainConfigs = data.param2;  // Strain configs

            Print("[CP] Successfully received all configs from the server.");

            // Debug Print General Config
            if (g_ClientCannabisPlusConfig)
            {
                Print("[CP] General Config Loaded.");
                Print("[CP] Workbench Power Used: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PowerUsed);
                Print("[CP] Plastic Wrap Usage: " + g_ClientCannabisPlusConfig.WorkbenchSettings.PlasticWrapUsage);
                Print("[CP] Workbench Processing Time: " + g_ClientCannabisPlusConfig.WorkbenchSettings.ProcessingTime);
            }

            // Debug Print All Strain Configs
            if (g_ClientCannabisStrainConfigs && g_ClientCannabisStrainConfigs.Count() > 0)
            {
                Print("[CP] Strain Configs Loaded: " + g_ClientCannabisStrainConfigs.Count());
                foreach (string strainName, CannabisStrainConfig strainConfig : g_ClientCannabisStrainConfigs)
                {
                    Print("[CP] Strain: " + strainName + " | GrowTime: " + strainConfig.GrowTime + " | CropCount: " + strainConfig.CropCount + " | SeedCount: " + strainConfig.SeedCount);
                }
            }
            else
            {
                Print("[CP] WARNING: No strain configs received.");
            }
        }
    }
}