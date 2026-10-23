;;,;; 2.02e Drake Broodling Drake DoT Breath

;------------------------------------------------------------------------------
 	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= BABYDRAKE_FLAME_DELAY
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake +WyrmCE +Wyrm
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 200
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 400
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 600
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 800
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 1000
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End
;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( BABYDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 125% ANY +HERO ;,;
		DamageScalar    = 40% ANY +STRUCTURE ;,; 66% ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= BABYDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 1200
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= BABYDRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
	End