; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

FXParticleSystem HEEnshroudingMist
  System
    Priority = VERY_LOW_OR_ABOVE
    Shader = ALPHA
    ParticleName = EXsmokeplume.tga
    Lifetime = 100 100
    SortLevel = 1
    Size = 15 15
    StartSizeRate = 1 1
    BurstCount = 0 3 ;,; 0 2
    IsGroundAligned = Yes
  End
  Color = DefaultColor
    Color1 = R:232 G:247 B:253 0
    Color2 = R:236 G:247 B:253 0
    Color3 = R:235 G:247 B:254 100
    ColorScale = -30 20
  End
  Alpha = DefaultAlpha
    Alpha2 = 0.1 0.15 50
    Alpha3 = 0 0 100
  End
  Update = DefaultUpdate
    SizeRate = 0.5 0.5
    SizeRateDamping = 1.01 1.01
    AngleZ = 0 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1.03 1.03
  End
  EmissionVelocity = OrthoEmissionVelocity
    X = -0.1 0.1
    Y = -0.1 0.1
  End
  EmissionVolume = CylinderEmissionVolume
    IsHollow = Yes ;,; No ;,; Yes
    Radius = 200
    Length = 6
    Offset = X:0 Y:0 Z:30
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem HENoldorSilverArrowTrail ;,;
  System
    Priority = VERY_LOW_OR_ABOVE
    ParticleName = EXSplatHaze.tga
    Lifetime = 30 30
    SortLevel = 1
    Size = 0 15
    BurstCount = 1 3
    IsParticleUpTowardsEmitter = Yes
  End
    Color = DefaultColor
      Color2 = R:100 G:100 B:125 5
      Color3 = R:0 G:0 B:0 15
	  Color4 = R:32 G:32 B:32 0
  End
  Update = DefaultUpdate
    SizeRate = -0.25 -0.2
    SizeRateDamping = 1 1
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = -0.01
    VelocityDamping = 1 1
    DriftVelocity = X:0 Y:0 Z:-0.1
  End
  EmissionVelocity = OrthoEmissionVelocity
    Z = 0 -0.1
  End
  EmissionVolume = SphereEmissionVolume
    Radius = 10
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem Envillight ;;,;;
  System
    Priority = VERY_LOW_OR_ABOVE
    Type = GPU_PARTICLE
    ParticleName = EXSparkle.tga
    Lifetime = 30 30 ; 25 25
	SystemLifetime = 60 ;
    SortLevel = 1
    Size = 5 5 ;1 1 ;2 2 ;3 3 ;5 5
    BurstDelay = 10 15
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color2 = R:230 G:232 B:250 5
    Color3 = R:0 G:0 B:0 25
  End
  Update = DefaultUpdate
    SizeRate = 0.1 0.1 ;0.5 0.5
    SizeRateDamping = 1 1
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
;,;=========DO NOT ADD ANYTHING BELOW OR DIRECTLY ABOVE THIS LINE======;,;
;,;PICK A RANDOM APPROPRIATE SPOT SOMEWHERE IN THE MIDDLE OF THE FILE ;,;

  EmissionVolume = CylinderEmissionVolume
    Radius = 10
    Length = 15
    Offset = X:0 Y:0 Z:15
  End
  Draw = GpuDraw
    FramesPerRow = 1
    TotalFrames = 1
    SpeedMultiplier = 1
  End
End

FXParticleSystem Vineslight ;;,;;
  System
    Priority = VERY_LOW_OR_ABOVE
    Type = GPU_PARTICLE
    ParticleName = EXSparkle.tga
    Lifetime = 30 30 ; 25 25
	SystemLifetime = 60 ;
    SortLevel = 1
    Size = 5 5 ;1 1 ;2 2 ;3 3 ;5 5
    BurstDelay = 10 15
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color2 = R:10 G:232 B:10 5
    Color3 = R:0 G:0 B:0 25
  End
  Update = DefaultUpdate
    SizeRate = 0.1 0.1 ;0.5 0.5
    SizeRateDamping = 1 1
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
;  EmissionVolume = BoxEmissionVolume
;    HalfSize = X:10 Y:10 Z:1
;  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 10
    Length = 15
    Offset = X:0 Y:0 Z:15
  End
  Draw = GpuDraw
    FramesPerRow = 1
    TotalFrames = 1
    SpeedMultiplier = 1
  End
End

FXParticleSystem MirkwoodLight ;;,;;
  System
    Priority = VERY_LOW_OR_ABOVE
    Type = GPU_PARTICLE
    ParticleName = EXSparkle.tga
    Lifetime = 30 30 ; 25 25
	SystemLifetime = 60 ;
    SortLevel = 1
    Size = 5 5 ;1 1 ;2 2 ;3 3 ;5 5
    BurstDelay = 10 15
    BurstCount = 1 1
  End
  Color = DefaultColor ; fades in, holds, fades out over the 30-frame life (2026-10-30; was black to red at 15, then black at once)
    Color1 = R:0 G:0 B:0 0
    Color2 = R:196 G:38 B:21 8
    Color3 = R:196 G:38 B:21 22
    Color4 = R:0 G:0 B:0 30
  End
  Update = DefaultUpdate
    SizeRate = 0.1 0.1 ;0.5 0.5
    SizeRateDamping = 1 1
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
;  EmissionVolume = BoxEmissionVolume
;    HalfSize = X:10 Y:10 Z:1
;  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 10
    Length = 15
    Offset = X:0 Y:0 Z:15
  End
  Draw = GpuDraw
    FramesPerRow = 1
    TotalFrames = 1
    SpeedMultiplier = 1
  End
End

FXParticleSystem SplashWaterHit
  System
    Priority = MEDIUM_OR_ABOVE
    Shader = ALPHA
    ParticleName = EXWater04.tga
    Lifetime = 30 30
    SystemLifetime = 1
    SortLevel = 1
    BurstCount = 2 2
  End
  Color = DefaultColor
    Color1 = R:238 G:183 B:79 0
    ColorScale = -20 20
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.2 0.6 0
    Alpha2 = 0 0 50
  End
  Update = DefaultUpdate
    SizeRate = 5 8
    SizeRateDamping = 0.8 0.85
    AngleZ = 0 7
    AngularDamping = 0.95 0.99
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = -0.5
    VelocityDamping = 0.9 0.95
  End
  EmissionVelocity = OrthoEmissionVelocity
    X = -1 1
    Y = -1 1
    Z = 3 7
  End
  EmissionVolume = LineEmissionVolume
    StartPoint = X:0 Y:0 Z:10
    EndPoint = X:0 Y:0 Z:10
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem ExplodingArrowExplosion
  System
    Priority = VERY_LOW_OR_ABOVE
    IsOneShot = Yes
    Shader = ALPHA
    ParticleName = EXfireballF.tga
    Lifetime = 80 80
    SystemLifetime = 2
    Size = 6 9
    StartSizeRate = 0.1 0.1
    BurstCount = 2 2
  End
  Color = DefaultColor
    Color1 = R:255 G:255 B:255 0
    Color2 = R:255 G:255 B:255 10
    Color3 = R:255 G:255 B:255 15
    Color4 = R:0 G:0 B:0 55
    Color5 = R:0 G:0 B:0 60
  End
  Alpha = DefaultAlpha
    Alpha2 = 0.4 0.6 5
    Alpha3 = 0.1 0.3 40
    Alpha4 = 0 0 80
  End
  Update = DefaultUpdate
    SizeRate = 10 12
    SizeRateDamping = 0.8 0.8
    AngleZ = -3 1.5
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = 0.1
    VelocityDamping = 0.75 0.75
  End
  EmissionVelocity = OrthoEmissionVelocity
    Z = 0 5
  End
  EmissionVolume = CylinderEmissionVolume
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem ExplodingArrowExplosionGlow
  System
    Priority = VERY_LOW_OR_ABOVE
    IsOneShot = Yes
    ParticleName = EXexplo03.tga
    Lifetime = 50 50
    SystemLifetime = 2
    Size = 6 9
    StartSizeRate = 0.1 0.1
    BurstCount = 2 2
  End
  Color = DefaultColor
    Color1 = R:215 G:211 B:204 0
    Color2 = R:143 G:134 B:112 20
    Color3 = R:0 G:0 B:0 30
  End
  Alpha = DefaultAlpha
    Alpha2 = 0.75 1 5
    Alpha3 = -0.5 0 10
  End
  Update = DefaultUpdate
    SizeRate = 10 11
    SizeRateDamping = 0.8 0.8
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = 0.1
    VelocityDamping = 0.75 0.75
  End
  EmissionVelocity = OrthoEmissionVelocity
    Z = 0 5
  End
  EmissionVolume = CylinderEmissionVolume
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem BloodSpurtFX
  System
    Priority = VERY_LOW_OR_ABOVE
    ParticleName = exmultidot.tga
    Lifetime = 8 8
    SystemLifetime = 15
    Size = 1 18
    BurstCount = 1 3
  End
  Color = DefaultColor
    Color1 = R:255 G:18 B:0 0
    Color2 = R:0 G:0 B:0 7
  End
  Update = DefaultUpdate
    SizeRate = 1 3
    SizeRateDamping = 0.8 0.85
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = -0.4
    VelocityDamping = 0.8 0.85
  End
  EmissionVelocity = OrthoEmissionVelocity
    X = 0 2
    Y = 0 1
    Z = 0 4
  End
  EmissionVolume = LineEmissionVolume
    IsHollow = Yes
    StartPoint = X:-1 Y:0 Z:0
    EndPoint = X:6 Y:0 Z:0
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem BloodHitSpark
  System
    Priority = VERY_LOW_OR_ABOVE
    ParticleName = EXSpark03.tga
    Lifetime = 8 8
    SystemLifetime = 2
    Size = 1 5
    BurstCount = 6 6
  End
  Color = DefaultColor
    Color1 = R:255 G:18 B:0 0
    Color2 = R:0 G:0 B:0 7
  End
  Update = DefaultUpdate
    SizeRate = 1 3
    SizeRateDamping = 0.8 0.85
    AngleZ = -7 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = -0.4
    VelocityDamping = 0.8 0.85
  End
  EmissionVelocity = OrthoEmissionVelocity
    X = 0 2
    Y = 0 1
    Z = 0 4
  End
  EmissionVolume = LineEmissionVolume
    IsHollow = Yes
    StartPoint = X:-1 Y:0 Z:0
    EndPoint = X:3 Y:0 Z:0
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem RamaArrowTrail
  System
    Priority = ALWAYS_RENDER
    ParticleName = EXspearhead.tga
    Lifetime = 15 15
    SortLevel = 1
    Size = 3 3
    BurstCount = 4 4
    IsGroundAligned = Yes
    IsParticleUpTowardsEmitter = Yes
  End
  Color = DefaultColor
    Color1 = R:249 G:217 B:91 5
    Color2 = R:0 G:0 B:0 20
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.25 0.25 0
    Alpha2 = 0 0 15
  End
  Update = DefaultUpdate
    SizeRate = -0.20 -0.20
    SizeRateDamping = 1 1
    AngleZ = 0 2
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
  EmissionVolume = LineEmissionVolume
    StartPoint = X:-5 Y:0 Z:0
    EndPoint = X:-5 Y:0 Z:0
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem RamaBlessing
  System
    Priority = VERY_LOW_OR_ABOVE
    ParticleName = EXLnzFlar4.tga
    Lifetime = 32 32
    Size = 30 30
    BurstDelay = 4 4
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color2 = R:50 G:50 B:25 10
    Color3 = R:13 G:13 B:13 15
    Color4 = R:0 G:0 B:0 10
  End
  Alpha = DefaultAlpha
    Alpha1 = 0 0.5 16
    Alpha2 = 0.5 0 20
  End
  Update = DefaultUpdate
    SizeRate = 2 2
    SizeRateDamping = 0.9 0.9
    AngleZ = -1 1
    AngularRateZ = -0.02 0.02
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 0 8.07921e+33
    ParticlesAttachToBone = Yes
  End
  EmissionVelocity = OutwardEmissionVelocity
  End
  EmissionVolume = PointEmissionVolume
    IsHollow = Yes
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem MallornTreeBloomLeaves
  System
    Priority = VERY_LOW_OR_ABOVE
    Shader = ALPHA
    ParticleName = EXLeaf01.tga
    Lifetime = 100 200
  ;  SystemLifetime = 500
    Size = 2 5
    BurstDelay = 4 4
    BurstCount = 1 4
  End
  Color = DefaultColor
    Color1 = R:196 G:38 B:21 0
  End
  Alpha = DefaultAlpha
    Alpha2 = 1 1 25
    Alpha3 = -0.25 0 250
  End
  Update = DefaultUpdate
    SizeRateDamping = 0.5 0.55
    AngleZ = -7 7
    AngularRateZ = -0.01 0.01
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 0.99 0.99
    Gravity = -0.01
  End
  EmissionVelocity = CylindricalEmissionVelocity
    Radial = 0.5 0.5
  End
 ; EmissionVolume = LineEmissionVolume
 ;   StartPoint = X:0 Y:0 Z:85
 ;   EndPoint = X:0 Y:0 Z:55
 ; End
  EmissionVolume = CylinderEmissionVolume
    Radius = 50
    Length = 15
    Offset = X:0 Y:0 Z:90
  End
  Draw = DefaultDraw
  End
  Wind = DefaultWind
    WindMotion = Circular
    WindStrength = 0.15
    WindFullStrengthDist = 0
    WindAngleChangeMin = 1
    WindAngleChangeMax = 1.5
    WindPingPongStartAngleMax = 0.75
    WindPingPongEndAngleMin = 5.5
    WindPingPongEndAngleMax = 6
  End
End

FXParticleSystem SkilloftheElvesFX
  System
    Priority = ALWAYS_RENDER
    ParticleName = exminerlight.tga
    Lifetime = 15 15
    SortLevel = 1
    Size = 9 12
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color2 = R:43 G:61 B:78 5
    Color3 = R:0 G:0 B:0 15
    Color4 = R:32 G:32 B:32 0
  End
  Update = DefaultUpdate
    SizeRate = 1 1
    SizeRateDamping = 1 1
    AngleZ = 0 7
    AngularRateZ = -0.1 0.1
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = -0.01
    VelocityDamping = 1 1
  End
  EmissionVelocity = OutwardEmissionVelocity
  End
  EmissionVolume = SphereEmissionVolume
    Radius = 10
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem SkilloftheElvesStartFX
  System
    Priority = ALWAYS_RENDER
    ParticleName = exblast.tga
    Lifetime = 40 40
    SystemLifetime = 10
    ; Size = 1 1
    SortLevel = 1
    BurstCount = 1 1
    IsGroundAligned = Yes
	 InitialDelay = 10 10
  End
  
  Color = DefaultColor
    Color2 = R:56 G:74 B:91 20
    Color3 = R:0 G:0 B:0 40
  End
  Alpha = DefaultAlpha
  End
  Update = DefaultUpdate
    SizeRate = 3 7
    SizeRateDamping = 1 1
    AngleZ = 0 -359
    AngularDamping = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 0.8 0.8
  End
  EmissionVelocity = OutwardEmissionVelocity
  End
  EmissionVolume = PointEmissionVolume
    IsHollow = Yes
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem GondolinTowerGlow
  System
    Priority = VERY_LOW_OR_ABOVE
    ParticleName = EXLnzFlar1.tga
    Lifetime = 100 100
    SortLevel = 1
    BurstDelay = 100 100
    BurstCount = 2 3
    IsGroundAligned = Yes
  End
  Color = DefaultColor
    Color2 = R:255 G:255 B:255 25
    Color3 = R:0 G:0 B:0 100
  End
  Update = DefaultUpdate
    SizeRate = 0.5 1
    SizeRateDamping = 1 1
    AngleZ = 0 7
    AngularRateZ = -0.05 0.05
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
  EmissionVolume = LineEmissionVolume
    StartPoint = X:0 Y:0 Z:15
    EndPoint = X:0 Y:0 Z:50
  End
  Draw = DefaultDraw
  End
End

; Light of the Trees: the light over the whole map (2026-10-27; each LightOfTreesSunbeam of CloudBreakSpecialPower's 500-unit grid carries
; these five). Colours: silver R:160 G:185 B:255, gold R:255 G:175 B:70; the colour keys carry the brightness and the rise / fall (additive and
; emissive particles fade by colour), over the spell's 19 s. A system attached to an object emits only while the object is not fogged for the
; local player (RW 0x5FA2CE): the sunbeam is ALWAYS_VISIBLE (as 2.02's CloudBreakSunbeam), so the light shows over the whole map.
; Art: openbfme/tools/lightoftrees_fx.py
; the silver haze ray: a wide soft ray from the top right (AngleZ 2.6), faint
FXParticleSystem LightOfTreesHazeSilver
  System
    Priority = ALWAYS_RENDER
    Shader = W3D_EMISSIVE
    Type = DRAWABLE
    ParticleName = exlotfx_raywide.w3d
    Lifetime = 570 570
    IsOneShot = Yes
    Size = 1 1
    BurstDelay = 1 1
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color1 = R:0 G:0 B:0 0
    Color2 = R:160 G:185 B:255 45
    Color3 = R:160 G:185 B:255 95
    Color4 = R:160 G:185 B:255 190
    Color5 = R:160 G:185 B:255 285
    Color6 = R:160 G:185 B:255 380
    Color7 = R:160 G:185 B:255 475
    Color8 = R:0 G:0 B:0 570
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.11 0.11 0
  End
  Update = RenderObjectUpdate
    StartSizeX = 1.0 1.0
    StartSizeY = 1.0 1.0
    StartSizeZ = 1 1
    AngleZ = 2.6 2.6
    Rotation = ROTATE_Z
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1

  End
  EmissionVelocity = OrthoEmissionVelocity

  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 250
    Offset = X:0 Y:0 Z:0
  End
  Draw = RenderObjectDraw
  End
End

; the gold haze ray: from the top left (AngleZ 0.55)
FXParticleSystem LightOfTreesHazeGold
  System
    Priority = ALWAYS_RENDER
    Shader = W3D_EMISSIVE
    Type = DRAWABLE
    ParticleName = exlotfx_raywide.w3d
    Lifetime = 570 570
    IsOneShot = Yes
    Size = 1 1
    BurstDelay = 1 1
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color1 = R:0 G:0 B:0 0
    Color2 = R:255 G:175 B:70 45
    Color3 = R:255 G:175 B:70 95
    Color4 = R:255 G:175 B:70 190
    Color5 = R:255 G:175 B:70 285
    Color6 = R:255 G:175 B:70 380
    Color7 = R:255 G:175 B:70 475
    Color8 = R:0 G:0 B:0 570
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.11 0.11 0
  End
  Update = RenderObjectUpdate
    StartSizeX = 1.0 1.0
    StartSizeY = 1.0 1.0
    StartSizeZ = 1 1
    AngleZ = 0.55 0.55
    Rotation = ROTATE_Z
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1

  End
  EmissionVelocity = OrthoEmissionVelocity

  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 250
    Offset = X:0 Y:0 Z:0
  End
  Draw = RenderObjectDraw
  End
End

; retail's slanted sunrays (LM_Sunrays2) from the top right, 1 a sunbeam (2026-10-30, was 1 or 2), waxing silver to gold
FXParticleSystem LightOfTreesSunrays
  System
    Priority = ALWAYS_RENDER
    Shader = W3D_EMISSIVE
    Type = DRAWABLE
    ParticleName = LM_Sunrays2.w3d
    Lifetime = 570 570
    IsOneShot = Yes
    Size = 1 1
    BurstDelay = 1 1
    BurstCount = 1 1 ; 1 a sunbeam (1 3 gave 1 or 2: the count is a random real, its fraction dropped)
  End
  Color = DefaultColor
    Color1 = R:0 G:0 B:0 0
    Color2 = R:204 G:180 B:170 45
    Color3 = R:255 G:175 B:70 95
    Color4 = R:160 G:185 B:255 190
    Color5 = R:255 G:175 B:70 285
    Color6 = R:160 G:185 B:255 380
    Color7 = R:255 G:175 B:70 475
    Color8 = R:0 G:0 B:0 570
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.18 0.18 0
  End
  Update = RenderObjectUpdate
    StartSizeX = 1.5 1.5
    StartSizeY = 1.5 1.5
    StartSizeZ = 1 1
    AngleZ = 3.14 3.14
    Rotation = ROTATE_Z
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1

  End
  EmissionVelocity = OrthoEmissionVelocity

  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 240
    Offset = X:0 Y:0 Z:0
  End
  Draw = RenderObjectDraw
  End
End

; silver dew falling from the rain's height (800), one every 7-8 s a sunbeam
FXParticleSystem LightOfTreesDew
  System
    Priority = ALWAYS_RENDER
    ParticleName = exlotfx_dew.tga
    Lifetime = 170 170
    SystemLifetime = 540
    Size = 13 15
    BurstDelay = 200 240
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color1 = R:0 G:0 B:0 0
    Color2 = R:160 G:185 B:255 15
    Color3 = R:160 G:185 B:255 155
    Color4 = R:0 G:0 B:0 170
  End
  Alpha = DefaultAlpha
    Alpha1 = 1 1 0
  End
  Update = DefaultUpdate
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1

  End
  EmissionVelocity = OrthoEmissionVelocity
    Z = -5.0 -4.6
  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 240
    Length = 40
    Offset = X:0 Y:0 Z:800
  End
  Draw = DefaultDraw
  End
End

; gold leaf-flakes falling from 800, one every 9-10 s a sunbeam
FXParticleSystem LightOfTreesLeaf
  System
    Priority = ALWAYS_RENDER
    ParticleName = exlotfx_leaf.tga
    Lifetime = 260 260
    SystemLifetime = 540
    Size = 12 14
    BurstDelay = 260 300
    BurstCount = 1 1
  End
  Color = DefaultColor
    Color1 = R:0 G:0 B:0 0
    Color2 = R:255 G:175 B:70 15
    Color3 = R:255 G:175 B:70 245
    Color4 = R:0 G:0 B:0 260
  End
  Alpha = DefaultAlpha
    Alpha1 = 1 1 0
  End
  Update = DefaultUpdate
    AngleZ = -3 3
    AngularRateZ = -0.06 0.06
    AngularDamping = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
    DriftVelocity = X:0.25 Y:0.08 Z:0
  End
  EmissionVelocity = OrthoEmissionVelocity
    Z = -3.2 -2.8
  End
  EmissionVolume = CylinderEmissionVolume
    Radius = 240
    Length = 40
    Offset = X:0 Y:0 Z:800
  End
  Draw = DefaultDraw
  End
End

FXParticleSystem HEThranduilPinningArrowRed ; hero rework: Pinning Shot's waves, ThranDeadeyeArrow in red
  System
    Priority = ALWAYS_RENDER
    ParticleName = EXspearhead.tga
    Lifetime = 15 15
    SortLevel = 1
    Size = 5 5
    BurstCount = 4 4
    IsGroundAligned = Yes
    IsParticleUpTowardsEmitter = Yes
  End
  Color = DefaultColor
    Color1 = R:220 G:30 B:30 0 ;,; R:30 G:170 B:50 0 (ThranDeadeyeArrow's green)
    Color2 = R:0 G:0 B:0 15
  End
  Alpha = DefaultAlpha
    Alpha1 = 0.5 0.5 0 ;,; 0.25 (ThranDeadeyeArrow's)
    Alpha2 = 0 0 15
  End
  Update = DefaultUpdate
    SizeRate = -0.25 -0.25
    SizeRateDamping = 1 1
    AngleZ = 0 2
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    VelocityDamping = 1 1
  End
  EmissionVelocity = OrthoEmissionVelocity
  End
  EmissionVolume = LineEmissionVolume
    StartPoint = X:-5 Y:0 Z:0
    EndPoint = X:-5 Y:0 Z:0
  End
  Draw = DefaultDraw
  End
End
