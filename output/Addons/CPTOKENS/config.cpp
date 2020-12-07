class CfgPatches
{
	class CPtoken
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};
class CfgMods
{
	class CPtoken
	{
		dir="CPTOKENS";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="CPtoken";
		credits="IceBlade, bombjack, Gloser, Kuli";
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
					"CPTOKENS/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"CPTOKENS/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"CPTOKENS/scripts/5_mission"
				};
			};
		};
	};
};
