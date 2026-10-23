; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

AudioEvent SpellSpawnTreeFlet
  Sounds = SPtreeflet
  Volume = 120
  MinRange = 300
  MaxRange = 1000
  ; PitchShift = 0 2
  Priority = critical
  Limit = 2
  Type = world shrouded everyone 
  SubmixSlider = SoundFX
End

AudioEvent TreeFletSelect
  Sounds = SPtreeflet_select
  Volume = 120
  MinVolume = 85
  Limit = 1
  MinRange = 400
  Type = world player
  SubmixSlider = SoundFX
End

AudioEvent SpellSpawnWaystone
  Sounds = SPwaystone
  Volume = 120
  MinRange = 300
  MaxRange = 1000
  ; PitchShift = 0 2
  Priority = critical
  Limit = 2
  Type = world shrouded everyone 
  SubmixSlider = SoundFX
End

AudioEvent WaystoneSelect
  Sounds = SPwaystone_select
  Volume = 120
  Limit = 1
  MinRange = 400
  Type = world player
  SubmixSlider = SoundFX
End

AudioEvent WaystonePurify
  Sounds      = SPheal
  Limit	      = 1
  Volume      = 120
  MinRange    = 400
  Type        = world shrouded everyone
  SubmixSlider = SoundFX
End

AudioEvent SpellMirkwoodTrap
  Sounds      = gsmirkwood_trap
  Limit	      = 2
  Volume      = 120
  MinRange    = 400
  MaxRange    = 800
  Type        = world everyone 
  SubmixSlider = SoundFX
End

AudioEvent SpellGoodLightOFTrees
  Sounds = SPlightof_trees
  Volume = 120

;,; ------------------------

  Priority = critical
  Limit = 1
  Type = ui everyone
  SubmixSlider = SoundFX
End

AudioEvent TaurielSwitchToSword
  Sounds = USwitchSworda
  Delay = 500 500
  Volume = 90
  VolumeShift = -10
  Type = world shrouded everyone
  SubmixSlider = SoundFX
End

AudioEvent TaurielKnifeMode
  Sounds = gSpTauriel_CloseQuarters
  Limit = 1
  Volume = 140
  MinRange = 250
  MaxRange = 800
  Type = world shrouded everyone
  SubmixSlider = SoundFX
End

Multisound TaurielKnifeModeMS
	Subsounds = TaurielKnifeMode TaurielSwitchToSword
End

AudioEvent TaurielFleetfooted
  Sounds = gSpTauriel_Fleetfooted
  Limit = 1
  Volume = 150
  MinRange = 250
  MaxRange = 800
  Type = world shrouded everyone
  SubmixSlider = SoundFX
End
