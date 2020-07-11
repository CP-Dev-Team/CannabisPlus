modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CP_CraftCigsCannabisSkunk);
        RegisterRecipe(new CP_CraftCigsCannabisBlue);
        RegisterRecipe(new CP_CraftCigsCannabisKush);
        RegisterRecipe(new CP_CraftCigsCannabisStardawg);
        RegisterRecipe(new CP_CraftCigsTobacco);
		
        RegisterRecipe(new CP_CraftCannabisBagSkunk);
        RegisterRecipe(new CP_CraftCannabisBrickSkunk);
        RegisterRecipe(new CP_CraftCannabisBagKush);
        RegisterRecipe(new CP_CraftCannabisBrickKush);
        RegisterRecipe(new CP_CraftCannabisBagBlue);
        RegisterRecipe(new CP_CraftCannabisBrickBlue);
        RegisterRecipe(new CP_CraftCannabisBagStardawg);
        RegisterRecipe(new CP_CraftCannabisBrickStardawg);
		
        RegisterRecipe(new CP_CraftCigarettePackSkunkEmpty);
	    RegisterRecipe(new CP_CraftCigarettePackBlueEmpty);
        RegisterRecipe(new CP_CraftCigarettePackKushEmpty);
	    RegisterRecipe(new CP_CraftCigarettePackStardawgEmpty);
        RegisterRecipe(new CP_CraftCigarettePackChernamorkaEmpty);
		
        RegisterRecipe(new CP_CraftCigarettePackSkunk);
        RegisterRecipe(new CP_CraftCigarettePackBlue);
        RegisterRecipe(new CP_CraftCigarettePackKush);
        RegisterRecipe(new CP_CraftCigarettePackStardawg);
        RegisterRecipe(new CP_CraftCigarettePackChernamorka);
        RegisterRecipe(new CP_CraftCigarettePackMerkur);
        RegisterRecipe(new CP_CraftCigarettePackPartyzanka);
    }
}