; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

 NewEvaEvent MirkwoodTaurielDie
  Priority = 7
  TimeBetweenEventsMS = 30000
  ExpirationTimeMS  = 5000
  SideSound
    Side = Elves
    Sound = CampMirkwoodTaurielKilled
  End
End

NewEvaEvent MallornTreeWaters
  Priority             = EVA_UPGRADE_COMPLETE_PRIORITY
  TimeBetweenEventsMS  = EVA_UPGRADE_COMPLETE_TIME_BETWEEN_EVENTS
  ExpirationTimeMS     = EVA_UPGRADE_COMPLETE_EXPIRATION_TIME
  SideSound
    Side = Elves
    Sound = CampLorienElfNewMallornUpgradeSecondaryWaters
  End
End
