//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// The CP_PlasticWrapper class provides all methods for Plastic wrapper machine.
// Currently, the class is only required for the item to be available in the game. 
// All methods to use the plastic wrapper are in the class CP_Workbench.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_PlasticWrapper extends ItemBase 
{
	protected ItemBase 			m_Parent;
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

		return "Skunk";

    };
	CP_CannabisBud GetCannibusBud()
	{
		return CP_CannabisBud.Cast( GetAttachmentByType( CP_CannabisBud ) );
	};
	
	void CreationWrapperItems(string CreationType)
	{
		Print ("trigger");

		string thingName =  FindAttachmentBySlotName("CP_Cannabus_Buds").GetType();
		ItemBase CannabisBud = GetCannibusBud();
		
		
		Print(thingName);
				
		if (thingName == "CP_CannabisSkunk" )
		{
			//m_UseWrapper = 1;
			GetGame().ObjectDelete( GetCannibusBud() );
			CP_CannabisBrickBase Brick = CP_CannabisBrickBase.Cast(GetInventory().CreateAttachment("CP_CannabisBrick" + CreationType ) );
			Brick.AddQuantity(1);
			AddHealth("","Health",-1);
			CannabisBud.AddQuantity(-20);			
		};
	
	};

	bool IsAttachedToPoweredItem()
	{
		if(m_Parent.GetCompEM().IsWorking())
			return true;
		return false;
		
	}
	
	
	bool IsOccupiedandPowered()
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


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of CP_PlasticWrapper class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void SetActions() 
	{
		super.SetActions();
		AddAction(ActionAttach);
		AddAction(ActionDetach);
		AddAction(ActionUsePlasticWrapper);
		//AddAction(ActionChangeDrillPressAction);
	}
}      