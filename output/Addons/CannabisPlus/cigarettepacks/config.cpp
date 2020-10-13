class CfgPatches
{
	class CP_Cigarettepacks
	{
		units[]={};
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
	
	class CP_CigarettePack_Empty: Inventory_Base
	{
		scope=2;
		displayName="Empty Cigarettespack";
		descriptionShort="Looking shaby but still usable";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=20;	
		varQuantityDestroyOnMin=0;	
		quantityBar=1;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_empty_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_empty_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CigarettePack_Chernamorka: Inventory_Base
	{
		scope=2;
		displayName="Chernamorka Cigarettes";
		descriptionShort="A pack of finest Chernamorka Cigarettes";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CigarettePack_Merkur: Inventory_Base
	{
		scope=2;
		displayName="Merkur Cigarettes";
		descriptionShort="A pack of finest Merkur Cigarettes";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CigarettePack_Partyzanka: Inventory_Base
	{
		scope=2;
		displayName="Partyzanka Cigarettes";
		descriptionShort="A pack of finest Partyzanka Cigarettes";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class CP_CigarettePack_CannabisSkunk: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Skunk";
		descriptionShort="A pack of skunk marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_skunk_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_skunk_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class CP_CigarettePack_CannabisBlue: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Blue God";
		descriptionShort="A pack of blue god marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabisblue_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabisblue_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class CP_CigarettePack_CannabisKush: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Purple Kush";
		descriptionShort="A pack of purple kush marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabiskush_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabiskush_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class CP_CigarettePack_CannabisStardawg: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Stardawg";
		descriptionShort="A pack of Stardawg marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Stardawg_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Stardawg_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CP_CigarettePack_CannabisFuture: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Future";
		descriptionShort="A pack of Future marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Future_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Future_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CP_CigarettePack_CannabisS1: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes S1";
		descriptionShort="A pack of S1 marijuana cigarettes.  Sponsored by StevesGoods.com";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_S1_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_S1_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CP_CigarettePack_CannabisNomad: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Nomad";
		descriptionShort="A pack of Nomad marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Nomad_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_Nomad_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class CP_CigarettePack_CannabisBlackFrost: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Black Frost";
		descriptionShort="A pack of Black Frost marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=5;	
		varQuantityDestroyOnMin=1;	
		quantityBar=0;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_BlackFrost_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_cannabis_BlackFrost_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

};
