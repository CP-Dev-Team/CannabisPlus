class CP_Workbench_Kit extends ItemBase
{
	ref protected EffectSound	m_DeployLoopSound;
	protected Object			Workbench_Kit1;
	
	void CP_Workbench_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	override void EEInit()
	{
		super.EEInit();
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
	}	
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
				
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}		
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() )
		{
			Workbench_Kit1 = GetGame().CreateObjectEx( "CP_Workbench", GetPosition(), ECE_PLACE_ON_SURFACE );
			Workbench_Kit1.SetPosition( position );
			Workbench_Kit1.SetOrientation( orientation );
		}	
		HideAllSelections();
		SetIsDeploySound( true );
		SetLifetime(3888000);
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}
}

class CP_Workbench_Holo extends ItemBase
{
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
    
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
}


class CP_Workbench extends Container_Base
{
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
   	}
    
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		ItemBase item = ItemBase.Cast(attachment);
		if (slotId == FindAttachmentBySlotName("DuctTape")
		{
			if(item)
			{
				string ItemName = item.GetType();
				if (ItemName.IndexOf("DuctTape") >= 0)
					return true;
			}
		}
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		ItemBase cargo = ItemBase.Cast(item);
		if (cargo)
		{
			string ItemName = cargo.GetType();
			if (ItemName.IndexOf("CP_Cannabis") >= 0 && (ItemName.IndexOf("Bag") == 0 && ItemName.IndexOf("Brick") == 0))
			{
				return true;
			} else
			{
				return false;
			}
		}
		return false;		
	}
}      