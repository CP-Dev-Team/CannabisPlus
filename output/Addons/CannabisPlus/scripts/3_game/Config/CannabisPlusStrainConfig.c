class CannabisStrainConfig
{
    int GrowTime;
    int CropCount;
    int SeedCount;

    void CannabisStrainConfig(int growTime = 8, int cropCount = 2, int seedCount = 9)
    {
        GrowTime = growTime;
        CropCount = cropCount;
        SeedCount = seedCount;
    }

    static CannabisStrainConfig CreateDefault()
    {
        return new CannabisStrainConfig(8, 2, 9);
    }

static CannabisStrainConfig LoadStrain(string strainName)
{
    CPDebugPrint("Loading strain: " + strainName);

    string path = m_CPProfileDir + m_CPProfileFolder + "/" + strainName + ".json";

    if (FileExist(path))
    {
        CannabisStrainConfig strain = new CannabisStrainConfig(); // Empty
        CPDebugPrint("File found. Loading from: " + path);
        JsonFileLoader<CannabisStrainConfig>.JsonLoadFile(path, strain);
        return strain;
    }
    else
    {
        CPDebugPrint("File not found. Using default settings for: " + strainName);
        CannabisStrainConfig defaultStrain = CreateDefault(); // ✅ Always use this
        defaultStrain.SaveIfMissing(strainName);
        return defaultStrain;
    }
}

    void LoadAllStrains()
    {
        Print("[CP] Automatically loading all strain configs...");

        auto strainConfigs = new map<string, ref CannabisStrainConfig>();

        string strainFolder = m_CPProfileDir + m_CPProfileFolder;
        array<string> strainFiles = {};

        if (FileExist(strainFolder))
        {
            FindFileHandle handle;
            string fileName;
            int fileAttr;

            handle = FindFile(strainFolder + "/*.json", fileName, fileAttr, FindFileFlags.ALL);

            while (fileName != "")
            {
                string strainName = fileName.Substring(0, fileName.Length() - 5); // Removes ".json"
                Print("[CP] Found strain config file: " + strainName);
                
                // Load the strain config
                CannabisStrainConfig strainConfig = CannabisStrainConfig.LoadStrain(strainName);
                strainConfigs.Insert(strainName, strainConfig);

                if (!FindNextFile(handle, fileName, fileAttr))
                    break;
            }
            CloseFindFile(handle);
        }

        g_CannabisStrainConfigs = strainConfigs;
        Print("[CP] All strain configs loaded successfully.");
    }
    
    void SaveIfMissing(string strainName)
    {
        string path = m_CPProfileDir + m_CPProfileFolder;

        if (!FileExist(path))
        {
            CPDebugPrint("Directory does not exist. Creating: " + path);
            MakeDirectory(path);
        }

        string fullPath = path + "/" + strainName + ".json";
        if (!FileExist(fullPath)) // Only save if the file doesn't exist
        {
            CPDebugPrint("Saving default config for: " + strainName);
            JsonFileLoader<CannabisStrainConfig>.JsonSaveFile(fullPath, this);
        }
    }
};