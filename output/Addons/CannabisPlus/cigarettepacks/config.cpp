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
	class CigarettePack_Empty: Inventory_Base
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
		varQuantityMax=20;	
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
		varQuantityMax=20;	
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
		varQuantityMax=20;	
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
	class CigarettePack_CannabisSkunk: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Skunk";
		descriptionShort="A pack of marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=20;	
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
	class CigarettePack_CannabisBlue: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Blue God";
		descriptionShort="A pack of marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=20;	
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
	class CigarettePack_CannabisKush: Inventory_Base
	{
		scope=2;
		displayName="Marijuana Cigarettes Purple Kush";
		descriptionShort="A pack of marijuana cigarettes.";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=20;	
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
};