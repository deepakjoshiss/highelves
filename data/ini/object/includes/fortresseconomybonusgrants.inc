//;;,;; Fortress granteconomybonus behaviors moved to this file for 2.1, now that we're adding Scavenger too.
//;;,;; It'll be much easier to maintain and allow us to change all our Fortresses at once :)

	Behavior = AttributeModifierAuraUpdate ModuleTag_AllowDwarvenRiches ;;,;; First added in 2.02e
		StartsActive	= No ;If no, requires upgrade to turn on.
		BonusName		= SpellBookDwarvenRiches
		TriggeredBy		= Upgrade_GrantDwarvenRiches
		RefreshDelay	= 2000
		Range			= 999999
		TargetEnemy		= No ;
		ObjectFilter	= ANY +DwarvenMineShaft +DwarvenMineShaftForUndermine
	End	
	
;,; Passive Fuel the Fires	

;,;	Behavior = AttributeModifierAuraUpdate ModuleTag_AllowFuelTheFires ;;,;; First added in 2.02e
;,;		StartsActive	= No ;If no, requires upgrade to turn on.
;,;		BonusName		= SpellBookFueltheFires
;,;		TriggeredBy		= Upgrade_GrantFueltheFires ; Upgrade_FortressGrantFueltheFires
;,;		RefreshDelay	= 2000
;,;		Range			= 999999
;,;		TargetEnemy		= No ;
;,;		ObjectFilter	= ANY SAME_PLAYER +IsengardLumberMill ;,; Added SAME_PLAYER +SUPPLY_GATHERING_CENTER 
;,;	End	

;,; Passive Fuel the Fires
;,;	Behavior = AttributeModifierAuraUpdate ModuleTag_ReplaceWorkers ;;,;; First added in 2.02e
;,;		StartsActive	= No ;If no, requires upgrade to turn on.
;,;		BonusName		= OnFuelLumberMillWorkerModifier
;,;		TriggeredBy		= Upgrade_GrantFueltheFires ; Upgrade_FortressGrantFueltheFires
;,;		RefreshDelay	= 1800 ;,; 2000
;,;		Range			= 999999
;,;		TargetEnemy		= No ;
;,;		ObjectFilter	= ANY SAME_PLAYER +MordorWorker +MordorWorkerFuels ;,; Added SAME_PLAYER +SUPPLY_GATHERING_CENTER 
;,;	End

	
	Behavior = AttributeModifierAuraUpdate ModuleTag_AllowScavenger ;;,;; First added in 2.1
		StartsActive	= No ;If no, requires upgrade to turn on.
		BonusName		= SpellBookScavenger
		TriggeredBy		= Upgrade_GrantScavenger
		RefreshDelay	= 2000
		Range			= 999999
		TargetEnemy		= No ;
		ObjectFilter	= ANY SAME_PLAYER WILD_EVIL_UNIT_FILTER +WildAzog +WildGoblinKing +WildShelob +Drogoth +WildMountainGiant +Wyrm +WyrmCE +SummonedDragon +SummonedDragonJH1 +WatcherHead +WatcherHittingArm +WatcherEgg +SpellBookDragonStrikeDragon +WildMountainGiant_Summoned +MordorBalrog +BarrowWight +LesserWight +IsengardWargPack ;,; Added SAME_PLAYER +Wyrm +SummonedDragon +SummonedDragonJH1 +WatcherHead +WatcherHittingArm +WatcherEgg +SpellBookDragonStrikeDragon +WildMountainGiant_Summoned ; Intended to affect EvilBeasts units even in another faction's hands.
	End	
