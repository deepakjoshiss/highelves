Behavior           = CreateObjectDie ModuleTag_SpawnRefundObject ;,; 
    ExemptStatus      = SOLD ;,; 
    RequiredStatus    = BUILD_BEING_CANCELED  ;,;  
    CreationList      = OCL_SpawnWallHubRefund ;,; 
    DeathTypes        = ALL ;,; 
    MinKillerAngle    = 0 ;,; required not to spawn OCL when we cancel construction
    MaxKillerAngle    = 360 ;,; required not to spawn OCL when we cancel construction
    UpgradeRequired   = Upgrade_ObjectLevel10 ;,; based on timer;,; 
  End
  