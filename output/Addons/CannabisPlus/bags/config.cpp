class CfgPatches
{
	class CP_Bags
	{
		units[]=
		{
			"CP_CannabisBagSkunk",
			"CP_CannabisBagBlue",
			"CP_CannabisBagKush",
			"CP_CannabisBagStardawg",
			"CP_CannabisBagFuture",
			"CP_CannabisBagS1",
			"CP_CannabisBagNomad",
			"CP_CannabisBagBlackFrost"
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
	class Inventory_Base;
	class CP_CannabisBags:Inventory_Base
	{
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		varStackMax=16;
		inventorySlot[]=
		{
			"CP_Cannabus_Bags","CP_CannabusWrapper_Bags"
		};
		cpStepUpToBrick="";
		//cpBuds="";
	};
	class CP_CannabisBagSkunk: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Skunk Weed";
		descriptionShort="About an ounce of Skunk weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;

		cpStepUpToBrick="CP_CannabisBrickSkunk";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_skunk_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagBlue: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Blue God Weed";
		descriptionShort="About an ounce of Blue God weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
<<<<<<< HEAD
		cpStepUpToBrick="CP_CannabisBrickBlue";
=======
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		cpBrick="CP_CannabisBrickBlue";
>>>>>>> parent of b9f99c4 (Full working dynamic Brick wrapping system - compliments to daemonforge)
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_blue_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagKush: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Purple Kush Weed";
		descriptionShort="About an ounce of Purple Kush weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
<<<<<<< HEAD
		cpStepUpToBrick="CP_CannabisBrickKush";
=======
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		cpBrick="CP_CannabisBrickKush";
>>>>>>> parent of b9f99c4 (Full working dynamic Brick wrapping system - compliments to daemonforge)
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_kush_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagStardawg: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Stardawg Weed";
		descriptionShort="About an ounce of Stardawg weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
<<<<<<< HEAD
		cpStepUpToBrick="CP_CannabisBrickStardawg";
=======
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		cpBrick="CP_CannabisBrickStardawg";
>>>>>>> parent of b9f99c4 (Full working dynamic Brick wrapping system - compliments to daemonforge)
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_stardawg_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagFuture: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Future Weed";
		descriptionShort="About an ounce of Future weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
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
		cpStepUpToBrick="CP_CannabisBrickFuture"
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_future_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagS1: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of S1 Hemp";
		descriptionShort="About an ounce of S1 hemp.  Sponsored by StevesGoods.com";
		model="\DZ\gear\tools\Heatpack.p3d";
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
		cpStepUpToBrick="CP_CannabisBrickS1"
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_s1_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagNomad: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Nomad Weed";
		descriptionShort="About an ounce of Nomad weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
<<<<<<< HEAD
		cpStepUpToBrick="CP_CannabisBrickNomad";
=======
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		cpBrick="CP_CannabisBrickNomad";
>>>>>>> parent of b9f99c4 (Full working dynamic Brick wrapping system - compliments to daemonforge)
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_nomad_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CP_CannabisBagBlackFrost: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Black Frost Weed";
		descriptionShort="About an ounce of black frost weed.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
<<<<<<< HEAD
		cpStepUpToBrick="CP_CannabisBrickBlackFrost"
=======
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=16;
		varQuantityDestroyOnMin=1;
		cpBrick="CP_CannabisBrickBlackFrost"
>>>>>>> parent of b9f99c4 (Full working dynamic Brick wrapping system - compliments to daemonforge)
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_blackfrost_co.paa"
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
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};
