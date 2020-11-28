class CannabisPlusRPC {

    void CannabisPlusRPC() {

        GetRPCManager().AddRPC( "CP_scripts", "RetreiveCannabisPlusConfig", this, SingeplayerExecutionType.Both );
    }    

    void RetreiveCannabisPlusConfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
    {
        Param1 <ref CannabisPlusConfig> m_CannabisPlusConfig;
        if ( !ctx.Read( m_CannabisPlusConfig ) ) return;
        
        if( type == CallType.Server )
        {
            Print( "[CP] Server function called!" );
        }
        else
        {
            Print( "[CP] Client function called!" );
	    GetDayZGame().SetCannabisPlusConfig(m_CannabisPlusConfig.param1);
        }
    }
}