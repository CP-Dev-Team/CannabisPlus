// Cannabis bags now extend AC_BagBase for standardized bag system
class CP_CannabisBags extends AC_BagBase
{
	// Legacy property names kept for backward compatibility
	protected string m_cpBrick = "";
	protected string m_CpRipBag = "";
	
	void CP_CannabisBags()
	{
		// Parent AC_BagBase constructor calls LoadConfigProperties()
	}
	
	// Override to load CannabisPlus-specific config properties
	override protected void LoadConfigProperties()
	{
		if (ConfigIsExisting("cpStepUpToBrick"))
		{
			m_cpBrick = ConfigGetString("cpStepUpToBrick");
			m_StepUpItem = m_cpBrick;  // Also set base class property
		}
		else
		{
			m_cpBrick = "";
		}
		
		if (ConfigIsExisting("cpStepDownToBud"))
		{
			m_CpRipBag = ConfigGetString("cpStepDownToBud");
			m_StepDownItem = m_CpRipBag;  // Also set base class property
		}
		else
		{
			m_CpRipBag = "";
		}
	}
	
	// Legacy getter methods for backward compatibility with existing recipes
	string GetcpBrick()
	{
		return m_cpBrick;  // Same as GetStepUpItem()
	}
	
	string GetCPRipBag()
	{
		return m_CpRipBag;  // Same as GetStepDownItem()
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