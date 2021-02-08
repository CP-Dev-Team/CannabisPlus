class CfgPatches
{
    class CP_DryPost
    {
        units[] =
        {
            ""
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data"
        };
    };
};
	
class CfgSlots
{ 
    class Slot_HangingPlants
    {
        name="HangingPlants";
        displayName="HangingPlants";
		selection="HangingPlants";
        ghostIcon="plant";
    };
    class Slot_HangingPlants2
    {
        name="HangingPlants2";
        displayName="HangingPlants2";
		selection="HangingPlants2";
        ghostIcon="plant";
    };
    class Slot_HangingPlants3
    {
        name="HangingPlants3";
        displayName="HangingPlants3";
		selection="HangingPlants3";
        ghostIcon="plant";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
	class ProxyHangingPlants : ProxyAttachment
    {
		inventorySlot="HangingPlants";
		model="CannabisPlus\furniture\HangingPlants.p3d";
    };
	class ProxyHangingPlants2 : ProxyAttachment
    {
		inventorySlot="HangingPlants2";
		model="CannabisPlus\furniture\HangingPlants2.p3d";
    };
	class ProxyHangingPlants3 : ProxyAttachment
    {
		inventorySlot="HangingPlants3";
		model="CannabisPlus\furniture\HangingPlants3.p3d";
    };
};

class CfgVehicles
{
    class Inventory_Base;
	class Container_Base;
    class CP_DryPost : Container_Base
    {
        scope = 2;
		displayName = "Drying Post";
		descriptionShort = "A post for drying cannabis and other plants.";
		model="\CannabisPlus\furniture\DryPost.p3d";
		weight=20000;
		itemSize[]={3,11};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
        varStackMax=1;
        inventorySlot[]={};
        physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[] = {10,4};
			openable = 1;
			allowOwnedCargoManipulation = 1;
		};
        attachments[]=
		{
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3",
			"Rope"
		};
        class GUIInventoryAttachmentsProps
        {
            class CP_DryingPost
            {
                name="Drying Post";
                description="A post for drying plants.";
                attachmentSlots[]=
                {
                    "HangingPlants",
					"HangingPlants2",
					"HangingPlants3",
					"Rope"
                };
            };
        };
		class AnimationSources
        {
            class Rope
            {
                source="user";
                initPhase=1;
                animPeriod=0.2;
            };
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\gear\camping\data\wooden_log.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\gear\camping\data\wooden_log.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\gear\camping\data\wooden_log_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\gear\camping\data\wooden_log_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\gear\camping\data\wooden_log_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="woodenlog_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodenlog_drop_SoundSet";
					id=898;
				};
			};
		};
    };

    class CP_RawSkunkCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Skunk Plant";
		descriptionShort = "A raw Skunk plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawBlueCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Blue God  Plant";
		descriptionShort = "A raw Blue God plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawKushCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Kush Plant";
		descriptionShort = "A raw Kush plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawStardawgCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Stardawg Plant";
		descriptionShort = "A raw Stardawg plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawFutureCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Future Plant";
		descriptionShort = "A raw Future plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawNomadCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Nomad Plant";
		descriptionShort = "A raw Nomad plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawS1CannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw S1 Plant";
		descriptionShort = "A raw S1 plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_RawBlackFrostCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Black Frost Plant";
		descriptionShort = "A raw Black Frost plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

	class CP_DriedCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Dried Cannabis Plant";
		descriptionShort = "A dried cannabis plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3"
        };
    };

};