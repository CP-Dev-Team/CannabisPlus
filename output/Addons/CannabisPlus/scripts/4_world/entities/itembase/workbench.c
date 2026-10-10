// CannabisPlus workbench on the AgricultureCore bench framework (AC_BenchBase).
// Recipes are in workbench/config.cpp (CfgACBenchRecipes CP_Workbench); amounts, time and power come from
// CP_WorkbenchSettings. Players use "Open bench": fill bags (buds + empty bag -> bag of the same strain) and
// wrap bricks (bags + plastic wrap -> brick of the same strain). Both keep going while there's enough.

class CP_Workbench_Kit extends AC_BenchKitBase
{
}

class CP_Workbench extends AC_BenchBase
{
	protected WorkbenchConfig GetCPBenchConfig()
	{
		CannabisPlusConfigManager config = GetCPConfig();
		if (config)
			return config.CP_WorkbenchSettings;
		return null;
	}

	// ------------------------------------------------------------------ settings

	override bool ACRequiresPower()
	{
		WorkbenchConfig config = GetCPBenchConfig();
		if (!config)
			return true;
		return config.RequireBattery == 1;
	}

	// PowerUsed is a percentage of a full truck battery (1500) per batch.
	override float GetACEnergyNeeded(AC_BenchRecipe recipe)
	{
		if (!ACRequiresPower())
			return 0;
		WorkbenchConfig config = GetCPBenchConfig();
		if (!config)
			return recipe.Energy;
		return config.PowerUsed * 1500 / 100;
	}

	override float GetACRecipeSeconds(AC_BenchRecipe recipe)
	{
		WorkbenchConfig config = GetCPBenchConfig();
		if (!config)
			return recipe.Seconds;
		return config.ProcessingSeconds;
	}

	override int GetACInputAmount(AC_BenchRecipe recipe, int inputIndex)
	{
		WorkbenchConfig config = GetCPBenchConfig();
		if (config && inputIndex == 0 && recipe.Name == "CP_FillBags")
			return config.BudsPerBag;
		if (config && inputIndex == 0 && recipe.Name == "CP_WrapBricks")
			return config.BagsPerBrick;
		if (config && inputIndex == 1 && recipe.Name == "CP_WrapBricks")
			return config.PlasticWrapUsage;
		return super.GetACInputAmount(recipe, inputIndex);
	}

	// ------------------------------------------------------------------ strain-specific products

	// The "same" inputs are keyed "<genetic class>|<strain record key>" (ItemBase.GetACSameKey), so products are
	// always genetic bags / bricks; OnACOutputCreated gives them the strain. Batches saved before CannabisPlus 4
	// stored the old class name (e.g. CP_CannabisSkunk) instead.
	override string ResolveACOutputType(AC_BenchRecipe recipe, string token, TStringArray usedTypes)
	{
		if (!usedTypes || usedTypes.Count() == 0 || usedTypes[0] == "")
			return "";

		string strain = CP_StrainHelper.GetStrain(GetCPUsedType(usedTypes[0]));
		if (!CP_StrainHelper.IsValidStrain(strain))
			return "";

		if (token == "@CP_BagFromBud")
			return CP_StrainHelper.GetGeneticClass(CP_StrainHelper.GetBagClass(strain));
		if (token == "@CP_BrickFromBag")
			return CP_StrainHelper.GetGeneticClass(CP_StrainHelper.GetBrickClass(strain));
		return super.ResolveACOutputType(recipe, token, usedTypes);
	}

	override void OnACOutputCreated(AC_BenchRecipe recipe, AC_BenchIngredient output, ItemBase product)
	{
		super.OnACOutputCreated(recipe, output, product);

		CP_StrainRecord record = GetCPUsedRecord();
		if (record)
			product.CPSetRecord(record);
	}

	// Products only top up stacks of the same strain.
	override bool CanACTopUp(AC_BenchRecipe recipe, AC_BenchIngredient output, ItemBase stack)
	{
		CP_StrainRecord record = GetCPUsedRecord();
		if (!record || !stack.IsCPGenetic())
			return super.CanACTopUp(recipe, output, stack);
		return stack.CPGetRecordKey() == record.GetKey();
	}

	// The class part of a used-input entry.
	protected static string GetCPUsedType(string used)
	{
		int bar = used.IndexOf("|");
		if (bar < 0)
			return used;
		return used.Substring(0, bar);
	}

	// Server: the strain of the running batch's buds / bags.
	protected CP_StrainRecord GetCPUsedRecord()
	{
		if (!m_ACUsedTypes || m_ACUsedTypes.Count() == 0)
			return null;

		string used = m_ACUsedTypes[0];
		int bar = used.IndexOf("|");
		if (bar >= 0)
			return CP_StrainRecord.FromKey(used.Substring(bar + 1, used.Length() - bar - 1));

		string legacyStrain = CP_StrainHelper.GetLegacyStrain(used);
		if (legacyStrain != "")
			return CP_StrainRecord.Named(legacyStrain);
		return null;
	}

	override string GetACOutputLabel(AC_BenchRecipe recipe, AC_BenchIngredient output)
	{
		if (output.IsDynamic() && output.Types[0] == "@CP_BagFromBud")
			return AC_BenchRecipe.Translate("#cp_bench_out_bag");
		if (output.IsDynamic() && output.Types[0] == "@CP_BrickFromBag")
			return AC_BenchRecipe.Translate("#cp_bench_out_brick");
		return super.GetACOutputLabel(recipe, output);
	}

	// ------------------------------------------------------------------ handling

	override bool IsElectricAppliance()
	{
		return true;
	}
}

class CP_Workbench_Holo extends ItemBase
{
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
}
