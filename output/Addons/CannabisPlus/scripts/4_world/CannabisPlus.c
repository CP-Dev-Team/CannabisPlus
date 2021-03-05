//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class CP_Plant_CannabisSkunk
{	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class CP_Plant_CannabisBlue
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class CP_Plant_CannabisKush
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// NEXT UPDATE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* 
 * Stardawg strain 
 */
modded class CP_Plant_CannabisStardawg
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


/* 
 * Future strain 
 */
modded class CP_Plant_CannabisFuture {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

/*
 * S1 strain
 */

modded class CP_Plant_CannabisS1 {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

/*
 * Nomad strain
 */

modded class CP_Plant_CannabisNomad {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

/*
 * 
 *  BlackFrost
 */

modded class CP_Plant_CannabisBlackFrost {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class CP_Plant_Tobacco
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Pepper
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Tomato
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Zucchini
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Pumpkin
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlantBase
{	
	private int m_growtime;
	
	private int m_tabacco_growtime;
	private	int m_cannabisSkunk_growtime; 
	private int m_cannabisKush_growtime;
	private int m_cannabisBlue_growtime;
	private int m_cannabisStardawg_growtime;
	private int m_cannabisFuture_growtime;
	private int m_cannabisS1_growtime;
	private int m_cannabisNomad_growtime;
	private int m_cannabisBlackFrost_growtime;

	private int m_pepper_growtime;
	private int m_tomato_growtime;
	private int m_zucchini_growtime;
	private int m_pumpkin_growtime;
	
	private int m_tabacco_cropcount;
	private int m_cannabisSkunk_cropcount;
	private int m_cannabisKush_cropcount;
	private int m_cannabisBlue_cropcount;
	private int m_cannabisStardawg_cropcount;
	private int m_cannabisFuture_cropcount;
	private int m_cannabisS1_cropcount;
	private int m_cannabisNomad_cropcount;
	private int m_cannabisBlackFrost_cropcount;

	private int m_pepper_cropcount;
	private int m_tomato_cropcount;
	private int m_zucchini_cropcount;
	private int m_pumpkin_cropcount;
	
	ref Timer m_DeleteDryPlantTimer = NULL;
	
	private GardenBase m_GardenBase = NULL;	
	private PluginHorticulture m_ModuleHorticulture;
	
	void PlantBase()
	{
		
		string plant_type = this.GetType();
		
		m_ModuleHorticulture 	= PluginHorticulture.Cast( GetPlugin( PluginHorticulture ) );		
		m_SprayUsage 			= 5;
		m_DeleteDryPlantTime 	= (60 * 10) + Math.RandomInt(0, 60 * 2);
		m_SpoiledRemoveTime 	= (60 * 20) + Math.RandomInt(0, 60 * 5);
		m_InfestationChance 	= 0.0; 															// Temporarily disabled until its fixed. Infestation is not visualy persistent over server restarts and m_SpoiledRemoveTimer crashes when it's meant to delete the plant.		
		m_GrowthStagesCount 	= GetGame().ConfigGetInt( "cfgVehicles " + plant_type + " Horticulture GrowthStagesCount" );
		//m_CropsCount = GetGame().ConfigGetInt( "cfgVehicles " + plant_type + " Horticulture CropsCount" );
		GetGame().ConfigGetText( "cfgVehicles " + plant_type + " Horticulture CropsType", m_CropsType );

		m_PlantStateIndex 				= -1;
		m_CurrentPlantMaterialQuantity 	= 0;
		m_IsInfested 					= false;
		m_SprayQuantity 				= 0.0;
		m_HasCrops 						= true;
	}

	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// destructor of plantbase class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	void ~PlantBase() {
		
		if (!m_MarkForDeletion) {
			RemovePlant();
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Init( GardenBase garden_base, float fertility, float harvesting_efficiency, float water)
	{	
		private bool isFertilized = false;
		//reads settings from CannabisPlus.json
		m_tabacco_growtime 				= GetCPConfig().tobacco_growtime;
		m_cannabisSkunk_growtime 		= GetCPConfig().cannabisSkunk_growtime;
		m_cannabisKush_growtime 		= GetCPConfig().cannabisKush_growtime;
		m_cannabisBlue_growtime	 		= GetCPConfig().cannabisBlue_growtime;
		m_cannabisStardawg_growtime		= GetCPConfig().cannabisStardawg_growtime;
		m_cannabisFuture_growtime 		= GetCPConfig().cannabisFuture_growtime;
		m_cannabisS1_growtime 			= GetCPConfig().cannabisS1_growtime;
		m_cannabisNomad_growtime 		= GetCPConfig().cannabisNomad_growtime;
		m_cannabisBlackFrost_growtime 	= GetCPConfig().cannabisBlackFrost_growtime;

		m_pepper_growtime 				= GetCPConfig().pepper_growtime;
		m_tomato_growtime 				= GetCPConfig().tomato_growtime;
		m_zucchini_growtime 			= GetCPConfig().zucchini_growtime;
		m_pumpkin_growtime 				= GetCPConfig().pumpkin_growtime;
	
		m_tabacco_cropcount 			= GetCPConfig().tobacco_cropcount;
		m_cannabisSkunk_cropcount 		= GetCPConfig().cannabisSkunk_cropcount;
		m_cannabisKush_cropcount 		= GetCPConfig().cannabisKush_cropcount;
		m_cannabisBlue_cropcount 		= GetCPConfig().cannabisBlue_cropcount;
		m_cannabisStardawg_cropcount 	= GetCPConfig().cannabisStardawg_cropcount;
		m_cannabisFuture_cropcount 		= GetCPConfig().cannabisFuture_cropcount;
		m_cannabisS1_cropcount 			= GetCPConfig().cannabisS1_cropcount;
		m_cannabisNomad_cropcount 		= GetCPConfig().cannabisNomad_cropcount;
		m_cannabisBlackFrost_cropcount 	= GetCPConfig().cannabisBlackFrost_cropcount;
		
		m_pepper_cropcount 				= GetCPConfig().pepper_cropcount;
		m_tomato_cropcount 				= GetCPConfig().tomato_cropcount;
		m_zucchini_cropcount 			= GetCPConfig().zucchini_cropcount;
		m_pumpkin_cropcount 			= GetCPConfig().pumpkin_cropcount;

		m_GardenBase = garden_base;
		
		// set fertility from default 1 to 2 if fertility larger then 1 to double income
		if(fertility > 1.0) {
			isFertilized = true;
		}
		
		//sets growtime and cropcount out of CannabisPlus.json
		switch(this.GetType()){
		    // cannabis skunk
			case "CP_Plant_CannabisSkunk":
				m_growtime = m_cannabisSkunk_growtime;
				m_CropsCount = m_cannabisSkunk_cropcount;
				break;
			// cannabis blue
			case "CP_Plant_CannabisBlue":
				m_growtime = m_cannabisBlue_growtime;
				m_CropsCount = m_cannabisBlue_cropcount;
				break;
			// cannabis kush
			case "CP_Plant_CannabisKush":
				m_growtime = m_cannabisKush_growtime;
				m_CropsCount = m_cannabisKush_cropcount;
				break;

			// cannabis Stardawg
			case "CP_Plant_CannabisStardawg":
				m_growtime = m_cannabisStardawg_growtime;
				m_CropsCount = m_cannabisStardawg_cropcount;
				break;

			// cannabis Future
			case "CP_Plant_CannabisFuture":
				m_growtime = m_cannabisFuture_growtime;
				m_CropsCount = m_cannabisFuture_cropcount;
				break;

			// cannabis S1
			case "CP_Plant_CannabisS1":
				m_growtime = m_cannabisS1_growtime;
				m_CropsCount = m_cannabisS1_cropcount;
				break;

			// cannabis Nomad
			case "CP_Plant_CannabisNomad":
				m_growtime = m_cannabisNomad_growtime;
				m_CropsCount = m_cannabisNomad_cropcount;
				break;

			// cannabis BlackFrost
			case "CP_Plant_CannabisBlackFrost":
				m_growtime = m_cannabisBlackFrost_growtime;
				m_CropsCount = m_cannabisBlackFrost_cropcount;
				break;
		
			// tobacco
			case "CP_Plant_Tobacco":
				m_growtime = m_tabacco_growtime;
				m_CropsCount = m_tabacco_cropcount;
				break;
			// deprecated
			case "Plant_Tobacco":
				m_growtime = m_tabacco_growtime;
				m_CropsCount = m_tabacco_cropcount;
				break;	
			// pepper 
			case "Plant_Pepper":
				m_growtime = m_pepper_growtime;
				m_CropsCount = m_pepper_cropcount;
				break;
			// tomato
			case "Plant_Tomato":
				m_growtime = m_tomato_growtime;
				m_CropsCount = m_tomato_cropcount;
				break;
			// zucchini
			case "Plant_Zucchini":
				m_growtime = m_zucchini_growtime;
				m_CropsCount = m_zucchini_cropcount;
				break;
			// pumpkin
			case "Plant_Pumpkin":
				m_growtime = m_pumpkin_growtime;
				m_CropsCount = m_pumpkin_cropcount;
				break;
			//not a CP plant, exit function to avoid messing up other plants
			default:
				return;

		}

		// if the plant is fertilized reduce time that the plant is full-grown
		if(isFertilized) {
			m_FullMaturityTime = (float) ((48 * m_growtime) + Math.RandomInt(0, 30)) / fertility; 
		} else {
			m_FullMaturityTime = (float) ((48 * m_growtime) + Math.RandomInt(0, 30)); 
		}
		
		m_SpoilAfterFullMaturityTime 	= (float) ((60 * 30) + Math.RandomInt(0, 60 * 30)) * fertility;

		m_StateChangeTime 				= (float) ((float)m_FullMaturityTime / ((float)m_GrowthStagesCount - 2.0));

		// if the plant is fertilized double the cropcount
		if(isFertilized) {
			m_CropsCount = m_CropsCount * harvesting_efficiency * 2;
		} else {
			m_CropsCount = m_CropsCount * harvesting_efficiency;
		}
		
		m_PlantMaterialMultiplier 		= 0.1 * harvesting_efficiency;
		
		float rain_intensity = GetGame().GetWeather().GetRain().GetActual();
		
		if ( rain_intensity > 0.0 ) {
			CheckWater();
		}
		else {
			CheckWater();
			
			if ( NeedsWater() )	{
				SetPlantState(STATE_DRY);
				
				if (GetGame().IsServer()) {
					m_DeleteDryPlantTimer = new Timer( CALL_CATEGORY_SYSTEM );
					m_DeleteDryPlantTimer.Run( m_DeleteDryPlantTime, this, "DeleteDryPlantTick", NULL, false );
				}
			}
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		if (GetGame().IsServer() && !ctx.Read( m_HasCrops ) ){
			return false;
		}
		return true;
	}
	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// call the inherited class
		super.OnStoreSave( ctx );
		if(GetGame().IsServer()){
			ctx.Write( m_HasCrops );
		}
	}
	
	
	private bool harvestingSpamCheck = false;
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Harvest( PlayerBase player )
	{
		if(harvestingSpamCheck==false && m_HasCrops==true){
			harvestingSpamCheck = true;
			m_HasCrops = false;
			SetSynchDirty();
			UpdatePlant();
			super.Harvest(player);
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( clearSpamCheck, 5000, true );
		}	
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void clearSpamCheck(){
		harvestingSpamCheck = false;
	}	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class ActionPlantSeed: ActionSingleUseBase
{
	override void Process( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject != NULL && targetObject.IsInherited(GardenBase) )
		{
			ItemBase seed_IB = ItemBase.Cast( action_data.m_MainItem );
			int prePlantCount = seed_IB.GetQuantity();
			super.Process(action_data);
			if(prePlantCount == seed_IB.GetQuantity()) {
				prePlantCount--;
				seed_IB.SetQuantity(prePlantCount);
			}
		}
		else{
			// call the inherited class
			super.Process(action_data);
		}
	}
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class ActionHarvestCrops: ActionInteractBase
{
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnExecuteClient( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
		PlantBase plant = PlantBase.Cast( targetObject );
		if(plant.HasCrops()){
			// call the inherited class
			super.OnExecuteClient(action_data);
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlantBase plant = PlantBase.Cast( targetObject );
		if(plant.HasCrops()){
			super.OnExecuteServer(action_data);
		}
	}
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class SeedPackBase
{	
	private int m_tobaccoSeed_count;		
	private int m_cannabisSkunkSeed_count;	
	private int m_cannabisBlueSeed_count;	
	private int m_cannabisKushSeed_count;	
	private int m_cannabisStardawgSeed_count;	

	private int m_cannabisFutureSeed_count;
	private int m_cannabisS1Seed_count;
	private int m_cannabisNomadSeed_count;
	private int m_cannabisBlackFrostSeed_count;

	private int m_pepperSeed_count;			
	private int m_tomatoSeed_count;			
	private int m_zucchiniSeed_count;		
	private int m_pumpkinSeed_count;		
	

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void EmptySeedPack( PlayerBase player )
	{

		string pack_type = GetType();
		string seeds_type = "";
		
		GetGame().ConfigGetText( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsType", seeds_type );
		
		//int seeds_quantity_max = GetGame().ConfigGetInt( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsQuantity" );
		int seeds_quantity_max;
		int seeds_quantity;
		// read seed count values from config file
		m_tobaccoSeed_count 			=  GetCPConfig().tobaccoSeed_count;		
		m_cannabisSkunkSeed_count 		=  GetCPConfig().cannabisSkunkSeed_count;	
		m_cannabisBlueSeed_count 		=  GetCPConfig().cannabisBlueSeed_count;	
		m_cannabisKushSeed_count 		=  GetCPConfig().cannabisKushSeed_count;	
		m_cannabisStardawgSeed_count 	=  GetCPConfig().cannabisStardawgSeed_count;	

		m_cannabisFutureSeed_count 		=  GetCPConfig().cannabisFutureSeed_count;
		m_cannabisS1Seed_count 			=  GetCPConfig().cannabisS1Seed_count;
		m_cannabisNomadSeed_count 		=  GetCPConfig().cannabisNomadSeed_count;
		m_cannabisBlackFrostSeed_count 	=  GetCPConfig().cannabisBlackFrostSeed_count;

		m_pepperSeed_count 				=  GetCPConfig().pepperSeed_count;			
		m_tomatoSeed_count 				=  GetCPConfig().tomatoSeed_count;			
		m_zucchiniSeed_count 			=  GetCPConfig().zucchiniSeed_count;	
		m_pumpkinSeed_count 			=  GetCPConfig().pumpkinSeed_count;		
		// select the current seedpack
		switch(this.GetType()) {
			// Cannabis Skunk seedpack
			case "CP_CannabisSeedsPackSkunk":
				seeds_quantity_max = m_cannabisSkunkSeed_count;
				break;
			// Cannabis Blue seedpack
			case "CP_CannabisSeedsPackBlue":
				seeds_quantity_max = m_cannabisBlueSeed_count;
				break;
			// Cannabis Kush seedpack
			case "CP_CannabisSeedsPackKush":
				seeds_quantity_max = m_cannabisKushSeed_count;
				break;	
			// Cannabis Stardawg seedpack
			case "CP_CannabisSeedsPackStardawg":
				seeds_quantity_max = m_cannabisStardawgSeed_count;
				break;

			// Cannabis Future seedpack
			case "CP_CannabisSeedsPackFuture":
				seeds_quantity_max = m_cannabisFutureSeed_count;
				break;

			// Cannabis S1 seedpack
			case "CP_CannabisSeedsPackS1":
				seeds_quantity_max = m_cannabisS1Seed_count;
				break;

			// Cannabis Nomad seedpack
			case "CP_CannabisSeedsPackNomad":
				seeds_quantity_max = m_cannabisNomadSeed_count;
				break;

			// Cannabis BlackFrost seedpack
			case "CP_CannabisSeedsPackBlackFrost":
				seeds_quantity_max = m_cannabisBlackFrostSeed_count;
				break;

			// Tobacco seedpack
			case "CP_TobaccoSeedsPack":
				seeds_quantity_max = m_tobaccoSeed_count;
				break;
			// deprecated
			case "TobaccoSeedsPack":
				seeds_quantity_max = m_tobaccoSeed_count;
				break;	
			// Pepper seedpack
			case "PepperSeedsPack":
				seeds_quantity_max = m_pepperSeed_count;
				break;
			// Tomato seedpack
			case "TomatoSeedsPack":
				seeds_quantity_max = m_tomatoSeed_count;
				break;
			// Zucchini seedpack
			case "ZucchiniSeedsPack":
				seeds_quantity_max = m_zucchiniSeed_count;
				break;
			// Pumpkin seedpack
			case "PumpkinSeedsPack":
				seeds_quantity_max = m_pumpkinSeed_count;
				break;
			//not a CP plant, exit function to avoid messing up other plants
			default:
                        super.EmptySeedPack(player);
				return;
		}
		
		seeds_quantity = Math.Round( seeds_quantity_max * GetHealth01("","") );
		// 'resets' the seed quantity to 1 if...
		if ( seeds_quantity < 1 ) { 
			seeds_quantity = 1;
		}
		
		if (player)	{
			
			EmptySeedsPackLambda lambda = new EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else {
			
			vector pos = GetPosition();
			GetGame().CreateObject(seeds_type, pos);
			GetGame().ObjectDelete( this );
		}
	}
}
