class CfgPatches
{
	class CannabisPlus_Cigarette
	{
		units[]=
		{
			"CP_Cigarette"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CP_Cigarette: Inventory_Base
	{
		scope=2;
		displayName="#cp_cigarette0";
		descriptionShort="#cp_cigarette1";
		model="\CannabisPlus\cigarettes\cigarettes_unlit.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettes\data\cigarettes_unlit_co.paa"
		};
	};
};
