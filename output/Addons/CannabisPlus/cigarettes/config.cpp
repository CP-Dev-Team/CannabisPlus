class CfgPatches
{
	class CannabisPlus_Cigarette
	{
		units[]=
		{
			"CP_Cigarette"
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
	class Edible_Base;
	class CP_Cigarette: Edible_Base
	{
		scope=2;
		displayName="Cigarette";
		descriptionShort="A Cigarette made out of good Tobacco";
		model="\CannabisPlus\cigarettes\cigarettes_lit.p3d";
		inventorySlot="Ingredient";
		lootCategory="Crafted";
		SingleUseActions[]={509,510};
		InteractActions[]={1002,1003};
		rotationFlags=16;
		weight=30;
		itemSize[]={1,1};
		absorbency=0;
		varQuantityInit=500;
		varQuantityMin=0;
		varQuantityMax=500;
		heatIsolation=0.13;
		quantityBar=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\cigarettes\data\cigarettes_lit_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\cigarettes\data\cigarettes_lit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\cigarettes\data\cigarettes_lit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\cigarettes\data\cigarettes_lit_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\cigarettes\data\cigarettes_lit_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\cigarettes\data\cigarettes_lit_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
