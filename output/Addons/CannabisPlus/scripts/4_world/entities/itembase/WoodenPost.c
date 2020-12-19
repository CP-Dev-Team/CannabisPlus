class CP_WoodenPost extends Inventory_Base
{	
    void ReplaceEdibleWithNew (string typeName)
    {
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        if (player)
        {
            ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
            player.ServerReplaceItemInHandsWithNew(lambda);
        }
        else
            Error("ReplaceEdibleWithNew - cannot use edible without player");
    }

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			//Create clothesline
			
    		Clothesline clothesline = Clothesline.Cast( GetGame().CreateObjectEx( "Clothesline", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			clothesline.SetPosition( position );
    		clothesline.SetOrientation( orientation );
 			
			SetIsDeploySound( true );
            ReplaceEdibleWithNew("");
		}
    }
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
