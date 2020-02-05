class CfgPatches
{
	class CP_Seeds
	{
		units[]={};
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
	class CannabisSeedsSkunk: SeedBase
	{
		scope=2;
		displayName="Skunk Cannabis Seeds";
		descriptionShort="A handful of Skunk cannabis seeds.";
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_CannabisSkunk";
		};
	};
	class CannabisSeedsBlue: SeedBase
	{
		scope=2;
		displayName="Blue God Cannabis Seeds";
		descriptionShort="A handful of Blue God cannabis seeds.";
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_CannabisBlue";
		};
	};
	class CannabisSeedsKush: SeedBase
	{
		scope=2;
		displayName="Purple Kush Cannabis Seeds";
		descriptionShort="A handful of Purple Kush cannabis seeds.";
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_CannabisKush";
		};
	};
	class TobaccoSeeds: SeedBase
	{
		scope=2;
		displayName="Tobacco Seeds";
		descriptionShort="A handful of tobacco seeds.";
		model="\dz\gear\cultivation\Zucchini_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_Tobacco";
		};
	};
	class CannabisSeedsPackSkunk: Inventory_Base
	{
		scope=2;
		displayName="Packed Cannabis Skunk Seeds";
		descriptionShort="A package of Skunk cannabis seeds.";
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
			"CannabisPlus\seeds\data\cannabis_seeds_pack_skunk_co.paa"
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
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
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
			ContainsSeedsType="CannabisSeedsSkunk";
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="Empty Seeds Pack";
				displayName="A Empty Seeds Pack";
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
	class CannabisSeedsPackBlue: Inventory_Base
	{
		scope=2;
		displayName="Packed Blue God Cannabis Seeds";
		descriptionShort="A package of Blue God cannabis seeds.";
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
			"CannabisPlus\seeds\data\cannabis_seeds_pack_blue_co.paa"
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
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
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
			ContainsSeedsType="CannabisSeedsBlue";
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="Empty Seeds Pack";
				displayName="A Empty Seeds Pack";
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
	class CannabisSeedsPackKush: Inventory_Base
	{
		scope=2;
		displayName="Packed Purple Kush Cannabis Seeds";
		descriptionShort="A package of Purple Kush cannabis seeds.";
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
			"CannabisPlus\seeds\data\cannabis_seeds_pack_kush_co.paa"
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
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
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
			ContainsSeedsType="CannabisSeedsKush";
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="Empty Seeds Pack";
				displayName="A Empty Seeds Pack";
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
	class TobaccoSeedsPack: Inventory_Base
	{
		scope=2;
		displayName="Packed Tobacco Seeds";
		descriptionShort="A package of tobacco seeds.";
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
								"DZ\gear\cultivation\data\zucchini_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\zucchini_seeds.rvmat"
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
			ContainsSeedsType="TobaccoSeeds";
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="Empty Seeds Pack";
				displayName="A Empty Seeds Pack";
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
