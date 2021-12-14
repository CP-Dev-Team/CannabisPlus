class ActionDrillPressCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( 10 );//120

	};
};
class ActionDrillPressLongerCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( 70 );//120

	};
};
class ActionUseDrillPress: ActionContinuousBase
{	
	void ActionUseDrillPress()
	{
		m_CallbackClass = ActionDrillPressCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	};
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return TendancyText;
    };

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		int currenttime = GetGame().GetTime();
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		ND_MetalFabbench Bench = ND_MetalFabbench.Cast( target_object );
		NDHeliPlugCore CheckSpark = NDHeliPlugCore.Cast( target_entity.GetAttachmentByType(NDHeliPlugCore) );
		
		if (Bench && Bench.IsOccupiedandPowered() && CheckSpark && !Bench.GetOutPutOccupied())//Bench.AttachmentCountinTotal()
		{
			TendancyText = Bench.GetDrillTendancyText()
			if(Bench.m_UseMetalFabBench == 0)
			{
				m_CallbackClass = ActionDrillPressCB;
			}
			else if(Bench.m_UseMetalFabBench == 1)
			{
				m_CallbackClass = ActionDrillPressLongerCB;
			}
			return true;
		}
		return false;
	};

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_MetalFabbench Bench = ND_MetalFabbench.Cast( action_data.m_Target.GetObject() );
		
		Bench.CreationPartsPliers(Bench.GetDrillTendancyCreationType())

	};
};
