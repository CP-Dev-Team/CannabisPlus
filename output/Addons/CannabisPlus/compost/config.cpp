class CfgPatches
{
    class CP_Composter
    {
        units[] =
        {
            ""
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data"
        };
    };
};

class CfgVehicles
{
    class Inventory_Base;
    class Container_Base;
    class CP_Composter : Container_Base
    {
            scope = 2;
		displayName = "Compost Bin";
		descriptionShort = "A bin for converting plant material into compost for fertilizer.";
		model="\CannabisPlus\compost\compost_bin2.p3d";
		weight=20000;
		itemSize[]={9,9};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
            varStackMax=1;
            //inventorySlot[]={};
            physLayer="item_heavy";
		itemsCargoSize[] = {10,14};
            hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\compost\data\LP_Crate_diffuse.tga.paa"
		};
            class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="woodenlog_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodenlog_drop_SoundSet";
					id=898;
				};
			};
		};
    };
};