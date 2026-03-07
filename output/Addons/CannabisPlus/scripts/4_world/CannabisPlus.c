class CP_CoreClass extends ItemBase 
{

	string GetCPitemTendancyText()
	{		
        return "";
    };
}



modded class CP_Plant_Tobacco
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Pepper
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Tomato
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Zucchini
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Pumpkin
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class Plant_Potato
{
	override void Harvest( PlayerBase player )
	{
		super.Harvest(player);
		if(GetGame().IsServer() && GetCPConfig().RemoveAfterHarvest==true){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( RemovePlantEx, 10, false, player.GetPosition() );
		}
	}
}

modded class ActionHarvestCrops: ActionInteractBase
{   
    override void OnExecuteClient( ActionData action_data )
    {    
        if(m_Plant && m_Plant.HasCrops()){
            // call the inherited class
            super.OnExecuteClient(action_data);
        }
    }
    
    override void OnExecuteServer( ActionData action_data )
    {
        if(m_Plant && m_Plant.HasCrops()){
            super.OnExecuteServer(action_data);
        }
    }
};