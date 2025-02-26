class CP_CoreClass extends ItemBase 
{

	string GetCPitemTendancyText()
	{		
        return "";
    };
}

modded class CP_Plant_CannabisSkunk
{	
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisBlue
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisKush
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisStardawg
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisFuture {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisS1 {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisNomad {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_CannabisBlackFrost {
	override void Harvest(PlayerBase player) {
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class CP_Plant_Tobacco
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Pepper
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Tomato
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Zucchini
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Pumpkin
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Potato
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().removeAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

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

modded class ActionHarvestCrops: ActionInteractBase
{   
    override void OnExecuteClient( ActionData action_data )
    {    
        if(m_Plant && m_Plant.HasCrops()){
            // call the inherited class
            super.OnExecuteClient(action_data);
        }
    }
    
    override void OnExecuteServer( ActionData action_data )
    {
        if(m_Plant && m_Plant.HasCrops()){
            super.OnExecuteServer(action_data);
        }
    }
};

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
