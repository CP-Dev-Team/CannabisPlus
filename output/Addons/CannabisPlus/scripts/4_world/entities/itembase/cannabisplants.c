class CP_RawPlantBase extends ItemBase
{
	string m_StrainName;

	void CP_RawPlantBase()
	{
		RegisterNetSyncVariableInt( "yield" );
	}
	
	int yield = 0;

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		if (g_Game.IsServer() && (!ctx.Read( yield ) || !ctx.Read( m_StrainName )))
		{
			return false;
		}
		return true;
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// call the inherited class
		super.OnStoreSave( ctx );
		if(g_Game.IsServer())
		{
			ctx.Write( yield );
			ctx.Write( m_StrainName );
		}
	}

	void SetYield(int value)
	{
		CPDebugPrint("Setting yield to: " + value);
		yield = value;
		SetSynchDirty();
	}

	int GetYield()
	{
		return yield;
	}

	void SetStrain(string strain)
	{
		CPDebugPrint("Setting strain to: " + strain);
		m_StrainName = strain;
		SetSynchDirty();
	}

	string GetStrain()
	{
		return m_StrainName;
	}
}

class CP_DriedCannabisPlant extends CP_RawPlantBase
{

}