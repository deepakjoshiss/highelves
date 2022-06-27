// mod/attributemodifier.inc
//
// A ModifierList is a set of bonuses that can be given as a package.  You can't ever be given the same list
// twice at the same time, but you can have two different lists that have the same effect.
//
// Category = 
//	LEADERSHIP, 
//	FORMATION, 
//	SPELL, 
//	WEAPON, 
//	STRUCTURE, 
//	LEVEL, 
//	BUFF, 
//	DEBUFF, 
//	STUN, 
//	INNATE_ARMOR,			// Used for the Create-a-Hero's permanent armor attribute.
//	INNATE_DAMAGEMULT		// Used for the Create-a-Hero's permanent damage multiplier attribute.
//  INNATE_VISION			// Used for the Create-a-Hero's permanent vision range attribute.
//  INNATE_AUTOHEAL			// Used for the Create-a-Hero's permanent auto-heal attribute.
//  INNATE_HEALTH			// Used for the Create-a-Hero's permanent health attribute.
//	The reason you have this bonus.  So things can affect all Leadership bonuses or dispel all spell effects
//
// In general, Additive bonuses should be things like 20% to give a bonus, and Multiplicitive bonuses should be things like 120%.
// Modifier = 
//	ARMOR,				// Additive.  The armor coefficients in Armor.ini go first to multiply the damage.  Then all of these are added together, capped at GameData's AttributeModifierArmorMaxBonus protection', and then the damage is multiplied by it again.
//	DAMAGE_ADD,			// Additive.  'Base' damage gets increased by this before hitting the DamageMult.
//	DAMAGE_MULT,			// Multiplicitive.  Then after DamageAdd, the damage is multiplied by all of these.
//	RESIST_FEAR,			// Additive.  Sum of these is a saving throw against fear (FEAR, DOOM, UNCONTROLLABLE_FEAR)
//	RESIST_TERROR,			// Additive.  Sum of these is a saving throw against terror (TERROR)
//	EXPERIENCE,			// Multiplicitive.  Experience gained multiplied by this, will compound in multiple bonuses
//	RANGE,				// Additive.  Sum of these added to max range.  20% and 10% makes range 130% normal.  (You probably want a vision range boost for targeting too.)
//	SPEED,				// Multiplicitive.  Multiply your speed by each of these numbers in turn.
//	CRUSH_DECELERATE,		// Multiplicitive.  The percentage you slow down when crushing gets multiplied by each of these.
//	RESIST_KNOCKBACK,		// Additive.  Sum of these is saving through against knockback.
//	SPELL_DAMAGE,			// Multiplicitive.  Just like DamageMult bonus, but only applies if damage type is Magic.  REPLACES DamageMult bonus.
//	RECHARGE_TIME,			// Multiplicitive.  Recharge time for all special powers multiplied by these.  Time is figured at the moment power is used, so this has no effect if gained or lost while power is recharging.
//	PRODUCTION,			// Multiplicitive.  Production speed for units and money amount produced by supply centers or money generators multiplied by these.  Again, time is computed at moment production starts.
//	HEALTH,				// Additive.  The moment you get this upgrade, this many hitpoints are added to both your max and current hitpoint scores.
//	HEALTH_MULT,			// Multiplicitive.  Multiply your hitpoints by this value. 
//	VISION,				// Additive.  Sum of these is added to vision range, which is used for targeting.
//	BOUNTY_PERCENTAGE		// Multiplicitive.  Multiply your (kill) bounty by this value.
//	MIN_CRUSH_VELOCITY_PERCENTAGE	//
//	AUTO_HEAL,			// Additive. Sum of these is added to the AutoHeal value.
//	SHROUD_CLEARING,		// Additive.  Sum of these is the % bonus to the range at which you clear fog and shroud
//	RATE_OF_FIRE,			// Multiplicitive.
//	DAMAGE_STRUCTURE_BOUNTY_ADD	// Additive.  Sum of these is added to your treasury per damage event done to a structure
//	COMMAND_POINT_BONUS		// Additive. Operates on the command point bonus.
//	CRUSHABLE_LEVEL			// Additive.  Adds the specified crushable level
//	CRUSHED_DECELERATE		// Multiplicitive.  The percentage that things crushing you slow
//	INVULNERABLE			// Currently, value does nothing (but one is required), the list of damage types after the value indicates what unit is invulnerable to
//
//	What is actually affected
//
// Duration = 1000
//	If self expiring effect, msec it lasts for

//	FX = FX_Name
//	use this to make a particle FX or tint for the attribute modifier

;//---Created by <D.J.>

;//============Hero Levels============

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

;==================levels end=================

;==================Unit Levels================
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
;------------------------------------------------

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
