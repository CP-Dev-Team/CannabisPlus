class CP_Tobacco extends ItemBase
{	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
