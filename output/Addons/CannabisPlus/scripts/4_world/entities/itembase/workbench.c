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

	// ------------------------------------------------------------------ storage instead of supply slots

	// CannabisPlus 3 had slots for buds, empty bags, bags, bricks and plastic wrap. Everything now goes into the
	// bench's storage, so several strains can be bagged one after the other. The slots stay in the config only so
	// old saves load; anything still in them is moved into the storage.
	static ref TStringArray CP_SUPPLY_SLOTS = {"CP_Cannabis_Buds", "AC_Empty_Bags", "CP_Cannabis_Bags", "CP_Cannabis_Bricks", "CP_PlasticRoll"};

	static bool IsCPSupplySlot(int slotId)
	{
		return CP_SUPPLY_SLOTS.Find(InventorySlots.GetSlotName(slotId)) != -1;
	}

	override bool UseACAttachmentOutputs()
	{
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (IsCPSupplySlot(slotId))
			return false;
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanDisplayAttachmentSlot(int slot_id)
	{
		if (IsCPSupplySlot(slot_id))
			return false;
		return super.CanDisplayAttachmentSlot(slot_id);
	}

	// The supply slots are never locked (nothing can go in, and old contents must be able to leave).
	override void UpdateACLocks()
	{
		super.UpdateACLocks();

		foreach (string slotName : CP_SUPPLY_SLOTS)
		{
			int slotId = InventorySlots.GetSlotIdFromString(slotName);
			if (slotId != InventorySlots.INVALID)
				GetInventory().SetSlotLock(slotId, false);
		}
	}

	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();

		if (g_Game.IsServer())
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(EmptyCPSupplySlots, 500, false);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(EmptyCPSupplySlots);
	}

	// Moves items from the old supply slots into the storage, or next to the bench when it's full.
	protected void EmptyCPSupplySlots()
	{
		foreach (string slotName : CP_SUPPLY_SLOTS)
		{
			int slotId = InventorySlots.GetSlotIdFromString(slotName);
			if (slotId == InventorySlots.INVALID)
				continue;

			EntityAI item = GetInventory().FindAttachment(slotId);
			if (!item)
				continue;

			bool moved = false;
			if (GetInventory().CanAddEntityInCargo(item, item.GetInventory().GetFlipCargo()))
				moved = GetInventory().TakeEntityToTargetCargo(InventoryMode.SERVER, this, item);
			if (!moved)
				moved = GetInventory().DropEntity(InventoryMode.SERVER, this, item);
			CPDebugPrint("Workbench: moved " + item.GetType() + " out of slot " + slotName + " -> " + moved);
		}
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
