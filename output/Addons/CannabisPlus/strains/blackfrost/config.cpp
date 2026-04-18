class CfgPatches
{
	class CP_BlackFrost
	{
		units[]=
		{
			"CP_CannabisSeedsBlackFrost",
			"CP_CannabisSeedsPackBlackFrost",
			"CP_Plant_CannabisBlackFrost",
			"CP_JointBlackFrost",
			"CP_CannabisBagBlackFrost",
			"CP_CannabisBrickBlackFrost",
			"CP_CannabisBlackFrost",
			"CP_JointPack_BlackFrost"
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
		class CP_Plant_CannabisBlackFrost
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa";
			healthyMat="CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsBlackFrost: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_blackfrost_cannabis_seeds0";
		descriptionShort="#cp_blackfrost_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisBlackFrost";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackBlackFrost: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_blackfrost_seeds0";
		descriptionShort="#cp_packed_cannabis_blackfrost_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\blackfrost\data\cannabis_seeds_pack_blackfrost_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\blackfrost_seeds.rvmat"
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
								"CannabisPlus\seeds\data\blackfrost_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\seeds\data\blackfrost_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsBlackFrost";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisBlackFrost: PlantBase
	{
		scope=2;
		displayName="#cp_blackfrost_plant0";
		descriptionShort="#cp_blackfrost_plant1";
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
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat",
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawBlackFrostCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawBlackFrostCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_blackfrost_plant0";
		descriptionShort="#cp_raw_blackfrost_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\blackfrost\data\cannabis_plant_blackfrost.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointBlackFrost: CP_JointBase
	{
		scope=2;
		displayName="#cp_blackfrost_joint0";
		descriptionShort="#cp_blackfrost_joint1";
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
	class CP_CannabisBagBlackFrost: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_blackfrost_weed_bag0";
		descriptionShort="#cp_blackfrost_weed_bag1";
		class Resources
		{
			class CP_CannabisBlackFrost
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
			"CannabisPlus\strains\blackfrost\data\cannabis_bag_blackfrost_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickBlackFrost: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_blackfrost_weed_brick0";
		descriptionShort="#cp_blackfrost_weed_brick1";
		class Resources
		{
			class CP_CannabisBagBlackFrost
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"CannabisPlus\strains\blackfrost\data\cannabis_seeds_pack_blackfrost_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"AgricultureCore\bricks\data\brick.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat",
			"CannabisPlus\strains\blackfrost\data\blackfrost_seeds.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisBlackFrost: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_blackfrost_bud0";
		descriptionShort="#cp_blackfrost_bud1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\blackfrost\data\cannabis_seedman_raw_blackfrost_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_BlackFrost: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_joints_blackfrost0";
		descriptionShort="#cp_marijuana_joints_blackfrost1";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\blackfrost\data\pack_of_cigs_cannabis_blackfrost_co.paa",
			"CannabisPlus\strains\blackfrost\data\pack_of_cigs_cannabis_blackfrost_co.paa"
		};
	};
};
