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
	string Look;				// whose textures the items use: a class in CfgCannabisStrainLooks ("" = plain textures)
	ref CP_StrainTraits Traits;	// reference traits, 0-100

    void CannabisStrainConfig(int growMins = 8, int cropCount = 2, int seedCount = 9)
    {
        MinutesToGrow = growMins;
        CropCount = cropCount;
        SeedsPerPackage = seedCount;
        WeedEffects = new WeedEffectsConfig();
        Traits = new CP_StrainTraits();
        Look = "";
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
            CannabisStrainConfig strain = CreateDefaultFor(strainName);
            strain.SaveIfMissing(strainName);
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
        // A strain with its own textures (a class in CfgCannabisStrainLooks named like it) uses them by default.
        if (Look == "" && CP_StrainLooks.Has(strainName))
            Look = strainName;
        if (Look != "" && !CP_StrainLooks.Has(Look))
        {
            Print("[CannabisPlus] WARNING: Strain " + strainName + " has an unknown Look \"" + Look + "\", using plain textures.");
            Look = "";
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

// The strain tree that ships with CannabisPlus: real strains with their commonly cited parents.
// - Foundation strains are found only (loot, traders): wild landraces, and real strains whose origin is unknown
//   or disputed (Chemdawg, Haze, Purple Skunk, Blackberry, Harlequin).
// - Every other strain is a cross of exactly two parents. A parent written "A+B" is the unnamed first cross of A
//   and B, used for real 3- and 4-way crosses (e.g. Skunk #1 = (Afghani x Colombian Gold) x Acapulco Gold),
//   so no strain names are invented.
// - A cross's reference traits are the average of its parents', and its tier is how many crosses deep it is.
// Trait values of foundation strains are game values, not lab data.
class CP_BuiltInStrains
{
    static array<string> GetNames()
    {
        array<string> names = {
            // foundation: wild landraces
            "Afghani", "Thai", "HinduKush", "AcapulcoGold", "ColombianGold", "DurbanPoison", "Hawaiian", "PurpleAfghani", "PurpleThai",
            // foundation: real strains of unknown or disputed origin
            "Chemdawg", "Haze", "PurpleSkunk", "Blackberry", "Harlequin",
            // crosses
            "NorthernLights", "OGKush", "PurpleKush", "TresDawg", "GodBud",
            "Skunk", "Blueberry", "Cookies", "Stardawg", "ZombieOG",
            "SuperSkunk", "BlueGod", "JackHerer", "SourDiesel"
        };
        return names;
    }

    // Built-in values for a strain, or null if it isn't one of the built-in strains.
    static CannabisStrainConfig Create(string name)
    {
        switch (name)
        {
            //                              display name, potency, yield, speed, hardiness, resin, CBD, aroma
            case "Afghani":         return MakeFoundation(name, "Afghani", 70, 65, 70, 80, 75, 5, 45, "Wild landrace from Afghanistan, the classic hash plant.");
            case "Thai":            return MakeFoundation(name, "Thai", 60, 45, 35, 50, 55, 5, 80, "Wild landrace from Thailand: tall, slow and fragrant.");
            case "HinduKush":       return MakeFoundation(name, "Hindu Kush", 72, 62, 68, 82, 78, 5, 50, "Wild landrace from the Hindu Kush mountains.");
            case "AcapulcoGold":    return MakeFoundation(name, "Acapulco Gold", 68, 60, 50, 55, 62, 5, 72, "Wild landrace from Mexico.");
            case "ColombianGold":   return MakeFoundation(name, "Colombian Gold", 65, 55, 45, 55, 60, 5, 70, "Wild landrace from Colombia's Santa Marta mountains.");
            case "DurbanPoison":    return MakeFoundation(name, "Durban Poison", 72, 55, 60, 60, 70, 3, 75, "Wild landrace from South Africa.");
            case "Hawaiian":        return MakeFoundation(name, "Hawaiian", 62, 58, 40, 52, 58, 5, 85, "Wild landrace from Hawaii.");
            case "PurpleAfghani":   return MakeFoundation(name, "Purple Afghani", 68, 60, 72, 80, 74, 5, 55, "Purple Afghan landrace.");
            case "PurpleThai":      return MakeFoundation(name, "Purple Thai", 62, 45, 38, 50, 58, 4, 82, "Purple Thai heirloom.");
            case "Chemdawg":        return MakeFoundation(name, "Chemdawg", 85, 55, 55, 60, 80, 3, 70, "Famous cut of unknown origin, first seen at a 1991 Grateful Dead show.");
            case "Haze":            return MakeFoundation(name, "Haze", 75, 45, 25, 45, 60, 3, 85, "Santa Cruz heirloom of tropical sativas; its exact parents are disputed.");
            case "PurpleSkunk":     return MakeFoundation(name, "Purple Skunk", 66, 62, 62, 65, 66, 5, 70, "Old Afghan-type line of unclear origin.");
            case "Blackberry":      return MakeFoundation(name, "Blackberry", 70, 60, 62, 68, 72, 5, 80, "A family of berry-scented lines rather than one fixed strain.");
            case "Harlequin":       return MakeFoundation(name, "Harlequin", 25, 60, 50, 70, 45, 85, 55, "High-CBD strain from Colombian Gold, Thai, Swiss and Nepali landraces.");

            //                          display name, parents
            case "NorthernLights":  return MakeCross(name, "Northern Lights", "Afghani", "Thai");
            case "OGKush":          return MakeCross(name, "OG Kush", "Chemdawg", "HinduKush");
            case "PurpleKush":      return MakeCross(name, "Purple Kush", "HinduKush", "PurpleAfghani");
            case "TresDawg":        return MakeCross(name, "Tres Dawg", "Chemdawg", "Afghani");
            case "GodBud":          return MakeCross(name, "God Bud", "Hawaiian", "PurpleSkunk");
            case "Skunk":           return MakeCross(name, "Skunk #1", "Afghani+ColombianGold", "AcapulcoGold");
            case "Blueberry":       return MakeCross(name, "Blueberry", "Afghani+PurpleThai", "Thai");
            case "Cookies":         return MakeCross(name, "Girl Scout Cookies", "OGKush", "DurbanPoison");
            case "Stardawg":        return MakeCross(name, "Stardawg", "Chemdawg", "TresDawg");
            case "ZombieOG":        return MakeCross(name, "Zombie OG", "OGKush", "Blackberry");
            case "SuperSkunk":      return MakeCross(name, "Super Skunk", "Skunk", "Afghani");
            case "BlueGod":         return MakeCross(name, "Blue God", "Blueberry", "GodBud");
            case "JackHerer":       return MakeCross(name, "Jack Herer", "NorthernLights+Haze", "Skunk+Haze");
            case "SourDiesel":      return MakeCross(name, "Sour Diesel", "Chemdawg", "SuperSkunk");
        }
        return null;
    }

    protected static CannabisStrainConfig MakeFoundation(string name, string displayName, int potency, int yield, int speed, int hardiness, int resin, int cbd, int aroma, string description)
    {
        CannabisStrainConfig strain = CannabisStrainConfig.CreateDefault();
        strain.DisplayName = displayName;
        strain.Description = description;
        if (CP_StrainLooks.Has(name)) strain.Look = name;	// no textures yet: plain textures
        strain.Tier = 0;
        strain.Traits = new CP_StrainTraits(potency, yield, speed, hardiness, resin, cbd, aroma);
        return strain;
    }

    protected static CannabisStrainConfig MakeCross(string name, string displayName, string parentA, string parentB)
    {
        CannabisStrainConfig strain = CannabisStrainConfig.CreateDefault();
        strain.DisplayName = displayName;
        if (CP_StrainLooks.Has(name)) strain.Look = name;	// no textures yet: plain textures
        strain.ParentA = parentA;
        strain.ParentB = parentB;
        strain.Tier = Math.Max(GetTier(parentA), GetTier(parentB)) + 1;
        // Kept in variables: a temporary result would be freed before its traits are read.
        CP_StrainTraits a = GetTraits(parentA);
        CP_StrainTraits b = GetTraits(parentB);
        strain.Traits = CP_StrainTraits.Average(a, b);
        return strain;
    }

    // Reference traits of a parent: a built-in strain, or "A+B" (the average of A and B).
    static CP_StrainTraits GetTraits(string parent)
    {
        int plus = parent.IndexOf("+");
        if (plus >= 0)
        {
            CP_StrainTraits a = GetTraits(parent.Substring(0, plus));
            CP_StrainTraits b = GetTraits(parent.Substring(plus + 1, parent.Length() - plus - 1));
            return CP_StrainTraits.Average(a, b);
        }

        CannabisStrainConfig strain = Create(parent);
        if (!strain)
            return new CP_StrainTraits();
        // A copy: strain (and its traits) is freed when this function ends.
        return strain.Traits.Copy();
    }

    // How many crosses deep a parent is: a built-in strain's tier, or "A+B" = one cross above the deeper of A and B.
    static int GetTier(string parent)
    {
        int plus = parent.IndexOf("+");
        if (plus >= 0)
            return Math.Max(GetTier(parent.Substring(0, plus)), GetTier(parent.Substring(plus + 1, parent.Length() - plus - 1))) + 1;

        CannabisStrainConfig strain = Create(parent);
        if (!strain)
            return 0;
        return strain.Tier;
    }
}

// Strain textures: classes in CfgCannabisStrainLooks (genetics/config.cpp). Each genetic item class says in
// cpLookTextures[] / cpLookMaterials[] which look entry goes on each of its hidden selections.
class CP_StrainLooks
{
    protected static ref TStringArray s_Names;

    // Every look, sorted (the same on the server and on clients, so items sync a look as its position).
    static TStringArray GetNames()
    {
        if (!s_Names)
        {
            s_Names = new TStringArray;
            string path = "CfgCannabisStrainLooks";
            int count = g_Game.ConfigGetChildrenCount(path);
            for (int i = 0; i < count; i++)
            {
                string name;
                g_Game.ConfigGetChildName(path, i, name);
                s_Names.Insert(name);
            }
            s_Names.Sort();
        }
        return s_Names;
    }

    static bool Has(string look)
    {
        return look != "" && GetNames().Find(look) != -1;
    }

    static int GetIndex(string look)
    {
        return GetNames().Find(look);
    }

    static string GetByIndex(int index)
    {
        TStringArray names = GetNames();
        if (index < 0 || index >= names.Count())
            return "";
        return names[index];
    }

    // A texture or material of a look, e.g. ("Skunk", "bag"); "" if the look has none.
    static string Get(string look, string entry)
    {
        string value = "";
        if (look != "" && entry != "")
            g_Game.ConfigGetText("CfgCannabisStrainLooks " + look + " " + entry, value);
        return value;
    }
}
