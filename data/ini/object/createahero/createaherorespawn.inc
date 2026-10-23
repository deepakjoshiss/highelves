

	Body = RespawnBody ModuleTag_RespawnBody
		CheerRadius 				= EMOTION_CHEER_RADIUS
		MaxHealth         			= CREATE_A_HERO_HEALTH ;;,;; ;;;FARAMIR_HEALTH	//BALANCE CreateAHero Health
		PermanentlyKilledByFilter	= NONE						//Who kills me permanently?
   		DodgePercent      			= HERO_DODGE_PERCENT
	End
	Behavior = RespawnUpdate ModuleTag_RespawnUpdate
		DeathAnim					= DYING						//Model condition to play when killed-to-respawn
		DeathFX						= FX_HeroDieToRespawn		//FXList to play when killed-to-respawn
		DeathAnimationTime			= 5000						//How long DeathAnim will take.
		InitialSpawnFX				= FX_HeroInitialSpawn
		RespawnAnim					= LEVELED					//Animation to play when respawning.
		RespawnFX					= FX_HeroRespawn			//FXList to play when respawning.
		RespawnAnimationTime		= 2000						//Time it takes for respawn to play.
		AutoRespawnAtObjectFilter	= NONE +CASTLE_KEEP			//Respawn at this location -- and at it's exit production point if possible.
		ButtonImage					= HIFaramir
		
		//RespawnEntries determine the ruleset for how a character can be revived. Some units may automatically respawn, others
		//may require a specific revive action performed on him. You can specify different values for each level... or use Level:Any
		;,;RespawnRules =	AutoSpawn:No		Cost:1500		Time:HERO_RESPAWNTIME_TIER_4		Health:100%		//DEFAULT VALUES ;;,;; Time previously 60000
	    ;,;new 2.02 respawn rules
		RespawnRules = AutoSpawn:No	Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_1 )		Health:100%
		RespawnEntry = Level:2					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_2 )
		RespawnEntry = Level:3					Cost:1500			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_3 )
		RespawnEntry = Level:4					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_4 )
		RespawnEntry = Level:5					Cost:1500			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_5 )
		RespawnEntry = Level:6					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_6 )
		RespawnEntry = Level:7					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_7 )
		RespawnEntry = Level:8					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_8 )
		RespawnEntry = Level:9					Cost:1500 			Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_9 )
		RespawnEntry = Level:10				Cost:1500   		Time:#MULTIPLY( HERO_RESPAWNTIME_TIER_4 HERO_RESPAWN_TIME_SCALAR_LEVEL_10 )
	End
