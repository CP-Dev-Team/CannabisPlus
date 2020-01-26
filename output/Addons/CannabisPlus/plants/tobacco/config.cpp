class CfgPatches
{
	class CannabisPlus_Gear_Cultivation
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Food",
			"DZ_Gear_Medical",
			"DZ_Gear_Tools"
		};
	};
};

class CfgVehicles {		
	class Edible_Base;
	
	class Tobacco: Edible_Base {
		scope=2;
		displayName="Tobacco";
		descriptionShort="Some tobacco leaves.";
		model="CannabisPlus\plants\tobacco\tobacco.p3d";
		rotationFlags=16;
		lootCategory="Crafted";
		weight=0;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\tobacco\data\tobacco_co.paa"
		};
	}
}