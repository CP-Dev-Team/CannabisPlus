class ActionSmokeJointSelfCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.DRINK,UATimeSpent.DEFAULT);
	}		
};

class ActionSmokeJointSelf: ActionContinuousBase {		
	string currentLanguage;		

	void ActionSmokeJointSelf()	{
		m_CallbackClass = ActionSmokeJointSelfCB;		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
	}		

	override void OnStartAnimationLoop(ActionData action_data) {	
		JointBase joint = JointBase.Cast(action_data.m_MainItem);
		if (joint) {
			joint.SetSmokingState(1);
			joint.UpdateVisuals();
		}
		super.OnStartAnimationLoop(action_data);
		Print("[DEBUG] ActionSmokeJointSelf:OnStartAnimationLoop")
	}

	override void OnEndInput(ActionData action_data) {
		super.OnEndInput(action_data);	
		JointBase joint = JointBase.Cast(action_data.m_MainItem);
		if (joint) {
			joint.SetSmokingState(0);
			joint.UpdateVisuals();
		}	
		Print("[DEBUG] ActionSmokeJointSelf:OnEndInput")
	}

	override void OnEndAnimationLoop(ActionData action_data) {
		super.OnEndAnimationLoop(action_data);
		JointBase joint = JointBase.Cast(action_data.m_MainItem);
		if (joint) {
			joint.SetSmokingState(0);
			joint.UpdateVisuals();
		}		
		Print("[DEBUG] ActionSmokeJointSelf:OnEndAnimationLoop")
	}

	override bool IsDrink() {
		return true;
	}

	override string GetText() {
		// reserve empty string as return statement
        string text = "";
		
		switch(currentLanguage) {
			// if language setting is german
			case "#options_language_DE":
				text = "Rauchen";
				break;
			// if language setting is french
			case "#options_language_FR":
				text = "Fumée";
				break;
			// if language setting is spanish
			case "#options_language_ES":
				text = "Fumar";
				break;
			// set english to default
			default:
				text = "Smoke";
		}
		// returns the string in the right language
		return text;
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
};