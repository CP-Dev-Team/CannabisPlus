modded class UATimeSpent
{
	const float CPWrapBag = 4;
}
class ActionCPWrapBrickCB : ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat( UATimeSpent.CPWrapBag/ActionCPUsePlasticWrapper.Cast(m_ActionData.m_Action).CYCLES );
	}
};
class ActionCPUsePlasticWrapper: ActionContinuousBase
{	
	static int CYCLES = 2;
	void ActionCPUsePlasticWrapper()
	{
		m_CallbackClass = ActionCPWrapBrickCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;		
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return  TendancyText;
    };

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		
		CP_Workbench Bench = CP_Workbench.Cast( target_object );
		CP_CannabisBags Bags = CP_CannabisBags.Cast( target_entity.GetAttachmentByType(CP_CannabisBags) );
		
		if (Bench && Bench.Wrapper_Attached() )
		{
			TendancyText = Bench.GetBrickTendancyText()
			return true;
		}
		return false;
	};
/*
	override void OnStartServer( ActionData action_data )
	{
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		
		Bench.CreateBricks();
		
	};
*/
	override void OnFinishProgressServer( ActionData action_data )
    {    
		CP_Workbench Bench = CP_Workbench.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		MinusQuantity( action_data.m_MainItem, target );
		Bench.CreateBricks();
    }
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Wrapped Brick of " + action_data.m_Target.GetObject().GetDisplayName();
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		
		if(item.GetQuantity() >= 2)
		{
			item.AddQuantity(-1,false);// some reason repeats the -# twice no clue.
		}
		else
		{
			GetGame().ObjectDelete(item);
		}
	}
};
