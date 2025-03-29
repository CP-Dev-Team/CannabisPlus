modded class MissionServer
{
    protected ref CannabisPlusConfigManager m_currentcfg;

    void InitCannabisStrainConfigs()
    {
        Print("[CP] Initializing strain configs (Server-Side)...");

        string path = m_CPProfileDir + m_CPProfileFolder + "/";
        
        if (!FileExist(path))  // Check if the directory exists
        {
            Print("[CP] Error: The directory " + path + " does not exist.");
            return;
        }
        
        string fileName;
        int fileAttr;
        FindFileHandle fileHandle = FindFile(path + "*.json", fileName, fileAttr, 0);

        if (fileHandle == 0)
        {
            Print("[CP] Error: Unable to open directory or find files.");
            return;
        }

        while (fileName != "")
        {
            if (fileName != "CannabisPlus.json")  // Skip the general config file
            {
                string strainName = fileName.Substring(0, fileName.Length() - 5); // Remove ".json"
                Print("[CP] Loading strain config: " + strainName);

                CannabisStrainConfig strainConfig = CannabisStrainConfig.LoadStrain(strainName);
                g_CannabisStrainConfigs.Set(strainName, strainConfig);
            }

            fileName = "";
            FindNextFile(fileHandle, fileName, fileAttr); // Get next file properly
        }

        CloseFindFile(fileHandle); // Close the file handle

        Print("[CP] All strain configs initialized (Server-Side). Total: " + g_CannabisStrainConfigs.Count());
    }

    override void OnInit()
    {
        super.OnInit();

        if (!m_currentcfg)
        {
            m_currentcfg = GetCPConfig();  // Load or create the general config

            if (m_currentcfg)
            {
                Print("[CP] General Config successfully loaded!");

                // Automatically load all available strain configs from disk
                InitCannabisStrainConfigs();

                // Debug print all loaded strains
                Print("[CP] Strain configs loaded. Total strains: " + g_CannabisStrainConfigs.Count());
                foreach (string strainName, CannabisStrainConfig strainConfig : g_CannabisStrainConfigs)
                {
                    Print("[CP] Loaded Strain: " + strainName + " | GrowTime: " + strainConfig.GrowTime + " | CropCount: " + strainConfig.CropCount + " | SeedCount: " + strainConfig.SeedCount);
                }
            }
            else
            {
                Print("[CP] Internal server config load failed!");
            }
        }

        // Register the RPC for client requests
        GetRPCManager().AddRPC("CP_scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both);
    }

    /* RPC HANDLING SERVERSIDE */
    void CLIENTCONFIGREQUEST(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server) 
        {
            Print("[CP] Sending all strain configs to client...");

            if (!m_currentcfg)
            {
                Print("[CP] Error: m_currentcfg is null.");
                return;
            }

            ref Param2< ref CannabisPlusConfigManager, ref map<string, ref CannabisStrainConfig> > rpcParams = 
                new Param2< ref CannabisPlusConfigManager, ref map<string, ref CannabisStrainConfig> >(m_currentcfg, g_CannabisStrainConfigs);
            
            GetRPCManager().SendRPC("CP_scripts", "CONFIGRESPONSE", rpcParams, true, sender);

            Print("[CP] Successfully sent all configs to client: " + sender.GetName());
        }
    }
}