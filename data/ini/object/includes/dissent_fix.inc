    Behavior = ObjectCreationUpgrade ModuleTag_TriggerHoldGroundUpgrade;,;
        TriggeredBy             = Upgrade_OnDissentTrigger
        Delay                   = 200.0
        GrantUpgrade            = Upgrade_HoldGroundStance
    End

    Behavior = ObjectCreationUpgrade ModuleTag_TriggerNeutralStanceUpgrade;,;
        TriggeredBy             = Upgrade_OnDissentTrigger
        Delay                   = 2400.0
        GrantUpgrade            = Upgrade_NeutralStance
    End

    Behavior = DoCommandUpgrade ModuleTag_TriggerHoldGround ;,;
        TriggeredBy                        = Upgrade_HoldGroundStance
        GetUpgradeCommandButtonName        = Command_SetStanceHoldGround
    End
    
    Behavior = DoCommandUpgrade ModuleTag_TriggerNeutralStance2 ;,;
        TriggeredBy                        = Upgrade_NeutralStance
        GetUpgradeCommandButtonName        = Command_SetStanceBattle
    End
