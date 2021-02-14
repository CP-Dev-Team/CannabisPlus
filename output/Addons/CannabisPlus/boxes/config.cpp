class CfgPatches
{
    class CP_Box
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
    class CP_Box : Inventory_Base
    {
            scope = 2;
		displayName = "Basic Box";
		descriptionShort = "A box for holding items.";
		model="\CannabisPlus\furniture\box.p3d";
		weight=500;
		itemSize[]={4,4};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
            varStackMax=1;
            //inventorySlot[]={};
            physLayer="item_large";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\boxes\data\Caja_Color.paa"
		};
            class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000000000;
					healthLevels[] = {{1,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.7,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.5,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0,{"DZ\gear\camping\data\spotlight_destruct.rvmat"}}};
				};
			};
		};
	};	
};