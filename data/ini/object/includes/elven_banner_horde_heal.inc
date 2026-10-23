; Elven banner-carrier healing, owned by the horde so Blight can disable it.
Behavior = AutoHealBehavior ModuleTag_HealHordeMembers
	HealOnlyIfNotInCombat	= Yes
	StartsActive			= No
	TriggeredBy			= Upgrade_ObjectLevel2
	ConflictsWith			= Upgrade_BlightAntiBWBuff
	HealingAmount			= 6 ;8 ;;,;; 10
	HealingDelay			= 2000
	KindOf					= INFANTRY CAVALRY
	UnitHealPulseFX			= FX_SpellHealUnitHealBuff
	AffectsContained			= Yes
	NonStackable			= Yes
End
