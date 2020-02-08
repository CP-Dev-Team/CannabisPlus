class CfgPatches
{
	class CP_Cigarettepacks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CigarettePack_ColorBase: Inventory_Base
	{
		scope=2;
		descriptionShort="A pack of cigarettes.";
		lootCategory="Crafted";
	};
	class CigarettePack_Empty: CigarettePack_ColorBase
	{
		scope=2;
		displayName="A empty Cigarettespack";
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		quantityBar=1;
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_empty_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_empty_co.paa",
			"CannabisPlus\cigarettepacks\data\pack_of_cigs_empty_co.paa"
		};
	};
	class CigarettePack_Chernamorka: CigarettePack_ColorBase
	{
		scope=2;
		displayName="Chernamorka Cigarettes";
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa"
		};
	};
	class CigarettePack_Merkur: CigarettePack_ColorBase
	{
		scope=2;
		displayName="Merkur Cigarettes";
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa"
		};
	};
	class CigarettePack_Partyzanka: CigarettePack_ColorBase
	{
		scope=2;
		displayName="Partyzanka Cigarettes";
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa",
			"DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa"
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
		SingleUseActions[]={509,510};
		InteractActions[]={1002,1003};
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
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
		class Medicine
		{
			prevention=0;
			treatment=0.89999998;
			diseaseExit=1;
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
		SingleUseActions[]={509,510};
		InteractActions[]={1002,1003};
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
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
		class Medicine
		{
			prevention=0;
			treatment=0.89999998;
			diseaseExit=1;
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
		SingleUseActions[]={509,510};
		InteractActions[]={1002,1003};
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
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
		class Medicine
		{
			prevention=0;
			treatment=0.89999998;
			diseaseExit=1;
		};
	};
};
