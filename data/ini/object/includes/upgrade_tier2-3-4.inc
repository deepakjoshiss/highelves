;,;Thanks for BfMe2 1.09 team

;,; TIER 2 DISCOUNT FOR ARROW UPGRADES AND TIER 3 FOR BANNER UPGRADES (NO DISCOUNT ON OTHER UPGRADES)
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		GiveNoXP = Yes
		ProductionModifier
			CostMultiplier	= 0.80
			ModifierFilter = ANY +Upgrade_GondorBasicTraining +Upgrade_ElvenBasicTraining +Upgrade_DwarvenBasicTraining +Upgrade_MordorBasicTraining +Upgrade_IsengardBasicTraining +Upgrade_WildBasicTraining +Upgrade_AngmarBasicTraining
		End
		ProductionModifier
			CostMultiplier	= 0.667
			ModifierFilter = ANY +Upgrade_GondorFireArrows +Upgrade_ElvenSilverthornArrows +Upgrade_DwarvenFireArrows +Upgrade_MordorFireArrows +Upgrade_IsengardFireArrows +Upgrade_WildFireArrows +Upgrade_AngmarIceArrows
		End
	End