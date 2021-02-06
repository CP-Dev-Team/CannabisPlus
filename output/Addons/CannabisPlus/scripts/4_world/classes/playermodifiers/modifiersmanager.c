modded class ModifiersManager
{

	override void Init() {
	
		super.Init();
		AddModifier(new VomitMdfr);
		AddModifier(new StonedMdfr);
	}
}