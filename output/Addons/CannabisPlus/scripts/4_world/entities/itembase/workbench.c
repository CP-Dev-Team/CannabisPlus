class CP_Workbench extends Container_Base
{

	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override void SetActions()
    	{
        	super.SetActions();
        
        	AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    	}
}      