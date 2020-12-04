modded class ActionTakeItemToHands: ActionInteractBase
{
   
    override void OnExecuteServer( ActionData action_data )
    {
        super.OnExecuteServer(action_data);
        EntityAI obj = EntityAI.Cast(action_data.m_Target.GetObject());
        if (obj){
            if ( obj.GetType() == "CP_RollingPapers" ) 
            {
                CPApi().Increment("PickedUp.RollingPapers");
            }
			if ( obj.GetType() == "CP_Relief_Balm" ) 
            {
                CPApi().Increment("PickedUp.CBDReliefBalm");
            }
        }
    }
}