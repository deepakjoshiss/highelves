//------------------------------------------------------------------------------
// Upgrade definitions
//------------------------------------------------------------------------------

;;===========================<D.J.>=======================

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

Upgrade Upgrade_MallornTreeBloom
  Type            		= OBJECT
	BuildCost           = H_ELVEN_NIMRODEL_WATERS_COST
	BuildTime           = H_ELVEN_MALLORN_TREE_BLOOM_TIME
	DisplayName         = UPGRADE:MallornTreeBloom
	ResearchSound				= UpgradeSilverThornArrows
	;,; SkirmishAIHeuristic = AI_UPGRADEHEURISTIC_IMPORTANT
End

Upgrade Upgrade_NimrodelWaters
	Type			= OBJECT
	BuildCost		= H_ELVEN_MALLORN_TREE_BLOOM_COST
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