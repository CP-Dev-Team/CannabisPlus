class CP_JointBase extends AC_SmokableBase 
{
	vector m_ParticleLocalPos = Vector(0, 0.2, 0);

	override int GetSmokeParticleId()
	{
		return ParticleList.AC_SMOKE;
	}

	override vector GetSmokeParticleLocalPos()
	{
		return m_ParticleLocalPos;
	}

	override float GetSmokingParticleSizeScale()
	{
		return 1.0;
	}

	override float GetSmokingParticleVelocityScale()
	{
		return 1.0;
	}
	
    string GetcpJointPack()
	{
        return CP_StrainHelper.GetJointPackFromJoint(GetType());
	}
	string GetCpJointName()
	{
		return CP_StrainHelper.GetStrain(GetType());
	}
	
	void MakeStoned(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(99) ) { //effectively resets the timer
			//player.GetModifiersManager().DeactivateModifier(99);
			return;  //let previous modifier finish
		}	
		player.GetModifiersManager().ActivateModifier(99);
	}
	
	void MakePuke(PlayerBase player) {
		if( player.GetModifiersManager().IsModifierActive(98) ) { //effectively resets the timer
			return;  //let previous modifier finish
		}
		player.GetModifiersManager().ActivateModifier(98);
	}
	
	override void SetActions()	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);	// add action to smoke the joint
	}
}