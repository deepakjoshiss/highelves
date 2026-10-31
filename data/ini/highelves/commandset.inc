; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

CommandSet HEElvenPorterCommandSet   
   1  = Command_Stop
   2  = Command_PorterExtinguishFire   
   3  = HECommand_ConstructElvenMallornTree
   4  =	HECommand_ConstructElvenBarracks
   5  = HECommand_ConstructElvenGreenPasture
   6  =	HECommand_ConstructElvenEntMoot
   7  = HECommand_ConstructElvenWatchTower ;;,;; HECommand_ConstructElvenStatue
   8  =	Command_ConstructElvenMirrorOfGaladriel ;;,;; HECommand_ConstructElvenWatchTower
   9  = HECommand_ConstructElvenStatue ;;,;; Command_ConstructElvenMirrorOfGaladriel   
   10 = Command_ConstructEregionForge
   11 = Command_ConstructSuperBattleTower
   12 =	Command_ConstructElvenWallHub
   13 = HECommand_ConstructElvenFortress

End

CommandSet HERohanLegolasCommandSet
	1	= Command_ToggleStance
	2  	= HECommand_LegolasHawkStrike
	3  	= Command_SpecialAbilityTrainArchersLegolas ;;,;; Command_LegolasKnifeFightingMode
	4  	= Command_ToggleLegolasWeapon ;,; Command_LegolasKnifeFightingMode ;;,;; Command_SpecialAbilityTrainArchersLegolas ;;,;; Command_SpecialAbilityTrainArchers
	5  	= Command_SpecialAbilityArrowStorm
	6	= Command_SpecialAbilityRamBaan
	7  	= Command_LegolasHawkStrike_AI ;;,;; Sûlherokhh AI bugfix - prevents ability from being used when it shouldn't be
	8  	= Command_SpecialAbilityArrowStorm_AI ;;,;; Sûlherokhh AI bugfix - prevents ability from being used when it shouldn't be
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

CommandSet HEElrondCommandSet
	1	= Command_ToggleStance
	2	= Command_ElrondFakeLeadership ;,; Command_SpecialAbility202ElrondElvenGrace ;;.;; Command_SpecialAbilityElrondElvenGrace
	3	= HECommand_SpecialAbilityElrondFarsight ;;,;; Command_ElrondFakeLeadership
	4	= Command_SpecialAbility202ElrondElvenGrace ;,; Command_ElrondFakeLeadership ;;,;; HECommand_SpecialAbilityElrondFarsight
	5	= Command_SpecialAbilityElrondRestoration ;,;Command_SpecialPowerSpawnWhirlwind ;;,;; Command_SpecialAbilityElrondRestoration
	6	= Command_SpecialPowerSpawnWhirlwind ;,; Command_SpecialAbilityElrondRestoration ;;,;; Command_SpecialPowerSpawnWhirlwind
	12	= Command_CaptureBuilding
	13	= Command_AttackMove
	14	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

CommandSet HEDwarvenSummonedCitadelCommandSet ;;,;; 2.02e commandset
	InitialVisible = 7
	1	= Command_ConstructDwarvenPorter
	2   	= Command_SelectRevivablesDwarvenFortress
	3	= Command_PurchaseUpgradeSummonedStructureFlamingMunitions
	4   = Command_PurchaseUpgradeDwarvenSummonedCitadelDwarvenStonework ;,;
	5	= Command_FireWeaponMightyCatapult ;,; 4	;;,;; Added for 3.0.0
	6	= Command_Sell
	7   = Command_ExitGarrison

	//Hero Menu
	15	= Command_RingHeroReviveSlot		// Note that we need an extra slot for the ring hero.
	16	= Command_CreateAHeroReviveSlot		// Note we also need an extra slot for the Create A Hero
	17	= Command_GenericReviveSlot1		//Revives any hero. Use Slot1-Slot8 and keep them UNIQUE within the same commandset! 
	18	= Command_GenericReviveSlot2		
	19	= Command_GenericReviveSlot3		
	20	= Command_GenericReviveSlot4		
	21	= Command_GenericReviveSlot5		
	22	= Command_GenericReviveSlot6		
	23	= Command_GenericReviveSlot7		
	24	= Command_RadialBack
	25  = Command_FireWeaponMightyCatapult_AI ;,;
End

CommandSet HEElvenFortressCommandSet
	InitialVisible = 6
	//Main Menu
	1	= HECommand_ConstructElvenPorter
;	2	= HECommand_ConstructNoldorWarriorHorde				; Added for BFME2 Expansion
	2   	= Command_SelectRevivablesElvenFortress
	3	= Command_SelectUpgradesElvenFortress
	4	= Command_PurchaseNewEagle
	5   = Command_EnableCEContentsElves ;,;
	6	= Command_Sell
	
		//Improvements
	7       = Command_PurchaseUpgradeElvenFortressEnchantedAnvil
	8	= Command_PurchaseUpgradeElvenFortressBlessedMist
	9	= Command_PurchaseUpgradeElvenFortressCrystalMoat
	10	= Command_PurchaseUpgradeElvenFortressMysticFountains
	11	= Command_PurchaseUpgradeElvenFortressFlamingMunitions ;;,;; Added for 2.1, pushing down positions of following buttons by one
	12	= Command_PurchaseUpgradeElvenFortressEncasingVines
	13	= Command_PurchaseUpgradeElvenFortressEaglesNest
	14	= Command_RadialBack
	
	//Heroes
	15	= Command_RingHeroReviveSlot
	16	= Command_CreateAHeroReviveSlot		// Note we also need an extra slot for the Create A Hero
	17	= Command_GenericReviveSlot1		//Revives any hero. Use Slot1-Slot8 and keep them UNIQUE within the same commandset! 
	18	= Command_GenericReviveSlot2	
	19	= Command_GenericReviveSlot3	
	20	= Command_GenericReviveSlot4	
	21	= Command_GenericReviveSlot5	
	22	= Command_GenericReviveSlot6	
	23	= Command_GenericReviveSlot7
	24	= Command_RadialBack			
End

CommandSet HEERElvenBarracksCommandSet
  	1 	= HECommand_ConstructElvenLorienWarriorHorde
  	2 	= HECommand_ConstructElvenLorienArcherHorde
  	3 	= HECommand_ConstructElvenMithlondSentryHorde
	4 	= Command_ConstructElvenGladhrimHorde
  	5 	= HECommand_ConstructElvenMirkwoodArcherHorde
 	7 	= HECommand_ConstructNoldorWarriorHorde
	8 	= Command_ConstructNoldorArcherHorde
  	9 	= HECommand_PurchaseUpgradeElvenBarracksLevel2
  	6 	= Command_Sell
End

CommandSet HEElvenBarracksCommandSetLevel2
  	1 	= HECommand_ConstructElvenLorienWarriorHorde
  	2 	= HECommand_ConstructElvenLorienArcherHorde
  	3 	= HECommand_ConstructElvenMithlondSentryHorde
	4 	= Command_ConstructElvenGladhrimHorde
  	5 	= HECommand_ConstructElvenMirkwoodArcherHorde
 	7 	= HECommand_ConstructNoldorWarriorHorde
	8 	= Command_ConstructNoldorArcherHorde
  	9 	= HECommand_PurchaseUpgradeElvenBarracksLevel3
  	6 	= Command_Sell
End

CommandSet HEElvenBarracksCommandSetLevel3
  	1 	= HECommand_ConstructElvenLorienWarriorHorde
  	2 	= HECommand_ConstructElvenLorienArcherHorde
  	3 	= HECommand_ConstructElvenMithlondSentryHorde
	4 	= Command_ConstructElvenGladhrimHorde
  	5 	= HECommand_ConstructElvenMirkwoodArcherHorde
 	7 	= HECommand_ConstructNoldorWarriorHorde
	8 	= Command_ConstructNoldorArcherHorde
  	6 	= Command_Sell
;  	7 	= Command_ConstructElvenLindonWarriorHorde
;  	8 	= Command_ConstructElvenImladrisWarriorHorde
End

CommandSet HEElvenGreenPastureCommandSet
  	1 	= HECommand_ConstructElvenRivendellLancers
  	2 	= Command_ConstructElvenRivendellArchers
		3 	= Command_ConstructElvenRivendellKnights
  	4 	= Command_ConstructElvenGreenPastureLevel2
  	6 	= Command_Sell
End

CommandSet HEElvenGreenPastureCommandSetLevel2
  	1 	= HECommand_ConstructElvenRivendellLancers
  	2 	= Command_ConstructElvenRivendellArchers
		3 	= Command_ConstructElvenRivendellKnights
  	4 	= Command_ConstructElvenGreenPastureLevel3
  	6 	= Command_Sell
End

CommandSet HEElvenGreenPastureCommandSetLevel3
  	1 	= HECommand_ConstructElvenRivendellLancers
  	2 	= Command_ConstructElvenRivendellArchers
		3 	= Command_ConstructElvenRivendellKnights
  	6 	= Command_Sell
End

CommandSet HEElvenEntMootCommandSet ;,;
  	1 	= Command_ConstructEntAshMelee
  	2	= Command_ConstructEntGeneric
	3   = HECommand_ConstructEntTreeBeard
  	4 	= Command_PurchaseUpgradeElvenEntMootLevel2
  	6 	= Command_Sell
End

CommandSet HEElvenEntMootCommandSetLevel2 ;,;
  	1 	= Command_ConstructEntAshMelee
  	2	= Command_ConstructEntGeneric
	3   = HECommand_ConstructEntTreeBeard
  	4 	= Command_PurchaseUpgradeElvenEntMootLevel3
  	6 	= Command_Sell
End

CommandSet HEElvenEntMootCommandSetLevel3 ;,;
  	1 	= Command_ConstructEntAshMelee
	2   = Command_ConstructEntGeneric
  	3	= HECommand_ConstructEntTreeBeard
  	6 	= Command_Sell
End

CommandSet HEElvenGlorfindelCommandSet
	1	= Command_ToggleStance 
	2 	= Command_MountHorseGlorfindel
	3 	= Command_SpecialAbilityGlorfindelBladeOfPurity
	4 	= Command_SpecialAbilityGlorfindelWindRider
	5 	= HECommand_GlorfindelStarlight
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  = Command_SetStanceBattle
	17  = Command_SetStanceAggressive
	18  = Command_SetStanceHoldGround
End

CommandSet HEElvenThranduilCommandSet	
	1	= Command_ToggleStance
    2  	= Command_SpecialAbilityElfCloakThranduil ;;,;; Command_ThranduilWildWalkButton
	3  	= Command_SpecialAbilityMoveUnseen ;,; Command_ThranduilWildWalkButton ;,; Command_SpecialAbilityMoveUnseen ;,; Command_SpecialAbilityDeadEye ;;,;; Command_SpecialAbilityMoveUnseen ; Command_SpecialAbilityDeadEye
	4  	= Command_ThranduilWildWalkButton ;,; Command_SpecialAbilityMoveUnseen ;;,;; Command_SpecialAbilityDeadEye ; Command_SpecialAbilityMoveUnseen
    5  	= Command_SpecialAbilityThranduilRampage ;,; Command_ThranduilWildWalkButton ;;,;; Command_SpecialAbilityElfCloakThranduil
    6  	= HECommand_SpecialAbilityThornofVengeance
    12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  = Command_SetStanceBattle
	17  = Command_SetStanceAggressive
	18  = Command_SetStanceHoldGround
End

CommandSet HEElvenFoundationCommandSet  
  2  = Command_ConstructERElvenBarracks
  3	 = Command_ConstructDwarvenBarracks
  4  = Command_ConstructDwarvenHearth
  5  = Command_ConstructDwarvenForgeWorks
  6  = HECommand_ConstructElvenWatchTower
  8  = HECommand_ConstructElvenMallornTree
  9  = HECommand_ConstructElvenGreenPasture  
  11 = Command_ConstructElvenMirrorOfGaladriel
End

CommandSet HEElvesSpellBookCommandSet
    1 = HECommand_SpellBookFarsight
    2 = HECommand_SpellBookRebuild
    3 = HECommand_SpellBookElvenGifts
    4 = HECommand_SpellBookRallyingCall
    5 = HECommand_SpellBookHeal

    6 = HECommand_SpellBookEnshroudingMist
    7 = HECommand_SpellBookArrowVolleyGood
    8 = HECommand_SpellBookTomBombadil
    9 = Command_SpellBookSpawnTreeFlet
    10 = Command_SpellBookRingOfAdamant
    11 = HECommand_SpellBookElvenWood

    12 = HECommand_SpellBookEagleAllies
    13 = HECommand_SpellBookEntAllies
    14 = Command_SpellBookElvenWaystone
    15 = Command_SpellBookLightOfTrees
    16 = HECommand_SpellBookCloudBreak

    17 = HECommand_SpellBookEarthquake
    18 = HECommand_SpellBookSunflare
    19 = HECommand_SpellBookFlood
    20 = HECommand_SpellBookCitadel
End

CommandSet HEElvesSpellStoreCommandSet
    1 = HECommand_PurchaseSpellFarsight
    2 = HECommand_PurchaseSpellRebuild
    3 = HECommand_PurchaseSpellElvenGifts
    4 = HECommand_PurchaseSpellRallyingCallMP
    5 = HECommand_PurchaseSpellHeal

    6 = HECommand_PurchaseSpellEnshroudingMistMP
    7 = HECommand_PurchaseSpellArrowVolleyGood
    8 = HECommand_PurchaseSpellTomBombadil
    9 = Command_PurchaseSpellSpawnTreeFlet
    10 = Command_PurchaseSpellRingOfAdamant
    11 = HECommand_PurchaseSpellElvenWood

    12 = HECommand_PurchaseSpellEagleAllies
    13 = HECommand_PurchaseSpellEntAllies
    14 = Command_PurchaseSpellElvenWaystone
    15 = Command_PurchaseSpellLightOfTrees
    16 = HECommand_PurchaseSpellCloudBreak

    17 = HECommand_PurchaseSpellEarthquake
    18 = HECommand_PurchaseSpellSunflare
    19 = HECommand_PurchaseSpellFlood
    20 = HECommand_PurchaseSpellCitadel
End
