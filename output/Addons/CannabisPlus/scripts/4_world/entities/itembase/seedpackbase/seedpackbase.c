modded class SeedPackBase
{	
	private int m_SeedCount;

	private int m_tobaccoSeed_count;

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

		string packType = this.GetType();
		string strainName;
		
		if (packType.Contains("CP_CannabisSeedsPack"))
		{
			strainName = "Cannabis" + packType.Substring(20, packType.Length() - 20); // Extracts the name after "CP_CannabisSeedsPack"

			if (g_CannabisStrainConfigs.Contains(strainName))
			{
				// Load the config from the map
				CannabisStrainConfig config = g_CannabisStrainConfigs.Get(strainName);
				m_SeedCount = config.SeedCount;
				seeds_quantity_max = m_SeedCount; //Can simplify later but just passing variables so OG code works.

				Print("[CP] Loaded strain config for: " + strainName + " | SeedCount: " + m_SeedCount );
			}
			else
			{
				Print("[CP] Warning: Strain config for '" + strainName + "' not found. Using default values.");
			}
		}
		else
		{
			Print("[CP] Not a CannabisPlus seed type: " + packType);
		}

		m_pepperSeed_count 				=  GetCPConfig().pepperSeed_count;
		m_tomatoSeed_count 				=  GetCPConfig().tomatoSeed_count;
		m_zucchiniSeed_count 			=  GetCPConfig().zucchiniSeed_count;
		m_pumpkinSeed_count 			=  GetCPConfig().pumpkinSeed_count;
		// select the current seedpack
		switch(this.GetType()) {
			// Tobacco seedpack
			case "CP_TobaccoSeedsPack":
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