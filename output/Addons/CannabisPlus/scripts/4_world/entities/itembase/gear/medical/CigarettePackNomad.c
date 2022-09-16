class CP_CigarettePack_CannabisNomad: CP_JointPack {
	override void SetActions()	{
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};