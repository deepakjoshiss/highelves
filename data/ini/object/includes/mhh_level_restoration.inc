	Behavior = GrantUpgradeCreate ModuleTag_ActLikeAnOldUpgrade
		UpgradeToGrant = Upgrade_ObjectLevel1
	End
	
    Behavior = LevelUpUpgrade ModuleTag_LevelUp2
        TriggeredBy            = Upgrade_ObjectLevel2
        LevelsToGain        = 1
        LevelCap            = 2
    End  

    Behavior = LevelUpUpgrade ModuleTag_LevelUp3
        TriggeredBy            = Upgrade_ObjectLevel3
        LevelsToGain        = 2
        LevelCap            = 3
    End  

    Behavior = LevelUpUpgrade ModuleTag_LevelUp4
        TriggeredBy            = Upgrade_ObjectLevel4
        LevelsToGain        = 3
        LevelCap            = 4
    End  

    Behavior = LevelUpUpgrade ModuleTag_LevelUp5
        TriggeredBy            = Upgrade_ObjectLevel5
        LevelsToGain        = 4
        LevelCap            = 5
    End 
    