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
		class CP_Plant_Tobacco
		{
			infestedTex="dz\gear\cultivation\data\zucchini_plant_insect_co.paa";
			infestedMat="";
			healthyTex="CannabisPlus\plants\data\tobacco_plant_co.paa";
			healthyMat="dz\gear\cultivation\data\zucchini_plant.rvmat";
		};
		
		//Remove in V3
		class Plant_Tobacco : CP_Plant_Tobacco{};

		class CP_Plant_CannabisSkunk
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\plants\data\cannabis_plant_skunk_co.paa";
			healthyMat="dz\gear\cultivation\data\cannabis_plant.rvmat";
		};
		
		class CP_Plant_CannabisKush
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\plants\data\cannabis_plant_kush_co.paa";
			healthyMat="dz\gear\cultivation\data\cannabis_plant.rvmat";
		};
		
		//old - Remove in V3
		class Plant_CannabisKush{};

		class CP_Plant_CannabisBlue
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\plants\data\cannabis_plant_blue_co.paa";
			healthyMat="dz\gear\cultivation\data\cannabis_plant.rvmat";
		};

		//old - Remove in V3
		class Plant_CannabisBlue{};

		class CP_Plant_CannabisStardawg
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa";
			healthyMat="dz\gear\cultivation\data\cannabis_plant.rvmat";
		};

	};
};
class CfgVehicles
{
	class PlantBase;
	class CP_Plant_CannabisSkunk: PlantBase
	{
		scope=2;
		displayName="Skunk Plant";
		descriptionShort="A Skunk plant.";
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		hiddenSelections[]=
		{
			"plantstage_03",
			"plantstage_02",
			"plantstage_04",
			"plantstage_05",
			"plantstage_01",
			"infestedparts"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CannabisSkunk";
		};
	};
	
	class CP_Plant_CannabisBlue: PlantBase
	{
		scope=2;
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		displayName="Blue God Plant";
		descriptionShort="A Blue God plant.";
		hiddenSelections[]=
		{
			"plantstage_03",
			"plantstage_02",
			"plantstage_04",
			"plantstage_05",
			"plantstage_01",
			"infestedparts"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CannabisBlue";
		};
	};
	
	//old - Remove in V3
	class Plant_CannabisBlue: CP_Plant_CannabisBlue{};

	class CP_Plant_CannabisKush: PlantBase
	{
		scope=2;
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		displayName="Purple Kush Plant";
		descriptionShort="A Purple Kush plant.";
		hiddenSelections[]=
		{
			"plantstage_03",
			"plantstage_02",
			"plantstage_04",
			"plantstage_05",
			"plantstage_01",
			"infestedparts"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CannabisKush";
		};
	};

	//old - Remove in V3
	class Plant_CannabisKush: CP_Plant_CannabisKush{};

	class CP_Plant_CannabisStardawg: PlantBase
	{
		scope=2;
		displayName="Stardawg Plant";
		descriptionShort="A Stardawg plant.";
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		hiddenSelections[]=
		{
			"plantstage_03",
			"plantstage_02",
			"plantstage_04",
			"plantstage_05",
			"plantstage_01",
			"infestedparts"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CannabisStardawg";
		};
	};

	class CP_Plant_Tobacco: PlantBase
	{	
		scope=2;
		displayName="Tobacco Plant";
		descriptionShort="A tobacco plant.";
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
			CropsType="Tobacco";
		};
	};

	//old - Remove in V3
	class Plant_Tobacco: CP_Plant_Tobacco{};
};
