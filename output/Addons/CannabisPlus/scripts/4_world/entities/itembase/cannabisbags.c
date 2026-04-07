// Cannabis bags now extend AC_BagBase for standardized bag system
class CP_CannabisBags extends AC_BagBase
{
	// Override to set base class properties via StrainHelper
	override protected void LoadConfigProperties()
	{
		m_StepUpItem = CP_StrainHelper.GetBrickFromBag(GetType());
		m_StepDownItem = CP_StrainHelper.GetBudFromBag(GetType());
	}
	
	string GetcpBrick()
	{
		return CP_StrainHelper.GetBrickFromBag(GetType());
	}
	
	string GetCPRipBag()
	{
		return CP_StrainHelper.GetBudFromBag(GetType());
	}
	
	// Override AG_CoreClass tendancy text for rip-open action display
	override string GetACitemTendancyText()
	{		
        return "Rip open " + GetDisplayName();
    }
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionCP_RipOpenBrickOrBag);
		//AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
};