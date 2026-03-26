class CfgPatches
{
	class CP_Bricks
	{
		units[]=
		{
			""
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"AgricultureCore"
		};
	};
};
class CfgVehicles
{
	class AC_BrickBase;
	class CP_CannabisBrickBase: AC_BrickBase
	{
		scope=0;
		inventorySlot[]={"CP_Cannabis_Bricks"};
		cpStepDownToBag="";
	};
};
