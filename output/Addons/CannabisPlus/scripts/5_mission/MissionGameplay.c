modded class MissionGameplay
{

	ref CannabisPlusRPC m_CannabisPlusRPC;

	void MissionGameplay()
	{
			m_CannabisPlusRPC = new ref CannabisPlusRPC();
			Print( "Loaded CannabisPlusRPC" );
	}
}