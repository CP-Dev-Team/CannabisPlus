class CP_Relief_Balm extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionApplyCream);
	}
	
	override void OnApply(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(eModifiers.MDF_PAINKILLERS ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( eModifiers.MDF_PAINKILLERS, false );
		}
		player.GetModifiersManager().ActivateModifier( eModifiers.MDF_PAINKILLERS );
	}

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
    {
        super.OnItemLocationChanged(old_owner, new_owner);

        if (GetGame().IsServer()) {

            DayZPlayer player_old = NULL;
            DayZPlayer player_new = NULL;
            
            bool CBDCreamPickedUp = false;
            bool CBDCreamDropped = false;
            
            if (old_owner) {
                if (Class.CastTo(player_old , old_owner) || Class.CastTo(player_old , old_owner.GetHierarchyRootPlayer() ) ) {
                    if (player_old.GetIdentity()){
                    CBDCreamDropped = true;
                    }
                }
            }
            
            if (new_owner) {
                if ( Class.CastTo(player_new , new_owner) || Class.CastTo(player_new , new_owner.GetHierarchyRootPlayer() ) ) {
                    if (player_new.GetIdentity()){
                    CBDCreamPickedUp = true;
                    }
                }
            }
            if (CBDCreamPickedUp && CBDCreamDropped && player_new != player_old ) { //Also making sure the player isn't just moving it around in the inventory 
            //          Print("CBDCream stolen off a deady player's body");
            CPApi().Increment("PickedUp.RollingPapers");
            } else if (CBDCreamPickedUp && player_new != player_old ){
            //          Print("Player has picked up CBDCream");
            CPApi().Increment("PickedUp.RollingPapers");
            } else if (CBDCreamDropped && player_new != player_old) {
            Print("Player has dropped CBDCream");
            //          CPApi().Increment("PickedUp.RollingPapers");
        }
      }
    }
};