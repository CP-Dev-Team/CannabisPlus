class CfgPatches
{
    class CP_Wrapper
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
    class CP_Wrapper : Container_Base
    {
        scope = 2;
		displayName = "Shrink Wrapper";
		descriptionShort = "A shrink wrapper for packaging of illicit drugs.";
		model="\CannabisPlus\boxes\box_medium.p3d";
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