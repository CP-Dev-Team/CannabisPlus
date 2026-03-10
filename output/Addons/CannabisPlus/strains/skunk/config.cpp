class CfgPatches
{
	class CP_Skunk
	{
		units[]=
		{
			"CP_CannabisSeedsSkunk",
			"CP_CannabisSeedsPackSkunk",
			"CP_Plant_CannabisSkunk",
			"CP_JointSkunk",
			"CP_CannabisBagSkunk",
			"CP_CannabisBrickSkunk",
			"CP_CannabisSkunk",
			"CP_JointPack_Skunk"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Cultivation",
			"DZ_Data",
			"CP_Fruits",
			"CP_Bags",
			"CP_Bricks",			"CP_Dry_Post",
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
		class CP_Plant_CannabisSkunk
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
	class CP_CannabisSeedsSkunk: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_skunk_cannabis_seeds0";
		descriptionShort="#cp_skunk_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisSkunk";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackSkunk: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_skunk_seeds0";
		descriptionShort="#cp_packed_cannabis_skunk_seeds1";
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
						{
							1,
							{
								"CannabisPlus\strains\skunk\data\skunk_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\strains\skunk\data\skunk_seeds.rvmat"
							}
						},
						{
							0.5,
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						{
							0.30000001,
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						{
							0,
							{
								"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType="CP_CannabisSeedsSkunk";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisSkunk: PlantBase
	{
		scope=1;
		displayName="#cp_skunk_plant0";
		descriptionShort="#cp_skunk_plant1";
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
			CropsType="CP_RawSkunkCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawSkunkCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_skunk_plant0";
		descriptionShort="#cp_raw_skunk_plant1";
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
	class CP_JointSkunk: CP_JointBase
	{
		scope=2;
		displayName="#cp_skunk_joint0";
		descriptionShort="#cp_skunk_joint1";
		cpPackJoint="CP_JointPack_Skunk";
		cpCheckJoint="CP_JointSkunk";
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
	class CP_CannabisBagSkunk: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_skunk_weed_bag0";
		descriptionShort="#cp_skunk_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickSkunk";
		cpStepDownToBud="CP_CannabisSkunk";
		class Resources
		{
			class CP_CannabisSkunk
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
	class CP_CannabisBrickSkunk: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_skunk_weed_brick0";
		descriptionShort="#cp_skunk_weed_brick1";
		cpStepDownToBag="CP_CannabisBagSkunk";
		class Resources
		{
			class CP_CannabisBagSkunk
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\skunk\data\cannabis_seeds_pack_skunk_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\skunk\data\skunk_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisSkunk: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_skunk_bud0";
		descriptionShort="#cp_skunk_bud1";
		cpStepUpToBag="CP_CannabisBagSkunk";
		cpStepUpToJoint="CP_JointSkunk";
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
	class CP_JointPack_Skunk: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_cigarettes_skunk0";
		descriptionShort="#cp_marijuana_cigarettes_skunk1";
		cpCheckPack="CP_JointSkunk";
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
