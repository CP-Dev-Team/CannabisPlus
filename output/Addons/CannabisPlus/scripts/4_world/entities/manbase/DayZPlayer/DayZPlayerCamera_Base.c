enum MyNVTypes
{	
	NONE = 0,
	NV_GOGGLES,
	NV_OPTICS_ON,
	NV_OPTICS_OFF,
	MAX,
	SMOKEJOINT
}

modded class DayZPlayerCameraBase extends DayZPlayerCamera {
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		
		super.OnUpdate(pDt, pOutResult);		
	}
	
	override void SetNVPostprocess(int NVtype)
	{		
		switch (NVtype)
		{
			case MyNVTypes.NONE:
				PPEffects.SetEVValuePP(0);
				PPEffects.SetColorizationNV(1.0, 1.0, 1.0);
				PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
			
			case MyNVTypes.NV_OPTICS_ON:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(3.0, 2.0, 9.0, 1.0);
			break;
			
			case MyNVTypes.NV_OPTICS_OFF:
				PPEffects.SetEVValuePP(-10);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
				PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
			
			case MyNVTypes.NV_GOGGLES:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;
			
			case MyNVTypes.SMOKEJOINT:
				PPEffects.SetEVValuePP(3);
				PPEffects.SetColorizationNV(0.5, 0.3, 0.1);
				//PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;			
		}
		
		if (PlayerBaseClient.Cast(m_pPlayer))
		{
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); //TODO 
		}
	}
	
	
	override void UpdateCameraNV(PlayerBase player) {
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() ) {		
			if(PlayerBase.Cast(m_pPlayer).m_HasConsumedJoint) {
				SetNVPostprocess(MyNVTypes.SMOKEJOINT);
			}else{
				SetNVPostprocess(MyNVTypes.NONE);
			}
		}
	}	
}