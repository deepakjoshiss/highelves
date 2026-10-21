Behavior = ObjectCreationUpgrade ModuleTag_EnableCostModifierWithADelay ;,;
    TriggeredBy             = Upgrade_MordorFaction Upgrade_WildFaction Upgrade_AngmarFaction Upgrade_ArnorFaction Upgrade_IsengardFaction Upgrade_MenFaction Upgrade_DwarfFaction Upgrade_ElfFaction
    Delay                   = 100.0 ;,; must be slightly delayed for prices to be accurate ;,; 
    GrantUpgrade = Upgrade_ObjectLevel1
End
Behavior = CostModifierUpgrade ModuleTag_InverseDiscounsCostModifier
    LabelForPalantirString	= GUI:FortressInverseDiscount
    StartsActive = No ;,; Yes
    TriggeredBy				= Upgrade_ObjectLevel1
    ConflictsWith           = Upgrade_IsWotr
    ObjectFilter			= ANY +MenFortress +DwarvenFortress +ElvenFortress +IsengardFortress +MordorFortress +WildFortress +AngmarFortress
    Percentage				= 20.00% ;,; 25.00%
    Percentage				= 40.00% ;,; 50.00%
    Percentage				= 60.01% ;,; 75.00%
    Percentage				= 80.00% ;,; 100.00%
    Percentage				= 100.00% ;,; 125.00% 
End
Behavior = CostModifierUpgrade ModuleTag_CostModifier
    LabelForPalantirString	= GUI:STRUCTURE_WALL_DISCOUNT
    StartsActive = Yes
    ObjectFilter			= ANY +MenFortress +DwarvenFortress +ElvenFortress +IsengardFortress +MordorFortress +WildFortress +AngmarFortress
    Percentage				= 25.00%
    Percentage				= 50.00%
;    Percentage				= 75.00%
;    Percentage				= 100.00%
;    Percentage				= 125.00% 
End
