class CfgPatches
{
	class CP_PurpleKush
	{
		units[]=
		{
			"CP_CannabisSeedsPurpleKush",
			"CP_CannabisSeedsPackPurpleKush",
			"CP_Plant_CannabisPurpleKush",
			"CP_JointPurpleKush",
			"CP_CannabisBagPurpleKush",
			"CP_CannabisBrickPurpleKush",
			"CP_CannabisPurpleKush",
			"CP_JointPack_PurpleKush"
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
		class CP_Plant_CannabisPurpleKush
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa";
			healthyMat="CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsPurpleKush: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_purplekush_cannabis_seeds0";
		descriptionShort="#cp_purplekush_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisPurpleKush";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackPurpleKush: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_purplekush_seeds0";
		descriptionShort="#cp_packed_cannabis_purplekush_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_seeds_pack_purplekush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\purplekush_seeds.rvmat"
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
								"CannabisPlus\seeds\data\purplekush_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\seeds\data\purplekush_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsPurpleKush";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisPurpleKush: PlantBase
	{
		scope=1;
		displayName="#cp_purplekush_plant0";
		descriptionShort="#cp_purplekush_plant1";
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
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat",
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawPurpleKushCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawPurpleKushCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_purplekush_plant0";
		descriptionShort="#cp_raw_purplekush_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_plant_purplekush.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointPurpleKush: CP_JointBase
	{
		scope=2;
		displayName="#cp_purplekush_joint0";
		descriptionShort="#cp_purplekush_joint1";
		cpPackJoint="CP_JointPack_PurpleKush";
		cpCheckJoint="CP_JointPurpleKush";
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
	class CP_CannabisBagPurpleKush: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_purplekush_weed_bag0";
		descriptionShort="#cp_purplekush_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickPurpleKush";
		cpStepDownToBud="CP_CannabisPurpleKush";
		class Resources
		{
			class CP_CannabisPurpleKush
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
			"CannabisPlus\strains\purplekush\data\cannabis_bag_purplekush_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickPurpleKush: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_purplekush_weed_brick0";
		descriptionShort="#cp_purplekush_weed_brick1";
		cpStepDownToBag="CP_CannabisBagPurpleKush";
		class Resources
		{
			class CP_CannabisBagPurpleKush
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_seeds_pack_purplekush_co.paa",
			"AgricultureCore\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\purplekush\data\purplekush_seeds.rvmat",
			"AgricultureCore\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisPurpleKush: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_purplekush_bud0";
		descriptionShort="#cp_purplekush_bud1";
		cpStepUpToBag="CP_CannabisBagPurpleKush";
		cpStepUpToJoint="CP_JointPurpleKush";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\purplekush\data\cannabis_seedman_raw_purplekush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_PurpleKush: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_joints_purplekush0";
		descriptionShort="#cp_marijuana_joints_purplekush1";
		cpCheckPack="CP_JointPurpleKush";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\purplekush\data\pack_of_cigs_cannabis_purplekush_co.paa",
			"CannabisPlus\strains\purplekush\data\pack_of_cigs_cannabis_purplekush_co.paa"
		};
	};
};
