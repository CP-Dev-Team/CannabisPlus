class CfgPatches
{
	class CP_Seeds
	{
		units[]=
		{
			"CP_CannabisSeedsSkunk",
			"CP_CannabisSeedsBlue",
			"CP_CannabisSeedsKush",
			"CP_CannabisSeedsStardawg",
			"CP_CannabisSeedsFuture",
			"CP_CannabisSeedsS1",
			"CP_CannabisSeedsNomad",
			"CP_CannabisSeedsBlackFrost",
			"CP_TobaccoSeeds",
			"CP_CannabisSeedsPackSkunk",
			"CP_CannabisSeedsPackBlue",
			"CP_CannabisSeedsPackKush",
			"CP_CannabisSeedsPackStardawg",
			"CP_CannabisSeedsPackFuture",
			"CP_CannabisSeedsPackS1",
			"CP_CannabisSeedsPackNomad",
			"CP_CannabisSeedsPackBlackFrost",
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
		scope=2;
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
	};
	class CP_CannabisSeedsSkunk: CP_CannabisSeeds
	{
		displayName="#cp_skunk_cannabis_seeds0";
		descriptionShort="#cp_skunk_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisSkunk";
		};
	};
	class CP_CannabisSeedsBlue: CP_CannabisSeeds
	{
		displayName="#cp_blue_god_cannabis_seeds0";
		descriptionShort="#cp_blue_god_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisBlue";
		};
	};
	class CP_CannabisSeedsKush: CP_CannabisSeeds
	{
		displayName="#cp_purple_kush_cannabis_seeds0";
		descriptionShort="#cp_purple_kush_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisKush";
		};
	};
	class CP_CannabisSeedsStardawg: CP_CannabisSeeds
	{
		displayName="#cp_stardawg_cannabis_seeds0";
		descriptionShort="#cp_stardawg_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisStardawg";
		};
	};
	class CP_CannabisSeedsFuture: CP_CannabisSeeds
	{
		displayName="#cp_future_cannabis_seeds0";
		descriptionShort="#cp_future_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisFuture";
		};
	};
	class CP_CannabisSeedsS1: CP_CannabisSeeds
	{
		displayName="#cp_s1_cannabis_seeds0";
		descriptionShort="#cp_s1_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisS1";
		};
	};
	class CP_CannabisSeedsNomad: CP_CannabisSeeds
	{
		displayName="#cp_nomad_cannabis_seeds0";
		descriptionShort="#cp_nomad_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisNomad";
		};
	};
	class CP_CannabisSeedsBlackFrost: CP_CannabisSeeds
	{
		displayName="#cp_blackfrost_cannabis_seeds0";
		descriptionShort="#cp_blackfrost_cannabis_seeds1";
		class Horticulture
		{
			PlantType="CP_Plant_CannabisBlackFrost";
		};
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
		scope=2;
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

	class CP_CannabisSeedsPackSkunk: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_cannabis_skunk_seeds0";
		descriptionShort="#cp_packed_cannabis_skunk_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\skunk_seeds.rvmat"
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
								"CannabisPlus\seeds\data\skunk_seeds.rvmat"
							}
						},

						{
							0.69999999,

							{
								"CannabisPlus\seeds\data\skunk_seeds.rvmat"
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
	class CP_CannabisSeedsPackBlue: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_blue_god_cannabis_seeds0";
		descriptionShort="#cp_packed_blue_god_cannabis_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\blue_seeds.rvmat"
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
								"CannabisPlus\seeds\data\blue_seeds.rvmat"
							}
						},

						{
							0.69999999,

							{
								"CannabisPlus\seeds\data\blue_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsBlue";
		};
	};
	class CP_CannabisSeedsPackKush: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_purple_kush_cannabis_seeds0";
		descriptionShort="#cp_packed_purple_kush_cannabis_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_kush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\kush_seeds.rvmat"
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
								"CannabisPlus\seeds\data\kush_seeds.rvmat"
							}
						},

						{
							0.69999999,

							{
								"CannabisPlus\seeds\data\kush_seeds.rvmat"
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
			ContainsSeedsType="CP_CannabisSeedsKush";
		};
	};
	class CP_CannabisSeedsPackStardawg: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_cannabis_stardawg_seeds0";
		descriptionShort="#cp_packed_cannabis_stardawg_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\stardawg_seeds.rvmat"
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
								"CannabisPlus\seeds\data\stardawg_seeds.rvmat"
							}
						},

						{
							0.69999999,

							{
								"CannabisPlus\seeds\data\stardawg_seeds.rvmat"
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
	class CP_CannabisSeedsPackFuture: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_cannabis_future_seeds0";
		descriptionShort="#cp_packed_cannabis_future_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_Future_co.paa"
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
	class CP_CannabisSeedsPackS1: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_s1_hemp_seeds0";
		descriptionShort="#cp_packed_s1_hemp_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_s1_co.paa"
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
	class CP_CannabisSeedsPackNomad: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_cannabis_nomad0";
		descriptionShort="#cp_packed_cannabis_nomad1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_nomad_co.paa"
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
	class CP_CannabisSeedsPackBlackFrost: CP_CannabisSeedsPack
	{
		displayName="#cp_packed_cannabis_blackfrost_seeds0";
		descriptionShort="#cp_packed_cannabis_blackfrost_seeds1";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_blackfrost_co.paa"
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
};
