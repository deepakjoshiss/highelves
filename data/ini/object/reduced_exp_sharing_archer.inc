    RemoveModule ModuleTag_DefaultShareExp  ;,; remove inherited default exp sharing  
    Behavior = ShareExperienceBehavior ModuleTag_ReducedShareExp
        Radius            = 100.0
        ObjectFilter    = ANY +HERO
        Percentage         = 0.5 ;,; 
        DropOff            = 1.0            ; Must be one or zero.
    End	
	