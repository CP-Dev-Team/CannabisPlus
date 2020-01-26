//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CfgVehicles
{
	class Edible_Base;
    class SeedBase;
    class ZucchiniSeedsPack;
	class ZucchiniSeeds;
    class Plant_Zucchini;


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class CannabisSeeds: SeedBase
	{
		displayName="Cannabis Seeds";
		descriptionShort="A handful of cannabis seeds.";
	};


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class TobaccoSeeds: ZucchiniSeeds
	{
		scope=2;
		displayName="Tobacco Seeds";
		descriptionShort="A handful of tobacco seeds.";
		model="\dz\gear\cultivation\Zucchini_seeds.p3d";
		class Horticulture
		{
			PlantType="Plant_Tobacco";
		};
	};


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class TobaccoSeedsPack: ZucchiniSeedsPack
	{
		displayName="Packed Tobacco Seeds";
		descriptionShort="A package of tobacco seeds.";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\tobacco\data\tobacco_seeds_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\gear\cultivation\data\zucchini_seeds.rvmat",
			"DZ\gear\cultivation\data\zucchini_seeds.rvmat",
			"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat",
			"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat",
			"DZ\gear\cultivation\data\zucchini_seeds_destruct.rvmat"
		};
		class Horticulture
		{
			ContainsSeedsType="TobaccoSeeds";
		};
	};


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class Plant_Tobacco: Plant_Zucchini
	{
		displayName="Tobacco Plant";
		descriptionShort="A tobacco plant.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\tobacco\data\tobacco_plant_co.paa"
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


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class Tobacco: Edible_Base
	{
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
	};
}