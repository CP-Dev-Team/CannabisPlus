class CP_StrainHelper
{
	// Known prefixes ordered longest-first so we match the most specific one
	static const string PREFIX_BAG       = "CP_CannabisBag";
	static const string PREFIX_BRICK     = "CP_CannabisBrick";
	static const string PREFIX_JOINT_PACK = "CP_JointPack_";
	static const string PREFIX_SEEDS_PACK = "CP_CannabisSeedsPack";
	static const string PREFIX_PLANT     = "CP_Plant_Cannabis";
	static const string PREFIX_JOINT     = "CP_Joint";
	static const string PREFIX_BUD       = "CP_Cannabis";

	static string GetStrain(string className)
	{
		// Order matters — check longer/more-specific prefixes first
		if (className.IndexOf(PREFIX_BRICK) == 0)
			return className.Substring(PREFIX_BRICK.Length(), className.Length() - PREFIX_BRICK.Length());

		if (className.IndexOf(PREFIX_BAG) == 0)
			return className.Substring(PREFIX_BAG.Length(), className.Length() - PREFIX_BAG.Length());

		if (className.IndexOf(PREFIX_SEEDS_PACK) == 0)
			return className.Substring(PREFIX_SEEDS_PACK.Length(), className.Length() - PREFIX_SEEDS_PACK.Length());

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
}
