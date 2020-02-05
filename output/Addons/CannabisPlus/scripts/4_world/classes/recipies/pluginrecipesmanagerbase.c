modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CraftCigsCannabisSkunk);
        RegisterRecipe(new CraftCigsCannabisBlue);
        RegisterRecipe(new CraftCigsCannabisKush);
        RegisterRecipe(new CraftCigsTobacco);
        RegisterRecipe(new CraftCannabisBagSkunk);
        RegisterRecipe(new CraftCannabisBrickSkunk);
        RegisterRecipe(new CraftCannabisBagKush);
        RegisterRecipe(new CraftCannabisBrickKush);
        RegisterRecipe(new CraftCannabisBagBlue);
        RegisterRecipe(new CraftCannabisBrickBlue);
    }
}