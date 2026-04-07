class CP_CannabisBud extends AG_CoreClass
{
    string GetcpBag()
	{
        return CP_StrainHelper.GetBagFromBud(GetType());
    }
	
	string GetcpJoint()
	{
		return CP_StrainHelper.GetJointFromBud(GetType());
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
	
};