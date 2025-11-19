class CP_JointPack extends ItemBase
{
	protected string m_cpPackage= "";
    
    void CP_JointPack()
	{
        
        if ( ConfigIsExisting("cpCheckPack") ) 
		{
            m_cpPackage= ConfigGetString("cpCheckPack");
        }
		else
		{
            m_cpPackage= "";
        }
    }
	
    string GetCpPackageName()
	{
        return m_cpPackage;
    }

	override void SetActions()
	{
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
}

class CP_CigarettePack_CannabisSkunk: CP_JointPack {};

class CP_CigarettePack_CannabisBlackFrost: CP_JointPack {};

class CP_CigarettePack_CannabisBlue: CP_JointPack {};

class CP_CigarettePack_CannabisStardawg: CP_JointPack {};

class CP_CigarettePack_CannabisS1: CP_JointPack {};

class CP_CigarettePack_CannabisNomad: CP_JointPack {};

class CP_CigarettePack_CannabisKush : CP_JointPack {};

class CP_CigarettePack_CannabisFuture: CP_JointPack {};

modded class CigarettePack_Chernamorka: Box_Base 
{	
	override void SetActions()	{
		
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};

modded class CigarettePack_Partyzanka: Box_Base 
{	
	override void SetActions()	{
		
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};

modded class CigarettePack_Merkur: Box_Base 
{	
	override void SetActions()	{
		
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};

class CP_CigarettePack_Empty: CigarettePack_ColorBase {};