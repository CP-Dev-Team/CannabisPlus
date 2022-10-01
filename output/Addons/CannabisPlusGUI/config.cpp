class CfgPatches
{
	class CannabisPlus_GhostIcons
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CPtoken"
		};
	};
};
class CfgMods
{
	class CannabisPlus_GhostIcons
	{
		dir="CannabisPlusGUI";
		name="Cannabis Plus";		
		credits="IceBlade, bombjack, Gloser";
		author="IceBlade";
		authorID="0";
		version="3.0";
		extra=0;
		type="Mod";
		dependencies[]={"gui"};
		class defs
		{
			class imageSets
            {
                files[]=
                {"CannabisPlusGUI\GUI\CP_GhostImages.imageset"};
            };
		};
	};
};

class CfgSlots
{ 
    class Slot_Wrapper
    {
          name="Wrapper";
          displayName="Wrapper";
          ghostIcon="set:CP_GhostImages image:Wrapper";
    };
    class Slot_Bagger
    {
          name="Bagger";
          displayName="Bagger";
          ghostIcon="set:CP_GhostImages image:Bagger";
    };
	
    class Slot_CP_Cannabis_Buds
    {
        name="CP_Cannabis_Buds";
        displayName="Buds Storage";
        ghostIcon="set:dayz_inventory image:plant";
		stackMax=100;
    };	
    class Slot_CP_Cannabis_Bags
    {
          name="CP_Cannabis_Bags";
          displayName="Bags";
          ghostIcon="missing";
          stackMax=160;
    };
	class Slot_CP_Cannabis_Bricks
    {
        name="CP_Cannabis_Bricks";
        displayName="Bricks Storage";
        ghostIcon="set:dayz_inventory image:plant";
		stackMax=25;
    };
    class Slot_CP_PlasticRoll
    {
        name="CP_PlasticRoll";
        displayName="Roll";
        ghostIcon="missing";
    };
	class Slot_CP_Empty_Bags
	{
		name="CP_Empty_Bags";
        displayName="Empty Bags";
        ghostIcon="missing";
		stackMax=160;
		
	}
};   