class ActionUnpackCigaretteBoxCB : ActionContinuousBaseCB {
	
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.UNPACK);
	}
};

class ActionUnpackCigaretteBox: ActionContinuousBase {	
	ItemBase resultItem;
	string currentLanguage;	
	void ActionUnpackCigaretteBox() {
		
		m_CallbackClass = ActionUnpackCigaretteBoxCB;
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
			CPDebugPrint("Unpacking cigarette pack type: " + packType);

			string itemType = "";

			if (packType.Contains("CP_CigarettePack_Cannabis"))
			{
				string strainName = packType.Substring(25, packType.Length() - 25); // Extract strain name after "CP_CigarettePack_Cannabis"
				CPDebugPrint("Extracted strain name: " + strainName);

				if (g_CannabisStrainConfigs.Contains(strainName))
				{
					itemType = "CP_Joint" + strainName;
					CPDebugPrint("Using joint type: " + itemType + " for strain: " + strainName);
				}
				else
				{
					CPDebugPrint("Warning: Strain config for '" + strainName + "' not found, skipping unpack.");
					return;
				}
			}
			else if (packType.Contains("CP_CigarettePack_Chernamorka") || packType.Contains("CP_CigarettePack_Merkur") || packType.Contains("CP_CigarettePack_Partyzanka") || packType.Contains("CigarettePack_Chernamorka") || packType.Contains("CigarettePack_Merkur") || packType.Contains("CigarettePack_Partyzanka"))
			{
				itemType = "CP_Cigarette";
				CPDebugPrint("Tobacco cigarette pack, using item type: CP_Cigarette");
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
				ItemBase stack = ItemBase.Cast(GetGame().CreateObject(itemType, action_data.m_Player.GetPosition(), false));
				if (stack)
				{
					if (stackQty > 1)
						stack.SetQuantity(stackQty);
					
					if (!resultItem)
						resultItem = stack; // First stack goes to hands
				}
				qty -= stackQty;
			}

			GetGame().ObjectDelete(action_data.m_MainItem);
			action_data.m_Player.GetHumanInventory().CreateInHands("CP_CigarettePack_Empty");
		}
	}
};