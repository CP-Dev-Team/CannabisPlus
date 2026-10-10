// Strain records on CannabisPlus items (CannabisPlus 4 genetics).
//
// Every strain uses one set of "genetic" item classes (config entry cpGenetic = 1: CP_CannabisGenetic,
// CP_CannabisBagGenetic, CP_Plant_CannabisGenetic, ...). The strain lives on the item as a CP_StrainRecord:
// - saved in CF mod storage (section "CannabisPlus"), so old saves are never misread
// - synced to clients as small numbers: the strain (index in g_CPStrainOrder), its look and a record hash
// - copied whenever CannabisPlus or the game turns one item into another (splits, crafting, harvest, ...)
// - items only stack with items of the same record
// Items of the 8 strains CannabisPlus 3 had classes for (CP_CannabisSkunk, ...) turn into genetic items of
// that strain when the server loads or spawns them.

const int CP_STORE_VERSION = 1;	// inside the CannabisPlus mod storage section

modded class ItemBase
{
	protected bool m_CPIsGenetic;
	protected ref CP_StrainRecord m_CPRecord;	// server
	protected int m_CPStrainIndex = -1;			// synced: index in g_CPStrainOrder, -1 = none / unknown cross
	protected int m_CPLook = -1;				// synced: index in CannabisStrainConfig.GetLegacyStrainNames()
	protected int m_CPRecordHash;				// synced: tells unknown crosses apart (0 = no record)
	protected int m_CPAppliedLook = -1;			// client: look whose textures are on the model

	void ItemBase()
	{
		m_CPIsGenetic = ConfigGetBool("cpGenetic");
		if (m_CPIsGenetic)
		{
			RegisterNetSyncVariableInt("m_CPStrainIndex");
			RegisterNetSyncVariableInt("m_CPLook");
			RegisterNetSyncVariableInt("m_CPRecordHash");
		}
	}

	bool IsCPGenetic()
	{
		return m_CPIsGenetic;
	}

	// ------------------------------------------------------------------ record

	// Server: this item's strain record. Items of the old per-strain classes give a record of their strain.
	CP_StrainRecord CPGetRecord()
	{
		if (m_CPIsGenetic)
			return m_CPRecord;

		string legacyStrain = CP_StrainHelper.GetLegacyStrain(GetType());
		if (legacyStrain != "")
			return CP_StrainRecord.Named(legacyStrain);
		return null;
	}

	// Server: gives a genetic item its strain (a copy of record).
	void CPSetRecord(CP_StrainRecord record)
	{
		if (!m_CPIsGenetic || !record || !g_Game.IsServer())
			return;

		m_CPRecord = record.Copy();
		CPSyncRecord();
	}

	protected void CPSyncRecord()
	{
		if (!m_CPRecord)
			return;

		m_CPStrainIndex = CP_GetStrainIndex(m_CPRecord.Strain);
		m_CPRecordHash = m_CPRecord.GetKey().Hash();
		if (m_CPRecordHash == 0)
			m_CPRecordHash = 1;

		string look = "";
		CannabisStrainConfig strainConfig = CP_GetStrainConfig(m_CPRecord.Strain);
		if (strainConfig)
			look = strainConfig.Look;
		m_CPLook = CP_StrainLooks.GetIndex(look);

		SetSynchDirty();
		CPApplyLook();
	}

	// The strain's registry name ("" for an unknown cross or no record). Works on clients too.
	string CPGetStrainName()
	{
		if (g_Game.IsServer())
		{
			CP_StrainRecord record = CPGetRecord();
			if (record)
				return record.Strain;
			return "";
		}

		if (!m_CPIsGenetic)
			return CP_StrainHelper.GetLegacyStrain(GetType());
		return CP_GetStrainByIndex(m_CPStrainIndex);
	}

	// Identifies the genetics for stacking and same-strain checks ("" = no strain). Works on clients too.
	string CPGetRecordKey()
	{
		if (g_Game.IsServer())
		{
			CP_StrainRecord record = CPGetRecord();
			if (record)
				return record.GetKey();
			return "";
		}

		string strain = CPGetStrainName();
		if (strain != "")
			return "S:" + strain;
		if (m_CPIsGenetic && m_CPRecordHash != 0)
			return "U:" + m_CPRecordHash;
		return "";
	}

	// Settings of this item's strain from the registry, or null.
	CannabisStrainConfig CPGetStrainConfig()
	{
		return CP_GetStrainConfig(CPGetStrainName());
	}

	// Bench "same" inputs: buds or bags of one strain (old and genetic items of a strain count together).
	override string GetACSameKey()
	{
		string key = CPGetRecordKey();
		if (key == "")
			return super.GetACSameKey();
		return CP_StrainHelper.GetGeneticClass(GetType()) + "|" + key;
	}

	override void ACInheritFrom(ItemBase source)
	{
		super.ACInheritFrom(source);

		if (source)
			CPSetRecord(source.CPGetRecord());
	}

	override bool CanBeCombined(EntityAI other_item, bool reservation_check = true, bool stack_max_limit = false)
	{
		if (!super.CanBeCombined(other_item, reservation_check, stack_max_limit))
			return false;

		ItemBase other = ItemBase.Cast(other_item);
		if (m_CPIsGenetic && other && CPGetRecordKey() != other.CPGetRecordKey())
			return false;
		return true;
	}

	// ------------------------------------------------------------------ names and looks

	// "Northern Lights", "Unknown Cross" or "Cannabis".
	string CPGetStrainDisplayName()
	{
		string strain = CPGetStrainName();
		CannabisStrainConfig strainConfig = CP_GetStrainConfig(strain);
		if (strainConfig && strainConfig.DisplayName != "")
			return strainConfig.DisplayName;
		if (strain != "")
			return strain;
		if (m_CPIsGenetic && m_CPRecordHash != 0)
			return Widget.TranslateString("#cp_gen_unknown");
		return Widget.TranslateString("#cp_gen_cannabis");
	}

	// Config text with %1 = the strain's name.
	protected string CPFormatText(string text)
	{
		if (text.IndexOf("#") == 0)
			text = Widget.TranslateString(text);
		text.Replace("%1", CPGetStrainDisplayName());
		return text;
	}

	override string GetDisplayName()
	{
		if (m_CPIsGenetic)
			return CPFormatText(ConfigGetString("displayName"));
		return super.GetDisplayName();
	}

	override bool DescriptionOverride(out string output)
	{
		if (!m_CPIsGenetic)
			return super.DescriptionOverride(output);

		output = CPFormatText(ConfigGetString("descriptionShort"));
		CannabisStrainConfig strainConfig = CPGetStrainConfig();
		if (strainConfig && strainConfig.Description != "")
			output = output + "\n" + strainConfig.Description;
		return true;
	}

	// Puts the textures of the strain's look (CfgCannabisStrainLooks) on the model. The item's config says which
	// look entry goes on each hidden selection (cpLookTextures[] / cpLookMaterials[]); entries the look doesn't
	// have keep the class's own texture.
	void CPApplyLook(bool force = false)
	{
		if (!m_CPIsGenetic || g_Game.IsDedicatedServer())
			return;
		if (m_CPLook < 0 || (m_CPLook == m_CPAppliedLook && !force))
			return;

		string look = CP_StrainLooks.GetByIndex(m_CPLook);
		if (look == "")
			return;

		TStringArray textureEntries = new TStringArray;
		TStringArray materialEntries = new TStringArray;
		ConfigGetTextArray("cpLookTextures", textureEntries);
		ConfigGetTextArray("cpLookMaterials", materialEntries);

		for (int i = 0; i < textureEntries.Count(); i++)
		{
			string texture = CP_StrainLooks.Get(look, textureEntries[i]);
			if (texture != "")
				SetObjectTexture(i, texture);
		}
		for (int j = 0; j < materialEntries.Count(); j++)
		{
			string material = CP_StrainLooks.Get(look, materialEntries[j]);
			if (material != "")
				SetObjectMaterial(j, material);
		}
		m_CPAppliedLook = m_CPLook;
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (m_CPIsGenetic)
			CPApplyLook();
	}

	// ------------------------------------------------------------------ new items, old items

	override void EEInit()
	{
		super.EEInit();

		if (!g_Game.IsServer() || GetType().IndexOf("CP_") != 0)
			return;

		// After loading and after whoever created the item has set it up.
		if (m_CPIsGenetic || CP_StrainHelper.GetLegacyStrain(GetType()) != "")
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CPCheckGenetics, 250, false);
	}

	protected void CPCheckGenetics()
	{
		if (IsSetForDeletion())
			return;

		if (!m_CPIsGenetic)
		{
			CPConvertLegacy();
			return;
		}

		if (m_CPRecord)
		{
			CPSyncRecord();
			return;
		}

		// Loot and admin spawns come without a strain. Per-strain seed packs (CP_CannabisSeedsPack<Strain>) hold
		// their strain; everything else gets a random foundation strain.
		string classStrain = CP_StrainHelper.GetStrain(GetType());
		if (classStrain != CP_StrainHelper.GENETIC && CP_GetStrainConfig(classStrain))
			CPSetRecord(CP_StrainRecord.Named(classStrain));
		else
			CPSetRecord(CP_StrainRecord.Named(CP_Genetics.PickWildStrain()));
	}

	// Turns an item of an old per-strain class into the genetic item of that strain, in the same place.
	protected void CPConvertLegacy()
	{
		string strain = CP_StrainHelper.GetLegacyStrain(GetType());
		string geneticType = CP_StrainHelper.GetGeneticClass(GetType());
		// Seed packs of a retired strain become the seed pack of the strain that replaces it.
		string ownType = CP_StrainHelper.ReplaceStrain(GetType(), strain);
		if (ownType != GetType() && g_Game.ConfigGetInt("CfgVehicles " + ownType + " cpGenetic") == 1)
			geneticType = ownType;
		if (strain == "" || !g_Game.ConfigIsExisting("CfgVehicles " + geneticType))
			return;

		// Plants keep growing as they are (their harvest converts), seeds already planted in a plot are kept for it.
		if (IsInherited(PlantBase) || GardenBase.Cast(GetHierarchyParent()))
			return;

		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		CP_ConvertLegacyLambda lambda = new CP_ConvertLegacyLambda(this, geneticType, player);
		lambda.m_Record = CP_StrainRecord.Named(strain);
		CPDebugPrint("Converting " + GetType() + " to " + geneticType + " (" + strain + ")");

		if (player)
			player.ServerReplaceItemWithNew(lambda);
		else
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
	}

	// ------------------------------------------------------------------ storage

	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		if (!m_CPIsGenetic || !m_CPRecord)
			return;

		CF_ModStorage ctx = storage["CannabisPlus"];
		if (!ctx)
			return;

		ctx.Write(CP_STORE_VERSION);
		m_CPRecord.Write(ctx);
	}

	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		if (!m_CPIsGenetic)
			return true;

		CF_ModStorage ctx = storage["CannabisPlus"];
		if (!ctx)
			return true;

		// Empty section: saved before the item had a record.
		int version;
		if (!ctx.Read(version))
			return true;

		CP_StrainRecord record = new CP_StrainRecord();
		if (!record.Read(ctx))
		{
			Print("[CannabisPlus] ERROR: could not read the strain of " + GetType() + ", it gets a new one.");
			return true;
		}

		m_CPRecord = record;
		return true;
	}
}

// Replaces an old per-strain item with the genetic item of its strain, keeping quantity, health and position.
class CP_ConvertLegacyLambda : TurnItemIntoItemLambda
{
	ref CP_StrainRecord m_Record;

	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		ItemBase item = ItemBase.Cast(new_item);
		if (item)
			item.CPSetRecord(m_Record);

		CP_RawPlantBase oldPlant = CP_RawPlantBase.Cast(old_item);
		CP_RawPlantBase newPlant = CP_RawPlantBase.Cast(new_item);
		if (oldPlant && newPlant)
			newPlant.SetYield(oldPlant.GetYield());
	}
}

// Splitting a stack (and other vanilla item changes) copies the strain to the new item.
modded class MiscGameplayFunctions
{
	override static void TransferItemProperties(EntityAI source, notnull EntityAI target, bool transfer_agents = true, bool transfer_variables = true, bool transfer_health = true, bool exclude_quantity = false)
	{
		super.TransferItemProperties(source, target, transfer_agents, transfer_variables, transfer_health, exclude_quantity);

		ItemBase from = ItemBase.Cast(source);
		ItemBase to = ItemBase.Cast(target);
		if (from && to && to.IsCPGenetic() && g_Game.IsServer())
			to.CPSetRecord(from.CPGetRecord());
	}
}

class CP_Genetics
{
	// Creates the genetic item of the same kind as className (whatever strain is in the name) on the ground
	// and gives it source's strain.
	static ItemBase CreateOnGround(string className, vector position, ItemBase source)
	{
		string type = CP_StrainHelper.GetGeneticClass(className);
		if (type == "")
			type = className;

		ItemBase item = ItemBase.Cast(g_Game.CreateObjectEx(type, position, ECE_PLACE_ON_SURFACE));
		if (item && source)
			item.CPSetRecord(source.CPGetRecord());
		return item;
	}

	// Both items have the same genetics (old and genetic items of one strain count as the same).
	static bool SameStrain(ItemBase a, ItemBase b)
	{
		if (!a || !b)
			return false;
		string key = a.CPGetRecordKey();
		return key != "" && key == b.CPGetRecordKey();
	}

	// A random wild landrace from the registry (for loot and admin spawns).
	static string PickWildStrain()
	{
		TStringArray wild = new TStringArray;
		map<string, ref CannabisStrainConfig> strains = CP_GetStrainMap();
		foreach (string strainName, CannabisStrainConfig strainConfig : strains)
		{
			if (strainConfig.Tier == 0)
				wild.Insert(strainName);
		}
		if (wild.Count() == 0)
			return "Afghan";
		return wild.GetRandomElement();
	}
}
