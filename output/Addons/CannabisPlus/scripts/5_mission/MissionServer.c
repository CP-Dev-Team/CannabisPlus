modded class MissionServer
{
	private string CONFIG_FILE =  "$profile:CannabisPlus.json";
	ref CannabisPlusConfig _config;	
	private int modVersion = 250;
	ref CannabisPlusRPC m_CannabisPlusRPC;

	void MissionServer()
	{
		m_CannabisPlusRPC = new ref CannabisPlusRPC();
		Print( "[CP] Loaded CannabisPlusRPC on Server" );
		
		string fileName;
		FileAttr fileAttr;
		FindFileHandle configFile = FindFile(CONFIG_FILE, fileName, fileAttr, 0);
		if(!configFile){
			_config = new CannabisPlusConfig();
			GetDayZGame().SetCannabisPlusConfig(_config);
			JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
			Print("[CP] Creating new CannabisPlus Config File");
		}else{
			//load current config file
			_config = new CannabisPlusConfig();
			JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
			if(_config.configVersion == modVersion) {
				//JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
				GetDayZGame().SetCannabisPlusConfig(_config);
				Print("[CP] Load Existing CannabisPlus Config File");
				//JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
			} else {					
				DeleteFile("$profile:CannabisPlus_old.json");
				CopyFile(CONFIG_FILE, "$profile:CannabisPlus_old.json");
				DeleteFile(CONFIG_FILE);
				_config = new CannabisPlusConfig();
				GetDayZGame().SetCannabisPlusConfig(_config);
				JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
				Print("[CP] Copy old CannabisPlus Config File");
			}
		}
		_config.Validate();
	}
}