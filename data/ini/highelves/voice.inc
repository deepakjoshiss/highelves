; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

; the macros of this file's own blocks (an audio file loads without the main load's macros)
#define M_TAURIEL_RESPONSE_VOLUME	95 ;170 
#define M_TAURIEL_RESPONSE_MINVOLUME 90  ;165 

AudioEvent TaurielVoiceAttack
  Sounds = tauriel_atk1 tauriel_atk2 tauriel_atk3 tauriel_atk4 tauriel_atk5 tauriel_atk6
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceAttackBuilding
  Sounds = tauriel_atks1 tauriel_atks2 tauriel_atks3 tauriel_atks4
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceAttackCharge
  Sounds = tauriel_charge1 tauriel_charge2 tauriel_charge3
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceDie
  Sounds = tauriel_death1 tauriel_death2 tauriel_death3 tauriel_death4 tauriel_death5
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinRange = 500
  MaxRange = 1000
  Limit = 3
  Type = world shrouded everyone voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceDisengage
  Sounds = tauriel_diseng1 tauriel_diseng2 tauriel_diseng3 tauriel_diseng4 
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceHelpMe
  Sounds = tauriel_help1 tauriel_help2
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Priority = critical
  Type = world shrouded player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceMove
  Sounds = tauriel_move1 tauriel_move2 tauriel_move3 tauriel_move4 tauriel_move5 tauriel_move6
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceMoveCamp
  Sounds = tauriel_movecamp1 tauriel_movecamp2 tauriel_movecamp3 tauriel_movecamp4
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceRespawn
  Sounds = tauriel_revive1
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceRetreat
  Sounds = tauriel_diseng1 tauriel_diseng2 tauriel_diseng3 tauriel_diseng4
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceSalute
  Sounds = tauriel_salute1 tauriel_salute2
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceSelect
  Sounds = tauriel_select1 tauriel_select2 tauriel_select3 tauriel_select4 tauriel_select5 tauriel_select6
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceSelectBattle
  Sounds = tauriel_combat1 tauriel_combat2 tauriel_combat3 tauriel_combat4
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent TaurielVoiceEyesandEars
  Sounds = tauriel_eyesandears1 tauriel_eyesandears2
  Priority = high
  Volume = M_TAURIEL_RESPONSE_VOLUME
  MinVolume = M_TAURIEL_RESPONSE_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

Multisound TaurielVoiceSelectMS
	Subsounds = TaurielVoiceSelect HeroVoiceSelect2
End

AudioEvent CampMirkwoodTaurielKilled
  Sounds = wreva_herodietauriel1 wreva_herodietauriel2
  Volume      = CAMP_ELF_VOLUME
  MinVolume   = CAMP_ELF_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End

AudioEvent CampLorienElfNewMallornUpgradeSecondaryWaters
  Sounds = lorevanew_malupsecwaters1 lorevanew_malupsecwaters2
  Volume      = CAMP_ELF_VOLUME
  MinVolume   = CAMP_ELF_MINVOLUME
  Type = world player voice
  SubmixSlider = voice
End
