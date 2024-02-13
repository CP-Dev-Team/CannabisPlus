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
	

	int BatteryRequired;
	int Workbench_Timer_Repeat;
	//int BudsToBagsUsage = GetCPConfig().Buds_To_Bags_Required;
	int BagsToBricksUsage; //GetCPConfig().Bags_To_Bricks_Required;	

	float Battery_Percent;

	float PlaticWrap_Percent;

	// timer to get bagger working
	protected ref Timer m_CP_Processing;
	protected ref Timer m_CP_ProcessingCheck;

	protected bool CP_TimerisRunning;
	protected bool CP_TimerIsPaused;
	
	int m_UseCPWorkbench = 0;
	//Defines a int used for action switching
			
	PlayerBase 		m_Player;
	//defines playerbase to call player
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// constructor of workbench class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void CP_Workbench() 
	{
		RegisterNetSyncVariableBool("CP_TimerisRunning");
		RegisterNetSyncVariableBool("CP_TimerIsPaused");

		if (GetGame() && GetGame().IsServer())
			CP_LoadConfig();
		
		//Gotta wait a little bit to load the config on the clientside while we fetch it from the serverside
		if (GetGame() && GetGame().IsClient())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CP_LoadConfig, 750, false);
		}	
	}
	
	void CP_LoadConfig()
	{
		//See if we gotta wait some more because we haven't received the config yet...
		if (GetGame() && GetGame().IsClient() && !GetCPConfig())
		{	
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CP_LoadConfig, 500, false);	
			return;
		}

		/*//////////////////////////////////////////////////////////////////////////
		//						Start of Config Control                 		  //
		//           	All Config Main Variables ill be put Below       		  //
		//////////////////////////////////////////////////////////////////////////*/
		
		/*                     	   Whole # Config Options                         */
		////////////////////////////////////////////////////////////////////////////
		BatteryRequired = GetCPConfig().RequireBattery;
		Workbench_Timer_Repeat = GetCPConfig().Workbench_Processing_Time;
		//int BudsToBagsUsage = GetCPConfig().Buds_To_Bags_Required;
		BagsToBricksUsage = 16; //GetCPConfig().Bags_To_Bricks_Required;	


		/*					 Percentile Config Options 0% - 100%                  */
		////////////////////////////////////////////////////////////////////////////

		Battery_Percent = GetCPConfig().WorkBench_PowerUsed / 100 * 1500;
	
		PlaticWrap_Percent = GetCPConfig().Plastic_Wrap_Usage;
	
		/*//////////////////////////////////////////////////////////////////////////
		//						  End of Config Control                 		  //
		//           	All Config Main Variables ill be put Above    			  //
		//////////////////////////////////////////////////////////////////////////*/		
	};

	void ~CP_Workbench()
	{
		if ( m_CP_Processing )
			delete m_CP_Processing;
		if (m_CP_ProcessingCheck)
		    delete m_CP_ProcessingCheck;
	};

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (GetGame() && GetGame().IsClient())
			UpdateLockState();
	}
	
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
		if(!CP_TimerIsPaused)	
			return "Pause Production";
		
		return "Resume Production";
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

	void SetTimerIsPaused(bool state)
	{
		CP_TimerIsPaused = state;
		SetSynchDirty();
	}

	void SetTimerIsRunning(bool state)
	{
		CP_TimerisRunning = state;
        SetSynchDirty();
	}

	void StartProcessing()
	{		
		if(m_CP_Processing && m_CP_Processing.IsRunning())
			return;

		//Print("Processing is ongoing.");
		//Print("Is Running not canceled" + m_CP_Processing);
		
		if(!m_CP_Processing)
		{
		   	m_CP_Processing = new Timer;
			m_CP_Processing.Run(Workbench_Timer_Repeat,this,"DoProcessing",NULL,true);
			SetTimerIsRunning(true);
			SetTimerIsPaused(false);
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

	void EndProcessing(float actiontime)
	{

		if (!m_CP_Processing.IsRunning()  && !m_CP_ProcessingCheck)
		{
			m_CP_ProcessingCheck = new Timer;
			m_CP_ProcessingCheck.Run(actiontime,this,"DoTimerProcessingCheck",NULL,false);
			//Print("m_CP_Processing  isnt runing start m_CP_ProcessingCheck = " + m_CP_ProcessingCheck);
		}
		else
		{
		   m_CP_ProcessingCheck.Run(actiontime,this,"DoTimerProcessingCheck",NULL,false);
			//Print("m_CP_ProcessingCheck is existing");
		};
		
    };
		
	void PauseOrResume()
	{
		if(!IsPaused())
		{
			m_CP_Processing.Pause();
			SetTimerIsPaused(true);
			UpdateLockState();
			return;
		}
			
		m_CP_Processing.Continue();
		SetTimerIsPaused(false);
		UpdateLockState();
	};
	
	bool IsRunning()
	{
		return CP_TimerisRunning;
	};

	bool IsPaused()
	{
		return CP_TimerIsPaused;	
	};

	bool IsProcessing()
	{
		return m_CP_Processing && m_CP_Processing.IsRunning();
	}

	bool CanStop()
	{
		return IsRunning();
	};

	void CheckStopProductionCall()
	{
		m_CP_Processing.Stop();
		StopProduction();
	};

	void StopProduction()
	{
		SetTimerIsRunning(false);
		SetTimerIsPaused(false);
		if (m_CP_Processing)
			delete m_CP_Processing;

		UpdateLockState();
		SetSynchDirty();
	};

	void KillProductionCheckTimer()
	{
		m_CP_ProcessingCheck.Stop();
		SetSynchDirty();
	};

	bool HaveEnoughBud()
	{
		return GetCannabisBud() && GetCannabisBud().GetQuantity() > 1;
	}

	bool HaveEnoughEmptyBags()
	{
		return GetEmptyBags() && GetEmptyBags().GetQuantity() > 0;
	}

	bool BaggerRuined()
	{
		return GetBagger().IsRuined();
	}

	bool CanCreateBags()
	{
        if (HaveEnoughBud() && HaveEnoughEmptyBags() && !BaggerRuined() && (!GetCannabisBags() || GetCannabisBags().GetQuantity() < 160))
            return true;
        
        return false;
	};

	bool WrapperRuined()
	{
		return GetWrapper().IsRuined();
	}
	
	bool HaveEnoughFullBags()
	{
		return GetCannabisBags() && GetCannabisBags().GetQuantity() >= 16;
	}

	bool HaveEnoughPlastic()
	{
		return GetPlasticRoll() && GetPlasticRoll().GetQuantity() > 5;
	}

	bool CanCreateBricks()
	{
		if( HaveEnoughFullBags() && HaveEnoughPlastic() && !WrapperRuined() && ( !GetCannabisBricks() || GetCannabisBricks().GetQuantity() < 25 ) )
			return true;
		
		return false;
	};
		
    void DoTimerProcessingCheck()
	{
	  StopProduction();
	  KillProductionCheckTimer();
    };
	
	void DoProcessing()
	{
		Print("BatteryRequired = " + BatteryRequired );
		Print("GetBattieries() = " + GetBattieries() )
		if(BatteryRequired == 1)
		{	
			if(GetBattieries().GetCompEM().GetEnergy() >= Battery_Percent )
			{
				//Print("HaveEnoughFullBags() = " + HaveEnoughFullBags() );
				//Print("HaveEnoughPlastic() = " + HaveEnoughPlastic() );
				//Print("CanCreateBricks() = " + CanCreateBricks() );
				//Print("WrapperRuined() = " + WrapperRuined() );
				Print("Battery power " + GetBattieries().GetCompEM().GetEnergy());
				if(CanCreateBags() == true )
				{
					SetTimerIsRunning(true);
					CreateBags();
					Print("Create bags.");
					//Print("CanCreateBags = true +" + m_CP_Processing);
				}
				else if(CanCreateBricks() == true )
				{
					SetTimerIsRunning(true);
					CreateBricks(); 
					Print("Create bricks.");
					//Print("CanCreateBricks = true +" + m_CP_Processing);
				}
				else
				{
					m_CP_Processing.Stop();
					SetTimerIsRunning(false);
					EndProcessing(1);
					Print("Out of materials.");
					SetSynchDirty();
				}
			}
			else if ( GetBattieries().GetCompEM().GetEnergy() < Battery_Percent )
			{
				m_CP_Processing.Stop();
				SetTimerIsRunning(false);
				EndProcessing(1);
				Print("Out of battery juice.");
				SetSynchDirty();
			}
		}
		else if (BatteryRequired == 0)
		{
			if(CanCreateBags() == true )
			{
				SetTimerIsRunning(true);
				CreateBags();
				//Print("Create bags.");
				//Print("CanCreateBags = true +" + m_CP_Processing);
			}
			else if(CanCreateBricks() == true )
			{
				SetTimerIsRunning(true);
				CreateBricks(); 
				//Print("Create bricks.");
				//Print("CanCreateBricks = true +" + m_CP_Processing);
			}
			else
			{
				m_CP_Processing.Stop();
				SetTimerIsRunning(false);
				EndProcessing(1);
				//Print("Out of materials.");
				SetSynchDirty();
			}
		}
		UpdateLockState();		
		SetSynchDirty();
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
                        Print("Creating " + Bagname + " attachment.");
						GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), false);
                        GetInventory().CreateAttachment(Bagname);
						GetCannabisBags().SetQuantity(1);
                        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), true);
                    }
                    else if (GetCannabisBags() && GetCannabisBags().GetType() == Bagname)
                    {
                        GetCannabisBags().AddQuantity(1); 
                        Print("Adding " + Bagname + "quantity.");
                    }
                    else
                    {
                        Print("Fucking else.");
                        return;
                    }

					Batteries.GetCompEM().AddEnergy( -Battery_Percent );
                    EmptyBags.AddQuantity(-1);
                    CannabisBud.AddQuantity(-2);
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
	
	void LockCPBaggerSlots(bool lock) 
	{
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BUDS), lock);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_EMPTYBAGS), lock);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), lock);
	};

	void LockCPWrapperSlots(bool lock) 
	{
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_PLASTICWRAP), lock);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGS), lock);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BRICKS), lock);
	};

	void LockCPBagger(bool lock)
	{
		ItemBase Bagger = GetBagger();	

		if (!Bagger)
		  

		   
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGGER), false);
            return;
		}
		
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BAGGER), lock);
							 
	
	};

	void LockCPWrapper(bool lock)
	{
		ItemBase Wrapper = GetWrapper();			

		if (!Wrapper )		
		  
  
		   
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_WRAPPER), false);
            return;
		}
		
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_WRAPPER), lock);
							  
	
	};

	void LockCPBattery(bool lock)
	{
		ItemBase Battery = GetBattieries();			

		if (!Battery)	
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BATTERIES), false);
            return;
		}	
		
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(ATTACHMENT_SLOT_BATTERIES), lock);
   
						  
   
	  
   
							  
	
	};
	
	
	bool BaggerOccupied()
	{
		if ( GetBagger() && ( GetEmptyBags() || GetCannabisBud() || GetCannabisBags() ) )
			return true;

		return false;
	};

	bool WrapperOccupied()
	{
		if ( GetWrapper() && ( GetCannabisBags() || GetPlasticRoll() || GetCannabisBricks() )   )
			return true;
			
		return false;
	};

    bool IsBaggerLocked()
    {
		ItemBase Bagger = GetBagger();	
		if(!Bagger)
			return false;

        return Bagger.IsLockedInSlot();
    };

    bool IsWrapperLocked()
    {
		ItemBase Wrapper = GetWrapper();
		if(!Wrapper)
			return false;	
		
    	return Wrapper.IsLockedInSlot();
    };

	void UpdateBaggerSlotLockState()
	{
								
			 
		  

		if ( IsProcessing() )
		{
			if ( !IsBaggerLocked() )
			{
				LockCPBagger(true);
			}
			LockCPBaggerSlots(true);
			LockCPBattery(true);
			//Print("All bagger slots locked.");
		}
		else if ( BaggerOccupied() )
		{
			LockCPBaggerSlots(false);
			LockCPBagger(true);
			LockCPBattery(false);
			//Print("Bagger locked.");
		}
		else
		{
			LockCPBaggerSlots(false);
			LockCPBagger(false);
			LockCPBattery(false);
			//Print("All bagger slots unlocked.");
		};
	}

	void UpdateWrapperSlotLockState()
	{
								  
  
			   
		  

		if ( IsProcessing() )
		{
			if ( !IsWrapperLocked() )
			{
				LockCPWrapper(true);
			}
			LockCPWrapperSlots(true);
			LockCPBattery(true);
			//Print("All wrapper slots locked.");
		}
		else if ( WrapperOccupied() )
		{
			LockCPWrapperSlots(false);
			LockCPWrapper(true);
			//Print("Wrapper locked.");
		}
		else
		{
			LockCPWrapperSlots(false);
			LockCPWrapper(false);
			//Print("All wrapper slots unlocked.");
		}
	}

    void UpdateLockState()
    {
		UpdateBaggerSlotLockState();
		UpdateWrapperSlotLockState();
    };
	
	bool IsPowered()
	{		
		if(BatteryRequired == true && HasEnergyManager() && GetCompEM().IsWorking() )
			return true;
		
		return false;
	};
	
	int GetInPutOccupied()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("BudsBuds"));
		if(thing)
			return 1;
		
		return 0;
	};
	
	int GetOutPutOccupied()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("Bricks"));
		if(thing)
			return 1;
		
		return 0;
	};
	
	bool Wrapper_Attached()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_WRAPPER))
			return true;
		
		return false;
	};

	bool Bagger_Attached()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGGER))
			return true;
		
		return false;
	};
	
	bool Wrapper_Attachments()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_WRAPPER) && FindAttachmentBySlotName(ATTACHMENT_SLOT_BAGS))
			return true;
		
		return false;
	};

	bool Bagger_Attachments()
	{
		if(FindAttachmentBySlotName( ATTACHMENT_SLOT_BAGGER) && FindAttachmentBySlotName(ATTACHMENT_SLOT_EMPTYBAGS))
			return true;
		
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

		if(slot_name != "LargeBattery" || "TruckBattery" )
            return true;
        
        if( BatteryRequired == 1 )
            return true;
        
		return false;
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
		return GetInventory().AttachmentCount() > 0;
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

		if (!GetGame().IsServer())
			return;

		UpdateLockState();
    };

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached( item, slot_name );

		if (!GetGame().IsServer())
			return;

		if (!IsRunning()) 
			UpdateLockState();
	};
	
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