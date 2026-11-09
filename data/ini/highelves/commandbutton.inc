; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

CommandButton HECommand_LegolasHawkStrike
  Command                 	= SPECIAL_POWER 
  SpecialPower            	= HESpecialAbilityHawkStrike
  Options                 	= NEED_TARGET_ENEMY_OBJECT ; NEED_TARGET_NEUTRAL_OBJECT CONTEXTMODE_COMMAND
  TextLabel               	= CONTROLBAR:HawkStrike
  ButtonImage             	= HSLegolasHawkStrike
  CursorName              	= Bombard
  InvalidCursorName       	= GenericInvalid
  ButtonBorderType        	= ACTION 
  DescriptLabel           	= CONTROLBAR:ToolTipHawkStrike
  InPalantir			= Yes
  AutoAbility			= Yes
 ; UnitSpecificSound       	= LegolasVoiceModeHawkStrike
  DisableOnModelCondition 	= WEAPONSET_TOGGLE_1 USER_67 ;,; WEAPONLOCK_SECONDARY					; disable if currently using swords
End

CommandButton HECommand_GlorfindelStarlight
	Command			= SPECIAL_POWER
	SpecialPower		= HESpecialAbilityGlorfindelStarlight
	TextLabel		= CONTROLBAR:GlorfindelStarlight
	DescriptLabel		= CONTROLBAR:ToolTipGlorfindelStarlight
	ButtonImage		= HSGlorfindelStarlight
	ButtonBorderType	= ACTION
	InPalantir		= Yes
	AutoAbility		= Yes
	UnitSpecificSound	= GlorfindelStarlight
	DisableOnModelCondition = USER_67 ;,;
End

CommandButton HECommand_SpecialAbilityElrondFarsight
	Command			= SPECIAL_POWER
	SpecialPower		= HESpecialAbilityElrondFarsight
	TextLabel		= CONTROLBAR:ElrondFarsight
	DescriptLabel		= CONTROLBAR:ToolTipElrondFarsight
	ButtonImage		= HSElrondFarSight
	Options			= NEED_TARGET_POS
	ButtonBorderType	= ACTION
	RadiusCursorType    	= FarsightRadiusCursor
	InPalantir		= Yes
	AutoAbility 		= Yes ;;,;;
	DisableOnModelCondition = USER_67 ;,;
End

CommandButton HECommand_SpecialAbilityThornofVengeance
	Command                 = SPECIAL_POWER
	WeaponSlot              = SECONDARY
	SpecialPower            = HESpecialAbilityThornVengeance
	Options                 = NEED_TARGET_ENEMY_OBJECT
	TextLabel               = CONTROLBAR:ThornofVengeance
	ButtonImage             = HSThranduilThornofVengeance
	CursorName              = Bombard
	InvalidCursorName       = GenericInvalid
	ButtonBorderType        = ACTION
	DescriptLabel           = CONTROLBAR:ToolTipThornofVengeance
	DisableOnModelCondition = WEAPONSET_TOGGLE_1 USER_67 ;,;
	InPalantir		= Yes
	AutoAbility		= Yes
	;UnitSpecificSound      = FaramirRangerVoiceWoundingArrow
End

CommandButton HECommand_ConstructElvenEntMoot
  Command          = DOZER_CONSTRUCT
  Object           = HEElvenEntMoot
  TextLabel        = CONTROLBAR:ConstructEntMoot
  ButtonImage      = BEEntMoot
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipElvenEntMoot
  Radial           = Yes  
End

CommandButton HECommand_ConstructElvenFortress ; Command_ConstructElvenFortress building the High Elves fortress: it unpacks bases\hefortress_elves (HEElvenCitadel)
	Command          = DOZER_CONSTRUCT
	Object           = HEElvenFortress
	TextLabel        = CONTROLBAR:ConstructElvenFortress
	ButtonImage      = BEFortress
	ButtonBorderType = BUILD 
	DescriptLabel    = CONTROLBAR:ToolTipConstructElvenFortress
	Radial           = Yes  
End

CommandButton HECommand_ConstructElvenBarracks
	Command          = DOZER_CONSTRUCT
	Object           = HEElvenBarracks
	TextLabel        = CONTROLBAR:ConstructElvenBarracks
	ButtonImage      = BEElvenBarracks
	ButtonBorderType = BUILD 
	DescriptLabel    = CONTROLBAR:ToolTipElvenBarracks
	Radial           = Yes  
End

CommandButton HECommand_PurchaseUpgradeElvenBarracksLevel2
   Command           	= OBJECT_UPGRADE
   Upgrade           	= HEUpgrade_ElvenBarracksLevel2
   Options           	= CANCELABLE
   TextLabel         	= CONTROLBAR:PurchaseUpgradeElvenBarracksLevel2
   ButtonImage       	= UCBuildingLvl2 ;,; UCCommon_UpgradeStructureNew
   ButtonBorderType	= BUILD
   DescriptLabel     	= CONTROLBAR:ToolTipBuildElvenBarracksLevel2   		; Originally CONTROLBAR:ToolTipUpgradeDwarvenBarracksLevel2
   Radial            	= Yes
   InPalantir        	= Yes
End

CommandButton HECommand_PurchaseUpgradeElvenBarracksLevel3
   Command           	= OBJECT_UPGRADE
   Upgrade           	= HEUpgrade_ElvenBarracksLevel3
   Options           	= CANCELABLE
   TextLabel         	= CONTROLBAR:PurchaseUpgradeElvenBarracksLevel3
   ButtonImage      	= UCBuildingLvl3 ;,; UCCommon_UpgradeStructureNew
   ButtonBorderType	= BUILD
   DescriptLabel     	= CONTROLBAR:ToolTipBuildElvenBarracksLevel3
   Radial            	= Yes
   InPalantir        	= Yes
End

CommandButton HECommand_ConstructElvenGreenPasture
  Command          	= DOZER_CONSTRUCT
  Object           	= HEElvenGreenPasture
  TextLabel        	= CONTROLBAR:ConstructElvenStable
  ButtonImage      	= BEGreenPasture
  ButtonBorderType 	= BUILD 
  DescriptLabel    	= CONTROLBAR:ToolTipGreenPasture
  Radial           	= Yes  
End

CommandButton HECommand_ConstructElvenStatue
  Command          = DOZER_CONSTRUCT
  Object           = HEElvenStatue
  TextLabel        = CONTROLBAR:ConstructElvenStatue
  ButtonImage      = BEHeroicStatue
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ConstructHeroicStatue ;,; OBJECT:HeroicStatueDescription
  Radial           = Yes  
End

CommandButton HECommand_ConstructElvenWatchTower
  Command          = DOZER_CONSTRUCT
  Object           = HEElvenBattleTower
  TextLabel        = CONTROLBAR:ConstructElvenBattleTower
  ButtonImage      = BEBattleTower
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipBattleTower
  Radial           = Yes  
End

CommandButton HECommand_ConstructElvenMallornTree
  Command          = DOZER_CONSTRUCT
  Object           = HEElvenMallornTree
  TextLabel        = CONTROLBAR:ConstructElvenMallornTree
  ButtonImage      = BEMallornTree
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipMallornTree
  Radial           = Yes  
End

CommandButton HECommand_ConstructEntTreeBeard
	Command				= UNIT_BUILD
	Object				= HERohanTreeBerd
	Options				= CANCELABLE NEED_UPGRADE
	NeededUpgrade		= Upgrade_ElvenEntMootLevel3 Upgrade_CustomGenericUpgrade2 ;,;Upgrade_CustomGenericUpgrade2 ;,;
	NeededUpgradeAny = Yes ;,;
	TextLabel			= CONTROLBAR:ConstructTreeBeard
	ButtonImage			= TreebeardEntMoot ;,;HITreebeard
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildTreeBeard
	Radial				= Yes
	InPalantir	   		= Yes
	ShowProductionCount		= Yes
;    UnitSpecificSound   = GondorArcherVoiceBuy      
End

CommandButton HECommand_ConstructElvenPorter
	Command				= UNIT_BUILD
	Object				= HEElvenPorter
	Options				= CANCELABLE
	TextLabel			= CONTROLBAR:ConstructElvenPorter
	ButtonImage			= BEFortress_Porter
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipConstructElvenPorter
	Radial				= Yes
	InPalantir			= Yes
	ShowProductionCount		= Yes
End

CommandButton HECommand_ConstructElvenLorienWarriorHorde
	Command				= UNIT_BUILD
	Object				= HEElvenLorienWarriorHorde
	Options				= CANCELABLE
	TextLabel			= CONTROLBAR:ConstructElvenLorienWarriorHorde
	ButtonImage			= BEElvenBarracks_LorienWarrior
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenLorienWarriorHordeWithNoPrerequisites
	Radial				= Yes
	InPalantir	   		= Yes
	ShowProductionCount		= Yes
;    UnitSpecificSound   = GondorArcherVoiceBuy  
;	Options				= NEED_UPGRADE			
;	Upgrade				= Upgrade_StructureLevel2
End

CommandButton HECommand_ConstructElvenLorienArcherHorde
	Command				= UNIT_BUILD
	Object				= HEElvenLorienArcherHorde
	Options				= CANCELABLE
	TextLabel			= CONTROLBAR:ConstructElvenLorienArcherHorde
	ButtonImage			= BEElvenBarracks_LorienArcher
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenLorienArcherHordeWithNoPrerequisites
	Radial				= Yes
	InPalantir	   		= Yes
	ShowProductionCount		= Yes
End

CommandButton HECommand_ConstructNoldorWarriorHorde					; Added for BFME2 Expansion
	Command				= UNIT_BUILD
	Object				= HENoldorWarriorHorde
	Options				= NEED_UPGRADE CANCELABLE
	NeededUpgrade			= HEUpgrade_ElvenBarracksLevel3 Upgrade_CustomGenericUpgrade2 ;,;Upgrade_CustomGenericUpgrade2
	NeededUpgradeAny = Yes ;,;
	TextLabel			= CONTROLBAR:ConstructNoldorWarriorHorde
	ButtonImage			= BEElvenBarracks_NoldorWarriorsIcon
	ButtonBorderType    		= BUILD 
	DescriptLabel       		= CONTROLBAR:ToolTipBuildNoldorWarriorHorde
	Radial				= Yes
	InPalantir			= Yes
	ShowProductionCount		= Yes    
End

CommandButton HECommand_ConstructElvenMithlondSentryHorde
	Command				= UNIT_BUILD
	Object				= HEElvenMithlondSentryHorde
	TextLabel			= CONTROLBAR:ConstructElvenMithlondSentryHorde
	ButtonImage			= BEElvenBarracks_MithlondSentry
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenMithlondSentryHorde
	Radial				= Yes
	InPalantir	   		= Yes
	IsClickable			= Yes
	Options				= CANCELABLE
	ShowProductionCount		= Yes      
End

CommandButton HECommand_ConstructElvenMirkwoodArcherHorde
	Command				= UNIT_BUILD
	Object				= HEElvenMirkwoodArcherHorde
	Options				= NEED_UPGRADE CANCELABLE
	NeededUpgrade			= HEUpgrade_ElvenBarracksLevel2 Upgrade_CustomGenericUpgrade1 ;,;Upgrade_CustomGenericUpgrade1
	NeededUpgradeAny = Yes ;,;
	TextLabel			= CONTROLBAR:ConstructElvenMirkwoodArcherHorde
	ButtonImage			= BEElvenBarracks_MirkwoodArcher
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenMirkwoodArcherHorde
	Radial				= Yes
	InPalantir	   		= Yes
	IsClickable			= Yes
	ShowProductionCount		= Yes    
End

CommandButton HECommand_ConstructElvenRivendellLancers
	Command				= UNIT_BUILD
	Object				= HEElvenRivendellLancerHorde
	Options				= CANCELABLE
	TextLabel			= CONTROLBAR:BuildElvenRivendellLancers
	ButtonImage			= BEGreenPasture_RivendellLancer
	ButtonBorderType		= BUILD													
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenRivendellLancers
	Radial				= Yes
	InPalantir	   		= Yes
	ShowProductionCount		= Yes
End

CommandButton HECommand_SpellBookHeal
	Command = SPELL_BOOK
	TextLabel			= CONTROLBAR:Heal
	Options				= NEED_TARGET_POS ; Huh, you can't have this flag and a radius cursor: CONTEXTMODE_COMMAND
	DescriptLabel		= CONTROLBAR:TooltipHeal    
	SpecialPower		= HESpellBookHeal
    ButtonImage			= SBGood_Heal
	ButtonBorderType	= ACTION 
	RadiusCursorType	= HealRadiusCursor
End

CommandButton HECommand_SpellBookElvenGifts
	Command = SPELL_BOOK
	Options				= NONPRESSABLE
	TextLabel			= CONTROLBAR:ElvenGifts
	DescriptLabel		= CONTROLBAR:TooltipElvenGifts    
	SpecialPower		= HESpellBookElvenGifts
    ButtonImage			= SBGood_ElvenGifts
End

CommandButton HECommand_SpellBookEnshroudingMist
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookEnshroudingMist
    ButtonImage			= SBGood_EnshroudingMist
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:EnshroudingMist
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipEnshroudingMist
	RadiusCursorType    = EnshroudingMistRadiusCursor
End

CommandButton HECommand_SpellBookRallyingCall
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookRallyingCall
    ButtonImage			= SBGood_RallyingCall
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:RallyingCall
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipRallyingCall
	RadiusCursorType    = RallyRadiusCursor
End

CommandButton HECommand_SpellBookTomBombadil
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookTomBombadil
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:SummonTomBombadil
    ButtonImage			= SBGood_TomBombadil
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipSummonTomBombadil
	RadiusCursorType	= TomBombadilRadiusCursor	
End

CommandButton HECommand_SpellBookFarsight
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookFarsight
    ButtonImage			= HSElrondFarSight
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:Farsight
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipFarsight
	RadiusCursorType    = FarsightRadiusCursor
End

CommandButton HECommand_SpellBookRebuild
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookRebuild
    ButtonImage			= SBGood_Rebuild
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:Rebuild
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipRebuild
	RadiusCursorType    = RebuildRadiusCursor
	InvalidCursorName	= GenericInvalid
End

CommandButton HECommand_SpellBookArrowVolleyGood
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookArrowVolleyGood
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:ArrowVolley
    ButtonImage			= SBGood_ArrowVolley
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipArrowVolley
    RadiusCursorType	= ArrowStormRadiusCursor
    CursorName			= AttackObj
    InvalidCursorName	= GenericInvalid
End

CommandButton HECommand_SpellBookElvenWood
	Command				= SPELL_BOOK
	SpecialPower		= HESpellBookElvenWood
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:ElvenWood
	ButtonImage			= SBGood_ElvenWood
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipElvenWood
	RadiusCursorType	= ElvenWoodRadiusCursor
    CursorName          = AttackObj
    InvalidCursorName   = GenericInvalid
End

CommandButton HECommand_SpellBookDwarvenRiches
	Command				= SPELL_BOOK
	SpecialPower		= HESpellBookDwarvenRiches
	Options				= NEED_TARGET_POS
	TextLabel			= CONTROLBAR:DwarvenRiches
	ButtonImage			= SBGood_DwarvenRiches
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipDwarvenRiches
	RadiusCursorType	= DwarvenRichesRadiusCursor
   CursorName          = AttackObj
    InvalidCursorName   = GenericInvalid
End

CommandButton HECommand_SpellBookCloudBreak
	Command				= SPELL_BOOK
	TextLabel			= CONTROLBAR:CloudBreak
	DescriptLabel		= CONTROLBAR:TooltipCloudBreak	
	SpecialPower		= HESpellBookCloudBreak
	ButtonImage		= SBGood_CloudBreak
	DescriptLabel		= CONTROLBAR:TooltipCloudBreak
	CommandTrigger        = Command_SpellBookCloudBreak_Rays ;,; Command_SpellBookCloudBreak_Healing
	DisableOnModelCondition = USER_69 ;,; 
End

CommandButton HECommand_SpellBookEntAllies
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookEntAllies
    ButtonImage			= SBGood_EntAllies
    Options				= NEED_TARGET_POS ; Huh, you can't have this flag and a radius cursor: CONTEXTMODE_COMMAND
	TextLabel			= CONTROLBAR:SummonEntAllies
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipSummonEntAllies
	RadiusCursorType	= EntAlliesRadiusCursor
    CursorName          = AttackObj
    InvalidCursorName   = GenericInvalid
End

CommandButton HECommand_SpellBookEagleAllies
	Command = SPELL_BOOK
    SpecialPower		= HESpellBookEagleAllies
    ButtonImage			= SBGood_EagleAllies
    Options				= NEED_TARGET_POS ; Huh, you can't have this flag and a radius cursor: CONTEXTMODE_COMMAND
	TextLabel			= CONTROLBAR:SummonEagleAllies
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipSummonEagleAllies
	RadiusCursorType	= EagleAlliesRadiusCursor
End

CommandButton HECommand_SpellBookEarthquake
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookEarthquake
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:Earthquake
    ButtonImage			= SBGood_Earthquake
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipEarthquake
    RadiusCursorType	= EarthquakeRadiusCursor
    CursorName			= AttackObj
    InvalidCursorName	= GenericInvalid
     CommandTrigger        = Command_SpellBookEarthquake_Devastation ;,; 
End

CommandButton HECommand_SpellBookFlood
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookFlood
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:Flood
    ButtonImage			= SBGood_Flood
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipFlood
    RadiusCursorType	= FloodRadiusCursor
    CursorName			= AttackObj
    InvalidCursorName	= GenericInvalid
End

CommandButton HECommand_SpellBookSunflare
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookSunflare
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:Sunflare
    ButtonImage			= SBGood_Sunflare
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipSunflare
    RadiusCursorType	= SunflareRadiusCursor
    CursorName			= AttackObj
    InvalidCursorName	= GenericInvalid
End

CommandButton HECommand_SpellBookCitadel
	Command				= SPELL_BOOK
    SpecialPower		= HESpellBookCitadel
	Options				= NEED_TARGET_POS 
	TextLabel			= CONTROLBAR:Citadel
    ButtonImage			= SBGood_Citadel
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipCitadel
    RadiusCursorType	= UndermineRadiusCursor
    CursorName			= AttackObj
    InvalidCursorName	= GenericInvalid
End

CommandButton HECommand_PurchaseSpellHeal
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_Heal 
    Science				= HESCIENCE_Heal
    TextLabel			= CONTROLBAR:Heal
	DescriptLabel		= CONTROLBAR:TooltipHeal
End

CommandButton HECommand_PurchaseSpellElvenGifts
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_ElvenGifts 
    Science				= HESCIENCE_ElvenGifts
    TextLabel			= CONTROLBAR:ElvenGifts
	DescriptLabel		= CONTROLBAR:TooltipElvenGifts
	
	;; Trigger this command button when the purchase science is activated
	CommandTrigger		= HECommand_SpellBookElvenGifts	
End

CommandButton HECommand_PurchaseSpellLoneTower
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= HSLoneTowerSummon ;,; SBGood_LoneTower 
    Science				= HESCIENCE_SpawnLoneTower
    TextLabel			= CONTROLBAR:LoneTower
	DescriptLabel		= CONTROLBAR:ToolTipLoneTower
End

CommandButton HECommand_PurchaseSpellEnshroudingMistMP
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_EnshroudingMist 
    Science				= HESCIENCE_EnshroudingMistMP
    TextLabel			= CONTROLBAR:EnshroudingMist
    DescriptLabel		= CONTROLBAR:TooltipEnshroudingMist
End

CommandButton HECommand_PurchaseSpellEnshroudingMistSP
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_EnshroudingMist 
    Science				= HESCIENCE_EnshroudingMistSP
    TextLabel			= CONTROLBAR:EnshroudingMist
    DescriptLabel		= CONTROLBAR:TooltipEnshroudingMist
End

CommandButton HECommand_PurchaseSpellRallyingCallMP
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_RallyingCall
    Science				= HESCIENCE_RallyingCallMP
    TextLabel			= CONTROLBAR:RallyingCall
    DescriptLabel		= CONTROLBAR:TooltipRallyingCall
End

CommandButton HECommand_PurchaseSpellRallyingCallSP
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_RallyingCall
    Science				= HESCIENCE_RallyingCall
    TextLabel			= CONTROLBAR:RallyingCall
    DescriptLabel		= CONTROLBAR:TooltipRallyingCall
End

CommandButton HECommand_PurchaseSpellTomBombadil
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_TomBombadil 
    Science				= HESCIENCE_TomBombadil
    TextLabel			= CONTROLBAR:SummonTomBombadil
    DescriptLabel		= CONTROLBAR:TooltipSummonTomBombadil
End

CommandButton HECommand_PurchaseSpellFarsight
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= HSElrondFarSight 
    Science				= HESCIENCE_Farsight
    TextLabel			= CONTROLBAR:Farsight
    DescriptLabel		= CONTROLBAR:TooltipFarsight
End

CommandButton HECommand_PurchaseSpellRebuild
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_Rebuild 
    Science				= HESCIENCE_Rebuild
    TextLabel			= CONTROLBAR:Rebuild
	DescriptLabel		= CONTROLBAR:TooltipRebuild
End

CommandButton HECommand_PurchaseSpellArrowVolleyGood
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_ArrowVolley
    Science				= HESCIENCE_ArrowVolleyGood
    TextLabel			= CONTROLBAR:ArrowVolley
	DescriptLabel		= CONTROLBAR:TooltipArrowVolley
End

CommandButton HECommand_PurchaseSpellElvenWood
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_ElvenWood 
    Science				= HESCIENCE_ElvenWood
    TextLabel			= CONTROLBAR:ElvenWood
	DescriptLabel		= CONTROLBAR:TooltipElvenWood
End

CommandButton HECommand_PurchaseSpellDwarvenRiches
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_DwarvenRiches
    Science				= HESCIENCE_DwarvenRiches
    TextLabel			= CONTROLBAR:DwarvenRiches
	DescriptLabel		= CONTROLBAR:TooltipDwarvenRiches	
	CommandTrigger		= HECommand_SpellBookDwarvenRiches ;;,;; added for 2.02e
End

CommandButton HECommand_PurchaseSpellMenOfDaleAllies
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= BDArcheryRange_MenofDale
    Science				= HESCIENCE_MenOfDaleAllies
    TextLabel			= CONTROLBAR:MenOfDaleAllies
	DescriptLabel		= CONTROLBAR:TooltipMenOfDaleAllies
End

CommandButton HECommand_PurchaseSpellCloudBreak
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_CloudBreak 
    Science				= HESCIENCE_CloudBreak
    TextLabel			= CONTROLBAR:CloudBreak
	DescriptLabel		= CONTROLBAR:TooltipCloudBreak
End

CommandButton HECommand_PurchaseSpellDunedainAllies
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_SummonDunedain
    Science				= HESCIENCE_DunedainAllies
    TextLabel			= CONTROLBAR:SummonDunedainAllies
	DescriptLabel		= CONTROLBAR:TooltipSummonDunedainAllies
End

CommandButton HECommand_PurchaseSpellEntAllies
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_EntAllies 
    Science				= HESCIENCE_EntAllies
    TextLabel			= CONTROLBAR:SummonEntAllies
	DescriptLabel		= CONTROLBAR:TooltipSummonEntAllies
End

CommandButton HECommand_PurchaseSpellEagleAllies
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_EagleAllies 
    Science				= HESCIENCE_EagleAllies
    TextLabel			= CONTROLBAR:SummonEagleAllies
	DescriptLabel		= CONTROLBAR:TooltipSummonEagleAllies
End

CommandButton HECommand_PurchaseSpellUndermine
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_Undermine 
    Science				= HESCIENCE_Undermine
    TextLabel			= CONTROLBAR:Undermine
	DescriptLabel		= CONTROLBAR:TooltipUndermine
End

CommandButton HECommand_PurchaseSpellBombard
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_Bombard 
    Science				= HESCIENCE_Bombard
    TextLabel			= CONTROLBAR:Bombard
	DescriptLabel		= CONTROLBAR:TooltipSpellBarrage ;,; CONTROLBAR:TooltipBombard
End

CommandButton HECommand_PurchaseSpellEarthquake
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= SBGood_Earthquake
    Science				= HESCIENCE_Earthquake
    TextLabel			= CONTROLBAR:Earthquake
	DescriptLabel		= CONTROLBAR:TooltipEarthquake
End

CommandButton HECommand_PurchaseSpellFlood
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_Flood
    Science				= HESCIENCE_Flood
    TextLabel			= CONTROLBAR:Flood
	DescriptLabel		= CONTROLBAR:TooltipFlood
End

CommandButton HECommand_PurchaseSpellSunflare
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_Sunflare
    Science				= HESCIENCE_Sunflare
    TextLabel			= CONTROLBAR:Sunflare
	DescriptLabel		= CONTROLBAR:TooltipSunflare
End

CommandButton HECommand_PurchaseSpellCitadel
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE
    ButtonImage			= SBGood_Citadel
    Science				= HESCIENCE_Citadel
    TextLabel			= CONTROLBAR:Citadel
	DescriptLabel		= CONTROLBAR:TooltipCitadel
End

CommandButton Command_PurchaseUpgradeElvenHeavyArmorTier4
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_HeavyArmorTier4
	NeededUpgrade		= Upgrade_TechnologyElvenHeavyArmor
	TextLabel			= CONTROLBAR:PurchaseUpgradeElvenHeavyArmor
	ButtonImage			= BEEregionForge_ElvenArmor
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeElvenHeavyArmor
	InPalantir	   		= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackElvenHeavyArmor
End

CommandButton Command_PurchaseUpgradeElvenBasicTrainingTier3 ;,;
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_BasicTrainingTier3
	NeededUpgrade		= Upgrade_TechnologyElvenBasicTraining
	TextLabel			= CONTROLBAR:PurchaseUpgradeElderRacesBasicTraining
	ButtonImage			= BEEregionForge_BannerCarrier
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeElderRacesBasicTraining
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackElderRacesBasicTraining
End

CommandButton Command_PurchaseUpgradeElvenForgedBladesTier2
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_ForgedBladesTier2
	NeededUpgrade		= Upgrade_TechnologyElvenForgedBlades
	TextLabel			= CONTROLBAR:PurchaseUpgradeElvenForgedBlades
	ButtonImage			= BEEregionForge_ForgedBlades
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeElvenForgedBlades
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackElvenForgedBlades
End

CommandButton Command_PurchaseUpgradeElvenForgedBladesTier4
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_ForgedBladesTier4
	NeededUpgrade		= Upgrade_TechnologyElvenForgedBlades
	TextLabel			= CONTROLBAR:PurchaseUpgradeElvenForgedBlades
	ButtonImage			= BEEregionForge_ForgedBlades
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeElvenForgedBlades
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackElvenForgedBlades
End

; ---- PROTOTYPE: Hero Armory (fortress pages)
CommandButton HECommand_HEArmoryOpen
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryOpen
  TextLabel        = CONTROLBAR:HEArmory
  ButtonImage      = HIThranduilCrown
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipHEArmory
  Radial           = Yes
End
CommandButton HECommand_HEArmoryLegolas
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryOpenLegolas
  TextLabel        = CONTROLBAR:HEArmoryLegolas
  ButtonImage      = HILegolas
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipHEArmoryHero
  Radial           = Yes
End
CommandButton HECommand_HEArmoryThranduil
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryOpenThranduil
  TextLabel        = CONTROLBAR:HEArmoryThranduil
  ButtonImage      = HIThranduil
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipHEArmoryHero
  Radial           = Yes
End
CommandButton HECommand_HEArmoryElrond
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryOpenElrond
  TextLabel        = CONTROLBAR:HEArmoryElrond
  ButtonImage      = HIElrond
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipHEArmoryHero
  Radial           = Yes
End
CommandButton HECommand_HEArmoryBackHero
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryBackHero
  TextLabel        = CONTROLBAR:RadialBack
  ButtonImage      = UCCommon_BackArrow
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipCommandRadialBack
  Radial           = Yes
End
CommandButton HECommand_HEArmoryBack
  Command          = SPECIAL_POWER
  SpecialPower     = HEArmoryBack
  TextLabel        = CONTROLBAR:RadialBack
  ButtonImage      = UCCommon_BackArrow
  ButtonBorderType = SYSTEM
  DescriptLabel    = CONTROLBAR:ToolTipCommandRadialBack
  Radial           = Yes
End
CommandButton HECommand_SelectUpgradesElvenFortress
  Command           = PUSH_VISIBLE_COMMAND_RANGE
  TextLabel         = CONTROLBAR:SelectUpgradesElvenFortress
  ButtonImage       = UCCommon_UpgradeStructureNew
  ButtonBorderType  = SYSTEM
  DescriptLabel     = CONTROLBAR:ToolTipCommandSelectUpgradesElvenFortress
  Radial            = Yes
  CommandRangeStart = 7
  CommandRangeCount = 8
End
CommandButton HECommand_SelectRevivablesElvenFortress
  Command           = PUSH_VISIBLE_COMMAND_RANGE
  TextLabel         = CONTROLBAR:SelectRevivablesElvenFortress
  ButtonImage       = UCCommon_GoodHeroes
  ButtonBorderType  = SYSTEM
  DescriptLabel     = CONTROLBAR:ToolTipCommandSelectRevivablesElvenFortress
  Radial            = Yes
  CommandRangeStart = 15
  CommandRangeCount = 10
End
