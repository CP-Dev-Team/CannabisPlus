modded class MissionServer
{
	//private string CONFIG_FILE =  "$profile:CannabisPlus.json";
	//ref CannabisPlusConfig _config;	
	//private int modVersion = 251;
	//ref CannabisPlusRPC m_CannabisPlusRPC;
	protected ref CannabisPlusConfigManager m_currentcfg;

	override void OnInit()
	{
		super.OnInit();
		if(!m_currentcfg)
			m_currentcfg = GetCPConfig();//Server creates default config for the mod on the startup!
		if(m_currentcfg)
			Print("[CP] Config Sucessfully loadet!");
		else
			Print("[CP] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "CP_scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both );
	}

	/* RPC HANDLING SERVERSIDE */
	void CLIENTCONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Server) {
			GetRPCManager().SendRPC("CP_scripts", "CONFIGRESPONSE", new Param1< ref CannabisPlusConfigManager >( m_currentcfg ), true, sender);
			Print("[CP] -> Sucessfully sendet: " + sender.GetName() + " CP Plus Config!");
		}
	}

	//void MissionServer()
	//{
		/*
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
		*/
	//}
}