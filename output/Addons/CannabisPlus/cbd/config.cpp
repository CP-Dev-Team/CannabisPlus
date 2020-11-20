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
	class Inventory_Base;
	class CP_Relief_Balm : Inventory_Base
	{
		scope=2;
		displayName="CBD Relief Balm";
		descriptionShort=
		"What if I told you that pain relief is just a swipe away? This revolutionary full spectrum salve holds the key to relieving pain with ease. Rub it on your knees after an epic day of hiking, apply it to your wrists after a long day of typing, or massage it into the back of your neck when dealing with headaches!";
		model="\dz\gear\food\Marmalade.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cbd\data\relief_balm_ca.paa"
		};
		weight=60;
		isMeleeWeapon=1;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		quantityBar=1;
		varQuantityDestroyOnMin=1;
		rotationFlags=17;
		absorbency=0.89999998;
		itemSize[]={2,2};
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
								"CannabisPlus\cbd\data\relief_balm.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\cbd\data\relief_balm.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\marmalade_jar_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\marmalade_jar_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\marmalade_jar_destruct.rvmat"
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
					soundSet="Marmalade_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
}