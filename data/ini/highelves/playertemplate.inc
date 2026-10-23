; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

PlayerTemplate HEFactionElves
	Side              		= Elves
	PlayableSide      		= Yes				; Please note: the presence of "SIDE:Elves" in the string file is what makes this appear in MP as a playable side.  And the skirmish scripts are what actually make it function.
	Evil			  	= No
	StartMoney        		= 0
	MaxLevelMP			= #DIVIDE( H_PLAYER_MAX_PURCHASE_POINTS_DEFAULT PLAYER_PURCHASE_POINTS_GRANTED )
	MaxLevelSP			= #DIVIDE( H_PLAYER_MAX_PURCHASE_POINTS_GOOD PLAYER_PURCHASE_POINTS_GRANTED )
	PreferredColor			= R:43 G:150 B:179
	StartingBuilding		= ElvenFortress
	
	;------------- NO STARTING UNITS FOR YOU -------
	;StartingUnit0 			= HEElvenLorienArcherHorde 
	;StartingUnitOffset0 		= X:-70 Y:220 Z:0
	
	StartingUnit1 			= HEElvenPorter 
	StartingUnitOffset1 		= X:30 Y:250 Z:0
	StartingUnit0 			= HEElvenPorter
	StartingUnitOffset0 		= X:1 Y:160 Z:0
	StartingUnit2		= CommandPointsThing ;,;
	StartingUnitOffset2 	= X:9999 Y:9999 Z:0 ;,;									
	StartingUnit3		= PlayerNumberDetector ;,;
	StartingUnitOffset3 	= X:19999 Y:-19999 Z:0 ;,;
	StartingUnit4		= LuaTicker ;,;
	StartingUnitOffset4 	= X:0 Y:0 Z:0
	StartingUnit5		= AIBonusesThing ;,;
	StartingUnitOffset5 	= X:0 Y:0 Z:0 ;,;
	
	StartingUnitTacticalWOTR	= HEElvenPorter
	StartingUnitTacticalWOTR	= HEElvenPorter
	StartingUnitTacticalWOTR	= WotR202PowerGranter ;;,;; Added for 2.3
	StartingUnitTacticalWOTR	= AIBonusesThing ;,;
	IntrinsicSciences		= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_ELVES
	SpellBook			= HEGoodSpellBook
	SpellBookMp			= HEElvesSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= HEElvesSpellStoreCommandSet
	DisplayName			= INI:FactionElves
	DefaultPlayerAIType		= ElvesSkirmishAI		; Needs to exist before I can change it.
	BeaconName			= MultiplayerBeacon
	LightPointsUpSound		= GondorLightPointsUp
	ObjectiveAddedSound		= Gui_MissionObjectiveNew
	ObjectiveCompletedSound		= Gui_MissionObjectiveCompleted
	InitialUpgrades			= Upgrade_ElfFaction		; Any upgrades this player template is born with.

	// NOTE: It is very important that the create-a-hero be the first buildable hero, to ensure that the create-a-hero and the ring hero are always 
	// attached to the first two buttons in the command set.

	BuildableHeroesMP		= CreateAHero HEElvenArwen HEElvenGlorfindel HEElvenHaldir MirkwoodTauriel HEElvenElrond HEElvenLegolas HEElvenThranduil ;,; reordered ;;,;; reordered
	BuildableRingHeroesMP		= ElvenGaladriel_RingHero
	SpellStoreCurrentPowerLabel 	= APT:SpellStoreCurrentEvenstarPower
	SpellStoreMaximumPowerLabel 	= APT:SpellStoreMaximumEvenstarPower
	ResourceModifierObjectFilter 	= RESOURCE_MODIFIER_OBJECT_FILTER
	ResourceModifierValues		= 100 100 100 100 95 90 90 85 85 79 75 73 71 68 66 ;,; 100 100 100 100 95 95 90 90 85 79 75 73 71 68 66 ;,; 100 100 100 100 90 85 80 75 71 68 66
	MultiSelectionPortrait		= UPElvenArmy
	LoadScreenMusic			= ElvesMusicForLoadScreen ;;,;; Shell2MusicForLoadScreen
End
