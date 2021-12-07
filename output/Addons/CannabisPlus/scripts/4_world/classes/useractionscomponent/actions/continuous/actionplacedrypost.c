//modded class ActionTogglePlaceObject: ActionSingleUseBase
//{
//    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
//    {    
//        if ( item && item.IsKindOf("CP_DryPost") ) 
//        {
//            Rope theRope; 
//            if ( Class.CastTo(theRope, item.FindAttachmentBySlotName("Rope") ) )
//            {
//                return true;
//            } 
//            else 
//            {
//                return false;
//            }
//        }
//        return super.ActionCondition( player, target, item );
//    }
//}
//
//modded class ActionPlaceObject : ActionDeployObject
//{    
//    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
//    {
//        if ( item && item.IsKindOf("CP_DryPost") ) 
//        {
//            Rope theRope; 
//            if ( Class.CastTo(theRope, item.FindAttachmentBySlotName("Rope") ) )
//            {
//                return true;
//            } 
//            else 
//            {
//                return false;
//            }
//        }
//        return super.ActionCondition( player, target, item );
//    }
//}