class CfgPatches
{
    class CP_PlasticWrapper
    {
        units[] =
        {
            ""
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data",
			"DZ_Scripts"
        };
    };
};
class CfgSlots
{ 
    class Slot_CP_Cannabus_Buds
    {
          name="CP_Cannabus_Buds";
          displayName="Buds Storage";
          ghostIcon="set:dayz_inventory image:plant";
    };
	class Slot_CP_Cannabus_Bricks
    {
          name="CP_Cannabus_Bricks";
          displayName="Bricks Storage";
          ghostIcon="set:dayz_inventory image:plant";
    };
    class Slot_CP_PlasticRoll
    {
          name="CP_PlasticRoll";
          displayName="Roll";
          ghostIcon="missing";
    };
};
//class CfgNonAIVehicles
//{
//    class ProxyAttachment;
//	class ProxyPlasticWrapper : ProxyAttachment
//    {
//		scope = 2;
//		inventorySlot="Wrapper";
//		model="CannabisPlus\plasticWrapper\PlasticWrapper.p3d";
//    };
//	class ProxyVacuumSealer : ProxyAttachment
//    {
//		inventorySlot="Bagger";
//		model="CannabisPlus\plasticWrapper\VacuumSealer.p3d";
//    };
//};  
class CfgVehicles
{
    class Inventory_Base;
    class CP_PlasticWrapper : Inventory_Base
    {
		scope = 2;
		displayName = "Shrink Wrapper";
		descriptionShort = "A shrink wrapper for wrapping your favourite sandwiches.. and perhaps other things.";
		model="\CannabisPlus\plasticWrapper\plasticWrapper.p3d";
		weight=200;
		itemSize[]={4,4};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varStackMax=1;
		inventorySlot[]=
		{
			"Wrapper"
		};
		attachments[]=
		{
			"CP_PlasticRoll",
			"CP_Cannabus_Buds",
			"CP_Cannabus_Bricks"
		};
		physLayer="item_small";
		hiddenSelections[]=
		{
			"plasticWrapper"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plasticWrapper\data\PlasticWrapper_co.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.85;
			energyStorageMax=0;
			isPassiveDevice=1;
			plugType=2;
			attachmentAction=1;
		};		
	};
	
};