; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

Weapon HEElvenLegolasBow ; hero rework: one arrow, Twin Draw's second from level 7 (OpenBFMESplitShot)
	AttackRange		= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed		= H_FAST_WEAPON_SPEED         			; dist/sec
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      			; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX			= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes 				; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     			;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 5.0     			;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    CanFireWhileMoving		= Yes
    
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget						; Twin Draw (level 7): a second arrow at another enemy near the target
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel7
	End
	ProjectileNugget						; Bow of the Galadhrim II: one more arrow at another enemy (OpenBFMESplitShot)
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_HELegolasBow2
	End
	ProjectileNugget						; Bow of the Galadhrim III: another
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_HELegolasBow3
	End
End

Weapon HEElvenLegolasBowWarhead
	ProjectileCollidesWith	= ENEMIES NEUTRAL STRUCTURES WALLS
	RadiusDamageAffects		= ENEMIES NEUTRALS NOT_SIMILAR
	HitStoredTarget			= Yes
	DamageNugget
		Damage				= H_RW_LEGOLAS_BOW_DAMAGE
		DamageScalar		= H_RW_LEGOLAS_INFANTRY_SCALAR NONE +INFANTRY
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO_RANGED
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
	End
	DamageNugget						; Arrowheads I: monsters and machines (items take the level percentage only)
		Damage				= 40
		AcceptDamageAdd		= No
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +MONSTER +MACHINE
		RequiredUpgradeNames	= Upgrade_HELegolasArrowheads1
	End
	DamageNugget						; Arrowheads I: heroes
		Damage				= 25
		AcceptDamageAdd		= No
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +HERO
		RequiredUpgradeNames	= Upgrade_HELegolasArrowheads1
	End
	DamageNugget						; Arrowheads II: monsters and heroes
		Damage				= 25
		AcceptDamageAdd		= No
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +MONSTER +HERO
		RequiredUpgradeNames	= Upgrade_HELegolasArrowheads2
	End
	DamageNugget						; Arrowheads III: monsters, machines and heroes
		Damage				= 30
		AcceptDamageAdd		= No
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +MONSTER +MACHINE +HERO
		RequiredUpgradeNames	= Upgrade_HELegolasArrowheads3
	End
End

; Fan of Arrows: 5 arrows, 10 from level 10, 15 from level 18, each at a different enemy within 100 of the target (OpenBFMESplitShot);
; full arrows (his bow's warhead)
Weapon HEElvenLegolasFanOfArrows
	AttackRange				= H_RW_HERO_POWER_REACH
	LeechRangeWeapon		= Yes
	WeaponSpeed				= H_FAST_WEAPON_SPEED
	MinWeaponSpeed			= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed			= H_FAST_WEAPON_SPEED_MAX
	FireFX					= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed		= Yes
	HitStoredTarget			= Yes
	HitPercentage			= 100
	DelayBetweenShots		= 5000
	PreAttackDelay			= 1
	PreAttackType			= PER_POSITION
	FiringDuration			= 1
	ClipSize				= 1
	AutoReloadsClip			= Yes
	AutoReloadWhenIdle		= 1
	ClipReloadTime			= Min:1500 Max:1500
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel10
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel10
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel10
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel10
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel10
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel18
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel18
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel18
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel18
	End
	ProjectileNugget
		ProjectileTemplateName	= OrangeFeatherArrow
		WarheadTemplateName		= HEElvenLegolasBowWarhead
		RequiredUpgradeNames	= Upgrade_ObjectLevel18
	End
End

; Piercing Arrow (level 9): a line ahead of him out to 500, 15 wide: an arrow at each of 17 points (LinearTarget, along his facing), radius 15, the circles touching
Weapon HEElvenLegolasPiercingArrow
	AttackRange				= H_RW_HERO_POWER_REACH
	LeechRangeWeapon		= Yes
	WeaponSpeed				= H_FAST_WEAPON_SPEED
	MinWeaponSpeed			= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed			= H_FAST_WEAPON_SPEED_MAX
	FireFX					= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed		= Yes
	HitPercentage			= 100
	DelayBetweenShots		= 5000
	PreAttackDelay			= 1
	PreAttackType			= PER_POSITION
	FiringDuration			= 1
	ClipSize				= 1
	AutoReloadsClip			= Yes
	AutoReloadWhenIdle		= 1
	ClipReloadTime			= Min:1500 Max:1500
	LinearTarget			= X:15 Y:0 T:0
	LinearTarget			= X:45 Y:0 T:0
	LinearTarget			= X:75 Y:0 T:0
	LinearTarget			= X:105 Y:0 T:0
	LinearTarget			= X:135 Y:0 T:0
	LinearTarget			= X:165 Y:0 T:0
	LinearTarget			= X:195 Y:0 T:0
	LinearTarget			= X:225 Y:0 T:0
	LinearTarget			= X:255 Y:0 T:0
	LinearTarget			= X:285 Y:0 T:0
	LinearTarget			= X:315 Y:0 T:0
	LinearTarget			= X:345 Y:0 T:0
	LinearTarget			= X:375 Y:0 T:0
	LinearTarget			= X:405 Y:0 T:0
	LinearTarget			= X:435 Y:0 T:0
	LinearTarget			= X:465 Y:0 T:0
	LinearTarget			= X:495 Y:0 T:0
	ProjectileNugget
		ProjectileTemplateName	= HEElvenLegolasPiercingProjectile ; his arrow with a light trail
		WarheadTemplateName		= HEElvenLegolasPiercingArrowWarhead
	End
End

Weapon HEElvenLegolasPiercingArrowWarhead
	RadiusDamageAffects		= ENEMIES NEUTRALS NOT_SIMILAR
	DamageNugget
		Damage				= H_RW_LEGOLAS_PIERCING_DAMAGE
		AcceptDamageAdd		= No ; powers grow with the level's percentage only
		Radius				= 15.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
	End
	MetaImpactNugget						; the soldiers it kills are thrown back
		SpecialObjectFilter	= NONE +INFANTRY
		ShockWaveAmount		= 30.0
		ShockWaveRadius		= 15.0
		ShockWaveTaperOff	= 1.0
		OnlyWhenJustDied	= Yes
	End
	DamageNugget						; Heartseeker II: 450 in all
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 15.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker2
	End
	DamageNugget						; Heartseeker II: buildings
		Damage				= 100
		AcceptDamageAdd		= No
		Radius				= 15.0
		DelayTime			= 0
		DamageType			= SIEGE
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +STRUCTURE
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker2
	End
	DamageNugget						; Heartseeker III: buildings, 200 in all
		Damage				= 100
		AcceptDamageAdd		= No
		Radius				= 15.0
		DelayTime			= 0
		DamageType			= SIEGE
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +STRUCTURE
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
	AttributeModifierNugget					; Heartseeker I: everything within 40 of the line slowed 30%, 10 s
		AttributeModifier		= HELegolasHeartseekerSlow1
		Radius					= 40.0
		AffectHordeMembers		= Yes
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker1
		ForbiddenUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
	AttributeModifierNugget					; Heartseeker III: the slow 50%
		AttributeModifier		= HELegolasHeartseekerSlow3
		Radius					= 40.0
		AffectHordeMembers		= Yes
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
End

; Piercing Arrow II (level 20): the line 30 wide (8 points, radius 30)
Weapon HEElvenLegolasPiercingArrow2
	AttackRange				= H_RW_HERO_POWER_REACH
	LeechRangeWeapon		= Yes
	WeaponSpeed				= H_FAST_WEAPON_SPEED
	MinWeaponSpeed			= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed			= H_FAST_WEAPON_SPEED_MAX
	FireFX					= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed		= Yes
	HitPercentage			= 100
	DelayBetweenShots		= 5000
	PreAttackDelay			= 1
	PreAttackType			= PER_POSITION
	FiringDuration			= 1
	ClipSize				= 1
	AutoReloadsClip			= Yes
	AutoReloadWhenIdle		= 1
	ClipReloadTime			= Min:1500 Max:1500
	LinearTarget			= X:30 Y:0 T:0
	LinearTarget			= X:90 Y:0 T:0
	LinearTarget			= X:150 Y:0 T:0
	LinearTarget			= X:210 Y:0 T:0
	LinearTarget			= X:270 Y:0 T:0
	LinearTarget			= X:330 Y:0 T:0
	LinearTarget			= X:390 Y:0 T:0
	LinearTarget			= X:450 Y:0 T:0
	ProjectileNugget
		ProjectileTemplateName	= HEElvenLegolasPiercingProjectile ; his arrow with a light trail
		WarheadTemplateName		= HEElvenLegolasPiercingArrow2Warhead
	End
End

Weapon HEElvenLegolasPiercingArrow2Warhead
	RadiusDamageAffects		= ENEMIES NEUTRALS NOT_SIMILAR
	DamageNugget
		Damage				= H_RW_LEGOLAS_PIERCING_DAMAGE
		AcceptDamageAdd		= No ; powers grow with the level's percentage only
		Radius				= 30.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
	End
	MetaImpactNugget						; the soldiers it kills are thrown back
		SpecialObjectFilter	= NONE +INFANTRY
		ShockWaveAmount		= 30.0
		ShockWaveRadius		= 30.0
		ShockWaveTaperOff	= 1.0
		OnlyWhenJustDied	= Yes
	End
	DamageNugget						; Heartseeker II: 450 in all
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 30.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker2
	End
	DamageNugget						; Heartseeker II: buildings
		Damage				= 100
		AcceptDamageAdd		= No
		Radius				= 30.0
		DelayTime			= 0
		DamageType			= SIEGE
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +STRUCTURE
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker2
	End
	DamageNugget						; Heartseeker III: buildings, 200 in all
		Damage				= 100
		AcceptDamageAdd		= No
		Radius				= 30.0
		DelayTime			= 0
		DamageType			= SIEGE
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +STRUCTURE
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
	AttributeModifierNugget					; Heartseeker I: everything within 40 of the line slowed 30%, 10 s
		AttributeModifier		= HELegolasHeartseekerSlow1
		Radius					= 40.0
		AffectHordeMembers		= Yes
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker1
		ForbiddenUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
	AttributeModifierNugget					; Heartseeker III: the slow 50%
		AttributeModifier		= HELegolasHeartseekerSlow3
		Radius					= 40.0
		AffectHordeMembers		= Yes
		RequiredUpgradeNames	= Upgrade_HELegolasHeartseeker3
	End
End

; Legolas's Arrow Wind (hero rework): 2.02's LegolasBowArrowStorm reaching the whole circle. Its 400 range was shorter than the 450 he
; starts the volley from plus the circle's radius, so every target beyond 400 used a shot and got no arrow
Weapon HEElvenLegolasArrowWindBow
  AttackRange = 700 ; ArrowStormUpdate StartAbilityRange 450 + the level-25 TargetRadius 240 ;,; LEGOLAS_ARROWSTORM_RANGE (400)
  WeaponSpeed = 561         ; dist/sec 
  MinWeaponSpeed = 481
  MaxWeaponSpeed = 641      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
  FireFX = FX_RohanArcherBowWeapon
  HitPercentage     = 100     ;When this weapon is used it will hit exactly all of the time.

  ProjectileNugget                    ; Default arrow
    ProjectileTemplateName = LegolasBowArrowStormProjectile
    WarheadTemplateName = LegolasBowArrowStormWarhead
  End
End







Weapon HELegolasBow
	AttackRange		= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed		= H_FAST_WEAPON_SPEED         			; dist/sec
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      			; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX			= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes 				; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     			;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 5.0     			;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    CanFireWhileMoving		= Yes
    
	ProjectileNugget                    			; Default Arrow
	    ProjectileTemplateName    = OrangeFeatherArrow
	    WarheadTemplateName       = LegolasSuperBowWarhead
	    ForbiddenUpgradeNames     = Upgrade_New1
	End

	ProjectileNugget                    ; Default arrow
	    ProjectileTemplateName    = RamaArrow
	    WarheadTemplateName       = LegolasSuperBowWarhead
	    RequiredUpgradeNames   	  = Upgrade_New1
	End

	; TEST (split shot): a second arrow from level 3, a third from level 7. OpenBFME (OpenBFMESplitShot in openbfme.ini) sends each to a different
	; enemy near the target; the original game fires them at the target
	ProjectileNugget
	    ProjectileTemplateName    = OrangeFeatherArrow
	    WarheadTemplateName       = LegolasSuperBowWarhead
	    RequiredUpgradeNames      = Upgrade_ObjectLevel3
	End

	ProjectileNugget
	    ProjectileTemplateName    = OrangeFeatherArrow
	    WarheadTemplateName       = LegolasSuperBowWarhead
	    RequiredUpgradeNames      = Upgrade_ObjectLevel7
	End
End

Weapon HELegolasHawkStrike
    LeechRangeWeapon      	= Yes ;,;
    AttackRange 	= LEGOLAS_HAWKSTRIKE_RANGE
    WeaponSpeed 	= 321         					; dist/sec 
    MinWeaponSpeed 	= 241
    MaxWeaponSpeed 	= 481      					; dist/sec Upper limit on scaling, when attacking past nominal "max" range
    FireFX 		= FX_RohanArcherBowWeapon
    ScaleWeaponSpeed 	= Yes 						; Used for lob weapons, scales speed proportional to range
    HitPercentage     	= 100     					;When this weapon is used it will hit exactly 75% of the time.

	;All these delays are controlled by the special power. Basically the special power can
	;launch whenever it's ready.
    DelayBetweenShots		= 0					; time between shots, msec
    PreAttackDelay		= 3000					; we want isntant
    PreAttackType		= PER_POSITION
    FiringDuration		= 1000					; Duration of the archer firing shot is 500ms.
    ;,; ClipSize 			= 1
    ;,; AutoReloadsClip 		= Yes
    ;,; AutoReloadWhenIdle 		= 1	
    ;,; ClipReloadTime 		= Min:1 Max:1

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    
	PreferredTargetBone = B_LLLID 					; Likes to shoot things in their left eye.

	ProjectileNugget                    				; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName = LegolasSpecialArrow
		WarheadTemplateName = HELegolasHawkStrikeWarhead
	End
	ProjectileNugget                    				; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName = LegolasSpecialArrow2ndArrow
		WarheadTemplateName = HELegolasHawkStrikeWarhead
	End
End

; Legolas's Hawk Strike (hero rework): HELegolasHawkStrike at the fast arrow speed (ElvenElrohir keeps the slow one)
Weapon HEElvenLegolasHawkStrike
    LeechRangeWeapon      	= Yes ;,;
    AttackRange 	= H_RW_HERO_POWER_REACH ; hero rework ;,; LEGOLAS_HAWKSTRIKE_RANGE (485)
    WeaponSpeed 	= H_FAST_WEAPON_SPEED ;,;         					; dist/sec 
    MinWeaponSpeed 	= H_FAST_WEAPON_SPEED_MIN ;,;
    MaxWeaponSpeed 	= H_FAST_WEAPON_SPEED_MAX ;,;      					; dist/sec Upper limit on scaling, when attacking past nominal "max" range
    FireFX 		= FX_RohanArcherBowWeapon
    ScaleWeaponSpeed 	= Yes 						; Used for lob weapons, scales speed proportional to range
    HitPercentage     	= 100     					;When this weapon is used it will hit exactly 75% of the time.

	;All these delays are controlled by the special power. Basically the special power can
	;launch whenever it's ready.
    DelayBetweenShots		= 0					; time between shots, msec
    PreAttackDelay		= 3000					; we want isntant
    PreAttackType		= PER_POSITION
    FiringDuration		= 1000					; Duration of the archer firing shot is 500ms.
    ;,; ClipSize 			= 1
    ;,; AutoReloadsClip 		= Yes
    ;,; AutoReloadWhenIdle 		= 1	
    ;,; ClipReloadTime 		= Min:1 Max:1

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    
	PreferredTargetBone = B_LLLID 					; Likes to shoot things in their left eye.

	ProjectileNugget                    				; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName = LegolasSpecialArrow
		WarheadTemplateName = HEElvenLegolasHawkStrikeWarhead
	End
	ProjectileNugget                    				; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName = LegolasSpecialArrow2ndArrow
		WarheadTemplateName = HEElvenLegolasHawkStrikeNoWarhead ; a visual only (2.02 gave it the full warhead: two hits)
	End
End

Weapon HELegolasHawkStrikeWarhead
	ProjectileCollidesWith 	= ALLIES ENEMIES NEUTRAL STRUCTURES WALLS 
	RadiusDamageAffects 	= ENEMIES NEUTRALS NOT_SIMILAR
	HitStoredTarget 	= Yes					; Always hits initial target.
	DamageNugget                        				; A basic Nugget that just does damage
    		;,; DamageScalar  	= 10% NONE +STRUCTURE +MordorCatapult +IsengardBallista +GondorTrebuchet +GondorTrebuchetWall 
		Damage        	= LEGOLAS_HAWKSTRIKE_DAMAGE
		Radius        	= 20
		DelayTime     	= 0
		DamageType    	= HERO_RANGED ;,; HERO
		DamageFXType  	= GOOD_ARROW_PIERCE
		DeathType     	= NORMAL
;;,;;   		DamageScalar  	= 250% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth
		DamageScalar  	= 250% NONE +WildMountainGiant +WildMountainGiantSentry +WildMountainGiant_Summoned
		DamageScalar  	= 200% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth +KhamulFellBeast +GondorGwaihir_Summoned +ElvenFortressEagle ;,; 175% ;,; 250% ;;,;; added for 2.02e
    	End

	DamageNugget                        				; A basic Nugget that just does damage
    		;,; DamageScalar  	= 10% NONE +STRUCTURE +MordorCatapult +IsengardBallista +GondorTrebuchet +GondorTrebuchetWall
		Damage        	= 60
		Radius        	= 60
		DelayTime     	= 0
		DamageType    	= HERO_RANGED ;,; HERO
		DamageFXType  	= MAGIC
		DeathType     	= NORMAL
    	End
		
	MetaImpactNugget ;,;
		SpecialObjectFilter = ANY +INFANTRY +CAVALRY
		ShockWaveAmount   = 50.0
		ShockWaveRadius   = 20.0
		ShockWaveArc      = 90 ; in degrees to each side 180 is full circle
		ShockWaveTaperOff = 1.0
		ShockWaveSpeed    = 0.0
		ShockWaveZMult    = 1.0
		OnlyWhenJustDied = Yes
	End
End

Weapon HEElvenLegolasHawkStrikeWarhead ; hero rework: 2.02's with Hawk of Mirkwood's blocks
	ProjectileCollidesWith 	= ALLIES ENEMIES NEUTRAL STRUCTURES WALLS 
	RadiusDamageAffects 	= ENEMIES NEUTRALS NOT_SIMILAR
	HitStoredTarget 	= Yes					; Always hits initial target.
	DamageNugget                        				; A basic Nugget that just does damage
    		;,; DamageScalar  	= 10% NONE +STRUCTURE +MordorCatapult +IsengardBallista +GondorTrebuchet +GondorTrebuchetWall 
		Damage        	= LEGOLAS_HAWKSTRIKE_DAMAGE
		Radius        	= 20
		DelayTime     	= 0
		DamageType    	= HERO_RANGED ;,; HERO
		DamageFXType  	= GOOD_ARROW_PIERCE
		DeathType     	= NORMAL
;;,;;   		DamageScalar  	= 250% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth
		DamageScalar  	= 250% NONE +WildMountainGiant +WildMountainGiantSentry +WildMountainGiant_Summoned
		DamageScalar  	= 200% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth +KhamulFellBeast +GondorGwaihir_Summoned +ElvenFortressEagle ;,; 175% ;,; 250% ;;,;; added for 2.02e
		DamageScalar	= 200% NONE +MONSTER ; hero rework: monsters (the first scalar that matches counts: giants 250%, fell beasts 200%)
    	End

	DamageNugget                        				; A basic Nugget that just does damage
    		;,; DamageScalar  	= 10% NONE +STRUCTURE +MordorCatapult +IsengardBallista +GondorTrebuchet +GondorTrebuchetWall
		Damage        	= 60
		Radius        	= 60
		DelayTime     	= 0
		DamageType    	= HERO_RANGED ;,; HERO
		DamageFXType  	= MAGIC
		DeathType     	= NORMAL
    	End
		
	MetaImpactNugget ;,;
		SpecialObjectFilter = ANY +INFANTRY +CAVALRY
		ShockWaveAmount   = 50.0
		ShockWaveRadius   = 20.0
		ShockWaveArc      = 90 ; in degrees to each side 180 is full circle
		ShockWaveTaperOff = 1.0
		ShockWaveSpeed    = 0.0
		ShockWaveZMult    = 1.0
		OnlyWhenJustDied = Yes
	End
	DamageNugget						; Hawk of Mirkwood I: 500 in all
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 20
		DelayTime			= 0
		DamageType			= HERO_RANGED
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		DamageScalar  	= 250% NONE +WildMountainGiant +WildMountainGiantSentry +WildMountainGiant_Summoned
		DamageScalar  	= 200% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth +KhamulFellBeast +GondorGwaihir_Summoned +ElvenFortressEagle ;,; 175% ;,; 250% ;;,;; added for 2.02e
		DamageScalar	= 200% NONE +MONSTER ; hero rework: monsters (the first scalar that matches counts: giants 250%, fell beasts 200%)
		RequiredUpgradeNames	= Upgrade_HELegolasHawk1
	End
	DamageNugget						; Hawk of Mirkwood II: 800 in all
		Damage				= 300
		AcceptDamageAdd		= No
		Radius				= 20
		DelayTime			= 0
		DamageType			= HERO_RANGED
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		DamageScalar  	= 250% NONE +WildMountainGiant +WildMountainGiantSentry +WildMountainGiant_Summoned
		DamageScalar  	= 200% NONE +MordorFellBeast +MordorWitchKingOnFellBeast +GondorGwaihir +Drogoth +KhamulFellBeast +GondorGwaihir_Summoned +ElvenFortressEagle ;,; 175% ;,; 250% ;;,;; added for 2.02e
		DamageScalar	= 200% NONE +MONSTER ; hero rework: monsters (the first scalar that matches counts: giants 250%, fell beasts 200%)
		RequiredUpgradeNames	= Upgrade_HELegolasHawk2
	End
	DamageNugget						; Hawk of Mirkwood II: machines (they take 5% of HERO_RANGED, 125-200% of HERO)
		Damage				= 300
		AcceptDamageAdd		= No
		Radius				= 20
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +MACHINE
		RequiredUpgradeNames	= Upgrade_HELegolasHawk2
	End
	DamageNugget						; Hawk of Mirkwood III: machines, 1100 in all
		Damage				= 800
		AcceptDamageAdd		= No
		Radius				= 20
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		SpecialObjectFilter	= ANY +MACHINE
		RequiredUpgradeNames	= Upgrade_HELegolasHawk3
	End
	DamageNugget						; Hawk of Mirkwood III: the burst
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 50
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
		RequiredUpgradeNames	= Upgrade_HELegolasHawk3
	End
	MetaImpactNugget						; Hawk of Mirkwood III: the soldiers it kills are thrown back
		SpecialObjectFilter		= NONE +INFANTRY
		ShockWaveAmount			= 30.0
		ShockWaveRadius			= 50.0
		ShockWaveTaperOff		= 1.0
		OnlyWhenJustDied		= Yes
		RequiredUpgradeNames	= Upgrade_HELegolasHawk3
	End
End

Weapon HEElvenLegolasHawkStrikeNoWarhead ; Hawk Strike's second arrow: a visual
	RadiusDamageAffects	= ENEMIES
End

Weapon HEMirkwoodArcherBow
	AttackRange         = H_ELVEN_MIRKWOOD_ARCHER_RANGE
	
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( ELVEN_MIRKWOOD_ARCHER_RANGE H_ARCHER_RANGE_MULTI )
	
	WeaponSpeed			= H_H_FAST_WEAPON_SPEED         ; dist/sec
	MinWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20	; prevent twitchy reaiming in horde on horde
	DelayBetweenShots   = 0
	PreAttackDelay      = ELVEN_MIRKWOOD_ARCHER_BOW_PREATTACKDELAY  
	PreAttackRandomAmount     = 200  
	PreAttackType       = PER_POSITION
	FiringDuration      = 0   

	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 0 ;,; 1	
	ClipReloadTime		= Min:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MIN Max:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX 

	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget	; Default arrow
		ProjectileTemplateName  = OrangeFeatherArrow
		WarheadTemplateName     = ElvenMirkwoodArcherBowWarhead
		ForbiddenUpgradeNames   = Upgrade_RohanFireArrows
	End
	ProjectileNugget	; Fire arrow avialble through fire upgrade
		ProjectileTemplateName  = GoodFactionFireArrow
		WarheadTemplateName     = RohanArcherBowFireWarhead
		RequiredUpgradeNames    = Upgrade_RohanFireArrows
	End
End

Weapon HEMirkwoodArcherSilverthornBow ;from RohanArcherBow
	AttackRange         = H_ELVEN_MIRKWOOD_ARCHER_RANGE	; increased range
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_ELVEN_MIRKWOOD_ARCHER_RANGE H_ARCHER_RANGE_MULTI )
	
	WeaponSpeed			= H_H_FAST_WEAPON_SPEED         ; dist/sec
	MinWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20	; prevent twitchy reaiming in horde on horde
	DelayBetweenShots   = 0
	PreAttackDelay      = ELVEN_MIRKWOOD_ARCHER_BOW_PREATTACKDELAY
	PreAttackRandomAmount     = 200  
	PreAttackType       = PER_POSITION
	FiringDuration      = 0   

	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 0;1
	ClipReloadTime		= Min:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MIN Max:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX

	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget	; Default arrow
		ProjectileTemplateName  = MirkwoodArcherSilverthornProjectile
		WarheadTemplateName     = MirkwoodArcherSilverthornBowWarhead
	End
End

Weapon ZephyrStrikeWeapon     ; BALANCE
	IdleAfterFiringDelay = 0
	AttackRange = ZEPHYR_STRIKE_RANGE
	MinimumAttackRange = 0.8
	WeaponSpeed = 401         ; dist/sec 
	MinWeaponSpeed = 241
	MaxWeaponSpeed = 601      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	ScaleWeaponSpeed = Yes ; Used for lob weapons, scales speed proportional to range
	RadiusDamageAffects = ENEMIES NOT_SIMILAR
	DelayBetweenShots = 5000               ; time between shots, msec
	PreAttackDelay        = 2600
	PreAttackType         = PER_ATTACK ; Do the delay each time we attack a new target
	PreAttackFX           = FX_GandalfPreAttackBlast
	FireFX                = FX_GandalfBlast
	FiringDuration      = 1400
  
	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= ZEPHYR_STRIKE_DAMAGE
		Radius			= ZEPHYR_STRIKE_RADIUS
		DamageType		= FORCE
		DamageFXType	= SWORD_SLASH
		DeathType		= EXPLODED
		DamageSpeed		= ZEPHYR_STRIKE_SHOCKWAVE_SPEED ; must match the ShockWaveSpeed below
	End
	
	MetaImpactNugget                    ; A Nugget that throws things back with force
;		HeroResist			= .75
		ShockWaveAmount   = ZEPHYR_STRIKE_SHOCKWAVE_AMOUNT
		ShockWaveRadius   = ZEPHYR_STRIKE_SHOCKWAVE_RADIUS
		ShockWaveTaperOff = 1.0
		ShockWaveZMult    = 1.000
		ShockWaveSpeed	  = ZEPHYR_STRIKE_SHOCKWAVE_SPEED
	End
End

Weapon HEHaldirBow
	AttackRange			= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( HALDIR_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed			= H_FAST_WEAPON_SPEED         ; dist/sec 
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX				= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     ;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 5.0     ;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20	; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      = H_HALDIR_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       = PER_POSITION ; Do the delay each time we attack a new target
	FiringDuration      = HALDIR_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle	= 1	
    ClipReloadTime		= Min:H_HALDIR_RELOADTIME_MIN Max:H_HALDIR_RELOADTIME_MAX
    ContinuousFireOne	= 0
    ContinuousFireCoast	= H_HALDIR_RELOADTIME_MAX
    ;,;InstantLoadClipOnActivate = Yes

    AntiAirborneVehicle	= Yes
    AntiAirborneMonster	= Yes
    CanFireWhileMoving		= Yes
    
	ProjectileNugget                    ; Default Arrow
		ProjectileTemplateName  = GoodFactionArrow
		WarheadTemplateName     = HaldirSuperBowWarhead
	End
End

Weapon HEMirkwoodArcherMissileHordeRangefinder
	AttackRange			= #SUBTRACT( H_ELVEN_MIRKWOOD_ARCHER_RANGE 100 )  ; Slightly shorter than the archer's actual weapon
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( ELVEN_MIRKWOOD_ARCHER_RANGE H_ARCHER_RANGE_MULTI )
	
	DelayBetweenShots		= 1000
	LeechRangeWeapon		= Yes
	AcceptableAimDelta		= 45
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	CanFireWhileMoving		= Yes		; When aboard a ship.
	FinishAttackOnceStarted = No
	HordeAttackNugget
	End
End

Weapon HERohanElvenWarriorSword
  LeechRangeWeapon      = Yes
  RadiusDamageAffects   = ENEMIES NEUTRALS ;,;
  AttackRange           = STANDARD_MELEE_ATTACK_RANGE ;,; 10.0
  MeleeWeapon           = Yes
  DelayBetweenShots     = ROHAN_ELVENWARRIOR_SWORD_DELAYBETWEENSHOTS           ; time between shots, msec
  OverrideVoiceAttackSound = ElvenWarriorVoiceAttack
  PreAttackDelay        = ROHAN_ELVENWARRIOR_SWORD_PREATTACKDELAY              ; 567 is sword swing delay time before contact with target.
  PreAttackType         = PER_SHOT ; Do the delay each time we attack a new target
  FireFX                = FX_GondorSwordHit
  FiringDuration        = ROHAN_ELVENWARRIOR_SWORD_FIRINGDURATION     ; Duration of the sword swing

  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = ROHAN_ELVEN_MELEE_DAMAGE
	DamageScalar  = 75% NONE +STRUCTURE ;,;
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = SLASH ;,; SPECIALIST
    DamageFXType  = SWORD_SLASH
    DeathType     = NORMAL
	FlankingBonus = 50%
    ForbiddenUpgradeNames      = Upgrade_ElvenForgedBlades ;,; Upgrade_GondorForgedBlades
  End
  
  DamageNugget                        ;,; A basic Nugget that just does damage
        Damage        = ROHAN_ELVEN_MELEE_DAMAGE_UPGRADE
        DamageScalar  = 75% NONE +STRUCTURE
        Radius        = 0.0
        DelayTime     = 0
        DamageType    = SLASH
        DamageFXType  = SWORD_SLASH
        DeathType     = NORMAL
        FlankingBonus = 50%
        RequiredUpgradeNames      = Upgrade_ElvenForgedBlades ;,; Upgrade_GondorForgedBlades
  End

  	DamageNugget
		Damage					= 20
		Radius					= 0.0
		DelayTime				= 0
		DamageType				= SIEGE ;;.;; SLASH
		DamageFXType			= SWORD_SLASH
		DeathType				= NORMAL
		FlankingBonus			= 50%
		SpecialObjectFilter		= NONE +STRUCTURE
		RequiredUpgradeNames	= Upgrade_ObjectLevel7
	End

End

Weapon HEElvenThranduilBow 
	AttackRange         = H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4
	
	WeaponSpeed         = H_FAST_WEAPON_SPEED         ; dist/sec
	MinWeaponSpeed      = H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed      = H_FAST_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	HitStoredTarget = Yes	; Always hits initial target.
	;ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.
	
	DelayBetweenShots   = 0
	PreAttackDelay      = 900 ;;,;; ROHAN_ELVENWARRIOR_BOW_PREATTACKDELAY 
	PreAttackType       = PER_POSITION
	FiringDuration      = 0

	;OverrideVoiceAttackSound		= ElvenWarriorVoiceAttackBow
	  
	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 1	
	ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= H_LEGOLAS_RELOADTIME_MAX
	  
	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= No ;;.;; Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget                    ; hero rework: one arrow, his own warhead (2.02's level 3 / 7 / 10 blocks are gone: items will add them)
	    ProjectileTemplateName    = SilverFeatherArrow
	    WarheadTemplateName       = HEElvenThranduilBowWarhead
	End
	ProjectileNugget                    ; Bow of the Elvenking II: a second arrow at another enemy (OpenBFMESplitShot)
	    ProjectileTemplateName    = SilverFeatherArrow
	    WarheadTemplateName       = HEElvenThranduilBowWarhead ; Bow of the Elvenking: a full arrow with the items' damage
	    RequiredUpgradeNames      = Upgrade_HEThranduilBow2
	End
	ProjectileNugget                    ; Bow of the Elvenking III: a third
	    ProjectileTemplateName    = SilverFeatherArrow
	    WarheadTemplateName       = HEElvenThranduilBowWarhead ; Bow of the Elvenking: a full arrow with the items' damage
	    RequiredUpgradeNames      = Upgrade_HEThranduilBow3
	End
End

; Thranduil's Rampage bow (hero rework): the bow firing every 3rd logic frame (named in openbfme.ini's OpenBFMEFireWaitsForReload), no draw,
; the same warhead. Used while Rampage runs (WEAPONSET_HERO_MODE) and for good from level 25 (PLAYER_UPGRADE).
Weapon HEThranduilRampageBow
	AttackRange         = H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 30 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4
	
	WeaponSpeed         = 1200
	MinWeaponSpeed      = 600
	MaxWeaponSpeed      = 1600
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	HitStoredTarget = Yes	; Always hits initial target.
	;ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.
	
	DelayBetweenShots   = 0
	PreAttackDelay      = 0 ; no draw on a new target
	PreAttackType       = PER_POSITION
	FiringDuration      = 0

	;OverrideVoiceAttackSound		= ElvenWarriorVoiceAttackBow
	  
	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 1	
	ClipReloadTime		= Min:H_THRANDUIL_RAMPAGE_RELOAD Max:H_THRANDUIL_RAMPAGE_RELOAD
	ContinuousFireOne	= 0
	ContinuousFireCoast	= H_THRANDUIL_RAMPAGE_RELOAD
	  
	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= No ;;.;; Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget
	    ProjectileTemplateName    = GoodFactionArrowDeadeye
	    WarheadTemplateName       = HEElvenThranduilBowWarhead
	End
	ProjectileNugget                    ; Bow of the Elvenking II: a second arrow at another enemy (OpenBFMESplitShot)
	    ProjectileTemplateName    = GoodFactionArrowDeadeye
	    WarheadTemplateName       = HEElvenThranduilBowWarhead ; Bow of the Elvenking: a full arrow with the items' damage
	    RequiredUpgradeNames      = Upgrade_HEThranduilBow2
	End
	ProjectileNugget                    ; Bow of the Elvenking III: a third
	    ProjectileTemplateName    = GoodFactionArrowDeadeye
	    WarheadTemplateName       = HEElvenThranduilBowWarhead ; Bow of the Elvenking: a full arrow with the items' damage
	    RequiredUpgradeNames      = Upgrade_HEThranduilBow3
	End
End

Weapon HEElvenThranduilBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS ALLIES NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = H_THRANDUIL_BOW_DAMAGE ; takes the level's flat bonus (DAMAGE_ADD)
    	;DamageScalar  		= 25000% NONE +MordorMumakil
    Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DelayTime     = 0
    DamageType    = HERO_RANGED
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
  End
  ; ---- Armory items (hero rework); the Rampage bow shares this warhead
  DamageNugget                        ; Arrowheads I: monsters and machines
    Damage        = H_THRANDUIL_ARROWHEADS1_DAMAGE
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
    SpecialObjectFilter  = ANY +MONSTER +MACHINE
    RequiredUpgradeNames = Upgrade_HEThranduilArrowheads1
  End
  DamageNugget                        ; Arrowheads I: heroes
    Damage        = 50
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
    SpecialObjectFilter  = ANY +HERO
    RequiredUpgradeNames = Upgrade_HEThranduilArrowheads1
  End
  DamageNugget                        ; Arrowheads II: monsters and heroes
    Damage        = 50
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
    SpecialObjectFilter  = ANY +MONSTER +HERO
    RequiredUpgradeNames = Upgrade_HEThranduilArrowheads2
  End
  DamageNugget                        ; Arrowheads III: monsters, machines and heroes
    Damage        = 60
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
    SpecialObjectFilter  = ANY +MONSTER +MACHINE +HERO
    RequiredUpgradeNames = Upgrade_HEThranduilArrowheads3
  End
  DamageNugget                        ; Wrath of Mirkwood I: magic
    Damage        = 40
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = MAGIC
    DamageFXType  = MAGIC
    DeathType     = NORMAL
    RequiredUpgradeNames = Upgrade_HEThranduilDamage1
  End
  DamageNugget                        ; Wrath of Mirkwood II: siege
    Damage        = 40
    AcceptDamageAdd = No
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = SIEGE
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
    RequiredUpgradeNames = Upgrade_HEThranduilDamage2
  End
  DamageNugget                        ; Wrath of Mirkwood III: hero damage
    Damage        = 80
    AcceptDamageAdd = No
    Radius        = 0.0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    RequiredUpgradeNames = Upgrade_HEThranduilDamage3
  End
End

Weapon HEThranduilThornofVengeance
	AttackRange				= H_RW_HERO_POWER_REACH ; hero rework ;,; FARAMIR_WOUNDING_ARROW_RANGE
	LeechRangeWeapon			= Yes
	WeaponSpeed				= H_FAST_WEAPON_SPEED ; hero rework ;,; 321
	MinWeaponSpeed			= H_FAST_WEAPON_SPEED_MIN ;,; 241
	MaxWeaponSpeed			= H_FAST_WEAPON_SPEED_MAX ;,; 481
	FireFX					= FX_ThranduilThornOfVengeance	;FX_FaramirWoundingArrow
	ScaleWeaponSpeed		= Yes ; Used for lob weapons, scales speed proportional to range
	HitStoredTarget			= Yes	; Always hits initial target.
	HitPercentage			= 100		 
	ScatterRadius			= 0.0		 ;When this weapon misses it can randomly miss by as much as this distance.
	DelayBetweenShots		= 5000									; time between shots, msec
	PreAttackDelay			= 1										; we want isntant
	PreAttackType			= PER_POSITION
	FiringDuration			= 1										; Duration of the archer firing shot is 500ms.
	ClipSize				= 1
	AutoReloadsClip			= Yes
	AutoReloadWhenIdle		= 1	
	ClipReloadTime			= Min:THRANDUIL_THORN_RELOADTIME_MIN Max:THRANDUIL_THORN_RELOADTIME_MAX
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	PreferredTargetBone		= B_LLLID ; Likes to shoot things in their left eye.
	
	
	ProjectileNugget										; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName	= ThranSpecialArrow
		WarheadTemplateName	= HEThranduilThornofVengeanceWarhead
	End
End

Weapon HEThranduilThornofVengeanceWarhead
  ProjectileCollidesWith = ALLIES ENEMIES NEUTRAL STRUCTURES WALLS 
  RadiusDamageAffects	 = ENEMIES NEUTRALS ALLIES NOT_SIMILAR
  HitStoredTarget		 = Yes	; Always hits initial target.
  HitPercentage		     = 100	
  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = H_THRANDUIL_THORN_DAMAGE
    AcceptDamageAdd = No ; powers grow with the level's percentage only
	DamageScalar  = 80% NONE +MordorBalrog +AngmarShadeWolf +SummonedDragon +SummonedDragonJH1 ;,;
    Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DelayTime     = 0
    DamageType    = HERO
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
  End
 
  DamageNugget                       
	Damage        		= H_THRANDUIL_THORN_MAGIC_DAMAGE
	AcceptDamageAdd		= No
	DamageScalar  		= 80% NONE +MordorBalrog +AngmarShadeWolf +SummonedDragon +SummonedDragonJH1 ;,;				
	DamageType    		= MAGIC
	DamageFXType  		= MAGIC
	DeathType     		= BURNED
	Radius				= 60
	DelayTime			= 200  
  End

  DamageNugget                      
	Damage        		= H_THRANDUIL_THORN_MAGIC_DAMAGE
	AcceptDamageAdd		= No
	DamageScalar  		= 80% NONE +MordorBalrog +AngmarShadeWolf +SummonedDragon +SummonedDragonJH1 ;,;		
	DamageType    		= MAGIC
	DamageFXType  		= ELECTRIC
	DeathType     		= BURNED
	DelayTime			= 200  
  End
  
  MetaImpactNugget                    ; A Nugget that throws things back with force
;	HeroResist			= .25
    ShockWaveAmount   = 70.0
    ShockWaveRadius   = 60.0 ;,; 15.0
    ShockWaveTaperOff = 0.5
    ShockWaveZMult    = 1.20
  End
  
End

Weapon SuperTowerBow       ; BALANCE Archer Weapon
	AttackRange               = 500
	WeaponSpeed               = 500       ; dist/sec 
	MinWeaponSpeed            = 600
	MaxWeaponSpeed            = 1200		; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX                    = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed          = Yes		; Used for lob weapons, scales speed proportional to range
	HitPercentage             = 100		;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius             = 16.0		;When this weapon misses it can randomly miss by as much as this distance.
	DelayBetweenShots         = 0
	PreAttackDelay            = 0   ; 1467 is the prep time for archer.
	PreAttackType             = PER_SHOT	; Do the delay each time we attack a new target
	FiringDuration            = 0    ; Duration of the archer firing shot is 500ms.
	IsAimingWeapon            = Yes
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	HitPassengerPercentage	= 20%
	AcceptableAimDelta		= 180.0	; We want to be able to shoot all round, as we canit move.
	
  ;ClipSize              = 0
	CanBeDodged = Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	
  ProjectileNugget          ; Default arrow
    ProjectileTemplateName  = GoodFactionArrow
    WarheadTemplateName     = SuperTowerBowWarhead
    ForbiddenUpgradeNames   = Upgrade_ElvenSilverthornArrowsTower
  End

  ProjectileNugget          ; Upgraded arrow
    ProjectileTemplateName  = MirkwoodArcherSilverthornProjectile
    WarheadTemplateName     = SuperTowerBowWarhead
    RequiredUpgradeNames		= Upgrade_ElvenSilverthornArrowsTower
  End

End

Weapon SuperTowerBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS 
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR ;ALLIES
  HitStoredTarget = Yes	; Always hits initial target.
  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = KEEP_BOW_DAMAGE
    DamageScalar  = 0% NONE
    Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DelayTime     = 0
    DamageType    = STRUCTURAL ; Moving all structure-based weapons over to Structural Damage for balance reasons - GB
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
  End
  
  	; Damage to everything else is increased
  	DamageNugget
	    Damage        		= STRUCTURE_BOW_DAMAGE
		Radius        		= 0.0
	    DelayTime     		= 0
		DamageType		= MAGIC
		DamageFXType		= MAGIC
	    DeathType     		= EXPLODED
	    RequiredUpgradeNames	= Upgrade_ElvenSilverthornArrowsTower
	End
	

	; ..and meta impact damage on infantry
	MetaImpactNugget
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 50.0
		ShockWaveRadius   = 10.0
		ShockWaveArc      = 90 ; in degrees to each side 180 is full circle
		ShockWaveTaperOff = 1.0
		ShockWaveSpeed    = 0.0
		ShockWaveZMult    = 1.0
		OnlyWhenJustDied = Yes
	    RequiredUpgradeNames	= Upgrade_ElvenSilverthornArrowsTower
	End
End

Weapon NoldorWarriorBow
	AttackRange         = H_ELVEN_MIRKWOOD_ARCHER_RANGE	; increased range
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_ELVEN_MIRKWOOD_ARCHER_RANGE H_ARCHER_RANGE_MULTI )
	
	WeaponSpeed			= H_H_FAST_WEAPON_SPEED         ; dist/sec 
	MinWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed      = H_H_FAST_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20	; prevent twitchy reaiming in horde on horde
	DelayBetweenShots   = 0
	PreAttackDelay      = H_FAST_ARCHER_BOW_PREATTACKDELAY
	PreAttackRandomAmount     = 200  
	PreAttackType       = PER_POSITION
	FiringDuration      = 1000   

	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 0  ;;1	
	ClipReloadTime		= Min:H_FAST_ARCHER_BOW_RELOADTIME_MIN Max:H_FAST_ARCHER_BOW_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= H_FAST_ARCHER_BOW_RELOADTIME_MAX ;;,;; ELVEN_NOLDOR_WARRIOR_BOW_RELOADTIME_MIN

	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget	; Default arrow
		ProjectileTemplateName  = GoldenSilverFeatherArrow ;;,;; MirkwoodArcherSilverthornProjectile
		WarheadTemplateName     = NoldorWarriorSilverthornBowWarhead ;;,;; MirkwoodArcherSilverthornBowWarhead
	End
End

Weapon CreateAHeroSuperRangedWeapon
    AttackRange			= #SUBTRACT( H_HERO_BOW_RANGE 25 )

	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
					
    LeechRangeWeapon    = Yes
    WeaponSpeed			= H_FAST_WEAPON_SPEED         // dist/sec 
    MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
    MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      // dist/sec Upper limit on scaling, when attacking past nominal "max" range
    FireFX				= FX_RohanArcherBowWeapon
    ScaleWeaponSpeed	= Yes // Used for lob weapons, scales speed proportional to range
    HitPercentage		= 100     //When this weapon is used it will hit exactly 75% of the time.
    ScatterRadius		= 0.0     //When this weapon misses it can randomly miss by as much as this distance.
    UseInnateAttributes	= Yes
   
    AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle	= Yes
    AntiAirborneMonster	= Yes  
    
    CanFireWhileMoving		= Yes
   
    ProjectileNugget                    // Default arrow
       ProjectileTemplateName	= MirkwoodArcherSilverthornProjectile
       WarheadTemplateName		= CreateAHeroSuperRangedWarhead
;;,;;	   ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level4
		ForbiddenUpgradeNames = Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4	;;,;;
    End

    ProjectileNugget	;;,;; Added for 2.3
       ProjectileTemplateName	= GoodFactionFireArrow
       WarheadTemplateName		= CreateAHeroSuperRangedWarhead
	   RequiredUpgradeNames		= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHero_ClassArcher
	   ForbiddenUpgradeNames		= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
    End
	
    ProjectileNugget	;;,;; Added for 2.3
       ProjectileTemplateName	= MirkwoodArcherSilverthornProjectile
       WarheadTemplateName		= CreateAHeroSuperRangedWarhead
	   RequiredUpgradeNames		= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHero_ClassArcher
	   ForbiddenUpgradeNames		= Upgrade_CreateAHeroArrowBonus_Level4
    End
   
    ProjectileNugget                    // Default arrow
       ProjectileTemplateName	= NoldorGoldenArrowProjectile ;;,;; MirkwoodArcherSilverthornProjectile
       WarheadTemplateName		= CreateAHeroSuperRangedWarhead
	   RequiredUpgradeNames		= Upgrade_CreateAHeroArrowBonus_Level4 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
    End
End

Weapon CreateAHeroSuperRangedWarhead
	ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS // Remember, the projectile is a rock, who has no allies
	RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
	HitStoredTarget = Yes	// Always hits initial target.
	UseInnateAttributes	= Yes

	//	No bonus
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_BOW_DAMAGE ;;,;; 80
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = GOOD_ARROW_PIERCE
		DeathType     = NORMAL
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroToggleWeapon_Level2 Upgrade_CreateAHeroArrowBonus_Level1 Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End

	//	Level 1 Archer bonus
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_BOW_DAMAGE ;;,;; 80
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = GOOD_ARROW_PIERCE
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level1 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L1
		Radius        = CREATE_A_HERO_ARROW_BONUS_RADIUS_L1	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = SLASH
		DamageFXType  = GOOD_ARROW_PIERCE
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level1 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End

	//	Level 2 Archer bonus
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_BOW_DAMAGE ;;,;; 80
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = FLAME
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L1
		Radius        = CREATE_A_HERO_ARROW_BONUS_RADIUS_L1	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = SLASH
		DamageFXType  = FLAME
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L2
		Radius        = CREATE_A_HERO_ARROW_BONUS_RADIUS_L2	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = FLAME
		DamageFXType  = FLAME
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level2 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
		ForbiddenUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHeroArrowBonus_Level4
	End

	//	Level 3 Archer bonus
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_BOW_DAMAGE ;;,;; 80
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = MAGIC
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L1
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = SLASH
		DamageFXType  = MAGIC
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L2
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = FLAME
		DamageFXType  = MAGIC
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
	End
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L3
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = MAGIC
		DamageFXType  = MAGIC
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
	End

	//	Level 4 Archer Bonus
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = CREATE_A_HERO_ARROW_BONUS_DAMAGE_L4
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 10% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = FLAME ;;,;; MAGIC
		DeathType     = EXPLODED ;;,;; NORMAL
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level4 Upgrade_CreateAHero_ClassArcher ;;.;; Added Upgrade_CreateAHero_ClassArcher
	End

	MetaImpactNugget                    ; A Nugget that throws things back with force
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 30.0
		ShockWaveRadius   = H_ARCHER_RADIUS
		ShockWaveTaperOff = 1.0
		RequiredUpgradeNames	= Upgrade_CreateAHeroArrowBonus_Level3
		OnlyWhenJustDied = Yes
;    	ShockWaveZMult   = 0.75
;   	HeroResist		  = 0.90		; 90% resistance to heroes
    End
End

Weapon LegolasSuperBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
    DamageNugget                       					; A basic Nugget that just does damage
    	Damage        		= H_LEGOLAS_BOW_DAMAGE
    	Radius        		= 0.0					; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
   		DelayTime     		= 0
    	DamageType    		= HERO_RANGED
    	DamageFXType  		= GOOD_ARROW_PIERCE
    	DeathType     		= NORMAL
		ForbiddenUpgradeNames	= Upgrade_New1
  	End
	  
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE
		DamageScalar  = 50% NONE +HERO
		DamageScalar  = 150% NONE +MACHINE 
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_ObjectLevel3
		ForbiddenUpgradeNames	= Upgrade_New1
	End
  
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = H_LEGOLAS_BOW_DAMAGE
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = GOOD_ARROW_PIERCE
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End

	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE
		DamageScalar  = 50% NONE +HERO
		DamageScalar  = 150% NONE +MACHINE 
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End
	
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 50% ANY +STRUCTURE +HERO 
		DamageScalar  = 150% NONE +MACHINE -DwarvenBattleWagon
		DelayTime     = 0
		DamageType    = MAGIC
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New2
	End
	
    MetaImpactNugget                    ; A Nugget that throws things back with force
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 30.0
		ShockWaveRadius   = H_ARCHER_RADIUS
		ShockWaveTaperOff = 1.0
		RequiredUpgradeNames	= Upgrade_New1
		OnlyWhenJustDied = Yes
;    	ShockWaveZMult   = 0.75
;   	HeroResist		  = 0.90		; 90% resistance to heroes
    End
End

Weapon ElvenThranduilSuperBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
    DamageNugget                       					; A basic Nugget that just does damage
    	Damage        		= H_THRANDUIL_BOW_DAMAGE
    	;DamageScalar  		= 25000% NONE +MordorMumakil
    	Radius        		= 0.0					; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    	DelayTime     		= 0
    	DamageType    		= HERO_RANGED
    	DamageFXType  		= GOOD_ARROW_PIERCE
    	DeathType     		= NORMAL
		ForbiddenUpgradeNames	= Upgrade_New1
  	End

	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE 
		DamageScalar  = 150% NONE +MACHINE -DwarvenBattleWagon
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_ObjectLevel3
		ForbiddenUpgradeNames	= Upgrade_New1
	End
  
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = H_THRANDUIL_BOW_DAMAGE
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End

	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE
		DamageScalar  = 150% NONE +MACHINE -DwarvenBattleWagon  
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End
	
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 50% ANY +STRUCTURE +HERO 
		DamageScalar  = 150% NONE +MACHINE -DwarvenBattleWagon 
		DelayTime     = 0
		DamageType    = MAGIC
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New2
	End
	
    MetaImpactNugget                    ; A Nugget that throws things back with force
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 30.0
		ShockWaveRadius   = H_ARCHER_RADIUS
		ShockWaveTaperOff = 1.0
		RequiredUpgradeNames	= Upgrade_New1
		OnlyWhenJustDied = Yes
;    	ShockWaveZMult   = 0.75
;   	HeroResist		  = 0.90		; 90% resistance to heroes
    End
End

Weapon ElvenElrondBow
	AttackRange		= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed			= H_FAST_WEAPON_SPEED         			; dist/sec 
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      			; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX				= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes 				; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     			;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 5.0     			;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    CanFireWhileMoving		= Yes
    
	ProjectileNugget                    			; Default Arrow
		ProjectileTemplateName  = SilverFeatherArrow
		WarheadTemplateName     = ElvenElrondBowWarhead
	End
End

Weapon ElvenElrondBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
    DamageNugget                       					; A basic Nugget that just does damage
    Damage        		= H_ELROND_BOW_DAMAGE
    Radius        		= 0.0					; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DelayTime     		= 0
    DamageType    		= HERO_RANGED
    DamageFXType  		= EARTH2
    DeathType     		= NORMAL
	ForbiddenUpgradeNames	= Upgrade_New1
  End

  	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 150
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 40% NONE +STRUCTURE 
		DelayTime     = 0
		DamageType    = SIEGE
		DamageFXType  = EARTH2
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_ObjectLevel3
		ForbiddenUpgradeNames	= Upgrade_New1
	End
  
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = H_ELROND_BOW_DAMAGE
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageType    = HERO_RANGED
		DamageFXType  = EARTH2
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End

	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 150
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 40% ANY +STRUCTURE +HERO
		DelayTime     = 0
		DamageType    = SIEGE
		DamageFXType  = EARTH2
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End
	
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 100
		Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime     = 0
		DamageScalar  = 45% NONE +HERO
		DamageType    = MAGIC
		DamageFXType  = EARTH2
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New2
	End
	
    MetaImpactNugget                    ; A Nugget that throws things back with force
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 30.0
		ShockWaveRadius   = H_ARCHER_RADIUS
		ShockWaveTaperOff = 1.0
		RequiredUpgradeNames	= Upgrade_New1
		OnlyWhenJustDied = Yes
;    	ShockWaveZMult   = 0.75
;   	HeroResist		  = 0.90		; 90% resistance to heroes
    End
End

Weapon HaldirSuperBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS 
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = H_HALDIR_BOW_DAMAGE
    ;DamageScalar  = 25000% NONE +MordorMumakil
    Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DelayTime     = 0
    DamageType    = HERO_RANGED
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
  End
  
  DamageNugget                        // A basic Nugget that just does damage
	Damage        = 120
	Radius        = H_ARCHER_RADIUS	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
	DelayTime     = 0
	DamageScalar  = 40% NONE +STRUCTURE +HERO
	DamageType    = MAGIC
	DamageFXType  = MAGIC
	DeathType     = NORMAL
	RequiredUpgradeNames	= Upgrade_ObjectLevel8 ; 2.02 scheme: Upgrade_HaldirGoldenArrow
	End
	
  MetaImpactNugget                    ; A Nugget that throws things back with force
	SpecialObjectFilter = NONE +INFANTRY
	ShockWaveAmount   = 30.0
	ShockWaveRadius   = H_ARCHER_RADIUS
	ShockWaveTaperOff = 1.0
	RequiredUpgradeNames	= Upgrade_ObjectLevel8 ; 2.02 scheme: Upgrade_HaldirGoldenArrow
	OnlyWhenJustDied = Yes
    End
End

Weapon MirkwoodTaurielBow
	AttackRange		= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed		= H_FAST_WEAPON_SPEED         			; dist/sec 
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      			; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX			= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes 				; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     			;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 5.0     			;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    CanFireWhileMoving		= Yes

	ProjectileNugget                    ; Default arrow
	    ProjectileTemplateName    = OrangeFeatherArrow
	    WarheadTemplateName       = TaurielBowWarhead
	    ForbiddenUpgradeNames     = Upgrade_New1
	End
	
	ProjectileNugget                    ; Default arrow
	    ProjectileTemplateName    = RamaArrow
	    WarheadTemplateName       = TaurielBowWarhead
	    RequiredUpgradeNames   	  = Upgrade_New1
	End
End

Weapon TaurielBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget = Yes	; Always hits initial target.
    DamageNugget                       					; A basic Nugget that just does damage
    	Damage        		= H_TAURIEL_BOW_DAMAGE
    	Radius        		= 0.0					; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
   		DelayTime     		= 0
    	DamageType    		= HERO_RANGED
    	DamageFXType  		= GOOD_ARROW_PIERCE
    	DeathType     		= NORMAL
  	End
	  
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 40
		Radius        = 0.0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE
		DamageScalar  = 50% NONE +HERO
		DamageScalar  = 150% NONE +MACHINE 
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_ObjectLevel3
	End

	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 40
		Radius        = 0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 12% NONE +STRUCTURE
		DamageScalar  = 50% NONE +HERO
		DamageScalar  = 150% NONE +MACHINE 
		DelayTime     = 0
		DamageType    = HERO
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New1
	End
	
	DamageNugget                        // A basic Nugget that just does damage
		Damage        = 60
		Radius        = 0	// HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 50% ANY +STRUCTURE +HERO 
		DamageScalar  = 150% NONE +MACHINE
		DelayTime     = 0
		DamageType    = MAGIC
		DamageFXType  = SPARKS1
		DeathType     = NORMAL
		RequiredUpgradeNames	= Upgrade_New2
	End
	
    MetaImpactNugget                    ; A Nugget that throws things back with force
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 30.0
		ShockWaveTaperOff = 1.0
		RequiredUpgradeNames	= Upgrade_New1
		OnlyWhenJustDied = Yes
;    	ShockWaveZMult   = 0.75
;   	HeroResist		  = 0.90		; 90% resistance to heroes
    End
End

Weapon TaurielExplodingArrow
	AttackRange		= H_HERO_BOW_RANGE
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_HERO_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	LeechRangeWeapon	= Yes ;;,;; Added for 2.4				
	WeaponSpeed			= H_FAST_WEAPON_SPEED         			; dist/sec 
	MinWeaponSpeed		= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed		= H_FAST_WEAPON_SPEED_MAX      			; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX				= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed	= Yes 				; Used for lob weapons, scales speed proportional to range
	HitPercentage		= 100     			;When this weapon is used it will hit exactly 100% of the time.
	ScatterRadius		= 0.0     			;When this weapon misses it can randomly miss by as much as this distance.

	AcceptableAimDelta	= 20				; prevent twitchy reaiming in horde on horde
	DelayBetweenShots	= H_LEGOLAS_DELAYBETWEENSHOTS 	; time between shots, msec
	PreAttackDelay      	= H_LEGOLAS_PREATTACKDELAY 	; 1467 is the prep time for archer.
	PreAttackType       	= PER_POSITION 			; Do the delay each time we attack a new target
	FiringDuration      	= H_LEGOLAS_FIRINGDURATION 	; Duration of the archer firing shot is 500ms.

    ClipSize			= 1
    AutoReloadsClip		= Yes
    AutoReloadWhenIdle		= 1	
    ClipReloadTime		= Min:H_LEGOLAS_RELOADTIME_MIN Max:H_LEGOLAS_RELOADTIME_MAX
    ContinuousFireOne		= 0
    ContinuousFireCoast		= H_LEGOLAS_RELOADTIME_MAX

    AntiAirborneVehicle		= Yes
    AntiAirborneMonster		= Yes
    CanFireWhileMoving		= Yes
    
	ProjectileNugget										; A Nugget that creates an Object and sends it to the target with a Warhead
		ProjectileTemplateName	= ElectricSpecialArrow
		WarheadTemplateName	= TaurielExplodingArrowWarhead
	End
End

Weapon TaurielExplodingArrowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS 
  RadiusDamageAffects	 = ENEMIES NEUTRALS NOT_SIMILAR
  HitStoredTarget		 = Yes	; Always hits initial target.
  HitPercentage		     = 100	
 
  DamageNugget                       
	Damage        		= 50				
	DamageType    		= HERO
	DamageFXType  		= FLAME
	DeathType     		= BURNED
	Radius				= H_TAURIEL_EXPLODING_ARROW_RADIUS
  End
  
  MetaImpactNugget                    ; A Nugget that throws things back with force
	SpecialObjectFilter = NONE +INFANTRY
;	HeroResist			= .25
    ShockWaveAmount   = 70.0
    ShockWaveRadius   = H_TAURIEL_EXPLODING_ARROW_RADIUS ;,; 15.0
    ShockWaveTaperOff = 0.5
    ShockWaveZMult    = 1.20
	OnlyWhenJustDied = Yes
  End
  
End

Weapon GaladhrimBow     ; BALANCE Elven warrior bow Weapon
	AttackRange         = H_GALADHRIM_WARRIOR_BOW_RANGE
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( ROHAN_ELVEN_RANGE H_ARCHER_RANGE_MULTI )
	
	WeaponSpeed         = H_H_MED_WEAPON_SPEED         ; dist/sec 
	MinWeaponSpeed      = H_H_MED_WEAPON_SPEED_MIN
	MaxWeaponSpeed      = H_H_MED_WEAPON_SPEED_MAX      ; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	FireFX              = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed    = Yes ; Used for lob weapons, scales speed proportional to range
	HitPercentage       = 100     ;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius       = 16.0     ;When this weapon misses it can randomly miss by as much as this distance.
	  
	AcceptableAimDelta	= 20	; prevent twitchy reaiming in horde on horde
	DelayBetweenShots   = 0
	PreAttackDelay      = ROHAN_ELVENWARRIOR_BOW_PREATTACKDELAY 
	PreAttackRandomAmount     = 200 ;,; Uncommented 
	PreAttackType       = PER_POSITION
	FiringDuration      = 0

	OverrideVoiceAttackSound			= ElvenWarriorVoiceAttackBow
	OverrideVoiceEnterStateAttackSound	= ElvenWarriorVoiceEnterStateAttackBow
	  
	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 0 ;;1	
	ClipReloadTime		= Min:ROHAN_ELVENWARRIOR_BOW_RELOADTIME_MIN Max:ROHAN_ELVENWARRIOR_BOW_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= ROHAN_ELVENWARRIOR_BOW_RELOADTIME_MAX
	  
	AntiAirborneVehicle	= Yes
	AntiAirborneMonster	= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged				= Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

	ProjectileNugget                    ; Default arrow
	    ProjectileTemplateName    = GoodFactionArrow
	    WarheadTemplateName       = GaladhrimBowWarhead
	    ForbiddenUpgradeNames     = Upgrade_ElvenSilverthornArrows ;,; Upgrade_GondorFireArrows ;,; Upgrade_ElvenSilverthornArrows
	End
	ProjectileNugget                    ; Fire arrow available from fire arrow upgrade
	    ProjectileTemplateName    = MirkwoodArcherSilverthornProjectile
	    WarheadTemplateName       = GaladhrimSilverthorneBowWarhead ;,; ElvenBowSilverthorneWarhead
	    RequiredUpgradeNames      = Upgrade_ElvenSilverthornArrows ;,; Upgrade_GondorFireArrows ;,; Upgrade_ElvenSilverthornArrows
  	End
End

Weapon GaladhrimBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR ;,; Removed ALLIES
  HitStoredTarget = Yes	; Always hits initial target.
 
  DamageNugget                        ; A basic Nugget that just does damage
    Damage        = H_GALADHRIM_WARRIOR_BOW_DAMAGE
    Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
    DamageScalar  = 120% NONE +WildMarauderSwords ;,;
    DelayTime     = 0
    DamageType    = PIERCE
    DamageFXType  = GOOD_ARROW_PIERCE
    DeathType     = NORMAL
  End
End

Weapon GaladhrimSilverthorneBowWarhead
  ProjectileCollidesWith = ENEMIES NEUTRAL STRUCTURES WALLS ;ALLIES (4/23/04 removed friendly fire)
  RadiusDamageAffects = ENEMIES NEUTRALS NOT_SIMILAR ;,; Removed ALLIES
  HitStoredTarget = Yes	; Always hits initial target.

	DamageNugget                        ; A basic Nugget that just does damage
		Damage        = H_GALADHRIM_WARRIOR_BOW_DAMAGE
		Radius        = 0.0	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DamageScalar  = 120% NONE +WildMarauderSwords ;,;
		DelayTime     = 0
		DamageType    = PIERCE
		DamageFXType  = MAGIC ;;,;; GOOD_ARROW_PIERCE
		DeathType     = EXPLODED ;;,;; NORMAL
	End

	; Damage to everything else is increased
  	DamageNugget
	    Damage        	= H_GALADHRIM_WARRIOR_BOW_DAMAGE_MAGIC
		Radius        	= 0.0
	    DelayTime     	= 0
		DamageType		= MAGIC
		DamageFXType	= MAGIC
	    DeathType     	= EXPLODED
	    DamageScalar  	= 25% NONE +STRUCTURE
		AcceptDamageAdd = No ;;,;;
	End

  	MetaImpactNugget
		SpecialObjectFilter = NONE +INFANTRY
		ShockWaveAmount   = 50.0
		ShockWaveRadius   = 10.0
		ShockWaveArc      = 90 ; in degrees to each side 180 is full circle
		ShockWaveTaperOff = 1.0
		ShockWaveSpeed    = 0.0
		ShockWaveZMult    = 1.0
		OnlyWhenJustDied = Yes
	End

End

Weapon GaladhrimWarriorHordeRangefinder
	AttackRange			= #SUBTRACT( H_GALADHRIM_WARRIOR_BOW_RANGE 100 )  ; Slightly shorter than the archer's actual weapon
	
	RangeBonusMinHeight      = 10 ;	= 10
	RangeBonus		= 1
	RangeBonusPerFoot	= #MULTIPLY( H_GALADHRIM_WARRIOR_BOW_RANGE H_ARCHER_RANGE_MULTI )
	
	DelayBetweenShots		= 800
	LeechRangeWeapon		= Yes
	AcceptableAimDelta		= 45
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	CanFireWhileMoving		= Yes		; When aboard a ship.
	FinishAttackOnceStarted = No
	HordeAttackNugget
	End
End

Weapon GaladhrimBowSlaved       ; BALANCE Archer Weapon
	AttackRange               = 400

	WeaponSpeed               = 450      ; dist/sec 
	MinWeaponSpeed            = 340
	MaxWeaponSpeed            = 675		; dist/sec Upper limit on scaling, when attacking past nominal "max" range
	
	FireFX                    = FX_RohanArcherBowWeapon
	ScaleWeaponSpeed          = Yes		; Used for lob weapons, scales speed proportional to range
	HitPercentage             = 100		;When this weapon is used it will hit exactly 50% of the time.
	ScatterRadius             = 16.0		;When this weapon misses it can randomly miss by as much as this distance.
	
	AcceptableAimDelta				= 20	; prevent twitchy reaiming in horde on horde
  DelayBetweenShots   			= 400
	PreAttackDelay      			= ELVEN_MIRKWOOD_ARCHER_BOW_PREATTACKDELAY 
	PreAttackRandomAmount     = 200 ;,; Uncommented 
	PreAttackType       			= PER_POSITION
	FiringDuration      			= 0
	
	ClipSize			= 1
	AutoReloadsClip		= Yes
	AutoReloadWhenIdle	= 0;1	
	ClipReloadTime		= Min:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MIN Max:ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX
	ContinuousFireOne	= 0
	ContinuousFireCoast	= ELVEN_MIRKWOOD_ARCHER_BOW_RELOADTIME_MAX 

	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	HitPassengerPercentage	= 20%
	CanBeDodged = Yes ; Will check for a DodgePercent on the target to have a second chance at failing HitPercent

  ProjectileNugget          ; Default arrow
    ProjectileTemplateName  = GoodFactionArrow
    WarheadTemplateName     = SuperTowerBowWarhead
    ForbiddenUpgradeNames   = Upgrade_ElvenSilverthornArrowsTower
  End

  ProjectileNugget          ; Upgraded arrow
    ProjectileTemplateName  = MirkwoodArcherSilverthornProjectile
    WarheadTemplateName     = SuperTowerBowWarhead
    RequiredUpgradeNames		= Upgrade_ElvenSilverthornArrowsTower
  End

End

Weapon MakeLightOfTreesCaster ;;,;; added for 2.02e
	AttackRange 			= 999999

	WeaponOCLNugget
		WeaponOCLName = OCL_LightOfTreesCaster
	End
End

; WeatherKiller (weapon.ini) less its last block: Light of the Trees' own weather changer must not clear the sunbeams the same cast makes
Weapon WeatherKillerLightOfTrees
	RadiusDamageAffects	= ENEMIES NEUTRALS ALLIES

	DamageNugget
		DamageType	= FROST
		DeathType	= CRUSHED
		SpecialObjectFilter		= ANY +DarknessCaster +FreezingRainCaster +BlizzardCaster +BlizzardFXObject +DarknessAmbientSoundObject
		Radius		  = 999999
		ForceKillObjectFilter	= ANY +DarknessCaster +FreezingRainCaster +BlizzardCaster +BlizzardFXObject +DarknessAmbientSoundObject
	End

	DamageNugget
		DamageType	= FROST
		DeathType	= CRUSHED
		DelayTime     = 2000
		SpecialObjectFilter		= ANY +AmbientDimmer
		Radius		  = 999999
		ForceKillObjectFilter	= ANY +AmbientDimmer
	End

	DamageNugget
		DamageType	= FROST
		DeathType	= CRUSHED
		SpecialObjectFilter	= NONE ENEMIES +LightOfTreesCaster +LightOfTreesSunbeam
		Radius		  = 999999
		ForceKillObjectFilter	= NONE ENEMIES +LightOfTreesCaster +LightOfTreesSunbeam
	End
End

Weapon ConstantLightOfTrees ;;,;; 
	RadiusDamageAffects = ALLIES
	LeechRangeWeapon      = Yes
	AttackRange           = 999999
	MeleeWeapon           = No
	DelayBetweenShots     = 2000
	PreAttackDelay        = 0
	PreAttackType         = PER_SHOT 
	FiringDuration        = 0

	AttributeModifierNugget
		AttributeModifier        = SpellLightOfTreesBonus
		Radius			 		 = 999999
		SpecialObjectFilter      = H_GENERIC_BUFF_RECIPIENT_OBJECT_FILTER
		AffectHordeMembers 	 	 = Yes
		DamageFXType             = SWORD_SLASH
	End

	AttributeModifierNugget
		AttributeModifier        = SpellLightOfTreesSpeedBonus
		Radius			 		 = 999999
		SpecialObjectFilter      = H_GENERIC_SPEED_BUFF_OBJECT_FILTER
		AffectHordeMembers 	 	 = Yes
		DamageFXType             = SWORD_SLASH
	End
End

Weapon GlorfindelStarlight ;;,;; 
	RadiusDamageAffects = ALLIES
	LeechRangeWeapon      = Yes
	AttackRange           = 20
	MeleeWeapon           = No
	DelayBetweenShots     = 2000
	PreAttackDelay        = 0
	PreAttackType         = PER_SHOT 
	FiringDuration        = 0

	AttributeModifierNugget
		AttributeModifier        = GlorfindelStarlightBonus
		Radius			 		 				 = H_HERO_AURA_RANGE
		SpecialObjectFilter      = H_GENERIC_BUFF_RECIPIENT_OBJECT_FILTER
		AffectHordeMembers 	 	 	 = Yes
		DamageFXType             = SWORD_SLASH
	End

	; AttributeModifierNugget
	; 	AttributeModifier        = SpellLightOfTreesSpeedBonus
	; 	Radius			 		 = H_HERO_AURA_RANGE
	; 	SpecialObjectFilter      = H_GENERIC_SPEED_BUFF_OBJECT_FILTER
	; 	AffectHordeMembers 	 	 = Yes
	; 	DamageFXType             = SWORD_SLASH
	; End
End

Weapon RivendellKnightsLance       ; BALANCE
  LeechRangeWeapon      = Yes
  AttackRange           = STANDARD_MELEE_ATTACK_RANGE
  MeleeWeapon           = Yes
  FireFX                = FX_GondorSwordHit
  DelayBetweenShots     = GONDOR_KNIGHTSOFDOL_DELAYBETWEENSHOTS           ; time between shots, msec
  PreAttackDelay        = GONDOR_KNIGHTSOFDOL_PREATTACKDELAY				; 400 is sword swing delay time before contact with target.
  FiringDuration        = GONDOR_KNIGHTSOFDOL_FIRINGDURATION				; Duration of the sword swing
  PreAttackType         = PER_SHOT											; Do the delay each time we attack a new target

	DamageNugget
		Damage					= H_RIVENDELL_KNIGHTS_DAMAGE
		Radius					= 0.0
		DelayTime				= 0
		DamageType			= HERO
		DamageFXType		= SWORD_SLASH
		DeathType				= NORMAL
		DamageScalar		= 70% NONE +HERO
	End

	DamageNugget
		Damage					= H_RIVENDELL_KNIGHTS_DAMAGE_MAGIC
		Radius					= 0.0
		DelayTime				= 0
		DamageType			= MAGIC
		DamageFXType		= SWORD_SLASH
		DeathType				= NORMAL
		DamageScalar		= 80% NONE +HERO
		RequiredUpgradeNames    = Upgrade_ElvenForgedBlades
	End

	DamageNugget
		Damage				= H_RIVENDELL_KNIGHTS_DAMAGE_SIEGE
		Radius				= 0.0
		DelayTime			= 0
		DamageType		= SIEGE
		DamageFXType	= SWORD_SLASH
		DeathType			= NORMAL
		SpecialObjectFilter = NONE +STRUCTURE 
		RequiredUpgradeNames    = Upgrade_ObjectLevel5
	End
End

Weapon RivendellKnightsCrush
  LeechRangeWeapon      = Yes
  AttackRange           = 9999999.0
  MeleeWeapon           = No
  DelayBetweenShots     = 0				; time between shots, msec
  PreAttackDelay        = 0				;PreAttackDelay+FiringDuration = UseWeaponTiming = Yes duration
  PreAttackType         = PER_SHOT 
  FiringDuration        = 0
  FireFX		= FX_GenericCrushImpactSound

  DamageNugget
    Damage        = H_RIVENDELL_KNIGHTS_CRUSH_DAMAGE
		DamageScalar  	= 25% NONE +RohanSpearmen +GondorTowerShieldGuard +DwarvenPhalanx +ElvenMithlondSentry +ArnorTowerShieldGuard +AngmarRhudaurSpearman +IsengardPikeman +MordorEasterling ;,;
		DamageScalar  	= 50% NONE +AngmarThrallMaster +AngmarThrallMasterInn +AngmarThrallMasterBanner +AngmarThrallMasterSpearmenBanner +AngmarThrallMasterAxeBanner +AngmarThrallMasterSlingerBanner +AngmarThrallMasterOrcBanner +AngmarThrallMasterWolfBanner +AngmarThrallMasterHillmenBanner ;,;
    Radius        = 0.0
    DelayTime     = 0
    DamageType    = CRUSH
    DeathType     = CRUSHED ;,; NORMAL
    FlankingBonus = CAVALRY_FLANK_CRUSH_BONUS  ;,; 200%
  End

	DamageNugget
    Damage        = 40
		;DamageScalar  	= 25% NONE +RohanSpearmen +GondorTowerShieldGuard +DwarvenPhalanx +ElvenMithlondSentry +ArnorTowerShieldGuard +AngmarRhudaurSpearman +IsengardPikeman +MordorEasterling ;,;
		;DamageScalar  	= 50% NONE +AngmarThrallMaster +AngmarThrallMasterInn +AngmarThrallMasterBanner +AngmarThrallMasterSpearmenBanner +AngmarThrallMasterAxeBanner +AngmarThrallMasterSlingerBanner +AngmarThrallMasterOrcBanner +AngmarThrallMasterWolfBanner +AngmarThrallMasterHillmenBanner ;,;
    Radius        = 15
    DelayTime     = 0
    DamageType    = MAGIC
    DeathType     = CRUSHED ;,; NORMAL
		RequiredUpgradeNames    = Upgrade_ObjectLevel5

    ;FlankingBonus = CAVALRY_FLANK_CRUSH_BONUS  ;,; 200%
  End

End

Weapon MirkwoodTrapWeapon
	RadiusDamageAffects		= ENEMIES NEUTRALS
	AttackRange						= 1000
	FireFX 								= FX_Devastation
	;//Paralyze everything
	ParalyzeNugget
		Radius									= H_WAYSTONE_STUN_RADIUS
		Duration								= 5500
		SpecialObjectFilter     = ANGMAR_NECRO_SOUL_FREEZE_SPECIAL_OBJECT_FILTER
		ParalyzeFX							= FX_LorienStunEffect
		FreezeAnimation 				= Yes
		AffectHordeMembers 			= Yes		;This will propagate the effect down to the horde members
	End
End

; Thranduil's Pinning Shot (hero rework, level 5): an arrow that pins a hero or monster (it cannot move or attack) and hurts it
Weapon HEThranduilPinningShot
	AttackRange				= H_RW_HERO_POWER_REACH
	LeechRangeWeapon		= Yes
	WeaponSpeed				= H_FAST_WEAPON_SPEED
	MinWeaponSpeed			= H_FAST_WEAPON_SPEED_MIN
	MaxWeaponSpeed			= H_FAST_WEAPON_SPEED_MAX
	FireFX					= FX_RohanArcherBowWeapon
	ScaleWeaponSpeed		= Yes
	HitStoredTarget			= Yes
	HitPercentage			= 100
	DelayBetweenShots		= 5000
	PreAttackDelay			= 1
	PreAttackType			= PER_POSITION
	FiringDuration			= 1
	ClipSize				= 1
	AutoReloadsClip			= Yes
	AutoReloadWhenIdle		= 1
	ClipReloadTime			= Min:1500 Max:1500
	AntiAirborneVehicle		= Yes
	AntiAirborneMonster		= Yes
	ProjectileNugget
		ProjectileTemplateName	= HEThranduilPinningArrow ; the Deadeye arrow with red waves
		WarheadTemplateName		= HEThranduilPinningShotWarhead
	End
End

Weapon HEThranduilPinningShotWarhead
	ProjectileCollidesWith	= ENEMIES NEUTRAL STRUCTURES WALLS
	RadiusDamageAffects		= ENEMIES NEUTRALS NOT_SIMILAR
	HitStoredTarget			= Yes
	HitPercentage			= 100
	DamageNugget
		Damage				= H_THRANDUIL_PINNING_DAMAGE
		AcceptDamageAdd		= No ; powers grow with the level's percentage only
		Radius				= 0.0
		DelayTime			= 0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		DeathType			= NORMAL
	End
	ParalyzeNugget
		Radius				= 0.0
		Duration			= H_THRANDUIL_PINNING_DURATION
		SpecialObjectFilter	= ANY +HERO +MONSTER
		ParalyzeFX			= FX_PoisonedStunEffect
	End
	ParalyzeNugget						; Hunter's Snare: 5 s
		Radius				= 0.0
		Duration			= 5000
		SpecialObjectFilter	= ANY +HERO +MONSTER
		RequiredUpgradeNames = Upgrade_HEThranduilHunter2
	End
	ParalyzeNugget						; Hunter III: the pin takes the soldiers, heroes and monsters within 50 of the target
		Radius				= 50.0
		Duration			= 5000
		SpecialObjectFilter	= ANY +INFANTRY +CAVALRY +HERO +MONSTER
		ParalyzeFX			= FX_PoisonedStunEffect
		RequiredUpgradeNames = Upgrade_HEThranduilHunter3
	End
	DamageNugget						; Hunter's Snare: +200 hero damage on the target (Hunter's Net spreads it instead)
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 0.0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		RequiredUpgradeNames = Upgrade_HEThranduilHunter2
		ForbiddenUpgradeNames = Upgrade_HEThranduilHunter3
	End
	DamageNugget						; Hunter's Net: the +200 on the soldiers, heroes and monsters within 50 of the target, the target too
		Damage				= 200
		AcceptDamageAdd		= No
		Radius				= 50.0
		DamageType			= HERO
		DamageFXType		= GOOD_ARROW_PIERCE
		SpecialObjectFilter	= ANY +INFANTRY +CAVALRY +HERO +MONSTER
		RequiredUpgradeNames = Upgrade_HEThranduilHunter3
	End
	MetaImpactNugget					; Hunter's Net: the soldiers it kills are thrown back
		SpecialObjectFilter	= NONE +INFANTRY
		ShockWaveAmount		= 30.0
		ShockWaveRadius		= 50.0
		ShockWaveTaperOff	= 1.0
		OnlyWhenJustDied	= Yes
		RequiredUpgradeNames = Upgrade_HEThranduilHunter3
	End
End
