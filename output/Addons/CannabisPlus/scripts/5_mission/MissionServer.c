modded class MissionServer
{
	protected ref CannabisPlusConfigManager m_currentcfg;

	override void OnInit()
	{
		super.OnInit();
		if(!m_currentcfg)
			m_currentcfg = GetCPConfig();//Server creates default config for the mod on the startup!
		if(m_currentcfg)
			Print("[CP] Config Sucessfully loaded!");
		else
			Print("[CP] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "CP_scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both );
	}

	/* RPC HANDLING SERVERSIDE */
	void CLIENTCONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Server) {
			GetRPCManager().SendRPC("CP_scripts", "CONFIGRESPONSE", new Param1< ref CannabisPlusConfigManager >( m_currentcfg ), true, sender);
			Print("[CP] -> Sucessfully sent: " + sender.GetName() + " CP Plus Config!");
		}
	}
}