class CfgPatches
{
	class CP_Stardawg
	{
		units[]=
		{
			"CP_CannabisSeedsStardawg",
			"CP_CannabisSeedsPackStardawg",
			"CP_Plant_CannabisStardawg",
			"CP_JointStardawg",
			"CP_CannabisBagStardawg",
			"CP_CannabisBrickStardawg",
			"CP_CannabisStardawg",
			"CP_JointPack_Stardawg"
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
		class CP_Plant_CannabisStardawg
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa";
			healthyMat="CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsStardawg: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_stardawg_cannabis_seeds0";
		descriptionShort="#cp_stardawg_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisStardawg";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackStardawg: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_stardawg_seeds0";
		descriptionShort="#cp_packed_cannabis_stardawg_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\stardawg\data\cannabis_seeds_pack_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\stardawg\data\stardawg_seeds.rvmat"
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
								"CannabisPlus\strains\stardawg\data\stardawg_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\strains\stardawg\data\stardawg_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsStardawg";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisStardawg: PlantBase
	{
		scope=1;
		displayName="#cp_stardawg_plant0";
		descriptionShort="#cp_stardawg_plant1";
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
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat",
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawStardawgCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawStardawgCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_stardawg_plant0";
		descriptionShort="#cp_raw_stardawg_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\stardawg\data\cannabis_plant_stardawg.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointStardawg: CP_JointBase
	{
		scope=2;
		displayName="#cp_stardawg_joint0";
		descriptionShort="#cp_stardawg_joint1";
		cpPackJoint="CP_JointPack_Stardawg";
		cpCheckJoint="CP_JointStardawg";
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
	class CP_CannabisBagStardawg: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_stardawg_weed_bag0";
		descriptionShort="#cp_stardawg_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickStardawg";
		cpStepDownToBud="CP_CannabisStardawg";
		class Resources
		{
			class CP_CannabisStardawg
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
			"CannabisPlus\strains\stardawg\data\cannabis_bag_stardawg_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickStardawg: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_stardawg_weed_brick0";
		descriptionShort="#cp_stardawg_weed_brick1";
		cpStepDownToBag="CP_CannabisBagStardawg";
		class Resources
		{
			class CP_CannabisBagStardawg
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"CannabisPlus\strains\stardawg\data\cannabis_seeds_pack_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"AgricultureCore\bricks\data\brick.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat",
			"CannabisPlus\strains\stardawg\data\stardawg_seeds.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisStardawg: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_stardawg_bud0";
		descriptionShort="#cp_stardawg_bud1";
		cpStepUpToBag="CP_CannabisBagStardawg";
		cpStepUpToJoint="CP_JointStardawg";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\stardawg\data\cannabis_seedman_raw_Stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_Stardawg: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_joints_stardawg0";
		descriptionShort="#cp_marijuana_joints_stardawg1";
		cpCheckPack="CP_JointStardawg";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\stardawg\data\pack_of_cigs_cannabis_Stardawg_co.paa",
			"CannabisPlus\strains\stardawg\data\pack_of_cigs_cannabis_Stardawg_co.paa"
		};
	};
};
