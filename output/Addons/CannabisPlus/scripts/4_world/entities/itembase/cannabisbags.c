class CP_CannabisBags extends ItemBase
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
	
	string GetCPitemTendancyText()
	{		
        return "Rip open " + GetDisplayName();
    };
	


	
	
	//void RipOpenBag()
	//{
	//	string Bagname = GetCPRipBag(); 
	//	
	//	ReplaceEdibleWithNew("Bagname");
	//};
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionCP_RipOpenBrickOrBag);
		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
};
class CP_EmptyBag extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
};

class CP_CannabisBagSkunk extends CP_CannabisBags{};

class CP_CannabisBagBlue extends CP_CannabisBags{};

class CP_CannabisBagKush extends CP_CannabisBags{};

class CP_CannabisBagStardawg extends CP_CannabisBags{};

class CP_CannabisBagFuture extends CP_CannabisBags{};

class CP_CannabisBagS1 extends CP_CannabisBags{};

class CP_CannabisBagNomad extends CP_CannabisBags{};

class CP_CannabisBagBlackFrost extends CP_CannabisBags{};
