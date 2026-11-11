; The High Elves faction's macros
#define H_SPEED_MULT                1
#define H_EXP_GAIN                  #MULTIPLY( H_SPEED_MULT 1 ) 
#define H_PRODUCTION_SPEED          #MULTIPLY( H_SPEED_MULT 1 )
#define H_RECHARGE_TIME             #DIVIDE( 1 H_SPEED_MULT )
#define H_FAST_WEAPON_SPEED_MIN                 300
#define H_FAST_WEAPON_SPEED                     600 
#define H_FAST_WEAPON_SPEED_MAX                 800
#define H_ARCHER_RADIUS                         10
#define H_H_FAST_WEAPON_SPEED_MIN               300
#define H_H_FAST_WEAPON_SPEED                   600 
#define H_H_FAST_WEAPON_SPEED_MAX               1200
#define H_H_MED_WEAPON_SPEED_MIN               350
#define H_H_MED_WEAPON_SPEED                   450 
#define H_H_MED_WEAPON_SPEED_MAX               700
#define H_ARCHER_RANGE_MULTI                    .010
#define H_GENERIC_BUFF_RECIPIENT_OBJECT_FILTER	ANY +INFANTRY +CAVALRY -MONSTER -SIEGEENGINE -MACHINE -IMMOBILE -DOZER -HERO -STRUCTURE -BASE_FOUNDATION -HORDE -SHIP -DwarvenBattleWagon -RohanOathbreaker -MordorRamCrew +MordorWorker -IsengardRamCrew -IsengardBeserker -DwarvenZerker -DwarvenZerkerHorde -GondorKnightsofDol -GondorKnightsofDolHorde -WildBabyDrake -WildBabyDrakeHorde -MordorBlackRider -MordorBlackRiderHorde -IsengardFanatic -IsengardBerserkerHorde -IsengardExplosiveMine -IsengardDeployedExplosiveMine -WildSpiderling_Slaved -AngmarDireWolf_Slaved -IsengardWarg_Slaved ;;,;; removed WargSentries, Fortress Spiderlings/Wolves, SIEGEENGINE and MONSTER (3.0.1 - experimental); added Mines; Added -SHIP for v3.0.3 ship balance
#define H_GENERIC_SPEED_BUFF_OBJECT_FILTER	    ANY +INFANTRY +ARCHER +CAVALRY +HERO +MACHINE +HORDE -MONSTER -STRUCTURE -BASE_FOUNDATION
#define H_ALL_ELVEN_ARCHER_AURA_FILTER          NONE +HEElvenMirkwoodArcher +HEElvenMirkwoodArcherHorde +HEElvenMirkwoodArcherBanner +GaladhrimWarrior +GaladhrimWarriorHorde +NoldorArcher +NoldorArcherHorde
#define H_HERO_FILTER_DAMAGE_BUFF               HEElvenElrond HEElvenHaldir HEElvenGlorfindel
#define H_HERO_FILTER_RANGE_BUFF                MirkwoodTauriel ; HEElvenThranduil has his own levels 2-25 (hero rework)
#define H_ELVEN_ARCHER_DAMAGE_FILTER            HEElvenMirkwoodArcher HEElvenMirkwoodArcherHorde HEElvenMirkwoodArcherBanner GaladhrimWarrior GaladhrimWarriorHorde RivendellKnights RivendellKnightsHorde
#define	H_HERO_BOW_RANGE				        	420
#define	H_VISION_HERO_RANGED				    	450
#define H_SHROUD_CLEAR_RANGED_HERO				550
#define H_HERO_AURA_RANGE               	280
#define H_LEGOLAS_PREATTACKDELAY 					800 
#define H_LEGOLAS_DELAYBETWEENSHOTS 			0 
#define H_LEGOLAS_FIRINGDURATION 					0
#define H_LEGOLAS_RELOADTIME_MIN					1000
#define H_LEGOLAS_RELOADTIME_MAX					1000
#define H_HALDIR_PREATTACKDELAY 					800 
#define H_HALDIR_RELOADTIME_MIN				    1100
#define H_HALDIR_RELOADTIME_MAX				    1100
#define	H_THRANDUIL_BOW_DAMAGE				    120 ; hero rework (openbfme/HERO-REWORK-PLAN.md) ;,; 200
#define	H_THRANDUIL_BUILDCOST				    	800 ; hero rework ;,; 3000
#define	H_LEGOLAS_BOW_DAMAGE				    	150
#define	H_LEGOLAS_BUILDCOST				    		2500
#define	H_TAURIEL_BOW_DAMAGE				    130
#define	H_TAURIEL_BUILDCOST				    2200
#define	H_HALDIR_BOW_DAMAGE				    150
#define	H_HALDIR_BUILDCOST				    2000
#define	H_ELROND_BOW_DAMAGE	                150
#define	H_ELROND_BUILDCOST			        2500
#define	H_TAURIEL_EXPLODING_ARROW_RADIUS	    50
#define H_FAST_ARCHER_BOW_PREATTACKDELAY 	    500
#define H_FAST_ARCHER_BOW_RELOADTIME_MIN	    1000 ;;.;; 750
#define H_FAST_ARCHER_BOW_RELOADTIME_MAX	    1200 ;;.;; 1000
#define H_ELVEN_NOLDORWARRIOR_BUILDTIME			35
#define H_ELVEN_NOLDORWARRIOR_BUILDCOST			2500
#define H_MIRKWOOD_ARCHER_BUILDTIME			    30
#define H_MIRKWOOD_ARCHER_BUILDCOST			    700
#define H_ELVEN_MIRKWOOD_ARCHER_RANGE           500
#define H_GALADHRIM_WARRIOR_BUILDTIME		    		25
#define H_GALADHRIM_WARRIOR_BUILDCOST		    		450
#define H_GALADHRIM_WARRIOR_VISION_RANGE	    	450
#define H_GALADHRIM_WARRIOR_HORDE_VISION_RANGE	400
#define H_GALADHRIM_WARRIOR_HORDE_SHROUD_RANGE	500
#define H_GALADHRIM_WARRIOR_BOW_RANGE		    		420
#define H_GALADHRIM_WARRIOR_BOW_DAMAGE		    	75
#define H_GALADHRIM_WARRIOR_BOW_DAMAGE_MAGIC		30
#define H_RIVENDELL_KNIGHTS_BUILDCOST		    	  1200
#define H_RIVENDELL_KNIGHTS_DAMAGE		    	    175
#define H_RIVENDELL_KNIGHTS_CRUSH_DAMAGE		    175
#define H_RIVENDELL_KNIGHTS_DAMAGE_MAGIC	      40
#define H_RIVENDELL_KNIGHTS_DAMAGE_SIEGE        40
#define H_SUPER_TOWER_BUILDTIME			               35
#define H_SUPER_TOWER_BUILDCOST			               2000
#define H_ELVEN_BARRACKS_BUILDTIME			            25
#define H_ELVEN_BARRACKS_LEVEL2_UPGRADE_COST			  750	; RotWK originally 500
#define H_ELVEN_BARRACKS_LEVEL2_UPGRADE_BUILDTIME		25
#define H_ELVEN_BARRACKS_LEVEL3_UPGRADE_COST			  1000
#define H_ELVEN_BARRACKS_LEVEL3_UPGRADE_BUILDTIME		40
#define H_ELVEN_MALLORN_TREE_BUILDTIME				    15
#define H_ELVEN_MALLORN_TREE_BLOOM_COST				    400
#define H_ELVEN_MALLORN_TREE_BLOOM_TIME				    15
#define H_ELVEN_NIMRODEL_WATERS_COST              400
#define H_ELVEN_NIMRODEL_WATERS_HEAL_AOE				  250
#define H_ELVEN_MALLORN_TREE_LVL2_EXP_NEEDED			1500
#define H_ELVEN_MALLORN_TREE_LVL3_EXP_NEEDED 			3000
#define H_STANDARD_HORDE_EXIT_DELAY			            5
#define H_ELVEN_SENTRY_TOWER_BUILDTIME				    35
#define H_ELVEN_SENTRY_TOWER_BUILDCOST				    600
#define H_SPELL_REBUILD_RADIUS_STRUCTURE_SCAN       300
#define H_PLAYER_MAX_PURCHASE_POINTS_DEFAULT        260
#define H_PLAYER_MAX_PURCHASE_POINTS_GOOD           260
#define H_SPELL_LIGHT_OF_TREES_DURATION                 20000 ;,; 180000
#define H_SPAWN_TREE_FLET_DECAL_RADIUS                  25
#define H_WAYSTONE_STUN_RADIUS                          100
#define H_HERO_COMMAND_POINTS_TIER_1	 10 ; v4.0 ;,; v2.3 40 ;;,;; v2.1 50 ;;,;; v2.0  20 ;;,;; 2.02f  30 ;;,;; 2.02e  40
#define H_HERO_COMMAND_POINTS_TIER_2	 20 ; v4.0 ;,; v2.3 50 ;;,;; v2.1 50 ;;,;; v2.0  40 ;;,;; 2.02f  50 ;;,;; 2.02e  60
#define H_HERO_COMMAND_POINTS_TIER_3	 30 ; v4.0 ;,; v2.3 60 ;;,;; v2.1 75 ;;,;; v2.0  60 ;;,;; 2.02f  70 ;;,;; 2.02e  80
#define H_HERO_COMMAND_POINTS_TIER_4	 40 ; v4.0 ;,; v2.3 70 ;;,;; v2.1 75 ;;,;; v2.0  80 ;;,;; 2.02f  90 ;;,;; 2.02e 100
#define H_HERO_COMMAND_POINTS_TIER_5	 50 ; v4.0 ;,; v2.3 80 ;;,;; v2.1 80 ;;,;; v2.0 100 ;;,;; 2.02f 110 ;;,;; 2.02e 120
#define H_HERO_BUILDTIME_TIER_1	25 ; v2.4 ;;,;; v2.3 50 ;;,;; v2.1 45	;;,;; 2.02e 20
#define H_HERO_BUILDTIME_TIER_2	25 ; v2.4 ;;,;; v2.3 60 ;;,;; v2.1 60	;;,;; 2.02e 30
#define H_HERO_BUILDTIME_TIER_3	30 ; v2.4 ;;,;; v2.3 70 ;;,;; v2.1 75	;;,;; 2.02e 40
#define H_HERO_BUILDTIME_TIER_4	30 ; v2.4 ;;,;; v2.3 80 ;;,;; v2.1 90	;;,;; 2.02e 50
#define H_HERO_BUILDTIME_TIER_5	40 ; v2.4 ;;,;; v2.3 90 ;;,;; v2.1 105 ;;,;; 2.02e 60
#define H_HERO_RESPAWNTIME_TIER_1 35000 ;,; 100000 ; v2.4 ;;,;; v2.3 100000 ;;,;; v2.1 90000
#define H_HERO_RESPAWNTIME_TIER_2 35250 ;,; 125000 ; v2.4 ;;,;; v2.3 120000 ;;,;; v2.1 120000
#define H_HERO_RESPAWNTIME_TIER_3 45500 ;,; 150000 ; v2.4 ;;,;; v2.3 140000 ;;,;; v2.1 150000
#define H_HERO_RESPAWNTIME_TIER_4 45750 ;,; 175000 ; v2.4 ;;,;; v2.3 160000 ;;,;; v2.1 180000 
#define H_HERO_RESPAWNTIME_TIER_5 55000 ;,; 200000 ; v2.4 ;;,;; v2.3 180000 ;;,;; v2.1 210000
#define    H_HERO_HIGH_LVL_HP_ADD               120
#define    H_HERO_HIGH_LVL_DAMAGE_MULT          104%
#define    H_HERO_HIGH_LVL_HIGH_DAMAGE_MULT     115%
#define    H_HERO_HIGH_LVL_RANGE_BONUS          15%
#define    H_HERO_HIGH_LVL_RECHARGE_TIME        25%
#define    H_HERO_LVL11_EXP_AWARD         400
#define    H_HERO_LVL12_EXP_AWARD         500
#define    H_HERO_LVL13_EXP_AWARD         600
#define    H_HERO_LVL14_EXP_AWARD         700
#define    H_HERO_LVL15_EXP_AWARD         800
#define    H_HERO_LVL16_EXP_AWARD         900
#define    H_HERO_LVL17_EXP_AWARD         1000
#define    H_HERO_LVL18_EXP_AWARD         1100
#define    H_HERO_LVL19_EXP_AWARD         1300
#define    H_HERO_LVL20_EXP_AWARD         1500
#define    H_HERO_EXP_DIVIDER             1  ;
#define    H_HERO_LVL2_EXP_NEEDED         #DIVIDE( 100 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL3_EXP_NEEDED         #DIVIDE( 200 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL4_EXP_NEEDED         #DIVIDE( 350 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL5_EXP_NEEDED         #DIVIDE( 550 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL6_EXP_NEEDED         #DIVIDE( 750 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL7_EXP_NEEDED         #DIVIDE( 1000 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL8_EXP_NEEDED         #DIVIDE( 1300 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL9_EXP_NEEDED         #DIVIDE( 1650 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL10_EXP_NEEDED        #DIVIDE( 2050 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL11_EXP_NEEDED        #DIVIDE( 2550 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL12_EXP_NEEDED        #DIVIDE( 3100 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL13_EXP_NEEDED        #DIVIDE( 3700 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL14_EXP_NEEDED        #DIVIDE( 4450 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL15_EXP_NEEDED        #DIVIDE( 5300 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL16_EXP_NEEDED        #DIVIDE( 6100 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL17_EXP_NEEDED        #DIVIDE( 6900 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL18_EXP_NEEDED        #DIVIDE( 7800 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL19_EXP_NEEDED        #DIVIDE( 8700 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL20_EXP_NEEDED        #DIVIDE( 9600 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL21_EXP_NEEDED        #DIVIDE( 10500 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL22_EXP_NEEDED        #DIVIDE( 11450 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL23_EXP_NEEDED        #DIVIDE( 12500 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL24_EXP_NEEDED        #DIVIDE( 13600 H_HERO_EXP_DIVIDER )
#define    H_HERO_LVL25_EXP_NEEDED        #DIVIDE( 15000 H_HERO_EXP_DIVIDER )

; ---- Hero rework (Legolas, Thranduil, Elrond; openbfme/HERO-REWORK-PLAN.md) ----
; Every level (2-25) adds the same: +60 HP, +1.7% damage (DAMAGE_MULT, and SPELL_DAMAGE for magic), +2 flat (DAMAGE_ADD: only the damage blocks that
; accept it, the bow's arrows; powers and item blocks say AcceptDamageAdd = No). Level 25: x1.499 damage, arrow (120 + 48) x 1.499 = 252 for Thranduil.
#define H_RW_LEVEL_HP				60
#define H_RW_LEVEL_DAMAGE_MULT		101.7%
#define H_RW_LEVEL_DAMAGE_ADD		2
; XP to reach a level: each next level costs more than the one before: 145 for level 2, +25 a level up to level 10 (2,205 in all), then +47 a
; level (13,020 at level 25); the same for the three heroes
#define H_RW_HERO_LVL2_EXP_NEEDED	145
#define H_RW_HERO_LVL3_EXP_NEEDED	315
#define H_RW_HERO_LVL4_EXP_NEEDED	510
#define H_RW_HERO_LVL5_EXP_NEEDED	730
#define H_RW_HERO_LVL6_EXP_NEEDED	975
#define H_RW_HERO_LVL7_EXP_NEEDED	1245
#define H_RW_HERO_LVL8_EXP_NEEDED	1540
#define H_RW_HERO_LVL9_EXP_NEEDED	1860
#define H_RW_HERO_LVL10_EXP_NEEDED	2205
#define H_RW_HERO_LVL11_EXP_NEEDED	2597
#define H_RW_HERO_LVL12_EXP_NEEDED	3036
#define H_RW_HERO_LVL13_EXP_NEEDED	3522
#define H_RW_HERO_LVL14_EXP_NEEDED	4055
#define H_RW_HERO_LVL15_EXP_NEEDED	4635
#define H_RW_HERO_LVL16_EXP_NEEDED	5262
#define H_RW_HERO_LVL17_EXP_NEEDED	5936
#define H_RW_HERO_LVL18_EXP_NEEDED	6657
#define H_RW_HERO_LVL19_EXP_NEEDED	7425
#define H_RW_HERO_LVL20_EXP_NEEDED	8240
#define H_RW_HERO_LVL21_EXP_NEEDED	9102
#define H_RW_HERO_LVL22_EXP_NEEDED	10011
#define H_RW_HERO_LVL23_EXP_NEEDED	10967
#define H_RW_HERO_LVL24_EXP_NEEDED	11970
#define H_RW_HERO_LVL25_EXP_NEEDED	13020
; XP awarded for killing the hero at a level: the 2.02 hero factor (100% at level 1, +10% a level), continued to level 25
#define H_RW_AWARD_FACTOR_LEVEL_2	110
#define H_RW_AWARD_FACTOR_LEVEL_3	120
#define H_RW_AWARD_FACTOR_LEVEL_4	130
#define H_RW_AWARD_FACTOR_LEVEL_5	140
#define H_RW_AWARD_FACTOR_LEVEL_6	150
#define H_RW_AWARD_FACTOR_LEVEL_7	160
#define H_RW_AWARD_FACTOR_LEVEL_8	170
#define H_RW_AWARD_FACTOR_LEVEL_9	180
#define H_RW_AWARD_FACTOR_LEVEL_10	190
#define H_RW_AWARD_FACTOR_LEVEL_11	200
#define H_RW_AWARD_FACTOR_LEVEL_12	210
#define H_RW_AWARD_FACTOR_LEVEL_13	220
#define H_RW_AWARD_FACTOR_LEVEL_14	230
#define H_RW_AWARD_FACTOR_LEVEL_15	240
#define H_RW_AWARD_FACTOR_LEVEL_16	250
#define H_RW_AWARD_FACTOR_LEVEL_17	260
#define H_RW_AWARD_FACTOR_LEVEL_18	270
#define H_RW_AWARD_FACTOR_LEVEL_19	280
#define H_RW_AWARD_FACTOR_LEVEL_20	290
#define H_RW_AWARD_FACTOR_LEVEL_21	300
#define H_RW_AWARD_FACTOR_LEVEL_22	310
#define H_RW_AWARD_FACTOR_LEVEL_23	320
#define H_RW_AWARD_FACTOR_LEVEL_24	330
#define H_RW_AWARD_FACTOR_LEVEL_25	340
#define H_THRANDUIL_HEALTH			1100 ; 2.02: 2000
#define H_THRANDUIL_RAMPAGE_RELOAD	600 ; fires every 3rd logic frame with OpenBFMEFireWaitsForReload (the normal bow: every 5th)
#define H_THRANDUIL_THORN_DAMAGE		1500 ; 2.02: 2000
#define H_THRANDUIL_THORN_MAGIC_DAMAGE	600 ; the burst (radius 60) and the hit each; 2.02: 850
#define H_THRANDUIL_PINNING_DAMAGE	400
#define H_THRANDUIL_PINNING_DURATION	4000
#define H_THRANDUIL_SUMMON_LIFETIME	40000
; Thranduil's Armory (hero rework, pass 2)
#define H_THRANDUIL_ARROWHEADS1_COST	300
#define H_THRANDUIL_ARROWHEADS1_TIME	10 ; seconds (placeholder)
#define H_THRANDUIL_ARROWHEADS1_DAMAGE	80 ; hero damage to monsters and machines, the level percentage only
#define H_THRANDUIL_ARMOR1_COST	250
#define H_THRANDUIL_ARMOR2_COST	700
#define H_THRANDUIL_ARMOR3_COST	1500
#define H_THRANDUIL_LIFE1_COST	250
#define H_THRANDUIL_LIFE2_COST	700
#define H_THRANDUIL_LIFE3_COST	1500
#define H_THRANDUIL_MOBILITY1_COST	200
#define H_THRANDUIL_MOBILITY2_COST	500
#define H_THRANDUIL_MOBILITY3_COST	1200
#define H_THRANDUIL_BOW1_COST	300
#define H_THRANDUIL_BOW2_COST	1000
#define H_THRANDUIL_BOW3_COST	2500
#define H_THRANDUIL_ARROWHEADS2_COST	1000
#define H_THRANDUIL_ARROWHEADS3_COST	2500
#define H_THRANDUIL_DAMAGE1_COST	300
#define H_THRANDUIL_DAMAGE2_COST	1000
#define H_THRANDUIL_DAMAGE3_COST	2500
#define H_THRANDUIL_HUNTER1_COST	200
#define H_THRANDUIL_HUNTER2_COST	500
#define H_THRANDUIL_HUNTER3_COST	1000
#define H_THRANDUIL_ITEM_TIME	10 ; seconds (placeholder)

; Reworked heroes' targeted powers (Legolas, Thranduil; Deepak 2026-11-11): they start from here, times the hero's range bonus (openbfme.ini's
; OpenBFMEAbilityRangeFollowsBonus), and their weapons reach the second, never short of the start (a shot beyond it is spent with no arrow)
#define H_RW_HERO_POWER_START	450
#define H_RW_HERO_POWER_REACH	475

; ---- Legolas (hero rework, openbfme/HERO-REWORK-PLAN.md): an infantry killer, bow only. HEElvenLegolas's own values: HERohanLegolas's
; (H_LEGOLAS_*) stay, ElvenElrohir is a copy of it
#define H_RW_LEGOLAS_BUILDCOST		800
#define H_RW_LEGOLAS_HEALTH		1000
#define H_RW_LEGOLAS_BOW_DAMAGE	90 ; takes the level's flat bonus (DAMAGE_ADD)
#define H_RW_LEGOLAS_INFANTRY_SCALAR	125% ; his arrow against infantry
#define H_RW_LEGOLAS_PIERCING_DAMAGE	250
; Legolas's Armory (hero rework, pass 2; prices set by Deepak 2026-11-11)
#define H_LEGOLAS_ITEM_TIME	10 ; seconds (placeholder)
#define H_LEGOLAS_ARMOR1_COST	250
#define H_LEGOLAS_ARMOR2_COST	700
#define H_LEGOLAS_ARMOR3_COST	1500
#define H_LEGOLAS_LIFE1_COST	250
#define H_LEGOLAS_LIFE2_COST	700
#define H_LEGOLAS_LIFE3_COST	1500
#define H_LEGOLAS_MOBILITY1_COST	200
#define H_LEGOLAS_MOBILITY2_COST	500
#define H_LEGOLAS_MOBILITY3_COST	1200
#define H_LEGOLAS_BOW1_COST	300
#define H_LEGOLAS_BOW2_COST	1000
#define H_LEGOLAS_BOW3_COST	2500
#define H_LEGOLAS_ARROWHEADS1_COST	200
#define H_LEGOLAS_ARROWHEADS2_COST	600
#define H_LEGOLAS_ARROWHEADS3_COST	1500
#define H_LEGOLAS_HAWK1_COST	300
#define H_LEGOLAS_HAWK2_COST	800
#define H_LEGOLAS_HAWK3_COST	2500
#define H_LEGOLAS_HEARTSEEKER1_COST	300
#define H_LEGOLAS_HEARTSEEKER2_COST	800
#define H_LEGOLAS_HEARTSEEKER3_COST	2000
