class ActionSmokeCigSelfCB : ActionContinuousBaseCB {

	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(1);
	}		
};

class ActionSmokeCigSelf: ActionContinuousBase {	

	string currentLanguage;	
	private float clhealth;
	private int ReduceAmount=5;

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

        if (cig) {
			cig.SetSmokingState(ESmokeState.SMOKING);
        };
		super.OnStartAnimationLoop(action_data);
    }

	 override void OnEndAnimationLoop( ActionData action_data )
    {
         CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);

        if (cig) {
			cig.SetSmokingState(ESmokeState.INACTIVE);
        };
	  super.OnEndAnimationLoop(action_data);		
    }
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);
		
		if (cig) {
			//player.AddValueToCigaretteValue(1);
		}	
			
		super.OnFinishProgressClient(action_data);
	}

	override void OnFinishProgressServer(ActionData action_data) {
        CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);

        if (cig) {
			//Print("[CP] ActionSmokeCigSelf:OnFinishProgressServer");

            cig.AddHealth("", "Health", -ReduceAmount);

			clhealth = cig.GetHealth();
			//Print("[DECPBUG] cig has " + clhealth + " health");

			cig.SetSynchronizedHealth(clhealth);

			if (clhealth <= 0) {
				cig.SetSmokingState(ESmokeState.NOT_SMOKING);
				cig.UpdateParticles();
				cig.Delete();
			}
        }
    }

	override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }
};