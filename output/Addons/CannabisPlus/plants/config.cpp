class CfgPatches
{
	class CP_Plants
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Cultivation"
		};
	};
};
class CfgHorticulture
{
	class Plants
	{
	};
};

class CfgVehicles
{
	class PlantBase;

	// So that vanilla cannabis can't be spawned.
	class Plant_Cannabis: PlantBase
	{
		scope=0;
	};
};
