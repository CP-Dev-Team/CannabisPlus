class CfgPatches
{
	class CP_Fruits
	{
		units[]=
		{
			"CP_CannabisSkunk",
			"CP_CannabisBlue",
			"CP_CannabisKush",
			"CP_CannabisStardawg",
			"CP_CannabisFuture",
			"CP_CannabisS1",
			"CP_CannabisNomad",
			"CP_CannabisBlackFrost",
			"CP_Tobacco"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Food"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CP_CannabisSkunk: Inventory_Base
	{
		scope=2;
		displayName="Cannabis";
		descriptionShort="Some cannabis bud. Skunk variety";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		inventorySlot[]={"DryPlant"};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="Zucchini_pickup_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class CP_CannabisBlue: Inventory_Base
	{
		scope=2;
		displayName="Blue God";
		descriptionShort="Some cannabis bud.  Blue God variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blue_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_blue_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blue_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blue_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisKush: Inventory_Base
	{
		scope=2;
		displayName="Purple Kush";
		descriptionShort="Some cannabis bud.  Purple Kush variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_kush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_kush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_kush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_kush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_kush_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisStardawg: Inventory_Base
	{
		scope=2;
		displayName="Stardawg";
		descriptionShort="Some cannabis bud.  Stardawg variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Stardawg_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Stardawg_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Stardawg_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Stardawg_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Stardawg_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisFuture: Inventory_Base
	{
		scope=2;
		displayName="Future";
		descriptionShort="Some cannabis bud.  Future variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_future_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisS1: Inventory_Base
	{
		scope=2;
		displayName="S1";
		descriptionShort="Some cannabis bud.  S1 variety.  Sponsored by StevesGoods.com";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisNomad: Inventory_Base
	{
		scope=2;
		displayName="Nomad";
		descriptionShort="Some cannabis bud.  Nomad variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_CannabisBlackFrost: Inventory_Base
	{
		scope=2;
		displayName="Black Frost";
		descriptionShort="Some cannabis bud.  Black Frost variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_baked.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_dried.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_burnt.rvmat",
			"CannabisPlus\fruits\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
	};
	class CP_Tobacco: Inventory_Base
	{
		scope=2;
		displayName="Tobacco Leaf";
		descriptionShort="Some tobacco leaves for rolling cigarettes";
		model="CannabisPlus\fruits\TobaccoLeaf.p3d";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
	};
};
