class CP_Pouch extends FirstAidKit
{
	ref array<string> CannabisPouchCargo = 
	{
		"CP_CannabisBags",
		"CP_CannabisSeeds",
		"CP_CannabisSeedsPack",
		"CP_Relief_Balm",
		"CP_CBDCrudeOil",
		"AC_CigarettePack_Empty",
		"CP_JointPack",
		"CP_CannabisBud",
		"CP_JointBase",
		"AC_RollingPapers"
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