modded class MissionServer
{
    void MissionServer()
    {
        if (GetGame().IsServer()) 
        {
			CannabisPlus.getInstance();
			
        }
    }
}
modded class MissionGameplay
{
    void MissionGameplay()
    {
        if (GetGame().IsServer()) 
        {
           CannabisPlus.getInstance();
        }	
    }
	
	override void OnUpdate(float timeslice) {
		
		super.OnUpdate(timeslice);
		/*
		Man player = GetGame().GetPlayer();
		PlayerBase playerPB = PlayerBase.Cast(player);
		*/
		
		/*
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) {
			PlayerBase playerPB = GetGame().GetPlayer();
			
			if(playerPB.m_HasConsumedJoint) {			
				PPEffects.SetEVValuePP(3.0);
				PPEffects.SetColorizationNV(0.5, 0.3, 0.1);
			} else {
				PPEffects.SetEVValuePP(0.0);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
			}	
		}
		*/
		
	}
}