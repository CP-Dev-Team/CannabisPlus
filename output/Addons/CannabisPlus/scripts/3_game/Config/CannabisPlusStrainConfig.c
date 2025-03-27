
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

    static CannabisStrainConfig LoadStrain(string strainName)
    {
        CannabisStrainConfig strain = new CannabisStrainConfig();
        string path = "$profile:CannabisPlus/Strains/" + strainName + ".json";

        if (FileExist(path))
        {
            JsonFileLoader<CannabisStrainConfig>.JsonLoadFile(path, strain);
        }
        else
        {
            strain.SaveStrain(strainName);  // Save default if file doesn't exist
        }

        return strain;
    }
    
    void LoadDefaultStrain(string strainName)
    {
        switch (strainName)
        {
            case "CannabisSkunk":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisKush":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisBlue":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisStardawg":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisFuture":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisS1":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisNomad":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            case "CannabisBlackFrost":
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
            default:
                GrowTime = 8;
                CropCount = 2;
                SeedCount = 9;
                break;
        }

        SaveStrain(strainName);
    }

    void SaveStrain(string strainName)
    {
        string path = "$profile:CannabisPlus/Strains/" + strainName + ".json";
        JsonFileLoader<CannabisStrainConfig>.JsonSaveFile(path, this);
    }
};
