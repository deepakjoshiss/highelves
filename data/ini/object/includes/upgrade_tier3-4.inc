;,;Thanks for BfMe2 1.09 team

;,; TIER 3 DISCOUNT FOR BANNER UPGRADES (NO DISCOUNT ON OTHER UPGRADES)
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		 GiveNoXP = Yes
		ProductionModifier
			CostMultiplier	= 0.80
			ModifierFilter = ANY +Upgrade_GondorBasicTraining +Upgrade_ElvenBasicTraining +Upgrade_DwarvenBasicTraining +Upgrade_MordorBasicTraining +Upgrade_IsengardBasicTraining +Upgrade_WildBasicTraining +Upgrade_AngmarBasicTraining
		End
	End