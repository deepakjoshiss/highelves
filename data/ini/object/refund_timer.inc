
    Behavior = ObjectCreationUpgrade ModuleTag_MakeEligibleForRefund ;,;
		TriggeredBy 			= Upgrade_MordorFaction Upgrade_WildFaction Upgrade_AngmarFaction Upgrade_ArnorFaction Upgrade_IsengardFaction Upgrade_MenFaction Upgrade_DwarfFaction Upgrade_ElfFaction
        Delay                   = 0.0
        GrantUpgrade            = Upgrade_ObjectLevel10 ;,; 
    End

    Behavior = ObjectCreationUpgrade ModuleTag_MakeIneligibleForRefund ;,;
		TriggeredBy 			= Upgrade_MordorFaction Upgrade_WildFaction Upgrade_AngmarFaction Upgrade_ArnorFaction Upgrade_IsengardFaction Upgrade_MenFaction Upgrade_DwarfFaction Upgrade_ElfFaction
        Delay                   = 6000.0
        RemoveUpgrade           = Upgrade_ObjectLevel10 ;,; 
    End
	