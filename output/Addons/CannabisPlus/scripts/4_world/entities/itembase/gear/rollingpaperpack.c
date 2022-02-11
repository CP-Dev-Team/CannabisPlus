class CP_RollingPapers: Inventory_Base 
{
    override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
    {
        super.OnItemLocationChanged(old_owner, new_owner);

        if (GetGame().IsServer()) {

            DayZPlayer player_old = NULL;
            DayZPlayer player_new = NULL;
            
            bool PapesPickedUp = false;
            bool PapesDropped = false;
            
            if (old_owner) {
                if (Class.CastTo(player_old , old_owner) || Class.CastTo(player_old , old_owner.GetHierarchyRootPlayer() ) ) {
                    if (player_old.GetIdentity()){
                    PapesDropped = true;
                    }
                }
            }
            
            if (new_owner) {
                if ( Class.CastTo(player_new , new_owner) || Class.CastTo(player_new , new_owner.GetHierarchyRootPlayer() ) ) {
                    if (player_new.GetIdentity()){
                    PapesPickedUp = true;
                    }
                }
            }
            if (PapesPickedUp && PapesDropped && player_new != player_old ) { //Also making sure the player isn't just moving it around in the inventory 
//          Print("Papes stolen off a deady player's body");
		CPApi().Log("PickedUp","RollingPapers");
            } else if (PapesPickedUp && player_new != player_old ){
//          Print("Player has picked up Papes");
		CPApi().Log("PickedUp","RollingPapers");
            } else if (PapesDropped && player_new != player_old) {
//          Print("Player has dropped Papes");
		CPApi().Log("Dropped","RollingPapers");
        }
      }
    }
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionCPUsePlasticWrapper);
	}
};