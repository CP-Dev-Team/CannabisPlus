class CfgPatches
{
	class CannabisPlus
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Food",
			"DZ_Gear_Medical"
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
		credits="IceBlade, bombjack";
		author="IceBlade";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Mission"
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
