class CP_StrainHelper
{
	// Known prefixes ordered longest-first so we match the most specific one
	static const string PREFIX_BAG       = "CP_CannabisBag";
	static const string PREFIX_BRICK     = "CP_CannabisBrick";
	static const string PREFIX_JOINT_PACK = "CP_JointPack_";
	static const string PREFIX_SEEDS_PACK = "CP_CannabisSeedsPack";
	static const string PREFIX_SEEDS     = "CP_CannabisSeeds";
	static const string PREFIX_PLANT     = "CP_Plant_Cannabis";
	static const string PREFIX_JOINT     = "CP_Joint";
	static const string PREFIX_BUD       = "CP_Cannabis";
	static const string PREFIX_RAW       = "CP_Raw";
	static const string SUFFIX_RAW       = "CannabisPlant";

	// The "strain" part of the genetic item classes (CP_CannabisGenetic, CP_CannabisBagGenetic, ...). Their real
	// strain is in the record each item carries.
	static const string GENETIC          = "Genetic";

	static string GetStrain(string className)
	{
		// Order matters — check longer/more-specific prefixes first
		if (className.IndexOf(PREFIX_BRICK) == 0)
			return className.Substring(PREFIX_BRICK.Length(), className.Length() - PREFIX_BRICK.Length());

		if (className.IndexOf(PREFIX_BAG) == 0)
			return className.Substring(PREFIX_BAG.Length(), className.Length() - PREFIX_BAG.Length());

		if (className.IndexOf(PREFIX_SEEDS_PACK) == 0)
			return className.Substring(PREFIX_SEEDS_PACK.Length(), className.Length() - PREFIX_SEEDS_PACK.Length());

		if (className.IndexOf(PREFIX_SEEDS) == 0)
			return className.Substring(PREFIX_SEEDS.Length(), className.Length() - PREFIX_SEEDS.Length());

		// CP_Raw<Strain>CannabisPlant
		int rawLength = PREFIX_RAW.Length() + SUFFIX_RAW.Length();
		if (className.IndexOf(PREFIX_RAW) == 0 && className.Length() > rawLength && className.Substring(className.Length() - SUFFIX_RAW.Length(), SUFFIX_RAW.Length()) == SUFFIX_RAW)
			return className.Substring(PREFIX_RAW.Length(), className.Length() - rawLength);

		if (className.IndexOf(PREFIX_JOINT_PACK) == 0)
			return className.Substring(PREFIX_JOINT_PACK.Length(), className.Length() - PREFIX_JOINT_PACK.Length());

		if (className.IndexOf(PREFIX_PLANT) == 0)
			return className.Substring(PREFIX_PLANT.Length(), className.Length() - PREFIX_PLANT.Length());

		if (className.IndexOf(PREFIX_JOINT) == 0)
			return className.Substring(PREFIX_JOINT.Length(), className.Length() - PREFIX_JOINT.Length());

		if (className.IndexOf(PREFIX_BUD) == 0)
			return className.Substring(PREFIX_BUD.Length(), className.Length() - PREFIX_BUD.Length());

		return "";
	}

	static string GetBudClass(string strain)       { return PREFIX_BUD + strain; }
	static string GetBagClass(string strain)        { return PREFIX_BAG + strain; }
	static string GetBrickClass(string strain)      { return PREFIX_BRICK + strain; }
	static string GetJointClass(string strain)      { return PREFIX_JOINT + strain; }
	static string GetJointPackClass(string strain)  { return PREFIX_JOINT_PACK + strain; }
	static string GetSeedsPackClass(string strain)  { return PREFIX_SEEDS_PACK + strain; }
	static string GetPlantClass(string strain)      { return PREFIX_PLANT + strain; }

	// Convenience: derive target class directly from a source classname
	static string GetBagFromBud(string budClass)       { return GetBagClass(GetStrain(budClass)); }
	static string GetBrickFromBag(string bagClass)     { return GetBrickClass(GetStrain(bagClass)); }
	static string GetJointFromBud(string budClass)     { return GetJointClass(GetStrain(budClass)); }
	static string GetJointPackFromJoint(string jointClass)  { return GetJointPackClass(GetStrain(jointClass)); }
	static string GetJointFromPack(string packClass)   { return GetJointClass(GetStrain(packClass)); }
	static string GetBudFromBag(string bagClass)       { return GetBudClass(GetStrain(bagClass)); }
	static string GetBagFromBrick(string brickClass)   { return GetBagClass(GetStrain(brickClass)); }

	static bool IsValidStrain(string strain)
	{
		return strain != "";
	}

	// The genetic class an item class belongs with, e.g. CP_CannabisBagSkunk -> CP_CannabisBagGenetic,
	// CP_RawSkunkCannabisPlant -> CP_RawGeneticCannabisPlant. "" if the class has no strain in its name.
	static string GetGeneticClass(string className)
	{
		return ReplaceStrain(className, GENETIC);
	}

	// The same kind of item with another strain in its name, e.g. (CP_CannabisBagGenetic, Skunk) -> CP_CannabisBagSkunk.
	static string ReplaceStrain(string className, string newStrain)
	{
		string strain = GetStrain(className);
		if (strain == "")
			return "";

		// The strain is always the last part of the name, except for raw plants (CP_Raw<Strain>CannabisPlant).
		if (className.IndexOf(PREFIX_RAW) == 0)
			return PREFIX_RAW + newStrain + SUFFIX_RAW;
		return className.Substring(0, className.Length() - strain.Length()) + newStrain;
	}

	// The strain an item class from CannabisPlus 3 (one class per strain) stands for now, or "" for any other
	// class. Retired strains (not real strains) give the real strain their items turn into.
	static string GetLegacyStrain(string className)
	{
		string strain = GetStrain(className);
		if (strain == "" || strain == GENETIC)
			return "";
		if (CannabisStrainConfig.GetLegacyStrainNames().Find(strain) == -1)
			return "";
		return GetRetiredReplacement(strain);
	}

	// CannabisPlus 3 strains that aren't real strains were retired in 4.0; their items become these.
	static string GetRetiredReplacement(string strain)
	{
		switch (strain)
		{
			case "Nomad":      return "Afghani";
			case "BlackFrost": return "NorthernLights";
			case "S1":         return "Harlequin";
			case "Future":     return "SuperSkunk";
		}
		return strain;
	}

	static bool IsRetiredStrain(string strain)
	{
		return GetRetiredReplacement(strain) != strain;
	}

	// Lists files in the server profile. DayZ 1.30 broke FindFile on $profile: paths
	// (https://report.bistudio.com/issues/DZEXP-134): it reads the last argument as a file system index.
	static FindFileHandle FindProfileFile(string pattern, out string fileName, out FileAttr fileAttr)
	{
	#ifdef DAYZ_1_29
		return FindFile(pattern, fileName, fileAttr, FindFileFlags.DIRECTORIES);
	#else
		// -1 lists $profile: wherever the profiles folder is (tested on a 1.30 server with -profiles outside the
		// server folder: -1 found the files, 0/1/2/3 found nothing). Thanks to the server owner who reported it.
		int allFileSystems = -1;
		FindFileHandle handle = FindFile(pattern, fileName, fileAttr, allFileSystems);
		if (handle)
			return handle;

		// Older work-arounds, in case -1 stops working: CF can list the profile when the profiles folder is
		// inside the server folder (otherwise it logs a script error, so skip it then); plain FindFile finds
		// nothing and the caller falls back to the built-in strain files by name.
		if (!CanCFListProfile())
			return FindFile(pattern, fileName, fileAttr, FindFileFlags.DIRECTORIES);
		return CF.FindFileEx(pattern, fileName, fileAttr, FindFileFlags.DIRECTORIES);
	#endif
	}

	// Same check CF.FindFileEx makes: the -profiles folder (its last path part) must exist inside the server folder.
	static bool CanCFListProfile()
	{
		string profiles;
		if (!GetCLIParam("profiles", profiles))
			return false;

		profiles.Replace("\\", "/");
		while (profiles.Length() > 0 && profiles.Substring(profiles.Length() - 1, 1) == "/")
			profiles = profiles.Substring(0, profiles.Length() - 1);

		if (profiles.IndexOf("/") == 0 || profiles.IndexOf(":/") == 1)
		{
			int lastSlash = profiles.LastIndexOf("/");
			profiles = profiles.Substring(lastSlash + 1, profiles.Length() - lastSlash - 1);
		}

		return profiles != "" && FileExist(profiles);
	}
}
