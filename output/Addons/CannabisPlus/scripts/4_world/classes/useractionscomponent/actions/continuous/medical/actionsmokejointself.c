class ActionSmokeJointSelfCB : ActionContinuousBaseCB {
	
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(1);
	}	
};

class ActionSmokeJointSelf: ActionContinuousBase {	

	string currentLanguage;	
	private float clhealth;
	private int ReduceAmount=5;
	int jointCycles;

	void ActionSmokeJointSelf()	{
		m_CallbackClass = ActionSmokeJointSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
	}	

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        	CP_JointBase joint;
		Class.CastTo(joint, item);
        	if (joint) {
	            clhealth = joint.GetSynchronizedHealth();
	            return true;
		}	
		return false;
    }	

	override string GetText() {
	string text = "#cp_smoke_joint";
	return text;
    }

	override void OnStartAnimationLoop( ActionData action_data ) {

        CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		
        if (joint) {
			joint.SetSmokingState(ESmokeState.SMOKING);
        };
	  super.OnStartAnimationLoop(action_data);
    }
	
    override void OnEndAnimationLoop( ActionData action_data )
    {
        CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		
        if (joint) {
			joint.SetSmokingState(ESmokeState.INACTIVE);
        };
	  super.OnEndAnimationLoop(action_data);		
    }			

	override void ApplyModifiers( ActionData action_data )
	{
		CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
				
		if (joint) {
			CPDebugPrint("ApplyModifiers cycles " + action_data.m_Player.GetJointCycles() );
			joint.MakeStoned(action_data.m_Player);
			if (action_data.m_Player.GetJointCycles() >= 5)
				joint.MakePuke(action_data.m_Player);
		}	
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		string joint_type = joint.GetType();
		string strainName = joint_type.Substring(8, joint_type.Length() - 8);  // Extracts the name after "CP_Joint"

		if (joint) {
			player.AddValueToJointValue(1, strainName);
			CPDebugPrint("OnFinishProgressClient cycles " + action_data.m_Player.GetJointCycles() );
		}

		super.OnFinishProgressClient(action_data);
	}
	
	override void OnFinishProgressServer(ActionData action_data) {
		CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		
		if (joint) {
			ApplyModifiers(action_data);
			CPDebugPrint("OnFinishProgressServer cycles " + action_data.m_Player.GetJointCycles() );
			
			joint.AddHealth("", "Health", -ReduceAmount);
			
			clhealth = joint.GetHealth();
			CPDebugPrint("Joint has " + clhealth + " health");
			
			joint.SetSynchronizedHealth(clhealth);
			
			if (clhealth <= 0) {
				CPDebugPrint("Deleting Joint");
				//CPApi().Log("Smoked", joint.GetType());
				joint.SetSmokingState(ESmokeState.NOT_SMOKING);
				joint.UpdateParticles();
				joint.Delete();
			}
		}
    }

	override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }
};