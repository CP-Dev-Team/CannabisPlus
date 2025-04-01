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

        int seeds_quantity_max;
        int seeds_quantity;

        m_tobaccoSeed_count = GetCPConfig().tobaccoSeed_count;

        string packType = this.GetType();
        string strainName;

        if (packType.Contains("CP_CannabisSeedsPack"))
        {   
            Print("[DEBUG] Seedspack type is: " + packType + ". Continuing");
            strainName = "Cannabis" + packType.Substring(20, packType.Length() - 20);

            Print("[DEBUG] json to lookup is: " + strainName + ". Continuing");

            if (g_CannabisStrainConfigs.Contains(strainName))
            {
                Print("[DEBUG] Config contains: " + strainName + ". Continuing");

                CannabisStrainConfig config = g_CannabisStrainConfigs.Get(strainName);
                m_SeedCount = config.SeedCount;
                seeds_quantity_max = m_SeedCount;

                Print("[CP] Loaded strain config for: " + strainName + " | SeedCount: " + m_SeedCount + " | seeds_quantity_max: " + seeds_quantity_max );
            }
            else
            {
                Print("[CP] Warning: Strain config for '" + strainName + "' not found. Using default values.");
                CannabisStrainConfig defaultConfig = CannabisStrainConfig.CreateDefault();
                m_SeedCount = defaultConfig.SeedCount;
                seeds_quantity_max = m_SeedCount;

                Print("[CP] Fallback default SeedCount: " + m_SeedCount);
            }
        }
        else
        {
            Print("[CP] Not a CannabisPlus seed type: " + packType);
        }

        m_pepperSeed_count = GetCPConfig().pepperSeed_count;
        m_tomatoSeed_count = GetCPConfig().tomatoSeed_count;
        m_zucchiniSeed_count = GetCPConfig().zucchiniSeed_count;
        m_pumpkinSeed_count = GetCPConfig().pumpkinSeed_count;

        switch(this.GetType())
        {
            case "CP_TobaccoSeedsPack":
                seeds_quantity_max = m_tobaccoSeed_count;
                break;
            case "PepperSeedsPack":
                seeds_quantity_max = m_pepperSeed_count;
                break;
            case "TomatoSeedsPack":
                seeds_quantity_max = m_tomatoSeed_count;
                break;
            case "ZucchiniSeedsPack":
                seeds_quantity_max = m_zucchiniSeed_count;
                break;
            case "PumpkinSeedsPack":
                seeds_quantity_max = m_pumpkinSeed_count;
                break;
            default:
                if (!packType.Contains("CP_CannabisSeedsPack"))
                {
                    super.EmptySeedPack(player);
                    return;
                }
                break;
        }

        seeds_quantity = Math.Round(seeds_quantity_max * GetHealth01("",""));
        Print("[DEBUG] seeds_quantity = " + seeds_quantity );

        if (seeds_quantity < 1)
        { 
            seeds_quantity = 1;
        }

        if (player)
        {
            Print("[DEBUG] Spawning seeds_quantity (" + seeds_quantity + ") onto player" );

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
