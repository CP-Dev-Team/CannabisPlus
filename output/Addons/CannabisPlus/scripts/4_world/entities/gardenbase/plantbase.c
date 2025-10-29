modded class PlantBase
{	
	private int m_GrowTime;
	
	private int m_tobacco_growtime;

	private int m_pepper_growtime;
	private int m_tomato_growtime;
	private int m_zucchini_growtime;
	private int m_pumpkin_growtime;
	private int m_potato_growtime;
	
	private int m_tobacco_cropcount;
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
		currentYield = 1;
		m_InfestationChance 	= 0.0; // Temporarily disabled until its fixed. Infestation is not visualy persistent over server restarts and m_SpoiledRemoveTimer crashes when it's meant to delete the plant.		
	}
	
	override void Init(GardenBase garden_base, float fertility, float harvesting_efficiency, float water)
	{   
		private bool isFertilized = false;
		private bool IncreaseCrop = true;

		m_GardenBase = garden_base;
		m_FullMaturityTime = 0;

		string plantType = this.GetType();
		string strainName;
		
		if (plantType.Contains("CP_Plant_Cannabis"))
		{
			strainName = plantType.Substring(17, plantType.Length() - 17); // Extracts the name after "CP_Plant_Cannabis"

			if (g_CannabisStrainConfigs.Contains(strainName))
			{
				// Load the config from the map
				CannabisStrainConfig config = g_CannabisStrainConfigs.Get(strainName);
				m_GrowTime = config.GrowTime;
				currentYield = config.CropCount;
				m_CropsCount = 1;  // Default crop count unless modified
				IncreaseCrop = false;
				m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency; // Set similar to other plants

				CPDebugPrint("Loaded strain config for: " + strainName + " | GrowTime: " + m_GrowTime + " | CropCount: " + currentYield);
			}
			else
			{
				CPDebugPrint("Warning: Strain config for '" + strainName + "' not found. Using default values.");
			}
		}
		else
		{
			CPDebugPrint("Not a CannabisPlus plant type: " + plantType);

			// Non-CannabisPlus plants
			switch (plantType)
			{
				case "CP_Plant_Tobacco":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().tobacco_growtime;
					m_CropsCount = GetCPConfig().tobacco_cropcount;
					currentYield = 1;
					break;

				case "Plant_Pepper":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().pepper_growtime;
					m_CropsCount = GetCPConfig().pepper_cropcount;
					currentYield = 1;
					break;

				case "Plant_Tomato":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().tomato_growtime;
					m_CropsCount = GetCPConfig().tomato_cropcount;
					currentYield = 1;
					break;

				case "Plant_Zucchini":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().zucchini_growtime;
					m_CropsCount = GetCPConfig().zucchini_cropcount;
					currentYield = 1;
					break;

				case "Plant_Pumpkin":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().pumpkin_growtime;
					m_CropsCount = GetCPConfig().pumpkin_cropcount;
					currentYield = 1;
					break;

				case "Plant_Potato":
					m_PlantMaterialMultiplier = 0.1 * harvesting_efficiency;
					m_GrowTime = GetCPConfig().potato_growtime;
					m_CropsCount = GetCPConfig().potato_cropcount;
					currentYield = 1;
					break;

				default:
					super.Init(garden_base, fertility, harvesting_efficiency, water);
					return;
			}
		}

		if (fertility > 1.0)
		{
			isFertilized = true;
		}

		if (plantType.Contains("CP_Plant_Cannabis"))
		{
			float baseTime = m_GrowTime * 60.0; // Assume GrowTime in minutes, convert to seconds
			float randomAdd = Math.RandomFloat(0, 30);
			if (isFertilized)
			{
				m_FullMaturityTime = (baseTime + randomAdd) / fertility;
			}
			else
			{
				m_FullMaturityTime = baseTime + randomAdd;
			}
			CPDebugPrint( "m_GrowTime: " + m_GrowTime + " | Fertility: " + fertility + " | Strain: " + strainName + " | m_FullMaturityTime: " + m_FullMaturityTime );
		}
		else // Not cannabis
		{
			if (isFertilized)
			{
				m_FullMaturityTime = (float)((48 * m_GrowTime) + Math.RandomInt(0, 30)) / fertility;
			}
			else
			{
				m_FullMaturityTime = (float)((48 * m_GrowTime) + Math.RandomInt(0, 30));
			}
		}

		m_SpoilAfterFullMaturityTime = GetCPConfig().spoiltime * 60;
		m_StateChangeTime = (float)((float)m_FullMaturityTime / ((float)m_GrowthStagesCount - 2.0));

		if (isFertilized)
		{
			if (IncreaseCrop)
			{
				m_CropsCount = m_CropsCount * harvesting_efficiency * 2;
			}
			currentYield = currentYield * harvesting_efficiency * 2;
		}
		else
		{
			m_CropsCount = m_CropsCount * harvesting_efficiency;
			currentYield = currentYield * harvesting_efficiency;
		}

		float rain_intensity = GetGame().GetWeather().GetRain().GetActual();

		if (m_PlantState < EPlantState.MATURE && !NeedsWater())
		{
			SetPlantState(EPlantState.GROWING);
			GrowthTimerTick(); 
		}
		
		if (rain_intensity <= 0.0 && NeedsWater())
		{
			SetPlantState(EPlantState.PAUSED);
		}
	}	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		if (GetGame().IsServer() && (!ctx.Read( m_HasCrops ) || !ctx.Read( m_CropsCount ) || !ctx.Read( currentYield ))){
			return false;
		}
		return true;
	}

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
				    	CPDebugPrint("harvested " + item);
                    }      
				
				// Dynamic strain handling for cannabis plants
				if (ItemName.IndexOf("CP_Raw") >= 0 && ItemName.IndexOf("CannabisPlant") >= 0)
				{
					CP_RawPlantBase plant = CP_RawPlantBase.Cast(item);
					if (plant)
					{
						plant.SetYield(currentYield);
						CPDebugPrint("Setting plant " + plant + " yield to " + currentYield);

						// Extract strain from class name (e.g., "Kush" from "CP_RawKushCannabisPlant")
						string strainName = ItemName.Substring(6, ItemName.Length() - 19); // Remove "CP_Raw" (6 chars) and "CannabisPlant" (13 chars)
						plant.SetStrain(strainName);
						CPDebugPrint("Extracted strain: " + strainName + " for plant: " + ItemName);
					}
				}
				else
				{
					// Not a CP item, use super
					super.Harvest(player);
					return;
				}
				if ( m_PlantState == EPlantState.SPOILED )
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
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( clearSpamCheck, 5000, false );
		}	
	}	
	
	void clearSpamCheck(){
		harvestingSpamCheck = false;
	}	
}