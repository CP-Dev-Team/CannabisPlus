modded class SeedPackBase
{   
    private int m_SeedCount;

    override void EmptySeedPack( PlayerBase player )
    {
        string pack_type = GetType();
        string seeds_type = "";

        g_Game.ConfigGetText( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsType", seeds_type );

        int seeds_quantity_max;
        int seeds_quantity;

        string packType = this.GetType();
        string strainName;

        if (packType.Contains("CP_CannabisSeedsPack"))
        {   
            CPDebugPrint("Seedspack type is: " + packType + ". Continuing");
            strainName = packType.Substring(20, packType.Length() - 20); // Extracts the name after "CP_CannabisSeedsPack"

            CPDebugPrint("json to lookup is: " + strainName + ". Continuing");

            if (g_CannabisStrainConfigs.Contains(strainName))
            {
                CPDebugPrint("Config contains: " + strainName + ". Continuing");

                CannabisStrainConfig config = g_CannabisStrainConfigs.Get(strainName);
                m_SeedCount = config.SeedCount;
                seeds_quantity_max = m_SeedCount;

                CPDebugPrint("Loaded strain config for: " + strainName + " | SeedCount: " + m_SeedCount + " | seeds_quantity_max: " + seeds_quantity_max );
            }
            else
            {
                CPDebugPrint("Warning: Strain config for '" + strainName + "' not found. Using default values.");
                CannabisStrainConfig defaultConfig = CannabisStrainConfig.CreateDefault();
                m_SeedCount = defaultConfig.SeedCount;
                seeds_quantity_max = m_SeedCount;

                CPDebugPrint("Fallback default SeedCount: " + m_SeedCount);
            }
        }
        else if (packType == "PepperSeedsPack")
        {
            seeds_quantity_max = GetGPConfig().PepperSeedsPerPackage;
        }
        else if (packType == "TomatoSeedsPack")
        {
            seeds_quantity_max = GetGPConfig().TomatoSeedsPerPackage;
        }
        else if (packType == "ZucchiniSeedsPack")
        {
            seeds_quantity_max = GetGPConfig().ZucchiniSeedsPerPackage;
        }
        else if (packType == "PumpkinSeedsPack")
        {
            seeds_quantity_max = GetGPConfig().PumpkinSeedsPerPackage;
        }
        else
        {
            super.EmptySeedPack(player);
            return;
        }

        seeds_quantity = Math.Round(seeds_quantity_max * GetHealth01("",""));
        CPDebugPrint("seeds_quantity = " + seeds_quantity );

        if (seeds_quantity < 1)
        { 
            seeds_quantity = 1;
        }

        if (player)
        {
            CPDebugPrint("Spawning seeds_quantity (" + seeds_quantity + ") onto player" );

            EmptySeedsPackLambda lambda = new EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
            player.ServerReplaceItemInHandsWithNew(lambda);
        }
        else
        {
            vector pos = GetPosition();
            g_Game.CreateObjectEx(seeds_type, pos, ECE_PLACE_ON_SURFACE);
            g_Game.ObjectDelete(this);
        }
    }
}
