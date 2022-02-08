modded class ActionConstructor {   	 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// register all new actions which the player will perform
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void RegisterActions(TTypenameArray actions) {		
		super.RegisterActions(actions);
		
        actions.Insert(ActionSmokeJointSelf);
		actions.Insert(ActionSmokeCigSelf); 
		actions.Insert(ActionUnpackCigaretteBox);
		actions.Insert(ActionApplyCream);
		actions.Insert(ActionDryPlants);

		actions.Insert(ActionUsePlasticWrapper);
		actions.Insert(ActionUseBagger);
	};
};