// The item classes every strain uses (CannabisPlus 4). Each item carries its strain as a record (scripts:
// CP_GeneticItem.c), which also gives it its name and textures. The textures below are only the fallback;
// hidden selections must match the old per-strain classes, whose textures are reused for each strain's look.
class CfgPatches
{
	class CP_Genetics
	{
		units[]=
		{
			"CP_CannabisSeedsGenetic",
			"CP_CannabisSeedsPackGenetic",
			"CP_Plant_CannabisGenetic",
			"CP_RawGeneticCannabisPlant",
			"CP_JointGenetic",
			"CP_CannabisBagGenetic",
			"CP_CannabisBrickGenetic",
			"CP_CannabisGenetic",
			"CP_JointPack_Genetic"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Cultivation",
			"DZ_Data",
			"CP_Fruits",
			"CP_Bags",
			"CP_Bricks",
			"CP_Dry_Post",
			"CP_Seeds",
			"CP_Plants",
			"CannabisPlus_Joint"
		};
	};
};

class CfgHorticulture
{
	class Plants
	{
		class CP_Plant_CannabisGenetic
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa";
			healthyMat="CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsGenetic: CP_CannabisSeeds
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_seeds0";
		descriptionShort="#cp_gen_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisGenetic";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackGenetic: CP_CannabisSeedsPack
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_seedspack0";
		descriptionShort="#cp_gen_seedspack1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_seeds_pack_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\skunk\data\skunk_seeds.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5;
					healthLevels[]=
					{
						{1,{}},
						{0.69999999,{}},
						{0.5,{"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"}},
						{0.30000001,{"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"}},
						{0,{"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"}}
					};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType="CP_CannabisSeedsGenetic";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisGenetic: PlantBase
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_plant0";
		descriptionShort="#cp_gen_plant1";
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
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat",
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawGeneticCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawGeneticCannabisPlant: CP_RawPlantBase
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_raw0";
		descriptionShort="#cp_gen_raw1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_plant_skunk.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointGenetic: CP_JointBase
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_joint0";
		descriptionShort="#cp_gen_joint1";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_co.paa"
		};
	};
	class CP_CannabisBags;
	class CP_CannabisBagGenetic: CP_CannabisBags
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_bag0";
		descriptionShort="#cp_gen_bag1";
		class Resources
		{
			class CP_CannabisGenetic
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_bag_skunk_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickGenetic: CP_CannabisBrickBase
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_brick0";
		descriptionShort="#cp_gen_brick1";
		class Resources
		{
			class CP_CannabisBagGenetic
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"CannabisPlus\strains\skunk\data\cannabis_seeds_pack_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"AgricultureCore\bricks\data\brick.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat",
			"CannabisPlus\strains\skunk\data\skunk_seeds.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisGenetic: CP_CannabisBud
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_bud0";
		descriptionShort="#cp_gen_bud1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_seedman_raw_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_Genetic: CP_JointPack
	{
		scope=2;
		cpGenetic=1;
		displayName="#cp_gen_jointpack0";
		descriptionShort="#cp_gen_jointpack1";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\pack_of_cigs_cannabis_skunk_co.paa",
			"CannabisPlus\strains\skunk\data\pack_of_cigs_cannabis_skunk_co.paa"
		};
	};
};
