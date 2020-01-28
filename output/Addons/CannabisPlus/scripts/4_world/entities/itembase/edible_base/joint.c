class CP_Joint : Edible_Base
{
	override bool CanBeCookedOnStick()
	{
		return false;
	}

	override bool CanBeCooked()
	{
		return false;
	}	

	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionSmokeJointSelf);
		AddAction(ActionSmokeJointTarget);
	}

	/*
		is called server-side
		the right place to adapt values if smoking
	*/

	/*
	override void OnConsume(float amount, PlayerBase consumer)
	{
		vector pos = this.ModelToWorld(GetMemoryPointPos("smokestart"));
		Print("POS:" + pos);
		Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, pos, Vector(0, 0, 0), true);
	}
	*/
}
