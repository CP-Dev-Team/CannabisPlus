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

			string jointType = "CP_CigarettePack_CannabisSkunk"; // default for vanilla packs

			if (packType.Contains("CP_CigarettePack_Cannabis"))
			{
				string strainName = packType.Substring(25, packType.Length() - 25); // Extract strain name after "CP_CigarettePack_Cannabis"
				CPDebugPrint("Extracted strain name: " + strainName);

				if (g_CannabisStrainConfigs.Contains(strainName))
				{
					jointType = "CP_Joint" + strainName;
					CPDebugPrint("Using joint type: " + jointType + " for strain: " + strainName);
				}
				else
				{
					CPDebugPrint("Warning: Strain config for '" + strainName + "' not found. Using default joint type: " + jointType);
				}
			}
			else
			{
				CPDebugPrint("Vanilla cigarette pack, using joint type: " + jointType);
			}

			for(int i = 0; i<action_data.m_MainItem.GetQuantity(); i++){
				resultItem = ItemBase.Cast( GetGame().CreateObject(jointType , action_data.m_Player.GetPosition(), false) );
			}

			GetGame().ObjectDelete(action_data.m_MainItem);
			action_data.m_Player.GetHumanInventory().CreateInHands("CP_CigarettePack_Empty");
		}
	}
};