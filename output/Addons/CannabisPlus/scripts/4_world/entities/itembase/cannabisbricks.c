class CP_CannabisBrickBase extends ItemBase 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCP_RipOpenBrickOrBag);
		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
	string GetCPitemTendancyText()
	{		
        return "UnWrap " + GetDisplayName();
    };
	
};
class CP_CannabisBrickSkunk extends CP_CannabisBrickBase{};

class CP_CannabisBrickBlue extends CP_CannabisBrickBase{};

class CP_CannabisBrickKush extends CP_CannabisBrickBase{};

class CP_CannabisBrickStardawg extends CP_CannabisBrickBase{};

class CP_CannabisBrickFuture extends CP_CannabisBrickBase{};

class CP_CannabisBrickS1 extends CP_CannabisBrickBase{};

class CP_CannabisBrickNomad extends CP_CannabisBrickBase{};

class CP_CannabisBrickBlackFrost extends CP_CannabisBrickBase{};



