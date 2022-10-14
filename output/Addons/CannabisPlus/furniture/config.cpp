class CfgPatches
{
    class CP_Dry_Post
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
		displayName="Dry Post Kit";
		descriptionShort="Used to place a dry post.";
		model="\CannabisPlus\furniture\DryPostKit.p3d";
		weight=300;
		rotationFlags=2;
		itemSize[]={1,4};
		itemBehaviour=1;
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
            class CP_DryPost
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
        scope = 0;
		displayName = "CorePlant";
		descriptionShort = "CorePlant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        itemSize[]={1,4};
		rotationFlags = 32;
        inventorySlot[]=
        {
            "HangingPlants",
            "HangingPlants2",
			"HangingPlants3",
            "HangingPlants4",
            "HangingPlants5",
			"HangingPlants6"
        };
		hiddenSelections[]={""};
		hiddenSelectionsTextures[]={""};
    };
	class CP_DriedCannabisPlant : CP_RawPlantBase
	{
		scope = 2;
		displayName = "Dried Plant";
		descriptionShort = "A Dried up Cannabis plant with all the buds picked off.";
		model="\CannabisPlus\furniture\DriedCannabisPlantHanging.p3d";
        itemSize[]={1,4};
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
	};
	
	class CP_RawSkunkCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Skunk Plant";
		descriptionShort = "A raw Skunk plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_skunk_co.paa"
		};
    };
	class CP_RawBlueCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Blue God Plant";
		descriptionShort = "A raw Blue God plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_blue_co.paa"
		};
    };

	class CP_RawKushCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Kush Plant";
		descriptionShort = "A raw Kush plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_kush_co.paa"
		};
    };

	class CP_RawStardawgCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Stardawg Plant";
		descriptionShort = "A raw Stardawg plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_stardawg_co.paa"
		};
    };

	class CP_RawFutureCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Future Plant";
		descriptionShort = "A raw Future plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_future_co.paa"
		};
    };

	class CP_RawNomadCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Nomad Plant";
		descriptionShort = "A raw Nomad plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_nomad_co.paa"
		};
    };

	class CP_RawS1CannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw S1 Plant";
		descriptionShort = "A raw S1 plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_s1_co.paa"
		};
    };

	class CP_RawBlackFrostCannabisPlant : CP_RawPlantBase
    {
        scope = 2;
		displayName = "Raw Black Frost Plant";
		descriptionShort = "A raw Black Frost plant";
		hiddenSelections[]=
		{
			"CannabisPlantHanging"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\plants\data\cannabis_plant_blackfrost_co.paa"
		};
    };
};