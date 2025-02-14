class CfgMods
{
	class CP_Pouch
	{
		author="THYER5";
	};
};
class CfgPatches
{
	class CP_Pouch
	{
		units[]=
		{
			"CP_Pouch"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Cultivation",
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables",
			"DZ_Gear_Cooking",
			"DZ_Gear_Tools",
			"DZ_Vehicles_Parts",
			"DZ_Characters"
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	
	class CP_Pouch: Container_Base
	{
		scope=2;
		displayName="#cp_cannabis_pouch0";
		descriptionShort="#cp_cannabis_pouch1";
		model="CannabisPlus\Pouch\cannabis_pouch.p3d";
		weight=30;
		itemSize[]={2,2};
		itemsCargoSize[]={3,4};
		allowOwnedCargoManipulation=1;
		inventorySlot[] = {"modular_pouch_6","modular_pouch_9","modular_pouch_10","modular_pouch_13","Belt_Right","VestHolster"};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\Pouch\data\CannabisPouch_co.paa"
		};
		attachments[]=
		{
			"CP_Joint_Base",
			"CP_RollingPapers"
		};
		class GUIInventoryAttachmentsProps
		{
			class PouchAttachments
			{
				name="#cp_pouch_attachments0";
				description="#cp_pouch_attachments0";
				attachmentSlots[]=
				{
					"CP_Joint_Base",
					"CP_RollingPapers"				
				};
				icon="";
			};		
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\Pouch\data\cannabispouch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\Pouch\data\cannabispouch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\Pouch\data\cannabispouch_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\Pouch\data\cannabispouch_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\Pouch\data\cannabispouch_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyjoint: ProxyAttachment 
    {
        scope=2;
        inventorySlot="CP_Joint_Base";
        model="CannabisPlus\joints\CP_joint.p3d";
    };
    class Proxypapers: ProxyAttachment  
    {
        scope=2;
        inventorySlot="CP_RollingPapers";
        model="CannabisPlus\rolling\CPlus_papers.p3d";
    };    
};
class CfgSlots
{
	class Slot_joint
	{
		name="CP_Joint_Base";
		displayName="#cp_joint0";
		ghostIcon="Missing";
	};
	class Slot_papers
	{
		name="CP_RollingPapers";
		displayName="#cp_rolling_papers0";
		ghostIcon="Missing";
	};	
};