modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
      super.RegisterRecipies();
	
		RegisterRecipe(new CP_CraftCBDCrudeOil);
		RegisterRecipe(new CP_CarveWoodenPost);
		RegisterRecipe(new CP_WorkBenchCraftKit);
		RegisterRecipe(new Decraft_CP_WorkBenchCraftKit);
		// Tobacco
		RegisterRecipe(new CP_CraftCigsTobacco);
		RegisterRecipe(new CP_CraftCigarettePackChernamorkaEmpty);
		RegisterRecipe(new CP_CraftCigarettePackChernamorka);
		RegisterRecipe(new CP_CraftCigarettePackMerkur);
		RegisterRecipe(new CP_CraftCigarettePackPartyzanka);
	
		// Skunk
		//RegisterRecipe(new CP_CraftCigarettePackSkunk);
	
		// BlueGod
		//RegisterRecipe(new CP_CraftCigarettePackBlue);
	
		// PurpleKush
		//RegisterRecipe(new CP_CraftCigarettePackKush);
	
		// Stardawg
		//RegisterRecipe(new CP_CraftCigarettePackStardawg);
	
		// Future
		//RegisterRecipe(new CP_CraftCigarettePackFuture);
	
		// S1
		//RegisterRecipe(new CP_CraftCigarettePackS1);
	
		// Nomad
		//RegisterRecipe(new CP_CraftCigarettePackNomad);
	
		// BlackFrost
		RegisterRecipe(new CP_CraftCigsCannabisBlackFrost);
		RegisterRecipe(new CP_CraftCannabisBagBlackFrost);
		RegisterRecipe(new CP_CraftCannabisBrickBlackFrost);       
		RegisterRecipe(new CP_CraftCigarettePackBlackFrostEmpty);
		RegisterRecipe(new CP_CraftCigarettePackBlackFrost);
		//RegisterRecipe(new CP_DeCraftCigsCannabisBlackFrost);
		//RegisterRecipe(new CP_DeCraftCannabisBagBlackFrost);

    }
}