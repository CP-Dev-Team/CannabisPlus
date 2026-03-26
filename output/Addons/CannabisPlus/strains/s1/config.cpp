class CfgPatches
{
	class CP_S1
	{
		units[]=
		{
			"CP_CannabisSeedsS1",
			"CP_CannabisSeedsPackS1",
			"CP_Plant_CannabisS1",
			"CP_JointS1",
			"CP_CannabisBagS1",
			"CP_CannabisBrickS1",
			"CP_CannabisS1",
			"CP_JointPack_S1"
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
		class CP_Plant_CannabisS1
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa";
			healthyMat="CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsS1: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_s1_cannabis_seeds0";
		descriptionShort="#cp_s1_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisS1";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackS1: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_s1_seeds0";
		descriptionShort="#cp_packed_cannabis_s1_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\s1\data\cannabis_seeds_pack_s1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\s1_seeds.rvmat"
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
								"CannabisPlus\seeds\data\s1_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\seeds\data\s1_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsS1";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisS1: PlantBase
	{
		scope=1;
		displayName="#cp_s1_plant0";
		descriptionShort="#cp_s1_plant1";
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
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat",
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawS1CannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawS1CannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_s1_plant0";
		descriptionShort="#cp_raw_s1_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\s1\data\cannabis_plant_s1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\s1\data\cannabis_plant_s1.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointS1: CP_JointBase
	{
		scope=2;
		displayName="#cp_s1_joint0";
		descriptionShort="#cp_s1_joint1";
		cpPackJoint="CP_JointPack_S1";
		cpCheckJoint="CP_JointS1";
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
	class CP_CannabisBagS1: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_s1_weed_bag0";
		descriptionShort="#cp_s1_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickS1";
		cpStepDownToBud="CP_CannabisS1";
		class Resources
		{
			class CP_CannabisS1
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
			"CannabisPlus\strains\s1\data\cannabis_bag_s1_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickS1: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_s1_weed_brick0";
		descriptionShort="#cp_s1_weed_brick1";
		cpStepDownToBag="CP_CannabisBagS1";
		class Resources
		{
			class CP_CannabisBagS1
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"CannabisPlus\strains\s1\data\cannabis_seeds_pack_s1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"AgricultureCore\bricks\data\brick.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat",
			"CannabisPlus\strains\s1\data\s1_seeds.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisS1: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_s1_bud0";
		descriptionShort="#cp_s1_bud1";
		cpStepUpToBag="CP_CannabisBagS1";
		cpStepUpToJoint="CP_JointS1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\s1\data\cannabis_seedman_raw_s1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_S1: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_joints_s10";
		descriptionShort="#cp_marijuana_joints_s11";
		cpCheckPack="CP_JointS1";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\s1\data\pack_of_cigs_cannabis_s1_co.paa",
			"CannabisPlus\strains\s1\data\pack_of_cigs_cannabis_s1_co.paa"
		};
	};
};
