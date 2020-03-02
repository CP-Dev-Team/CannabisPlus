class CfgPatches
{
	class CP_scripts
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
		version="1.0";
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
