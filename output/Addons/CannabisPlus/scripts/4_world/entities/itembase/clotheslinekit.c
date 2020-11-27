class ClotheslineKit extends KitBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			//Create clothesline
			
			Clothesline clothesline = Clothesline.Cast( GetGame().CreateObjectEx( "Clothesline", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			clothesline.SetPosition( position );
			clothesline.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			SetIsDeploySound( true );
		}	
	}
	
	override bool DoPlacingHeightCheck()
	{
		return true;
	}
	
	override float HeightCheckOverride()
	{
		return 2.54;
	}
	
	override void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase stick = ItemBase.Cast(GetGame().CreateObjectEx("WoodenStick",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, stick);
			stick.SetQuantity(2);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}
}
