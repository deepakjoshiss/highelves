	DamageNugget; A basic Nugget that just does damage
        Damage         = 350
		DamageScalar   = 40% ANY +Drogoth +GondorGwaihir_Summoned +GondorGwaihir +MordorFellBeast +MordorWitchKingOnFellBeast +ElvenFortressEagle +SpellBookDragonStrikeDragon +KhamulFellBeast +MorgomirFellBeast
        DamageScalar   = 1000% ANY +MACHINE -DwarvenBattleWagon
		DamageScalar   = 40% NONE +DwarvenBattleWagon ;,; 200% NONE +DwarvenBattleWagon
		DamageScalar   = 100% NONE +RohanTreeBerd ;,; 200% 
		DamageScalar   = 27% ANY +HERO -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved ;,; 40% ;,; 30%
		DamageScalar   = 250% NONE +MordorMumakil
		DamageScalar   = 200% ANY +MONSTER -HERO -RohanEntBirch -RohanEntFir -RohanEntAsh -RohanEntOak -RohanGenericEnt -RohanEntBirch_Summoned -RohanEntFir_Summoned -RohanEntAsh_Summoned -RohanEntOak_Summoned -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved -WildBabyDrake
		DamageScalar   = 50% NONE +GondorFarm +DwarvenMineShaft +DwarvenMineShaftForUndermine +ElvenMallornTree +WildMineShaft +IsengardFurnace +MordorSlaughterHouse +ArnorFarm +AngmarMill +IsengardLumberMill +MordorLumberMill +WildLumberMill
		DamageScalar   = 70% ANY +STRUCTURE
		DamageScalar  = 20% ANY +PORTER
		Radius         = 0.0
        DelayTime      = 1
        DamageType     = SIEGE
        DamageFXType   = CLUBBING
        DeathType      = NORMAL
    End

	DamageNugget; Splash damage nugget one
        Damage         = 100
		DamageScalar   = 40% ANY +Drogoth +GondorGwaihir_Summoned +GondorGwaihir +MordorFellBeast +MordorWitchKingOnFellBeast +ElvenFortressEagle +SpellBookDragonStrikeDragon +KhamulFellBeast +MorgomirFellBeast
        DamageScalar   = 1000% ANY +MACHINE -DwarvenBattleWagon
		DamageScalar   = 40% NONE +DwarvenBattleWagon ;,; 200% NONE +DwarvenBattleWagon
		DamageScalar   = 100% NONE +RohanTreeBerd ;,; 200% 
		DamageScalar   = 27% ANY +HERO -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved ;,; 40% ;,; 30%
        DamageScalar   = 250% NONE +MordorMumakil
		DamageScalar   = 200% ANY +MONSTER -HERO -RohanEntBirch -RohanEntFir -RohanEntAsh -RohanEntOak -RohanGenericEnt -RohanEntBirch_Summoned -RohanEntFir_Summoned -RohanEntAsh_Summoned -RohanEntOak_Summoned -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved -WildBabyDrake
		DamageScalar   = 50% NONE +GondorFarm +DwarvenMineShaft +DwarvenMineShaftForUndermine +ElvenMallornTree +WildMineShaft +IsengardFurnace +MordorSlaughterHouse +ArnorFarm +AngmarMill +IsengardLumberMill +MordorLumberMill +WildLumberMill
		DamageScalar   = 70% ANY +STRUCTURE
		DamageScalar   = 250% ANY +MordorBlackRider
		DamageScalar  = 20% ANY +PORTER
		Radius         = 15.0
        DelayTime      = 1
        DamageType     = SIEGE
        DamageFXType   = CLUBBING
        DeathType      = NORMAL
    End
    DamageNugget; Splash damage nugget two
        Damage         = 150
		DamageScalar   = 40% ANY +Drogoth +GondorGwaihir_Summoned +GondorGwaihir +MordorFellBeast +MordorWitchKingOnFellBeast +ElvenFortressEagle +SpellBookDragonStrikeDragon +KhamulFellBeast +MorgomirFellBeast
        DamageScalar   = 1000% ANY +MACHINE -DwarvenBattleWagon
		DamageScalar   = 40% NONE +DwarvenBattleWagon ;,; 200% NONE +DwarvenBattleWagon
		DamageScalar   = 100% NONE +RohanTreeBerd ;,; 200% 
		DamageScalar   = 27% ANY +HERO -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved ;,; 40% ;,; 30%
        DamageScalar   = 250% NONE +MordorMumakil
		DamageScalar   = 200% ANY +MONSTER -HERO -RohanEntBirch -RohanEntFir -RohanEntAsh -RohanEntOak -RohanGenericEnt -RohanEntBirch_Summoned -RohanEntFir_Summoned -RohanEntAsh_Summoned -RohanEntOak_Summoned -WildFireDrake -WildFortressFireDrake -FireDrake_Slaved -WildBabyDrake
		DamageScalar   = 50% NONE +GondorFarm +DwarvenMineShaft +DwarvenMineShaftForUndermine +ElvenMallornTree +WildMineShaft +IsengardFurnace +MordorSlaughterHouse +ArnorFarm +AngmarMill +IsengardLumberMill +MordorLumberMill +WildLumberMill
		DamageScalar   = 70% ANY +STRUCTURE
		DamageScalar   = 200% ANY +MordorBlackRider
		DamageScalar  = 20% ANY +PORTER
		Radius         = 30.0
        DelayTime      = 1
        DamageType     = SIEGE
        DamageFXType   = CLUBBING
        DeathType      = NORMAL
    End

    MetaImpactNugget; A Nugget that throws things back with force
        ;HeroResist         = 50.0 ;always works on heroes
        ShockWaveAmount    = 60.0
        ShockWaveRadius    = 30.0
        ShockWaveTaperOff  =  0.5
    End
