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

; ---- Hero rework (openbfme/HERO-REWORK-PLAN.md): one list per level, the same values in each (level lists stack: a list's name is applied once)
ModifierList HEReworkHeroLevel2
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel3
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel4
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel5
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel6
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel7
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel8
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel9
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel10
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel11
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel12
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel13
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel14
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel15
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel16
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel17
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel18
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel19
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel20
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel21
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel22
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel23
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel24
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

ModifierList HEReworkHeroLevel25
	Category = LEVEL
	Modifier = HEALTH H_RW_LEVEL_HP
	Modifier = DAMAGE_MULT H_RW_LEVEL_DAMAGE_MULT
	Modifier = SPELL_DAMAGE H_RW_LEVEL_DAMAGE_MULT
	Modifier = DAMAGE_ADD H_RW_LEVEL_DAMAGE_ADD
	Duration = 0
End

; Thranduil's Elvenking's Command (passive, the whole map): Mirkwood archers +10% damage and +10% range from level 8; level 18 adds the second list
; for +15% / +15% in all (damage multiplies: 1.10 x 1.04545 = 1.15; range adds: 10% + 5%)
ModifierList HEThranduilElvenkingsCommand1
	Category = LEADERSHIP
	Modifier = DAMAGE_MULT 110%
	Modifier = RANGE 10%
	Duration = 2200	; the aura refreshes every 2000
End

ModifierList HEThranduilElvenkingsCommand2
	Category = LEADERSHIP
	Modifier = DAMAGE_MULT 104.545%
	Modifier = RANGE 5%
	Duration = 2200
End

; ---- Thranduil's Armory items (hero rework, pass 2); each tier adds to the one before
ModifierList HEThranduilArmor1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = ARMOR 15%
	Duration = 0
End

ModifierList HEThranduilArmor2
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = ARMOR 10%
	Modifier = RESIST_KNOCKBACK 100%
	Modifier = CRUSHABLE_LEVEL 2
	Duration = 0
End

ModifierList HEThranduilArmor3
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = ARMOR 10%
	Duration = 0
End

ModifierList HEThranduilArmor3Aura
	Category = LEADERSHIP
	Modifier = ARMOR 20%
	Duration = 2200
End

ModifierList HEThranduilLife1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 400
	Duration = 0
End

ModifierList HEThranduilLife2
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 600
	Duration = 0
End

ModifierList HEThranduilLife3
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 1000
	Duration = 0
End

ModifierList HEThranduilMobility1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = SPEED 115%
	Duration = 0
End

ModifierList HEThranduilMobility2
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = SPEED 108.7% ; 1.15 x 1.087 = +25% in all
	Modifier = RANGE 10%
	Duration = 0
End

ModifierList HEThranduilBow1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = RANGE 10%
	Duration = 0
End

ModifierList HEThranduilBow2
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = RANGE 5%
	Duration = 0
End

ModifierList HEThranduilBow3
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = RANGE 10%
	Duration = 0
End

ModifierList HEThranduilHunter1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = SHROUD_CLEARING 50%
	Modifier = VISION 25%
	Duration = 0
End

; ---- Legolas's Armory items (hero rework, pass 2): Mail, Swift Feet I / II and Bow use Thranduil's lists (the same values); these differ
ModifierList HELegolasLife1
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 300
	Duration = 0
End

ModifierList HELegolasLife2
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 500
	Duration = 0
End

ModifierList HELegolasLife3
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = HEALTH 800
	Duration = 0
End

ModifierList HELegolasMobility3
	Category = LEVEL ; permanent, like the level bonuses
	Modifier = SPEED 108% ; 1.25 x 1.08 = +35% in all
	Modifier = RANGE 5%
	Duration = 0
End

; Heartseeker I / III: Piercing Arrow's slow (III's replaces I's)
ModifierList HELegolasHeartseekerSlow1
	Category = WEAPON
	Modifier = SPEED 70%
	Duration = 10000
End

ModifierList HELegolasHeartseekerSlow3
	Category = WEAPON
	Modifier = SPEED 50%
	Duration = 10000
End
