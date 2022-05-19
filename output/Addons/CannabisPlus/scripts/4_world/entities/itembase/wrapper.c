//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// The CP_PlasticWrapper class provides all methods for Plastic wrapper machine.
// Currently, the class is only required for the item to be available in the game. 
// All methods to use the plastic wrapper are in the class CP_Workbench.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_PlasticRoll extends ItemBase{};
class CP_PlasticWrapper extends ItemBase 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
}      