; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

ModifierList Modifier_ElvenForgedBlades
	Category = WEAPON
	Duration = 0
	Upgrade = Upgrade_ElvenForgedBlades Delay:100
End

ModifierList Modifier_ElvenHeavyArmor
	Category = WEAPON
	Duration = 0
	Upgrade = Upgrade_ElvenHeavyArmor Delay:100
End

ModifierList Modifier_TieredBlades
	Category = WEAPON
	Duration = 0
	Upgrade =  Upgrade_ForgedBladesTier1 Delay:100
	Upgrade =  Upgrade_ForgedBladesTier2 Delay:100
	Upgrade =  Upgrade_ForgedBladesTier3 Delay:100
	Upgrade =  Upgrade_ForgedBladesTier4 Delay:100
End

ModifierList Modifier_TieredArmor
	Category = WEAPON
	Duration = 0
	Upgrade = Upgrade_HeavyArmorTier1 Delay:100
	Upgrade = Upgrade_HeavyArmorTier2 Delay:100
	Upgrade = Upgrade_HeavyArmorTier3 Delay:100
	Upgrade = Upgrade_HeavyArmorTier4 Delay:100
End

ModifierList Modifier_ElvenBannerCarriers
	Category = WEAPON
	Duration = 0
	Upgrade = Upgrade_ElvenBasicTraining Delay:100
End

ModifierList Modifier_TieredBannerCarriers
	Category = WEAPON
	Duration = 0
	Upgrade =  Upgrade_BasicTrainingTier1 Delay:100
	Upgrade =  Upgrade_BasicTrainingTier2 Delay:100
	Upgrade =  Upgrade_BasicTrainingTier3 Delay:100
	Upgrade =  Upgrade_BasicTrainingTier4 Delay:100
End

ModifierList TestingFastGamePlay
;	Modifier = SPEED 200%
;	Category = STRUCTURE
	Modifier = EXPERIENCE H_EXP_GAIN
	Modifier = PRODUCTION H_PRODUCTION_SPEED //Handled by hard coded value now (so building construction will work).
	Modifier = RECHARGE_TIME H_RECHARGE_TIME
	Duration = 0
End

ModifierList HEElvenStatueLeadership
	Category					= LEADERSHIP
;;,;;	Modifier					= RESIST_FEAR 100%	// Additive.  Sum of these is a saving throw against fear

	Modifier					= EXPERIENCE 150% ;;,;; 200%
	Modifier					= ARMOR 20% ;,; 25% ;;,;; 50%
	Modifier					= DAMAGE_MULT 125% ;,; 133% ;;,;; 150%		// Multiplicitive.  Damage multiplied by this, will compound in multiple bonuses
	Duration					= 2200 ;;,;; 2000			// Matches RefreshRate of giving module
	ReplaceInCategoryIfLongest	= Yes
	IgnoreIfAnticategoryActive	= Yes
	FX							= FX_GenericLeadership
End

ModifierList HEElvenStatuePassiveLeadershipResistFear
	Category					= SPELL ;;,;; LEADERSHIP
	Modifier					= RESIST_FEAR 100%	// Additive.  Sum of these is a saving throw against fear
	Modifier					= RESIST_TERROR 100% ;;,;;
	Duration					= 2200 ;;,;; 2000			// Matches RefreshRate of giving module
	FX	                        = FX_Fearless ;,;
;;,;;	ReplaceInCategoryIfLongest	= Yes
;;,;;	IgnoreIfAnticategoryActive	= Yes
End
