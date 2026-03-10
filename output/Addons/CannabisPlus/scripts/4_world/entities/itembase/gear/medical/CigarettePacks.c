class CP_JointPack extends AC_CigarettePack_Empty
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