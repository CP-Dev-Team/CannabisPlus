class ActionSmokeJointSelfCB : ActionContinuousBaseCB {

	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(CannabisPlus.getInstance().GetConfig().GetSmokeTime() / (100/CannabisPlus.getInstance().GetConfig().GetSmokePercent()));
	}		
};

class ActionSmokeJointSelf: ActionContinuousBase {	

	string currentLanguage;	
	private float clhealth;

	void ActionSmokeJointSelf()	{
		m_CallbackClass = ActionSmokeJointSelfCB;		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;

		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
	}	

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        CP_JointBase joint;
		Class.CastTo(joint, item);

        if (joint) {
            clhealth = joint.GetSynchronizedHealth();
            return true;
		}	
        return false;
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

	override void OnStartAnimationLoop( ActionData action_data ) {

        CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);

		Print("[DEBUG] ActionSmokeJointSelf:OnStartAnimationLoop");
        if (joint) {
			joint.StartSmoking();
        };
		super.OnStartAnimationLoop(action_data);
    }

	override void OnEndInput( ActionData action_data )
	{
		super.OnEndInput(action_data);
		CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		float ReduceAmount = CannabisPlus.getInstance().GetConfig().GetSmokePercent();

        if (joint) {
			Print("[DEBUG] ActionSmokeJointSelf:OnEndInput");

            joint.AddHealth("", "Health", -ReduceAmount);

			clhealth = joint.GetHealth();
			Print("[DEBUG] Joint has " + clhealth + " health");

			joint.SetSynchronizedHealth(clhealth);

			if (clhealth <= 0) {
				Print("[DEBUG] Deleting Joint");
				joint.Delete();
			}
        }
	}

	override void OnFinishProgressServer(ActionData action_data) {
        CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		float ReduceAmount = CannabisPlus.getInstance().GetConfig().GetSmokePercent();

        if (joint) {
			Print("[DEBUG] ActionSmokeJointSelf:OnFinishProgressServer");

            joint.AddHealth("", "Health", -ReduceAmount);

			clhealth = joint.GetHealth();
			Print("[DEBUG] Joint has " + clhealth + " health");

			joint.SetSynchronizedHealth(clhealth);

			if (clhealth <= 0) {
				Print("[DEBUG] Deleting Joint");
				joint.Delete();
			}
        }
    }

	override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }
};