class CfgPatches
{
	class CP_Rollingpaper
	{
		units[]=
		{
			"CP_RollingPapers"
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
	class CP_RollingPapers: Inventory_Base
	{
		scope=2;
		displayName="Fizla Rolling Papers";
		descriptionShort="A pack of Fizla Original rolling papers";
		model="CannabisPlus\rolling\CPlus_Papers.p3d";
		rotationFlags=17;
		canBeSplit=0;
		weight=20;
		itemSize[]={2,1};
		absorbency=0.2;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		quantityBar=1;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\rolling\data\CP_fizla_Original_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\rolling\data\fizla.rvmat"
		};
	};
	class CP_RollingPapers_Green: CP_RollingPapers
	{
		scope=2;
		descriptionShort="A pack of Fizla Slimline rolling papers";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\rolling\data\CP_fizla_Slimline_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\rolling\data\fizla.rvmat"
		};
	};
	class CP_RollingPapers_Silver: CP_RollingPapers
	{
		scope=2;
		descriptionShort="A pack of Fizla Super Thin rolling papers";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\rolling\data\CP_fizla_SuperThin_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\rolling\data\fizla.rvmat"
		};
	};
};
