modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CraftCigsCannabisSkunk);
        RegisterRecipe(new CraftCigsCannabisBlue);
        RegisterRecipe(new CraftCigsCannabisKush);
        RegisterRecipe(new CraftCigsCannabisStardawg);
        RegisterRecipe(new CraftCigsTobacco);
		
        RegisterRecipe(new CraftCannabisBag);
        RegisterRecipe(new CraftCannabisBagSkunk);
        RegisterRecipe(new CraftCannabisBrick);
        RegisterRecipe(new CraftCannabisBrickSkunk);
        RegisterRecipe(new CraftCannabisBagKush);
        RegisterRecipe(new CraftCannabisBrickKush);
        RegisterRecipe(new CraftCannabisBagBlue);
        RegisterRecipe(new CraftCannabisBrickBlue);
        RegisterRecipe(new CraftCannabisBagStardawg);
        RegisterRecipe(new CraftCannabisBrickStardawg);
		
        RegisterRecipe(new CraftCigarettePackSkunkEmpty);
	    RegisterRecipe(new CraftCigarettePackBlueEmpty);
        RegisterRecipe(new CraftCigarettePackKushEmpty);
	    RegisterRecipe(new CraftCigarettePackStardawgEmpty);
        RegisterRecipe(new CraftCigarettePackChernamorkaEmpty);
		
        RegisterRecipe(new CraftCigarettePackSkunk);
        RegisterRecipe(new CraftCigarettePackBlue);
        RegisterRecipe(new CraftCigarettePackKush);
        RegisterRecipe(new CraftCigarettePackStardawg);
        RegisterRecipe(new CraftCigarettePackChernamorka);
    }
}