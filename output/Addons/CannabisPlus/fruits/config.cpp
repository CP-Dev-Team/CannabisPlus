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
	class Edible_Base;
	class FoodAnimationSources;
	class FruitStageTransitions;
	class CannabisSkunk: Edible_Base
	{
		scope=2;
		displayName="Cannabis";
		descriptionShort="Some cannabis bud. Skunk variety";
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
	
	class CannabisBlue: Edible_Base
	{
		scope=2;
		displayName="Blue God";
		descriptionShort="Some cannabis bud.  Blue God variety.";
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
	class CannabisKush: Edible_Base
	{
		scope=2;
		displayName="Purple Kush";
		descriptionShort="Some cannabis bud.  Purple Kush variety.";
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
	class Tobacco: Edible_Base
	{
		scope=2;
		displayName="Tobaccoleaf";
		descriptionShort="A Tobaccoleaf for rolling Cigarettes";
		model="CannabisPlus\fruits\tobacco.p3d";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=30;
		varQuantityMin=0;
		varQuantityMax=30;
		quantityBar=1;
		inventorySlot="Ingredient";
		containsSeedsType="";
		containsSeedsQuantity="0";
	};
};
