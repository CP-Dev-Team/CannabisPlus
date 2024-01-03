modded class PlantBase
{	
	private int m_growtime;
	
	private int m_tabacco_growtime;
	private int m_cannabisSkunk_growtime; 
	private int m_cannabisKush_growtime;
	private int m_cannabisBlue_growtime;
	private int m_cannabisStardawg_growtime;
	private int m_cannabisFuture_growtime;
	private int m_cannabisS1_growtime;
	private int m_cannabisNomad_growtime;
	private int m_cannabisBlackFrost_growtime;

	private int m_pepper_growtime;
	private int m_tomato_growtime;
	private int m_zucchini_growtime;
	private int m_pumpkin_growtime;
	private int m_potato_growtime;
	
	private int m_tabacco_cropcount;
	private int m_cannabisSkunk_cropcount;
	private int m_cannabisKush_cropcount;
	private int m_cannabisBlue_cropcount;
	private int m_cannabisStardawg_cropcount;
	private int m_cannabisFuture_cropcount;
	private int m_cannabisS1_cropcount;
	private int m_cannabisNomad_cropcount;
	private int m_cannabisBlackFrost_cropcount;

	private int m_pepper_cropcount;
	private int m_tomato_cropcount;
	private int m_zucchini_cropcount;
	private int m_pumpkin_cropcount;
	private int m_potato_cropcount;

	private int m_spoiltime;
	
	ref Timer m_DeleteDryPlantTimer = NULL;
	
	private GardenBase m_GardenBase = NULL;	
	private PluginHorticulture m_ModuleHorticulture;
	private int currentYield;
	
	void PlantBase()
	{
		
		string plant_type = this.GetType();
		
		m_ModuleHorticulture 	= PluginHorticulture.Cast( GetPlugin( PluginHorticulture ) );		
		m_SprayUsage 			= 5;
		m_DeleteDryPlantTime 	= (60 * 10) + Math.RandomInt(0, 60 * 2);
		m_SpoiledRemoveTime 	= (60 * 20) + Math.RandomInt(0, 60 * 5);
		m_InfestationChance 	= 0.0; 															// Temporarily disabled until its fixed. Infestation is not visualy persistent over server restarts and m_SpoiledRemoveTimer crashes when it's meant to delete the plant.		
		m_GrowthStagesCount 	= GetGame().ConfigGetInt( "cfgVehicles " + plant_type + " Horticulture GrowthStagesCount" );
		//m_CropsCount = GetGame().ConfigGetInt( "cfgVehicles " + plant_type + " Horticulture CropsCount" );
		GetGame().ConfigGetText( "cfgVehicles " + plant_type + " Horticulture CropsType", m_CropsType );

		m_PlantStateIndex 				= -1;
		m_CurrentPlantMaterialQuantity 	= 0;
		m_IsInfested 					= false;
		m_SprayQuantity 				= 0.0;
		m_HasCrops 						= true;
		int currentYield = 1;
	}

	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// destructor of plantbase class
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	void ~PlantBase() {
		
		if (!m_MarkForDeletion) {
			RemovePlant();
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Init( GardenBase garden_base, float fertility, float harvesting_efficiency, float water)
	{	
		private bool isFertilized = false;
		private bool IncreaseCrop = true;
		
		//reads settings from CannabisPlus.json
		m_tabacco_growtime 				= GetCPConfig().tobacco_growtime;
		m_cannabisSkunk_growtime 		= GetCPConfig().cannabisSkunk_growtime;
		m_cannabisKush_growtime 		= GetCPConfig().cannabisKush_growtime;
		m_cannabisBlue_growtime	 		= GetCPConfig().cannabisBlue_growtime;
		m_cannabisStardawg_growtime		= GetCPConfig().cannabisStardawg_growtime;
		m_cannabisFuture_growtime 		= GetCPConfig().cannabisFuture_growtime;
		m_cannabisS1_growtime 			= GetCPConfig().cannabisS1_growtime;
		m_cannabisNomad_growtime 		= GetCPConfig().cannabisNomad_growtime;
		m_cannabisBlackFrost_growtime 	= GetCPConfig().cannabisBlackFrost_growtime;

		m_pepper_growtime 				= GetCPConfig().pepper_growtime;
		m_tomato_growtime 				= GetCPConfig().tomato_growtime;
		m_zucchini_growtime 			= GetCPConfig().zucchini_growtime;
		m_pumpkin_growtime 				= GetCPConfig().pumpkin_growtime;
		m_potato_growtime 				= GetCPConfig().potato_growtime;
	
		m_tabacco_cropcount 			= GetCPConfig().tobacco_cropcount;
		m_cannabisSkunk_cropcount 		= GetCPConfig().cannabisSkunk_cropcount;
		m_cannabisKush_cropcount 		= GetCPConfig().cannabisKush_cropcount;
		m_cannabisBlue_cropcount 		= GetCPConfig().cannabisBlue_cropcount;
		m_cannabisStardawg_cropcount 	= GetCPConfig().cannabisStardawg_cropcount;
		m_cannabisFuture_cropcount 		= GetCPConfig().cannabisFuture_cropcount;
		m_cannabisS1_cropcount 			= GetCPConfig().cannabisS1_cropcount;
		m_cannabisNomad_cropcount 		= GetCPConfig().cannabisNomad_cropcount;
		m_cannabisBlackFrost_cropcount 	= GetCPConfig().cannabisBlackFrost_cropcount;
		
		m_pepper_cropcount 				= GetCPConfig().pepper_cropcount;
		m_tomato_cropcount 				= GetCPConfig().tomato_cropcount;
		m_zucchini_cropcount 			= GetCPConfig().zucchini_cropcount;
		m_pumpkin_cropcount 			= GetCPConfig().pumpkin_cropcount;
		m_potato_cropcount 				= GetCPConfig().potato_cropcount;

		m_spoiltime					= GetCPConfig().spoiltime;

		m_GardenBase = garden_base;
		
		// set fertility from default 1 to 2 if fertility larger then 1 to double income
		if(fertility > 1.0) {
			isFertilized = true;
		}		
		
		//sets growtime and cropcount out of CannabisPlus.json
		switch(this.GetType()){
		    // cannabis skunk
			case "CP_Plant_CannabisSkunk":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisSkunk_growtime;
				currentYield = m_cannabisSkunk_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;
			
			// cannabis blue
			case "CP_Plant_CannabisBlue":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisBlue_growtime;
				currentYield = m_cannabisBlue_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;
			
			// cannabis kush
			case "CP_Plant_CannabisKush":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisKush_growtime;
				currentYield = m_cannabisKush_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;

			// cannabis Stardawg
			case "CP_Plant_CannabisStardawg":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisStardawg_growtime;
				currentYield = m_cannabisStardawg_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;

			// cannabis Future
			case "CP_Plant_CannabisFuture":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisFuture_growtime;
				currentYield = m_cannabisFuture_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;

			// cannabis S1
			case "CP_Plant_CannabisS1":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisS1_growtime;
				currentYield = m_cannabisS1_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;

			// cannabis Nomad
			case "CP_Plant_CannabisNomad":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisNomad_growtime;
				currentYield = m_cannabisNomad_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;

			// cannabis BlackFrost
			case "CP_Plant_CannabisBlackFrost":
				m_PlantMaterialMultiplier = 0;
				m_growtime = m_cannabisBlackFrost_growtime;
				currentYield = m_cannabisBlackFrost_cropcount;
				m_CropsCount = 1;
				IncreaseCrop = false;
				break;
		
			// tobacco
			case "CP_Plant_Tobacco":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_tabacco_growtime;
				m_CropsCount = m_tabacco_cropcount;
				currentYield = 1;
				break;
			
			// deprecated
			case "Plant_Tobacco":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_tabacco_growtime;
				m_CropsCount = m_tabacco_cropcount;
				currentYield = 1;
				break;	
			
			// pepper 
			case "Plant_Pepper":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_pepper_growtime;
				m_CropsCount = m_pepper_cropcount;
				currentYield = 1;
				break;
			
			// tomato
			case "Plant_Tomato":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_tomato_growtime;
				m_CropsCount = m_tomato_cropcount;
				currentYield = 1;
				break;
			
			// zucchini
			case "Plant_Zucchini":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_zucchini_growtime;
				m_CropsCount = m_zucchini_cropcount;
				currentYield = 1;
				break;
			
			// pumpkin
			case "Plant_Pumpkin":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_pumpkin_growtime;
				m_CropsCount = m_pumpkin_cropcount;
				currentYield = 1;
				break;
			
			// potato
			case "Plant_Potato":
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
				m_growtime = m_potato_growtime;
				m_CropsCount = m_potato_cropcount;
				currentYield = 1;
				break;
			
			//not a CP plant, exit function to avoid messing up other plants
			default:
                super.Init( garden_base, fertility, harvesting_efficiency, water);
				return;
		}

		// if the plant is fertilized reduce time that the plant is full-grown
		if(isFertilized) {
			m_FullMaturityTime = (float) ((48 * m_growtime) + Math.RandomInt(0, 30)) / fertility; 
		} else {
			m_FullMaturityTime = (float) ((48 * m_growtime) + Math.RandomInt(0, 30)); 
		}

//		m_SpoilAfterFullMaturityTime 	= (float) ((60 * 30) + Math.RandomInt(0, 60 * 30)) * fertility;		
		m_SpoilAfterFullMaturityTime 	= m_spoiltime * 60;

		m_StateChangeTime 				= (float) ((float)m_FullMaturityTime / ((float)m_GrowthStagesCount - 2.0));

		// if the plant is fertilized double the cropcount
		if(isFertilized) {
			if (IncreaseCrop)
			{
				m_CropsCount = m_CropsCount * harvesting_efficiency * 2;
			}	
			currentYield = currentYield * harvesting_efficiency * 2;
		} else {
			m_CropsCount = m_CropsCount * harvesting_efficiency;
			currentYield = currentYield * harvesting_efficiency;
		}
		
		//moved up so that cannabis plants dont spawn it
		//m_PlantMaterialMultiplier 		= 0.1 * harvesting_efficiency;
		//m_PlantMaterialMultiplier 		= 0;
		
		float rain_intensity = GetGame().GetWeather().GetRain().GetActual();
		
		if ( rain_intensity > 0.0 ) {
			CheckWater();
		}
		else {
			CheckWater();
			
			if ( NeedsWater() )	{
				SetPlantState(STATE_DRY);
				
				if (GetGame().IsServer()) {
					m_DeleteDryPlantTimer = new Timer( CALL_CATEGORY_SYSTEM );
					m_DeleteDryPlantTimer.Run( m_DeleteDryPlantTime, this, "DeleteDryPlantTick", NULL, false );
				}
			}
		}
	}
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		if (GetGame().IsServer() && (!ctx.Read( m_HasCrops ) || !ctx.Read( m_CropsCount ) || !ctx.Read( currentYield ))){
			return false;
		}
		return true;
	}
	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// call the inherited class
		super.OnStoreSave( ctx );
		if(GetGame().IsServer()){
			ctx.Write( m_HasCrops );
			ctx.Write( m_CropsCount );
			ctx.Write( currentYield );
		}
	}
	
	
	private bool harvestingSpamCheck = false;
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	override void Harvest( PlayerBase player )
	{
		if(harvestingSpamCheck==false && m_HasCrops==true){
			harvestingSpamCheck = true;
			for ( int i = 0; i < m_CropsCount; i++ )
			{
				vector pos = player.GetPosition();
				ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( m_CropsType, pos, ECE_PLACE_ON_SURFACE ) );
				item.SetQuantity( item.GetQuantityMax() );
				string ItemName  = item.GetType();
                        
                        if (ItemName.IndexOf("CP_") >= 0)
				{
				      //Print("[CP] harvested " + item);
                        }      
				
				switch(ItemName){
				      // cannabis skunk
					case "CP_RawSkunkCannabisPlant":
						CP_RawSkunkCannabisPlant skunkplant = CP_RawSkunkCannabisPlant.Cast(item);
						if (skunkplant)
						{
							skunkplant.SetYield(currentYield);
							//Print("[CP] setting plant " + skunkplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis blue
					case "CP_RawBlueCannabisPlant":
						CP_RawBlueCannabisPlant blueplant = CP_RawBlueCannabisPlant.Cast(item);
						if (blueplant)
						{
							blueplant.SetYield(currentYield);
							//Print("[CP] setting plant " + blueplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis kush
					case "CP_RawKushCannabisPlant":
						CP_RawKushCannabisPlant kushplant = CP_RawKushCannabisPlant.Cast(item);
						if (kushplant)
						{
							kushplant.SetYield(currentYield);
							//Print("[CP] setting plant " + kushplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis Stardawg
					case "CP_RawStardawgCannabisPlant":
						CP_RawStardawgCannabisPlant stardawgplant = CP_RawStardawgCannabisPlant.Cast(item);
						if (stardawgplant)
						{
							stardawgplant.SetYield(currentYield);
							//Print("[CP] setting plant " + stardawgplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis Future
					case "CP_RawFutureCannabisPlant":
						CP_RawFutureCannabisPlant futureplant = CP_RawFutureCannabisPlant.Cast(item);
						if (futureplant)
						{
							futureplant.SetYield(currentYield);
							//Print("[CP] setting plant " + futureplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis S1
					case "CP_RawS1CannabisPlant":
						CP_RawS1CannabisPlant s1plant = CP_RawS1CannabisPlant.Cast(item);
						if (s1plant)
						{
							s1plant.SetYield(currentYield);
							//Print("[CP] setting plant " + s1plant + " yield to " + currentYield); 
						}	
						break;
					// cannabis Nomad
					case "CP_RawNomadCannabisPlant":
						CP_RawNomadCannabisPlant nomadplant = CP_RawNomadCannabisPlant.Cast(item);
						if (nomadplant)
						{
							nomadplant.SetYield(currentYield);
							//Print("[CP] setting plant " + nomadplant + " yield to " + currentYield); 
						}	
						break;
					// cannabis BlackFrost
					case "CP_RawBlackFrostCannabisPlant":
						CP_RawBlackFrostCannabisPlant bfplant = CP_RawBlackFrostCannabisPlant.Cast(item);
						if (bfplant)
						{
							bfplant.SetYield(currentYield);
							//Print("[CP] setting plant " + bfplant + " yield to " + currentYield); 
						}	
						break;
					default:
                                    //not a CP item, skip out
                                    super.Harvest(player);
						return;
				}
				if ( IsSpoiled() )
				{
					Edible_Base food_item = Edible_Base.Cast( item );
					if ( food_item )
					{
						food_item.ChangeFoodStage( FoodStageType.ROTTEN );
					}
				}
			}
			m_HasCrops = false;
			SetSynchDirty();
			UpdatePlant();
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( clearSpamCheck, 5000, true );
		}	
	}	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void clearSpamCheck(){
		harvestingSpamCheck = false;
	}	
}