class VomitMdfr: ModifierBase
{
	int LIFETIME = 30;
	
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_IsPersistent 		= false;
		m_ID 				= 98;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
			return false;
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if ( attached_time >= LIFETIME )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnActivate(PlayerBase player)
	{
		//Print("[CP] Vomit modifier activating on player: " + player);
		SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_VOMIT );
		if( symptom )
		{
			symptom.SetDuration( 5 );
		}	
	}
	
	override protected void OnDeactivate(PlayerBase player)
	{
		//Print("[CP] Vomit modifier deactivating on player: " + player);
	}		
};