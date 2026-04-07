class CfgPatches
{
	class CP_Bags
	{
		units[]=
		{
			""
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class CP_CannabisBags:Inventory_Base
	{
		scope=0;
		displayName="#cp_base_bag0";
		descriptionShort="#cp_base_bag1";
		model="AgricultureCore\bags\CP_baggy.p3d";
		rotationFlags=17;
		canBeSplit=1;
		varQuantityInit=16;
		varQuantityMin=0;
		varQuantityMax=160;
		varQuantityDestroyOnMin=1;
		varStackMax=16;
		weight=28;
		itemSize[]={1,3};
		lootCategory="Crafted";
		hiddenSelections[]=
		{
			"zbytek"
		};
		inventorySlot[]=
		{
			"CP_Cannabis_Bags"
		};
	};
};
