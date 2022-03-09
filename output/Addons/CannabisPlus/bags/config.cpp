class CfgPatches
{
	class CP_Bags
	{
		units[]=
		{
			"CP_CannabisBagSkunk",
			"CP_CannabisBagBlue",
			"CP_CannabisBagKush",
			"CP_CannabisBagStardawg",
			"CP_CannabisBagFuture",
			"CP_CannabisBagS1",
			"CP_CannabisBagNomad",
			"CP_CannabisBagBlackFrost"
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

	class CP_CannabisBags:Inventory_Base
	{
		scope=1;
		displayName="base bag";
		descriptionShort="Ignore me , Ignore me";
		model="CannabisPlus\bags\CP_baggy.p3d";
		rotationFlags=17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=160;
		varQuantityDestroyOnMin=1;
		varStackMax=16;
		weight=28;
		itemSize[]={1,3};
		lootCategory="Crafted";
		hiddenSelections[]=
		{
			"zbytek"
		};
		inventorySlot[]=
		{
			"CP_Cannabus_Bags"
		};
		cpStepUpToBrick="";
		cpStepDownToBud="";
	};
	class CP_EmptyBag : Inventory_Base
	{
		scope=2;
		displayName="Empty 1oz Bag";
		descriptionShort="Empty bag that holds 1oz of an item.";
		model="CannabisPlus\bags\CP_baggy.p3d";
		rotationFlags=17;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=160;
		varQuantityDestroyOnMin=1;
		varStackMax=16;
		weight=28;
		itemSize[]={1,2};
		absorbency=0.2;
		lootCategory="Crafted";
		cpStepUpToBrick="CP_CannabisBrickSkunk";
		inventorySlot[]={"CP_Empty_Bags"};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\empty_bag_ca.paa"
		};
	};
	
	class CP_CannabisBagSkunk: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Skunk Weed";
		descriptionShort="About an ounce of Skunk weed.";
		cpStepUpToBrick="CP_CannabisBrickSkunk";
		cpStepDownToBud="CP_CannabisSkunk";
		class Resources
		{
			class CP_CannabisSkunk
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_skunk_co.paa"
		};
	};
	class CP_CannabisBagBlue: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Blue God Weed";
		descriptionShort="About an ounce of Blue God weed.";
		cpStepUpToBrick="CP_CannabisBrickBlue";
		cpStepDownToBud="CP_CannabisBlue";
		class Resources
		{
			class CP_CannabisBlue
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_blue_co.paa"
		};
	};
	class CP_CannabisBagKush: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Purple Kush Weed";
		descriptionShort="About an ounce of Purple Kush weed.";
		cpStepUpToBrick="CP_CannabisBrickKush";
		cpStepDownToBud="CP_CannabisKush";
		class Resources
		{
			class CP_CannabisKush
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_kush_co.paa"
		};
	};
	class CP_CannabisBagStardawg: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Stardawg Weed";
		descriptionShort="About an ounce of Stardawg weed.";
		cpStepUpToBrick="CP_CannabisBrickStardawg";
		cpStepDownToBud="CP_CannabisStardawg";
		class Resources
		{
			class CP_CannabisStardawg
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_stardawg_co.paa"
		};
	};
	class CP_CannabisBagFuture: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Future Weed";
		descriptionShort="About an ounce of Future weed.";
		cpStepUpToBrick="CP_CannabisBrickFuture";
		cpStepDownToBud="CP_CannabisFuture";
		class Resources
		{
			class CP_CannabisFuture
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_future_co.paa"
		};
	};
	class CP_CannabisBagS1: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of S1 Hemp";
		descriptionShort="About an ounce of S1 hemp.  Sponsored by StevesGoods.com";
		cpStepUpToBrick="CP_CannabisBrickS1";
		cpStepDownToBud="CP_CannabisS1";
		class Resources
		{
			class CP_CannabisS1
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_s1_co.paa"
		};
	};
	class CP_CannabisBagNomad: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Nomad Weed";
		descriptionShort="About an ounce of Nomad weed.";
		cpStepUpToBrick="CP_CannabisBrickNomad";
		cpStepDownToBud="CP_CannabisNomad";
		class Resources
		{
			class CP_CannabisNomad
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_nomad_co.paa"
		};
	};
	class CP_CannabisBagBlackFrost: CP_CannabisBags
	{
		scope=2;
		displayName="Bag of Black Frost Weed";
		descriptionShort="About an ounce of black frost weed.";
		cpStepUpToBrick="CP_CannabisBrickBlackFrost";
		cpStepDownToBud="CP_CannabisBlackFrost";
		class Resources
		{
			class CP_CannabisBlackFrost
			{
				value=2;
				variable="quantity";
			};
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bags\data\cannabis_bag_blackfrost_co.paa"
		};
	};
};
