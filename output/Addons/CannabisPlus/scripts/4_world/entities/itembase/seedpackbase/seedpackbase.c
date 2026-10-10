modded class SeedPackBase
{
    override void EmptySeedPack( PlayerBase player )
    {
        string packType = GetType();
        if (!packType.Contains("CP_CannabisSeedsPack"))
        {
            super.EmptySeedPack(player);
            return;
        }

        // Every pack gives genetic seeds of its strain (old per-strain packs too).
        CP_StrainRecord record = CPGetRecord();
        string seeds_type = "CP_CannabisSeedsGenetic";

        int seeds_quantity_max = CannabisStrainConfig.CreateDefault().SeedsPerPackage;
        CannabisStrainConfig config = CPGetStrainConfig();
        if (config)
            seeds_quantity_max = config.SeedsPerPackage;
        else
            CPDebugPrint("Warning: No strain config for seed pack " + packType + ". Using default values.");

        CPDebugPrint("Emptying " + packType + " (" + CPGetStrainName() + ") | SeedsPerPackage: " + seeds_quantity_max);

        int seeds_quantity = Math.Round(seeds_quantity_max * GetHealth01("",""));
        if (seeds_quantity < 1)
            seeds_quantity = 1;

        if (player)
        {
            CP_EmptySeedsPackLambda lambda = new CP_EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
            lambda.m_Record = record;
            player.ServerReplaceItemInHandsWithNew(lambda);
        }
        else
        {
            ItemBase seeds = ItemBase.Cast(g_Game.CreateObjectEx(seeds_type, GetPosition(), ECE_PLACE_ON_SURFACE));
            if (seeds)
            {
                seeds.SetQuantity(seeds_quantity);
                seeds.CPSetRecord(record);
            }
            g_Game.ObjectDelete(this);
        }
    }
}

class CP_EmptySeedsPackLambda : EmptySeedsPackLambda
{
    ref CP_StrainRecord m_Record;

    override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
    {
        super.CopyOldPropertiesToNew(old_item, new_item);

        ItemBase seeds = ItemBase.Cast(new_item);
        if (seeds)
            seeds.CPSetRecord(m_Record);
    }
}
