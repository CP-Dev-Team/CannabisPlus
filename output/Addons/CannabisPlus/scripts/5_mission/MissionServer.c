modded class MissionServer
{
	private string CONFIG_FILE =  "$profile:CannabisPlus.json";
	ref CannabisPlusConfig _config;	
	private int modVersion = 100;
	ref CannabisPlusRPC m_CannabisPlusRPC;

	void MissionServer()
	{
		m_CannabisPlusRPC = new ref CannabisPlusRPC();
		Print( "Loaded CannabisPlusRPC" );

		if ( GetGame().IsServer() ){
			_config = new CannabisPlusConfig();
			string fileName;
			FileAttr fileAttr;
			FindFileHandle configFile = FindFile(CONFIG_FILE, fileName, fileAttr, 0);
			if(!configFile){
				JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
				Print("Create new CannabisPlus Config File");
			}else{
				if(_config.configVersion == modVersion) {
					JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
					Print("Load CannabisPlus Config File");
				} else {					
					DeleteFile("$profile:CannabisPlus_old.json");
					CopyFile(CONFIG_FILE, "$profile:CannabisPlus_old.json");
					DeleteFile(CONFIG_FILE);
					JsonFileLoader<CannabisPlusConfig>.JsonSaveFile(CONFIG_FILE, _config);
					JsonFileLoader<CannabisPlusConfig>.JsonLoadFile(CONFIG_FILE, _config);
		
					Print("Copy old CannabisPlus Config File");
				}
			}
			_config.Validate();
		}	
	}
}