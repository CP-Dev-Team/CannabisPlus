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
        displayName="Hanging Plants";
        ghostIcon="set:dayz_inventory image:plant";
    };
    class Slot_HangingPlants2
    {
        name="HangingPlants2";
        displayName="HangingPlants2";
		selection="HangingPlants2";
        ghostIcon="set:dayz_inventory image:plant";
    };
    class Slot_HangingPlants3
    {
        name="HangingPlants3";
        displayName="HangingPlants3";
		selection="HangingPlants3";
        ghostIcon="set:dayz_inventory image:plant";
    };
	class Slot_HangingPlants4
    {
        name="HangingPlants4";
        displayName="HangingPlants4";
		selection="HangingPlants3";
        ghostIcon="set:dayz_inventory image:plant";
    };
	class Slot_HangingPlants5
    {
        name="HangingPlants5";
        displayName="HangingPlants5";
		selection="HangingPlants3";
        ghostIcon="set:dayz_inventory image:plant";
    };
	class Slot_HangingPlants6
    {
        name="HangingPlants6";
        displayName="HangingPlants6";
		selection="HangingPlants3";
		ghostIcon="set:dayz_inventory image:plant";
    };
	class Slot_DriedPlantPile
	{
        name="DriedPlantPile";
        displayName="DriedPlantPile";
		ghostIcon="set:dayz_inventory image:plant";
		stackMax=50;
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
	class ProxyHangingPlants : ProxyAttachment
    {
		scope = 2;
		inventorySlot="HangingPlants";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
	class ProxyHangingPlants2 : ProxyAttachment
    {
		inventorySlot="HangingPlants2";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
	class ProxyHangingPlants3 : ProxyAttachment
    {
		inventorySlot="HangingPlants3";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
	
	class ProxyHangingPlants4 : ProxyAttachment
    {
		inventorySlot="HangingPlants4";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
	class ProxyHangingPlants5 : ProxyAttachment
    {
		inventorySlot="HangingPlants5";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
	class ProxyHangingPlants6 : ProxyAttachment
    {
		inventorySlot="HangingPlants6";
		model="CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
};

class CfgVehicles
{
    class Inventory_Base;
	class Container_Base;
	class CP_DryPost_Kit: Inventory_Base
	{
		scope=2;
		displayName="Dry Pot Kit";
		descriptionShort="Used in Preparing for Barricading Windows";
		model="\CannabisPlus\furniture\DryPostKit.p3d";
		weight=300;
		rotationFlags=17;
		itemSize[]={1,4};
		itemBehaviour=1;
		attachments[]=
		{
			"Rope"
		};
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
    class CP_DryPost : Inventory_Base
    {
        scope = 2;
		displayName = "Drying Post";
		descriptionShort = "A post for drying cannabis and other plants.";
		model="\CannabisPlus\furniture\DryPost.p3d";
		weight=20000;
		itemSize[]={3,11};
		itemBehaviour=2;
        physLayer="item_large";
		itemsCargoSize[] = {10,4};
		rotationFlags = 12;
        attachments[]=
		{
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3",
            "HangingPlants4",
            "HangingPlants5",
			"HangingPlants6",
			"DriedPlantPile",
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
					"HangingPlants4",
					"HangingPlants5",
					"HangingPlants6",
					"DriedPlantPile",
					"Rope"
                };
				ghostIcon="set:dayz_inventory image:plant";
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
			class DryPile
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


	class CP_RawPlantBase : Inventory_Base
    {
        scope = 2;
		displayName = "CorePlant";
		descriptionShort = "CorePlant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3",
            "HangingPlants4",
            "HangingPlants5",
			"HangingPlants6"
        };
    };
	class CP_DriedCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName = "Dried Plant";
		descriptionShort = "A Dried up Cannabis plant with all the buds picked off.";
		model="\CannabisPlus\furniture\DriedCannabisPlantHanging.p3d";
        itemSize[]={3,3};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=1;
		inventorySlot[]=
		{
			"DriedPlantPile"
		};
	}
	
	class CP_RawSkunkCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Skunk Plant";
		descriptionShort = "A raw Skunk plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};

    };
	class CP_RawBlueCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Blue God  Plant";
		descriptionShort = "A raw Blue God plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};

    };

	class CP_RawKushCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Kush Plant";
		descriptionShort = "A raw Kush plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};

    };

	class CP_RawStardawgCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Stardawg Plant";
		descriptionShort = "A raw Stardawg plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};
 
    };

	class CP_RawFutureCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Future Plant";
		descriptionShort = "A raw Future plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};

    };

	class CP_RawNomadCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Nomad Plant";
		descriptionShort = "A raw Nomad plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
       itemSize[]={4,4};

    };

	class CP_RawS1CannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw S1 Plant";
		descriptionShort = "A raw S1 plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
            itemSize[]={4,4};

    };

	class CP_RawBlackFrostCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Black Frost Plant";
		descriptionShort = "A raw Black Frost plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={4,4};

    };

};