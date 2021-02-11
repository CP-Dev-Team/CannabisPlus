class CfgPatches
{
	class CP_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"JM_CF_Scripts",
			"CPtoken"
		};
	};
};
class CfgMods
{
	class CannabisPlus
	{
		dir="CannabisPlus";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="CannabisPlus";
		credits="IceBlade, bombjack, Gloser";
		author="IceBlade";
		authorID="0";
		version="3.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
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
