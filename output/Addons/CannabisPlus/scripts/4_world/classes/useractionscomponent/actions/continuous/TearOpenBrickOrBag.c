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
	
	int m_ChangeGetText = 0;
	
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
		CP_CoreClass CPCORE = item;

		if(Bag && Bag.GetQuantity() <= 1)
		{
			TendancyText = CPCORE.GetCPitemTendancyText();
	
			return true;
		}	
		return false;

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
				
				UnboxBrickBag lambda = new UnboxBrickBag(action_data.m_MainItem, itemType, action_data.m_Player, itemCount);
				action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
				
				//spawns wrapping Paper
				//ItemBase paper = ItemBase.Cast( GetGame().CreateObjectEx("Paper", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
				
				action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			}
		}
	}
};
class UnboxBrickBag : ReplaceItemWithNewLambdaBase
{
	int m_ItemCount;
	void UnboxBrickBag (EntityAI old_item, string new_item_type, PlayerBase player, int count) { m_ItemCount = count; }

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		if ( GetGame().ConfigIsExisting( "CfgMagazines " + m_NewItemType ) )
		{
			Magazine pile;
			Class.CastTo(pile, new_item);
			pile.ServerSetAmmoCount(m_ItemCount);
		}
		else
		{
			ItemBase unboxed;
			Class.CastTo(unboxed, new_item);
			unboxed.SetQuantity(m_ItemCount);
		}
	}
	
	override void OnSuccess(EntityAI new_item)
	{
		super.OnSuccess(new_item);
	}
};