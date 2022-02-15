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
            "DZ_Data",
			"DZ_Scripts"
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
		itemBehaviour=0;
		inventorySlot[]=
		{
			"Wrapper"
		};
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
	class CP_PlasticRoll: Inventory_Base
	{
		scope=2;
		displayName="Base base base";
		descriptionShort="Base bud";
		model="\CannabisPlus\plasticWrapper\CP_EmptyROll_DeleteMep3d.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,4};
		quantityBar=1;
		varQuantityDestroyOnMin=1;
		canBeSplit=0;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		inventorySlot[]={"CP_PlasticRoll"};
	};
	
};