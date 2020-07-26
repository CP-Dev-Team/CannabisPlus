class ActionUnpackCigaretteBoxCB : ActionContinuousBaseCB {
	
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.UNPACK);
	}
};


class ActionUnpackCigaretteBox: ActionContinuousBase {	
	ItemBase resultItem;
	string currentLanguage;	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void ActionUnpackCigaretteBox() {
		
		m_CallbackClass = ActionUnpackCigaretteBoxCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
		GameOptions gameOptions = new GameOptions();
		ListOptionsAccess lang = ListOptionsAccess.Cast(gameOptions.GetOptionByType( AT_OPTIONS_LANGUAGE ));
		lang.GetItemText(lang.GetIndex(), currentLanguage);		
	}		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void CreateConditionComponents() {		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override bool HasProneException() {
		return true;
	}

	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override bool HasTarget() {
		return false;
	}
		
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override string GetText() {
		
		string text = "";
		
		switch(currentLanguage) {
			// if language setting is german
			case "#options_language_DE":
				text = "Auspacken";
				break;
			// if language setting is french
			case "#options_language_FR":
				text = "Déballer";
				break;
			// if language setting is spanish
			case "#options_language_ES":
				text = "Desenvolver";
				break;
			// set english to default
			default:
				text = "Unpack";
		}
		return text;
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void OnFinishProgressServer( ActionData action_data )
	{		
		super.OnFinishProgressServer(action_data);
		
		if ( action_data.m_MainItem && action_data.m_MainItem.GetHierarchyRootPlayer() == action_data.m_Player ) {						
			
			for(int i = 0; i<action_data.m_MainItem.GetQuantity(); i++){
				
				switch(action_data.m_MainItem.GetType()) {
					
					case "CP_CigarettePack_CannabisBlue":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_JointBlue" , action_data.m_Player.GetPosition(), false) );						
						break;					
					case "CP_CigarettePack_CannabisKush":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_JointKush" , action_data.m_Player.GetPosition(), false) );
						break;					
					case "CP_CigarettePack_CannabisSkunk":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_JointSkunk" , action_data.m_Player.GetPosition(), false) );
						break;
					case "CP_CigarettePack_CannabisStardawg":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_JointStardawg" , action_data.m_Player.GetPosition(), false) );
						break;					
					case "CigarettePack_Merkur":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_Cigarette" , action_data.m_Player.GetPosition(), false) );
						break;					
					case "CigarettePack_Chernamorka":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_Cigarette" , action_data.m_Player.GetPosition(), false) );
						break;					
					case "CigarettePack_Partyzanka":
						resultItem = ItemBase.Cast( GetGame().CreateObject("CP_Cigarette" , action_data.m_Player.GetPosition(), false) );
						break;
				}
			}
			
			GetGame().ObjectDelete(action_data.m_MainItem);
			action_data.m_Player.GetHumanInventory().CreateInHands("CP_CigarettePack_Empty");
		}
	}	
};