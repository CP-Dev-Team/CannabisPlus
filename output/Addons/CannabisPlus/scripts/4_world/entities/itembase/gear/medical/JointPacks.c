class CP_JointPack extends AC_CigarettePack_Empty
{
    string GetCpPackageName()
	{
        return CP_StrainHelper.GetJointFromPack(GetType());
    }

	override void SetActions()
	{
		AddAction(ActionUnpackJointBox);
		super.SetActions();
	}
}