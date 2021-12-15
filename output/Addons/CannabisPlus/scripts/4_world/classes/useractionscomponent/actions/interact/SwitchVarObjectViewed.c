
/*
class ActionChangeDrillPressAction: ActionSingleUseBase
{
    void ActionChangeSmithIngotAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Change Action";
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		ND_MetalFabbench Bench = ND_MetalFabbench.Cast( target_object );
		NDHeliPlugCore CheckSpark = NDHeliPlugCore.Cast( target_entity.GetAttachmentByType(NDHeliPlugCore) );
        
        if (Bench && Bench.IsOccupiedandPowered() && CheckSpark && !Bench.GetOutPutOccupied())
		{
            return true;
        }
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {
        ND_MetalFabbench Bench = ND_MetalFabbench.Cast( action_data.m_Target.GetObject() );
		
        if (Bench)
		{
            Bench.StepBenchTendancy();
        }
    };
};
*/