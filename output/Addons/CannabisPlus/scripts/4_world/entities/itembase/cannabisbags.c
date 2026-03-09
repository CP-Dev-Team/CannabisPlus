class CP_CannabisBags extends CP_CoreClass
{
    protected string m_cpBrick= "";
	protected string m_CpRipBag="";
    
    void CP_CannabisBags()
	{
        if ( ConfigIsExisting("cpStepUpToBrick") ) 
		{
            m_cpBrick= ConfigGetString("cpStepUpToBrick");
        }
		else
		{
            m_cpBrick= "";
        }
		
		if ( ConfigIsExisting("cpStepDownToBud") ) 
		{
            m_CpRipBag = ConfigGetString("cpStepDownToBud");
        }
		else
		{
            m_CpRipBag = "";
        }
    }
		
	string GetcpBrick()
	{
        return m_cpBrick;
    }
	
	string GetCPRipBag()
	{
        return m_CpRipBag;
    }
	
	override string GetCPitemTendancyText()
	{		
        return "Rip open " + GetDisplayName();
    };
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionCP_RipOpenBrickOrBag);
		//AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
};