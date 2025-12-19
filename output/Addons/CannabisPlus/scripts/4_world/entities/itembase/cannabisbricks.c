class CP_CannabisBrickBase extends CP_CoreClass 
{
	void CP_CannabisBrickBase(){}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCP_RipOpenBrickOrBag);
		//AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
	override string GetCPitemTendancyText()
	{		
        return "#cp_unwrap " + GetDisplayName();
    };
	
};