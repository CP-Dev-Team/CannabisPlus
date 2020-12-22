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
    class Slot_CannabisPlant
    {
        name="Raw Cannabis Plant";
        displayName="Raw Cannabis Plant";
        ghostIcon="plant";
    };
    class Slot_CannabisPlant2
    {
        name="Raw Cannabis Plant2";
        displayName="Raw Cannabis Plant2";
        ghostIcon="plant";
    };
    class Slot_CannabisPlant3
    {
        name="Raw Cannabis Plant3";
        displayName="Raw Cannabis Plant3";
        ghostIcon="plant";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyCP_RawCannabisPlant : ProxyAttachment
    {
        scope = 2;
        InventorySlot="Raw Cannabis Plant";
        model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
    };
};

class CfgVehicles
{
    class Inventory_Base;
    class CP_DryPost : Inventory_Base
    {
        scope = 2;
		displayName = "Dry Post";
		descriptionShort = "A post for drying plants.";
		model="\CannabisPlus\furniture\DryPost.p3d";
		weight=20000;
		itemSize[]={3,11};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
        varStackMax=1;
        inventorySlot[]={};
        attachments[]=
		{
            "Raw Cannabis Plant",
            "Raw Cannabis Plant2",
			"Raw Cannabis Plant3",
			"Rope"
		};
		simpleHiddenSelections[] = 
		{
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
                    "Raw Cannabis Plant",
                    "Raw Cannabis Plant2",
                    "Raw Cannabis Plant3"
                };
            };
        };
    };

    class CP_RawCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Cannabis Plant";
		descriptionShort = "Raw Cannabis Plant";
		model="\CannabisPlus\furniture\CannabisPlantHanging.p3d";
        inventorySlot[]=
        {
            "Raw Cannabis Plant",
            "Raw Cannabis Plant2",
            "Raw Cannabis Plant3"
        };
    };
    /*    
	class CP_WoodenPost : Inventory_Base
	{
		scope=2;
		displayName="Wooden Post";
		descriptionShort="A wooden post.";
		model="\CannabisPlus\furniture\DryPost.p3d";
		weight=20000;
		itemSize[]={3,11};
		varQuantityDestroyOnMin=1;
		itemBehaviour=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=50;
        varStackMax=2;
        inventorySlot[]={};
        attachments[]=
		{
			"Rope"
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
	*/
};