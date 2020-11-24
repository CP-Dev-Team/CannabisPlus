class StonedMdfr: ModifierBase
{
	int LIFETIME = 30;  //currently the same as the config
	
	static const int CHANCE_OF_LAUGHTER = 50;
	static const int CHANCE_OF_COUGH = 25;
	static const int WATER_DRAIN_WHILE_STONED = 2;
	
	float 			m_LastWaterLevel;
	ref HumanMovementState		m_MovementState	= new HumanMovementState();

	override void Init()
	{
		m_TrackActivatedTime	= true;
		m_IsPersistent 		= false;
		m_ID 				= 99;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 10;
	}
	
	override string GetDebugText()
	{
		return (LIFETIME - GetAttachedTime()).ToString();
	}
	
	override protected void OnActivate(PlayerBase player)
	{
		int roll = Math.RandomInt(0, 100);
		Print("[CP] Stoned modifier activating on player: " + player + " with roll: " + roll);	
		
		if ( roll < CHANCE_OF_COUGH )
		{
			Print("[CP] Stoned modifier COUGHING");	
			player.GetSymptomManager().QueueUpPrimarySymptom(99);	
			
		} else if ( roll < CHANCE_OF_LAUGHTER )
		{
			Print("[CP] Stoned modifier LAUGHING");	
			player.GetSymptomManager().QueueUpPrimarySymptom(100);
		}
	}
	
	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		Print("[CP] Stoned modifier deactivating on player: " + player);
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

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		
		if (player.GetStatWater().Get() > (WATER_DRAIN_WHILE_STONED))
	 		player.GetStatWater().Add(-1 * WATER_DRAIN_WHILE_STONED);
	}
};