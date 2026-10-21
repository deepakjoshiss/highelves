;,;Thanks for BfMe2 1.09 team

;,; DISCOUNT ON ALL UPGRADES
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		GiveNoXP = Yes
		ProductionModifier
			CostMultiplier	= 0.60
			ModifierFilter = ANY +Upgrade_GondorBasicTraining +Upgrade_ElvenBasicTraining +Upgrade_DwarvenBasicTraining +Upgrade_MordorBasicTraining +Upgrade_IsengardBasicTraining +Upgrade_WildBasicTraining +Upgrade_AngmarBasicTraining
		End
		ProductionModifier
			CostMultiplier	= 0.667
			ModifierFilter = ANY +Upgrade_GondorForgedBlades +Upgrade_GondorHeavyArmor +Upgrade_GondorFireArrows +Upgrade_ElvenForgedBlades +Upgrade_ElvenHeavyArmor +Upgrade_ElvenSilverthornArrows +Upgrade_DwarvenForgedBlades +Upgrade_DwarvenMithrilMail +Upgrade_DwarvenFireArrows +Upgrade_MordorForgedBlades +Upgrade_MordorHeavyArmor +Upgrade_MordorFireArrows +Upgrade_IsengardForgedBlades +Upgrade_IsengardHeavyArmor +Upgrade_IsengardFireArrows +Upgrade_WildForgedBlades +Upgrade_WildHeavyArmor +Upgrade_WildFireArrows +Upgrade_AngmarDarkIronBlades +Upgrade_AngmarDarkIronArmor +Upgrade_AngmarIceArrows
		End
	End