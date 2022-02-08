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
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		isMeleeWeapon=1;
		varQuantityDestroyOnMin=1;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=25;
		varStackMax=1;
		inventorySlot[]={"CP_Cannabus_Bricks"};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_skunk_co.paa"
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
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_skunk_co.paa"
		};
	};
	class CP_CannabisBrickBlue: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Blue God Weed";
		descriptionShort="One pound of Blue God weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_blue_co.paa"
		};
	};
	class CP_CannabisBrickKush: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Purple Kush Weed";
		descriptionShort="One pound of Purple Kush weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_kush_co.paa"
		};
	};
	class CP_CannabisBrickStardawg: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Stardawg Weed";
		descriptionShort="One pound of Stardawg weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_stardawg_co.paa"
		};
	};
	class CP_CannabisBrickFuture: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Future Weed";
		descriptionShort="One pound of Future weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_future_co.paa"
		};
	};
	class CP_CannabisBrickS1: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of S1 Hemp";
		descriptionShort="One pound of S1 hemp.  Sponsored by StevesGoods.com";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_s1_co.paa"
		};
	};
	class CP_CannabisBrickNomad: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Nomad Weed";
		descriptionShort="One pound of Nomad weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_nomad_co.paa"
		};
	};
	class CP_CannabisBrickBlackFrost: CP_CannabisBrickBase
	{
		scope=2;
		displayName="Brick of Black Frost Weed";
		descriptionShort="One pound of Black Frost weed.";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_blackfrost_co.paa"
		};
	};
};
