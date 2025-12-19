class CfgPatches
{
	class CP_Plants
	{
		units[]=
		{
			"CP_Plant_Tobacco"
		};
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
		class CP_Plant_Tobacco
		{
			infestedTex="dz\gear\cultivation\data\zucchini_plant_insect_co.paa";
			infestedMat="";
			healthyTex="CannabisPlus\plants\data\tobacco_plant_co.paa";
			healthyMat="dz\gear\cultivation\data\zucchini_plant.rvmat";
		};
	};
};

class CfgVehicles
{
	class PlantBase;
	class CP_Plant_Tobacco: PlantBase
	{
		scope=2;
		displayName="#cp_tobacco_plant0";
		descriptionShort="#cp_tobacco_plant1";
		model="DZ\gear\cultivation\zucchini_plant.p3d";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\tobacco_plant_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\zucchini_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=5;
			CropsType="CP_Tobacco";
		};
	};

	// So that vanilla cannabis can't be spawned.
	class Plant_Cannabis: PlantBase
	{
		scope=0;
	};
};
