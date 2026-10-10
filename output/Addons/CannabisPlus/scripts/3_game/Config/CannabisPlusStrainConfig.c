// One strain in the registry: profiles/CannabisPlus/Strains/<name>.json. Every strain uses the same set of
// "genetic" item classes; the strain only lives on the items as a record (CP_StrainRecord), so server owners
// can add strains here without new classes.
class CannabisStrainConfig
{
    int MinutesToGrow;
    int CropCount;
    int SeedsPerPackage;

	// Weed Effects.
	ref WeedEffectsConfig WeedEffects;

	// Genetics.
	string DisplayName;			// shown in item names, e.g. "Northern Lights"
	string Description;			// optional extra line in the item description
	int Tier;					// 0 = wild landrace, 1-4 = how many crosses deep it is
	string ParentA;				// the two strains it is bred from ("" for landraces)
	string ParentB;
	string Look;				// whose textures the items use: Skunk, BlueGod, PurpleKush, Stardawg, S1, Future, Nomad or BlackFrost
	ref CP_StrainTraits Traits;	// reference traits, 0-100

    void CannabisStrainConfig(int growMins = 8, int cropCount = 2, int seedCount = 9)
    {
        MinutesToGrow = growMins;
        CropCount = cropCount;
        SeedsPerPackage = seedCount;
        WeedEffects = new WeedEffectsConfig();
        Traits = new CP_StrainTraits();
        Look = "Skunk";
    }

    static CannabisStrainConfig CreateDefault()
    {
        return new CannabisStrainConfig(8, 2, 9);
    }

    // The values a strain starts with: the built-in values for strains that ship with CannabisPlus,
    // otherwise generic values with the file name as display name.
    static CannabisStrainConfig CreateDefaultFor(string strainName)
    {
        CannabisStrainConfig strain = CP_BuiltInStrains.Create(strainName);
        if (!strain)
        {
            strain = CreateDefault();
            strain.DisplayName = strainName;
        }
        return strain;
    }

    static CannabisStrainConfig LoadStrain(string strainName)
    {
        CPDebugPrint("Loading strain: " + strainName);

        CannabisStrainConfig strain;
        string path = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder + "/" + strainName + ".json";

        if (FileExist(path))
        {
            // Settings missing from the file (e.g. the genetics added in 4.0) keep the strain's default.
            strain = CreateDefaultFor(strainName);
            string error;
            if (!JsonFileLoader<CannabisStrainConfig>.LoadFile(path, strain, error))
            {
                // Broken json (e.g. a typo): leave the server's file untouched and use defaults for this strain.
                Print("[CannabisPlus] ERROR: " + error);
                Print("[CannabisPlus] ERROR: Using default settings for strain " + strainName + " until " + path + " is fixed.");
                return CreateDefaultFor(strainName);
            }
            strain.Validate(strainName);
            // Rewrite the file so newly added settings appear and removed ones are dropped.
            strain.Save(strainName);
            CPDebugPrint("Loaded from: " + path);
        }
        else
        {
            CPDebugPrint("File not found. Using default values for: " + strainName);
            strain = CreateDefaultFor(strainName);
            strain.SaveIfMissing(strainName);
        }

        return strain;
    }

    // The strains that ship with CannabisPlus.
    static array<string> GetDefaultStrainNames()
    {
        return CP_BuiltInStrains.GetNames();
    }

    // The 8 strains CannabisPlus 3 had their own item classes for. Their old items turn into genetic items.
    static array<string> GetLegacyStrainNames()
    {
        array<string> legacyStrains = {
            "Skunk",
            "BlueGod",
            "PurpleKush",
            "Stardawg",
            "S1",
            "Future",
            "Nomad",
            "BlackFrost"
        };
        return legacyStrains;
    }

    // Writes the built-in strains that have no file yet. Runs when the strains folder is new and after a
    // CannabisPlus update (so new built-in strains appear); a strain file deleted on purpose stays deleted
    // until the next update.
    static void GenerateMissingDefaults(bool onlyIfFolderMissing)
    {
        string strainsFolderPath = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder;
        if (onlyIfFolderMissing && FileExist(strainsFolderPath))
            return;

        CPDebugPrint("Writing missing built-in strain configs...");
        array<string> defaultStrains = GetDefaultStrainNames();
        foreach (string strainName : defaultStrains)
        {
            CreateDefaultFor(strainName).SaveIfMissing(strainName);
        }
    }

    void Validate(string strainName = "")
    {
        if (MinutesToGrow < 1) MinutesToGrow = 1;
        if (CropCount < 1) CropCount = 1;
        if (SeedsPerPackage < 1) SeedsPerPackage = 1;
        if (!WeedEffects) WeedEffects = new WeedEffectsConfig();
        if (!Traits) Traits = new CP_StrainTraits();
        Traits.Validate();
        if (Tier < 0) Tier = 0;
        if (DisplayName == "") DisplayName = strainName;
        if (GetLegacyStrainNames().Find(Look) == -1)
        {
            Print("[CannabisPlus] WARNING: Strain " + strainName + " has an unknown Look \"" + Look + "\", using Skunk.");
            Look = "Skunk";
        }
    }

    // Stability of items of this named strain: wild landraces breed truest.
    int GetStability()
    {
        if (Tier == 0)
            return 90;
        return 85;
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
            Save(strainName);
        }
    }

    void Save(string strainName)
    {
        string path = m_CPProfileDir + m_CPProfileFolder + "/" + m_CPStrainsFolder;
        if (!FileExist(path))
            MakeDirectory(path);

        string error;
        if (!JsonFileLoader<CannabisStrainConfig>.SaveFile(path + "/" + strainName + ".json", this, error))
            Print("[CannabisPlus] ERROR: " + error);
    }

    // Copy for the client (the config map doesn't arrive intact over RPC, so it is rebuilt field by field).
    CannabisStrainConfig CopyForClient()
    {
        CannabisStrainConfig copy = new CannabisStrainConfig(MinutesToGrow, CropCount, SeedsPerPackage);
        if (WeedEffects)
            copy.WeedEffects = new WeedEffectsConfig(WeedEffects.HueIntensity, WeedEffects.RadBlurXPower, WeedEffects.RadBlurYPower, WeedEffects.RotBlurPow);
        copy.DisplayName = DisplayName;
        copy.Description = Description;
        copy.Tier = Tier;
        copy.ParentA = ParentA;
        copy.ParentB = ParentB;
        copy.Look = Look;
        if (Traits)
            copy.Traits = Traits.Copy();
        return copy;
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

// A strain's reference traits (see the design doc: potency, yield, speed, hardiness, resin, CBD, aroma).
class CP_StrainTraits
{
    int Potency;
    int Yield;
    int Speed;
    int Hardiness;
    int Resin;
    int CBD;
    int Aroma;

    void CP_StrainTraits(int potency = 50, int yield = 50, int speed = 50, int hardiness = 50, int resin = 50, int cbd = 5, int aroma = 50)
    {
        Potency = potency;
        Yield = yield;
        Speed = speed;
        Hardiness = hardiness;
        Resin = resin;
        CBD = cbd;
        Aroma = aroma;
    }

    int Get(CP_ETrait trait)
    {
        switch (trait)
        {
            case CP_ETrait.POTENCY: return Potency;
            case CP_ETrait.YIELD: return Yield;
            case CP_ETrait.SPEED: return Speed;
            case CP_ETrait.HARDINESS: return Hardiness;
            case CP_ETrait.RESIN: return Resin;
            case CP_ETrait.CBD: return CBD;
            case CP_ETrait.AROMA: return Aroma;
        }
        return 0;
    }

    void Set(CP_ETrait trait, int value)
    {
        switch (trait)
        {
            case CP_ETrait.POTENCY: Potency = value; break;
            case CP_ETrait.YIELD: Yield = value; break;
            case CP_ETrait.SPEED: Speed = value; break;
            case CP_ETrait.HARDINESS: Hardiness = value; break;
            case CP_ETrait.RESIN: Resin = value; break;
            case CP_ETrait.CBD: CBD = value; break;
            case CP_ETrait.AROMA: Aroma = value; break;
        }
    }

    void Validate()
    {
        for (int i = 0; i < CP_ETrait.COUNT; i++)
        {
            Set(i, Math.Clamp(Get(i), 0, 100));
        }
    }

    CP_StrainTraits Copy()
    {
        return new CP_StrainTraits(Potency, Yield, Speed, Hardiness, Resin, CBD, Aroma);
    }

    // A cross's reference traits: the average of its parents'.
    static CP_StrainTraits Average(CP_StrainTraits a, CP_StrainTraits b)
    {
        CP_StrainTraits result = new CP_StrainTraits();
        for (int i = 0; i < CP_ETrait.COUNT; i++)
        {
            result.Set(i, Math.Round((a.Get(i) + b.Get(i)) / 2.0));
        }
        return result;
    }
};

// The strain tree that ships with CannabisPlus: 7 wild landraces and 16 crosses of exactly two parents.
// A cross's reference traits are the average of its parents', so every named strain can be bred.
class CP_BuiltInStrains
{
    static array<string> GetNames()
    {
        array<string> names = {
            // wild landraces
            "Afghan", "Thai", "ColombianGold", "AcapulcoGold", "HinduKush", "Hawaiian", "SwissHemp",
            // tier 1
            "NorthernLights", "GoldenCross", "PurpleAfghani", "Chemdawg", "Nomad",
            // tier 2
            "Skunk", "PurpleKush", "Blueberry", "GodBud", "TresDawg",
            // tier 3
            "BlueGod", "Stardawg", "GoldenGoat", "S1", "BlackFrost",
            // tier 4
            "Future"
        };
        return names;
    }

    static array<string> GetLandraceNames()
    {
        array<string> names = {"Afghan", "Thai", "ColombianGold", "AcapulcoGold", "HinduKush", "Hawaiian", "SwissHemp"};
        return names;
    }

    // Built-in values for a strain, or null if it isn't one of the built-in strains.
    static CannabisStrainConfig Create(string name)
    {
        switch (name)
        {
            //                  name, display name, look, potency, yield, speed, hardiness, resin, CBD, aroma
            case "Afghan":          return MakeLandrace("Afghan", "Nomad", 70, 65, 70, 80, 75, 5, 45);
            case "Thai":            return MakeLandrace("Thai", "Stardawg", 60, 45, 35, 50, 55, 5, 80);
            case "ColombianGold":   return MakeLandrace("Colombian Gold", "Skunk", 65, 55, 45, 55, 60, 5, 70);
            case "AcapulcoGold":    return MakeLandrace("Acapulco Gold", "Future", 68, 60, 50, 55, 62, 5, 72);
            case "HinduKush":       return MakeLandrace("Hindu Kush", "PurpleKush", 72, 62, 68, 82, 78, 5, 50);
            case "Hawaiian":        return MakeLandrace("Hawaiian", "S1", 62, 58, 40, 52, 58, 5, 85);
            case "SwissHemp":       return MakeLandrace("Swiss Hemp", "S1", 10, 70, 60, 85, 30, 80, 40);

            //                  display name, look, tier, parents
            case "NorthernLights":  return MakeCross("Northern Lights", "BlackFrost", 1, "Afghan", "Thai");
            case "GoldenCross":     return MakeCross("Golden Cross", "Future", 1, "ColombianGold", "AcapulcoGold");
            case "PurpleAfghani":   return MakeCross("Purple Afghani", "PurpleKush", 1, "Afghan", "HinduKush");
            case "Chemdawg":        return MakeCross("Chemdawg", "Stardawg", 1, "Thai", "HinduKush");
            case "Nomad":           return MakeCross("Nomad", "Nomad", 1, "Afghan", "AcapulcoGold");
            case "Skunk":           return MakeCross("Skunk", "Skunk", 2, "Afghan", "GoldenCross");
            case "PurpleKush":      return MakeCross("Purple Kush", "PurpleKush", 2, "HinduKush", "PurpleAfghani");
            case "Blueberry":       return MakeCross("Blueberry", "BlueGod", 2, "Thai", "PurpleAfghani");
            case "GodBud":          return MakeCross("God Bud", "BlueGod", 2, "Hawaiian", "PurpleAfghani");
            case "TresDawg":        return MakeCross("Tres Dawg", "Stardawg", 2, "Chemdawg", "Afghan");
            case "BlueGod":         return MakeCross("Blue God", "BlueGod", 3, "Blueberry", "GodBud");
            case "Stardawg":        return MakeCross("Stardawg", "Stardawg", 3, "Chemdawg", "TresDawg");
            case "GoldenGoat":      return MakeCross("Golden Goat", "Future", 3, "Hawaiian", "Skunk");
            case "S1":              return MakeCross("S1", "S1", 3, "SwissHemp", "Skunk");
            case "BlackFrost":      return MakeCross("Black Frost", "BlackFrost", 3, "NorthernLights", "PurpleKush");
            case "Future":          return MakeCross("Future", "Future", 4, "GoldenGoat", "PurpleKush");
        }
        return null;
    }

    protected static CannabisStrainConfig MakeLandrace(string displayName, string look, int potency, int yield, int speed, int hardiness, int resin, int cbd, int aroma)
    {
        CannabisStrainConfig strain = CannabisStrainConfig.CreateDefault();
        strain.DisplayName = displayName;
        strain.Look = look;
        strain.Tier = 0;
        strain.Traits = new CP_StrainTraits(potency, yield, speed, hardiness, resin, cbd, aroma);
        return strain;
    }

    protected static CannabisStrainConfig MakeCross(string displayName, string look, int tier, string parentA, string parentB)
    {
        CannabisStrainConfig strain = CannabisStrainConfig.CreateDefault();
        strain.DisplayName = displayName;
        strain.Look = look;
        strain.Tier = tier;
        strain.ParentA = parentA;
        strain.ParentB = parentB;
        // Kept in variables: a temporary result would be freed before its traits are read.
        CannabisStrainConfig a = Create(parentA);
        CannabisStrainConfig b = Create(parentB);
        strain.Traits = CP_StrainTraits.Average(a.Traits, b.Traits);
        return strain;
    }
}
