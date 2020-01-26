class Tobacco : Edible_Base
{
	override bool CanBeCookedOnStick()
	{
		return false;
	}

	override bool CanBeCooked()
	{
		return true;
	}	

	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceFeed);
		AddAction(ActionEatFruit);
	}
}
