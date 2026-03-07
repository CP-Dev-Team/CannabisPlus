class CPLoadPackActionData : ActionData
{
	int m_LoadedCount;

	void CPLoadPackActionData()
	{
		m_LoadedCount = 0;
	}
};

class ActionCPLoadPackCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.MAG_LOAD);
	}
};

class ActionCPLoadPack : ActionContinuousBase
{
	void ActionCPLoadPack()
	{
		m_CallbackClass = ActionCPLoadPackCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_FILLMAG;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_FILLMAG;
		m_Text = "Load into pack";
	}

	override ActionData CreateActionData()
	{
		CPLoadPackActionData data = new CPLoadPackActionData();
		return data;
	}

	override bool HasProneException()
	{
		return true;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone();
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	protected bool IsVanillaCigarettePack(ItemBase pack)
	{
		return pack.IsInherited(CigarettePack_Chernamorka) || pack.IsInherited(CigarettePack_Merkur) || pack.IsInherited(CigarettePack_Partyzanka);
	}

	protected bool CanLoadPack(ActionTarget target, ItemBase item)
	{
		if (!target || !item)
			return false;

		ItemBase pack = ItemBase.Cast(target.GetObject());
		if (!pack)
			return false;

		if (pack.GetQuantity() >= 20)
			return false;

		CP_JointBase joint = CP_JointBase.Cast(item);
		if (joint)
		{
			CP_JointPack jointPack = CP_JointPack.Cast(pack);
			if (!jointPack)
				return false;

			return joint.GetCpJointName() == jointPack.GetCpPackageName();
		}

		CP_Cigarette cigarette = CP_Cigarette.Cast(item);
		if (cigarette)
		{
			return IsVanillaCigarettePack(pack);
		}

		return false;
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		CPLoadPackActionData data = CPLoadPackActionData.Cast(action_data);
		ItemBase currentItem = ItemBase.Cast(action_data.m_Player.GetItemInHands());
		
		CPDebugPrint("LoadPack ActionConditionContinue - currentItem: " + currentItem);
		
		if (!currentItem)
		{
			CPDebugPrint("LoadPack ActionConditionContinue - NO CURRENT ITEM, returning false");
			return false;
		}
		
		if (data)
		{
			int available = currentItem.GetQuantity() - data.m_LoadedCount;
			CPDebugPrint("LoadPack ActionConditionContinue - qty: " + currentItem.GetQuantity() + ", loaded: " + data.m_LoadedCount + ", available: " + available);
			
			if (available <= 0)
			{
				CPDebugPrint("LoadPack ActionConditionContinue - NO AVAILABLE, returning false");
				return false;
			}
		}
		
		ItemBase pack = ItemBase.Cast(action_data.m_Target.GetObject());
		if (pack)
		{
			CPDebugPrint("LoadPack ActionConditionContinue - pack qty: " + pack.GetQuantity());
		}
		
		bool canLoad = CanLoadPack(action_data.m_Target, currentItem);
		CPDebugPrint("LoadPack ActionConditionContinue - CanLoadPack result: " + canLoad);
		return canLoad;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return CanLoadPack(target, item);
	}

	override bool CanBePerformedFromQuickbar()
	{
		return true;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		CPDebugPrint("LoadPack OnStartServer - Action started");
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		CPDebugPrint("LoadPack OnFinishProgressServer - CALLED");
		
		CPLoadPackActionData data = CPLoadPackActionData.Cast(action_data);
		ItemBase source = ItemBase.Cast(action_data.m_Player.GetItemInHands());
		ItemBase pack = ItemBase.Cast(action_data.m_Target.GetObject());

		CPDebugPrint("LoadPack OnFinishProgressServer - source: " + source + ", pack: " + pack + ", data: " + data);

		if (!source || !pack || !data)
		{
			CPDebugPrint("LoadPack OnFinishProgressServer - NULL CHECK FAILED, returning");
			return;
		}

		int available = source.GetQuantity() - data.m_LoadedCount;
		int packQuantity = pack.GetQuantity();

		CPDebugPrint("LoadPack OnFinishProgressServer - source qty: " + source.GetQuantity() + ", loaded count: " + data.m_LoadedCount + ", available: " + available + ", pack qty: " + packQuantity);

		if (available <= 0 || packQuantity >= 20)
		{
			CPDebugPrint("LoadPack OnFinishProgressServer - LIMIT CHECK FAILED, returning");
			return;
		}

		pack.SetQuantity(packQuantity + 1);
		pack.SetSynchDirty();
		data.m_LoadedCount++;

		CPDebugPrint("LoadPack Loaded 1 into pack (cycle " + data.m_LoadedCount + ", pack qty: " + (packQuantity + 1) + ")");
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		CPLoadPackActionData data = CPLoadPackActionData.Cast(action_data);
		if (data && data.m_LoadedCount > 0)
		{
			ItemBase source = ItemBase.Cast(action_data.m_Player.GetItemInHands());
			if (source)
			{
				int remaining = source.GetQuantity() - data.m_LoadedCount;

				CPDebugPrint("LoadPack Action ended - loaded " + data.m_LoadedCount + " total, source remaining: " + remaining);

				if (remaining <= 0)
				{
					source.Delete();
				}
				else
				{
					source.SetQuantity(remaining);
				}
			}
		}
	}
};