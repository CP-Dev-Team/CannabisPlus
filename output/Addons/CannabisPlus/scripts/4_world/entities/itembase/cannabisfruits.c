class CP_CannabisBud extends CP_CoreClass
{
	   
    protected string m_cpBags= "";
	
	protected string m_cpJoint= "";
    
    void CP_CannabisBud ()
	{
        
        if ( ConfigIsExisting("cpStepUpToBag") ) 
		{
            m_cpBags= ConfigGetString("cpStepUpToBag");
        }
		else
		{
            m_cpBags= "";
        }
		
		if ( ConfigIsExisting("cpStepUpToJoint") ) 
		{
            m_cpJoint= ConfigGetString("cpStepUpToJoint");
        }
		else
		{
            m_cpJoint= "";
        }
    }
	
    string GetcpBag()
	{
        return m_cpBags;
    }
	
	string GetcpJoint()
	{
		return m_cpJoint;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
	
};

class CP_CannabisSkunk extends CP_CannabisBud{};

class CP_CannabisBlue extends CP_CannabisBud{};

class CP_CannabisKush extends CP_CannabisBud{};

class CP_CannabisStardawg extends CP_CannabisBud{};

class CP_CannabisFuture extends CP_CannabisBud{};

class CP_CannabisS1 extends CP_CannabisBud{};

class CP_CannabisNomad extends CP_CannabisBud{};

class CP_CannabisBlackFrost extends CP_CannabisBud{};

class CP_Tobacco extends CP_CannabisBud{};


