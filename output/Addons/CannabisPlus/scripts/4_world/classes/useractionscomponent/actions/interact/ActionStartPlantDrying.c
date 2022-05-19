class ActionDryPlants: ActionInteractBase
{	
	void ActionDryPlants()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Leave to Dry";
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
		if(!DryingPost.IsLocked() && CPPlant && (!CPDriedPlants || CPDriedPlants.GetQuantity() < 50) )
		{
			return true;
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		CP_DryPost DryingProcess = CP_DryPost.Cast( action_data.m_Target.GetObject() );
		DryingProcess.CheckStart();
	}
}