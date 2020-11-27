class CfgPatches
{
	class CP_Furniture
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgSlots
{
	class Slot_DryPlant
    {
        name="DryPlant";
        displayName="DryPlant";
		ghostIcon="plant";
    };
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothesline : Inventory_Base
	{
		scope = 2;
		displayName = "Clothesline";
		descriptionShort = "Clothesline";
		model="\CannabisPlus\furniture\clothesline.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		rotationFlags = 2;
		attachments[] = {"Att_CombinationLock","Material_Nails","Material_WoodenPlanks","Material_MetalSheets","CamoNet"};
		itemsCargoSize[]={10,50};

		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock", "CamoNet"};
				icon = "cat_bb_attachments";
				selection = "shed";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails", "Material_WoodenPlanks","Material_MetalSheets"};
				icon = "cat_bb_material";
				selection = "shed";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Material_MetalWire: AnimSourceHidden{};
			class Deployed :  AnimSourceHidden{};
			class Base_Frame : AnimSourceHidden{};
			class Base_Wood : AnimSourceHidden{};
			class Wall1_Frame : AnimSourceHidden{};
			class Wall2_Frame : AnimSourceHidden{};
			class Wall3_Frame : AnimSourceHidden{};
			class Wall4_Frame : AnimSourceHidden{};
			class Roof_Frame : AnimSourceHidden{};
			class Wall1_Wood : AnimSourceHidden{};
			class Wall2_Wood : AnimSourceHidden{};
			class Wall3_Wood : AnimSourceHidden{};
			class Wall4_Wood : AnimSourceHidden{};
			class Roof_Wood : AnimSourceHidden{};
			class Roof_Metal : AnimSourceHidden{};
			class CamoNet : AnimSourceHidden{};
			class Doors1 : AnimSourceHidden{};
			class Doors1_Rotate : AnimRotate{};
			class Doors2 : AnimSourceHidden{};
			class Doors2_Rotate : AnimRotate{};
		};
		class Construction
		{
			class shed
			{
				class Base_Frame
				{
					name="$STR_CfgVehicles_Construction_Part_Base";
					is_base=1;
					id=1;
					required_parts[]={};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Base_Wood
				{
					name = "Base Wood";
					id = 2;
					required_parts[] = {"Base_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall1_Frame
				{
					name = "Wall 1 Frame";
					id = 3;
					required_parts[] = {"Base_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall2_Frame
				{
					name = "Wall 2 Frame";
					id = 4;
					required_parts[] = {"Base_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall3_Frame
				{
					name = "Wall 3 Frame";
					id = 5;
					required_parts[] = {"Base_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall4_Frame
				{
					name = "Wall 4 Frame";
					id = 6;
					required_parts[] = {"Base_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Roof_Frame
				{
					name = "Roof Frame";
					id = 7;
					required_parts[] = {"Wall1_Frame", "Wall2_Frame","Wall3_Frame", "Wall4_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall1_Wood
				{
					name = "Wall 1 Wood";
					id = 8;
					required_parts[] = {"Wall1_Frame", "Wall2_Frame","Wall3_Frame", "Wall4_Frame","Roof_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall2_Wood
				{
					name = "Wall 2 Wood";
					id = 9;
					required_parts[] = {"Wall1_Frame", "Wall2_Frame","Wall3_Frame", "Wall4_Frame","Roof_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall3_Wood
				{
					name = "Wall 3 Wood";
					id = 10;
					required_parts[] = {"Wall1_Frame", "Wall2_Frame","Wall3_Frame", "Wall4_Frame","Roof_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Wall4_Wood
				{
					name = "Wall 4 Wood";
					id = 11;
					required_parts[] = {"Wall1_Frame", "Wall2_Frame","Wall3_Frame", "Wall4_Frame","Roof_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Roof_Wood
				{
					name = "Roof Wood";
					id = 12;
					required_parts[] = {"Roof_Frame"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Doors1
				{
					name = "Door 1";
					id = 13;
					is_gate=1;
					required_parts[] = {"Wall1_Wood", "Wall2_Wood","Wall3_Wood", "Wall4_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};
				class Doors2
				{
					name = "Door 2";
					id = 14;
					is_gate=1;
					required_parts[] = {"Wall1_Wood", "Wall2_Wood","Wall3_Wood", "Wall4_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
					};
				};				
				class Roof_Metal
				{
					name = "Roof Metal";
					id = 15;
					required_parts[] = {"Roof_Wood"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 10;
						};
					};
				};
			};
		};
	};
	class ClotheslineKitPlacing : Inventory_Base
	{
		scope=2;
		displayName="This is a hologram";
		descriptionShort="Nothing to see here, move along";
		model="\DZ\gear\camping\fence_kit_placing.p3d";
	};
	class ClotheslineKit: Inventory_Base
	{
		scope=2;
		displayName="ClotheslineKit";
		descriptionShort="ClotheslineKit";
		model="\DZ\gear\camping\fence_kit.p3d";
		rotationFlags=17;
		itemSize[]={1,5};
		weight=280;
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

};
