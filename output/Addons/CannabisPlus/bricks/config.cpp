class CfgPatches
{
	class CP_Bricks
	{
		units[]=
		{
			"CP_CannabisBrickSkunk",
			"CP_CannabisBrickBlue",
			"CP_CannabisBrickKush",
			"CP_CannabisBrickStardawg",
			"CP_CannabisBrickFuture",
			"CP_CannabisBrickS1",
			"CP_CannabisBrickNomad",
			"CP_CannabisBrickBlackFrost"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class CP_CannabisBrickBase: Container_Base
	{
		scope=2;
		displayName="Brick Base";
		descriptionShort="Base";
		model="CannabisPlus\bricks\CP_brick.p3d";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={2,2};
		absorbency=0.2;
		isMeleeWeapon=1;
		varQuantityDestroyOnMin=1;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varStackMax=1;
		inventorySlot[]={"CP_Cannabus_Bricks"};
		cpStepDownToBag="";
		hiddenSelections[]=
		{
			"SeedPack",
			"Brick"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\cultivation\data\cannabis_seeds_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class CP_CannabisBrickSkunk: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Skunk Weed";
		descriptionShort="One pound of Skunk weed.";
		cpStepDownToBag="CP_CannabisBagSkunk";
		class Resources
		{
			class CP_CannabisBagSkunk
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_skunk_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickBlue: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Blue God Weed";
		descriptionShort="One pound of Blue God weed.";
		cpStepDownToBag="CP_CannabisBagBlue";
		class Resources
		{
			class CP_CannabisBagBlue
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_blue_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickKush: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Purple Kush Weed";
		descriptionShort="One pound of Purple Kush weed.";
		cpStepDownToBag="CP_CannabisBagKush";
		class Resources
		{
			class CP_CannabisBagKush
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_kush_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickStardawg: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Stardawg Weed";
		descriptionShort="One pound of Stardawg weed.";
		cpStepDownToBag="CP_CannabisBagStardawg";
		class Resources
		{
			class CP_CannabisStardawg
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_stardawg_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickFuture: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Future Weed";
		descriptionShort="One pound of Future weed.";
		cpStepDownToBag="CP_CannabisBagFuture";
		class Resources
		{
			class CP_CannabisBagFuture
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_Future_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickS1: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of S1 Hemp";
		descriptionShort="One pound of S1 hemp.  Sponsored by StevesGoods.com";
		cpStepDownToBag="CP_CannabisBagS1";
		class Resources
		{
			class CP_CannabisBagS1
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_s1_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickNomad: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Nomad Weed";
		descriptionShort="One pound of Nomad weed.";
		cpStepDownToBag="CP_CannabisBagNomad";
		class Resources
		{
			class CP_CannabisBagNomad
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_nomad_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
	class CP_CannabisBrickBlackFrost: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Black Frost Weed";
		descriptionShort="One pound of Black Frost weed.";
		cpStepDownToBag="CP_CannabisBagBlackFrost";
		class Resources
		{
			class CP_CannabisBagBlackFrost
			{
				value=8;
				variable="quantity";
			};
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds_pack_blackfrost_co.paa",
			"CannabisPlus\bricks\data\cannabis_brick_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\seeds\data\cannabis_seeds.rvmat",
			"CannabisPlus\bricks\data\brick.rvmat"
		};
	};
};
