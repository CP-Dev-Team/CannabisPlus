class CfgPatches
{
	class CannabisPlus_Joint
	{
		units[]=
		{
			"CP_Joint"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_gear_tools"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;
	class CP_Joint: Edible_Base
	{
		scope=2;
		displayName="Joint";
		descriptionShort="A joint for smoking weed...";
		model="\CannabisPlus\joint\sherlockpipe_g.p3d";
		repairableWithKits[]={5,8};
		repairCosts[]={30,25};
		inventorySlot="Ingredient";
		lootCategory="Crafted";
		SingleUseActions[]={509,510};
		InteractActions[]={1002,1003};		
		rotationFlags=16;
		weight=30;
		itemSize[]={2,1};
		absorbency=0;
		heatIsolation=0.13;
		visibilityModifier=0.69999999;
		//hiddenSelections[]=
		//{
		//	"zbytek"
		//};
		//hiddenSelectionsTextures[]=
		//{
		//	"CannabisPlus\joint\data\tobacco_co.paa"
		//};	
	};
};
