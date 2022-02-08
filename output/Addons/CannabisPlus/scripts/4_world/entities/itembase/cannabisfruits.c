class CP_CannabisBud extends ItemBase
{
	   
    protected string m_cpBags= "";
    
    void CP_CannabisBags ()
	{
        
        if ( ConfigIsExisting("cpBag") ) 
		{
            m_cpBags= ConfigGetString("cpBag");
        }
		else
		{
            m_cpBags= "";
        }
    }
    
    string GetcpBrick()
	{
        return m_cpBags;
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


