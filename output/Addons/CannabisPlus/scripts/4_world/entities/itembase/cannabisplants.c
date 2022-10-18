class CP_RawPlantBase extends ItemBase
{

	void CP_RawPlantBase()
	{
		RegisterNetSyncVariableBool( "yield" );
	}
	int yield = 0;

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		if (GetGame().IsServer() && !ctx.Read( yield ))
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
		}
	}


	
	void SetYield(int value) 
	{
		yield = value;
	}
	
	int GetYield() 
	{
		return yield;
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