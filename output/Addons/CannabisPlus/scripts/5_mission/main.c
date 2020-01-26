modded class MissionServer
{
    void MissionServer()
    {
        if (GetGame().IsServer()) 
        {
			CannabisPlus.getInstance();
			
        }
    }
}
modded class MissionGameplay
{
    void MissionGameplay()
    {
        if (GetGame().IsServer()) 
        {
           CannabisPlus.getInstance();
        }	
    }
}