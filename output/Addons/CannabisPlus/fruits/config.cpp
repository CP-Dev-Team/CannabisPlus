class CfgPatches
{
	class CP_Fruits
	{
		units[]=
		{
			"CP_Tobacco"
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
	class CP_CoreClass:Inventory_Base
	{
		scope=0;
		displayName="";
		descriptionShort="";
	};
	
	class CP_CannabisBud: Inventory_Base
	{
		scope=0;
		displayName="#cp_base_bud0";
		descriptionShort="#cp_base_bud1";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		varQuantityDestroyOnMin=1;
		canBeSplit=1;
		varQuantityInit=2;
		varQuantityMin=0;
		varQuantityMax=100;
		varStackMax=2;
		inventorySlot[]={"DryPlant","CP_Cannabis_Buds"};
		cpStepUpToBag="";
		cpStepUpToJoint="";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw_skunk_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"CannabisPlus\fruits\data\cannabis_seedman_raw.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
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

	class CP_Tobacco: Inventory_Base
	{
		scope=2;
		displayName="#cp_tobacco_leaf0";
		descriptionShort="#cp_tobacco_leaf1";
		model="CannabisPlus\fruits\TobaccoLeaf.p3d";
		cpStepUpToBag="";
		rotationFlags=17;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
	};

	// So that vanilla cannabis can't be spawned.
	class Edible_Base;
	class Cannabis: Edible_Base
	{
		scope=0;
	};

};
