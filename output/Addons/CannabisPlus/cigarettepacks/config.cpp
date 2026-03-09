class CfgPatches
{
	class CP_Cigarettepacks
	{
		units[]=
		{
			"CP_CigarettePack_Chernamorka",
			"CP_CigarettePack_Merkur",
			"CP_CigarettePack_Partyzanka",
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical",
			"AgricultureCore"
		};
	};
};
class CfgVehicles
{
	class AC_CigarettePack_Empty;
	class CP_JointPack: AC_CigarettePack_Empty
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
		quantityBar=0;
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
	class CP_CigarettePack_Chernamorka: AC_CigarettePack_Empty
	{
		scope=2;
		displayName="#cp_chernamorka_cigarettes0";
		descriptionShort="#cp_chernamorka_cigarettes1";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
	class CP_CigarettePack_Merkur: AC_CigarettePack_Empty
	{
		scope=2;
		displayName="#cp_merkur_cigarettes0";
		descriptionShort="#cp_merkur_cigarettes1";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
	class CP_CigarettePack_Partyzanka: AC_CigarettePack_Empty
	{
		scope=2;
		displayName="#cp_partyzanka_cigarettes0";
		descriptionShort="#cp_partyzanka_cigarettes1";
		varQuantityInit=20;
		varQuantityMin=1;
		varQuantityMax=20;
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
	};
};