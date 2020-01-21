modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CraftCigsCannabis);
        RegisterRecipe(new CraftCigsTobacco);
        RegisterRecipe(new CraftCannabisBag);
        RegisterRecipe(new CraftCannabisBrick);
        RegisterRecipe(new CraftCannabisBagKush);
        RegisterRecipe(new CraftCannabisBrickKush);
        RegisterRecipe(new CraftCannabisBagBlue);
        RegisterRecipe(new CraftCannabisBrickBlue);
    }
}