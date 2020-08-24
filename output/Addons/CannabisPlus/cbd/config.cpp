class CfgPatches
{
	class CP_CBD
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
	class Edible_Base;
	class CP_Relief_Balm: Edible_Base
	{
		scope=2;
		displayName="CBD Relief Balm";
		descriptionShort="CBD Relief Balm";
		model="\dz\gear\consumables\spraycan.p3d";
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cbd\data\relief_balm_co.paa"
		};
		rotationFlags=17;
		itemSize[]={1,3};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
//		varQuantityDestroyOnMin=1;  Should leave empty canister.
		weight=1000;
//		stackedUnit="ml";
		quantityBar=0;
		absorbency=0.69999999;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\butane_canister.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\butane_canister.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\butane_canister_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\butane_canister_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\butane_canister_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet="Tablets_open_SoundSet";
					id=201;
				};
				class Tablets_catch
				{
					soundSet="Tablets_catch_SoundSet";
					id=202;
				};
				class Tablets_close
				{
					soundSet="Tablets_close_SoundSet";
					id=203;
				};
				class pickup
				{
					soundSet="purificationtablets_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="purificationtablets_drop_SoundSet";
					id=898;
				};
			};
		};
	};
}