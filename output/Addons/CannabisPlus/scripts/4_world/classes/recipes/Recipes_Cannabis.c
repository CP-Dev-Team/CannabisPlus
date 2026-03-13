class CP_CraftCannabisBag extends RecipeBase
{


    protected string m_cpBags= "";

	override void Init()
	{
		m_Name = "Fill Bag";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 0.25;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 2;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1

		InsertIngredient(0,"CP_CannabisBud");//you can insert multiple ingredients this way
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -2;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1, "AC_EmptyBag");
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here
		//
		//m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		//m_ResultSetQuantity[0] = 1;//-1 = do nothing
		//m_ResultSetHealth[0] = -1;//-1 = do nothing
		//m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		//m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		//m_ResultToInventory[0] >= -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		//m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		//m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		//int BudsToBagsUsage = GetCPConfig().Buds_To_Bags_Required;
	
		//CP_CannabisBud ingredient1 = CP_CannabisBud.Cast(ingredients[0]);
	
		//CP_EmptyBag ingredient2 = CP_EmptyBag.Cast(ingredients[1]);
	
		//if(ingredient1.GetQuantity() >= BudsToBagsUsage)
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		CP_CannabisBud ingredient1 = CP_CannabisBud.Cast(ingredients[0]);		
		//CP_CannabisBags BudsHolder;
		//CP_CannabisBags BudsHolder = Cast(results[0]);
		
		string Bagname = ingredient1.GetcpBag(); 
		
		
		CP_CannabisBags BudsHolder = CP_CannabisBags.Cast(GetGame().CreateObject(Bagname, ingredient1.GetPosition()));
		BudsHolder.SetQuantity(1);
	}
};

class CP_CraftCannabisBrick extends RecipeBase
{	
	protected string m_cpBrick= "";

	override void Init()
	{
		m_Name = "Wrap Brick";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2.25;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 16;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = 25;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1

		InsertIngredient(0,"CP_CannabisBags");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -16;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1, "DuctTape");//you can insert multiple ingredients this way

		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -25;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here
		//
		//m_ResultSetFullQuantity[0] = true;//true = set full quantity, false = do nothing
		//m_ResultSetQuantity[0] = -1;//-1 = do nothing
		//m_ResultSetHealth[0] = -1;//-1 = do nothing
		//m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		//m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		//m_ResultToInventory[0] >= -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		//m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		//m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		int BagsToBricksUsage = 16; //GetCPConfig().Bags_To_Bricks_Required;
	
		CP_CannabisBags ingredient1 = CP_CannabisBags.Cast(ingredients[0]);
	
		if(ingredient1.GetQuantity() >= BagsToBricksUsage)
		{
			return true;
		}
		return false;
		
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		CP_CannabisBags ingredient1 = CP_CannabisBags.Cast(ingredients[0]);
		
		//ItemBase BrickHolder;
		
		string Brickname = ingredient1.GetcpBrick(); 
		
		CP_CannabisBrickBase BrickHolder = CP_CannabisBrickBase.Cast(GetGame().CreateObject(Brickname, ingredient1.GetPosition()));
	}
};
class CP_CraftCigsCannabis extends RecipeBase
{
	protected string m_cpJoint= "";
	
	override void Init()
	{
		m_Name = "Roll Joint";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 0.5;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1

		InsertIngredient(0,"CP_CannabisBud");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -1;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1, "AC_RollingPapers");//you can insert multiple ingredients this way

		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here
		//
		//m_ResultSetFullQuantity[0] = true;//true = set full quantity, false = do nothing
		//m_ResultSetQuantity[0] = -1;//-1 = do nothing
		//m_ResultSetHealth[0] = -1;//-1 = do nothing
		//m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		//m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		//m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		//m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		//m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		CP_CannabisBud ingredient1 = CP_CannabisBud.Cast(ingredients[0]);		
		//ItemBase JointHolder;
		string JointName = ingredient1.GetcpJoint(); 
		
		CP_JointBase JointHolder = CP_JointBase.Cast(GetGame().CreateObject(JointName, ingredient1.GetPosition()));
	}
};

class CP_CraftJointPackEmpty extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Create a pack of joints.";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 0.01;//animation length in relative time units
		m_Specialty = 0;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = 1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1

		InsertIngredient(0,"CP_JointBase");//you can insert multiple ingredients this way
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1, "AC_CigarettePack_Empty");//you can insert multiple ingredients this way
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = true;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here
		//
		//m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		//m_ResultSetQuantity[0] = -1;//-1 = do nothing
		//m_ResultSetHealth[0] = -1;//-1 = do nothing
		//m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		//m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		//m_ResultToInventory[0] = 1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		//m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		//m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase item;
		Class.CastTo(item ,ingredients[1]);
		CP_JointBase joint = CP_JointBase.Cast(ingredients[0]);
		CPDebugPrint("[EmptyPack CanDo] Damage: " + item.GetDamage() + ", jointQty: " + joint.GetQuantity());
		if( item.GetDamage() == 0) {
			return true;
		}
		return false;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		CP_JointBase ingredient1 = CP_JointBase.Cast(ingredients[0]);
		int jointQty = ingredient1.GetQuantity();
		string PackName = ingredient1.GetcpJointPack(); 
		
		CPDebugPrint("[EmptyPack Do] jointQty: " + jointQty + ", PackName: " + PackName);
		
		CP_JointPack PackHolder = CP_JointPack.Cast(GetGame().CreateObject(PackName, ingredient1.GetPosition()));
		int packQty = Math.Min(jointQty, 20);
		if (packQty < 1)
			packQty = 1;
		PackHolder.SetQuantity(packQty);
		
		CPDebugPrint("[EmptyPack Do] Created pack with qty: " + packQty);
	}
};

class CP_CraftJointPack extends RecipeBase
{
	protected int m_SavedJointQty;
	protected int m_SavedPackQty;
	
	override void Init()
	{
		m_Name = "Put joint into pack.";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 0.01;//animation length in relative time units
		m_Specialty = 0;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = 19;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1

		InsertIngredient(0,"CP_JointBase");
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// handled in Do()
		m_IngredientDestroy[0] = false;// handled in Do()
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2

		InsertIngredient(1, "CP_JointPack");
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// handled in Do()
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here

        //m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		//m_ResultSetQuantity[0] = -1;//-1 = do nothing
		//m_ResultSetHealth[0] = -1;//-1 = do nothing
		//m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		//m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		//m_ResultToInventory[0] = 1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		//m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		//m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		CP_JointBase ingredient0 = CP_JointBase.Cast(ingredients[0]);
		CP_JointPack ingredient1 = CP_JointPack.Cast(ingredients[1]);
		
		if(!ingredient0 || !ingredient1)
			return false;

		if (ingredient1.GetQuantity() >= 20)
			return false;
					
		string JointName = ingredient0.GetCpJointName(); 
		string PackName = ingredient1.GetCpPackageName(); 
		
		m_SavedJointQty = ingredient0.GetQuantity();
		m_SavedPackQty = ingredient1.GetQuantity();
		
		CPDebugPrint("[LoadPack CanDo] JointName: " + JointName + ", PackName: " + PackName + ", jointQty: " + m_SavedJointQty + ", packQty: " + m_SavedPackQty);
		
		if(JointName == PackName)
		{
			return true;
		};
		return false;
    }

    override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
    {
        CP_JointBase joint = CP_JointBase.Cast(ingredients[0]);
        CP_JointPack pack = CP_JointPack.Cast(ingredients[1]);

        if (!joint || !pack)
            return;

        // Use saved quantities from CanDo (before engine/recipe modifications)
        int jointQty = m_SavedJointQty;
        int packQty = m_SavedPackQty;
        int currentPackQty = pack.GetQuantity();
        int spaceInPack = 20 - packQty;
        int toTransfer = Math.Min(jointQty, spaceInPack);

        CPDebugPrint("[LoadPack Do] ENTRY - savedJointQty: " + jointQty + ", savedPackQty: " + packQty + ", currentPackQty: " + currentPackQty + ", toTransfer: " + toTransfer);

        if (toTransfer <= 0)
            return;

        // Set absolute target quantity to avoid phantom +1 from engine
        int targetPackQty = packQty + toTransfer;
        pack.SetQuantity(targetPackQty);
        CPDebugPrint("[LoadPack Do] SET pack qty to: " + targetPackQty);

        int remaining = jointQty - toTransfer;
        if (remaining <= 0)
        {
            CPDebugPrint("[LoadPack Do] Deleting joint (no remaining)");
            joint.Delete();
        }
        else
        {
            CPDebugPrint("[LoadPack Do] Setting joint remaining to: " + remaining);
            joint.SetQuantity(remaining);
        }
    }
};