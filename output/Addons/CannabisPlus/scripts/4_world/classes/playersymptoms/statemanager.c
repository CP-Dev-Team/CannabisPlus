modded class SymptomManager
{
	void SymptomManager(PlayerBase player)
	{
		RegisterSymptom(new StonedLaughSymptom);
		RegisterSymptom(new StonedCoughSymptom);
	}
}