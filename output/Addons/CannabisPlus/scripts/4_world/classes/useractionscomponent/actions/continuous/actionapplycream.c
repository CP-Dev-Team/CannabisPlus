class ActionApplyCreamCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.WASH_HANDS);
	}
};

class ActionApplyCream: ActionContinuousBase
{
	string currentLanguage;	

	void ActionApplyCream()
	{
		m_CallbackClass = ActionApplyCreamCB;
		m_CommandUID	= DayZPlayerConstants.CMD_ACTIONFB_WASHHANDSWELL;

		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTSelf;
	}
	
	override bool HasTarget()
	{
		return false;
	}

	override void ApplyModifiers( ActionData action_data )
	{
		//action_data.m_Player.m_ModifiersManager.DeactivateModifier(eModifiers.MDF_POISONING);
	}
	
	override string GetText() 
	{
		return "Apply Cream";

/* 		// reserve empty string as return statement
        string text = "";
		
		switch(currentLanguage) {
			// if language setting is german
			case "#options_language_DE":
				text = "Creme auftragen";
				break;
			// if language setting is french
			case "#options_language_FR":
				text = "Appliquer la crème";
				break;
			// if language setting is spanish
			case "#options_language_ES":
				text = "Aplicar crema";
				break;
			// set english to default
			default:
				text = "Apply Cream";
		}
		// returns the string in the right language
		return text; */
	}
};