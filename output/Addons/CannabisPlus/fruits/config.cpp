class CfgPatches
{
	class CP_Fruits
	{
		units[]={};
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
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Future_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Future_co.paa"
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
			"CannabisPlus\fruits\data\cannabis_seedman_baked_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_S1_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_S1_co.paa"
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
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_Nomad_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_Nomad_co.paa"
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
			"CannabisPlus\fruits\data\cannabis_seedman_baked_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_BlackFrost_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_BlackFrost_co.paa"
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

/*  
	class CannabisAcapulco: Edible_Base
	{
		scope=2;
		displayName="Acapulco Gold";
		descriptionShort="Some cannabis bud.  Acapulco Gold variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_acapulco_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_acapulco_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_acapulco_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_acapulco_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_acapulco_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
	class CannabisCookies: Edible_Base
	{
		scope=2;
		displayName="Cookies";
		descriptionShort="Some cannabis bud.  Cookies variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_cookies_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_cookies_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_cookies_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_cookies_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_cookies_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
	class CannabisAfghani: Edible_Base
	{
		scope=2;
		displayName="Afghani";
		descriptionShort="Some cannabis bud.  Afghani variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_afghani_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_afghani_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_afghani_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_afghani_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_afghani_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
	class CannabisBlueberry: Edible_Base
	{
		scope=2;
		displayName="Blueberry";
		descriptionShort="Some cannabis bud.  Blueberry variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blueberry_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_blueberry_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blueberry_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_blueberry_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_blueberry_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
	class CannabisDurban: Edible_Base
	{
		scope=2;
		displayName="Durban Poison";
		descriptionShort="Some cannabis bud.  Durban Poison variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_durban_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_durban_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_durban_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_durban_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_durban_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
	class CannabisOGkush: Edible_Base
	{
		scope=2;
		displayName="OG Kush";
		descriptionShort="Some cannabis bud.  OG Kush variety.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_ogkush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_ogkush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_ogkush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_raw_ogkush_co.paa",
			"CannabisPlus\fruits\data\cannabis_seedman_baked_ogkush_co.paa"
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
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,284,293,30,1};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={1,100,293,10,1,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={1,69,172,70,1};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={1,20,40,10,1};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
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
*/

	class CP_Tobacco: Inventory_Base
	{
		scope=2;
		displayName="Tobaccoleaf";
		descriptionShort="A Tobaccoleaf for rolling Cigarettes";
		model="CannabisPlus\fruits\tobacco.p3d";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
	};

};
