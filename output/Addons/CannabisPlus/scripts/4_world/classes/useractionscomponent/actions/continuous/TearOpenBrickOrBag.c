class ActionCP_RipOpenBrickOrBagCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
};

class ActionCP_RipOpenBrickOrBag: ActionContinuousBase
{	
	void ActionCP_RipOpenBrickOrBag()
	{
		m_CallbackClass = ActionCP_RipOpenBrickOrBagCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	string TendancyText = "";
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return  TendancyText;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CP_CannabisBags Bag = item;
		
		TendancyText = Bag.GetBagTendancyText()
		
		return true;

	};
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		if ( action_data.m_MainItem)
		{
			string path = "CfgVehicles " + action_data.m_MainItem.GetType();
			string child_name = "";
			int count;
			array<string> resources = new array<string>;
			
			if( GetGame().ConfigIsExisting( path ) && GetGame().ConfigIsExisting( path + " Resources") )
			{
				path = path + " Resources";
				count = GetGame().ConfigGetChildrenCount ( path );
				for (int i = 0; i < count; i++)
				{
					GetGame().ConfigGetChildName ( path, i, child_name );
					
					if ( GetGame().ConfigGetInt( path + " " + child_name + " value" ) )
					{
						resources.Insert( child_name );
					}
				}

				//TODO modify to allow for multiple ammo types spawning (if needed??)
				string itemType = resources.Get(0);
				int itemCount = GetGame().ConfigGetInt( path + " " + itemType + " value" );
				
				UnboxLambda lambda = new UnboxLambda(action_data.m_MainItem, itemType, action_data.m_Player, itemCount);
				action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
				
				//spawns wrapping Paper
				ItemBase paper = ItemBase.Cast( GetGame().CreateObjectEx("Paper", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
				
				action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			}
		}
	}
};


