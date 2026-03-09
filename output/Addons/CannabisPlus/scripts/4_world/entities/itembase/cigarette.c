class CP_Cigarette extends AC_SmokableBase
{	
	vector m_ParticleLocalPos = Vector(0, 0.1, 0);

	override int GetSmokeParticleId()
	{
		return ParticleList.AC_SMOKE;
	}

	override vector GetSmokeParticleLocalPos()
	{
		return m_ParticleLocalPos;
	}

	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeCigSelf);	// add action to smoke the joint
		AddAction(ActionCPLoadPack);
	}
}








