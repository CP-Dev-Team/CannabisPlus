class CfgMods
{
	class CP_Pouch //NAME OF MOD
	{
		dir="CP_Pouch";//NAME OF MOD
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="CP_Pouch";//NAME OF MOD
		credits="";
		author="THYER5";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"CannabisPlus/scripts/4_world"
				};
			};
		};
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
		displayName="Cannabis Pouch";
		descriptionShort="Storage for your paraphernalia";
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
				name="Pouch Attachments";
				description="";
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
								"Cannabis\data\Pouch\data\cannabispouch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Cannabis\data\Pouch\data\cannabispouch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Cannabis\data\Pouch\data\cannabispouch_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Cannabis\data\Pouch\data\cannabispouch_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"Cannabis\data\Pouch\data\cannabispouch_destruct.rvmat"
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
		displayName="Joint";
		ghostIcon="Missing";
	};
	class Slot_papers
	{
		name="CP_RollingPapers";
		displayName="Rolling Papers";
		ghostIcon="Missing";
	};	
};