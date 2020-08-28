class CP_Relief_Balm extends ItemBase
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
};