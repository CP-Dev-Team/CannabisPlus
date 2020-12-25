class CP_RawCannabisPlant : Inventory_Base{}
class CP_DriedCannabisPlant : Inventory_Base{}

class CP_DryPost extends Container_Base
{	
    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        
        if (slot_name == "Rope")
            SetAnimationPhase ("Rope", 0);  // Shows the rope on the model when rope is attached.
    }
    
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        
        if (slot_name == "Rope")
            SetAnimationPhase ("Rope", 1);  // Hides the rope on the model when rope is detached.
            Dry();
    }

	private bool m_IsLocked = false;
    private ref Timer m_PlantDryTime;


	bool IsLocked()
	{
		return m_IsLocked;
	}

	void Lock(float actiontime)
	{	
		m_IsLocked = true;
		m_PlantDryTime.Run(actiontime, this, "Unlock", NULL,false);
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	void Unlock()
	{
		m_IsLocked = false;
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	void Drying()
	{
		m_PlantDryTime = new Timer();
	}

    bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		return false;
    }

    CP_RawCannabisPlant GetRawCannabisPlant()
	{
		return CP_RawCannabisPlant.Cast( GetAttachmentByType(CP_RawCannabisPlant) );
	}

    void Dry()
    {
        if ( IsItemTypeAttached ( CP_RawCannabisPlant ) ) // Checks if plant is attached
        {
            GetInventory().CreateAttachment("CP_DriedCannabisPlant"); // Creates dried plant in output slot.
            float DryTime = ( Math.RandomInt(1,30) );   
            GetGame().ObjectDelete( GetRawCannabisPlant() ); // Deletes RawCannabisPlant after function is started.
            Lock(DryTime); // Locks until process is done. DryTime is the how long it takes before unlocking.
        }
    }

    override string GetPlaceSoundset()
    {
        return "woodenlog_drop_SoundSet";
    }
    
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    }
}
