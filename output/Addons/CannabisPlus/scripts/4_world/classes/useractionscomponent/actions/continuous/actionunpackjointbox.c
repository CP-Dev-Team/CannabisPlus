class ActionUnpackJointBoxCB : ActionContinuousBaseCB {
	
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.UNPACK);
	}
};

class ActionUnpackJointBox: ActionContinuousBase {	
	ItemBase resultItem;
	string currentLanguage;	
	void ActionUnpackJointBox() {
		
		m_CallbackClass = ActionUnpackJointBoxCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}		
	override void CreateConditionComponents() {		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool HasProneException() {
		return true;
	}

	override bool HasTarget() {
		return false;
	}
		
	override string GetText() {
	string text = "#cp_unpack";
	return text;
    }
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);

		if ( action_data.m_MainItem && action_data.m_MainItem.GetHierarchyRootPlayer() == action_data.m_Player ) {

			string packType = action_data.m_MainItem.GetType();
			CPDebugPrint("Unpacking joint pack type: " + packType);

			string itemType = "";

			// CP joint packs (CP_JointPack_*)
			CP_JointPack jointPack;
			if (Class.CastTo(jointPack, action_data.m_MainItem))
			{
				itemType = jointPack.GetCpPackageName();
				if (itemType == "")
				{
					CPDebugPrint("Warning: Joint pack has no cpCheckPack config, skipping unpack.");
					return;
				}
				CPDebugPrint("Using joint type: " + itemType);
			}
			// DP cigarette packs (DP_CigarettePack_*)
			else if (packType.Contains("DP_CigarettePack_"))
			{
				itemType = "DP_Cigarette";
				CPDebugPrint("DP cigarette pack, using item type: DP_Cigarette");
			}
			// Vanilla cigarette packs
			else if (packType.Contains("CigarettePack_Chernamorka") || packType.Contains("CigarettePack_Merkur") || packType.Contains("CigarettePack_Partyzanka"))
			{
				itemType = "DP_Cigarette";
				CPDebugPrint("Vanilla cigarette pack, using item type: DP_Cigarette");
			}
			else
			{
				CPDebugPrint("Unknown pack type: " + packType + ", skipping unpack.");
				return;
			}

			int qty = action_data.m_MainItem.GetQuantity();
			
			// Create stacks based on varQuantityMax (joints max out at 10)
			int maxStackSize = 10;
			while (qty > 0)
			{
				int stackQty = Math.Min(qty, maxStackSize);
				ItemBase stack = ItemBase.Cast(g_Game.CreateObject(itemType, action_data.m_Player.GetPosition(), false));
				if (stack)
				{
					if (stackQty > 1)
						stack.SetQuantity(stackQty);
					
					if (!resultItem)
						resultItem = stack; // First stack goes to hands
				}
				qty -= stackQty;
			}

			g_Game.ObjectDelete(action_data.m_MainItem);
			action_data.m_Player.GetHumanInventory().CreateInHands("AC_CigarettePack_Empty");
		}
	}
};

// Backward compatibility for mods still referencing the old unpack action name.
class ActionUnpackCigaretteBoxCB : ActionUnpackJointBoxCB
{
}

class ActionUnpackCigaretteBox : ActionUnpackJointBox
{
}