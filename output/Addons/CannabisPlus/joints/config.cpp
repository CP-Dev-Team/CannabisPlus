class CfgPatches
{
	class CannabisPlus_Joint
	{
		units[]=
		{
			"CP_JointSkunk",
			"CP_JointBlue",
			"CP_JointKush",
			"CP_JointStardawg",
			"CP_JointFuture",
			"CP_JointS1",
			"CP_JointNomad",
			"CP_JointBlackFrost"
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
	class Inventory_Base;
	class CP_Joint_Base: Inventory_Base
	{
		scope=0;
		displayName="A Joint";
		descriptionShort="Have a puff and see!";
		model="CannabisPlus\joints\CP_joint.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_co.paa"
		};
	};
	class CP_JointSkunk: CP_Joint_Base
	{
		scope=2;
		displayName="Skunk Joint";
		descriptionShort="A joint made out of finest Skunk weed";
	};
	class CP_JointBlue: CP_Joint_Base
	{
		scope=2;
		displayName="Blue God Joint";
		descriptionShort="A joint made out of finest Blue God weed";
	};
	class CP_JointKush: CP_Joint_Base
	{
		scope=2;
		displayName="Purple Kush Joint";
		descriptionShort="A joint made out of finest Purple Kush weed";
	};
	class CP_JointStardawg: CP_Joint_Base
	{
		scope=2;
		displayName="Stardawg Joint";
		descriptionShort="A joint made out of finest Stardawg weed";
	};
	class CP_JointFuture: CP_Joint_Base
	{
		scope=2;
		displayName="Future Joint";
		descriptionShort="A joint made out of finest Future weed";
	};
	class CP_JointS1: CP_Joint_Base
	{
		scope=2;
		displayName="S1 Joint";
		descriptionShort="A joint made out of the finest S1 hemp.  Sponsored by StevesGoods.com";
	};
	class CP_JointNomad: CP_Joint_Base
	{
		scope=2;
		displayName="Nomad Joint";
		descriptionShort="A joint made out of finest Nomad weed";
	};
	class CP_JointBlackFrost: CP_Joint_Base
	{
		scope=2;
		displayName="BlackFrost Joint";
		descriptionShort="A joint made out of finest BlackFrost weed";
	};
};
