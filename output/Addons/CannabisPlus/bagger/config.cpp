class CfgPatches
{
    class CP_Bagger
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
    class CP_Bagger : Inventory_Base
    {
        scope = 2;
		displayName = "#cp_vacuum_bagger0";
		descriptionShort = "cp_vacuum_bagger1";
		model="CannabisPlus\bagger\VacuumSealer.p3d";
		weight=200;
		itemSize[]={4,2};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varStackMax=1;
		inventorySlot[]=
		{
			"Bagger"
		};
/*		physLayer="item_small";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\boxes\data\Caja_Color.paa"
		};
*/	};	
};