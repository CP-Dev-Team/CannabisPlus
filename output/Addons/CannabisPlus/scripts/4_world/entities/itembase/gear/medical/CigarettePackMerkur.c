modded class CigarettePack_Merkur: Box_Base 
{	
	override void SetActions()	{
		
		AddAction(ActionUnpackCigaretteBox);
		super.SetActions();
	}
};