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
}
class CP_CigarettePack_Empty: CigarettePack_ColorBase {};