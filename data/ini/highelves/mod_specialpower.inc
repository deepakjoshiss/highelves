; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

SpecialPower SpecialAbilityRamBaan
  Enum              = SPECIAL_GENERAL_TARGETLESS
  ReloadTime		= 1
End

SpecialPower SpecialAbilityThranduilRampage
  Enum              = SPECIAL_GENERAL_TARGETLESS
  ReloadTime		= 1
End

SpecialPower SpellBookLightOfTrees_Rays ;,; SpellBookCloudBreak_Healing
  Enum            	= SPECIAL_SPELL_BOOK_CLOUD_BREAK
  ReloadTime       	= 5000 
  Flags             	= WATER_OK RESPECT_RECHARGE_TIME_DISCOUNT
  RadiusCursorRadius  = 120.0
End

SpecialPower SpellBookLightOfTrees
	Enum                     = SPECIAL_SPELL_BOOK_CLOUD_BREAK
	RequiredSciences         = SCIENCE_LightOfTrees
	ReloadTime               = 30000 ;,; 240000;SPELL_RECHARGE_TIME_TIER_2 ;;,;; 360000; RotWK originally SPELL_RECHARGE_TIME_TIER_3 ;600000 in milliseconds
	InitiateAtLocationSound  = SpellGoodLightOFTrees
	Flags					 = RESPECT_RECHARGE_TIME_DISCOUNT
End

SpecialPower SpellBookSpawnTreeFlet
	Enum									= SPECIAL_SPELL_BOOK_SPAWN_LONE_TOWER
	RadiusCursorRadius		= H_SPAWN_TREE_FLET_DECAL_RADIUS
	RequiredSciences			= HESCIENCE_SpawnLoneTower
	ReloadTime						= SPELL_RECHARGE_TIME_TIER_2 ;,; SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_1 ; in milliseconds
	InitiateAtLocationSound	= SpellSpawnTreeFlet
	ViewObjectDuration		= 10000
	ViewObjectRange				= 200
	Flags									= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_STRUCTURE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= H_SPAWN_TREE_FLET_DECAL_RADIUS
End

SpecialPower SpellBookElvenWaystone
	Enum									= SPECIAL_SPELL_BOOK_DRAGON_ALLY
	RadiusCursorRadius		= H_SPAWN_TREE_FLET_DECAL_RADIUS
	RequiredSciences			= SCIENCE_ElvenWaystone
	ReloadTime						= SPELL_RECHARGE_TIME_TIER_2 ;,; SPELL_RECHARGE_TIME_TIER_6 ;;,;; SPELL_RECHARGE_TIME_TIER_1 ; in milliseconds
	InitiateAtLocationSound	= SpellSpawnWaystone
	ViewObjectDuration		= 10000
	ViewObjectRange				= 200
	Flags									= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_STRUCTURE_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= H_SPAWN_TREE_FLET_DECAL_RADIUS
End

SpecialPower SpecialAbilityWaystoneTeleport
	Enum									  	=	SPECIAL_TELEPORT_TEAM_TO_CASTER
	RadiusCursorRadius				=	100.0
	ReloadTime								=	60000
	ObjectFilter							=	ANY	+INFANTRY +CAVALRY +DOZER +HERO -HERohanTreeBerd ALLIES
	InitiateSound					  	= CaH_TeleportPart1
End

SpecialPower SpecialAbilityMirkwoodTrap
	Enum											= SPECIAL_ARROW_STORM
	ReloadTime								= 60000
	RadiusCursorRadius				= H_WAYSTONE_STUN_RADIUS
	Flags											= WATER_OK
	ObjectFilter 		  				= ALL
End

SpecialPower SpecialAbilityPurify
	Enum											= SPECIAL_GENERAL_TARGETLESS
	ReloadTime								= 120000
	PublicTimer								= No
	InitiateSound 						= WaystonePurify
End

SpecialPower SpellBookRingOfAdamant
	Enum									= SPECIAL_SPELL_BOOK_SCAVENGER
  RequiredSciences			= SCIENCE_RingOfAdamant
  ReloadTime						= 0   ; in milliseconds
  Flags									= RESPECT_RECHARGE_TIME_DISCOUNT
End

SpecialPower SpecialAbilityTaurielForestDaughter
  Enum			 =	SPECIAL_BALROG_WINGS
	ReloadTime		 =	180000				  // This is completely	   auto, so	make the timout	*quite*	fast.
	PublicTimer		 =	No
	Flags			= NO_FORBIDDEN_OBJECTS
	ForbiddenObjectFilter	= NONE +STRUCTURE
	ForbiddenObjectRange	= 10
	InitiateAtLocationSound = CaH_Invulnerability
	Flags				    = LIMIT_DISTANCE
	MaxCastRange		    = 800
End

SpecialPower SpecialAbilityTaurielSummon
	Enum			= SPECIAL_SPELL_BOOK_DUNEDAIN_ALLIES
	ReloadTime		= 180000
	InitiateAtLocationSound	= TaurielVoiceEyesandEars
	RadiusCursorRadius	= 60.0
	Flags					= NO_FORBIDDEN_OBJECTS
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

SpecialPower SpecialAbilityTaurielFleetFooted
  Enum                = SPECIAL_TRIGGER_ATTRIBUTE_MODIFIER
  ReloadTime          = 120000

End

SpecialPower SpecialAbilityExplodingArrow
  Enum                = SPECIAL_ARROW_STORM
  ReloadTime          = 24000
  RadiusCursorRadius  = H_TAURIEL_EXPLODING_ARROW_RADIUS
  InitiateSound 	  = TaurielFleetfooted
  ObjectFilter 		  = ALL ;-BASE_FOUNDATION -INERT -IGNORED_IN_GUI -WALK_ON_TOP_OF_WALL -BLOCKING_GATE -WALL_UPGRADE -UNATTACKABLE -MOVE_ONLY
End

; ---- PROTOTYPE: Hero Armory page switches (instant, no recharge); their modules are on HEElvenCitadel
SpecialPower HEArmoryOpen
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
SpecialPower HEArmoryOpenLegolas
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
SpecialPower HEArmoryOpenThranduil
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
SpecialPower HEArmoryOpenElrond
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
SpecialPower HEArmoryBackHero
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
SpecialPower HEArmoryBack
  Enum = SPECIAL_GENERAL_TARGETLESS
  ReloadTime = 0
End
