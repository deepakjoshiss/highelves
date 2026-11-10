; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

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
	NeededUpgrade			= HEUpgrade_ElvenBarracksLevel3
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
   Object            = HEElvenMallornTree
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
  Science						= HESCIENCE_SpawnLoneTower
  TextLabel					= CONTROLBAR:TreeFlet
	DescriptLabel			= CONTROLBAR:ToolTipTreeFlet
End

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

; ---- Thranduil (hero rework, openbfme/HERO-REWORK-PLAN.md)
CommandButton HECommand_ThranduilRampage1
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilRampage1
	TextLabel				= CONTROLBAR:HEThranduilRampage
	ButtonImage				= HSThranduilDeadeye
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilRampage1
	InPalantir				= Yes
	DisableOnModelCondition = USER_67
End

CommandButton HECommand_ThranduilRampage2
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilRampage2
	TextLabel				= CONTROLBAR:HEThranduilRampage
	ButtonImage				= HSThranduilDeadeye
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilRampage2
	InPalantir				= Yes
	DisableOnModelCondition = USER_67
End

CommandButton HECommand_ThranduilRampage3
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilRampage3
	TextLabel				= CONTROLBAR:HEThranduilRampage
	ButtonImage				= HSThranduilDeadeye
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilRampage3
	InPalantir				= Yes
	DisableOnModelCondition = USER_67
End

CommandButton HECommand_ThranduilRampagePassive
	Command					= SPECIAL_POWER
	SpecialPower			= SpecialAbilityFakeLeadership2
	Options					= NONPRESSABLE
	TextLabel				= CONTROLBAR:HEThranduilRampage
	ButtonImage				= HSThranduilDeadeye
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilRampagePassive
	InPalantir				= Yes
End

CommandButton HECommand_ThranduilWoodlandRealm5
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilWoodlandRealm5
	TextLabel				= CONTROLBAR:HEThranduilWoodlandRealm
	ButtonImage				= WOR_MirkwoodArcher
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilWoodlandRealm5
	InPalantir				= Yes
	DisableOnModelCondition = USER_67
End

CommandButton HECommand_ThranduilWoodlandRealm10
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilWoodlandRealm10
	TextLabel				= CONTROLBAR:HEThranduilWoodlandRealm
	ButtonImage				= WOR_MirkwoodArcher
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilWoodlandRealm10
	InPalantir				= Yes
	DisableOnModelCondition = USER_67
End

CommandButton HECommand_ThranduilPinningShot
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilPinningShot
	Options					= NEED_TARGET_ENEMY_OBJECT
	TextLabel				= CONTROLBAR:HEThranduilPinningShot
	ButtonImage				= HSFaramirWoundingArrow
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilPinningShot
	InPalantir				= Yes
	WeaponSlot				= SECONDARY
	CursorName				= Bombard
	InvalidCursorName		= GenericInvalid
	DisableOnModelCondition = WEAPONSET_TOGGLE_1 USER_67
	AutoAbility				= Yes
End

CommandButton HECommand_ThranduilElvenkingsCommand
	Command					= SPECIAL_POWER
	SpecialPower			= SpecialAbilityFakeLeadership
	Options					= NONPRESSABLE
	TextLabel				= CONTROLBAR:HEThranduilElvenkingsCommand
	ButtonImage				= HSThranduilWildWalk
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilElvenkingsCommand
	InPalantir				= Yes
End

CommandButton HECommand_SpecialAbilityThornofVengeance25
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThornVengeance25
	Options					= NEED_TARGET_ENEMY_OBJECT
	TextLabel				= CONTROLBAR:ThornofVengeance
	ButtonImage				= HSThranduilThornofVengeance
	ButtonBorderType		= ACTION
	DescriptLabel			= CONTROLBAR:ToolTipHEThornofVengeance25
	InPalantir				= Yes
	WeaponSlot				= SECONDARY
	CursorName				= Bombard
	InvalidCursorName		= GenericInvalid
	DisableOnModelCondition = WEAPONSET_TOGGLE_1 USER_67
	AutoAbility				= Yes
End
CommandButton HECommand_ThranduilLeap
	Command					= SPECIAL_POWER
	SpecialPower			= HESpecialAbilityThranduilLeap
	Options					= NEED_TARGET_POS CONTEXTMODE_COMMAND
	TextLabel				= CONTROLBAR:HEThranduilLeap
	ButtonImage				= KUBlinkIcon
	ButtonBorderType		= ACTION
	CursorName				= EvilAbilityObj
	InvalidCursorName		= GenericInvalid
	DescriptLabel			= CONTROLBAR:ToolTipHEThranduilLeap
	InPalantir				= Yes
End
