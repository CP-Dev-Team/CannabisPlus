class CP_CigarettePack_CannabisS1: CP_JointPack {
	override void SetActions()	{
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};