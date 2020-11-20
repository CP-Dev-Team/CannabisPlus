modded class ActionConstructor 
{    
	override void RegisterActions(TTypenameArray actions) 
	{
		super.RegisterActions(actions);

        actions.Insert(ActionSmokeJointSelf);
		actions.Insert(ActionSmokeCigSelf); 
		actions.Insert(ActionUnpackCigaretteBox);
		actions.Insert(ActionApplyCream);
	}
};