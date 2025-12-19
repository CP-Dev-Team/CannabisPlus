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
		displayName="#cp_empty_cigarettespack0";
		descriptionShort="#cp_empty_cigarettespack1";
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
		scope=0;
		displayName="#cp_empty_jointspack0";
		descriptionShort="#cp_empty_jointspack1";
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
		displayName="#cp_chernamorka_cigarettes0";
		descriptionShort="#cp_chernamorka_cigarettes1";
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
		displayName="#cp_merkur_cigarettes0";
		descriptionShort="#cp_merkur_cigarettes1";
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
		displayName="#cp_partyzanka_cigarettes0";
		descriptionShort="#cp_partyzanka_cigarettes1";
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
};