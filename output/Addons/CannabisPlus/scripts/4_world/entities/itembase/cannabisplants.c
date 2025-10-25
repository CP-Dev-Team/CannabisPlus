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
		if (GetGame().IsServer() && (!ctx.Read( yield ) || !ctx.Read( m_StrainName )))
		{
			return false;
		}
		return true;
	}
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// call the inherited class
		super.OnStoreSave( ctx );
		if(GetGame().IsServer())
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

class CP_RawSkunkCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawBlueCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawKushCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawStardawgCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawFutureCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawS1CannabisPlant extends CP_RawPlantBase
{

}

class CP_RawNomadCannabisPlant extends CP_RawPlantBase
{

}

class CP_RawBlackFrostCannabisPlant extends CP_RawPlantBase
{

}

class CP_DriedCannabisPlant extends CP_RawPlantBase
{

}