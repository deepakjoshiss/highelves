;/////////////////////////////////////////////////////////////////////////////////////////////////////////
;FILE: mod/armor.inc //////////////////////////////////////////////////////////////////////////////
;/////////////////////////////////////////////////////////////////////////////////////////////////////////
;Just so you know the choices available, here is part of Damage.h
;
;
;	"FORCE",
;	"CRUSH",	
;	"SLASH",
;	"PIERCE",
;	"SIEGE",
;	"STRUCTURAL",
;
;	"FLAME",
;	"FROST"
;	"HEALING",	
;	"UNRESISTABLE",	
;	"WATER",
;	"PENALTY",	
;	"FALLING",	
;	"TOPPLING",
;	"REFLECTED",
;	"PASSENGER",
;	"MAGIC",
;	"CHOP",
;	"HERO",
;	"SPECIALIST",
;	"URUK",
;	"HERO_RANGED",
;	"FLY_INTO",
;
;	"UNDEFINED",
;	"LOGICAL_FIRE",
;	"CAVALRY",
;	"CAVALRY_RANGED",
;	"POISON",
;
;	"SLASH", - Fighter Dmg
;	"CAVALRY" - Cavalry Dmg
;	"PIERCE",  - Archer Dmg
;	"SPECIALIST", - Pikeman Dmg
;
;
;


;//////////////////////MOD ARMORS///////////////////////////////////////////

Armor HeroMiniMountedArmorUpgraded
  Armor = DEFAULT         40%   
  Armor = SLASH           20%	; RotWK originally was 60%  
  Armor = PIERCE          10% ;,; 25% ;30% ;;,;; 35%	; RotWK originally was 60% 
  Armor = SPECIALIST      80% ;,; 130%   ; RotWK originally was 100% 
  Armor = CRUSH           10% ;;,;; 10%   
  Armor = CAVALRY	        30% 
  Armor = SIEGE           30%   
  Armor = FLAME           20%   
  Armor = FROST           20%   ;
  Armor = MAGIC           80%   
  Armor = HERO            60%   
  Armor = HERO_RANGED     60%   
  Armor = POISON	        50% 
  Armor = STRUCTURAL	    40% ;,; 65% ;;,;; 80%	; RotWK originally was 50% 
End