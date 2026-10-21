;==================================================
	Behavior = AutoHealBehavior ModuleTag_CustomHeroBonus1
		TriggeredBy = Upgrade_CustomGenericUpgrade1
		ConflictsWith = Upgrade_CustomGenericUpgrade2 Upgrade_CustomGenericUpgrade3 Upgrade_CustomGenericUpgrade4 Upgrade_CustomGenericUpgrade5
		HealingAmount			= 75
		Radius					= 300
		HealingDelay			= 2000
		NonStackable			= No
		RespawnNearbyHordeMembers = No
		KindOf				= HERO
		UnitHealPulseFX = FX_CustomHealAura2
	End
;-------------------------------------------------------------------------------
	Behavior = AttributeModifierAuraUpdate ModuleTag_CustomHeroBonus2
		TriggeredBy = Upgrade_CustomGenericUpgrade2
		ConflictsWith = Upgrade_CustomGenericUpgrade1 Upgrade_CustomGenericUpgrade3 Upgrade_CustomGenericUpgrade4 Upgrade_CustomGenericUpgrade5
		BonusName		= CustomHeroModifier_38_Debuff
		RefreshDelay	= 2000
		Range			= 300
		TargetEnemy = Yes
		ObjectFilter	= ANY +HERO
	End
;-------------------------------------------------------------------------------
	Behavior = AttributeModifierAuraUpdate ModuleTag_CustomHeroBonus3
		TriggeredBy = Upgrade_CustomGenericUpgrade3
		ConflictsWith = Upgrade_CustomGenericUpgrade1 Upgrade_CustomGenericUpgrade2 Upgrade_CustomGenericUpgrade4 Upgrade_CustomGenericUpgrade5
		BonusName		= CustomHeroModifier_39_Silence
		RefreshDelay	= 2000
		Range			= 150
		TargetEnemy = Yes
		ObjectFilter	= ANY +HERO
	End
;-------------------------------------------------------------------------------
	Behavior = AttributeModifierAuraUpdate ModuleTag_CustomHeroBonus4
		TriggeredBy = Upgrade_CustomGenericUpgrade4
		ConflictsWith = Upgrade_CustomGenericUpgrade1 Upgrade_CustomGenericUpgrade2 Upgrade_CustomGenericUpgrade3 Upgrade_CustomGenericUpgrade5
		BonusName		= CustomHeroModifier_40_Buff
		RefreshDelay	= 2000
		Range			= 300
		AllowSelf = Yes
		ObjectFilter	= ANY +HERO
	End
;-------------------------------------------------------------------------------
	Behavior = AttributeModifierAuraUpdate ModuleTag_CustomHeroBonus5
		TriggeredBy = Upgrade_CustomGenericUpgrade5
		ConflictsWith = Upgrade_CustomGenericUpgrade1 Upgrade_CustomGenericUpgrade2 Upgrade_CustomGenericUpgrade3 Upgrade_CustomGenericUpgrade4
		BonusName		= CustomHeroModifier_41_HitPoints
		RefreshDelay	= 3000
		Range			= 300
		AllowSelf = Yes
		ObjectFilter	= ANY +HERO
	End
;==================================================