;	Behavior = GrantUpgradeCreate ModuleTag_ActLikeAnOldUpgrade
;		UpgradeToGrant = Upgrade_ObjectLevel1 ;,; 
;		GiveOnBuildComplete = Yes ;,; 
;    End

;	Behavior = ObjectCreationUpgrade ModuleTag_SpawnTicker ;,;
;		TriggeredBy             = Upgrade_ObjectLevel1
;		Delay                   = 3000.0
;		ThingToSpawn            = LuaEcoTicker
;        Offset                  = X:0 Y:0 Z:0
;	End

	Behavior = AttributeModifierAuraUpdate ModuleTag_Damaged ;,;
        TriggeredBy = Upgrade_Damaged
        BonusName = DamagedStructureModifier
        RefreshDelay = 1000 
        AllowSelf = Yes
    End

	Behavior = AttributeModifierAuraUpdate ModuleTag_ReallyDamaged ;,;
        TriggeredBy = Upgrade_ReallyDamaged
        BonusName = ReallyDamagedStructureModifier
        RefreshDelay = 1000 
        AllowSelf = Yes
    End

;,; ============== stop repair while being damaged ==================== ;,; 
    Behavior = PassiveAreaEffectBehavior ModuleTag_StopRepair;,;
        UpgradeRequired = Upgrade_StopRepair
        EffectRadius            = 100
        PingDelay            = 50 ;,; 250
        ModifierName            = WorkerDebuff
        AllowFilter            = ANY +MordorFarmWorkerNoSelect +GondorFarmWorkerNoSelect +ElvenFarmWorkerNoSelect +DwarvenFarmWorkerNoSelect
    End

    ;,; check every 2 sec if there are any workers repairing that shouldn't be ;,; 
    
    Behavior = PassiveAreaEffectBehavior ModuleTag_BackupStopRepair;,;
        UpgradeRequired = Upgrade_StopRepair
        EffectRadius            = 100
        PingDelay            = 2000 
        ModifierName            = BackupWorkerDebuff
        AllowFilter            = ANY +MordorFarmWorkerNoSelect +GondorFarmWorkerNoSelect +ElvenFarmWorkerNoSelect +DwarvenFarmWorkerNoSelect
    End


;,; =================== end ===================================== ;,; 