class CP_Pouch extends FirstAidKit
{
	ref array<string> CannabisPouchCargo = 
	{
		"CP_CannabisBagSkunk",
		"CP_CannabisBagBlue",
		"CP_CannabisBagKush",
		"CP_CannabisBagStardawg",
		"CP_CannabisBagFuture",
		"CP_CannabisBagS1",
		"CP_CannabisBagNomad",
		"CP_CannabisBagBlackFrost",
		"CP_CannabisSeedsSkunk",
		"CP_CannabisSeedsBlue",
		"CP_CannabisSeedsKush",
		"CP_CannabisSeedsStardawg",
		"CP_CannabisSeedsFuture",
		"CP_CannabisSeedsS1",
		"CP_CannabisSeedsNomad",
		"CP_CannabisSeedsBlackFrost",
		"CP_TobaccoSeeds",
		"CP_CannabisSeedsPackSkunk",
		"CP_CannabisSeedsPackBlue",
		"CP_CannabisSeedsPackKush",
		"CP_CannabisSeedsPackStardawg",
		"CP_CannabisSeedsPackFuture",
		"CP_CannabisSeedsPackS1",
		"CP_CannabisSeedsPackNomad",
		"CP_CannabisSeedsPackBlackFrost",
		"CP_TobaccoSeedsPack",
		"CP_Relief_Balm",
		"CP_CBDCrudeOil",
		"CP_CigarettePack_Empty",
		"CigarettePack_Chernamorka",
		"CigarettePack_Merkur",
		"CigarettePack_Partyzanka",
		"CP_CigarettePack_CannabisSkunk",
		"CP_CigarettePack_CannabisBlue",
		"CP_CigarettePack_CannabisKush",
		"CP_CigarettePack_CannabisStardawg",
		"CP_CigarettePack_CannabisFuture",
		"CP_CigarettePack_CannabisS1",
		"CP_CigarettePack_CannabisNomad",
		"CP_CigarettePack_CannabisBlackFrost",
		"CP_Cigarette",
		"CP_CannabisSkunk",
		"CP_CannabisBlue",
		"CP_CannabisKush",
		"CP_CannabisStardawg",
		"CP_CannabisFuture",
		"CP_CannabisS1",
		"CP_CannabisNomad",
		"CP_CannabisBlackFrost",
		"CP_Tobacco",
		"CP_JointBase",
		"CP_RollingPapers"
	};
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (!super.CanReceiveItemIntoCargo(item))
		{
			return false;
		}

		foreach (string allowedCargo : CannabisPouchCargo)
		{
			if (item.IsKindOf(allowedCargo))
			{
				return true;
			}
		}

		return false;
	}

	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		if (!super.CanSwapItemInCargo(child_entity, new_entity))
		{
			return false;
		}

		foreach (string allowedCargo : CannabisPouchCargo)
		{
			if (new_entity.IsKindOf(allowedCargo))
			{
				return true;
			}
		}

		return false;
	}
}