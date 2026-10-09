modded class ActionConstructor {   	 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// register all new actions which the player will perform
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void RegisterActions(TTypenameArray actions) {		
		super.RegisterActions(actions);
		
        actions.Insert(ActionSmokeJointSelf);
		actions.Insert(ActionUnpackJointBox);
		actions.Insert(ActionUnpackCigaretteBox);
		actions.Insert(ActionApplyCream);
		// starts drying process on Drypost
		actions.Insert(ActionDryPlants);
		actions.Insert(ActionCP_RipOpenBrickOrBag);
	};
};