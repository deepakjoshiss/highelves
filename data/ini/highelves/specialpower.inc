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

SpecialPower HESpellBookHeal
	InitiateAtLocationSound 	= SpellHeal
	Enum                		= SPECIAL_SPELL_BOOK_HEAL
	Flags				= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	ReloadTime         		= SPELL_RECHARGE_TIME_TIER_1
	RequiredSciences     		= HESCIENCE_Heal
	RadiusCursorRadius  		= SPELL_HEAL_RADIUS_CURSOR	
End

SpecialPower HESpellBookSpawnLoneTower
	Enum				= SPECIAL_SPELL_BOOK_SPAWN_LONE_TOWER
	RadiusCursorRadius		= SPAWN_LONE_TOWER_DECAL_RADIUS
	RequiredSciences			= HESCIENCE_SpawnLoneTower
	ReloadTime			= SPELL_RECHARGE_TIME_TIER_2 ;,; SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_1 ; in milliseconds
	InitiateAtLocationSound		= SpellSpawnLoneTower
	ViewObjectDuration		= 10000
	ViewObjectRange			= 200
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_STRUCTURE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= SPAWN_LONE_TOWER_DECAL_RADIUS
End

SpecialPower HESpellBookSpawnLoneTowerDwarf
	Enum					= SPECIAL_SPELL_BOOK_SPAWN_LONE_TOWER
	RadiusCursorRadius		= SPAWN_LONE_TOWER_DECAL_RADIUS
	RequiredSciences		= HESCIENCE_SpawnLoneTower
	ReloadTime				= SPELL_RECHARGE_TIME_TIER_2 ;,; SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_1 ; in milliseconds
	InitiateAtLocationSound	= SpellSpawnLoneTower
	ViewObjectDuration		= 10000
	ViewObjectRange			= 200
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_STRUCTURE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= SPAWN_LONE_TOWER_DECAL_RADIUS
End

SpecialPower HESpellBookFarsight
	Enum				= SPECIAL_SPELL_BOOK_PALANTIR_VISION
	Flags				= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	ReloadTime			= SPELL_RECHARGE_TIME_TIER_5 ;,; SPELL_RECHARGE_TIME_TIER_6 ; in milliseconds
	RadiusCursorRadius		= 100.0 ;,; 75.0 ;;,;; 300.0
	RequiredSciences			= HESCIENCE_Farsight
	InitiateAtLocationSound	= SpellFarsight
End

SpecialPower HESpellBookRallyingCall
	Enum				= SPECIAL_SPELL_BOOK_RALLYING_CALL
	ReloadTime			= SPELL_RECHARGE_TIME_TIER_1 ; in milliseconds
	RadiusCursorRadius		= 125.0 ;,; 100.0 ;,; 75.0
	Flags					= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	RequiredSciences			= HESCIENCE_RallyingCall HESCIENCE_RallyingCallMP
	InitiateAtLocationSound 	= SpellRallyingCallMS
End

SpecialPower HESpellBookTomBombadil
	Enum				= SPECIAL_SPELL_BOOK_TOM_BOMBADIL
	ReloadTime			= SPELL_RECHARGE_TIME_TIER_2
	RadiusCursorRadius		= 15.0
	RequiredSciences			= HESCIENCE_TomBombadil
	InitiateAtLocationSound 	= SpellSummonTomBombadilMS	;SpellPalantirVision
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 15.0
End

SpecialPower HESpellBookHobbitAllies
	Enum					= SPECIAL_SPELL_BOOK_HOBBIT_ALLIES
	RequiredSciences		= HESCIENCE_HobbitAllies
	ReloadTime				= SPELL_RECHARGE_TIME_TIER_2
	InitiateAtLocationSound	= SpellSummonHobbitsMS
	RadiusCursorRadius		= 100.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

SpecialPower HESpellBookRebuild
	Enum					= SPECIAL_SPELL_BOOK_REBUILD
	Flags					= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	ReloadTime				= SPELL_RECHARGE_TIME_TIER_6 ;;,;; 240000				; RotWK originally SPELL_RECHARGE_TIME_TIER_2
	RadiusCursorRadius		= SPELL_REBUILD_RADIUS_CURSOR
	RequiredSciences		= HESCIENCE_Rebuild
	InitiateAtLocationSound = SpellRebuild
End

SpecialPower HESpellBookArrowVolleyGood
	Enum				= SPECIAL_SPELL_BOOK_ARROW_VOLLEY_GOOD
	RadiusCursorRadius		= GOOD_VOLLEY_ARROW_RADIUS_CURSOR ;,; 95
	RequiredSciences			= HESCIENCE_ArrowVolleyGood
	ReloadTime			= SPELL_RECHARGE_TIME_TIER_6 ;,; SPELL_RECHARGE_TIME_TIER_7 ;,; SPELL_RECHARGE_TIME_TIER_6 ;,;SPELL_RECHARGE_TIME_TIER_2
	InitiateAtLocationSound		= SpellArrowVolleyMS
	ViewObjectDuration		= 10000
	ViewObjectRange			= 200
	Flags					= RESPECT_RECHARGE_TIME_DISCOUNT WATER_OK ;,; Added WATER_OK
End

SpecialPower HESpellBookEnshroudingMist
	Enum					= SPECIAL_SPELL_BOOK_ENSHROUDING_MIST
	ReloadTime				= SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_2
	Flags					= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	RadiusCursorRadius		= ENSHROUDING_MIST_EFFECT_RADIUS
	RequiredSciences		= HESCIENCE_EnshroudingMistMP HESCIENCE_EnshroudingMistSP
	InitiateAtLocationSound = SpellEnshroudingMist
End

SpecialPower HESpellBookElvenWood
	Enum				= SPECIAL_SPELL_BOOK_ELVEN_WOOD
	RadiusCursorRadius		= SPELLBOOK_TAINT_RADIUS		; Match the radius in FXList ElvenWood
	RequiredSciences			= HESCIENCE_ElvenWood
	ReloadTime      		= SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_1 ;;.;; SPELL_RECHARGE_TIME_TIER_2
	InitiateAtLocationSound 	= SpellElvenWood
	ViewObjectDuration 		= 5000
	ViewObjectRange 		= SPELLBOOK_TAINT_RADIUS ;;,;; 175
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT WATER_OK ;,; Added WATER_OK
	ForbiddenObjectFilter	= NONE +WatcherHead +WatcherHittingArm +WatcherCaldera +InvisibleElvenWoodObject +InvisibleTaintObject ;,; Added +InvisibleElvenWoodObject +InvisibleTaintObject
	ForbiddenObjectRange	= SPELLBOOK_TAINT_RADIUS
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

SpecialPower HESpellBookUndermine
	Enum             		= SPECIAL_SPELL_BOOK_ELVEN_WOOD ;,;SPECIAL_SPELL_BOOK_UNDERMINE
	RequiredSciences  		= HESCIENCE_Undermine
	ReloadTime       		= SPELL_RECHARGE_TIME_TIER_2   ; in milliseconds
	RadiusCursorRadius		= SPAWN_UNDERMINE_DECAL_RADIUS ;;,;; commented out 95.0 from the end
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_UNDERMINE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 300 ;,;UNDERMINE_FORBIDDEN_OBJECT_RADIUS ;,;SPAWN_UNDERMINE_DECAL_RADIUS
	InitiateAtLocationSound = SpellUndermine
End

SpecialPower HESpellBookMenOfDaleAllies
	Enum						= SPECIAL_SPELL_BOOK_MEN_OF_DALE_ALLIES
	RequiredSciences				= HESCIENCE_MenOfDaleAllies
	ReloadTime					= SPELL_RECHARGE_TIME_TIER_3 ;,; SPELL_RECHARGE_TIME_TIER_2 ; in milliseconds
	InitiateAtLocationSound			= SpellSummonDunedainAllies
	RadiusCursorRadius			= 100.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

SpecialPower HESpellBookCloudBreak
	Enum             	  = SPECIAL_SPELL_BOOK_DARKNESS
	RequiredSciences  = HESCIENCE_CloudBreak
	ReloadTime       = SPELL_RECHARGE_TIME_TIER_3 ;,; SPELL_RECHARGE_TIME_TIER_2 ;;,;; 450000; SPELL_RECHARGE_TIME_TIER_3   ;RotWK originally 500000	
	InitiateSound    = SpellCloudBreakStereo
	Flags			 = WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT ;,; Added WATER_OK in v5.1
	RadiusCursorRadius    = 120.0 ;,; Added in v5.1
End

SpecialPower HESpellBookRohanAllies
	Enum			= SPECIAL_SPELL_BOOK_ROHAN_ALLIES
	RequiredSciences		= HESCIENCE_RohanAllies
	ReloadTime      	= SPELL_RECHARGE_TIME_TIER_3 ; in milliseconds
	InitiateAtLocationSound = SpellRohirrimSummonMS
	RadiusCursorRadius	= 110.0 ;150.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 110.0
End

SpecialPower HESpellBookEntAllies
	Enum			= SPECIAL_SPELL_BOOK_ENT_ALLIES
	RequiredSciences		= HESCIENCE_EntAllies
	ReloadTime      	= SPELL_RECHARGE_TIME_TIER_3 ; in milliseconds
	InitiateAtLocationSound = SpellEntsSummon
	RadiusCursorRadius	= 100.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

SpecialPower HESpellBookEagleAllies
	Enum			= SPECIAL_SPELL_BOOK_EAGLE_ALLIES
	Flags					= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	RequiredSciences		= HESCIENCE_EagleAllies
	ReloadTime      	= SPELL_RECHARGE_TIME_TIER_3 ; in milliseconds
	InitiateAtLocationSound = SpellEagleAlliesSummon	;EagleVoiceSelect
	RadiusCursorRadius	= 100.0
End

SpecialPower HESpellBookDunedainAllies
	Enum			= SPECIAL_SPELL_BOOK_DUNEDAIN_ALLIES
	RequiredSciences		= HESCIENCE_DunedainAllies
	ReloadTime		= SPELL_RECHARGE_TIME_TIER_3 ; in milliseconds
	InitiateAtLocationSound	= SpellSummonDunedainAllies
	RadiusCursorRadius	= 100.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

SpecialPower HESpellBookBombard
	Enum					= SPECIAL_SPELL_BOOK_BOMBARD
	Flags					= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	RadiusCursorRadius		= 200
	RequiredSciences  		= HESCIENCE_Bombard
	ReloadTime       		= SPELL_RECHARGE_TIME_TIER_3
	InitiateAtLocationSound	= SpellBarrageStartMS
End

SpecialPower HESpellBookArmyoftheDead
	Enum			= SPECIAL_SPELL_BOOK_ARMY_OF_THE_DEAD
	RequiredSciences		= HESCIENCE_ArmyoftheDead
	ReloadTime      	= SPELL_RECHARGE_TIME_TIER_4 ; in milliseconds
	InitiateAtLocationSound = ArmyDeadEnterMS ;,; ArmyDeadEnterMono		;ArmyDeadEnterStereo	
	RadiusCursorRadius	= 200.0  
	ViewObjectDuration	= 5000
	ViewObjectRange		= 150
	Flags					= RESPECT_RECHARGE_TIME_DISCOUNT ;,; NO_FORBIDDEN_OBJECTS
	;,; ForbiddenObjectFilter	= NO_SUMMON_UNDERMINE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 200.0
End

SpecialPower HESpellBookEarthquake
	Enum					= SPECIAL_SPELL_BOOK_EARTHQUAKE
	RadiusCursorRadius		= 300
	RequiredSciences		= HESCIENCE_Earthquake
	ReloadTime				= SPELL_RECHARGE_TIME_TIER_4 ; in milliseconds
	InitiateAtLocationSound	= SpellEarthquakeMS
	ViewObjectDuration		= 10000
	ViewObjectRange			= 200
	Flags					= RESPECT_RECHARGE_TIME_DISCOUNT WATER_OK ;,; Added WATER_OK
End

SpecialPower HESpellBookFlood
	Enum			= SPECIAL_SPELL_BOOK_FLOOD
	RadiusCursorRadius	= 175
	RequiredSciences		= HESCIENCE_Flood
	ReloadTime		= SPELL_RECHARGE_TIME_TIER_4 ; in milliseconds
	ViewObjectDuration 	= 10000
	ViewObjectRange	 	= 200
	InitiateAtLocationSound	= SpellFloodMS
	Flags					= RESPECT_RECHARGE_TIME_DISCOUNT WATER_OK ;;,;; Added WATER_OK
End

SpecialPower HESpellBookSunflare
	Enum			= SPECIAL_SPELL_BOOK_SUNFLARE
	Flags			= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
	RadiusCursorRadius	= SPELL_SUNFLARE_EFFECT_RADIUS
	RequiredSciences		= HESCIENCE_Sunflare
	ReloadTime		= SPELL_RECHARGE_TIME_TIER_4 ;// in milliseconds
	ViewObjectDuration	= SPELL_SUNFLARE_VIEW_OBJECT_DURATION
	ViewObjectRange		= SPELL_SUNFLARE_VIEW_OBJECT_RANGE
	InitiateAtLocationSound = SpellSunflareMS
End

SpecialPower HESpellBookCitadel
	Enum			= SPECIAL_SPELL_BOOK_CITADEL
	RadiusCursorRadius	= SPAWN_CITADEL_DECAL_RADIUS
	RequiredSciences		= HESCIENCE_Citadel
	ReloadTime		= SPELL_RECHARGE_TIME_TIER_4 ; in milliseconds
	InitiateAtLocationSound = SpellSpawnDwarfCitadel
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_CITADEL_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= SPAWN_CITADEL_DECAL_RADIUS
End

SpecialPower HESpecialAbilityGlorfindelStarlight
	Enum						= SPECIAL_HERO_MODE;SPECIAL_GENERAL_TARGETLESS_THREE
	ReloadTime					= 180000;270000 ;;,;; 240000 ;;.;; 120000
	InitiateAtLocationSound		= GlorfindelStarlight
End
