// Refactored to extend ActionAC_LoadPackBase from AgricultureCore for shared pack loading logic
class ActionCPLoadPack : ActionAC_LoadPackBase
{
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

			return CP_StrainHelper.GetStrain(joint.GetType()) == CP_StrainHelper.GetStrain(jointPack.GetType());
		}

		return false;
	}

	// Override base class abstract method
	override bool CanLoadIntoPack(ActionTarget target, ItemBase sourceItem)
	{
		return CanLoadPack(target, sourceItem);
	}

	// Override to add debug logging
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		CPDebugPrint("LoadPack OnStartServer - Action started");
	}

	// Override to add debug logging
	override void OnFinishProgressServer(ActionData action_data)
	{
		AC_LoadPackActionData data = AC_LoadPackActionData.Cast(action_data);
		ItemBase source = ItemBase.Cast(action_data.m_Player.GetItemInHands());
		ItemBase pack = null;
		if (data)
			pack = data.m_TargetPack;

		CPDebugPrint("LoadPack OnFinishProgressServer - source: " + source + ", pack: " + pack + ", data: " + data);

		if (data && source)
		{
			int available = source.GetQuantity() - data.m_LoadedCount;
			CPDebugPrint("LoadPack OnFinishProgressServer - source qty: " + source.GetQuantity() + ", loaded count: " + data.m_LoadedCount + ", available: " + available);
		}

		// Call base implementation
		super.OnFinishProgressServer(action_data);

		if (data && pack)
		{
			CPDebugPrint("LoadPack Loaded 1 into pack (cycle " + data.m_LoadedCount + ", pack qty: " + pack.GetQuantity() + ")");
		}
	}

	// Override to add debug logging
	override void OnEndServer(ActionData action_data)
	{
		AC_LoadPackActionData data = AC_LoadPackActionData.Cast(action_data);
		if (data && data.m_LoadedCount > 0)
		{
			ItemBase source = ItemBase.Cast(action_data.m_Player.GetItemInHands());
			int remaining = 0;
			if (source)
				remaining = source.GetQuantity() - data.m_LoadedCount;
			CPDebugPrint("LoadPack Action ended - loaded " + data.m_LoadedCount + " total, source remaining: " + remaining);
		}

		super.OnEndServer(action_data);
	}
};