	
  
  Behavior = PassiveAreaEffectBehavior ModuleTag_NimrodelWatersHealing
		UpgradeRequired			    = Upgrade_NimrodelWaters
		EffectRadius			      = H_ELVEN_NIMRODEL_WATERS_HEAL_AOE ;100 ;200 // please update the decal size in experience lvl INI if you change this... the value there is about 2.2x the value here
		PingDelay				        = 2000;msec
		HealPercentPerSecond	  = 3%
		AllowFilter				      = ANY +INFANTRY +CAVALRY +HERO -MACHINE +MONSTER -IMMOBILE +DOZER
		NonStackable			      = Yes
		HealFX					        = FX_SpellHealUnitHealBuff
	End

	Behavior = BannerCarrierUpdate BannerCarrierUpdateModuleTag
		UpgradeRequired			    = Upgrade_NimrodelWaters
		IdleSpawnRate				  = 10000 ;;,;; 10000	;5000							; spawn a new member every n seconds when idle (in miliseconds)		
		UnitSpawnFX					  = FX_BannerCarrierSpawnUnit		; name of particle FX to use when the BannerCarrier spawns a new unit		
		; This well object acts like a banner carrier except it spawns unit on nearby hordes instead of itself.
		ReplenishNearbyHorde		= Yes
		ReplenishAllNearbyHordes	= Yes
		ScanHordeDistance			= H_ELVEN_NIMRODEL_WATERS_HEAL_AOE
	End

  