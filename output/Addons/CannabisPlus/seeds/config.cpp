class CfgPatches
{
	class CP_Seeds
	{
		units[]=
		{
			"CP_TobaccoSeeds",
			"CP_TobaccoSeedsPack"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Cultivation"
		};
	};
};
class CfgVehicles
{
	class SeedBase;
	class Inventory_Base;
	class CP_CannabisSeeds : SeedBase
	{
		scope=0;
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
	};
	class CP_TobaccoSeeds: SeedBase
	{
		scope=2;
		displayName="#cp_tobacco_seeds0";
		descriptionShort="#cp_tobacco_seeds1";
		model="\dz\gear\cultivation\Zucchini_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="CP_Plant_Tobacco";
		};
	};
	class CP_CannabisSeedsPack : Inventory_Base
	{
		scope=0;
		model="\dz\gear\cultivation\zucchini_seeds_pack.p3d";
		rotationFlags=17;
		quantityBar=1;
		itemSize[]={1,1};
		weight=10;
		spawnOffset=0;
		lootCategory="Materials";
		lootTag[]=
		{
			"Farm",
			"Kitchen",
			"Forester"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="#cp_empty_seeds_pack0";
				displayName="#cp_empty_seeds_pack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};

	class CP_TobaccoSeedsPack: Inventory_Base
	{
		scope=2;
		displayName="#cp_packed_tobacco_seeds0";
		descriptionShort="#cp_packed_tobacco_seeds1";
		model="\dz\gear\cultivation\zucchini_seeds_pack.p3d";
		rotationFlags=17;
		quantityBar=1;
		itemSize[]={1,1};
		weight=10;
		spawnOffset=0;
		lootCategory="Materials";
		lootTag[]=
		{
			"Farm",
			"Kitchen",
			"Forester"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\tobacco_seeds_pack_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\tobacco_seeds.rvmat"
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
								"CannabisPlus\seeds\data\tobacco_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\seeds\data\tobacco_seeds.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cultivation\data\zucchini_seeds_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType="CP_TobaccoSeeds";
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="#cp_empty_seeds_pack0";
				displayName="#cp_empty_seeds_pack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};

	// So that vanilla cannabis doesn't show up.
	class CannabisSeeds: SeedBase
	{
		scope=0;
	};
	class CannabisSeedsPack: Inventory_Base
	{
		scope=0;
	};
};
