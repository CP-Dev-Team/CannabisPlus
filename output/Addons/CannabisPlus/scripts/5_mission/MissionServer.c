modded class MissionServer
{
    protected ref CannabisPlusConfigManager m_currentcfg;

    void InitCannabisStrainConfigs()
    {
        CPDebugPrint("Initializing strain configs (Server-Side)...");

        string path = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder + "/";
        CPDebugPrint("Strains folder path: " + path);
        
        if (!FileExist(path))  // Check if the directory exists
        {
            CPDebugPrint("Error: The directory " + path + " does not exist.");
            return;
        }
        
        string fileName;
        int fileAttr;
        FindFileHandle fileHandle = FindFile(path + "*.json", fileName, fileAttr, 0);

        if (fileHandle == 0)
        {
            CPDebugPrint("Error: Unable to open directory or find files.");
            return;
        }

        int loadedCount = 0;
        while (fileName != "")
        {
            CPDebugPrint("Found file: " + fileName);
            if (fileName != "CannabisPlus.json")  // Skip the general config file
            {
                string strainName = fileName.Substring(0, fileName.Length() - 5); // Remove ".json"
                CPDebugPrint("Loading strain config: " + strainName);

                CannabisStrainConfig strainConfig = CannabisStrainConfig.LoadStrain(strainName);
                g_CannabisStrainConfigs.Set(strainName, strainConfig);
                loadedCount++;
                CPDebugPrint("Loaded strain: " + strainName + " - MinutesToGrow: " + strainConfig.MinutesToGrow + ", CropCount: " + strainConfig.CropCount + ", SeedsPerPackage: " + strainConfig.SeedsPerPackage);
            }

            fileName = "";
            FindNextFile(fileHandle, fileName, fileAttr); // Get next file properly
        }

        CloseFindFile(fileHandle); // Close the file handle

        CPDebugPrint("All strain configs initialized (Server-Side). Total: " + g_CannabisStrainConfigs.Count() + ", Loaded: " + loadedCount);
    }

    override void OnInit()
    {
        super.OnInit();

        if (!m_currentcfg)
        {
            m_currentcfg = GetCPConfig();  // Load or create the general config

            if (m_currentcfg)
            {
                CPDebugPrint("General Config successfully loaded!");

                CannabisStrainConfig.GenerateAllDefaultsIfStrainsFolderMissing();
                CPDebugPrint("GenerateAllDefaultsIfStrainsFolderMissing completed.");
                // Automatically load all available strain configs from disk
                InitCannabisStrainConfigs();
				
				// Pre-register all cannabis strains with AgricultureCore
				// This is required so plants loaded from storage after server restart
				// are in the registry when Harvest() checks it
				for (int i = 0; i < g_CannabisStrainConfigs.Count(); i++)
				{
					string strainName = g_CannabisStrainConfigs.GetKey(i);
					CannabisStrainConfig strainCfg = g_CannabisStrainConfigs.GetElement(i);
					string plantType = "CP_Plant_Cannabis" + strainName;
					AC_RegisterPlant(plantType, strainCfg.MinutesToGrow, 1, strainCfg.CropCount, true, false);
					CPDebugPrint("Pre-registered plant: " + plantType);
				}
            }
            else
            {
                CPDebugPrint("Internal server config load failed!");
            }
        }

        // Register the RPC for client requests
        GetRPCManager().AddRPC("CP_scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both);
        CPDebugPrint("RPC CLIENTCONFIGREQUEST registered.");
    }

    /* RPC HANDLING SERVERSIDE */
    void CLIENTCONFIGREQUEST(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server) 
        {
            CPDebugPrint("Sending all strain configs to client...");

            if (!m_currentcfg)
            {
                CPDebugPrint("Error: m_currentcfg is null.");
                return;
            }

            ref Param2<CannabisPlusConfigManager, map<string, ref CannabisStrainConfig>> rpcParams = 
                new Param2<CannabisPlusConfigManager, map<string, ref CannabisStrainConfig>>(m_currentcfg, g_CannabisStrainConfigs);
            
            GetRPCManager().SendRPC("CP_scripts", "CONFIGRESPONSE", rpcParams, true, sender);

            CPDebugPrint("Successfully sent all configs to client: " + sender.GetName() + ", Strains sent: " + g_CannabisStrainConfigs.Count());
        }
    }
}
