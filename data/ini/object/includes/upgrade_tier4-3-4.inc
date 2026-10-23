;,;Thanks for BfMe2 1.09 team

;,; TIER 3 DISCOUNT FOR ARMOR UPGRADES (NO DISCOUNT ON OTHER UPGRADES)
	Behavior = ProductionUpdate ProductionUpdateModuleTag
		GiveNoXP = Yes
		ProductionModifier
			CostMultiplier	= 0.834
			ModifierFilter = ANY +Upgrade_GondorHeavyArmor +Upgrade_ElvenHeavyArmor +Upgrade_DwarvenMithrilMail +Upgrade_MordorHeavyArmor +Upgrade_IsengardHeavyArmor +Upgrade_WildHeavyArmor +Upgrade_AngmarDarkIronArmor 
		End
	End