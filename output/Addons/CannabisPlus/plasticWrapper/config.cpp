class CfgPatches
{
    class CP_PlasticWrapper
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
    class CP_PlasticWrapper : Inventory_Base
    {
            scope = 2;
		displayName = "Shrink Wrapper";
		descriptionShort = "A shrink wrapper for wrapping your favourite sandwiches.. and perhaps other things.";
		model="\CannabisPlus\plasticWrapper\plasticWrapper.p3d";
		weight=200;
		itemSize[]={4,4};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varStackMax=1;
		//inventorySlot[]={};
		physLayer="item_small";
		hiddenSelections[]=
		{
			"plasticWrapper"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plasticWrapper\data\PlasticWrapper_co.paa"
		};
	};	
};