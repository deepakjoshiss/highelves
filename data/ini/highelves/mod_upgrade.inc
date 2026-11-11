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


; Hero rework (openbfme/HERO-REWORK-PLAN.md): the level upgrades above 2.02's ten (Upgrade_ObjectLevel1-10 are in upgrade.ini)
Upgrade Upgrade_ObjectLevel11
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel12
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel13
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel14
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel15
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel16
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel17
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel18
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel19
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel20
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel21
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel22
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel23
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel24
	Type			= OBJECT
End
Upgrade Upgrade_ObjectLevel25
	Type			= OBJECT
End

; ---- Hero Armory items (hero rework, openbfme/HERO-REWORK-PLAN.md): player upgrades bought on the hero's Armory page of the fortress
Upgrade Upgrade_HEThranduilArrowheads1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArrowheads1
	BuildCost		= H_THRANDUIL_ARROWHEADS1_COST
	BuildTime		= H_THRANDUIL_ARROWHEADS1_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilArmor1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArmor1
	BuildCost		= H_THRANDUIL_ARMOR1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilArmor2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArmor2
	BuildCost		= H_THRANDUIL_ARMOR2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilArmor3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArmor3
	BuildCost		= H_THRANDUIL_ARMOR3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilLife1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilLife1
	BuildCost		= H_THRANDUIL_LIFE1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilLife2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilLife2
	BuildCost		= H_THRANDUIL_LIFE2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilLife3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilLife3
	BuildCost		= H_THRANDUIL_LIFE3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilMobility1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilMobility1
	BuildCost		= H_THRANDUIL_MOBILITY1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilMobility2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilMobility2
	BuildCost		= H_THRANDUIL_MOBILITY2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilMobility3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilMobility3
	BuildCost		= H_THRANDUIL_MOBILITY3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilBow1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilBow1
	BuildCost		= H_THRANDUIL_BOW1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilBow2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilBow2
	BuildCost		= H_THRANDUIL_BOW2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilBow3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilBow3
	BuildCost		= H_THRANDUIL_BOW3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilArrowheads2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArrowheads2
	BuildCost		= H_THRANDUIL_ARROWHEADS2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilArrowheads3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilArrowheads3
	BuildCost		= H_THRANDUIL_ARROWHEADS3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilDamage1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilDamage1
	BuildCost		= H_THRANDUIL_DAMAGE1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilDamage2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilDamage2
	BuildCost		= H_THRANDUIL_DAMAGE2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilDamage3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilDamage3
	BuildCost		= H_THRANDUIL_DAMAGE3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilHunter1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilHunter1
	BuildCost		= H_THRANDUIL_HUNTER1_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilHunter2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilHunter2
	BuildCost		= H_THRANDUIL_HUNTER2_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEThranduilHunter3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEThranduilHunter3
	BuildCost		= H_THRANDUIL_HUNTER3_COST
	BuildTime		= H_THRANDUIL_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArmor1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArmor1
	BuildCost		= H_LEGOLAS_ARMOR1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArmor2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArmor2
	BuildCost		= H_LEGOLAS_ARMOR2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArmor3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArmor3
	BuildCost		= H_LEGOLAS_ARMOR3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasLife1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasLife1
	BuildCost		= H_LEGOLAS_LIFE1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasLife2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasLife2
	BuildCost		= H_LEGOLAS_LIFE2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasLife3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasLife3
	BuildCost		= H_LEGOLAS_LIFE3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasMobility1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasMobility1
	BuildCost		= H_LEGOLAS_MOBILITY1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasMobility2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasMobility2
	BuildCost		= H_LEGOLAS_MOBILITY2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasMobility3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasMobility3
	BuildCost		= H_LEGOLAS_MOBILITY3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasBow1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasBow1
	BuildCost		= H_LEGOLAS_BOW1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasBow2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasBow2
	BuildCost		= H_LEGOLAS_BOW2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasBow3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasBow3
	BuildCost		= H_LEGOLAS_BOW3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArrowheads1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArrowheads1
	BuildCost		= H_LEGOLAS_ARROWHEADS1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArrowheads2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArrowheads2
	BuildCost		= H_LEGOLAS_ARROWHEADS2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasArrowheads3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasArrowheads3
	BuildCost		= H_LEGOLAS_ARROWHEADS3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHawk1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHawk1
	BuildCost		= H_LEGOLAS_HAWK1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHawk2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHawk2
	BuildCost		= H_LEGOLAS_HAWK2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHawk3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHawk3
	BuildCost		= H_LEGOLAS_HAWK3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHeartseeker1
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHeartseeker1
	BuildCost		= H_LEGOLAS_HEARTSEEKER1_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHeartseeker2
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHeartseeker2
	BuildCost		= H_LEGOLAS_HEARTSEEKER2_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HELegolasHeartseeker3
	Type			= PLAYER
	DisplayName		= UPGRADE:HELegolasHeartseeker3
	BuildCost		= H_LEGOLAS_HEARTSEEKER3_COST
	BuildTime		= H_LEGOLAS_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondArmor1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondArmor1
	BuildCost		= H_ELROND_ARMOR1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondArmor2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondArmor2
	BuildCost		= H_ELROND_ARMOR2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondArmor3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondArmor3
	BuildCost		= H_ELROND_ARMOR3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondLife1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondLife1
	BuildCost		= H_ELROND_LIFE1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondLife2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondLife2
	BuildCost		= H_ELROND_LIFE2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondLife3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondLife3
	BuildCost		= H_ELROND_LIFE3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondVilya1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondVilya1
	BuildCost		= H_ELROND_VILYA1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondVilya2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondVilya2
	BuildCost		= H_ELROND_VILYA2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondVilya3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondVilya3
	BuildCost		= H_ELROND_VILYA3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondHerald1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondHerald1
	BuildCost		= H_ELROND_HERALD1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondHerald2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondHerald2
	BuildCost		= H_ELROND_HERALD2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondHerald3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondHerald3
	BuildCost		= H_ELROND_HERALD3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWisdom1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWisdom1
	BuildCost		= H_ELROND_WISDOM1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWisdom2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWisdom2
	BuildCost		= H_ELROND_WISDOM2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWisdom3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWisdom3
	BuildCost		= H_ELROND_WISDOM3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondStones1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondStones1
	BuildCost		= H_ELROND_STONES1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondStones2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondStones2
	BuildCost		= H_ELROND_STONES2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondStones3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondStones3
	BuildCost		= H_ELROND_STONES3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWrath1
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWrath1
	BuildCost		= H_ELROND_WRATH1_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWrath2
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWrath2
	BuildCost		= H_ELROND_WRATH2_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
Upgrade Upgrade_HEElrondWrath3
	Type			= PLAYER
	DisplayName		= UPGRADE:HEElrondWrath3
	BuildCost		= H_ELROND_WRATH3_COST
	BuildTime		= H_ELROND_ITEM_TIME
	ResearchSound	= UpgradeSilverThornArrows
End
