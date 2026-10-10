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
        FindFileHandle fileHandle = CP_StrainHelper.FindProfileFile(path + "*.json", fileName, fileAttr);

        if (fileHandle == 0)
        {
            // TEMPORARY until Bohemia fixes DZEXP-134 (DayZ 1.30 FindFile can't list $profile: when the
            // profiles folder is outside the server folder): load the built-in strains by name instead.
            Print("[CannabisPlus] WARNING: Could not list the strain files in " + path + " - loading the built-in strains by name instead. Extra custom strain files will not load.");
            Print("[CannabisPlus] WARNING: On DayZ 1.30 put the -profiles folder inside the server folder (e.g. -profiles=profiles) to load custom strains, until Bohemia fixes DZEXP-134.");
            LoadDefaultStrainsByName(path);
            return;
        }

        int loadedCount = 0;
        while (fileName != "")
        {
            CPDebugPrint("Found file: " + fileName);
            string strainName = fileName.Substring(0, fileName.Length() - 5); // Remove ".json"
            if (CP_StrainHelper.IsRetiredStrain(strainName))
            {
                // Retired in 4.0 (not a real strain); its items now belong to another strain. The file is left alone.
                Print("[CannabisPlus] Strain file " + fileName + " is not used any more: " + strainName + " was retired, its items became " + CP_StrainHelper.GetRetiredReplacement(strainName) + ".");
            }
            else if (fileName != "CannabisPlus.json")  // Skip the general config file
            {
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

    // TEMPORARY fallback for DZEXP-134: loads the built-in strain files by name, which works on every host.
    protected void LoadDefaultStrainsByName(string path)
    {
        array<string> strainNames = CannabisStrainConfig.GetDefaultStrainNames();
        foreach (string strainName : strainNames)
        {
            if (!FileExist(path + strainName + ".json"))
                continue;

            CannabisStrainConfig strainConfig = CannabisStrainConfig.LoadStrain(strainName);
            g_CannabisStrainConfigs.Set(strainName, strainConfig);
            CPDebugPrint("Loaded strain by name: " + strainName + " - MinutesToGrow: " + strainConfig.MinutesToGrow + ", CropCount: " + strainConfig.CropCount);
        }
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

                // New servers and updated mods get the built-in strains that have no file yet.
                CannabisStrainConfig.GenerateMissingDefaults(!g_CPConfigUpdated);
                // Automatically load all available strain configs from disk
                InitCannabisStrainConfigs();
                CP_RebuildStrainOrder();

				// Genetic plants take their grow time and crops from their own strain (PlantBase.GetACPlantEntry).
				// Plants of the old per-strain classes still growing in plots use these registry entries.
				array<string> legacyStrains = CannabisStrainConfig.GetLegacyStrainNames();
				foreach (string strainName : legacyStrains)
				{
					string currentStrain = CP_StrainHelper.GetRetiredReplacement(strainName);
					CannabisStrainConfig strainCfg = g_CannabisStrainConfigs.Get(currentStrain);
					if (!strainCfg)
						strainCfg = CannabisStrainConfig.CreateDefaultFor(currentStrain);
					string plantType = CP_StrainHelper.GetPlantClass(strainName);
					AC_RegisterPlant(plantType, strainCfg.MinutesToGrow, 1, strainCfg.CropCount, true, true);
					CPDebugPrint("Pre-registered plant: " + plantType);
				}
				CPDebugPrint("Strains loaded: " + g_CPStrainOrder.Count());
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
