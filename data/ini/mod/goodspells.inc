

;--------------------------Light of the Trees------------------------------------
  Behavior = OCLSpecialPower ModuleTag_LightOfTrees ;,; 
    SpecialPowerTemplate            = SpellBookLightOfTrees
  	OCL                             = OCL_LightOfTreesWeatherChanger
  	CreateLocation       			= CREATE_AT_LOCATION  
    AttributeModifierWeatherBased   = Yes
    WeatherDuration            		= H_SPELL_LIGHT_OF_TREES_DURATION
    ChangeWeather            		= SUNNY
    AvailableAtStart     			= No
    RequirementsFilterMPSkirmish 	= SPELL_BOOK_REQUIREMENTS_FILTER
    RequirementsFilterStrategic 	= SPELL_BOOK_REQUIREMENTS_FILTER_STRATEGIC
  End

  Behavior = CloudBreakSpecialPower  ModuleTag_LightTreesRays ;,;
    SpecialPowerTemplate             = SpellBookLightOfTrees_Rays
    SunbeamObject                    = LightOfTreesSunbeam
    ObjectSpacing                    = 500
    WeatherDuration                  = H_SPELL_LIGHT_OF_TREES_DURATION           
    AvailableAtStart                 = No
    RequirementsFilterMPSkirmish 	 = SPELL_BOOK_REQUIREMENTS_FILTER
    RequirementsFilterStrategic 	 = SPELL_BOOK_REQUIREMENTS_FILTER_STRATEGIC
  End

	Behavior = OCLSpecialPower ModuleTag_SpawnTreeFlet
		SpecialPowerTemplate 		        = SpellBookSpawnTreeFlet
		OCL                  		        = OCL_SpellBookSpawnTreeFlet
		CreateLocation       		        = CREATE_AT_LOCATION
		AvailableAtStart	 			        = Yes
		RequirementsFilterMPSkirmish 		= SPELL_BOOK_REQUIREMENTS_FILTER
		RequirementsFilterStrategic 		= SPELL_BOOK_REQUIREMENTS_FILTER_STRATEGIC
	End	

  Behavior = OCLSpecialPower ModuleTag_ElvenWaystone
		SpecialPowerTemplate 		        = SpellBookElvenWaystone
		OCL                  		        = OCL_SpellBookElvenWaystone
		CreateLocation       		        = CREATE_AT_LOCATION
		AvailableAtStart	 			        = Yes
		RequirementsFilterMPSkirmish 		= SPELL_BOOK_REQUIREMENTS_FILTER
		RequirementsFilterStrategic 		= SPELL_BOOK_REQUIREMENTS_FILTER_STRATEGIC
	End	