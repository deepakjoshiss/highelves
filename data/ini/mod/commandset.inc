; //------------------------------------------------------------------------------
; // mod/commandSet.inc
; //
; // See what was for Generals below.  For LotR things have changed since we no longer have
; // the same UI.
; // If the Command in CommandButton.ini has a field Radial=Yes, then that command
; // will show up in a radial menu above the object in the game world.
; //
; // If a command button has InPalantir=Yes then it will be displayed in the
; // palantir when it's in a command set for the selected object.
; //
; // Locations for the Skill button in clockwise fashion.  The top right button
; // being button 1. 

; // If these actions are not taken, the commands will only show
; // up if you pass in -OldGui to the game (but they are not usable right now)
; // ------------------------------------------------------------------------------
; //Command sets are groups of command buttons that will be displayed in the
; //context sensitive user interface for a selected object showing what you
; //can do with that object
; //
; //LHS numbers are the physical GUI buttons.  You can assign a command
; //to any of the physical buttons, they do *NOT* need to appear in
; //continuous order ... you may have gaps if you desire
; //
; //RHS strings are CommandButton.ini command names
; //
; //Buttons for a regular command context are ordered as:
; //                    +--+
; //+--+--+--+--+--+--+ |13|
; //|01|03|05|07|09|11| +--+
; //+--+--+--+--+--+--+ |14|    <-- Smaller buttons 3 fit within 11 & 12 in height.
; //|02|04|06|08|10|12| +--+
; //+--+--+--+--+--+--+ |15|
; //                    +--+
; //------------------------------------------------------------------------------


CommandSet ElvenSuperTowerCommandSet
	1 = Command_PurchaseUpgradeElvenSilverthornTowerArrows
	2 = Command_ExitGarrison
	3 = Command_ExitGarrison
	4 = Command_ExitGarrison
	6 = Command_Sell
End

CommandSet MirkwoodTaurielCommandSet
	1	= Command_ToggleStance
	2   = Command_SpecialAbilityTaurielLeadership
	3	= Command_SpecialAbilityExplodingArrow
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

CommandSet GaladhrimWarriorHordeCommandSet
	1 	= Command_ToggleStance
	2 	= Command_ToggleRohanElvenWarriorWeapon ;,; Command_ToggleElvenWarriorWeapon
	3 	= Command_PurchaseUpgradeElvenForgedBladesTier2 ;,; Command_PurchaseUpgradeGondorFireArrows ;,; Command_PurchaseUpgradeRohanForgedBladesForElves
	4 	= Command_PurchaseUpgradeElvenHeavyArmor  ;,; Command_PurchaseUpgradeGondorForgedBlades ;,; Command_PurchaseUpgradeRohanHeavyArmorForElves
	5 	= Command_PurchaseUpgradeElvenSilverthornArrows  ;,; Command_PurchaseUpgradeGondorHeavyArmor ;,; Command_PurchaseUpgradeRohanFireArrows
	6 	= Command_PurchaseUpgradeElvenBasicTrainingTier3 ;,; Command_PurchaseUpgradeRohanBasicTraining ;,; Command_PurchaseUpgradeGondorBasicTraining ;,; Command_PurchaseUpgradeRohanBasicTraining
	12	= Command_CaptureBuilding ;,;
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

CommandSet ElvenMellornTreeCommandSet
	1 = Command_PurchaseNimrodelWaters
	2 = Command_PurchaseUpgradeBloom
	6 = Command_Sell
End

CommandSet TreeFletCommandSet
  1 = Command_ExitGarrison
	2 = Command_PurchaseNimrodelWaters
	3 = Command_PurchaseUpgradePurifyngFlames
	4 = Command_PurchaseUpgradeElvenFortressBlessedMist
	5 = Command_PurchaseUpgradeElvenSilverthornTowerArrows
	6 = Command_Sell
End

CommandSet ElvenWaystoneCommandSet
	1 = Command_SpecialAbilityWaystoneTeleport
	6 = Command_Sell
End
