class CfgPatches
{
	class CannabisPlus_Joint
	{
		units[]=
		{};
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
	class CP_JointBase: Inventory_Base
	{
		scope=2;
		displayName="Skunk Joint";
		descriptionShort="A joint made out of finest Skunk weed";
		model="\CannabisPlus\joints\joint_new.p3d";
		inventorySlot="Ingredient";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		cpPackJoint="CP_CigarettePack_Empty";
		cpCheckJoint="";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	}
	class CP_JointSkunk: CP_JointBase
	{
		scope=2;
		displayName="Skunk Joint";
		descriptionShort="A joint made out of finest Skunk weed";
		cpPackJoint="CP_CigarettePack_CannabisSkunk";
		cpCheckJoint="CP_JointSkunk";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointBlue: CP_JointBase
	{
		scope=2;
		displayName="Blue God Joint";
		descriptionShort="A joint made out of finest Blue God weed";
		cpPackJoint="CP_CigarettePack_CannabisBlue";
		cpCheckJoint="CP_JointBlue";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointKush: CP_JointBase
	{
		scope=2;
		displayName="Purple Kush Joint";
		descriptionShort="A joint made out of finest Purple Kush weed";
		cpPackJoint="CP_CigarettePack_CannabisKush";
		cpCheckJoint="CP_JointKush";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointStardawg: CP_JointBase
	{
		scope=2;
		displayName="Stardawg Joint";
		descriptionShort="A joint made out of finest Stardawg weed";
		cpPackJoint="CP_CigarettePack_CannabisStardawg";
		cpCheckJoint="CP_JointStardawg";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointFuture: CP_JointBase
	{
		scope=2;
		displayName="Future Joint";
		descriptionShort="A joint made out of finest Future weed";
		cpPackJoint="CP_CigarettePack_CannabisFuture";
		cpCheckJoint="CP_JointFuture";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointS1: CP_JointBase
	{
		scope=2;
		displayName="S1 Joint";
		descriptionShort="A joint made out of the finest S1 hemp.  Sponsored by StevesGoods.com";
		cpPackJoint="CP_CigarettePack_CannabisS1";
		cpCheckJoint="CP_JointS1";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointNomad: CP_JointBase
	{
		scope=2;
		displayName="Nomad Joint";
		descriptionShort="A joint made out of finest Nomad weed";
		cpPackJoint="CP_CigarettePack_CannabisNomad";
		cpCheckJoint="CP_JointNomad";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
	class CP_JointBlackFrost: CP_JointBase
	{
		scope=2;
		displayName="BlackFrost Joint";
		descriptionShort="A joint made out of finest BlackFrost weed";
		cpPackJoint="CP_CigarettePack_CannabisBlackFrost";
		cpCheckJoint="CP_JointBlackFrost";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\Joint_New.paa"
		};
	};
};
