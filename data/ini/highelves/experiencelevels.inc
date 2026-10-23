; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

; the macros of this file's own blocks (an audio file loads without the main load's macros)
#define SAURON MordorSauron MordorSauron_RingHero

ExperienceLevel	HELegolasLevel7
	TargetNames = HERohanLegolas
	RequiredExperience				=	LEGOLAS_LVL7_EXP_NEEDED 
	ExperienceAward					=	LEGOLAS_LVL7_EXP_AWARD	
	AttributeModifiers				=	HeroLevelUpDamage6
	Rank							=	7
	LevelUpFx						=	FX:GoodLevelUpFX ;,; FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades				= Upgrade_ObjectLevel7 Upgrade_New1 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40 ;16
		MaxRadius					=	200 ;16
		MaxSelectedUnits			=	40 ;1
	End	
END	

ExperienceLevel	HELegolasLevel10
	TargetNames = HERohanLegolas
	RequiredExperience				=	LEGOLAS_LVL10_EXP_NEEDED 
	ExperienceAward					=	LEGOLAS_LVL10_EXP_AWARD	
  	AttributeModifiers				=	HeroLevelUpDamage9
	Rank							=	10
	LevelUpFx						=	FX:GoodLevelUpFX ;,; FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_New2
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40 ;16
		MaxRadius					=	200 ;16
		MaxSelectedUnits			=	40 ;1
	End	
END	

ExperienceLevel	LegolasLevel11
	TargetNames						=	HERohanLegolas ;,;  HEElvenLegolas            (removed for new 2.02 exp system, 13 july 2016)
	RequiredExperience				=	LEGOLAS_LVL10_EXP_NEEDED 
	ExperienceAward					=	LEGOLAS_LVL10_EXP_AWARD	
  	AttributeModifiers				=	HeroLevelUpDamage9
	Rank							=	11
	LevelUpFx						=	FX:GoodLevelUpFX ;,; FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40 ;16
		MaxRadius					=	200 ;16
		MaxSelectedUnits			=	40 ;1
	End	
END	

ExperienceLevel	HEElvenMallornTreeLevel2
	TargetNames = HEElvenMallornTree
	RequiredExperience		= H_ELVEN_MALLORN_TREE_LVL2_EXP_NEEDED
	ExperienceAward			= ELVEN_MALLORN_TREE_LVL2_EXP_AWARD
	Rank					= 2
	AttributeModifiers		= ElvenMallornTreeBuildSpeedModLvl2
	Upgrades				= Upgrade_StructureLevel2
	LevelUpFx				= FX:ElfMallornTreeUpgrade
End

ExperienceLevel	HEElvenMallornTreeLevel3
	TargetNames = HEElvenMallornTree
	RequiredExperience		= H_ELVEN_MALLORN_TREE_LVL3_EXP_NEEDED
	ExperienceAward			= ELVEN_MALLORN_TREE_LVL3_EXP_AWARD
	Rank					= 3
	AttributeModifiers		= ElvenMallornTreeBuildSpeedModLvl3 
	Upgrades				= Upgrade_StructureLevel3
	LevelUpFx				= FX:ElfMallornTreeUpgrade
End	

ExperienceLevel	HENoldorWarriorLevel1
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	1
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_1
	InformUpdateModule			=	Yes
	Rank						=	1
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	Upgrades					=	Upgrade_MiniHordeLvl1
	SelectionDecal
		Texture					=	decal_G_level1
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel2
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_2
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_2
	AttributeModifiers			=	NoldorWarriorBonusRank2 GenericHeroDamageBonusRank2
	InformUpdateModule			=	Yes
	Rank						=	2
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl2
	SelectionDecal
		Texture					=	decal_G_level2
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel3
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_3
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_3
	AttributeModifiers			=	NoldorWarriorBonusRank3 GenericHeroDamageBonusRank3
	InformUpdateModule			=	Yes
	Rank						=	3
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl3
	SelectionDecal
		Texture					=	decal_G_level3
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel4
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_4
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_4
	AttributeModifiers			=	NoldorWarriorBonusRank4 GenericHeroDamageBonusRank4
	InformUpdateModule			=	Yes
	Rank						=	4
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl4
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel5
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_5
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_5
	AttributeModifiers			=	NoldorWarriorBonusRank5 GenericHeroDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	5
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl5
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel6
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_6
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_6
	AttributeModifiers			=	NoldorWarriorBonusRank6 GenericHeroDamageBonusRank6
	InformUpdateModule			=	Yes
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl6
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel7
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_7
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_7
	AttributeModifiers			=	NoldorWarriorBonusRank7 GenericHeroDamageBonusRank7
	InformUpdateModule			=	Yes
	Rank						=	7
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl7
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel8
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_8
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_8
	AttributeModifiers			=	NoldorWarriorBonusRank8 GenericHeroDamageBonusRank8
	InformUpdateModule			=	Yes
	Rank						=	8
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl8
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel9
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_9
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_9
	AttributeModifiers			=	NoldorWarriorBonusRank9 GenericHeroDamageBonusRank9
	InformUpdateModule			=	Yes
	Rank						=	9
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl9
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	HENoldorWarriorLevel10
	TargetNames = HENoldorWarrior HENoldorWarriorHorde
	RequiredExperience			=	NOLDOR_WARRIOR_REQUIRED_EXP_LEVEL_10
	ExperienceAward				=	NOLDOR_WARRIOR_AWARD_LEVEL_10
	AttributeModifiers			=	NoldorWarriorBonusRank10 GenericHeroDamageBonusRank10
	InformUpdateModule			=	Yes
	Rank						=	10
	LevelUpFx					=	FX:GoodLevelUpFX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_MiniHordeLvl10
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	NOLDOR_WARRIOR_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	NOLDOR_WARRIOR_DECAL_MIN_RADIUS
		MaxRadius				=	NOLDOR_WARRIOR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	NOLDOR_WARRIOR_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel HEElvenHaldirLevel1
	TargetNames = HEElvenHaldir
	RequiredExperience			=	1
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_1
	Rank						=	1
	Upgrades					=	Upgrade_ObjectLevel1
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel2
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL2_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_2
	AttributeModifiers			=	ElvenHaldirBonusRank2 GenericHeroDamageBonusRank2
	Rank						=	2
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel3
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL3_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_3
	AttributeModifiers			=	ElvenHaldirBonusRank3 GenericHeroDamageBonusRank3
	Rank						=	3
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel4
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL4_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_4
	AttributeModifiers			=	ElvenHaldirBonusRank4 GenericHeroDamageBonusRank4
	Rank						=	4
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel4
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel5
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL5_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenHaldirBonusRank5 GenericHeroDamageBonusRank5
	Rank						=	5
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel5 ;,;
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel6
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL6_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_6
	AttributeModifiers			=	ElvenHaldirBonusRank6 GenericHeroDamageBonusRank6
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	;,; Upgrades					=	Upgrade_HaldirLeadership
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel7
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL7_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_7
	AttributeModifiers			=	ElvenHaldirBonusRank7 GenericHeroDamageBonusRank7
	Rank						=	7
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel7
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel8
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL8_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_8
	AttributeModifiers			=	ElvenHaldirBonusRank8 GenericHeroDamageBonusRank8
	Rank						=	8
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel8 ;,;
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel9
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL9_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_9
	AttributeModifiers			=	ElvenHaldirBonusRank9 GenericHeroDamageBonusRank9
	Rank						=	9
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenHaldirLevel10
	TargetNames = HEElvenHaldir
	RequiredExperience			=	H_HERO_LVL10_EXP_NEEDED
	ExperienceAward				=	ELVEN_HALDIR_AWARD_LEVEL_10
	AttributeModifiers			=	ElvenHaldirBonusRank10 GenericHeroDamageBonusRank10
	Rank						=	10
	LevelUpFx					=	FX:GoodLevelUpFX
	;,; Upgrades					=	Upgrade_HaldirGoldenArrow
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_HALDIR_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_HALDIR_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenGlorfindelLevel5
	TargetNames = HEElvenGlorfindel
	RequiredExperience			=	ELVEN_GLORFINDEL_REQUIRED_EXP_LEVEL_5
	ExperienceAward				=	ELVEN_GLORFINDEL_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenGlorfindelBonusRank5 GenericHeroDamageBonusRank5 RivendellKnightsSpeed
	Rank						=	5
	InformUpdateModule			=	Yes
	Upgrades							= Upgrade_ObjectLevel5
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_GLORFINDEL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_GLORFINDEL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenGlorfindelLevel6
	TargetNames = HEElvenGlorfindel
	RequiredExperience			=	ELVEN_GLORFINDEL_REQUIRED_EXP_LEVEL_6
	ExperienceAward				=	ELVEN_GLORFINDEL_AWARD_LEVEL_6
	AttributeModifiers			=	ElvenGlorfindelBonusRank6 GenericHeroDamageBonusRank6
	InformUpdateModule			=	Yes
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel6
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_GLORFINDEL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_GLORFINDEL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel2
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL2_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_2
	AttributeModifiers			=	ElvenElrondBonusRank2 GenericHeroDamageBonusRank2
	Rank						=	2
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel2
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel3
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL3_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_3
	AttributeModifiers			=	ElvenElrondBonusRank3 GenericHeroDamageBonusRank3
	Rank						=	3
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel3
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel4
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL4_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_4
	AttributeModifiers			=	ElvenElrondBonusRank4 GenericHeroDamageBonusRank4
	Rank						=	4
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel5
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL5_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenElrondBonusRank5 GenericHeroDamageBonusRank5
	Rank						=	5
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel5
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel6
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL6_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_6
	AttributeModifiers			=	ElvenElrondBonusRank6 GenericHeroDamageBonusRank6
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel7
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL7_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_7
	AttributeModifiers			=	ElvenElrondBonusRank7 GenericHeroDamageBonusRank7
	Rank						=	7
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades				= Upgrade_ObjectLevel7 Upgrade_New1 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel8
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL8_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_8
	AttributeModifiers			=	ElvenElrondBonusRank8 GenericHeroDamageBonusRank8
	Rank						=	8
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel9
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL9_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_9
	AttributeModifiers			=	ElvenElrondBonusRank9 GenericHeroDamageBonusRank9
	Rank						=	9
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenElrondLevel10
	TargetNames = HEElvenElrond
	RequiredExperience			=	H_HERO_LVL10_EXP_NEEDED
	ExperienceAward				=	ELVEN_ELROND_AWARD_LEVEL_10
	AttributeModifiers			=	ElvenElrondBonusRank10 GenericHeroDamageBonusRank10
	Rank						=	10
	Upgrades					=	Upgrade_New2
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_ELROND_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_ELROND_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel2
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL2_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_2
	AttributeModifiers			=	ElvenLegolasBonusRank2 GenericHeroDamageBonusRank2
	Rank						=	2
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel3
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL3_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_3
	AttributeModifiers			=	ElvenLegolasBonusRank3 GenericHeroDamageBonusRank3
	Rank						=	3
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel3
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel4
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL4_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_4
	AttributeModifiers			=	ElvenLegolasBonusRank4 GenericHeroDamageBonusRank4
	Rank						=	4
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel4
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel5
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL5_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenLegolasBonusRank5 GenericHeroDamageBonusRank5
	Rank						=	5
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel6
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL6_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_6
	AttributeModifiers			=	ElvenLegolasBonusRank6 GenericHeroDamageBonusRank6
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel7
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL7_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_7
	AttributeModifiers			=	ElvenLegolasBonusRank7 GenericHeroDamageBonusRank7
	Rank						=	7
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades				= Upgrade_ObjectLevel7 Upgrade_New1 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel8
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL8_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_8
	AttributeModifiers			=	ElvenLegolasBonusRank8 GenericHeroDamageBonusRank8
	Rank						=	8
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel9
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL9_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_9
	AttributeModifiers			=	ElvenLegolasBonusRank9 GenericHeroDamageBonusRank9
	Rank						=	9
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenLegolasLevel10
	TargetNames = HEElvenLegolas
	RequiredExperience			=	H_HERO_LVL10_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	ElvenLegolasBonusRank10 GenericHeroDamageBonusRank10
	Upgrades				= Upgrade_New2 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
	Rank						=	10
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel2
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL2_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_2
	AttributeModifiers			=	ElvenThranduilBonusRank2 GenericHeroDamageBonusRank2
	Rank						=	2
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel2
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel3
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL3_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_3
	AttributeModifiers			=	ElvenThranduilBonusRank3 GenericHeroDamageBonusRank3
	Rank						=	3
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel3 ;,;
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel4
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL4_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_4
	AttributeModifiers			=	ElvenThranduilBonusRank4 GenericHeroDamageBonusRank4
	Rank						=	4
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel4
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel5
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL5_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenThranduilBonusRank5 GenericHeroDamageBonusRank5
	Rank						=	5
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel6
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL6_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_6
	AttributeModifiers			=	ElvenThranduilBonusRank6 GenericHeroDamageBonusRank6
	Rank						=	6
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades					=	Upgrade_ObjectLevel6 ;,;
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel7
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL7_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_7
	AttributeModifiers			=	ElvenThranduilBonusRank7 GenericHeroDamageBonusRank7
	Rank						=	7
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades				= Upgrade_New1 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
;,; 	Upgrades					=	Upgrade_ThranduilMoveUnseen
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel8
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL8_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_8
	AttributeModifiers			=	ElvenThranduilBonusRank8 GenericHeroDamageBonusRank8
	Rank						=	8
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel9
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL9_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_9
	AttributeModifiers			=	ElvenThranduilBonusRank9 GenericHeroDamageBonusRank9
	Rank						=	9
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HEElvenThranduilLevel10
	TargetNames = HEElvenThranduil
	RequiredExperience			=	H_HERO_LVL10_EXP_NEEDED
	ExperienceAward				=	ELVEN_THRANDUIL_AWARD_LEVEL_10
	AttributeModifiers			=	ElvenThranduilBonusRank10 GenericHeroDamageBonusRank10
	Rank						=	10
	LevelUpFx					=	FX:GoodLevelUpFX
	Upgrades				= Upgrade_ObjectLevel10 Upgrade_New2 ; 2.02 v9.8.0 scheme (+ the mod's Upgrade_New*)
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_THRANDUIL_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_THRANDUIL_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel	ElvenMirkwoodArcherLevel6
	TargetNames					=	H_ELVEN_ARCHER_DAMAGE_FILTER ;HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner
	RequiredExperience			=	#ADD( REQUIRED_EXP_ADVANCED_LEVEL_5 REQUIRED_EXP_ADVANCED_LEVEL_2 )
	ExperienceAward				=	ELVEN_MIRKWOOD_ARCHER_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenMirkwoodArcherBonusRank5 GenericUnitDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	6
	LevelUpFx					=	FX:GenericLevelUp4FX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_ObjectLevel6
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	ELVEN_MIRKWOOD_ARCHER_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	ElvenMirkwoodArcherLevel7
	TargetNames					=	H_ELVEN_ARCHER_DAMAGE_FILTER ;HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner
	RequiredExperience			=	#ADD( REQUIRED_EXP_ADVANCED_LEVEL_5 REQUIRED_EXP_ADVANCED_LEVEL_3 )
	ExperienceAward				=	ELVEN_MIRKWOOD_ARCHER_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenMirkwoodArcherBonusRank5 GenericUnitDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	7
	LevelUpFx					=	FX:GenericLevelUp4FX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_ObjectLevel7
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	ELVEN_MIRKWOOD_ARCHER_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	ElvenMirkwoodArcherLevel8
	TargetNames					=	H_ELVEN_ARCHER_DAMAGE_FILTER ;HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner
	RequiredExperience			=	#ADD( REQUIRED_EXP_ADVANCED_LEVEL_5 REQUIRED_EXP_ADVANCED_LEVEL_3 )
	ExperienceAward				=	ELVEN_MIRKWOOD_ARCHER_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenMirkwoodArcherBonusRank5 GenericUnitDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	8
	LevelUpFx					=	FX:GenericLevelUp4FX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_ObjectLevel8
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	ELVEN_MIRKWOOD_ARCHER_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	ElvenMirkwoodArcherLevel9
	TargetNames					=	H_ELVEN_ARCHER_DAMAGE_FILTER ;HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner
	RequiredExperience			=	#ADD( REQUIRED_EXP_ADVANCED_LEVEL_5 REQUIRED_EXP_ADVANCED_LEVEL_4 )
	ExperienceAward				=	ELVEN_MIRKWOOD_ARCHER_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenMirkwoodArcherBonusRank5 GenericUnitDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	9
	LevelUpFx					=	FX:GenericLevelUp4FX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_ObjectLevel9
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	ELVEN_MIRKWOOD_ARCHER_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	ElvenMirkwoodArcherLevel10
	TargetNames					=	H_ELVEN_ARCHER_DAMAGE_FILTER ;HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner
	RequiredExperience			=	#ADD( REQUIRED_EXP_ADVANCED_LEVEL_5 REQUIRED_EXP_ADVANCED_LEVEL_5 )
	ExperienceAward				=	ELVEN_MIRKWOOD_ARCHER_AWARD_LEVEL_5
	AttributeModifiers			=	ElvenMirkwoodArcherBonusRank5 GenericUnitDamageBonusRank5
	InformUpdateModule			=	Yes
	Rank						=	10
	LevelUpFx					=	FX:GenericLevelUp4FX
	LevelUpTintColor			=	R:255 G:255	B:255
	LevelUpTintPreColorTime		=	500
	LevelUpTintPostColorTime	=	3000
	LevelUpTintSustainColorTime	=	500
	EmotionType					=	CHEER
	Upgrades					=	Upgrade_ObjectLevel10
	SelectionDecal
		Texture					=	decal_G_level4
		Texture2				=	decal_good_CO
		Style					=	SHADOW_MERGE_DECAL
		OpacityMin				=	ELVEN_MIRKWOOD_ARCHER_DECAL_OPACITY_MIN 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	ELVEN_MIRKWOOD_ARCHER_DECAL_MAX_SELECTED_UNITS
	End
END

ExperienceLevel	TaurielLevel1
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	1
	ExperienceAward			=	ARWEN_LVL1_EXP_AWARD
	Rank					=	1
	Upgrades				= Upgrade_ObjectLevel1
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel2
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL2_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL2_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	2
	Upgrades				= 	Upgrade_ObjectLevel2
	AttributeModifiers		=	ElvenLegolasBonusRank2 GenericHeroDamageBonusRank2
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel3
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL3_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL3_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	3
	AttributeModifiers		=	ElvenLegolasBonusRank3 GenericHeroDamageBonusRank3
	Upgrades				= 	Upgrade_ObjectLevel3 ;Upgrade_ArwenElvenGraceTrigger
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel4
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL4_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL4_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	4
	AttributeModifiers		=	ElvenLegolasBonusRank4 GenericHeroDamageBonusRank4
	Upgrades				=	Upgrade_ObjectLevel4
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel5
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL5_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL5_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	5
	Upgrades				=	Upgrade_ObjectLevel5
	AttributeModifiers		=	ElvenLegolasBonusRank5 GenericHeroDamageBonusRank5
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel6
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL6_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL6_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	6
	AttributeModifiers		=	ElvenLegolasBonusRank6 GenericHeroDamageBonusRank6
	Upgrades				=	Upgrade_ObjectLevel6 ;Upgrade_ArwenFloodTrigger Upgrade_ObjectLevel6
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel7
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL7_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL7_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	7
	Upgrades				=	Upgrade_ObjectLevel7 Upgrade_New1
	AttributeModifiers		=	TaurielBonusRank7 ElvenLegolasBonusRank7 GenericHeroDamageBonusRank7
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel8
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL8_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL8_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	8
	AttributeModifiers		=	ElvenLegolasBonusRank8 GenericHeroDamageBonusRank8
	Upgrades				= 	Upgrade_ObjectLevel8
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel9
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=   H_HERO_LVL9_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL9_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	9
	Upgrades				= 	Upgrade_ObjectLevel9
	AttributeModifiers		=	ElvenLegolasBonusRank9 GenericHeroDamageBonusRank9
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel	TaurielLevel10
	TargetNames				=	MirkwoodTauriel MirkwoodTauriel_WOTR
	RequiredExperience		=	H_HERO_LVL10_EXP_NEEDED
	ExperienceAward			=	ARWEN_LVL10_EXP_AWARD
	LevelUpFx				=	FX:GoodLevelUpFX
	Rank					=	10
	AttributeModifiers		=	ElvenLegolasBonusRank10 GenericHeroDamageBonusRank10
	Upgrades				=	Upgrade_ObjectLevel10 Upgrade_New2
	SelectionDecal
		Texture				=	decal_hero_good
		Style				=	SHADOW_ALPHA_DECAL
		OpacityMin			=	50%
		OpacityMax			=	100%
		MinRadius			=	40
		MaxRadius			=	200
		MaxSelectedUnits	=	40
	End
End

ExperienceLevel HighElvesHeroLevel11
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL11_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel11
	Rank						=	11
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel12
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL12_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel12
	Rank						=	12
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel13
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL13_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel13
	Rank						=	13
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel14
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL14_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel14
	Rank						=	14
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel15
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF
	RequiredExperience			=	H_HERO_LVL15_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel15
	Rank						=	15
	Upgrades					=	Upgrade_New3
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesRangeHeroLevel15
	TargetNames					=	H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL15_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesRangeHeroBonusLevel15
	Rank						=	15
	Upgrades					=	Upgrade_New3
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel16
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL16_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel16
	Rank						=	16
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel17
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL17_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel17
	Rank						=	17
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel18
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL18_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel18
	Rank						=	18
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel19
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL19_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel19
	Rank						=	19
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel20
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF
	RequiredExperience			=	H_HERO_LVL20_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel20
	Rank						=	20
	Upgrades					=	Upgrade_New4
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesRangedHeroLevel20
	TargetNames					=	H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL20_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesRangeHeroBonusLevel20
	Rank						=	20
	Upgrades					=	Upgrade_New4
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel21
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL21_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel21
	Rank						=	21
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel22
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL22_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel22
	Rank						=	22
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel23
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL23_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel23
	Rank						=	23
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel24
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL24_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel24
	Rank						=	24
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END

ExperienceLevel HighElvesHeroLevel25
	TargetNames					=	H_HERO_FILTER_DAMAGE_BUFF H_HERO_FILTER_RANGE_BUFF
	RequiredExperience			=	H_HERO_LVL25_EXP_NEEDED
	ExperienceAward				=	ELVEN_LEGOLAS_AWARD_LEVEL_10
	AttributeModifiers			=	HighElvesHeroBonusLevel25
	Rank						=	25
	Upgrades					=	Upgrade_New5
	LevelUpFx					=	FX:GoodLevelUpFX
	SelectionDecal
		Texture					=	decal_hero_good
		Style					=	SHADOW_ALPHA_DECAL
		OpacityMin				=	50% 
		OpacityMax				=	100% 
		MinRadius				=	ELVEN_LEGOLAS_DECAL_MIN_RADIUS
		MaxRadius				=	ELVEN_LEGOLAS_DECAL_MAX_RADIUS
		MaxSelectedUnits		=	40
	End
END
