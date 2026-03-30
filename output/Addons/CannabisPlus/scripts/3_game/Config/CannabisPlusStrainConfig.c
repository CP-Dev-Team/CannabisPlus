class CannabisStrainConfig
{
    int MinutesToGrow;
    int CropCount;
    int SeedsPerPackage;

	// Weed Effects.
	ref WeedEffectsConfig WeedEffects;

    void CannabisStrainConfig(int growMins = 8, int cropCount = 2, int seedCount = 9)
    {
        MinutesToGrow = growMins;
        CropCount = cropCount;
        SeedsPerPackage = seedCount;
        WeedEffects = new WeedEffectsConfig();
    }

    static CannabisStrainConfig CreateDefault()
    {
        return new CannabisStrainConfig(8, 2, 9);
    }

    static CannabisStrainConfig LoadStrain(string strainName)
    {
        CPDebugPrint("Loading strain: " + strainName);

        CannabisStrainConfig strain;
        string path = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder + "/" + strainName + ".json";

        if (FileExist(path))
        {
            strain = new CannabisStrainConfig();
            JsonFileLoader<CannabisStrainConfig>.JsonLoadFile(path, strain);
            strain.Validate();
            CPDebugPrint("Loaded from: " + path);
        }
        else
        {
            CPDebugPrint("File not found. Using default values for: " + strainName);
            strain = CreateDefault();
            strain.SaveIfMissing(strainName);
        }

        return strain;
    }

    static void GenerateAllDefaultsIfStrainsFolderMissing()
    {
        string strainsFolderPath = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder;
        if (!FileExist(strainsFolderPath))
        {
            CPDebugPrint("Strains folder not found. Generating default strain configs...");

            array<string> defaultStrains = {
                "Skunk",
                "BlueGod",
                "PurpleKush",
                "Stardawg",
                "S1",
                "Future",
                "Nomad",
                "BlackFrost"
            };

            foreach (string strainName : defaultStrains)
            {
                CreateDefault().SaveIfMissing(strainName);
            }

            CPDebugPrint("Default strain configs created.");
        }
    }

    void Validate()
    {
        if (MinutesToGrow < 1) MinutesToGrow = 1;
        if (CropCount < 1) CropCount = 1;
        if (SeedsPerPackage < 1) SeedsPerPackage = 1;
        if (!WeedEffects) WeedEffects = new WeedEffectsConfig();
    }

    void SaveIfMissing(string strainName)
    {
        string path = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder;
        if (!FileExist(path))
        {
            MakeDirectory(path);
        }

        string fullPath = path + "/" + strainName + ".json";
        if (!FileExist(fullPath))
        {
            CPDebugPrint("Saving default config for: " + strainName);
            JsonFileLoader<CannabisStrainConfig>.JsonSaveFile(fullPath, this);
        }
    }
}

class WeedEffectsConfig
{
    float HueIntensity;
    int RadBlurXPower;
    int RadBlurYPower;
    int RotBlurPow;
    
    void WeedEffectsConfig(float hueIntensity = 58.0, int radBlurX = 2, int radBlurY = 2, int rotBlur = 10)
    {
        HueIntensity = hueIntensity;
        RadBlurXPower = radBlurX;
        RadBlurYPower = radBlurY;
        RotBlurPow = rotBlur;
    }
};