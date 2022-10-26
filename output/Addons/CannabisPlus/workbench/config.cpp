class CfgPatches
{
    class CP_Workbench
    {
        units[]={};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data"
        };
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
	class Proxycannabis_seedman : ProxyAttachment
    {
		scope = 2;
		inventorySlot="CP_Cannabis_Buds";
		model="DZ\gear\food\cannabis_seedman.p3d";
    };
	class ProxyPlasticWrapper : ProxyAttachment
    {
		scope = 2;
		inventorySlot="Wrapper";
		model="CannabisPlus\plasticWrapper\PlasticWrapper.p3d";
    };
	class ProxyVacuumSealer : ProxyAttachment
    {
		inventorySlot="Bagger";
		model="CannabisPlus\bagger\VacuumSealer.p3d";
    };
	class ProxyCP_EmptyROll_DeleteMep3d : ProxyAttachment
	{
		inventorySlot="CP_PlasticRoll";
		model="CannabisPlus\plasticWrapper\CP_EmptyROll_DeleteMep3d.p3d";
	};
	class ProxyCP_baggy : ProxyAttachment
    {
		inventorySlot="CP_Empty_Bags";
		model="CannabisPlus\bags\CP_baggy.p3d";
    };
	class ProxyCP_Proxybaggy : ProxyAttachment
    {
		inventorySlot="CP_Cannabis_Bags";
		model="CannabisPlus\bags\Proxies\CP_Proxybaggy.p3d";
    };
	class ProxyCP_brick : ProxyAttachment
    {
		inventorySlot="CP_Cannabis_Bricks";
		model="CannabisPlus\bricks\CP_brick.p3d";
    };
	class Proxybattery_truck : ProxyAttachment
	{
		inventorySlot="LargeBattery";
		model="\dz\vehicles\parts\battery_truck.p3d";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	
	class DuctTape: Inventory_Base 
	{
		inventorySlot[] = {"DuctTapes"};
	};
	
	class CP_Workbench_Kit: Inventory_Base
	{
		scope = 2;
		displayName = "Cannabis Workbench Kit";
		descriptionShort = "A cannabis workbench kit for packaging your favourite strains.";
		model="\CannabisPlus\workbench\workbenchKit.p3d";
		itemSize[] = {5,3};
		rotationFlags = 2;
		itemBehaviour=0;
		weight = 300;
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Inventory: AnimSourceShown
			{
			};
			class Placing: AnimSourceHidden
			{
			};
		};
    };
	  
    class CP_Workbench : Inventory_Base
    {
		scope = 2;
		displayName = "Cannabis Workbench";
		descriptionShort = "A cannabis workbench for packaging your favourite strains.";
		model="\CannabisPlus\workbench\workbench.p3d";
		weight=50000;
		itemSize[]={6,6};
		itemBehaviour=0;
		physLayer="item_heavy";
		placement = "ForceSlopeOnTerrain";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\workbench\data\tisch1.paa"
		};		
		attachments[]=
		{
			"Wrapper",
			"Bagger",
			"LargeBattery",
			"CP_Empty_Bags",
			"CP_PlasticRoll",
			"CP_Cannabis_Buds",
			"CP_Cannabis_Bags",
			"CP_Cannabis_Bricks"
		};
		class GUIInventoryAttachmentsProps
		{
			class CP_Machines
			{
				name="Machines";
				description="";
				attachmentSlots[]=
				{
					"Wrapper",
					"Bagger",
					"LargeBattery"
				};
				icon="";
			};
			class CP_Bagger
			{
				name="Bagger";
				description="";
				attachmentSlots[]=
				{
					"CP_Empty_Bags",
					"CP_Cannabis_Buds"
				};
				icon="set:BuildingFortIcons image:WindowBarricade";
			};
			class CP_Wrapper
			{
				name="Wrapper";
				description="";
				attachmentSlots[]=
				{
					"CP_PlasticRoll",
					"CP_Cannabis_Bags",
					"CP_Cannabis_Bricks"
				};
				icon="set:BuildingFortIcons image:WindowBarricade";
			};
		};

	};
	
    class CP_Workbench_Holo: CP_Workbench
	{
		scope = 0;
	};	
};