modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
      super.RegisterRecipies();
	
		RegisterRecipe(new CP_CraftCBDCrudeOil);
		RegisterRecipe(new CP_CarveWoodenPost);
		RegisterRecipe(new CP_WorkBenchCraftKit);
		RegisterRecipe(new Decraft_CP_WorkBenchCraftKit);
		RegisterRecipe(new CP_CraftCigsCannabis);
		RegisterRecipe(new CP_CraftCannabisBag);
		RegisterRecipe(new CP_CraftCannabisBrick);       
		RegisterRecipe(new CP_CraftJointPackEmpty);
		RegisterRecipe(new CP_CraftJointPack);
    }
}