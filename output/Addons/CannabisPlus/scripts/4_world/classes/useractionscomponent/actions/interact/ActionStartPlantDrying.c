class ActionDryPlants: ActionInteractBase
{	
	string returntext = ""

	void ActionDryPlants()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return returntext;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		
		CP_RawPlantBase CPPlant = CP_RawPlantBase.Cast( target_entity.GetAttachmentByType(CP_RawPlantBase) );
		
		CP_DriedCannabisPlant CPDriedPlants = CP_DriedCannabisPlant.Cast( target_entity.GetAttachmentByType(CP_DriedCannabisPlant) );
		
		CP_DryPost DryingPost = CP_DryPost.Cast( target.GetObject() );
		
		//if (!DryingPost.IsLocked() && CPPlant && CPDriedPlants && CPDriedPlants.GetQuantity() < 50 )
		if( DryingPost && !DryingPost.IsLocked() && CPPlant )
		{
			return true;
			returntext = "Leave to Dry."
			Print( "Drying post locked: " + DryingPost.IsLocked() );
		}
		else if ( CPDriedPlants && CPDriedPlants.GetQuantity() >= 50 )
		{
			return false;
			returntext = "Too Many Dried Plants."
		}
		return false;
		returntext = "Is Drying."
	}

	override void OnExecuteServer( ActionData action_data )
	{
		CP_DryPost DryingProcess = CP_DryPost.Cast( action_data.m_Target.GetObject() );
		DryingProcess.CheckStart();
	}
}