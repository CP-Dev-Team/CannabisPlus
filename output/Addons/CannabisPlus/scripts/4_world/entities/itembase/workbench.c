//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 'workbench_kit' represents the item from which the finished workbench can be made.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_Workbench_Kit extends ItemBase 
{
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Event handler that is fired if placement of workbenchkit is complete.
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" ) 
	{		
		super.OnPlacementComplete( player );		
		
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );

			CP_Workbench CPWorkbench = CP_Workbench.Cast( GetGame().CreateObjectEx( "CP_Workbench", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			
			CPWorkbench.SetPosition( position);
			CPWorkbench.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			this.Delete();
			SetIsDeploySound( true );
		}	
	}

	override string GetPlaceSoundset()
	{
		return "seachest_drop_SoundSet";
	}
	
	override bool IsDeployable()
	{
		return true;
	}

	override bool DoPlacingHeightCheck()
	{
		return false;
	}
	override float HeightCheckOverride()
	{
		return 20;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// The workbench class provides all methods for processing and production of the goods.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_Workbench extends ItemBase 
{
	
	const string ATTACHMENT_SLOT_WRAPPER	 	    = "Wrapper";
	const string ATTACHMENT_SLOT_BAGGER	 	        = "Bagger";
	const string ATTACHMENT_SLOT_BATTERIES			= "LargeBattery";
	const string ATTACHMENT_SLOT_PLASTICWRAP		= "CP_PlasticRoll";
	const string ATTACHMENT_SLOT_EMPTYBAGS          = "CP_Empty_Bags";
	const string ATTACHMENT_SLOT_BUDS 				= "CP_Cannabis_Buds";
	const string ATTACHMENT_SLOT_BAGS				= "CP_Cannabis_Bags";
	const string ATTACHMENT_SLOT_BRICKS 			= "CP_Cannabis_Bricks";
	
	/*//////////////////////////////////////////////////////////////////////////
	//						Start of Config Control                 		  //
	//           	All Config Main Variables ill be put Below       		  //
	//////////////////////////////////////////////////////////////////////////*/
	
	/*                     	   Whole # Config Options                         */
	////////////////////////////////////////////////////////////////////////////
		int BatteryRequired = GetCPConfig().RequireBattery;
		int Workbench_Timer_Repeat = GetCPConfig().Workbench_Processing_Time;
		//int BudsToBagsUsage = GetCPConfig().Buds_To_Bags_Required;
		int BagsToBricksUsage = 16; //GetCPConfig().Bags_To_Bricks_Required;	


	/*					 Percentile Config Options 0% - 100%                  */
	////////////////////////////////////////////////////////////////////////////

	
	    float Battery_Percent = GetCPConfig().WorkBench_PowerUsed / 100 * 1500;
	
		float PlaticWrap_Percent = GetCPConfig().Plastic_Wrap_Usage;


	
	/*//////////////////////////////////////////////////////////////////////////
	//						  End of Config Control                 		  //
	//           	All Config Main Variables ill be put Above    			  //
	//////////////////////////////////////////////////////////////////////////*/
	
	// timer to get bagger working
	protected ref Timer m_CP_Processing;
	protected ref Timer m_CP_ProcessingCheck;

	protected bool CP_TimerisRunning;
	protected bool CP_TimerIsPaused;
	protected bool m_CP_BaggerLocked;
	protected bool m_CP_WrapperLocked;
	protected bool m_CP_BatteryLocked;
	protected bool m_CP_BaggerSlotsLocked;
	protected bool m_CP_WrapperSlotsLocked;

	protected bool m_CP_BudSlotOccupied;
    protected bool m_CP_BagSlotOccupied;
    protected bool m_CP_EmptyBagSlotOccupied;
    protected bool m_CP_PlasticWrapSlotOccupied;
    protected bool m_CP_BrickSlotOccupied;
    protected bool m_CP_BatterySlotOccupied;
    protected bool m_CP_BaggerSlotOccupied;
    protected bool m_CP_WrapperSlotOccupied;

	int m_UseCPWorkbench = 0;
	//Defines a int used for action switching
			
	PlayerBase 		m_Player;
	//defines playerbase to call player
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of workbench class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void EEInit()
	{
		super.EEInit();
		//if (GetGame().IsServer())
		//	UpdateLockState();
	}

	void CP_Workbench() 
	{
		RegisterNetSyncVariableBool("CP_TimerisRunning");
		RegisterNetSyncVariableBool("CP_TimerIsPaused");
	};

	void ~CP_Workbench()
	{
		if ( m_CP_Processing )
			delete m_CP_Processing;
		if (m_CP_ProcessingCheck)
		    delete m_CP_ProcessingCheck;
	};
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Start of Step based Variables to change outcome and Text shown for actions. not complicated but very handy
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
		
	CP_CannabisBud GetCannabisBud()
	{
		return CP_CannabisBud.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_BUDS ) );
	};

	CP_CannabisBags GetCannabisBags()
	{
		return CP_CannabisBags.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGS ) );
	};
	
	CP_EmptyBag GetEmptyBags()
	{
		return CP_EmptyBag.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_EMPTYBAGS ) );
	};
	CP_PlasticRoll GetPlasticRoll()
	{
		return CP_PlasticRoll.Cast(FindAttachmentBySlotName(ATTACHMENT_SLOT_PLASTICWRAP) );
	};
	CP_CannabisBrickBase GetCannabisBricks()
	{
		return CP_CannabisBrickBase.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_BRICKS ) );
	};
	VehicleBattery GetBattieries()
	{
		return VehicleBattery.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_BATTERIES ) );
	};
	CP_Bagger GetBagger()
	{
		return CP_Bagger.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGGER ) );
	};
	CP_PlasticWrapper GetWrapper()
	{
		return CP_PlasticWrapper.Cast(FindAttachmentBySlotName( ATTACHMENT_SLOT_WRAPPER ) );
	};	
	
	string GetPauseOrResumeText()
	{
		if(CP_TimerIsPaused == false)
		{		
			return "Pause Production";
		}
		else if(CP_TimerIsPaused == true)
			return "Resume Production";
			
		return "";
		
	};
	
	string GetBagTendancyText()
	{
		if(!GetCannabisBud())
			return "";
		
		string BagName = GetCannabisBud().GetDisplayName();

		
        return "Fill bag with " + BagName;

    };
	
	string GetBrickTendancyText()
	{
		if(!GetCannabisBags())
			return "";
		
		string Brickname = GetCannabisBags().GetDisplayName();

		
        return "Wrap " + Brickname;

    };

	void start_processing()
	{		
		if(m_CP_Processing && m_CP_Processing.IsRunning())
			return;

		//Print("Processing is ongoing.");
		//Print("Is Running not canceled" + m_CP_Processing);
		
		if(!m_CP_Processing)
		{
		   	m_CP_Processing = new Timer;
			m_CP_Processing.Run(Workbench_Timer_Repeat,this,"Do_processing",NULL,true);
			CP_TimerisRunning = true;
			CP_TimerIsPaused = false;
			//UpdateLockState();
			//Print("Processing is started." + m_CP_Processing);

		}

		//f(m_CP_Processing && !m_CP_Processing.IsRunning())
		//
		//	m_CP_Processing.Continue();
		//	CP_TimerisRunning = true;
		//	CP_TimerIsPaused = false;
		//	//UpdateLockState();
		//	//Print("Processing is started.");
		//	//Print(m_CP_Processing);
		//

		UpdateLockState();
	};
	void End_Processing(float actiontime)
	{

		if (!m_CP_Processing.IsRunning()  && !m_CP_ProcessingCheck)
		{
			m_CP_ProcessingCheck = new Timer;
			m_CP_ProcessingCheck.Run(actiontime,this,"Do_Timer_ProcessingCheck",NULL,false);
			//Print("m_CP_Processing  isnt runing start m_CP_ProcessingCheck = " + m_CP_ProcessingCheck);
		}
		else
		{
		   m_CP_ProcessingCheck.Run(actiontime,this,"Do_Timer_ProcessingCheck",NULL,false);
			//Print("m_CP_ProcessingCheck is existing");
		};
		
    };
		
	void PauseOrResume()
	{
		if(CP_TimerIsPaused == false)
		{
			m_CP_Processing.Pause();
			CP_TimerIsPaused = true;
			UpdateLockState();
		}
		else if(CP_TimerIsPaused == true)
		{
			m_CP_Processing.Continue();
			CP_TimerIsPaused = false;
			UpdateLockState();
		}
		Synchronize();	
	};
	
	bool RunningOrNot()
	{
		if(CP_TimerisRunning == true)
		{

		  return true;
		}
		else
		return false;
		Synchronize();	

	};

	bool Pausedornot()
	{
		if(CP_TimerIsPaused == true)
		{

		  return true;
		}
		else
		return false;	
	};

	bool EnabledStop()
	{
		if(CP_TimerisRunning == false)
		{
			return true;
		}
		return false;
	};

	void CheckStopProductionCall()
	{
		m_CP_Processing.Stop();
		StopProduction();
		
	};

	void StopProduction()
	{
		CP_TimerisRunning = false;
		CP_TimerIsPaused = false;
		if (m_CP_Processing) delete m_CP_Processing;
		UpdateLockState();
		Synchronize();

	};
	void KillProductionCheckTimer()
	{
		m_CP_ProcessingCheck.Stop();

		Synchronize();

	};
	bool CanCreateBags()
	{
        if ((GetCannabisBud() && GetCannabisBud().GetQuantity() > 1) && (GetEmptyBags() && GetEmptyBags().GetQuantity() > 0) && (!GetCannabisBags() || GetCannabisBags().GetQuantity() < 160))
        {
            return true;
        }
        else
            return false;
	};
	
	bool CanCreateBricks()
	{
		if((GetCannabisBags() && GetCannabisBags().GetQuantity() >= 16 && GetPlasticRoll() && GetPlasticRoll().GetQuantity() > 5) || (GetCannabisBags() && GetCannabisBags().GetQuantity() >= 16 && GetCannabisBricks().GetQuantity() < 25 && GetPlasticRoll() && GetPlasticRoll().GetQuantity() > 5))
		{
			return true;
		}
		else
			return false;
	};
		
    void Do_Timer_ProcessingCheck()
	{
	  StopProduction();
	  KillProductionCheckTimer();
    };
	
	void Do_processing()
	{
		if( GetGame() && GetGame().IsServer() && BatteryRequired == 1)
		{
			if(GetBattieries().GetCompEM().GetEnergy() > Battery_Percent )
			{
				//Print("Battery Check.");
				if(CanCreateBags() == true )
				{
					CP_TimerisRunning = true;
					CreateBags();
					//Print("Create bags.");
					//Print("CanCreateBags = true +" + m_CP_Processing);
				}
				else if(CanCreateBricks() == true )
				{
					CP_TimerisRunning = true;
					CreateBricks(); 
					//Print("Create bricks.");
					//Print("CanCreateBricks = true +" + m_CP_Processing);
				}
				else
				{
					m_CP_Processing.Stop();
					CP_TimerisRunning == false;
					End_Processing(1);
					//Print("Out of materials.");
					Synchronize();
				}
			}
			else if ( GetBattieries().GetCompEM().GetEnergy() < Battery_Percent )
			{
				m_CP_Processing.Stop();
				End_Processing(1);
				//Print("Out of Battery Juice.");
				Synchronize();
			}
		}
		else if ( GetGame() && GetGame().IsServer() && BatteryRequired == 0 )
		{
			if(CanCreateBags() == true )
			{
				CP_TimerisRunning = true;
				CreateBags();
				//Print("Create bags.");
				//Print("CanCreateBags = true +" + m_CP_Processing);
			}
			else if(CanCreateBricks() == true )
			{
				CP_TimerisRunning = true;
				CreateBricks(); 
				//Print("Create bricks.");
				//Print("CanCreateBricks = true +" + m_CP_Processing);
			}
			else
			{
				m_CP_Processing.Stop();
				CP_TimerisRunning == false;
				End_Processing(1);
				//Print("Out of materials.");
				Synchronize();
			}
		}
		UpdateLockState();
		Synchronize();
	};

    void CreateBags()
    {
        ItemBase CannabisBud = GetCannabisBud();
        ItemBase EmptyBags = GetEmptyBags();
        ItemBase Batteries = GetBattieries();
        
        if(!GetCannabisBud())
            return;
        
        string Bagname = GetCannabisBud().GetcpBag(); 
        
        if (BatteryRequired == 1)
        {
            if (GetBattieries().GetCompEM().GetEnergy() >= Battery_Percent)
            {
                if(GetCannabisBud().GetQuantity() >= 2)
                {        
                    if(!GetCannabisBags())
                    {
                        //Print("Creating attachment.");
						GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), false);
                        GetInventory().CreateAttachment(Bagname);
						GetCannabisBags().SetQuantity(1);
                        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), true);
                    }
                    else if (GetCannabisBags() && GetCannabisBags().GetType() == Bagname)
                    {
                        GetCannabisBags().AddQuantity(1); 
                        //Print("Adding quantity.");
                    }
                    else
                    {
                        //Print("Fucking else.");
                        return;
                    }

                    EmptyBags.AddQuantity(-1);
                    CannabisBud.AddQuantity(-2); 
                    Batteries.GetCompEM().AddEnergy( -Battery_Percent );
                };
            };
        }
        else if(BatteryRequired == 0)
        {
			if(GetCannabisBud().GetQuantity() >= 2)
			{        
				if(!GetCannabisBags())
				{
					//Print("Creating attachment.");
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), false);
					GetInventory().CreateAttachment(Bagname);
					GetCannabisBags().SetQuantity(1);
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), true);
				}
				else if (GetCannabisBags() && GetCannabisBags().GetType() == Bagname)
				{
					GetCannabisBags().AddQuantity(1); 
					//Print("Adding quantity.");
				}
				else
				{
					//Print("Fucking else.");
					return;
				}

				EmptyBags.AddQuantity(-1);
				CannabisBud.AddQuantity(-2); 
			};
        };
    };

	void CreateBricks()
	{
		ItemBase CannabisBag = GetCannabisBags();
		ItemBase PlasticWrap = GetPlasticRoll();
		ItemBase Batteries = GetBattieries();
		
		if(!GetCannabisBags())
			return;
		
		string Brickname = GetCannabisBags().GetcpBrick(); 
		
		if(BatteryRequired == 1)
		{
			if(GetCannabisBags().GetQuantity() >= BagsToBricksUsage && GetPlasticRoll().GetQuantity() >= PlaticWrap_Percent)
			{
				if(!GetCannabisBricks())
				{
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), false);
					GetInventory().CreateAttachment(Brickname);
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), true);
				}
				else if (GetCannabisBricks() && GetCannabisBricks().GetType() == Brickname)
				{
					GetCannabisBricks().AddQuantity(1); 
                    //Print("Adding quantity.");
				}
				else
				{
					return;
				}
        		CannabisBag.AddQuantity(-BagsToBricksUsage);
				PlasticWrap.AddQuantity(-PlaticWrap_Percent);
				Batteries.GetCompEM().AddEnergy( -Battery_Percent );
			};
		}
	    else if(BatteryRequired == 0)
		{
			if(GetCannabisBags().GetQuantity() >= BagsToBricksUsage && GetPlasticRoll().GetQuantity() >= PlaticWrap_Percent)
			{
				if(!GetCannabisBricks())
				{
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), false);
					GetInventory().CreateAttachment(Brickname);
					GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), true);
				}
				else if (GetCannabisBricks() && GetCannabisBricks().GetType() == Brickname)
				{
					GetCannabisBricks().AddQuantity(1); 
				}
				else
				{
					return;
				}
        		CannabisBag.AddQuantity(-BagsToBricksUsage);
				PlasticWrap.AddQuantity(-PlaticWrap_Percent);
			};
		};
	};
	
	void LockCPBaggerSlots(bool do_lock) {
		ItemBase Bagger;
	
		if (Class.CastTo(Bagger, GetBagger()) && do_lock && (m_CP_Processing && ( m_CP_Processing.IsRunning() || !Pausedornot() ) ) ) {
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BUDS), do_lock);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_EMPTYBAGS), do_lock);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), do_lock);
			m_CP_BaggerSlotsLocked = true;
		} else {
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BUDS), false);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_EMPTYBAGS), false);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), false);
			m_CP_BaggerSlotsLocked = false;
		}
		Print("m_CP_BaggerSlotsLocked = "+m_CP_BaggerSlotsLocked);
		Synchronize();
	};

	void LockCPWrapperSlots(bool do_lock) {
		ItemBase Wrapper;
		
		if ( Class.CastTo(Wrapper, GetWrapper()) && do_lock ) {
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_PLASTICWRAP), do_lock);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), do_lock);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), do_lock);
			m_CP_WrapperSlotsLocked = true;

		} else {
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_PLASTICWRAP), false);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), false);
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), false);
			m_CP_WrapperSlotsLocked = false;
		}
		Print("m_CP_WrapperSlotsLocked = "+m_CP_WrapperSlotsLocked);
		Synchronize();
	};

	void LockCPBagger(bool do_lock)
	{
		ItemBase Bagger = GetBagger();	

		if ( Bagger )
		{
			if (do_lock)
			{
				Bagger.LockToParent();
				m_CP_BaggerLocked = true;
			}
			else
			{
				Bagger.UnlockFromParent();
				m_CP_BaggerLocked = false;
			};
			Print("m_CP_BaggerLocked = "+m_CP_BaggerLocked);
			Synchronize();
		};
	};

	void LockCPWrapper(bool do_lock)
	{
		ItemBase Wrapper = GetWrapper();			

		if ( Wrapper )
		{
			if (do_lock)
			{
				Wrapper.LockToParent();
				m_CP_WrapperLocked = true;
			}
			else
			{
				Wrapper.UnlockFromParent();
				m_CP_WrapperLocked = false;
			};
			Print("m_CP_WrapperLocked = "+m_CP_WrapperLocked);
			Synchronize();
		};
	};

	void LockCPBattery(bool do_lock)
	{
		ItemBase Battery = GetBattieries();			

		if ( Battery )
		{
			if (do_lock)
			{
				Battery.LockToParent();
				m_CP_BatteryLocked = true;
			}
			else
			{
				Battery.UnlockFromParent();
				m_CP_BatteryLocked = false;
			};
			Print("m_CP_BatteryLocked = "+m_CP_BatteryLocked);
			Synchronize();
		};
	};
	
	
	bool BaggerOccupied()
	{
		if ( GetBagger() && ( GetEmptyBags() || GetCannabisBud() || GetCannabisBags() ) )
		{
			m_CP_BaggerSlotOccupied = true;
			return true;
		}

		m_CP_BaggerSlotOccupied = false;
		return false;
	}

	bool WrapperOccupied()
	{
		if ( GetWrapper() && ( GetCannabisBags() || GetPlasticRoll() || GetCannabisBricks() )   )
		{
			m_CP_WrapperSlotOccupied = true;
			return true;
		}

		m_CP_WrapperSlotOccupied = false;
		return false;
	}

    bool IsBaggerLocked()
    {
		ItemBase Bagger = GetBagger();		
		
        if ( Bagger && Bagger.IsLockedInSlot() ) {
            return true;
		}
        return false;
    };

    bool IsWrapperLocked()
    {
		ItemBase Wrapper = GetWrapper();		
		
        if ( Wrapper && Wrapper.IsLockedInSlot() ) {
			return true;
		}
        return false;
    };

    void UpdateLockState()
    {
		Print("Starting UpdateLockState()");

		ItemBase Bagger = GetBagger();
		ItemBase Wrapper = GetWrapper();
		m_CP_BaggerSlotOccupied = BaggerOccupied();
		m_CP_WrapperSlotOccupied = WrapperOccupied();

		// If a process timer is running, lock everything
		if ( m_CP_Processing && m_CP_Processing.IsRunning() ) 
		{
			Print("Process timer is running, all slots locked");

			if ( Bagger && !IsBaggerLocked() ) 
			{
				LockCPBagger(true);
			} 
			if ( Wrapper && !IsWrapperLocked() ) 
			{
				LockCPWrapper(true);
			}
			LockCPBaggerSlots(true);
			LockCPWrapperSlots(true);
			LockCPBattery(true);
			Print("All slots locked.");
		} 
		else 
		{
			Print("No process timer so locking based on contents");
			LockCPBaggerSlots(false);
			LockCPWrapperSlots(false);
			LockCPBattery(false);

			// If cannabisBud or cannabisBags or emptyBag are present, lock the bagger
			if ( Bagger && BaggerOccupied() )
				LockCPBagger(true);
			else
				LockCPBagger(false);
			
			// If cannabisBags or plasticRoll or cannabisBrickBase are present, lock the plasticWrapper
			if ( Wrapper && WrapperOccupied() )
				LockCPWrapper(true);
			else
				LockCPWrapper(false);

		}
		Synchronize();
    };
	
	void Synchronize()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	};
	
	bool IsPowered()
	{		
		if( GetGame() && GetGame().IsServer() && BatteryRequired == 1 && HasEnergyManager() && GetCompEM().IsWorking() )
		{
			return true;
		}
		return false;
	};
	
	int GetInPutOccupied()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("BudsBuds"));
		if(thing)
		{
			return 1;
		}
		return 0;
	};
	
	int GetOutPutOccupied()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("Bricks"));
		if(thing)
		{
			return 1;
		}
		return 0;
	};
	
	bool Wrapper_Attached()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_WRAPPER))
		{
			return true;
		}
		return false;
	};
	bool Bagger_Attached()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGGER))
		{
			return true;
		}
		return false;
	};
	
	bool Wrapper_Attachments()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_WRAPPER) && FindAttachmentBySlotName(ATTACHMENT_SLOT_BAGS))
		{
			return true;
		}
		return false;
	};
	bool Bagger_Attachments()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGGER) && FindAttachmentBySlotName(ATTACHMENT_SLOT_EMPTYBAGS))
		{
			return true;
		}
		return false;
	};
	
	override bool CanDisplayAttachmentCategory(string category_name) 
	{	
		if ( category_name == "CP_Machines")
			return true;
		else if ( category_name == "CP_Wrapper" && ( Wrapper_Attached() || ( GetBagger() && GetCannabisBags() ) ) )
			return true;
		else if ( category_name == "CP_Bagger" && Bagger_Attached() )
			return true;
		else
			return false;
    };
	
    override bool CanDisplayAttachmentSlot( int slot_id )
    {
        //if (!super.CanDisplayAttachmentSlot(slot_id))
            //return false;
        int BatteryRequired = GetCPConfig().RequireBattery;
        
        string slot_name = InventorySlots.GetSlotName(slot_id);
        
        if ( GetGame() && GetGame().IsServer() ) {
			if( slot_name == "LargeBattery" ) {
				if( BatteryRequired == 1 ) {
					return true;
					//Print("Battery required");
				} else {
					return false;
					//Print("Battery not required.");
				}
			}
        }
        return true;
    }

	override bool IsElectricAppliance()
	{
		return true;
	};
		 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	// checks if the player can get the workbench into his hands
	// - if any item is in attachment-slots or in cargo, the player can´t get the workbench into his hands
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool CanPutIntoHands(EntityAI parent) 
	{				
		return false;
	};

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	};

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		
	// checks if has not additional items in it
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool IsAnyItemAttached() 
	{		
		if(GetInventory().AttachmentCount() > 0)
		{
			return true;		
		}
		return false;
	};

	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// checks if it has no items in cargo
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool IsCargoEmpty()    
    {        
        if(GetInventory() && GetInventory().GetCargo() && GetInventory().GetCargo().GetItemCount() > 0 )
            return true;        

        return false;
    };

    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item,slot_name);

		Print("Something attached to slot " + slot_name);

        if (!GetGame().IsServer())
            UpdateLockState();
    };

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached( item, slot_name );

		Print("Something detached to slot " + slot_name);
		
        if (!GetGame().IsServer())
        {
            if ( !RunningOrNot() )
                UpdateLockState();
        }

    }
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// determines the actions that the player can perform at the workbench
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	override void SetActions()
	{
		super.SetActions();
		

		AddAction(ActionCPUseBagger);
		AddAction(ActionCPResumeAndPause);
		AddAction(ActionStopCPWorkbench);		
	};

}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// not sure if this class is necessary
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class CP_Workbench_Holo extends ItemBase {
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool CanPutInCargo( EntityAI parent ) {
		return false;
	};
    
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool CanPutIntoHands(EntityAI parent) {
		return false;
	};
}