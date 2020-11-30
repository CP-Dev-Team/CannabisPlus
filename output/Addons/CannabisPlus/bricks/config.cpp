class CfgPatches
{
	class CP_Bricks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Containers"
		};
	};
};

class CfgVehicles
{
	class Container_Base;

	/* Skunk */
	class CP_CannabisBrickSkunk: Container_Base
	{	
		scope=2;
		displayName="Brick of Skunk Weed";
		descriptionShort="One pound of Skunk weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_skunk_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* BlueGod */
	class CP_CannabisBrickBlue: Container_Base
	{
		scope=2;
		displayName="Brick of Blue God Weed";
		descriptionShort="One pound of Blue God weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_blue_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	
	/* PurpleKush */
	class CP_CannabisBrickKush: Container_Base
	{	
		scope=2;
		displayName="Brick of Purple Kush Weed";
		descriptionShort="One pound of Purple Kush weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_kush_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* Stardawg */	
	class CP_CannabisBrickStardawg: Container_Base
	{	
		scope=2;
		displayName="Brick of Stardawg Weed";
		descriptionShort="One pound of Stardawg weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_stardawg_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* Future */
	class CP_CannabisBrickFuture: Container_Base
	{	
		scope=2;
		displayName="Brick of Future Weed";
		descriptionShort="One pound of Future weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_future_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* S1 */
	class CP_CannabisBrickS1: Container_Base
	{	
		scope=2;
		displayName="Brick of S1 Hemp";
		descriptionShort="One pound of S1 hemp.  Sponsored by StevesGoods.com";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_s1_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* Nomad */
	class CP_CannabisBrickNomad: Container_Base
	{	
		scope=2;
		displayName="Brick of Nomad Weed";
		descriptionShort="One pound of Nomad weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_nomad_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	/* Black Frost */
	class CP_CannabisBrickBlackFrost: Container_Base
	{	
		scope=2;
		displayName="Brick of Black Frost Weed";
		descriptionShort="One pound of Black Frost weed.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=450;
		itemSize[]={3,3};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"CannabisPlus\bricks\data\cannabis_brick_blackfrost_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CannabisPlus\bricks\data\cannabis_brick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

};
