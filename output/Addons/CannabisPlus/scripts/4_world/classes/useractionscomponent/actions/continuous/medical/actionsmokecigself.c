//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// callback function for 'ActionSmokeCigSelf'-action 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
class ActionSmokeCigSelfCB : ActionContinuousBaseCB {
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.DRINK,UATimeSpent.DEFAULT);
	}	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnFinish(bool pCanceled){
		Print("!!!!!!!!!!!!!!!!!! OnFinish");
		super.OnFinish(pCanceled);
		CP_Cigarette joint = CP_Cigarette.Cast(m_ActionData.m_Target.GetObject());
		if(joint.m_SmokeParticle){
			joint.m_SmokeParticle.Delete();
			joint.m_SmokeParticle.Stop();
			joint.SetSmokingState(0);
		}		
	}
	
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ActionSmokeCigSelf: ActionContinuousBase {		
	string currentLanguage;		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	void ActionSmokeCigSelf()	{
		m_CallbackClass = ActionSmokeCigSelfCB;		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
	}		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void OnExecuteServer(ActionData action_data){
		super.OnExecuteServer(action_data);		
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		joint.SetSmokingState(1);		
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void OnStartAnimationLoopServer(ActionData action_data) {
		super.OnStartAnimationLoopServer(action_data);
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		joint.SetSmokingState(1);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	/*
	override void OnFinishProgress( ActionData action_data ) {
		Print("!!!!!!!!!!!!!!!!!! OnFinishProgress");
		super.OnFinishProgress(action_data);
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		joint.m_SmokeParticle.Stop();
		joint.m_SmokeParticle.Delete();
		joint.SetSmokingState(0);				
	}
	*/
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// when the player stops pressing the mouse button
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void OnEndInput(ActionData action_data) {
		Print("!!!!!!!!!!!!!!!!!! OnEndInput");
		super.OnEndInput(action_data);
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		
		if(joint.m_SmokeParticle){
			joint.m_SmokeParticle.Delete();
			joint.m_SmokeParticle.Stop();	
			joint.SetSmokingState(0);
		}				
		
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/*
	override void OnEndServer( ActionData action_data ) {		
		Print("!!!!!!!!!!!!!!!!!! OnEndServer");
		super.OnEndServer(action_data);
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		joint.m_SmokeParticle.Stop();
		joint.m_SmokeParticle.Delete();
		joint.SetSmokingState(0);
	}
	*/
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnEndAnimationLoop(ActionData action_data) {
		Print("!!!!!!!!!!!!!!!!!! OnEndAnimationLoop");
		super.OnEndAnimationLoop(action_data);
		CP_Cigarette joint = CP_Cigarette.Cast(action_data.m_Target.GetObject());
		if(joint.m_SmokeParticle) {
			joint.m_SmokeParticle.Stop();
			joint.m_SmokeParticle.Delete();
			joint.SetSmokingState(0);
		}
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool IsDrink() {
		return true;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// returns a localized text of the action
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
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
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool HasProneException() {
		return true;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool HasTarget() {
		return false;
	}
};