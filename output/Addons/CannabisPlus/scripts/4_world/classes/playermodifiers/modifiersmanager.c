modded class ModifiersManager
{
	void ModifiersManager(PlayerBase player)
	{
		AddModifier(new VomitMdfr);
		AddModifier(new StonedMdfr);
	}
}