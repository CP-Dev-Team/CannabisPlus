//preconfiguring the CannabisPlus.json
class CannabisPlusConfig
{
	int configVersion				= 100;
	
	bool removeAfterHarvest 		= true;
	
	float tobacco_growtime 			= 8;
	float tobacco_cropcount 		= 2;
	float tobaccoSeed_count 		= 9;
	
	float cannabis_growtime         = 8; //deprecated
	float cannabis_cropcount        = 2; //deprecated
	float cannabisSeed_count        = 9; //deprecated
	
	float cannabisSkunk_growtime 	= 8;
	float cannabisSkunk_cropcount 	= 2;
	float cannabisSkunkSeed_count 	= 9;
	
	float cannabisKush_growtime 	= 8;
	float cannabisKush_cropcount 	= 2;
	float cannabisKushSeed_count 	= 9;
	
	float cannabisBlue_growtime 	= 8;
	float cannabisBlue_cropcount 	= 2;
	float cannabisBlueSeed_count 	= 9;

	float cannabisStardawg_growtime 	= 8;
	float cannabisStardawg_cropcount 	= 2;
	float cannabisStardawgSeed_count 	= 9;
	
	float pepper_growtime 			= 8;
	float pepper_cropcount 			= 2;
	float pepperSeed_count 			= 9;
	
	float tomato_growtime 			= 8;
	float tomato_cropcount 			= 2;
	float tomatoSeed_count 			= 9;
	
	float zucchini_growtime 		= 8;
	float zucchini_cropcount 		= 2;
	float zucchiniSeed_count 		= 9;
	
	float pumpkin_growtime 			= 8;
	float pumpkin_cropcount 		= 2;
	float pumpkinSeed_count 		= 9;
	
	// smoke effect settings
	bool activateCigaretteSmokingEffect = true; // reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingCigaretteEffectDuration 	= 20;	// Time in seconds for the effect to stop
	int cigarettesToActivateEffect 		= 1;	// number of cigarettes consumed to activate the effect
	// joint smoke effect settings
	bool activateJointSmokingEffect 	= true; // reduces the fluctuation/sway in aiming when a cigarette is smoked
	int smokingJointEffectDuration 		= 20;	// Time in seconds for the effect to stop
	int jointsToActivateEffect 			= 1;	// number of cigarettes consumed to activate the effect

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CannabisPlus{
	static ref CannabisPlus g_CannabisPlus;		
	private string CONFIG_FILE =  "$profile:CannabisPlus.json";
	private ref CannabisPlusConfig _config;
	
	private int modVersion = 100;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CannabisPlus(){
		
		if ( GetGame().IsServer() ){
			_config = new CannabisPlusConfig();
			string fileName;
			FileAttr fileAttr;
			FindFileHandle configFile = FindFile(CONFIG_FILE, fileName, fileAttr, 0);
			if(!configFile){
				JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
				Print("Create new Config File");
			}
			else{
								
				if(_config.configVersion == modVersion) {
					JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
					Print("Load Config File");
				} else {
					
					DeleteFile("$profile:CannabisPlus_old.json");
					CopyFile(CONFIG_FILE, "$profile:CannabisPlus_old.json");
					DeleteFile(CONFIG_FILE);
					JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
					JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
					
					Print("Copy old Config File");
				}
			}
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// returns a reference of cannabis class to get access to neccessary variables
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static ref CannabisPlus getInstance(){
		
		if(!g_CannabisPlus){
			g_CannabisPlus = new CannabisPlus();
		}
		
		return g_CannabisPlus;
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// returns the config of cannabis plus to get access to variables
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	CannabisPlusConfig GetConfig(){
		return _config;
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Cannabis //deprecated
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

modded class Plant_CannabisSkunk
{	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_CannabisBlue
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_CannabisKush
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// NEXT UPDATE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_CannabisStardawg
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class Plant_Tobacco
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
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
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
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
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
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
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
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
		if(GetGame().IsServer() && CannabisPlus.getInstance().GetConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlant, 10, true );
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
modded class PlantBase
{	
	private float m_growtime;
	
	private float m_tabacco_growtime;
	private	float m_cannabis_growtime; //deprecated
	private	float m_cannabisSkunk_growtime; 
	private float m_cannabisKush_growtime;
	private float m_cannabisBlue_growtime;
	// NEXT UPDATE
	private float m_cannabisStardawg_growtime;
	// END NEXT UPDATE
	private float m_pepper_growtime;
	private float m_tomato_growtime;
	private float m_zucchini_growtime;
	private float m_pumpkin_growtime;
	
	private float m_tabacco_cropcount;
	private float m_cannabis_cropcount; // deprecated7
	private float m_cannabisSkunk_cropcount;
	private float m_cannabisKush_cropcount;
	private float m_cannabisBlue_cropcount;
	// NEXT UPDATE
	private float m_cannabisStardawg_cropcount;
	// END NEXT UPDATE
	private float m_pepper_cropcount;
	private float m_tomato_cropcount;
	private float m_zucchini_cropcount;
	private float m_pumpkin_cropcount;
	
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
		m_tabacco_growtime 			= CannabisPlus.getInstance().GetConfig().tobacco_growtime;
		m_cannabis_growtime         =  CannabisPlus.getInstance().GetConfig().cannabis_growtime; //deprecated
		m_cannabisSkunk_growtime 	= CannabisPlus.getInstance().GetConfig().cannabisSkunk_growtime;
		m_cannabisKush_growtime 	= CannabisPlus.getInstance().GetConfig().cannabisKush_growtime;
		m_cannabisBlue_growtime	 	= CannabisPlus.getInstance().GetConfig().cannabisBlue_growtime;
		// NEXT UPDATE
		m_cannabisStardawg_growtime	 	= CannabisPlus.getInstance().GetConfig().cannabisStardawg_growtime;
		// END NEXT UPDATE
		m_pepper_growtime 			= CannabisPlus.getInstance().GetConfig().pepper_growtime;
		m_tomato_growtime 			= CannabisPlus.getInstance().GetConfig().tomato_growtime;
		m_zucchini_growtime 		= CannabisPlus.getInstance().GetConfig().zucchini_growtime;
		m_pumpkin_growtime 			= CannabisPlus.getInstance().GetConfig().pumpkin_growtime;
	
		m_tabacco_cropcount 		= CannabisPlus.getInstance().GetConfig().tobacco_cropcount;
		m_cannabis_cropcount 	    = CannabisPlus.getInstance().GetConfig().cannabis_cropcount; //deprecated
		m_cannabisSkunk_cropcount 	= CannabisPlus.getInstance().GetConfig().cannabisSkunk_cropcount;
		m_cannabisKush_cropcount 	= CannabisPlus.getInstance().GetConfig().cannabisKush_cropcount;
		m_cannabisBlue_cropcount 	= CannabisPlus.getInstance().GetConfig().cannabisBlue_cropcount;
		// NEXT UPDATE
		m_cannabisStardawg_cropcount 	= CannabisPlus.getInstance().GetConfig().cannabisStardawg_cropcount;
		// END NEXT UPDATE
		m_pepper_cropcount 			= CannabisPlus.getInstance().GetConfig().pepper_cropcount;
		m_tomato_cropcount 			= CannabisPlus.getInstance().GetConfig().tomato_cropcount;
		m_zucchini_cropcount 		= CannabisPlus.getInstance().GetConfig().zucchini_cropcount;
		m_pumpkin_cropcount 		= CannabisPlus.getInstance().GetConfig().pumpkin_cropcount;

		m_GardenBase = garden_base;
		
		// set fertility from default 1 to 2 if fertility larger then 1 to double income
		if(fertility > 1.0) {
			isFertilized = true;
		}
		
		//sets growtime and cropcount out of CannabisPlus.json
		switch(this.GetType()){
		    case "Plant_Cannabis": //deprecated
				m_growtime = m_cannabis_growtime;
				m_CropsCount = m_cannabis_cropcount;
				break;
			// cannabis skunk
			case "Plant_CannabisSkunk":
				m_growtime = m_cannabisSkunk_growtime;
				m_CropsCount = m_cannabisSkunk_cropcount;
				break;
			// cannabis blue
			case "Plant_CannabisBlue":
				m_growtime = m_cannabisBlue_growtime;
				m_CropsCount = m_cannabisBlue_cropcount;
				break;
			// cannabis kush
			case "Plant_CannabisKush":
				m_growtime = m_cannabisKush_growtime;
				m_CropsCount = m_cannabisKush_cropcount;
				break;
			// cannabis Stardawg
			case "Plant_CannabisStardawg":
				m_growtime = m_cannabisStardawg_growtime;
				m_CropsCount = m_cannabisStardawg_cropcount;
				break;
			// tobacco
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

			default:
				m_growtime = 8;		
				m_CropsCount = 5;	
				break;

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
	private int m_tobaccoSeed_count;		// number of tobacco seeds that emerge
	private int m_cannabisSeed_count;       // deprecated
	private int m_cannabisSkunkSeed_count;	// number of cannabis skunk seeds that emerge
	private int m_cannabisBlueSeed_count;	// number of cannabis blue emerge
	private int m_cannabisKushSeed_count;	// number of cannabis kush that emerge
	private int m_cannabisStardawgSeed_count;	// number of cannabis Stardawg seeds that emerge
	private int m_pepperSeed_count;			// number of pepper seeds that emerge
	private int m_tomatoSeed_count;			// number of tomato seeds that emerge
	private int m_zucchiniSeed_count;		// number of zucchini seeds that emerge
	private int m_pumpkinSeed_count;		// number of pumpkin seeds that emerge
	

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
		int seeds_quantity = seeds_quantity_max;
		// read seed count values from config file
		m_tobaccoSeed_count 		=  CannabisPlus.getInstance().GetConfig().tobaccoSeed_count;		// tobacco
		m_cannabisSeed_count        =  CannabisPlus.getInstance().GetConfig().cannabisSeed_count;       //deprecated
		m_cannabisSkunkSeed_count 	=  CannabisPlus.getInstance().GetConfig().cannabisSkunkSeed_count;	// cannabis skunk
		m_cannabisBlueSeed_count 	=  CannabisPlus.getInstance().GetConfig().cannabisBlueSeed_count;	// cannbis blue
		m_cannabisKushSeed_count 	=  CannabisPlus.getInstance().GetConfig().cannabisKushSeed_count;	// cannabis kush
		m_cannabisStardawgSeed_count 	=  CannabisPlus.getInstance().GetConfig().cannabisStardawgSeed_count;	// cannabis Stardawg
		m_pepperSeed_count 			=  CannabisPlus.getInstance().GetConfig().pepperSeed_count;			// pepper
		m_tomatoSeed_count 			=  CannabisPlus.getInstance().GetConfig().tomatoSeed_count;			// tomato
		m_zucchiniSeed_count 		=  CannabisPlus.getInstance().GetConfig().zucchiniSeed_count;		// zucchini
		m_pumpkinSeed_count 		=  CannabisPlus.getInstance().GetConfig().pumpkinSeed_count;		// pumpkin
		// select the current seedpack
		switch(this.GetType()) {
			case "CannabisSeedsPack":  //deprecated
				seeds_quantity_max = m_cannabisSeed_count;
				break;			
			// Cannabis Skunk seedpack
			case "CannabisSeedsPackSkunk":
				seeds_quantity_max = m_cannabisSkunkSeed_count;
				break;
			// Cannabis Blue seedpack
			case "CannabisSeedsPackBlue":
				seeds_quantity_max = m_cannabisBlueSeed_count;
				break;
			// Cannabis Stardawg seedpack
			case "CannabisSeedsPackStardawg":
				seeds_quantity_max = m_cannabisStardawgSeed_count;
				break;
			// Tobacco seedpack
			case "TobaccoSeedsPack":
				seeds_quantity_max = m_tobaccoSeed_count;
				break;
			// Cannabis Kush seedpack
			case "CannabisSeedsPackKush":
				seeds_quantity_max = m_cannabisKushSeed_count;
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
			
			default:
				seeds_quantity_max = 9;
				break;
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
