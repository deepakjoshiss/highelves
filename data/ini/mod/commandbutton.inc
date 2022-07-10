;------------------------------------------------------------------------------
; mod/commandbutton.inc
;
;Command buttons are buttons that we place on the in game UI to create the
;context sensitive command sets
;------------------------------------------------------------------------------
;;------------------- Added By DJ ---------------------
;;-----------------------------------------------------

CommandButton Command_SpecialAbilityRamBaan
	Command					= SPECIAL_POWER 
	SpecialPower			= SpecialAbilityRamBaan
	TextLabel				= CONTROLBAR:RamBaan
	ButtonImage				= HSHaldirGoldenArrow
	Options                 = NONPRESSABLE
	ButtonBorderType	  	= ACTION 
	DescriptLabel		  	= CONTROLBAR:ToolTipLegolasRamBaan
	InPalantir			  	= Yes	
End

CommandButton Command_SpecialAbilityThranduilRampage
  	Command                 = SPECIAL_POWER 
  	SpecialPower            = SpecialAbilityThranduilRampage
  	TextLabel               = CONTROLBAR:DeadEye
  	ButtonImage             = HSThranduilDeadeye
	Options                 = NONPRESSABLE
  	ButtonBorderType        = ACTION 
  	DescriptLabel           = CONTROLBAR:ToolTipDeadEye
  	InPalantir		= Yes
End

CommandButton Command_ConstructSuperBattleTower
  Command          = DOZER_CONSTRUCT
  Object           = SuperBattleTower
  TextLabel        = CONTROLBAR:ConstructGondolinTower
  ButtonImage      = HSBruchtalTurm
  ButtonBorderType = BUILD 
  DescriptLabel    = OBJECT:GondolinTowerDescription
  Radial           = Yes  
End

CommandButton Command_ConstructNoldorArcherHorde					; Added for BFME2 Expansion
	Command					= UNIT_BUILD
	Object					= NoldorArcherHorde
	Options					= NEED_UPGRADE CANCELABLE
	NeededUpgrade			= Upgrade_ElvenBarracksLevel3
	TextLabel				= CONTROLBAR:ConstructNoldorArcherHorde
	ButtonImage				= BEElvenBarracks_NoldorWarriorsIcon
	ButtonBorderType    	= BUILD 
	DescriptLabel       	= CONTROLBAR:ToolTipBuildNoldorArcherHorde
	Radial					= Yes
	InPalantir				= Yes
	ShowProductionCount		= Yes    
End

CommandButton Command_ConstructElvenGladhrimHorde
	Command					= UNIT_BUILD
	Object					= GaladhrimWarriorHorde
	TextLabel				= CONTROLBAR:ConstructRohanElvenWarriorHorde ;,; CONTROLBAR:ConstructElvenWarriorHorde
	ButtonImage				= UIElven_GaladhrimButton ;,; BEElvenBarracks_LorienWarrior
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildRohanElvenWarriorHorde ;,; CONTROLBAR:ToolTipBuildElvenWarriorHorde
	Radial					= Yes
	InPalantir	   			= Yes
	IsClickable				= Yes
	Options					= CANCELABLE
	ShowProductionCount		= Yes      
End

CommandButton Command_ConstructElvenRivendellKnights
	Command						= UNIT_BUILD
	Object						= RivendellKnightsHorde
	Options						= NEED_UPGRADE CANCELABLE
	NeededUpgrade			= Upgrade_ElvenGreenPastureLevel3
	TextLabel					= CONTROLBAR:BuildElvenRivendellLancers
	ButtonImage				= BEGreenPasture_RivendellLancer
	ButtonBorderType	= BUILD													
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenRivendellLancers
	Radial						= Yes
	InPalantir	   		= Yes
	ShowProductionCount		= Yes
End

CommandButton Command_PurchaseNimrodelWaters
  	Command				= OBJECT_UPGRADE
  	Upgrade				= Upgrade_NimrodelWaters
  	Options				= CANCELABLE
  	TextLabel         	= CONTROLBAR:NimrodelWaters
  	ButtonImage       	= UIBlessedWaters
  	ButtonBorderType  	= UPGRADE
  	DescriptLabel     	= CONTROLBAR:ToolTipNimrodelWaters
  	Radial            	= Yes
  	InPalantir	   		= Yes
End

CommandButton Command_PurchaseUpgradeBloom
   Command           = OBJECT_UPGRADE
   Object            = ElvenMallornTree
   Upgrade           = Upgrade_MallornTreeBloom
   NeededUpgrade	 	 = Upgrade_StructureLevel2
   Options           = NEED_UPGRADE CANCELABLE
   TextLabel         = CONTROLBAR:PurchaseMallornTreeBloom
   ButtonImage       = BEMallornTree ;,; UCCommon_UpgradeStructureNew
   ButtonBorderType	 = BUILD
   DescriptLabel     = CONTROLBAR:ToolTipMallornTreeBloom
   LacksPrerequisiteLabel = CONTROLBAR:ToolTipMallornTreeBloomRequired ;;,;;
   Radial            = Yes
   InPalantir        = Yes
End

CommandButton Command_PurchaseUpgradePurifyngFlames
   Command           = OBJECT_UPGRADE
   Object            = TreeFlet
   Upgrade           = Upgrade_PurifyingFlames
   Options           = CANCELABLE
   TextLabel         = UPGRADE:PurifyingFlames
   ButtonImage       = BILorienFortBanners
   ButtonBorderType	 = BUILD
   DescriptLabel     = UPGRADE:ToolTipPurifyingFlames
   Radial            = Yes
   InPalantir        = Yes
End

;----------------Spell Store Light of the trees--------------------

CommandButton Command_SpellBookLightOfTrees_Rays ;,; 
    Command             = SPECIAL_POWER
    SpecialPower        = SpellBookLightOfTrees_Rays
 End

CommandButton Command_SpellBookLightOfTrees
	Command						= SPELL_BOOK
  SpecialPower			= SpellBookLightOfTrees
  ButtonImage				= SBGood_LightOfTrees
	TextLabel					= CONTROLBAR:LightOfTrees
	DescriptLabel			= CONTROLBAR:ToolTipLightOfTrees
	CommandTrigger    = Command_SpellBookLightOfTrees_Rays
End

CommandButton Command_PurchaseSpellLightOfTrees
	Command						= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
  ButtonImage				= SBGood_LightOfTrees 
  Science						= SCIENCE_LightOfTrees
  TextLabel					= CONTROLBAR:LightOfTrees
	DescriptLabel			= CONTROLBAR:ToolTipLightOfTrees
End

;--------------Spell Store Tree flet--------------------

CommandButton Command_SpellBookSpawnTreeFlet
	Command						= SPELL_BOOK
  SpecialPower			= SpellBookSpawnTreeFlet
	Options         	= NEED_TARGET_POS 
	TextLabel       	= CONTROLBAR:TreeFlet
  ButtonImage				= BILorienFlet
	ButtonBorderType  = ACTION 
	DescriptLabel     = CONTROLBAR:ToolTipTreeFlet
  RadiusCursorType  = MallornGrove
  CursorName        = AttackObj
  InvalidCursorName = GenericInvalid
End

CommandButton Command_PurchaseSpellSpawnTreeFlet
	Command						= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
  ButtonImage				= BILorienFlet 
  Science						= SCIENCE_SpawnLoneTower
  TextLabel					= CONTROLBAR:TreeFlet
	DescriptLabel			= CONTROLBAR:ToolTipTreeFlet
End

;------------Spell Store Waystone-----------------------

CommandButton Command_SpellBookElvenWaystone
	Command						= SPELL_BOOK
  SpecialPower			= SpellBookElvenWaystone
	Options         	= NEED_TARGET_POS 
	TextLabel       	= CONTROLBAR:Waystone
  ButtonImage				= SBWaystone
	ButtonBorderType  = ACTION 
	DescriptLabel     = CONTROLBAR:TooltipWaystone
  RadiusCursorType  = Waystone
  CursorName        = AttackObj
  InvalidCursorName = GenericInvalid
End

CommandButton Command_PurchaseSpellElvenWaystone
	Command						= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
  ButtonImage				= SBWaystone 
  Science						= SCIENCE_ElvenWaystone
  TextLabel					= CONTROLBAR:Waystone
	DescriptLabel			= CONTROLBAR:TooltipWaystone
End

CommandButton Command_SpecialAbilityWaystoneTeleport
	Command			   		= SPECIAL_POWER
	SpecialPower	    = SpecialAbilityWaystoneTeleport
	Options			   		= NEED_TARGET_POS CONTEXTMODE_COMMAND
	TextLabel		   		= CONTROLBAR:WaystoneTeleport
	ButtonImage		   	= SBWaystone
	RadiusCursorType  = WaystoneTeleport ;DominateRadiusCursor
	ButtonBorderType  = ACTION
	DescriptLabel	    = CONTROLBAR:ToolTipWaystoneTeleport
	InPalantir		    = Yes
End

CommandButton Command_SpecialAbilityMirkwoodTrap
  Command               = SPECIAL_POWER
  SpecialPower          = SpecialAbilityMirkwoodTrap
  Options								= NEED_TARGET_POS CONTEXTMODE_COMMAND ;;.;; Added "OK_FOR_MULTI_EXECUTE"
  TextLabel             = CONTROLBAR:MirkwoodTrap
  ButtonImage           = SBMirkwoodTrap
  CursorName						= Bombard
  RadiusCursorType			= MirkwoodTrap ;DoubtRadiusCursor
  InvalidCursorName			= GenericInvalid
  ButtonBorderType      = ACTION 
  DescriptLabel         = CONTROLBAR:TooltipMirkwoodTrap
  InPalantir            = Yes
  AutoAbility						= No ;Yes ;;,;; ;;; No
  ;UnitSpecificSound    = 
End

CommandButton Command_SpecialAbilityPurify
  Command                 = SPECIAL_POWER 
  SpecialPower            = SpecialAbilityPurify
  TextLabel               = CONTROLBAR:WaystonePurify
  ButtonImage             = HSAragornAthelas
  ButtonBorderType        = ACTION 
  DescriptLabel           = CONTROLBAR:ToolTipWaystonePurify
  InPalantir			  			= Yes
  AutoAbility							= No
	UnitSpecificSound				= WaystonePurify
End

;-------------------Spell Store Ring Of Adamant----------------------------
CommandButton Command_SpellBookRingOfAdamant
	Command					= SPELL_BOOK
	Options					= NONPRESSABLE
	TextLabel				= CONTROLBAR:RingOfAdamant
	DescriptLabel		= CONTROLBAR:TooltipRingOfAdamant    
	SpecialPower		= SpellBookRingOfAdamant
  ButtonImage			= SBLorienAdamant
End

CommandButton Command_PurchaseSpellRingOfAdamant
	Command						= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
  ButtonImage				= SBLorienAdamant 
  Science						= SCIENCE_RingOfAdamant
  TextLabel					= CONTROLBAR:RingOfAdamant
	DescriptLabel			= CONTROLBAR:TooltipRingOfAdamant	
  ;;Trigger this command button when the purchase science is activated	
  CommandTrigger		= Command_SpellBookRingOfAdamant
End

;--------------------Tauriel-------------------
CommandButton Command_SpecialAbilityTaurielLeadership
	Options			  	= NONPRESSABLE
	TextLabel			= CONTROLBAR:TaurielLeadership
	ButtonImage			= HIMirkwoodSilvanCaptain
	RadiusCursorType	= TRAINING
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:ToolTipTaurielLeadership
	InPalantir			= Yes
End

CommandButton Command_SpecialAbilityExplodingArrow
	Command                 = SPECIAL_POWER
;;	WeaponSlot              = SECONDARY
	SpecialPower            = SpecialAbilityExplodingArrow
	Options                 = NEED_TARGET_POS
	TextLabel               = CONTROLBAR:ExplodingArrow
	ButtonImage             = HSThranduilThornofVengeance
	CursorName              = Bombard
  	RadiusCursorType        = LightningSwordRadiusCursor
	InvalidCursorName       = GenericInvalid
	ButtonBorderType        = ACTION
	DescriptLabel           = CONTROLBAR:ToolTipExplodingArrow
;;	DisableOnModelCondition = WEAPONSET_TOGGLE_1		
	InPalantir		= Yes
	AutoAbility		= Yes
	;UnitSpecificSound      = FaramirRangerVoiceWoundingArrow
End


