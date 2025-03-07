
modded class MissionGameplay extends MissionBase
{
	protected bool m_isModdedMissionInitialized = false;

	override void OnInit()
	{
		super.OnInit();
		if(!m_isModdedMissionInitialized) {
			GetRPCManager().AddRPC( "CP_scripts", "CONFIGRESPONSE", this, SingeplayerExecutionType.Client );
			m_isModdedMissionInitialized = true;
		}
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("CP_scripts", "CLIENTCONFIGREQUEST", null, true);//Sends the remote a request to get the config.
	}

	/* RPC HANDLING OF CLIENT */ 
	void CONFIGRESPONSE(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {

		if(type == CallType.Client) 
		{
			Param1 <ref CannabisPlusConfigManager> data;
        	if ( !ctx.Read( data ) ) return;
			g_ClientCannabisPlusConfig = data.param1; //Update our referenz in Gamemodule.
			Print("[CP] Sucessfully recieved config from remote!");
		}
	}
}