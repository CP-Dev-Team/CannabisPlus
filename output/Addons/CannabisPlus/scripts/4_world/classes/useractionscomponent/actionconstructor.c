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
		// turn on the bagger on workbench
		//actions.Insert(ActionTurnOnBagger);
		// turn off the bagger on workbench
		//actions.Insert(ActionTurnOffBagger);
		// turn on the wrapper on workbench
		//actions.Insert(ActionTurnOnWrapper);
		// turn off the wrapper on workbench
		//actions.Insert(ActionTurnOffWrapper);
		//WorkBench actions
		actions.Insert(ActionUsePlasticWrapper);
	}
};