;;,;; 2.02e Wyrm DoT Breath

;------------------------------------------------------------------------------
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		Radius			= WYRM_FIRE_RADIUS
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageArc		= 45
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
	End

	; To catch the units standing right on the point of the triangle.
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1
        DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;		
 		Radius			= WYRM_FIRE_RADIUS
 		DelayTime		= 200 ;,; 250 ;,; 200
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 		DamageSpeed		= 400
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 200 ;,; 250 ;,; 200
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		Radius			= WYRM_FIRE_RADIUS
 		DelayTime		= 400 ;,; 500 ;,; 400
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 		DamageSpeed		= 400
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 400 ;,; 500 ;,; 400
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
 		Radius			= WYRM_FIRE_RADIUS
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 600 ;,; 750 ;,; 600
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 		DamageSpeed		= 400
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 600 ;,; 750 ;,; 600
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		Radius			= WYRM_FIRE_RADIUS
		DelayTime		= 800 ;,; 1000 ;,; 800
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 		DamageSpeed		= 400
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 800 ;,; 1000 ;,; 800
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
  		Radius			= WYRM_FIRE_RADIUS
 		DelayTime		= 1000 ;,; 1250 ;,; 1000
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 		DamageSpeed		= 400
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 1000 ;,; 1250 ;,; 1000
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End

;------------------------------------------------------------------------------
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		Radius			= WYRM_FIRE_RADIUS
 		DelayTime		= 1200 ;,; 1500 ;,; 1200
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageArc		= 45
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End
 
 	; To catch the units standing right on the point of the triangle.
 	DamageNugget															; A basic Nugget that just does damage
 		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
 		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
 		DelayTime		= 1200 ;,; 1500 ;,; 1200
 		DamageType		= FLAME
 		DamageFXType	= FLAME
 		DeathType		= BURNED
 		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
 	End
	
		;------------------------------------------------------------------------------
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= WYRM_FIRE_RADIUS
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1400
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageArc		= 45
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
	End

	; To catch the units standing right on the point of the triangle.
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1400
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
	End
	
			;------------------------------------------------------------------------------
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= WYRM_FIRE_RADIUS
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1600
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageArc		= 45
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
	End

	; To catch the units standing right on the point of the triangle.
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1600
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
	End
	
	;------------------------------------------------------------------------------
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= WYRM_FIRE_RADIUS
		DamageScalar    = 25% ANY +STRUCTURE -COMMANDCENTER ;,;
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1800 ;,; 1750 ;,; 1800
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageArc		= 45
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
	End

	; To catch the units standing right on the point of the triangle.
	DamageNugget															; A basic Nugget that just does damage
		Damage			= #MULTIPLY( WYRM_FIRE_DAMAGE .100 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.125 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE 0.34 ) ;,; #MULTIPLY( WYRM_FIRE_DAMAGE .100 )
		Radius			= 20
		DamageScalar    = 40% NONE +AngmarShadeWolf ;,; 
		DamageScalar  	= 17500% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  	= 3000% NONE +WildFireDrake_Summoned +FireDrake_Slaved +WildFortressFireDrake +WildBabyDrake
		DamageScalar  	= 7500% NONE +SummonedDragon +SummonedDragonJH1	
		DamageScalar  	= 300% ANY +GondorSentryTower_Independant +DwarvenSentryTower_Independent  +MordorBarricade -GondorSentryTower -DwarvenSentryTower -MordorFortressBarricadeExpansion ;,;
		DelayTime		= 1800 ;,; 1750 ;,; 1800
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		DamageMaxHeight = 20 ;;,;; 50												; We won't hurt something far above us.  Birds fly at around 100
	End