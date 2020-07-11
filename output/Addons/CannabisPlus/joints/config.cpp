class CfgPatches
{
	class CannabisPlus_Joint
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_gear_tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	//deprecated cannabis classes, take out after v2 releases
	class Edible_Base;
	class PlantBase;
	class SeedBase;
	
	//deprecated
	class Cannabis: Edible_Base
	{
		displayName="Cannabis - Sell by 10/1/20!!";
		descriptionShort="Some cannabis bud.";
		weight=14;
	};
	//deprecated
	class Plant_Cannabis: PlantBase
	{
		scope=2;
		displayName="Cannabis Plant - Harvest by 10/1/20!!";
		descriptionShort="A Cannabis plant.";
	};
	//deprecated
	class CannabisSeeds: SeedBase
	{
		displayName="Cannabis Seeds - Harvest by 10/1/20!!";
		descriptionShort="A handful of cannabis seeds.";
	};
	//deprecated
	class CannabisSeedsPack: Inventory_Base
	{
		displayName="Packed Cannabis Seeds - Harvest by 10/1/20!!";
		descriptionShort="A pack of cannabis seeds.";
	};
	//deprecated
	class CannabisBag: Inventory_Base
	{
		scope=2;
		displayName="Bag of Weed - sell by 10/1/20!!";
		descriptionShort="About an ounce of weed.";
		model="\dz\gear\tools\heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag.paa"
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
								"DZ\gear\tools\data\heat_pack.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\heat_pack.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\heat_pack_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\heat_pack_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\heat_pack_destruct.rvmat"
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
	//deprecated
	class CannabisBrick: Inventory_Base
	{
		scope=2;
		displayName="Brick of Weed - Sell by 10/1/20!!";
		descriptionShort="One pound of weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick.paa"
		};
		lootCategory="Crafted";
		rotationFlags=17;
		weight=454;
		itemSize[]={3,3};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
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
	//deprecated
	class CigarettePack_ColorBase: Inventory_Base
	{
		scope=2;
		descriptionShort="A pack of cigarettes. - Removing 10/1/20!!";
		lootCategory="Crafted";
	};
	//deprecated
	class CigarettePack_Cannabis: CigarettePack_ColorBase
	{
		displayName="Marijuana Cigarettes - Removing 10/1/20!!";
		descriptionShort="A pack of marijuana cigarettes.";
		lootCategory="Crafted";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis.paa"
		};
	};
    //end of deprecated cannabis classes

	class CP_JointSkunk : Inventory_Base
	{
		scope=2;
		displayName="Skunk Joint";
		descriptionShort="A joint made out of finest Skunk weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=100;
				}
			}
		}			
	};

	class CP_JointBlue: Inventory_Base
	{
		scope=2;
		displayName="Blue God Joint";
		descriptionShort="A joint made out of finest Blue God weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=100;
				}
			}
		}
	};

	class CP_JointKush: Inventory_Base
	{
		scope=2;
		displayName="Purple Kush Joint";
		descriptionShort="A joint made out of finest Purple Kush weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=100;
				}
			}
		}
	};

	class CP_JointStardawg: Inventory_Base
	{
		scope=2;
		displayName="Stardawg Joint";
		descriptionShort="A joint made out of finest Stardawg weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=100;
				}
			}
		}
	};	
};
