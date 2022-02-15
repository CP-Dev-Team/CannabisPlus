class CP_CannabisBags extends ItemBase
{
   
    protected string m_cpBrick= "";
    
    void CP_CannabisBags ()
	{
        
        if ( ConfigIsExisting("cpStepUpToBrick") ) 
		{
            m_cpBrick= ConfigGetString("cpStepUpToBrick");
        }
		else
		{
            m_cpBrick= "";
        }
    }
    
    string GetcpBrick()
	{
        return m_cpBrick;
    }
};
class CP_EmptyBag extends ItemBase{};

class CP_CannabisBagSkunk extends CP_CannabisBags{};

class CP_CannabisBagBlue extends CP_CannabisBags{};

class CP_CannabisBagKush extends CP_CannabisBags{};

class CP_CannabisBagStardawg extends CP_CannabisBags{};

class CP_CannabisBagFuture extends CP_CannabisBags{};

class CP_CannabisBagS1 extends CP_CannabisBags{};

class CP_CannabisBagNomad extends CP_CannabisBags{};

class CP_CannabisBagBlackFrost extends CP_CannabisBags{};
