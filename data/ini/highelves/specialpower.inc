; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

SpecialPower HESpecialAbilityElrondFarsight
	Enum					= SPECIAL_SPELL_BOOK_PALANTIR_VISION
	ReloadTime				= 80000 ;;,;; 60000
	Flags					= WATER_OK ;;,;; Added for v2.4
	RadiusCursorRadius		= 100 ;,; 75 ;;,;; 250
	InitiateAtLocationSound	= Farsight
End

SpecialPower HESpecialAbilityHawkStrike
	Enum		= SPECIAL_AT_VISIBLE_OBJECT
	ReloadTime		= 24000 ;;,;; 30000
	InitiateSound	= LegolasHawkStrikeArrowShoot		;this plays when he fires, not when he targets
End

SpecialPower HESpecialAbilityThornVengeance
  Enum                = SPECIAL_WOUND_ARROW
  ReloadTime          = 120000 ;180000 ;;,;; 60000 ; in milliseconds
;  RadiusCursorRadius  = 150.0
  InitiateAtLocationSound = GenericSpell
  ;PalantirMovie = PalantirAlert_RohanReinforcements
  ObjectFilter = ALL -BASE_FOUNDATION -INERT -IGNORED_IN_GUI -WALK_ON_TOP_OF_WALL -BLOCKING_GATE -WALL_UPGRADE -UNATTACKABLE -MOVE_ONLY
End

SpecialPower HESpellBookElvenGifts
	Enum				= SPECIAL_SPELL_BOOK_ELVEN_GIFTS
    RequiredSciences			= HESCIENCE_ElvenGifts
    ReloadTime      			= 0 ; in milliseconds
    Flags						= RESPECT_RECHARGE_TIME_DISCOUNT
End

SpecialPower HESpellBookDwarvenRiches
	Enum						= SPECIAL_SPELL_BOOK_DWARVEN_RICHES
	ReloadTime					= SPELL_RECHARGE_TIME_TIER_1 ;,; SPELL_RECHARGE_TIME_TIER_2
	RadiusCursorRadius			= DWARVENRICHES_EFFECT_RADIUS
	RequiredSciences			= HESCIENCE_DwarvenRiches
	InitiateAtLocationSound		= SpellDwarvenRiches1
	Flags						= RESPECT_RECHARGE_TIME_DISCOUNT NEEDS_OBJECT_FILTER 
	ObjectFilter				= INDUSTRY_TYPE_SPELL_OBJECT_FILTER
End

SpecialPower HESpellBookCloudBreak
	Enum             	  = SPECIAL_SPELL_BOOK_DARKNESS
	RequiredSciences  = HESCIENCE_CloudBreak
	ReloadTime       = SPELL_RECHARGE_TIME_TIER_3 ;,; SPELL_RECHARGE_TIME_TIER_2 ;;,;; 450000; SPELL_RECHARGE_TIME_TIER_3   ;RotWK originally 500000	
	InitiateSound    = SpellCloudBreakStereo
	Flags			 = WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT ;,; Added WATER_OK in v5.1
	RadiusCursorRadius    = 120.0 ;,; Added in v5.1
End

SpecialPower HESpecialAbilityGlorfindelStarlight
	Enum						= SPECIAL_HERO_MODE;SPECIAL_GENERAL_TARGETLESS_THREE
	ReloadTime					= 180000;270000 ;;,;; 240000 ;;.;; 120000
	InitiateAtLocationSound		= GlorfindelStarlight
End
