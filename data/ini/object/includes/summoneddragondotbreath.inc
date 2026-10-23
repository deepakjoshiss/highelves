;;,;; 2.02e Summoned Dragon DoT Breath

;------------------------------------------------------------------------------
	DamageNugget                        ; The large 90 degree arc
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 350
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,;  
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget                        ; The large 90 degree arc ;,;
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 );,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 200
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	
	;,;DamageNugget						; The small area directly in front.
	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
	;,;	DelayTime		= 200
	;,;	DamageType		= FLAME
	;,;	DamageFXType	= FLAME
	;,;	DeathType		= BURNED
	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
	;,;	DamageSpeed		= 400
	;,;End

	DamageNugget
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 650
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget ;,;
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 500
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,; 
		DamageScalar  = 750% NONE +WyrmCE +Wyrm  ;,;  
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End

;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 400
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 ) 
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 400
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 400
;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 400
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 400
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 
;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 600
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 600
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 600
;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 600
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 600
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 
;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 800
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 800
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 800
;,; ;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 800
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 800
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End

;------------------------------------------------------------------------------
	DamageNugget                        ; The large 90 degree arc
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 950
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget                        ; The large 90 degree arc ;,;
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 800
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	
	;,;DamageNugget						; The small area directly in front.
	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
	;,;	DelayTime		= 1000
	;,;	DamageType		= FLAME
	;,;	DamageFXType	= FLAME
	;,;	DeathType		= BURNED
	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
	;,;	DamageSpeed		= 400
	;,;End

	DamageNugget
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 1250
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget ;,;
		Damage			=  #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 1100
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,; 
		DamageScalar  = 750% NONE +WyrmCE +Wyrm  ;,;  
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End

;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1200
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 ) 
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1200
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 1200
;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1200
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1200
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End

;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1400
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1400
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 1400
;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1400
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1400
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End

;,; ;------------------------------------------------------------------------------
;,; 	DamageNugget                        ; The large 90 degree arc
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1600
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	DamageNugget                        ; The large 90 degree arc ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1600
;,; 		DamageType		= FLAME
;,; 		DamageFXType	= FLAME
;,; 		DeathType		= BURNED
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,;         DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
;,; 	End
;,; 	
;,; 	;,;DamageNugget						; The small area directly in front.
;,; 	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
;,; 	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
;,; 	;,;	DelayTime		= 1600
;,; 	;,;	DamageType		= FLAME
;,; 	;,;	DamageFXType	= FLAME
;,; 	;,;	DeathType		= BURNED
;,; 	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 	;,;	DamageSpeed		= 400
;,; 	;,;End
;,; 
;,; 	DamageNugget
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
;,; 		DelayTime		= 1600
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End
;,; 	DamageNugget ;,;
;,; 		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
;,; 		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
;,; 		DelayTime		= 1600
;,; 		DamageType		= MAGIC
;,; 		DamageFXType	= FLAME ;,;
;,; 		DeathType		= BURNED ;,;
;,; 		;,;DamageArc		= 90
;,; 		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
;,; 		DamageSpeed		= 400
;,; 	End

;------------------------------------------------------------------------------
	DamageNugget                        ; The large 90 degree arc
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 1550
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget                        ; The large 90 degree arc ;,;
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 1400
		DamageType		= FLAME
		DamageFXType	= FLAME
		DeathType		= BURNED
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
        DamageScalar  = 200000% NONE +MINE ;,; Make sure we one shot kill mines
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,; 
		DamageScalar  = 750% NONE +WyrmCE +Wyrm  ;,;  
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	
	;,;DamageNugget						; The small area directly in front.
	;,;	Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.056 )
	;,;	Radius			= #MULTIPLY( SUMMONED_DRAGON_FLAME_RADIUS 0.25 )
	;,;	DelayTime		= 1800
	;,;	DamageType		= FLAME
	;,;	DamageFXType	= FLAME
	;,;	DeathType		= BURNED
	;,;	DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
	;,;	DamageSpeed		= 400
	;,;End

	DamageNugget
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_RADIUS
		DelayTime		= 1850
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,; 
		DamageScalar  = 750% NONE +WyrmCE +Wyrm  ;,;  
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
	DamageNugget ;,;
		Damage			= #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.333 ) ;,; #MULTIPLY( SUMMONED_DRAGON_FLAME_TARGET_DAMAGE 0.111 )
		Radius			= SUMMONED_DRAGON_FLAME_TARGET_RADIUS
		DelayTime		= 1700
		DamageType		= MAGIC
		DamageFXType	= FLAME ;,;
		DeathType		= BURNED ;,;
		;,;DamageArc		= 90
		DamageMaxHeight = 20 ;;,;; 50 ;We won't hurt something far above us.  Birds fly at around 100
		DamageSpeed		= 400
		DamageScalar  = 40% NONE +AngmarShadeWolf +MordorBalrog ;,;
		DamageScalar  = 750% NONE +WyrmCE +Wyrm ;,; 
		DamageScalar  = 300% NONE +SummonedDragon +SummonedDragonJH1 ;,;
	End
