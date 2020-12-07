class CP_RollingPapers: Inventory_Base 
{
/*    override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
    {
        super.OnItemLocationChanged(old_owner, new_owner);
        
        DayZPlayer player_old = NULL;
        DayZPlayer player_new = NULL;
        
        bool PapesPickedUp = false;
        bool PapesDropped = false;
        
        if (old_owner) {
            if (Class.CastTo(player_old , old_owner) || Class.CastTo(player_old , old_owner.GetHierarchyRootPlayer()) {
                if (player_old.GetIdentity()){
                   PapesDropped = true;
                }
            }
        }
        
        if (new_owner) {
            if ( Class.CastTo(player_new , new_owner) || Class.CastTo(player_new , new_owner.GetHierarchyRootPlayer() ) {
                if (player_new.GetIdentity()){
                   PapesPickedUp = true;
                }
            }
        }
       if (PapesPickedUp && PapesDropped && player_new != player_old ) { //Also making sure the player isn't just moving it around in the inventory 
//          Print("Papes stolen off a deady player's body");
          CPApi().Increment("PickedUp.RollingPapers");
       } else if (PapesPickedUp){
//          Print("Player has picked up Papes");
          CPApi().Increment("PickedUp.RollingPapers");
       } else if (PapesDropped) {
          Print("Player has dropped Papes");
//          CPApi().Increment("PickedUp.RollingPapers");
       }
    } */
};
