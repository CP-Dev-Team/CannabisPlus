class CP_JointBase extends AC_SmokableBase 
{
	vector m_ParticleLocalPos = Vector(0, 0.2, 0);
	protected string m_cpJointPack= "";
	protected string m_cpJointNames= "";

	void CP_JointBase() 
	{							
        if ( ConfigIsExisting("cpPackJoint") ) 
		{
            m_cpJointPack= ConfigGetString("cpPackJoint");
        }
		else
		{
            m_cpJointPack= "";
        }
		
				        
        if ( ConfigIsExisting("cpCheckJoint") ) 
		{
            m_cpJointNames= ConfigGetString("cpCheckJoint");
        }
		else
		{
            m_cpJointNames= "";
        }
		
	}

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
        return m_cpJointPack;
	}
	string GetCpJointName()
	{
		return m_cpJointNames;
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