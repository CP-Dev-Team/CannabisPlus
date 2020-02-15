modded class DayZPlayerCameraBase extends DayZPlayerCamera {
	
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		
		super.OnUpdate(pDt, pOutResult);		
	}
	
	override void UpdateCameraNV(PlayerBase player) {
		
		super.UpdateCameraNV(player);
		
				
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) {		
			if(PlayerBase.Cast(m_pPlayer).m_HasConsumedJoint) {
				PPEffects.SetEVValuePP(3.0);
				PPEffects.SetColorizationNV(0.5, 0.3, 0.1);
			} else {
				PPEffects.SetEVValuePP(0.0);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
			}	
		}
	}
}