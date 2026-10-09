class CfgPatches
{
    class CP_Workbench
    {
        units[]={};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Vehicles_Parts",
            "AgricultureCore",
            "AC_Bench"
        };
    };
};

// The truck battery shows on the bench through vanilla's ProxyBattery_truck (slots TruckBattery + LargeBattery).
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
		inventorySlot="AC_Empty_Bags";
		model="AgricultureCore\bags\CP_baggy.p3d";
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
};
class CfgVehicles
{
	class AC_BenchBase;
	class AC_BenchKitBase;

	// Placed like a tent; the placing preview uses AgricultureCore's hologram setup.
	class CP_Workbench_Kit: AC_BenchKitBase
	{
		scope = 2;
		displayName="#cp_cannabis_workbench_kit0";
		descriptionShort="#cp_cannabis_workbench_kit1";
		model="\CannabisPlus\workbench\workbenchKit.p3d";
		acBenchType = "CP_Workbench";
		itemSize[] = {5,3};
		weight = 300;
    };

	// Runs on the AgricultureCore bench framework (recipes below, settings in CP_WorkbenchSettings).
    class CP_Workbench : AC_BenchBase
    {
		scope = 2;
		displayName="#cp_cannabis_workbench0";
		descriptionShort="#cp_cannabis_workbench1";
		model="\CannabisPlus\workbench\workbench.p3d";
		acBenchRecipeSet = "CP_Workbench";
		weight=50000;
		itemSize[]={6,6};
		itemsCargoSize[]={10,4};
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
			"AC_Empty_Bags",
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
					"AC_Empty_Bags",
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

// Workbench recipes. Amounts, time and power per batch come from CP_WorkbenchSettings (BudsPerBag,
// BagsPerBrick, PlasticWrapUsage, ProcessingSeconds, RequireBattery, PowerUsed); the numbers here are defaults.
// Both repeat while there's enough, like the old workbench. Products keep the strain of what went in.
class CfgACBenchRecipes
{
	class CP_Workbench
	{
		class CP_FillBags
		{
			displayName = "#cp_recipe_fill_bags";
			seconds = 5;
			energy = 15;
			stations[] = {"CP_Bagger"};
			inputs[] = {"CP_CannabisBud:2:same", "AC_EmptyBag:1"};
			outputs[] = {"@CP_BagFromBud:1"};
			repeat = 1;
		};
		class CP_WrapBricks
		{
			displayName = "#cp_recipe_wrap_bricks";
			seconds = 5;
			energy = 15;
			stations[] = {"CP_PlasticWrapper"};
			inputs[] = {"CP_CannabisBags:16:same", "CP_PlasticRoll:10"};
			outputs[] = {"@CP_BrickFromBag:1"};
			repeat = 1;
		};
	};
};
