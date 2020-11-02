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
	class CP_Clothesline : Inventory_Base
	{
		scope=2;
		displayName = "Clothesline";
		descriptionShort = "A clothesline.  Used for drying clothes.. and maybe other things.";
		model = "\CannabisPlus\clothesline\druglab.p3d";
		itemSize[] = { 3,3 };
		inventorySlot[]={""};
		attachments[]=
		{
			"DryPlant"
		};
		class GUIInventoryAttachmentsProps
		{
			class Cavity
			{
				name="Plant";
				description="";
				attachmentSlots[]=
				{
					"DryPlant"
				};
			};
		};
		hitpoints=100;
	};
};
