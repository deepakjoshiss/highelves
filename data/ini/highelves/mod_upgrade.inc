; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

Upgrade Upgrade_New0
  Type               = OBJECT
End

Upgrade Upgrade_New1
  Type               = OBJECT
End

Upgrade Upgrade_New2
  Type               = OBJECT
End

Upgrade Upgrade_New3
  Type               = OBJECT
End

Upgrade Upgrade_New4
  Type               = OBJECT
End

Upgrade Upgrade_New5
  Type               = OBJECT
End

Upgrade Upgrade_ObjectUnderHumanControl ;;,;; Sûlherokhh's method of designating an object as being under the AI's control.  One upgrade is simpler than eight.
  Type				= OBJECT
End

Upgrade Upgrade_MallornTreeBloom
  Type            		= OBJECT
	BuildCost           = H_ELVEN_MALLORN_TREE_BLOOM_COST
	BuildTime           = H_ELVEN_MALLORN_TREE_BLOOM_TIME
	DisplayName         = UPGRADE:MallornTreeBloom
	ResearchSound				= UpgradeSilverThornArrows

End

Upgrade Upgrade_NimrodelWaters
	Type			= OBJECT
	BuildCost		= H_ELVEN_NIMRODEL_WATERS_COST
	BuildTime		= H_ELVEN_MALLORN_TREE_BLOOM_TIME
	DisplayName		= UPGRADE:NimrodelWaters
	Tooltip		    = UPGRADE:ToolTipNimrodelWaters
	ResearchCompleteEvaEvent	= MallornTreeWaters
End

Upgrade Upgrade_PurifyingFlames
  Type            		= OBJECT
	BuildCost           = H_ELVEN_MALLORN_TREE_BLOOM_COST
	BuildTime           = H_ELVEN_MALLORN_TREE_BLOOM_TIME
	DisplayName         = UPGRADE:PurifyingFlames
	Tooltip		    			= UPGRADE:ToolTipPurifyingFlames
	ResearchSound				= UpgradeSilverThornArrows
End

; ---- PROTOTYPE: Hero Armory pages on the fortress (HEElvenCitadel). Each page is a player upgrade: a CommandSetUpgrade shows the page while
; it is held; Back removes it (RemoveUpgradeUpgrade). Granted instantly by special powers (PlayerUpgradeSpecialPower), no production queue.
Upgrade Upgrade_HEArmoryPage
  Type = PLAYER
End
Upgrade Upgrade_HEArmoryLegolas
  Type = PLAYER
End
Upgrade Upgrade_HEArmoryThranduil
  Type = PLAYER
End
Upgrade Upgrade_HEArmoryElrond
  Type = PLAYER
End
Upgrade Upgrade_HEArmoryBackHero
  Type = PLAYER
End
Upgrade Upgrade_HEArmoryBack
  Type = PLAYER
End
