modded class DayZPlayerImplementAiming {
	
	
	
	override bool ProcessAimFilters(float pDt, SDayZPlayerAimingModel pModel, int stance_index)
	{
		float breathing_offset_x;
		float breathing_offset_y;
		
		float noise_offset_x;
		float noise_offset_y;		
		
		float shake_offset_x;
		float shake_offset_y;
		
		float recoil_offset_mouse_x;
		float recoil_offset_mouse_y;
		
		float recoil_offset_hands_x;
		float recoil_offset_hands_y;
		
		float kuru_offset_x;
		float kuru_offset_y;
	
		float player_stamina = m_PlayerPb.GetStaminaHandler().GetStaminaNormalized();
		float speed = ((1.0 - player_stamina) * 4.0) + 1.0 * m_SwayModifier[2];
	
			
		if( m_PlayerPb.IsHoldingBreath() || m_PlayerPb.m_HasConsumedCigarette )
		{
			speed *= 0.1;
		}
		
		m_TotalTime += pDt * speed;
		m_SwayWeight = CalculateWeight(	stance_index, player_stamina, m_PlayerPb.m_CameraSwayModifier );
		

		
		//! get sway
		ApplyBreathingPattern(breathing_offset_x, breathing_offset_y, 3.0, m_TotalTime, m_SwayWeight);
		ApplyHorizontalNoise(noise_offset_x, noise_offset_y, 0.2, 0.5, 3.0 * m_SwayModifier[0], speed, 3 * m_SwayModifier[1], m_SwayWeight, pDt);
		
		int shake_level = m_PlayerPb.GetShakeLevel();
		if(shake_level != 0)
		{
			ApplyShakes(shake_offset_x, shake_offset_y, shake_level);
		}
		//Print(shake_level);
		//! get recoil
		if( m_CurrentRecoil )
		{
			m_CurrentRecoil.Update(pModel, recoil_offset_mouse_x, recoil_offset_mouse_y, recoil_offset_hands_x, recoil_offset_hands_y, pDt);
		}
		
		if( m_KuruShake )
		{
			m_KuruShake.Update(pDt, kuru_offset_x, kuru_offset_y);
		}
		
		//! hands offset
		pModel.m_fAimXHandsOffset = breathing_offset_x + noise_offset_x + recoil_offset_hands_x + shake_offset_x + kuru_offset_x;
		pModel.m_fAimYHandsOffset = breathing_offset_y + noise_offset_y + recoil_offset_hands_y + shake_offset_y + kuru_offset_y;

		//! cam offset
		pModel.m_fAimXCamOffset = -shake_offset_x - recoil_offset_hands_x - kuru_offset_x + m_CamShakeX;
		pModel.m_fAimYCamOffset	= -shake_offset_y - recoil_offset_hands_y - kuru_offset_y + m_CamShakeY;
		
		/*
		if( m_CamShakeX != 0 ) Print(m_CamShakeX);
		if( m_CamShakeX != 0 ) Print(m_CamShakeY);
		*/
		/*
		pModel.m_fAimXCamOffset = -shake_offset_y - recoil_offset_hands_y;// + shake_offset_x;
		pModel.m_fAimYCamOffset	= shake_offset_x + recoil_offset_hands_x;// + shake_offset_y;
		*/
		
		//! clamp aim ranges 
		if (stance_index == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
		{			
			float newVal = DayZPlayerUtils.LinearRangeClamp(pModel.m_fCurrentAimX, pModel.m_fCurrentAimY, m_AimXClampRanges);
			pModel.m_fAimYHandsOffset += newVal - pModel.m_fCurrentAimY;
		}
		
		if( m_PlayerDpi.IsInOptics() && m_KuruShake )
		{
			//TODO - do not offset mouse
		}
		//! mouse offset
		pModel.m_fAimXMouseShift = recoil_offset_mouse_x -kuru_offset_x / 10;
		pModel.m_fAimYMouseShift = recoil_offset_mouse_y + kuru_offset_y / 10;
		//Debug.ClearCanvas();
		//Debug.CanvasDrawPoint(pModel.m_fAimXHandsOffset * 100 + 250 ,pModel.m_fAimYHandsOffset * 100 + 300, ARGBF( 1, 0, 1, 1 ));
		
		return true;
	}
	
}