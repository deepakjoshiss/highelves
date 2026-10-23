;;,;; 2.02e Fire Drake DoT Breath

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= FIREDRAKE_FLAME_DELAY
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 10000% NONE +WyrmCE +Wyrm
		DamageScalar  	= 3000% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 200
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 400
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 10000% NONE +WyrmCE +Wyrm
		DamageScalar  	= 3000% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 600
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 800
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 10000% NONE +WyrmCE +Wyrm
		DamageScalar  	= 3000% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 1000
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End

;------------------------------------------------------------------------------
  	DamageNugget                        ; A basic Nugget that just does damage
		Damage			= #MULTIPLY( FIREDRAKE_FLAME_DAMAGE .143 )
		DamageScalar    = 66% ANY +STRUCTURE ;,;
		DamageScalar    = 50% ANY +MordorBlackRider ;,;
		Radius			= FIREDRAKE_FLAME_RADIUS	; HitStoredTarget means we hurt the person we launched at.  And nobody else.  So a miss hurts nobody.
		DelayTime		= 1200
		DamageScalar    = 200% ANY +DwarvenBattleWagon ;,; 150%
		DamageType		= FLAME
		DamageFXType		= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;50	;;,;; 2.3 fix
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 10000% NONE +WyrmCE +Wyrm
		DamageScalar  	= 3000% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= DRAKE_SCALAR_VS_BLACKRIDERS ANY +MordorBlackRider
	End
