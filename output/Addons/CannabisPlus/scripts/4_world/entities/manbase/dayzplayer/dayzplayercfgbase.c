/* 
    DayZplayercfgBase
    Added to Register Animations for Items.
*/
modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterOneHanded(pType, pBehavior);

        pType.AddItemInHandsProfileIK("CP_JointSkunk", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointBlue", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointKush", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointStardawg", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointFuture", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointS1", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointNomad", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_JointBlackFrost", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_Cigarette", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CP_Relief_Balm", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/marmalade.anm");
				
		pType.AddItemInHandsProfileIK("CP_CannabisBrickBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/first_aid_kit.anm");
		pType.AddItemInHandsProfileIK("CP_CannabisBags", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/Heatpack.anm");
		pType.AddItemInHandsProfileIK("CP_EmptyBag", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/Heatpack.anm");
    };
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
      super.RegisterHeavy(pType, pBehavior);

     	 pType.AddItemInHandsProfileIK("CP_DryPost", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
	 	 pType.AddItemInHandsProfileIK("CP_DryPost_Kit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
    };
};