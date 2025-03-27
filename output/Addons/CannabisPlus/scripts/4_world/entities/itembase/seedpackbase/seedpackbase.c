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
		m_tobaccoSeed_count 			=  GetCPConfig().GetGeneralConfig().tobaccoSeed_count;
		m_cannabisSkunkSeed_count 		=  GetCPConfig().LoadStrain("CannabisSkunk").SeedCount;
		m_cannabisBlueSeed_count 		=  GetCPConfig().LoadStrain("CannabisBlue").SeedCount;
		m_cannabisKushSeed_count 		=  GetCPConfig().LoadStrain("CannabisKush").SeedCount;
		m_cannabisStardawgSeed_count 	=  GetCPConfig().LoadStrain("CannabisStardawg").SeedCount;

		m_cannabisFutureSeed_count 		=  GetCPConfig().LoadStrain("CannabisFuture").SeedCount;
		m_cannabisS1Seed_count 			=  GetCPConfig().LoadStrain("CannabisS1").SeedCount;
		m_cannabisNomadSeed_count 		=  GetCPConfig().LoadStrain("CannabisNomad").SeedCount;
		m_cannabisBlackFrostSeed_count 	=  GetCPConfig().LoadStrain("CannabisBlackFrost").SeedCount;

		m_pepperSeed_count 				=  GetCPConfig().GetGeneralConfig().pepperSeed_count;
		m_tomatoSeed_count 				=  GetCPConfig().GetGeneralConfig().tomatoSeed_count;
		m_zucchiniSeed_count 			=  GetCPConfig().GetGeneralConfig().zucchiniSeed_count;
		m_pumpkinSeed_count 			=  GetCPConfig().GetGeneralConfig().pumpkinSeed_count;
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
		
		seeds_quantity = Math.Round(seeds_quantity_max * GetHealth01("",""));
	
		if (seeds_quantity < 1)
		{ 
			seeds_quantity = 1;
		}
		
		if (player)
		{
			EmptySeedsPackLambda lambda = new EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
		{
			vector pos = GetPosition();
			GetGame().CreateObjectEx(seeds_type, pos, ECE_PLACE_ON_SURFACE);
			GetGame().ObjectDelete(this);
		}
	}
}