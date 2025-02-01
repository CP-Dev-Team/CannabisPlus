class CfgPatches
{
    class CannabixPlus_Boxes
    {
        units[] =
        {
            "CP_MediumBox",
            "CP_SmallBox"
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
    class CP_MediumBox : Inventory_Base
    {
		scope = 2;
		displayName="#cp_medium_box0";
		descriptionShort="#cp_medium_box1";
		model="\CannabisPlus\boxes\box_medium.p3d";
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
	};	

      class CP_SmallBox : Inventory_Base
    {
		scope = 2;
		displayName="#cp_small_box0";
		descriptionShort="#cp_small_box1";
		model="\CannabisPlus\boxes\box_small.p3d";
		weight=250;
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
	};
};