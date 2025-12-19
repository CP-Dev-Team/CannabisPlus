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
		scope=0;
		displayName="#cp_joint_base0";
		descriptionShort="#cp_joint_base1";
		model="\CannabisPlus\joints\CP_joint.p3d";
		inventorySlot[]={"CP_Joint_Base"};
		rotationFlags=16;
		weight=30;
		itemSize[]={1,1};
		cpPackJoint="CP_CigarettePack_Empty";
		cpCheckJoint="";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\joints\data\joint_co.paa"
		};
	};
};
