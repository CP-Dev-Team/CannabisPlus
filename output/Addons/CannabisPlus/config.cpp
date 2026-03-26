class CfgPatches
{
	class CannabisPlus
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"AgricultureCore"
		};
	};
};
class CfgMods
{
	class CannabisPlus
	{
		dir="CannabisPlus";
		name="Cannabis Plus";		
		credits="IceBlade, bombjack, Gloser, Kuli, Dumpgrah";
		author="IceBlade";
		authorID="0";
		version="3.0.7";
		extra=0;
		type="Mod";
		defines[]={"CANNABISPLUS"};
		dependencies[]={"gui","Game","World","Mission"};
		class defs
		{
			class imageSets
            {
                files[]=
                {
					"CannabisPlus/GUI/CP_GhostImages.imageset"
				};
            };
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"CannabisPlus/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"CannabisPlus/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"CannabisPlus/scripts/5_mission"
				};
			};
		};
	};
};

class CfgSoundShaders
{
    class Custom_SoundShader_Base
    {
        range = 30;
    };

    class Smoking_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
        	{
        		"CannabisPlus\sounds\smoke.ogg", 
        		1
        	}
        };
        volume = 1;
    };
};

class CfgSoundSets
{
    class Custom_SoundSet_Base
    {
        sound3DProcessingType = "character3DProcessingType";
        volumeCurve = "characterAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    class Smoking_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "Smoking_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.5;
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
          ghostIcon="set:CP_GhostImages image:bags";
          stackMax=160;
    };
    class Slot_CP_Cannabis_Bricks
    {
        name="CP_Cannabis_Bricks";
        displayName="Bricks Storage";
        ghostIcon="set:CP_GhostImages image:Bricks";
        stackMax=25;
    };
    class Slot_CP_PlasticRoll
    {
        name="CP_PlasticRoll";
        displayName="Roll";
        ghostIcon="set:CP_GhostImages image:PlasticWrap";
    };
    class Slot_AC_Empty_Bags
    {
        name="AC_Empty_Bags";
        displayName="Empty Bags";
        ghostIcon="set:CP_GhostImages image:bags";
        stackMax=160;
    };
    class Slot_HangingPlants
    {
        name="HangingPlants";
        displayName="Hanging Plants";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_HangingPlants2
    {
        name="HangingPlants2";
        displayName="HangingPlants2";
        selection="HangingPlants2";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_HangingPlants3
    {
        name="HangingPlants3";
        displayName="HangingPlants3";
        selection="HangingPlants3";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_HangingPlants4
    {
        name="HangingPlants4";
        displayName="HangingPlants4";
        selection="HangingPlants3";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_HangingPlants5
    {
        name="HangingPlants5";
        displayName="HangingPlants5";
        selection="HangingPlants3";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_HangingPlants6
    {
        name="HangingPlants6";
        displayName="HangingPlants6";
        selection="HangingPlants3";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
    };
    class Slot_DriedPlantPile
    {
        name="DriedPlantPile";
        displayName="DriedPlantPile";
        ghostIcon="set:CP_GhostImages image:HangingPlant";
        stackMax=50;
    };
};	
