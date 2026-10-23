; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

ModifierList HighElvesHeroBonusLevel11
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel12
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel13
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel14
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel15
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_HIGH_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesRangeHeroBonusLevel15
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Modifier = RANGE H_HERO_HIGH_LVL_RANGE_BONUS
	Modifier = VISION H_HERO_HIGH_LVL_RANGE_BONUS
	Modifier = SHROUD_CLEARING H_HERO_HIGH_LVL_RANGE_BONUS
	ModelCondition = WEAPONSET_HERO_MODE
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel16
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel17
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel18
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel19
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel20
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_HIGH_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesRangeHeroBonusLevel20
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Modifier = RANGE H_HERO_HIGH_LVL_RANGE_BONUS
	Modifier = VISION H_HERO_HIGH_LVL_RANGE_BONUS
	Modifier = SHROUD_CLEARING H_HERO_HIGH_LVL_RANGE_BONUS
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel21
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Modifier = RECHARGE_TIME H_HERO_HIGH_LVL_RECHARGE_TIME
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel22
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel23
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel24
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_DAMAGE_MULT
	Duration = 0
End

ModifierList HighElvesHeroBonusLevel25
	Category = LEVEL
	Modifier = HEALTH H_HERO_HIGH_LVL_HP_ADD
	Modifier = DAMAGE_MULT H_HERO_HIGH_LVL_HIGH_DAMAGE_MULT
	Modifier = RANGE H_HERO_HIGH_LVL_RANGE_BONUS
	Modifier = VISION H_HERO_HIGH_LVL_RANGE_BONUS
	Duration = 0
End

ModifierList RivendellKnightsSpeed
	Category = LEVEL
	Modifier = SPEED 110% ;;,;; 
	Modifier = RESIST_KNOCKBACK 60%
	Modifier = MINIMUM_CRUSH_VELOCITY 70%
	Modifier = CRUSH_DECELERATE 20%
	Duration = 0 // FOrever
End

ModifierList FearlessLevel
	Category = Level
	Modifier = RESIST_FEAR 100%	// Additive.  Sum of these is a saving throw against fear
	Modifier = RESIST_TERROR 100% // Additive.  Sum of these is a saving throw against terror (TERROR) ;,; Added in v5.1
	Duration = 0				// Duration is forever when zero
End

ModifierList ElvenFortressIvoryTowerBonus
	Category = STRUCTURE
	Modifier = SHROUD_CLEARING 240% ;;,;; 200% // Additive.  Sum of these is the % bonus to the range at which you clear fog and shroud
	Duration = 0 // FOrever
End

ModifierList DwarvenCitadelIvoryTowerBonus
	Category = STRUCTURE
	Modifier = SHROUD_CLEARING 180% ;;,;; 200% // Additive.  Sum of these is the % bonus to the range at which you clear fog and shroud
	Duration = 0 // FOrever
End

ModifierList ElvenFortressVinesLeadership
	Category					= STRUCTURE
	Modifier					= ARMOR 50%			// Additive.  Sum of these are subtracted from all entries in Armor.ini
	Modifier					= DAMAGE_MULT 100%		// Multiplicitive.  Damage multiplied by this, will compound in multiple bonuses
	Modifier					= EXPERIENCE 150%	// Multiplicitive.  All exp gained mult by this
	Modifier 					= RANGE 20% 		// Additive.
  Modifier 					= VISION 20%		// Additive. 
	Duration					= 2100				// Matches RefreshRate of giving module
	FX							  = FX_VineslightBonus
End

ModifierList ElvenEnvilLeadership
	Category = WEAPON
	Modifier = BOUNTY_PERCENTAGE 25.0%	;// Percentage of victim bounty value to build granted to slaying member's player.
	Duration = 3000						// lasts for 2.5 seconds
	FX							= FX_EnvillightBonus
End

ModifierList SuperTowerBonus
	Category = STRUCTURE
	Modifier = VISION 30%
	Modifier = RANGE 25%
	Duration = 3000						// 2 secs
End

ModifierList SpellBookHighElvenGifts // Please update cah modifier also
	Category = SPELL
	Modifier = DAMAGE_MULT 150%		// damage increased 50%
	Modifier = ARMOR 33%
	Duration = 0					// Duration is forever when set to 0
End

ModifierList SpellBookHighElvenCAHGifts
	Category = SPELL
	Modifier = SPEED 130%
	Duration = 0					// Duration is forever when set to 0
End

ModifierList TaurielBonusRank7
	Category = LEVEL
	Modifier = HEALTH ELVEN_LEGOLAS_LEVEL_HEALTH_BONUS
	Modifier = VISION 20%
	Modifier = RANGE 20%
	Modifier = SHROUD_CLEARING 40%
	Duration = 0
End

ModifierList TaurielLeadership
	Category					= WEAPON
	Modifier 					= VISION 20%
	Modifier 					= RANGE 20%
	Duration					= 3000
	FX							= FX_TaurielBonus
End

ModifierList TaurielLeadershipLvl3
	Category					= WEAPON
	Modifier 					= VISION 50%
	Modifier 					= RANGE 50%
	Modifier					= RECHARGE_TIME 50%
	Duration					= 3000
	FX							  = FX_TaurielBonus
End

ModifierList MallornTreeBloomBonus
	Category = STRUCTURE
	Modifier = PRODUCTION 2	
	Modifier = HEALTH 1000
	Modifier = COMMAND_POINT_BONUS 50							// Additive.
	ModelCondition 	 = USER_3
	Duration = 0
End

ModifierList RingOfAdamantBonus
	Category = STUN
	Modifier = PRODUCTION 1.25	
	Modifier = ARMOR 20%
	Modifier = COMMAND_POINT_BONUS 25							// Additive.
	ModelCondition 	 = USER_3
	Duration = 0
End

ModifierList SpellLightOfTreesBonus
	Category = SPELL
	Modifier = DAMAGE_MULT 133% ;;,;; 150%	
	Modifier = ARMOR 25% ;33% ;;,;; 50%
	Duration = 2100 ;;,;; 0 ; changed for 2.02e because this is no longer applied by the weather - see note in system.ini
	FX		 = FX_SpellLightOfTrees  ;;,;; FX_InfiniteGenericLeadershipLvl1
End

ModifierList SpellLightOfTreesSpeedBonus
	Category = SPELL
	Modifier = SPEED 120%
	Duration = 2100 ;;,;; 0 ; changed for 2.02e because this is no longer applied by the weather - see note in system.ini
End

ModifierList KnightsWeaponSong
	Category = WEAPON
	Modifier = ARMOR 90%			;// Additive.  Sum of these are subtracted from all entries in Armor.ini
	Modifier = CRUSH_DECELERATE 0%		;// Multiplicitive.  Zero would be no deceleration.
	Duration = 20000			;// lasts for 30 seconds
	ModelCondition = USER_4
End
