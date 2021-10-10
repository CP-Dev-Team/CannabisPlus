//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ActionTurnOnWrapper: ActionInteractBase {

	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of ActionTurnOnWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	void ActionTurnOnWrapper() {		
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}
	

	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Are all conditions met for the action to be displayed?
	// - wrapper must be attached to the workbench 
	// - car battery must be attached to the workbench 
	// - wrapper is currently NOT working
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) {	
		Object target_object = target.GetObject();
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		CP_Workbench workbench = CP_Workbench.Cast(target_object);		
		// check if plastic wrapper and car battery attached to workbench and the wrapper is currently NOT working
		if( (workbench.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CP_PlasticWrapper")) != null) && (workbench.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery")) != null) && (workbench.m_IsWrapperActive == false)){
			return true;
		} else {
			return false;
		}
	}
	
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Returns the string to be displayed in the game.
	// todo: localization
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override string GetText() {
		return "Turn On Wrapper";
	}
	
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// turns on the wrapper when the code is executed on the client
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnExecuteServer(ActionData action_data) {
		CP_Workbench workbench = CP_Workbench.Cast( action_data.m_Target.GetObject() ); // cast to workbench class
		workbench.TurnWrapperOn();
		//workbench.m_IsWrapperActive = true;
		
	}

	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// turns on the wrapper when the code is executed on the client
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnExecuteClient(ActionData action_data) {		
		CP_Workbench workbench = CP_Workbench.Cast( action_data.m_Target.GetObject() ); // cast to workbench class
		workbench.TurnWrapperOn();		
	}
}