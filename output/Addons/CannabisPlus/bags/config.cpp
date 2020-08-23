class CfgPatches
{
	class CP_Bags
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class CP_CannabisBagSkunk: Inventory_Base
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

	class CP_CannabisBagBlue: Inventory_Base
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
	
	//old - Remove in V3
	class CannabisBagBlue: CP_CannabisBagBlue{};

	class CP_CannabisBagKush: Inventory_Base
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
	
	//old - Remove in V3
	class CannabisBagKush: CP_CannabisBagKush {};

	class CP_CannabisBagStardawg: Inventory_Base
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

	/* Future */
	class CP_CannabisBagFuture: Inventory_Base
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

	/* S1 */
	class CP_CannabisBagS1: Inventory_Base
	{
		scope=2;
		displayName="Bag of S1 Weed";
		descriptionShort="About an ounce of S1 weed.";
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

	/* Nomad */
	class CP_CannabisBagNomad: Inventory_Base
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

	/* Black Frost */
	class CP_CannabisBagBlackFrost: Inventory_Base
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
