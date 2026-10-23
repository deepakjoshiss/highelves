	Behavior = WeaponFireSpecialAbilityUpdate ModuleTag_ZephyrStrikeWeaponFireUpdate   
		SpecialPowerTemplate		= SpecialAbilityZephyrStrike
		WhichSpecialWeapon			= 1
		SkipContinue				= Yes
;,;	Behavior = WeaponFireSpecialAbilityUpdate ModuleTag_ZephyrStrikeWeaponFireUpdate ;,; Commented to make room for line limit in weapon.ini
		UnpackTime					= 1700 
		PackTime					= 1		
		FreezeAfterTriggerDuration	= 2500 ; Hold AI for this long after we fire.
;,;		SpecialPowerTemplate		= SpecialAbilityZephyrStrike
		AwardXPForTriggering		= 0		
		StartAbilityRange			= 80.0
;,;		WhichSpecialWeapon			= 1
		MustFinishAbility		= Yes
		SpecialWeapon				= ZephyrStrikeWeapon
	End