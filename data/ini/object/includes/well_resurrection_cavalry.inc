;/////////////////////////////////////////////////////////
;// Well resurrection horde module
 ;/////////////////////////////////////////////////////////

   	Behavior = ObjectCreationUpgrade ModuleTag_GrantDelayedFortUpgrade ;,;
		TriggeredBy             = Upgrade_FortRespawnCountdown
		Delay                   = STANDARD_CAV_RESURRECTION_DELAY
        GrantUpgrade            =  Upgrade_FortRespawnStart
	End

  	Behavior = ObjectCreationUpgrade ModuleTag_GrantDelayedWellUpgrade ;,;
		TriggeredBy             = Upgrade_WellRespawnCountdown
		Delay                   = STANDARD_CAV_RESURRECTION_DELAY
        GrantUpgrade            =  Upgrade_WellRespawnStart
	End

    Behavior = ObjectCreationUpgrade ModuleTag_GrantDelayedHearthUpgrade ;,;
		TriggeredBy             = Upgrade_BWRespawnCountdown
		Delay                   = BATTLEWAGON_STANDARD_RESURRECTION_DELAY
        GrantUpgrade            = Upgrade_BWRespawnStart
	End

    Behavior = BannerCarrierUpdate FortResurrectionModuleTag
        UpgradeRequired         = Upgrade_FortRespawnStart ;,; 
        IdleSpawnRate            = WELL_STANDARD_CAVALRY_RESURRECTION_RATE    ; spawn a new member every n seconds when idle (in miliseconds)
        ;,; MeleeFreeUnitSpawnTime            = 12000    ; n miliseconds units must not have been fighting to be able to spawn units when idle (in miliseconds) ;,;
        UnitSpawnFX            = FX_BannerCarrierSpawnUnit ;
        ReplenishNearbyHorde        = Yes
        ScanHordeDistance        = 0 ;,;
    End

    Behavior = BannerCarrierUpdate WellResurrectionModuleTag
        UpgradeRequired         = Upgrade_WellRespawnStart ;,; 
        IdleSpawnRate            = WELL_STANDARD_CAVALRY_RESURRECTION_RATE    ; spawn a new member every n seconds when idle (in miliseconds)
        MeleeFreeUnitSpawnTime            = STANDARD_CAV_RESURRECTION_DELAY    ; n miliseconds units must not have been fighting to be able to spawn units when idle (in miliseconds) ;,;
        UnitSpawnFX            = FX_BannerCarrierSpawnUnit ;
        ReplenishNearbyHorde        = Yes
        ScanHordeDistance        = 0 ;,;
    End

    Behavior = BannerCarrierUpdate BWResurrectionModuleTag
        UpgradeRequired         = Upgrade_BWRespawnStart ;,; 
        IdleSpawnRate            = BATTLEWAGON_STANDARD_RESURRECTION_RATE    ; spawn a new member every n seconds when idle (in miliseconds)
        ;,; MeleeFreeUnitSpawnTime            = 12000    ; n miliseconds units must not have been fighting to be able to spawn units when idle (in miliseconds) ;,;
        UnitSpawnFX            = FX_BannerCarrierSpawnUnit ;
        ReplenishNearbyHorde        = Yes
        ScanHordeDistance        = 0 ;,;
    End    
    
    Behavior = AutoHealBehavior ModuleTag_BWHealing    ;;,;;
        StartsActive             = No
        TriggeredBy             = Upgrade_BWRespawnStart
        HealingAmount             = BATTLEWAGON_HEARTH_HEAL_AMOUNT
        HealingDelay             = BATTLEWAGON_HEARTH_HEAL_DELAY
        UnitHealPulseFX            = FX_SpellHealUnitHealBuff
        NonStackable            = No
        HealOnlyIfNotUnderAttack    = Yes
        HealOnlyIfNotInCombat = Yes ;,; 
        AffectsContained        = Yes
    End
    