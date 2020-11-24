class VomitMdfr: ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 				= 100;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override void OnTick(PlayerBase player, float deltaT)
	{

	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnActivate(PlayerBase player)
	{
		Print("[CP] Vomit modifier PUKING");
		player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_VOMIT );
	}


	override bool DeactivateCondition(PlayerBase player)
	{
		return !ActivateCondition(player);
	}		
};