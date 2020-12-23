class CP_DryPost extends Container_Base
{	
    /*    private void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
    */
    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        
        if (slot_name == "Rope")
            SetAnimationPhase ("Rope", 0);
    }
    
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        
        if (slot_name == "Rope")
            SetAnimationPhase ("Rope", 1);
    }
  
/*	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		PlayerBase pb = PlayerBase.Cast( player );
		if ( GetGame().IsServer() )
		{
			//Create DryPost
    		CP_DryPost drypost = CP_DryPost.Cast( GetGame().CreateObjectEx( "CP_DryPost", GetPosition(), ECE_PLACE_ON_SURFACE ) );
            drypost.SetPosition( position );
    		drypost.SetOrientation( orientation );
 			
            //    HideAllSelections();
			SetIsDeploySound( true );
		}
    }
*/
    override string GetPlaceSoundset()
    {
        return "woodenlog_drop_SoundSet";
    }
    
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    } 
}
