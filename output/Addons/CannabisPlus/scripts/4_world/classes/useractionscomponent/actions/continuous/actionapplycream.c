class ActionApplyCreamCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SEW_CUTS);
	}
};

class ActionApplyCream : ActionContinuousBase
{
	string currentLanguage;	

	void ActionApplyCream()
	{
		m_CallbackClass 	= ActionApplyCreamCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_WASHHANDSWELL;
		m_FullBody 			= true;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;

		/* Removing because it's not supported on Linux
		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);
		*/
	}

	void ApplyCream( ItemBase item, PlayerBase player )
	{			
		PluginTransmissionAgents m_mta = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		m_mta.TransmitAgents(item, player, AGT_ITEM_TO_FLESH);

		if (item.HasQuantity())
		{
			item.AddQuantity(-1,true);
		}
		else
		{
			item.Delete();
		}
	}	
	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply(action_data.m_Player);
		//player.m_ModifiersManager.ActivateModifier(eModifiers.MDF_CHEMICALPOISON);
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		if (action_data.m_MainItem)
		{
			action_data.m_MainItem.Open();
			ApplyModifiers(action_data);
			ApplyCream( action_data.m_MainItem, target );
		}
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
	
	override string GetText() 
	{
	string text = "#cp_apply_cream";
	return text;
    }

	/* Removing because it's not supported on Linux
	override string GetText() 
	{
        // reserve empty string as return statement
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
		};
		// returns the string in the right language
		return text;
	};
	*/


};