class CfgPatches
{
	class CP_Future
	{
		units[]=
		{
			"CP_CannabisSeedsFuture",
			"CP_CannabisSeedsPackFuture",
			"CP_Plant_CannabisFuture",
			"CP_JointFuture",
			"CP_CannabisBagFuture",
			"CP_CannabisBrickFuture",
			"CP_CannabisFuture",
			"CP_JointPack_Future"
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
		class CP_Plant_CannabisFuture
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\future\data\cannabis_plant_future_co.paa";
			healthyMat="CannabisPlus\strains\future\data\cannabis_plant_future.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsFuture: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_future_cannabis_seeds0";
		descriptionShort="#cp_future_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisFuture";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackFuture: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_future_seeds0";
		descriptionShort="#cp_packed_cannabis_future_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\future\data\cannabis_seeds_pack_future_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\future_seeds.rvmat"
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
								"CannabisPlus\seeds\data\future_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\seeds\data\future_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsFuture";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisFuture: PlantBase
	{
		scope=1;
		displayName="#cp_future_plant0";
		descriptionShort="#cp_future_plant1";
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
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa",
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa",
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa",
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa",
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa",
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat",
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat",
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat",
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat",
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat",
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawFutureCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawFutureCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_future_plant0";
		descriptionShort="#cp_raw_future_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\future\data\cannabis_plant_future_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\future\data\cannabis_plant_future.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointFuture: CP_JointBase
	{
		scope=2;
		displayName="#cp_future_joint0";
		descriptionShort="#cp_future_joint1";
		cpPackJoint="CP_JointPack_Future";
		cpCheckJoint="CP_JointFuture";
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
	class CP_CannabisBagFuture: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_future_weed_bag0";
		descriptionShort="#cp_future_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickFuture";
		cpStepDownToBud="CP_CannabisFuture";
		class Resources
		{
			class CP_CannabisFuture
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
			"CannabisPlus\strains\future\data\cannabis_bag_future_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickFuture: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_future_weed_brick0";
		descriptionShort="#cp_future_weed_brick1";
		cpStepDownToBag="CP_CannabisBagFuture";
		class Resources
		{
			class CP_CannabisBagFuture
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\future\data\cannabis_seeds_pack_future_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\future\data\future_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisFuture: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_future_bud0";
		descriptionShort="#cp_future_bud1";
		cpStepUpToBag="CP_CannabisBagFuture";
		cpStepUpToJoint="CP_JointFuture";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\future\data\cannabis_seedman_raw_future_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_Future: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_cigarettes_future0";
		descriptionShort="#cp_marijuana_cigarettes_future1";
		cpCheckPack="CP_JointFuture";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\future\data\pack_of_cigs_cannabis_future_co.paa",
			"CannabisPlus\strains\future\data\pack_of_cigs_cannabis_future_co.paa"
		};
	};
};
