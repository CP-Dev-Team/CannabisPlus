class CfgPatches
{
	class CP_BlueGod
	{
		units[]=
		{
			"CP_CannabisSeedsBlueGod",
			"CP_CannabisSeedsPackBlueGod",
			"CP_Plant_CannabisBlueGod",
			"CP_JointBlueGod",
			"CP_CannabisBagBlueGod",
			"CP_CannabisBrickBlueGod",
			"CP_CannabisBlueGod",
			"CP_JointPack_BlueGod"
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
		class CP_Plant_CannabisBlueGod
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa";
			healthyMat="CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsBlueGod: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_bluegod_cannabis_seeds0";
		descriptionShort="#cp_bluegod_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisBlueGod";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackBlueGod: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_bluegod_seeds0";
		descriptionShort="#cp_packed_cannabis_bluegod_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\bluegod\data\cannabis_seeds_pack_bluegod_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\bluegod_seeds.rvmat"
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
								"CannabisPlus\strains\bluegod\data\bluegod_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\strains\bluegod\data\bluegod_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsBlueGod";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisBlueGod: PlantBase
	{
		scope=2;
		displayName="#cp_bluegod_plant0";
		descriptionShort="#cp_bluegod_plant1";
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
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat",
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawBlueGodCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawBlueGodCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_bluegod_plant0";
		descriptionShort="#cp_raw_bluegod_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\bluegod\data\cannabis_plant_bluegod.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointBlueGod: CP_JointBase
	{
		scope=2;
		displayName="#cp_bluegod_joint0";
		descriptionShort="#cp_bluegod_joint1";
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
	class CP_CannabisBagBlueGod: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_bluegod_weed_bag0";
		descriptionShort="#cp_bluegod_weed_bag1";
		class Resources
		{
			class CP_CannabisBlueGod
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
			"CannabisPlus\strains\bluegod\data\cannabis_bag_bluegod_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickBlueGod: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_bluegod_weed_brick0";
		descriptionShort="#cp_bluegod_weed_brick1";
		class Resources
		{
			class CP_CannabisBagBlueGod
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa",
			"CannabisPlus\strains\bluegod\data\cannabis_seeds_pack_bluegod_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"AgricultureCore\bricks\data\brick.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat",
			"CannabisPlus\strains\bluegod\data\bluegod_seeds.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisBlueGod: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_bluegod_bud0";
		descriptionShort="#cp_bluegod_bud1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\bluegod\data\cannabis_seedman_raw_bluegod_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_BlueGod: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_joints_bluegod0";
		descriptionShort="#cp_marijuana_joints_bluegod1";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\bluegod\data\pack_of_cigs_cannabis_bluegod_co.paa",
			"CannabisPlus\strains\bluegod\data\pack_of_cigs_cannabis_bluegod_co.paa"
		};
	};
};
