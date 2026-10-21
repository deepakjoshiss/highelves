;;;,;================ CORRODE ALLEGIANCE CP BUG FIX ==========================;,;
;,; 1. When Corrode Allegiance is cast on me,
;,;    Spawn a temporary shadow that belongs to the original player that CAN convert other CP shadows ;	
    
	Behavior = ObjectCreationUpgrade ModuleTag_SpawnCorrodeAllegianceCommandPointReducer ;,;
		TriggeredBy             = Upgrade_CorrodeAllegianceNegativeCPHack ;,; 
		Delay                   = 0.0
		ThingToSpawn    		= CorrodeAllegianceNeutralShadowConverter
		Offset                  = X:0 Y:0 Z:0
	End

;,; 2. Immediately spawn a neutral shadow equal to the hero's command points 
    Behavior = DoCommandUpgrade ModuleTag_TriggerNeutralShadowSpawn ;,;
        TriggeredBy                        = Upgrade_CorrodeAllegianceNegativeCPHack
        GetUpgradeCommandButtonName        = Command_SpecialAbilitySpawnNeutralCPShadow
    End
    Behavior = OCLSpecialPower ModuleTag_SpawnNeutralConvertibleShadow
        SpecialPowerTemplate        = SpecialAbilitySpawnNeutralShadow
        OCL                  = OCL_SpawnTier5NegativeCPShadow ;,; TIER 5 HERO
        CreateLocation            = CREATE_AT_LOCATION
        AvailableAtStart        = Yes
    End	

;,; 3. wait until our shadow from #1 converts the neutral shadow. 
;,; Once the what used to be neutral shadow dies, the heroes' used CPs are deducted from the original player ;,; 

;,; 4. Spawn a permanent shadow while in the enemy's possession, 
;,;    since heroes' CP does not get transferred upon conversion 

	Behavior = ObjectCreationUpgrade ModuleTag_SpawnCorrodeAllegianceCommandPointShadow ;,;
		TriggeredBy             = Upgrade_CorrodeAllegianceCPHack ;,; 
		Delay                   = 0.0
		ThingToSpawn    		= HeroTier5CPShadow ;,; TIER 5 HERO
		Offset                  = X:-9999.0 Y:-9999.0 Z:0.0 ;,;X:0 Y:0 Z:-299
	End

;,;================ CORRODE ALLEGIANCE CP BUG FIX END ==========================;,;
