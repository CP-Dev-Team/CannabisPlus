class CfgPatches
{
	class CP_Bricks
	{
		units[]=
		{
			""
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
		scope=0;
		displayName="#cp_brick_base0";
		descriptionShort="#cp_brick_base1";
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
		inventorySlot[]={"CP_Cannabis_Bricks"};
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
};
