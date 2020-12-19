class CfgPatches
{
    class CP_Clothesline
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
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxybdu_jacket_g : ProxyAttachment
    {
        scope = 2;
        InventorySlot="Raw Cannabis Plant";
        model="\DZ\characters\tops\bdu_jacket_g.p3d";
    };
    class Proxybdu_pants_g : ProxyAttachment
    {
        scope = 2;
        InventorySlot="Raw Cannabis Plant2";
        model="\DZ\characters\pants\bdu_pants_g.p3d";
    };
};

class CfgVehicles
{
    class Inventory_Base;
    class Clothing_Base : Inventory_Base
    {
        inventorySlot[]=
        {
            "Raw Cannabis Plant",
            "Raw Cannabis Plant2"
        };
    };
    class Clothesline : Inventory_Base
    {
        scope = 2;
		displayName = "Clothesline";
		descriptionShort = "Clothesline";
		model="\CannabisPlus\furniture\clothesline.p3d";
        attachments[]=
        {
            "Raw Cannabis Plant",
            "Raw Cannabis Plant2"
        };
        class GUIInventoryAttachmentsProps
        {
            class CP_Line
            {
                name="Hang Clothes";
                description="";
                attachmentSlots[]=
                {
                    "Raw Cannabis Plant",
                    "Raw Cannabis Plant2"
                };
            };
        };
    };

    class CP_RawCannabisPlant : Inventory_Base
    {
        scope = 2;
		displayName = "Raw Cannabis Plant";
		descriptionShort = "Raw Cannabis Plant";
		model="\CannabisPlus\fruits\tobacco.p3d";
        inventorySlot[]=
        {
            "Raw Cannabis Plant",
            "Raw Cannabis Plant2"
        };
    };
        
/*    class CP_WoodenPost : WoodenLog
    {
		displayName="Wooden Post";
		descriptionShort="A wooden post.";
		model="\dz\gear\camping\wooden_log.p3d";
        varStackMax=2;
        inventorySlot[]={};
        attachments[]=
		{
			"Rope"
		};
    };
*/
	class CP_WoodenPost : Inventory_Base
	{
		scope=2;
		displayName="Wooden Post";
		descriptionShort="A wooden post.";
		model="\dz\gear\camping\wooden_log.p3d";
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

/*	class ClotheslineKit: Inventory_Base
	{
		scope=2;
		displayName="Clothesline Kit";
		descriptionShort="Clothesline Kit";
		model="\DZ\gear\camping\fence_kit.p3d";
		rotationFlags=17;
		itemSize[]={1,5};
		weight=280;
		itemBehaviour=1;
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
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage=0;
						};
						class Blood
						{
							damage=0;
						};
						class Shock
						{
							damage=0;
						};
					};
					class FragGrenade
					{
						class Health
						{
							damage=0;
						};
						class Blood
						{
							damage=0;
						};
						class Shock
						{
							damage=0;
						};
					};
				};
			};
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
			class Inventory: AnimSourceHidden
			{
			};
			class Placing: AnimSourceHidden
			{
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet="FenceKit_crafting_1_SoundSet";
					id=1111;
				};
				class crafting_2
				{
					soundSet="FenceKit_crafting_2_SoundSet";
					id=1112;
				};
				class crafting_3
				{
					soundSet="FenceKit_crafting_3_SoundSet";
					id=1113;
				};
				class crafting_4
				{
					soundSet="FenceKit_crafting_4_SoundSet";
					id=1114;
				};
				class crafting_5
				{
					soundSet="FenceKit_crafting_5_SoundSet";
					id=1115;
				};
			};
		};
	};
	class ClotheslineKitPlacing: ClotheslineKit
	{
		displayName="This is a hologram";
		descriptionShort="Nothing to see here, move along";
		scope=2;
		model="\CannabisPlus\furniture\clothesline.p3d";
		storageCategory=10;
		hiddenSelections[]=
		{
			"placing"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.tga"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\camping\data\fence_pile_of_planks.rvmat"
		};
		hologramMaterial="tent_medium";
		hologramMaterialPath="dz\gear\camping\data";
		alignHologramToTerain=0;
		slopeTolerance=0.30000001;
	};
*/
};