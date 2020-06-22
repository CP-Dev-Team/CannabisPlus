class CfgPatches
{
	class CannabisPlus_Joint
	{
		units[]={};
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
	class Inventory_Base;
	class CP_JointSkunk : Inventory_Base
	{
		scope=2;
		displayName="Skunk Joint";
		descriptionShort="A joint made out of finest Skunk weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
	};

	class CP_JointBlue: Inventory_Base
	{
		scope=2;
		displayName="Blue God Joint";
		descriptionShort="A joint made out of finest Blue God weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
	};

	class CP_JointKush: Inventory_Base
	{
		scope=2;
		displayName="Purple Kush Joint";
		descriptionShort="A joint made out of finest Purple Kush weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
	};

	class CP_JointStardawg: Inventory_Base
	{
		scope=2;
		displayName="Stardawg Joint";
		descriptionShort="A joint made out of finest Stardawg weed";
		model="\CannabisPlus\joints\joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_ca.paa"
		};
	};	
};
