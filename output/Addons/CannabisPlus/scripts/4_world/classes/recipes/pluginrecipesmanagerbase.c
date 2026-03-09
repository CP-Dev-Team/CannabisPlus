modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
      super.RegisterRecipies();
	
		RegisterRecipe(new CP_CraftCBDCrudeOil);
		RegisterRecipe(new CP_CarveWoodenPost);
		RegisterRecipe(new CP_WorkBenchCraftKit);
		RegisterRecipe(new Decraft_CP_WorkBenchCraftKit);
		
		// Cannabis
		RegisterRecipe(new CP_CraftCigsCannabis);
		RegisterRecipe(new CP_CraftCannabisBag);
		RegisterRecipe(new CP_CraftCannabisBrick);       
		RegisterRecipe(new CP_CraftCigarettePackEmpty);
		RegisterRecipe(new CP_CraftCigarettePack);
		//RegisterRecipe(new CP_DeCraftCigsCannabis);
		//RegisterRecipe(new CP_DeCraftCannabisBag);

    }
}