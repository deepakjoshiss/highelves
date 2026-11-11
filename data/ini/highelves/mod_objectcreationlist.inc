; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

ObjectCreationList OCL_LightOfTreesWeatherChanger ;;,;; added
	CreateObject
		ObjectNames = LightOfTreesWeatherChanger
	End
End

ObjectCreationList OCL_LightOfTreesCaster
	CreateObject
		ObjectNames = LightOfTreesCaster
	End
End

ObjectCreationList OCL_SpellBookSpawnTreeFlet
	CreateObject
		ObjectNames			  = TreeFlet
		Count				      = 1
		FadeIn			      = Yes
		FadeTime		      = 2000
		ClearRemovables		= Yes
		UseJustBuiltFlag	= Yes							; turn on the JUST_BUILT model condition.
		JustBuiltDuration	= 1500
	End
End

ObjectCreationList OCL_SpellBookElvenWaystone
	CreateObject
		ObjectNames				= ElvenWaystone
		Disposition 			= ABSOLUTE_ANGLE
		DispositionAngle	= 315
		FadeIn						= Yes
		ClearRemovables		= Yes
		UseJustBuiltFlag	= Yes
		JustBuiltDuration	= 4000
	End
End

; Thranduil's Call of the Woodland Realm (hero rework, openbfme/HERO-REWORK-PLAN.md): Mirkwood archers for 40 s where he stands
ObjectCreationList OCL_HEThranduilWoodlandRealm5
	CreateObject
		ObjectNames				= HEThranduilSummonedArcherHorde5
		IgnoreCommandPointLimit	= Yes
		Disposition				= LIKE_EXISTING
	End
End

ObjectCreationList OCL_HEThranduilWoodlandRealm10
	CreateObject
		ObjectNames				= HEThranduilSummonedArcherHorde10
		IgnoreCommandPointLimit	= Yes
		Disposition				= LIKE_EXISTING
	End
End

; Elrond's Flood of the Bruinen (hero rework): the flood at his position, turned as he faces
ObjectCreationList OCL_HEElrondFlood
	CreateObject
		ObjectNames			= HEElrondFlood
		Disposition			= RELATIVE_ANGLE
		DispositionAngle	= 0
	End
End
