//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// The CP_PlasticWrapper class provides all methods for Plastic wrapper machine.
// Currently, the class is only required for the item to be available in the game. 
// All methods to use the plastic wrapper are in the class CP_Workbench.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_PlasticWrapper extends ItemBase {
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of CP_PlasticWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_PlasticWrapper(){
		Print("INIT WRAPPER");
	}
	
	override bool CanPutAsAttachment( EntityAI parent )
	{
		/*
		if (!super.CanPutAsAttachment(parent))
			return false;
		
		string obj_type = parent.GetType();
		if ( parent.IsInherited(CP_Workbench) )
		{
			CP_Workbench workbench = CP_Workbench.Cast( parent );
			return workbench.CanReceiveAttachment(this, InventorySlots.INVALID);
		}
		
		if (GetCompEM().GetPluggedDevice())
			return false;
		*/
		Print("CAN ATTACH");
		return true;
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of CP_PlasticWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void SetActions() {
		super.SetActions();
		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
}      