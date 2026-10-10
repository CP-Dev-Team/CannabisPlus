// The strain of the seed being planted, handed from GardenBase.CreatePlant to the new plant's Init.
static ref CP_StrainRecord g_CPPendingPlantRecord;

modded class GardenBase
{
	override void CreatePlant(Slot slot)
	{
		CP_StrainRecord record = null;
		ItemBase seed = slot.GetSeed();
		if (seed && g_Game.IsServer())
		{
			record = seed.CPGetRecord();
			// Seeds of the old per-strain classes grow a genetic plant of their strain too.
			if (record && seed.IsKindOf("CP_CannabisSeeds"))
				slot.m_PlantType = "CP_Plant_CannabisGenetic";
		}

		g_CPPendingPlantRecord = record;
		super.CreatePlant(slot);
		g_CPPendingPlantRecord = null;
	}
}

modded class PlantBase
{
	// Genetic plants grow by their own strain's settings; plants of the old per-strain classes use the
	// registry entries MissionServer makes for them.
	override AG_PlantRegistryEntry GetACPlantEntry()
	{
		if (!IsCPGenetic())
			return super.GetACPlantEntry();

		if (!m_CPRecord && g_Game.IsServer())
		{
			if (g_CPPendingPlantRecord)
				CPSetRecord(g_CPPendingPlantRecord);
			else
				CPSetRecord(CP_StrainRecord.Named(CP_Genetics.PickWildStrain()));
		}

		AG_PlantRegistryEntry entry = new AG_PlantRegistryEntry();
		entry.UseMinuteGrowTime = true;
		entry.IncreaseCropOnFertilize = true;
		entry.CropCount = 1;

		CannabisStrainConfig strainConfig = CPGetStrainConfig();
		if (strainConfig)
		{
			entry.GrowTime = strainConfig.MinutesToGrow;
			entry.InitialYield = strainConfig.CropCount;
		}
		return entry;
	}

	override void OnItemHarvested(ItemBase item, string itemType)
	{
		super.OnItemHarvested(item, itemType);

		// Raw plants remember how many buds they give on the drying post.
		CP_RawPlantBase plant = CP_RawPlantBase.Cast(item);
		if (plant)
		{
			plant.SetYield(GetCurrentYield());
			CPDebugPrint("Setting plant " + plant + " yield to " + GetCurrentYield());
		}

		if (item)
			item.CPSetRecord(CPGetRecord());
	}

	// Vanilla puts the CfgHorticulture texture back on the plant; keep the strain's look.
	override void ChangeInfestation(bool is_infested)
	{
		super.ChangeInfestation(is_infested);

		if (IsCPGenetic())
			CPApplyLook(true);
	}
}
