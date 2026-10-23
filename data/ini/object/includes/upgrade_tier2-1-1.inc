;,;Thanks for BfMe2 1.09 team

;,; TIER 2 DISCOUNT FOR ARROW UPGRADES AND TIER 1 DISCOUNT FOR WEAPON, ARMOR, BANNER UPGRADES
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		GiveNoXP = Yes
		ProductionModifier
			CostMultiplier	= 0.25
			ModifierFilter = ANY +Upgrade_GondorBasicTraining +Upgrade_ElvenBasicTraining +Upgrade_DwarvenBasicTraining +Upgrade_MordorBasicTraining +Upgrade_IsengardBasicTraining +Upgrade_WildBasicTraining +Upgrade_AngmarBasicTraining
		End
		ProductionModifier
			CostMultiplier	= 0.5
			ModifierFilter = ANY +Upgrade_GondorForgedBlades +Upgrade_GondorHeavyArmor +Upgrade_ElvenForgedBlades +Upgrade_ElvenHeavyArmor +Upgrade_DwarvenForgedBlades +Upgrade_DwarvenMithrilMail +Upgrade_MordorForgedBlades +Upgrade_MordorHeavyArmor +Upgrade_IsengardForgedBlades +Upgrade_IsengardHeavyArmor +Upgrade_WildForgedBlades +Upgrade_WildHeavyArmor +Upgrade_AngmarDarkIronBlades +Upgrade_AngmarDarkIronArmor
		End
		ProductionModifier
			CostMultiplier	= 0.667
			ModifierFilter = ANY +Upgrade_GondorFireArrows +Upgrade_ElvenSilverthornArrows +Upgrade_DwarvenFireArrows +Upgrade_MordorFireArrows +Upgrade_IsengardFireArrows +Upgrade_WildFireArrows +Upgrade_AngmarIceArrows
		End
	End