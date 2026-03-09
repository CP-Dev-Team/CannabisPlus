class CfgPatches
{
	class CP_Nomad
	{
		units[]=
		{
			"CP_CannabisSeedsNomad",
			"CP_CannabisSeedsPackNomad",
			"CP_Plant_CannabisNomad",
			"CP_JointNomad",
			"CP_CannabisBagNomad",
			"CP_CannabisBrickNomad",
			"CP_CannabisNomad",
			"CP_JointPack_Nomad"
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
			"CP_Cigarettepacks",
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
		class CP_Plant_CannabisNomad
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa";
			healthyMat="CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat";
		};
	};
};

class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;

	class CP_CannabisSeeds;
	class CP_CannabisSeedsNomad: CP_CannabisSeeds
	{
		scope=2;
		displayName="#cp_nomad_cannabis_seeds0";
		descriptionShort="#cp_nomad_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisNomad";
		};
	};
	class CP_CannabisSeedsPack;
	class CP_CannabisSeedsPackNomad: CP_CannabisSeedsPack
	{
		scope=2;
		displayName="#cp_packed_cannabis_nomad_seeds0";
		descriptionShort="#cp_packed_cannabis_nomad_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_seeds_pack_nomad_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\nomad_seeds.rvmat"
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
								"CannabisPlus\seeds\data\nomad_seeds.rvmat"
							}
						},
						{
							0.69999999,
							{
								"CannabisPlus\seeds\data\nomad_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsNomad";
		};
	};
	class PlantBase;
	class CP_Plant_CannabisNomad: PlantBase
	{
		scope=1;
		displayName="#cp_nomad_plant0";
		descriptionShort="#cp_nomad_plant1";
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
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat",
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="CP_RawNomadCannabisPlant";
		};
	};
	class CP_RawPlantBase;
	class CP_RawNomadCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName="#cp_raw_nomad_plant0";
		descriptionShort="#cp_raw_nomad_plant1";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_plant_nomad.rvmat"
		};
	};
	class CP_JointBase;
	class CP_JointNomad: CP_JointBase
	{
		scope=2;
		displayName="#cp_nomad_joint0";
		descriptionShort="#cp_nomad_joint1";
		cpPackJoint="CP_JointPack_Nomad";
		cpCheckJoint="CP_JointNomad";
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
	class CP_CannabisBagNomad: CP_CannabisBags
	{
		scope=2;
		displayName="#cp_nomad_weed_bag0";
		descriptionShort="#cp_nomad_weed_bag1";
		cpStepUpToBrick="CP_CannabisBrickNomad";
		cpStepDownToBud="CP_CannabisNomad";
		class Resources
		{
			class CP_CannabisNomad
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
			"CannabisPlus\strains\nomad\data\cannabis_bag_nomad_co.paa"
		};
	};
	class CP_CannabisBrickBase;
	class CP_CannabisBrickNomad: CP_CannabisBrickBase
	{
		scope=2;
		displayName="#cp_nomad_weed_brick0";
		descriptionShort="#cp_nomad_weed_brick1";
		cpStepDownToBag="CP_CannabisBagNomad";
		class Resources
		{
			class CP_CannabisBagNomad
			{
				value=16;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_seeds_pack_nomad_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\strains\nomad\data\nomad_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBud;
	class CP_CannabisNomad: CP_CannabisBud
	{
		scope=2;
		displayName="#cp_nomad_bud0";
		descriptionShort="#cp_nomad_bud1";
		cpStepUpToBag="CP_CannabisBagNomad";
		cpStepUpToJoint="CP_JointNomad";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\nomad\data\cannabis_seedman_raw_nomad_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
	};
	class CP_JointPack;
	class CP_JointPack_Nomad: CP_JointPack
	{
		scope=2;
		displayName="#cp_marijuana_cigarettes_nomad0";
		descriptionShort="#cp_marijuana_cigarettes_nomad1";
		cpCheckPack="CP_JointNomad";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\strains\nomad\data\pack_of_cigs_cannabis_nomad_co.paa",
			"CannabisPlus\strains\nomad\data\pack_of_cigs_cannabis_nomad_co.paa"
		};
	};
};
