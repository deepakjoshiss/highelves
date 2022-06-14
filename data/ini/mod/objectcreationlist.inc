;//////////////////////////////////////////////////////////////////////////////
;FILE: mod/objectcreationlist.inc (SYSTEM) ////////////////////////////////////////
;//////////////////////////////////////////////////////////////////////////////

;======================<D.J.>=========================
ObjectCreationList OCL_LightOfTreesWeatherChanger ;;,;; added
	CreateObject
		ObjectNames = LightOfTreesWeatherChanger
	End
End

;-------------------------------------------------------------
ObjectCreationList OCL_LightOfTreesCaster ;;,;; added for 2.02e
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