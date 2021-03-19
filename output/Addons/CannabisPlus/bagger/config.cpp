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
    class Container_Base;
    class CP_Bagger : Container_Base
    {
        scope = 2;
		displayName = "Vacuum Bagger";
		descriptionShort = "A vacuum sealer for packaging of illicit drugs.";
		model="\CannabisPlus\boxes\box_small.p3d";
		weight=200;
		itemSize[]={2,4};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varStackMax=1;
		//inventorySlot[]={};
		physLayer="item_heavy";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\boxes\data\Caja_Color.paa"
		};
	};	
};