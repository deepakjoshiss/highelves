;,; 2.02 v8.4 AI Resource and CP Bonus

;,; Brutal Bonuses ;,;
Behavior = AttributeModifierUpgrade ModuleTag_BrutalAISinglePlayer
        TriggeredBy                = Upgrade_BrutalAISinglePlayer Upgrade_AITeam1 ;,; dj-dev: alone on its team (OpenBFMEAITeamUpgrades)
		RequiresAllTriggers = Yes
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level1
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_BrutalAISinglePlayer2
        TriggeredBy                = Upgrade_BrutalAISinglePlayer Upgrade_StructureLevel2
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_BrutalAISinglePlayer3 
        TriggeredBy                = Upgrade_BrutalAISinglePlayer Upgrade_StructureLevel3
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level3
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIBrutalMultiplayer
        TriggeredBy                = Upgrade_BrutalAIMultiPlayer Upgrade_AITeam1 ;,; dj-dev: alone on its team (OpenBFMEAITeamUpgrades)
		RequiresAllTriggers = Yes
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level1
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIBrutalMultiplayer2 
        TriggeredBy                = Upgrade_BrutalAIMultiPlayer Upgrade_StructureLevel2
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIBrutalMultiplayer3 
        TriggeredBy                = Upgrade_BrutalAIMultiPlayer Upgrade_StructureLevel3
        AttributeModifier        = BrutalAIResourceBuildingBonus_Level3
		RequiresAllTriggers = Yes
    End
	
;,; Hard Bonuses ;,;

	Behavior = AttributeModifierUpgrade ModuleTag_HardAISinglePlayer
        TriggeredBy                = Upgrade_HardAISinglePlayer Upgrade_AITeam1 ;,; dj-dev: alone on its team (OpenBFMEAITeamUpgrades)
		RequiresAllTriggers = Yes
        AttributeModifier        = HardAIResourceBuildingBonus_Level1
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_HardAISinglePlayer2 
        TriggeredBy                = Upgrade_HardAISinglePlayer Upgrade_StructureLevel2
        AttributeModifier        = HardAIResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_HardAISinglePlayer3 
        TriggeredBy                = Upgrade_HardAISinglePlayer Upgrade_StructureLevel3
        AttributeModifier        = HardAIResourceBuildingBonus_Level3
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIHardMultiplayer
        TriggeredBy                = Upgrade_HardAIMultiPlayer Upgrade_AITeam1 ;,; dj-dev: alone on its team (OpenBFMEAITeamUpgrades)
		RequiresAllTriggers = Yes
        AttributeModifier        = HardAIResourceBuildingBonus_Level1
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIHardMultiplayer2 
        TriggeredBy                = Upgrade_HardAIMultiPlayer Upgrade_StructureLevel2
        AttributeModifier        = HardAIResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	
	Behavior = AttributeModifierUpgrade ModuleTag_AIHardMultiplayer3 
        TriggeredBy                = Upgrade_HardAIMultiPlayer Upgrade_StructureLevel3
        AttributeModifier        = HardAIResourceBuildingBonus_Level3
		RequiresAllTriggers = Yes
    End	

;,; dj-dev (OpenBFMEAITeamUpgrades): a computer with allies gets the extra income from level 2 (Upgrade_AITeam2: a team of 2 or more)
	Behavior = AttributeModifierUpgrade ModuleTag_BrutalAISinglePlayerTeam2
        TriggeredBy                = Upgrade_BrutalAISinglePlayer Upgrade_StructureLevel2 Upgrade_AITeam2
        AttributeModifier        = AITeamResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	Behavior = AttributeModifierUpgrade ModuleTag_AIBrutalMultiplayerTeam2
        TriggeredBy                = Upgrade_BrutalAIMultiPlayer Upgrade_StructureLevel2 Upgrade_AITeam2
        AttributeModifier        = AITeamResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	Behavior = AttributeModifierUpgrade ModuleTag_HardAISinglePlayerTeam2
        TriggeredBy                = Upgrade_HardAISinglePlayer Upgrade_StructureLevel2 Upgrade_AITeam2
        AttributeModifier        = AITeamResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
	Behavior = AttributeModifierUpgrade ModuleTag_AIHardMultiplayerTeam2
        TriggeredBy                = Upgrade_HardAIMultiPlayer Upgrade_StructureLevel2 Upgrade_AITeam2
        AttributeModifier        = AITeamResourceBuildingBonus_Level2
		RequiresAllTriggers = Yes
    End
