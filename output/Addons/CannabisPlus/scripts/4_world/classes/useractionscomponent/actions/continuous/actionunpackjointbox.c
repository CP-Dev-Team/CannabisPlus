// Joint packs unpack through AgricultureCore's shared ActionAC_UnpackPack into genetic joints;
// the joints get the pack's strain (ItemBase.ACInheritFrom).
class ActionUnpackJointBoxCB : ActionAC_UnpackPackCB
{
};

class ActionUnpackJointBox : ActionAC_UnpackPack
{
	void ActionUnpackJointBox()
	{
		m_Text = "#cp_unpack";
	}

	override protected string GetUnpackItemType(ItemBase pack)
	{
		CP_JointPack jointPack;
		if (Class.CastTo(jointPack, pack))
			return CP_StrainHelper.GetGeneticClass(CP_StrainHelper.GetJointFromPack(jointPack.GetType()));

		return super.GetUnpackItemType(pack);
	}
};

// Backward compatibility for mods still referencing the old unpack action name.
class ActionUnpackCigaretteBoxCB : ActionUnpackJointBoxCB
{
};

class ActionUnpackCigaretteBox : ActionUnpackJointBox
{
};
