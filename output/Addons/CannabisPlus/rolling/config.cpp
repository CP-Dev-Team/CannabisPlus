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
		displayName="Rolling Papers";
		descriptionShort="A pack of old rollingpapers";
		model="CannabisPlus\rolling\RollingPaperPackage.p3d";
		rotationFlags=17;
		canBeSplit=0;
		weight=20;
		itemSize[]={1,1};
		absorbency=0.2;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		quantityBar=1;
	};
};
