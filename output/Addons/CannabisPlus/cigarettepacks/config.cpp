class CfgPatches
{
	class CP_Cigarettepacks
	{
		units[]=
		{
			"CP_CigarettePack_Empty",
			"CigarettePack_Chernamorka",
			"CigarettePack_Merkur",
			"CigarettePack_Partyzanka",
			"CP_CigarettePack_CannabisSkunk",
			"CP_CigarettePack_CannabisBlue",
			"CP_CigarettePack_CannabisKush",
			"CP_CigarettePack_CannabisStardawg",
			"CP_CigarettePack_CannabisFuture",
			"CP_CigarettePack_CannabisS1",
			"CP_CigarettePack_CannabisNomad",
			"CP_CigarettePack_CannabisBlackFrost"
		};
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
		varQuantityMax=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		cpCheckPack="";
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
	class CP_JointPack: Inventory_Base
	{
		scope=2;
		displayName="Empty Cigarettespack";
		descriptionShort="Looking shaby but still usable";
		model="\dz\gear\medical\cigarette_pack.p3d";
		lootCategory="Crafted";
		itemSize[]={1,1};
		weight=50;
		canBeSplit=0;
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		cpCheckPack="empty";
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
	class CigarettePack_Chernamorka: CP_CigarettePack_Empty
	{
		scope=2;
		displayName="Chernamorka Cigarettes";
		descriptionShort="A pack of finest Chernamorka Cigarettes";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
	class CigarettePack_Merkur: CP_CigarettePack_Empty
	{
		scope=2;
		displayName="Merkur Cigarettes";
		descriptionShort="A pack of finest Merkur Cigarettes";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
	class CigarettePack_Partyzanka: CP_CigarettePack_Empty
	{
		scope=2;
		displayName="Partyzanka Cigarettes";
		descriptionShort="A pack of finest Partyzanka Cigarettes";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
	class CP_CigarettePack_CannabisSkunk: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Skunk";
		descriptionShort="A pack of skunk marijuana cigarettes.";
		cpCheckPack="CP_JointSkunk";
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
	};
	class CP_CigarettePack_CannabisBlue: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Blue God";
		descriptionShort="A pack of blue god marijuana cigarettes.";
		cpCheckPack="CP_JointBlue";
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
	};
	class CP_CigarettePack_CannabisKush: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Purple Kush";
		descriptionShort="A pack of purple kush marijuana cigarettes.";
		cpCheckPack="CP_JointKush";
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
	};
	class CP_CigarettePack_CannabisStardawg: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Stardawg";
		descriptionShort="A pack of Stardawg marijuana cigarettes.";
		cpCheckPack="CP_JointStardawg";
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
	};
	class CP_CigarettePack_CannabisFuture: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Future";
		descriptionShort="A pack of Future marijuana cigarettes.";
		cpCheckPack="CP_JointFuture";
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
	};
	class CP_CigarettePack_CannabisS1: CP_JointPack
	{
		scope=2;
		displayName="Hemp Cigarettes S1";
		descriptionShort="A pack of S1 hemp cigarettes.  Sponsored by StevesGoods.com";
		cpCheckPack="CP_JointS1";
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
	};
	class CP_CigarettePack_CannabisNomad: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Nomad";
		descriptionShort="A pack of Nomad marijuana cigarettes.";
		cpCheckPack="CP_JointNomad";
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
	};
	class CP_CigarettePack_CannabisBlackFrost: CP_JointPack
	{
		scope=2;
		displayName="Marijuana Cigarettes Black Frost";
		descriptionShort="A pack of Black Frost marijuana cigarettes.";
		cpCheckPack="CP_JointBlackFrost";
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
	};
};
