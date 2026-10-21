;,;Thanks for BfMe2 1.09 team

;,; DISCOUNT ON ALL UPGRADES
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		GiveNoXP = Yes
		ProductionModifier ;,; banner upgrades
			CostMultiplier	= 0.25
			ModifierFilter = ANY +Upgrade_GondorBasicTraining +Upgrade_ElvenBasicTraining +Upgrade_DwarvenBasicTraining +Upgrade_MordorBasicTraining +Upgrade_IsengardBasicTraining +Upgrade_WildBasicTraining +Upgrade_AngmarBasicTraining
		End
		ProductionModifier ;,; blades and arrow upgrades
			CostMultiplier	= 0.334 ;,;0.5
			ModifierFilter = ANY +Upgrade_GondorForgedBlades +Upgrade_GondorFireArrows +Upgrade_ElvenForgedBlades +Upgrade_ElvenSilverthornArrows +Upgrade_DwarvenForgedBlades +Upgrade_DwarvenFireArrows +Upgrade_MordorForgedBlades +Upgrade_MordorFireArrows +Upgrade_IsengardForgedBlades +Upgrade_IsengardFireArrows +Upgrade_WildForgedBlades +Upgrade_WildFireArrows +Upgrade_AngmarDarkIronBlades +Upgrade_AngmarIceArrows
		End
		ProductionModifier ;,; armor upgrades
			CostMultiplier	= 0.167  ;,;0.5
			ModifierFilter = ANY +Upgrade_GondorHeavyArmor +Upgrade_ElvenHeavyArmor +Upgrade_DwarvenMithrilMail +Upgrade_MordorHeavyArmor +Upgrade_IsengardHeavyArmor +Upgrade_WildHeavyArmor +Upgrade_AngmarDarkIronArmor
		End
	End