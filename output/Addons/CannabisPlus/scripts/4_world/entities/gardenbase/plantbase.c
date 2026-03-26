modded class PlantBase
{
	override void Init(GardenBase garden_base, float fertility, float harvesting_efficiency, float water)
	{
		string plantType = this.GetType();

		// Cannabis plants - register dynamically from strain configs
		if (plantType.Contains("CP_Plant_Cannabis"))
		{
			string strainName = plantType.Substring(17, plantType.Length() - 17);

			if (g_CannabisStrainConfigs.Contains(strainName))
			{
				CannabisStrainConfig config = g_CannabisStrainConfigs.Get(strainName);
				// Cannabis: UseMinuteGrowTime = true, IncreaseCropOnFertilize = false
				AC_RegisterPlant(plantType, config.MinutesToGrow, 1, config.CropCount, true, false);
				CPDebugPrint("Registered cannabis strain for Init: " + strainName + " | MinutesToGrow: " + config.MinutesToGrow + " | Yield: " + config.CropCount);
			}
			else
			{
				CPDebugPrint("Warning: Strain config for '" + strainName + "' not found. Using default values.");
			}
		}

		// Let AC handle the actual Init (registry lookup, growth calc, fertility, etc.)
		super.Init(garden_base, fertility, harvesting_efficiency, water);
	}

	override void OnItemHarvested(ItemBase item, string itemType)
	{
		// Cannabis-specific harvest logic: set yield and strain on raw plants
		if (itemType.IndexOf("CP_Raw") >= 0 && itemType.IndexOf("CannabisPlant") >= 0)
		{
			CP_RawPlantBase plant = CP_RawPlantBase.Cast(item);
			if (plant)
			{
				plant.SetYield(GetCurrentYield());
				CPDebugPrint("Setting plant " + plant + " yield to " + GetCurrentYield());

				// Extract strain from class name (e.g., "PurpleKush" from "CP_RawPurpleKushCannabisPlant")
				string strainName = itemType.Substring(6, itemType.Length() - 19); // Remove "CP_Raw" (6) and "CannabisPlant" (13)
				plant.SetStrain(strainName);
				CPDebugPrint("Extracted strain: " + strainName + " for plant: " + itemType);
			}
		}

		if (itemType.IndexOf("CP_") >= 0)
		{
			CPDebugPrint("harvested " + item);
		}
	}
}