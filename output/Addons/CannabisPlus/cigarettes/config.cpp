class CfgPatches
{
	class CannabisPlus_Cigarette
	{
		units[]={};
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
	class CP_Cigarette: Inventory_Base
	{
		scope=2;
		displayName="Cigarette";
		descriptionShort="A Cigarette made out of good Tobacco";
		model="\CannabisPlus\cigarettes\cigarettes_unlit.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
	};
};
