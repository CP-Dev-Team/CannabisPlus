//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// The CP_PlasticWrapper class provides all methods for Plastic wrapper machine.
// Currently, the class is only required for the item to be available in the game. 
// All methods to use the plastic wrapper are in the class CP_Workbench.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_PlasticWrapper extends ItemBase 
{
	int m_UseWrapper = 0;
	//Defines a int used for action switching
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of CP_PlasticWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_PlasticWrapper()
	{
		
	}
	string GetWrapperTendancyText()
	{
         return "Wrap Brick";
    };
	string GetWrapperTendancyCreationType()
	{
        return "CannabisBrickSkunk";
    };
	CP_CannabisSkunk GetCannibusBud()
	{
		return CP_CannabisSkunk.Cast( GetAttachmentByType( CP_CannabisSkunk ) );
	};
	
	void CreationWrapperItems(string CreationType)
	{
		Print ("trigger");

		string thingName =  FindAttachmentBySlotName("CP_Cannabus_Buds").GetType();
		
		Print(thingName);
				
		if (thingName == "CP_CannabisSkunk" )
		{
			GetGame().ObjectDelete( GetCannibusBud() );
			GetInventory().CreateAttachment("CP_" + CreationType ); 
		};
	
	};
	int IsOccupiedandPowered()
	{		
		if(HasEnergyManager() && GetCompEM().IsWorking())
		{
			return true;
		}
		return false;
	};
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool CanPutAsAttachment( EntityAI parent ) 
	{
		
		if (!super.CanPutAsAttachment(parent))
			return false;		
		return true;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of CP_PlasticWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void SetActions() 
	{
		super.SetActions();
		AddAction(ActionAttach);
		AddAction(ActionDetach);
		//AddAction(ActionUsePlasticWrapper);
		//AddAction(ActionChangeDrillPressAction);
	}
}      