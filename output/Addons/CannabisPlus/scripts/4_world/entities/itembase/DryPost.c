class CP_DryPost extends ItemBase
{	
    private void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };

    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item,slot_name);

        if(slot_name == "Rope")
        {
            if ( item.IsKindOf("Rope")) // any attachment but Rope
            {
                ShowSimpleSelection("Rope", 1)
            }
        }
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);

        if(slot_name == "Rope")
        {
            if ( item.IsKindOf("Rope")) // any attachment except Rope
            {
                ShowSimpleSelection("Rope", 0)
            }
        }
    }

    override bool IsDeployable()
	{
        return false;
	}

    /*
    override void OnPlacementStarted( Man player ) 
    {
        Object targetObject;

        CP_DryPost DryPost = CP_DryPost.Cast( targetObject );

        string thingName = DryPost.FindAttachmentBySlotName("Rope").GetType();
        if ( thingName == "Rope" )
        {
            SetTakeable(true);
        }
        SetTakeable(false);
            
        super.OnPlacementStarted( player );

    //        SetTakeable(false);
    }
    */
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		PlayerBase pb = PlayerBase.Cast( player );
		if ( GetGame().IsServer() )
		{
        /*            //Create Hologram
            PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
        */
			//Create DryPost
    		CP_DryPost drypost = CP_DryPost.Cast( GetGame().CreateObjectEx( "CP_DryPost", GetPosition(), ECE_PLACE_ON_SURFACE ) );
		//	CP_DryPost drypost = CP_DryPost.Cast( GetGame().CreateObjectEx( "CP_DryPost", pb.GetLocalProjectionPosition(), false ) );			
            drypost.SetPosition( position );
    		drypost.SetOrientation( orientation );
 			
            HideAllSelections();
			SetIsDeploySound( true );
		}
    }

    override string GetPlaceSoundset()
    {
        return "woodenlog_drop_SoundSet";
    }
    
    override void SetActions()
    {
        super.SetActions();
        {
            AddAction(ActionTogglePlaceObject);
            AddAction(ActionPlaceObject);
        }
    }
}
