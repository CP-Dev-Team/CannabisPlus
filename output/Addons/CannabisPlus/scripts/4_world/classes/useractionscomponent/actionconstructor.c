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
		// starts drying process on Drypost
		actions.Insert(ActionDryPlants);
		//WorkBench actions
		actions.Insert(ActionCPUsePlasticWrapper);
		actions.Insert(ActionCPUseBagger);
	};
};