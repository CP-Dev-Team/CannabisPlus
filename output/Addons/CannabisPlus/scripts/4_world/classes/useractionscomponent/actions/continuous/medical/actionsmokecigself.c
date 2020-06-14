class ActionSmokeCigSelfCB : ActionContinuousBaseCB {

	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(CannabisPlus.getInstance().GetConfig().GetSmokeTime() / (100/CannabisPlus.getInstance().GetConfig().GetSmokePercent()));
	}		
};

class ActionSmokeCigSelf: ActionContinuousBase {	

	string currentLanguage;	
	private float clhealth;

	void ActionSmokeCigSelf()	{
		m_CallbackClass = ActionSmokeCigSelfCB;		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;

		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
	}	

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        CP_Cigarette cig;
		Class.CastTo(cig, item);

        if (cig) {
            clhealth = cig.GetSynchronizedHealth();
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

        CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);

		//Print("[DEBUG] ActionSmokeCigSelf:OnStartAnimationLoop");
        if (cig) {
			cig.StartSmoking();
        };
		super.OnStartAnimationLoop(action_data);
    }

	override void OnEndInput( ActionData action_data )
	{
		super.OnEndInput(action_data);
		CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);
		float ReduceAmount = CannabisPlus.getInstance().GetConfig().GetSmokePercent();

        if (cig) {
			//Print("[DEBUG] ActionSmokeCigSelf:OnEndInput");

            cig.AddHealth("", "Health", -ReduceAmount);

			clhealth = cig.GetHealth();
			//Print("[DEBUG] cig has " + clhealth + " health");

			cig.SetSynchronizedHealth(clhealth);

			if (clhealth <= 0) {
				//Print("[DEBUG] Deleting Joint");
				cig.Delete();
			}
        }
	}

	override void OnFinishProgressServer(ActionData action_data) {
        CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);
		float ReduceAmount = CannabisPlus.getInstance().GetConfig().GetSmokePercent();

        if (cig) {
			//Print("[DEBUG] ActionSmokeCigSelf:OnFinishProgressServer");

            cig.AddHealth("", "Health", -ReduceAmount);

			clhealth = cig.GetHealth();
			//Print("[DEBUG] cig has " + clhealth + " health");

			cig.SetSynchronizedHealth(clhealth);

			if (clhealth <= 0) {
				//Print("[DEBUG] Deleting cig");
				cig.Delete();
			}
        }
    }

	override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }
};