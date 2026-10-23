; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

FXList FX_SpellLightOfTrees
  BuffNugget
	BuffType = Dominate
	BuffThingTemplate = SpellLightOfTreesBonus
	BuffInfantryTemplate = SpellLightOfTreesBonus
	BuffCavalryTemplate = SpellLightOfTreesBonus
	BuffTrollTemplate = SpellLightOfTreesBonus
  BuffOrcTemplate = SpellLightOfTreesBonus
	BuffShipTemplate = SpellLightOfTreesBonus
	BuffMonsterTemplate = SpellLightOfTreesBonus
	BuffMumakilTemplate = SpellLightOfTreesBonus
	IsComplexBuff = No
	BuffLifeTime = 3000
  End
End

FXList FX_EnvillightBonus
  ParticleSystem
    Name = Envillight
    AttachToObject = Yes
  End
End

FXList FX_VineslightBonus
  ParticleSystem
    Name = Vineslight
    AttachToObject = Yes
  End
End

FXList FX_TaurielBonus
  ParticleSystem
    Name = MirkwoodLight
    AttachToObject = Yes
  End
End

FXList FX_RamaBowHit
	ParticleSystem
		Name = SplashWaterHit
	End
End

FXList FX_TaurielInitialSpawn
  Sound
	Name = GenericRespawn1
  End
  Sound
	Name = TaurielVoiceSalute
  End
  ParticleSystem
    Name = ResurrectionCenter
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionLightShaft
    Offset = X:0.0 Y:0.0 Z:0.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionVortex
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionWave
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
End

FXList FX_TaurielRespawn
  Sound
	Name = GenericRespawn1
  End
  Sound
	Name = TaurielVoiceRespawn
  End
  ParticleSystem
    Name = ResurrectionCenter
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionLightShaft
    Offset = X:0.0 Y:0.0 Z:0.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionVortex
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = ResurrectionWave
    Offset = X:0.0 Y:0.0 Z:5.0
    OrientToObject = Yes
  End
End

FXList FX_TaurielDieToRespawn
  ParticleSystem
    Name = GandalfSwordHitSpark
    Offset = X:12.0 Y:0.0 Z:8.0
    OrientToObject = Yes
  End
  ParticleSystem
    Name = GandalfSwordHitFlash
    Offset = X:12.0 Y:0.0 Z:8.0
    OrientToObject = Yes
  End
; ----------------------------------------------
	; EvaEventOwner = TaurielVoiceDie
	; EvaEventAlly = None
  ; End
End

FXList FX_BloodDamageHit
  ; ParticleSystem
    ; Name = MidgeDamageFX
  ; End
  ParticleSystem
    Name = BloodSpurtFX
    Offset = X:0.0 Y:0.0 Z:8.0
    OrientToObject = Yes
  End
End

FXList FX_TaurielCloseQuarters
  TintDrawable
	Color				= R:126 G:120 B:94
	PreColorTime		= 100
	PostColorTime		= 100
	SustainedColorTime	= 700
	Frequency			= 0
	Amplitude			= 0
  End
  Sound
	Name = TaurielKnifeModeMS
  End
End

FXList FX_ExpodingArrowExplosion
	ParticleSystem
		Name = FirebombHit
	End
	ParticleSystem
		Name = FirebombFlash
	End
	
	
	ParticleSystem
		Name = ExplodingArrowExplosion
	End


	ParticleSystem
		Name = ExplodingArrowExplosionGlow
	End

  Sound
	  Name = ImpactCorsairFireBomb
  End

	TerrainScorch
		Type		= RANDOM
		Weather		= NORMAL
		RandomRange = X:0 Y:3
		Radius		= 8
	End

	TerrainScorch
		Type		= RANDOM
		Weather		= SNOWY
		RandomRange = X:4 Y:6
		Radius		= 8
	End
 
End

FXList FX_LorienStunEffect
  BuffNugget
	BuffType = Cursed
	BuffThingTemplate = LorienStunBuff
	BuffInfantryTemplate = LorienStunBuff
	BuffCavalryTemplate = LorienStunBuff
	BuffTrollTemplate = LorienStunBuff
    BuffOrcTemplate = LorienStunBuff
	IsComplexBuff = No
	BuffLifeTime = 5500
  End
End
