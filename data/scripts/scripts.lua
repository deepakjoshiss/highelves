----------------------------------------------------------------------
------------------------- 2.02 Helper Functions ----------------------
----------------------------------------------------------------------
verbosity = 0
dimmerCount = 0 --
playerCount = 0 --
-- archerCounter = 0
beginFlierIteration = false
GameReloaded = true

ObjStatusList = {
    ["DESTROYED"] = 0, ["CAN_ATTACK"] = 1, ["UNDER_CONSTRUCTION"] = 2, ["UNSELECTABLE"] = 3,
    ["NO_COLLISIONS"] = 4, ["NO_ATTACK"] = 5, ["AIRBORNE_TARGET"] = 6, ["PARACHUTING"] = 7,
    ["REPULSOR"] = 8, ["HIJACKED"] = 9, ["AFLAME"] = 10, ["BURNED"] = 11,
    ["WET"] = 12, ["IS_FIRING_WEAPON"] = 13, ["IS_BRAKING"] = 14, ["STEALTHED"] = 15,
    ["HIDDEN"] = 16, ["DETECTED"] = 17, ["CAN_STEALTH"] = 18, ["SOLD"] = 19,
    ["UNDERGOING_REPAIR"] = 20, ["RECONSTRUCTING"] = 21, ["IS_ATTACKING"] = 22, ["NO_AUTO_ACQUIRE"] = 23,
    ["USING_ABILITY"] = 24, ["IS_AIMING_WEAPON"] = 25, ["NO_ATTACK_FROM_AI"] = 26, ["IGNORING_STEALTH"] = 27,
    ["IS_MELEE_ATTACKING"] = 28, ["GUARD_SELECTION"] = 29, ["LEASHED_RETURNING"] = 30, ["DEATH_1"] = 31,
    ["DEATH_2"] = 32, ["DEATH_3"] = 33, ["DEATH_4"] = 34, ["DEATH_5"] = 35,
    ["CONTESTED"] = 36, ["CONTESTING_BUILDING"] = 37, ["HORDE_MEMBER"] = 38, ["RIDERLESS"] = 39,
    ["RIDER_IS_PILOT"] = 40, ["RIDER1"] = 41, ["RIDER2"] = 42, ["RIDER3"] = 43,
    ["RIDER4"] = 44, ["RIDER5"] = 45, ["RIDER6"] = 46, ["RIDER7"] = 47,
    ["RIDER8"] = 48, ["IMMOBILE"] = 49, ["FLEE_OFF_MAP"] = 50, ["NOT_IN_WORLD"] = 51,
    ["INAUDIBLE"] = 52, ["CHANTING"] = 53, ["ENRAGED"] = 54, ["CREATE_DRAWABLE_WITH_LOW_DETAIL"] = 55,
    ["SINKING"] = 56, ["RAMPAGING"] = 57, ["INSIDE_GARRISON"] = 58, ["DEPLOYED"] = 59,
    ["UNATTACKABLE"] = 60, ["ENCLOSED"] = 61, ["TEMPORARILY_DEFECTED"] = 62, ["TAGGED"] = 63,
    ["DEPLOYING"] = 64, ["BLOODTHIRSTY"] = 65, ["PORTER_TAGGED"] = 66, ["GRAB_AND_DROP"] = 67,
    ["STAND_GROUND"] = 68, ["UNCONTROLLABLY_SCARED"] = 69, ["SPECIAL_ABILITY_PACKING_UNPACKING"] = 70, ["PLEASE_EAT_ME"] = 71,
    ["UPDATING_AI"] = 72, ["HUNT_WHEN_IDLE"] = 73, ["IGNORE_AI_COMMAND"] = 74, ["RUNNING_DOWN_FROM_BEHIND"] = 75,
    ["DO_NOT_SCORE"] = 76, ["CAN_NOT_WALK_ON"] = 77, ["MARCH_OF_DEATH"] = 78, ["DO_NOT_PICK_ME"] = 79,
    ["INHERITED_FROM_ALLY_TEAM"] = 80, ["SWITCHED_WEAPONS"] = 81, ["END_FIRE_STATE"] = 82, ["BOOKENDING"] = 83,
    ["ELVISH_EXPRESSLY"] = 84, ["INSIDE_CASTLE"] = 85, ["BUILD_BEING_CANCELED"] = 86, ["PENDING_CONSTRUCTION"] = 87,
    ["PHANTOM_STRUCTURE"] = 88, ["IN_FORMATION_TEMPLATE"] = 89, ["IS_LEAVING_FACTORY"] = 90, ["MOVING_TO_DISMOUNT"] = 91,
    ["NO_HERO_PROPERTIES"] = 92, ["CAN_ENTER_ANYTHING"] = 93, ["HOLDING_THE_RING"] = 94, ["INVISIBLE_DETECTED_BY_FRIEND"] = 95,
    ["INVISIBLE_DETECTED"] = 96, ["WORKER_REPAIRING"] = 97, ["ATTACHED"] = 98, ["WONT_RIDE_WITH_YOU"] = 99,
    ["COMMAND_BUTTON_TOGGLED"] = 100, ["IGNORE_PARALYZE_NUGGET"] = 101, ["SUMMONING_REPLACEMENT"] = 102, ["HOLDING_THE_SHARD"] = 103,
    ["USER_DEFINED_1"] = 104, ["USER_DEFINED_2"] = 105
}

KindOfTable = {
	["OBSTACLE"]=0, ["SELECTABLE"]=1, ["IMMOBILE"]=2, ["CAN_ATTACK"]=3, ["STICK_TO_TERRAIN_SLOPE"]=4, ["CAN_CAST_REFLECTIONS"]=5, ["SHRUBBERY"]=6, ["STRUCTURE"]=7, ["INFANTRY"]=8, ["CAVALRY"]=9, ["MONSTER"]=10, ["MACHINE"]=11, ["AIRCRAFT"]=12, ["HUGE_VEHICLE"]=13, ["DOZER"]=14, ["SWARM_DOZER"]=15, ["HARVESTER"]=16, ["COMMANDCENTER"]=17, 
	["CASTLE_CENTER"]=18, ["SALVAGER"]=19, ["WEAPON_SALVAGER"]=20, ["TRANSPORT"]=21, ["BRIDGE"]=22, ["LANDMARK_BRIDGE"]=23, ["BRIDGE_TOWER"]=24, ["PROJECTILE"]=25, ["PRELOAD"]=26, ["NO_GARRISON"]=27, ["CASTLE_KEEP"]=28, ["WAVE_EFFECT"]=29, ["NO_COLLIDE"]=30, ["REPAIR_PAD"]=31, ["HEAL_PAD"]=32, ["STEALTH_GARRISON"]=33, ["SUPPLY_GATHERING_CENTER"]=34, ["AIRFIELD"]=35, 
	["DRAWABLE_ONLY"]=36, ["MP_COUNT_FOR_VICTORY"]=37, ["REBUILD_HOLE"]=38, ["SCORE"]=39, ["SCORE_CREATE"]=40, ["SCORE_DESTROY"]=41, ["NO_HEAL_ICON"]=42, ["CAN_RAPPEL"]=43, ["PARACHUTABLE"]=44, ["CAN_BE_REPULSED"]=45, ["MOB_NEXUS"]=46, ["IGNORED_IN_GUI"]=47, ["CRATE"]=48, ["CAPTURABLE"]=49, ["LINKED_TO_FLAG"]=50, ["CLEARED_BY_BUILD"]=51, ["SMALL_MISSILE"]=52, ["ALWAYS_VISIBLE"]=53, 
	["UNATTACKABLE"]=54, ["MINE"]=55, ["CLEANUP_HAZARD"]=56, ["PORTABLE_STRUCTURE"]=57, ["ALWAYS_SELECTABLE"]=58, ["ATTACK_NEEDS_LINE_OF_SIGHT"]=59, ["WALK_ON_TOP_OF_WALL"]=60, ["DEFENSIVE_WALL"]=61, ["FS_POWER"]=62, ["FS_FACTORY"]=63, ["FS_BASE_DEFENSE"]=64, ["FS_TECHNOLOGY"]=65, ["AIRCRAFT_PATH_AROUND"]=66, ["LOW_OVERLAPPABLE"]=67, ["FORCEATTACKABLE"]=68, ["AUTO_RALLYPOINT"]=69, ["OATHBREAKER"]=70, ["POWERED"]=71, 
	["PRODUCED_AT_HELIPAD"]=72, ["DRONE"]=73, ["CAN_SEE_THROUGH_STRUCTURE"]=74, ["BALLISTIC_MISSILE"]=75, ["CLICK_THROUGH"]=76, ["SUPPLY_SOURCE_ON_PREVIEW"]=77, ["PARACHUTE"]=78, ["GARRISONABLE_UNTIL_DESTROYED"]=79, ["BOAT"]=80, ["IMMUNE_TO_CAPTURE"]=81, ["HULK"]=82, ["SHOW_PORTRAIT_WHEN_CONTROLLED"]=83, ["SPAWNS_ARE_THE_WEAPONS"]=84, ["CANNOT_BUILD_NEAR_SUPPLIES"]=85, ["SUPPLY_SOURCE"]=86, ["REVEAL_TO_ALL"]=87, ["DISGUISER"]=88, ["INERT"]=89, 
	["HERO"]=90, ["IGNORES_SELECT_ALL"]=91, ["DONT_AUTO_CRUSH_INFANTRY"]=92, ["SIEGE_TOWER"]=93, ["TREE"]=94, ["SHRUB"]=95, ["CLUB"]=96, ["ROCK"]=97, ["THROWN_OBJECT"]=98, ["GRAB_AND_KILL"]=99, ["OPTIMIZED_PROP"]=100, ["ENVIRONMENT"]=101, ["DEFLECT_BY_SPECIAL_POWER"]=102, ["WORKING_PASSENGER"]=103, ["BASE_FOUNDATION"]=104, ["NEED_BASE_FOUNDATION"]=105, ["REACT_WHEN_SELECTED"]=106, ["GIMLI"]=107, 
	["ORC"]=108, ["HORDE"]=109, ["COMBO_HORDE"]=110, ["NONOCCLUDING"]=111, ["NO_FREEWILL_ENTER"]=112, ["CAN_USE_SIEGE_TOWER"]=113, ["CAN_RIDE_SIEGE_LADDER"]=114, ["TACTICAL_MARKER"]=115, ["PATH_THROUGH_EACH_OTHER"]=116, ["NOTIFY_OF_PREATTACK"]=117, ["GARRISON"]=118, ["MELEE_HORDE"]=119, ["BASE_SITE"]=120, ["INERT_SHROUD_REVEALER"]=121, ["OCL_BIT"]=122, ["SPELL_BOOK"]=123, ["DEPRECATED"]=124, ["PATH_THROUGH_INFANTRY"]=125, 
	["NO_FORMATION_MOVEMENT"]=126, ["NO_BASE_CAPTURE"]=127, ["ARMY_SUMMARY"]=128, ["HOBBIT"]=129, ["NOT_AUTOACQUIRABLE"]=130, ["URUK"]=131, ["CHUNK_VENDOR"]=132, ["ARCHER"]=133, ["MOVE_ONLY"]=134, ["FS_CASH_PRODUCER"]=135, ["ROCK_VENDOR"]=136, ["BLOCKING_GATE"]=137, ["CAN_RIDE_BATTERING_RAM"]=138, ["SIEGE_LADDER"]=139, ["MINE_TRIGGER"]=140, ["BUFF"]=141, ["GRAB_AND_DROP"]=142, ["PORTER"]=143, 
	["SCARY"]=144, ["CRITTER_EMITTER"]=145, ["SALT_LICK"]=146, ["CAN_ATTACK_WALLS"]=147, ["IGNORE_FOR_VICTORY"]=148, ["DO_NOT_CLASSIFY"]=149, ["WALL_UPGRADE"]=150, ["ARMY_OF_DEAD"]=151, ["TAINT"]=152, ["BASE_DEFENSE_FOUNDATION"]=153, ["NOT_SELLABLE"]=154, ["WEBBED"]=155, ["WALL_HUB"]=156, ["BUILD_FOR_FREE"]=157, ["IGNORE_FOR_EVA_SPEECH_POSITION"]=158, ["MADE_OF_WOOD"]=159, ["MADE_OF_METAL"]=160, ["MADE_OF_STONE"]=161, 
	["MADE_OF_DIRT"]=162, ["FACE_AWAY_FROM_CASTLE_KEEP"]=163, ["BANNER"]=164, ["I_WANT_TO_EAT_YOU"]=165, ["INDUSTRY_AFFECTED"]=166, ["DWARVENRICHES_AFFECTED"]=167, ["GANDALF"]=168, ["ARAGORN"]=169, ["HAS_HEALTH_BAR"]=170, ["BIG_MONSTER"]=171, ["DEPLOYED_MINE"]=172, ["CANNOT_RETALIATE"]=173, ["CREEP"]=174, ["TAINTEFFECT"]=175, ["TROLL_BUFF_NUGGET"]=176, ["VITAL_FOR_BASE_SURVIVAL"]=177, ["DO_NOT_PICK_ME_WHEN_BUILDING"]=178, ["SUMMONED"]=179, 
	["HIDE_IF_FOGGED"]=180, ["ALWAYS_SHOW_HOUSE_COLOR"]=181, ["MOVE_FOR_NOONE"]=182, ["WB_DISPLAY_SCRIPT_NAME"]=183, ["CAN_CLIMB_WALLS"]=184, ["MUMAKIL_BUFF_NUGGET"]=185, ["LARGE_RECTANGLE_PATHFIND"]=186, ["SUBMARINE"]=187, ["PORT"]=188, ["WALL_SEGMENT"]=189, ["CREATE_A_HERO"]=190, ["SHIP"]=191, ["OPTIMIZED_SOUND"]=192, ["PASS_EXPERIENCE_TO_CONTAINED"]=193, ["DOZER_FACTORY"]=194, ["THREAT_FINDER"]=195, ["ECONOMY_STRUCTURE"]=196, ["LIVING_WORLD_BUILDING_MIRROR"]=197, 
	["PIKE"]=198, ["NONCOM"]=199, ["OBSOLETE"]=200, ["SCALEABLE_WALL"]=201, ["SKYBOX"]=202, ["WALL_GATE"]=203, ["CAPTUREFLAG"]=204, ["NEUTRALGOLLUM"]=205, ["PASS_EXPERIENCE_TO_CONTAINER"]=206, ["GIANT_BIRD"]=207, ["ORIENTS_TO_CAMERA"]=208, ["NEVER_CULL_FOR_MP"]=209, ["DONT_USE_CANCEL_BUILD_BUTTON"]=210, ["ONE_RING"]=211, ["HEAVY_MELEE_HITTER"]=212, ["DONT_HIDE_IF_FOGGED"]=213, ["CAN_SHOOT_OVER_WALLS"]=214, ["PASS_EXPERIENCE_TO_PRODUCER"]=215, 
	["EXPANSION_PAD"]=216, ["AMPHIBIOUS"]=217, ["SUPPORT"]=218, ["TROLL"]=219, ["SIEGEENGINE"]=220, ["HORDE_MONSTER"]=221 }
	
CompareTable = { ["<"]=0, ["<="]=1, ["=="]=2, [">="]=3, [">"]=4, ["~="]=5 } -- 

HeroTeamsTable = {}

heroAbilityList = {
    ElvenLegolas = {
        { ability = "SpecialAbilityHawkStrike", cooldown = 45 },
        { ability = "SpecialAbilityTrainArchers", cooldown = 150 },
        { ability = "SpecialAbilityKnifeFighter", cooldown = 15 },
        { ability = "SpecialAbilityArrowStorm", cooldown = 210 },
    },
    ElvenThranduil = {	
        { ability = "SpecialAbilityMoveUnseen", cooldown = 120 },
        { ability = "SpecialAbilityThranduilDeadeye", cooldown = 120 },
		{ ability = "SpecialAbilityThornVengeance", cooldown = 240 },
    },
	ElvenHaldir = {	
        { ability = "SpecialAbilityHaldirGoldenArrow", cooldown = 180 },
    },
	ElvenArwen = {
		{ ability = "SpecialAbility202ElvenGrace", cooldown = 90 },
        { ability = "SpecialAbilityPersonalFlood", cooldown = 180 },
    },
    ElvenGlorfindel = {
        { ability = "SpecialAbilityGlorfindelBladeOfPurity", cooldown = 120 },
        { ability = "SpecialAbilityGlorfindelWindRider", cooldown = 120 },
        { ability = "SpecialAbilityGlorfindelStarlight", cooldown = 270 },
    },
    ElvenElrond = {
        { ability = "SpecialAbility202ElrondElvenGrace", cooldown = 90 },
        { ability = "SpecialAbilityElrondFarsight", cooldown = 120 },
        { ability = "SpecialPowerSpawnTornado", cooldown = 300 },
        { ability = "SpecialAbilityElrondRestoration", cooldown = 240 },
    },
	RohanTreeBerd = {
        { ability = "SpecialAbilityTreebeardEnrage", cooldown = 120 },
        { ability = "SpecialAbilityGrabPassenger2", cooldown = 120 },
    },
	GondorGandalf = {
        { ability = "SpecialAbilityWizardBlast", cooldown = 45 },
        { ability = "SpecialAbilityLightningSword", cooldown = 120 },
        { ability = "SpecialAbilityIstariLight", cooldown = 150 },
        { ability = "SpecialAbilityWordOfPower", cooldown = 360 },
    },
	GondorAragornMP = {
		{ ability = "SpecialAbility202AragornAthelas", cooldown = 90 },
		{ ability = "SpecialAbilityAragornBladeMaster", cooldown = 120 },
		{ ability = "SpecialAbilityAragornElendil", cooldown = 120 },
		{ ability = "SuperweaponSpawnOathbreakers", cooldown = 300 },
	},
	RohanTheoden = {
		{ ability = "SpecialAbilityKingsFavor", cooldown = 150 },
		{ ability = "SpecialAbilityTheodenGloriousCharge", cooldown = 240 },
	},	
	GondorBoromir = {
		{ ability = "SpecialAbilityHornOfGondor", cooldown = 105 },
		{ ability = "SpecialAbilityBoromirCaptainofGondor", cooldown = 150 },
	},
	GondorFaramir = {
		{ ability = "SpecialAbilityWoundArrow", cooldown = 45 },
		{ ability = "SpecialAbilityFaramirCaptainofGondor", cooldown = 150 },
	},
	RohanEomer = {
		{ ability = "SpecialAbilitySpearThrow", cooldown = 60 },
	},
	RohanEowyn = {
		{ ability = "SpecialAbilitySmite", cooldown = 60 },
		{ ability = "SpecialAbilityDisguise", cooldown = 30 },
		{ ability = "SpecialAbilityEowynShieldMaiden", cooldown = 120 },
	},
	DwarvenCaptainofDale = {
		{ ability = "SpecialAbilityDaleSlamArrow", cooldown = 45 },
		{ ability = "SpecialAbilityTrainArchers", cooldown = 150 },
		{ ability = "SpecialAbilityDaleBeastSlayerArrow", cooldown = 144 },
	},
	DwarvenGloin = {
		{ ability = "SpecialAbilityDwarvenGloinSlam", cooldown = 60 },
		{ ability = "SpecialAbilityDwarvenGloinShakeFoundation", cooldown = 180 },
		{ ability = "SpecialAbilityGloinSmash", cooldown = 240 },
	},
	DwarvenDain = {
		{ ability = "SpecialAbilityDainMightyRage", cooldown = 180 },
		{ ability = "SpecialAbilityDainSummonRoyalGuard", cooldown = 210 },
	},
	DwarvenGimli = {
		{ ability = "SpecialAbilityGimliAxe", cooldown = 45 },
		{ ability = "SpecialAbilityGimliLeap", cooldown = 60 },
		{ ability = "SpecialAbilityGimliHeroMode", cooldown = 180 },
	},
	IsengardWormTongue = {
		{ ability = "SpecialAbilityWormtongueEscape", cooldown = 90 },
		{ ability = "SpecialAbilityWormtongueVenomousWords", cooldown = 60 },
		{ ability = "SpecialAbilityWormtongueBackstab", cooldown = 90 },
		{ ability = "SpecialAbilityWormtongueCorrodeAllegiance_CPFix", cooldown = 180 },
	},
	IsengardLurtz = {
		{ ability = "SpecialAbilityLurtzCarnage", cooldown = 120 },
		{ ability = "SpecialAbilityLurtzCripple", cooldown = 80 },
	},
	IsengardSharku = {
		{ ability = "SpecialAbilityTameTheBeast", cooldown = 120 },
		{ ability = "SpecialAbilityIsengardSharkuManEaterGrab", cooldown = 90 },	
		{ ability = "SpecialAbilityIsengardSharkuManEaterDrop", cooldown = 90 },			
	},
	IsengardSaruman = {
		{ ability = "SpecialPowerTelekeneticPush", cooldown = 60 },
		{ ability = "SpecialAbilitySarumanFireball", cooldown = 60 },	
		{ ability = "SpecialAbilityKingsFavor", cooldown = 150 },	
		{ ability = "SpecialAbilityLightingBolt", cooldown = 120 },
		{ ability = "SpecialAbilityDominateEnemy", cooldown = 360 },	
	},
	Drogoth = {
		{ ability = "SpecialAbilityDrogothFireball", cooldown = 60 }, 
		{ ability = "SpecialAbilityWingBlast", cooldown = 90 },	
		{ ability = "SpecialAbilityDrogothFireflight", cooldown = 180 },
		{ ability = "SpecialAbilityDrogothIncinerate", cooldown = 300 },	
	},
	WildShelob = {
		{ ability = "SpecialAbilityShelobWebbing", cooldown = 60 }, 
		{ ability = "SpecialAbilityScreech", cooldown = 180 },	
		{ ability = "SpecialAbilityWildShelobTunnel", cooldown = 75 },
		{ ability = "SpecialAbilityWildShelobPoisonedStinger", cooldown = 120 },	
	},
	WildGoblinKing = {
		{ ability = "SpecialAbilitySkullTotem", cooldown = 120 },	
		{ ability = "SpecialAbilityGoblinKingPoisonedStinger", cooldown = 120 },	
		{ ability = "SpecialAbilityCallFromTheDeep", cooldown = 300 },	
	},
	WildAzog = {
		{ ability = "SpecialAbilityCrackTheWhip", cooldown = 150 },	
		{ ability = "SpecialAbilityCreateAHeroBattleRage_Level3", cooldown = 120 },	
	},
	MordorWitchKing = {
		{ ability = "SpecialAbilityMordorWitchkingMorgulBlade", cooldown = 60 },	
		{ ability = "SpecialAbilityScreech", cooldown = 180 },
		{ ability = "SpecialAbilityCurseEnemy", cooldown = 180 },	
	},
	KhamulMounted = {
		{ ability = "SpecialAbilityBlackRiderMorgulBlade", cooldown = 60 },	
		{ ability = "SpecialAbilityScreech", cooldown = 180 },
	},
	MordorMorgromirMounted = {
		{ ability = "SpecialAbilityBlackRiderMorgulBlade", cooldown = 60 },	
		{ ability = "SpecialAbilityScreech", cooldown = 180 },
	},
	EvilMenBlackRider = {
		{ ability = "SpecialAbilityBlackRiderMorgulBlade", cooldown = 60 },	
		{ ability = "SpecialAbilityScreech", cooldown = 180 },
	},
	MordorMouthOfSauron = {
		{ ability = "SpecialAbilityMouthOfSauronDoubt", cooldown = 60 },	
		{ ability = "SpecialAbilityMouthOfSauronEvilEye", cooldown = 150 },
		{ ability = "SpecialAbilityMouthOfSauronDissent", cooldown = 240 },	
	},
	MordorGothmog = {
		{ ability = "SpecialAbilityLieutenantsFavor", cooldown = 150 },
		{ ability = "SpecialAbilityLurtzCarnage", cooldown = 120 },	
	},
	AngmarHwaldar = {
		{ ability = "SpecialAbilityHwaldarSummonHillmen1", cooldown = 180 },
		{ ability = "SpecialAbilityHwaldarSummonHillmen2", cooldown = 180 },	
	},
	AngmarMorgramir = {
		{ ability = "SpecialAbilityBlackRiderMorgulBlade", cooldown = 60 },
		{ ability = "SpecialAbilityDarkGlory", cooldown = 180 },	
		{ ability = "SpecialAbilityAngmarMorgramirRuin", cooldown = 180 },
	},
	AngmarKarsh = {
		{ ability = "SpecialAbilityKarshBlink", cooldown = 120 },
		{ ability = "SpecialAbilityWhisperofDeath", cooldown = 120 },	
	},
	AngmarRogash = {
		-- { ability = "SpecialAbilityRogashDominateTroll", cooldown = 180 },
		{ ability = "SpecialAbilityRogashCTSummon", cooldown = 240 },
		{ ability = "SpecialAbilityRogashLeap", cooldown = 120 },	
		{ ability = "SpecialAbilityRageoftheNorth", cooldown = 180 },
	},
	AngmarWitchking = {
		{ ability = "SpecialAbilityWitchkingMorgulBlade", cooldown = 60 },
		{ ability = "SpecialAbilityScreech", cooldown = 180 },	
		{ ability = "SpecialAbilityCurseEnemy", cooldown = 180 },
	},
	SummonedDragon = {
        { ability = "SpecialAbilitySummonedDragonReposition", cooldown = 15 },
    },
	SummonedDragonJH1 = {
        { ability = "SpecialAbilitySummonedDragonReposition", cooldown = 15 },
    },
}

-- The High Elves faction (FactionHighElves): its heroes are copies named HE<hero>, with the High Elves copy of a power where they have one
heroAbilityList.HEElvenLegolas = {
        { ability = "HESpecialAbilityHawkStrike", cooldown = 45 },
        { ability = "SpecialAbilityTrainArchers", cooldown = 150 },
        { ability = "SpecialAbilityKnifeFighter", cooldown = 15 },
        { ability = "SpecialAbilityArrowStorm", cooldown = 210 },
}
heroAbilityList.HEElvenThranduil = {
        { ability = "SpecialAbilityMoveUnseen", cooldown = 120 },
        { ability = "SpecialAbilityThranduilDeadeye", cooldown = 120 },
		{ ability = "HESpecialAbilityThornVengeance", cooldown = 240 },
}
heroAbilityList.HEElvenHaldir = {
        { ability = "SpecialAbilityHaldirGoldenArrow", cooldown = 180 },
}
heroAbilityList.HEElvenArwen = {
		{ ability = "SpecialAbility202ElvenGrace", cooldown = 90 },
        { ability = "SpecialAbilityPersonalFlood", cooldown = 180 },
}
heroAbilityList.HEElvenGlorfindel = {
        { ability = "SpecialAbilityGlorfindelBladeOfPurity", cooldown = 120 },
        { ability = "SpecialAbilityGlorfindelWindRider", cooldown = 120 },
        { ability = "HESpecialAbilityGlorfindelStarlight", cooldown = 270 },
}
heroAbilityList.HEElvenElrond = {
        { ability = "SpecialAbility202ElrondElvenGrace", cooldown = 90 },
        { ability = "HESpecialAbilityElrondFarsight", cooldown = 120 },
        { ability = "SpecialPowerSpawnTornado", cooldown = 300 },
        { ability = "SpecialAbilityElrondRestoration", cooldown = 240 },
}
heroAbilityList.HERohanTreeBerd = {
        { ability = "SpecialAbilityTreebeardEnrage", cooldown = 120 },
        { ability = "SpecialAbilityGrabPassenger2", cooldown = 120 },
}

FlierTable = {}
heroPowers = {}
TowerTable = {}
EcoStructuresTable = {}
FortsTable = {
	forts = {},
	shadows = {}
}
Citadels = {}
WorkerTable = {}
MHHSTable = {}

---
-- GetObjString()
-- Converts the output of ObjectDescription(x) to a key that can be retrieved from globals()
--

function getFrameNow()
	-- Using GetFrame() directly in multiple spots breaks it
	-- getFrameNow() can be called as many times as needed
	local frame = GetFrame()
	return frame
end

function GetObjDecimal(obj)
	-- Returns a clean object number
	-- Example output: 567
	local desc = ObjectDescription(obj)
	local len = strlen(desc)
	local start = 0

	-- find "Object "
	for i = 1, len - 6 do
		if strsub(desc, i, i + 5) == "Object" then
			start = i + 7 -- after "Object "
			break
		end
	end

	if start == 0 then
		return nil
	end

	-- find end of number
	local finish = start
	for i = start, len do
		local c = strsub(desc, i, i)
		if c < "0" or c > "9" then
			finish = i - 1
			break
		end
	end
	return tonumber(strsub(desc, start, finish))
end

function GetObjString(objDesc)
	local charMatch = 0

	for i = 1, strlen(objDesc) do
		local c = strsub(objDesc, i,i)
		if c == '[' then
			charMatch = i -1
			break
		end
	end

	local displ = tonumber(strsub(objDesc, 8, charMatch))

	return "ObjID#" .. format("%08x", displ)
end

function SetUnitReference(self)
	local ref = GetObjString(ObjectDescription(self))
	ExecuteAction("SET_UNIT_REFERENCE", ref, self)
	return ref
end

function GetUnitReference(self)
	return SetUnitReference(self) 
end

function ForceSelectObject(obj, objectIniName, centerCamera)

    --Call examples:
	--ForceSelectObject(self, "ElvenHaldir", "0") -- select but do not center the camera
	--ForceSelectObject(self, "ElvenHaldir", "1") -- select and center the camera

	ExecuteAction("OBJECT_FORCE_SELECT", GetScriptTeamName(obj), objectIniName, centerCamera, "placeholder")

end


function GetUnitLevel(self)
	local reference = GetUnitReference(self)
	local level = 1
	for i = 0, 10 do
		if EvaluateCondition("UNIT_COMPARE_RANK", reference, CompareTable["=="], i) then
			-- ExecuteAction("DISPLAY_TEXT", "Level " .. tostring(i))
			level = i -- Set level if match is found
			break -- Exit loop after finding level
		end
	end 
	return level
end

function GiveUnitExperienceLevel(self, level, ExpIniTemplateName)
    -- Must use the template name from experiencelevels.ini
    -- Example entry in the ini: ExperienceLevel ElvenLegolasLevel2
    -- This function applies experience levels from Level2 up to the specified level
    -- Usage example: GiveUnitExperienceLevel(self, 7, "ElvenLegolas") -- set Lego at Lvl 7
	-- Note: Hordes must be set by level minus 1 for the intended level to apply
	-- Note 2: Giving hordes levels does not increase their EXP.
    local ref = SetUnitReference(self)
    for i = 1, level do
        local templateName = ExpIniTemplateName .. "Level" .. tostring(i) -- Example: ElvenLegolasLevel7
        ExecuteAction("UNIT_GIVE_EXPERIENCE_LEVEL", ref, templateName)
    end
end

function GiveExpPoints(self, points)
	local ref = GetUnitReference(self)
    ExecuteAction("UNIT_GIVE_EXPERIENCE_POINTS", ref, points)
end

function GetHealth(self)
    local reference = GetUnitReference(self)
    local low, high = 1, 100

	if EvaluateCondition("UNIT_HEALTH", reference, CompareTable["=="], 100) then
		return 100
	end

    for _ = 1, 7 do  -- Binary search runs in at most 7 iterations
        local mid = floor((low + high) / 2)

        if EvaluateCondition("UNIT_HEALTH", reference, CompareTable["=="], mid) then
            -- ExecuteAction("DISPLAY_TEXT", "HP " .. tostring(mid))
            return mid  -- Return immediately if found
        elseif EvaluateCondition("UNIT_HEALTH", reference, CompareTable[">"], mid) then
            low = mid + 1
        else
            high = mid
        end
    end

    -- ExecuteAction("DISPLAY_TEXT", "HP " .. tostring(low))
    return low  -- If not found, binary search guarantees `low` is correct
end

-- Toggles a unit's object status on or off
-- @ param unit: The object (self)
-- @ param status: A string in UPPERCASE (e.g., "UNATTACKABLE")
-- @ param enable: true/false OR 1/0 (whether to enable or disable the status)
-- Example: ToggleObjectStatus(self, "UNATTACKABLE", true)
function ToggleObjectStatus(unit, status, enable)
    if ObjStatusList[status] then  -- Ensure the status is valid
        ExecuteAction("UNIT_CHANGE_OBJECT_STATUS", unit, ObjStatusList[status], enable)
    end
end

-- Check if a unit has object status
-- ObjectHasStatus(self, "TEMPORARILY_DEFECTED")
-- Returns true if the unit has the status, false otherwise
function ObjectHasStatus(unit, status)
	local reference = GetUnitReference(unit)
	local statusPresent = EvaluateCondition("UNIT_HAS_OBJECT_STATUS", reference, ObjStatusList[status])
	return statusPresent 
end

function CheckStatuses(self)
	if ObjectHasStatus(self, "DESTROYED") then ExecuteAction("DISPLAY_TEXT", "DESTROYED") end
	if ObjectHasStatus(self, "CAN_ATTACK") then ExecuteAction("DISPLAY_TEXT", "CAN_ATTACK") end
	if ObjectHasStatus(self, "UNDER_CONSTRUCTION") then ExecuteAction("DISPLAY_TEXT", "UNDER_CONSTRUCTION") end
	if ObjectHasStatus(self, "UNSELECTABLE") then ExecuteAction("DISPLAY_TEXT", "UNSELECTABLE") end
	if ObjectHasStatus(self, "NO_COLLISIONS") then ExecuteAction("DISPLAY_TEXT", "NO_COLLISIONS") end
	if ObjectHasStatus(self, "NO_ATTACK") then ExecuteAction("DISPLAY_TEXT", "NO_ATTACK") end
	if ObjectHasStatus(self, "AIRBORNE_TARGET") then ExecuteAction("DISPLAY_TEXT", "AIRBORNE_TARGET") end
	if ObjectHasStatus(self, "PARACHUTING") then ExecuteAction("DISPLAY_TEXT", "PARACHUTING") end
	if ObjectHasStatus(self, "REPULSOR") then ExecuteAction("DISPLAY_TEXT", "REPULSOR") end
	if ObjectHasStatus(self, "HIJACKED") then ExecuteAction("DISPLAY_TEXT", "HIJACKED") end
	if ObjectHasStatus(self, "AFLAME") then ExecuteAction("DISPLAY_TEXT", "AFLAME") end
	if ObjectHasStatus(self, "BURNED") then ExecuteAction("DISPLAY_TEXT", "BURNED") end
	if ObjectHasStatus(self, "WET") then ExecuteAction("DISPLAY_TEXT", "WET") end
	if ObjectHasStatus(self, "IS_FIRING_WEAPON") then ExecuteAction("DISPLAY_TEXT", "IS_FIRING_WEAPON") end
	if ObjectHasStatus(self, "IS_BRAKING") then ExecuteAction("DISPLAY_TEXT", "IS_BRAKING") end
	if ObjectHasStatus(self, "STEALTHED") then ExecuteAction("DISPLAY_TEXT", "STEALTHED") end
	if ObjectHasStatus(self, "HIDDEN") then ExecuteAction("DISPLAY_TEXT", "HIDDEN") end
	if ObjectHasStatus(self, "DETECTED") then ExecuteAction("DISPLAY_TEXT", "DETECTED") end
	if ObjectHasStatus(self, "CAN_STEALTH") then ExecuteAction("DISPLAY_TEXT", "CAN_STEALTH") end
	if ObjectHasStatus(self, "SOLD") then ExecuteAction("DISPLAY_TEXT", "SOLD") end
	if ObjectHasStatus(self, "UNDERGOING_REPAIR") then ExecuteAction("DISPLAY_TEXT", "UNDERGOING_REPAIR") end
	if ObjectHasStatus(self, "RECONSTRUCTING") then ExecuteAction("DISPLAY_TEXT", "RECONSTRUCTING") end
	if ObjectHasStatus(self, "IS_ATTACKING") then ExecuteAction("DISPLAY_TEXT", "IS_ATTACKING") end
	if ObjectHasStatus(self, "NO_AUTO_ACQUIRE") then ExecuteAction("DISPLAY_TEXT", "NO_AUTO_ACQUIRE") end
	if ObjectHasStatus(self, "USING_ABILITY") then ExecuteAction("DISPLAY_TEXT", "USING_ABILITY") end
	if ObjectHasStatus(self, "IS_AIMING_WEAPON") then ExecuteAction("DISPLAY_TEXT", "IS_AIMING_WEAPON") end
	if ObjectHasStatus(self, "NO_ATTACK_FROM_AI") then ExecuteAction("DISPLAY_TEXT", "NO_ATTACK_FROM_AI") end
	if ObjectHasStatus(self, "IGNORING_STEALTH") then ExecuteAction("DISPLAY_TEXT", "IGNORING_STEALTH") end
	if ObjectHasStatus(self, "IS_MELEE_ATTACKING") then ExecuteAction("DISPLAY_TEXT", "IS_MELEE_ATTACKING") end
	if ObjectHasStatus(self, "GUARD_SELECTION") then ExecuteAction("DISPLAY_TEXT", "GUARD_SELECTION") end
	if ObjectHasStatus(self, "LEASHED_RETURNING") then ExecuteAction("DISPLAY_TEXT", "LEASHED_RETURNING") end
	if ObjectHasStatus(self, "DEATH_1") then ExecuteAction("DISPLAY_TEXT", "DEATH_1") end
	if ObjectHasStatus(self, "DEATH_2") then ExecuteAction("DISPLAY_TEXT", "DEATH_2") end
	if ObjectHasStatus(self, "DEATH_3") then ExecuteAction("DISPLAY_TEXT", "DEATH_3") end
	if ObjectHasStatus(self, "DEATH_4") then ExecuteAction("DISPLAY_TEXT", "DEATH_4") end
	if ObjectHasStatus(self, "DEATH_5") then ExecuteAction("DISPLAY_TEXT", "DEATH_5") end
	if ObjectHasStatus(self, "CONTESTED") then ExecuteAction("DISPLAY_TEXT", "CONTESTED") end
	if ObjectHasStatus(self, "CONTESTING_BUILDING") then ExecuteAction("DISPLAY_TEXT", "CONTESTING_BUILDING") end
	if ObjectHasStatus(self, "HORDE_MEMBER") then ExecuteAction("DISPLAY_TEXT", "HORDE_MEMBER") end
	if ObjectHasStatus(self, "RIDERLESS") then ExecuteAction("DISPLAY_TEXT", "RIDERLESS") end
	if ObjectHasStatus(self, "RIDER_IS_PILOT") then ExecuteAction("DISPLAY_TEXT", "RIDER_IS_PILOT") end
	if ObjectHasStatus(self, "RIDER1") then ExecuteAction("DISPLAY_TEXT", "RIDER1") end
	if ObjectHasStatus(self, "RIDER2") then ExecuteAction("DISPLAY_TEXT", "RIDER2") end
	if ObjectHasStatus(self, "RIDER3") then ExecuteAction("DISPLAY_TEXT", "RIDER3") end
	if ObjectHasStatus(self, "RIDER4") then ExecuteAction("DISPLAY_TEXT", "RIDER4") end
	if ObjectHasStatus(self, "RIDER5") then ExecuteAction("DISPLAY_TEXT", "RIDER5") end
	if ObjectHasStatus(self, "RIDER6") then ExecuteAction("DISPLAY_TEXT", "RIDER6") end
	if ObjectHasStatus(self, "RIDER7") then ExecuteAction("DISPLAY_TEXT", "RIDER7") end
	if ObjectHasStatus(self, "RIDER8") then ExecuteAction("DISPLAY_TEXT", "RIDER8") end
	if ObjectHasStatus(self, "IMMOBILE") then ExecuteAction("DISPLAY_TEXT", "IMMOBILE") end
	if ObjectHasStatus(self, "FLEE_OFF_MAP") then ExecuteAction("DISPLAY_TEXT", "FLEE_OFF_MAP") end
	if ObjectHasStatus(self, "NOT_IN_WORLD") then ExecuteAction("DISPLAY_TEXT", "NOT_IN_WORLD") end
	if ObjectHasStatus(self, "INAUDIBLE") then ExecuteAction("DISPLAY_TEXT", "INAUDIBLE") end
	if ObjectHasStatus(self, "CHANTING") then ExecuteAction("DISPLAY_TEXT", "CHANTING") end
	if ObjectHasStatus(self, "ENRAGED") then ExecuteAction("DISPLAY_TEXT", "ENRAGED") end
	if ObjectHasStatus(self, "CREATE_DRAWABLE_WITH_LOW_DETAIL") then ExecuteAction("DISPLAY_TEXT", "CREATE_DRAWABLE_WITH_LOW_DETAIL") end
	if ObjectHasStatus(self, "SINKING") then ExecuteAction("DISPLAY_TEXT", "SINKING") end
	if ObjectHasStatus(self, "RAMPAGING") then ExecuteAction("DISPLAY_TEXT", "RAMPAGING") end
	if ObjectHasStatus(self, "INSIDE_GARRISON") then ExecuteAction("DISPLAY_TEXT", "INSIDE_GARRISON") end
	if ObjectHasStatus(self, "DEPLOYED") then ExecuteAction("DISPLAY_TEXT", "DEPLOYED") end
	if ObjectHasStatus(self, "UNATTACKABLE") then ExecuteAction("DISPLAY_TEXT", "UNATTACKABLE") end
	if ObjectHasStatus(self, "ENCLOSED") then ExecuteAction("DISPLAY_TEXT", "ENCLOSED") end
	if ObjectHasStatus(self, "TEMPORARILY_DEFECTED") then ExecuteAction("DISPLAY_TEXT", "TEMPORARILY_DEFECTED") end
	if ObjectHasStatus(self, "TAGGED") then ExecuteAction("DISPLAY_TEXT", "TAGGED") end
	if ObjectHasStatus(self, "DEPLOYING") then ExecuteAction("DISPLAY_TEXT", "DEPLOYING") end
	if ObjectHasStatus(self, "BLOODTHIRSTY") then ExecuteAction("DISPLAY_TEXT", "BLOODTHIRSTY") end
	if ObjectHasStatus(self, "PORTER_TAGGED") then ExecuteAction("DISPLAY_TEXT", "PORTER_TAGGED") end
	if ObjectHasStatus(self, "GRAB_AND_DROP") then ExecuteAction("DISPLAY_TEXT", "GRAB_AND_DROP") end
	if ObjectHasStatus(self, "STAND_GROUND") then ExecuteAction("DISPLAY_TEXT", "STAND_GROUND") end
	if ObjectHasStatus(self, "UNCONTROLLABLY_SCARED") then ExecuteAction("DISPLAY_TEXT", "UNCONTROLLABLY_SCARED") end
	if ObjectHasStatus(self, "SPECIAL_ABILITY_PACKING_UNPACKING") then ExecuteAction("DISPLAY_TEXT", "SPECIAL_ABILITY_PACKING_UNPACKING") end
	if ObjectHasStatus(self, "PLEASE_EAT_ME") then ExecuteAction("DISPLAY_TEXT", "PLEASE_EAT_ME") end
	if ObjectHasStatus(self, "UPDATING_AI") then ExecuteAction("DISPLAY_TEXT", "UPDATING_AI") end
	if ObjectHasStatus(self, "HUNT_WHEN_IDLE") then ExecuteAction("DISPLAY_TEXT", "HUNT_WHEN_IDLE") end
	if ObjectHasStatus(self, "IGNORE_AI_COMMAND") then ExecuteAction("DISPLAY_TEXT", "IGNORE_AI_COMMAND") end
	if ObjectHasStatus(self, "RUNNING_DOWN_FROM_BEHIND") then ExecuteAction("DISPLAY_TEXT", "RUNNING_DOWN_FROM_BEHIND") end
	if ObjectHasStatus(self, "DO_NOT_SCORE") then ExecuteAction("DISPLAY_TEXT", "DO_NOT_SCORE") end
	if ObjectHasStatus(self, "CAN_NOT_WALK_ON") then ExecuteAction("DISPLAY_TEXT", "CAN_NOT_WALK_ON") end
	if ObjectHasStatus(self, "MARCH_OF_DEATH") then ExecuteAction("DISPLAY_TEXT", "MARCH_OF_DEATH") end
	if ObjectHasStatus(self, "DO_NOT_PICK_ME") then ExecuteAction("DISPLAY_TEXT", "DO_NOT_PICK_ME") end
	if ObjectHasStatus(self, "INHERITED_FROM_ALLY_TEAM") then ExecuteAction("DISPLAY_TEXT", "INHERITED_FROM_ALLY_TEAM") end
	if ObjectHasStatus(self, "SWITCHED_WEAPONS") then ExecuteAction("DISPLAY_TEXT", "SWITCHED_WEAPONS") end
	if ObjectHasStatus(self, "END_FIRE_STATE") then ExecuteAction("DISPLAY_TEXT", "END_FIRE_STATE") end
	if ObjectHasStatus(self, "BOOKENDING") then ExecuteAction("DISPLAY_TEXT", "BOOKENDING") end
	if ObjectHasStatus(self, "ELVISH_EXPRESSLY") then ExecuteAction("DISPLAY_TEXT", "ELVISH_EXPRESSLY") end
	if ObjectHasStatus(self, "INSIDE_CASTLE") then ExecuteAction("DISPLAY_TEXT", "INSIDE_CASTLE") end
	if ObjectHasStatus(self, "BUILD_BEING_CANCELED") then ExecuteAction("DISPLAY_TEXT", "BUILD_BEING_CANCELED") end
	if ObjectHasStatus(self, "PENDING_CONSTRUCTION") then ExecuteAction("DISPLAY_TEXT", "PENDING_CONSTRUCTION") end
	if ObjectHasStatus(self, "PHANTOM_STRUCTURE") then ExecuteAction("DISPLAY_TEXT", "PHANTOM_STRUCTURE") end
	if ObjectHasStatus(self, "IN_FORMATION_TEMPLATE") then ExecuteAction("DISPLAY_TEXT", "IN_FORMATION_TEMPLATE") end
	if ObjectHasStatus(self, "IS_LEAVING_FACTORY") then ExecuteAction("DISPLAY_TEXT", "IS_LEAVING_FACTORY") end
	if ObjectHasStatus(self, "MOVING_TO_DISMOUNT") then ExecuteAction("DISPLAY_TEXT", "MOVING_TO_DISMOUNT") end
	if ObjectHasStatus(self, "MOVING_TO_DISMOUNT") then ExecuteAction("DISPLAY_TEXT", "MOVING_TO_DISMOUNT") end
	if ObjectHasStatus(self, "NO_HERO_PROPERTIES") then ExecuteAction("DISPLAY_TEXT", "NO_HERO_PROPERTIES") end
	if ObjectHasStatus(self, "CAN_ENTER_ANYTHING") then ExecuteAction("DISPLAY_TEXT", "CAN_ENTER_ANYTHING") end
	if ObjectHasStatus(self, "HOLDING_THE_RING") then ExecuteAction("DISPLAY_TEXT", "HOLDING_THE_RING") end
	if ObjectHasStatus(self, "INVISIBLE_DETECTED_BY_FRIEND") then ExecuteAction("DISPLAY_TEXT", "INVISIBLE_DETECTED_BY_FRIEND") end
	if ObjectHasStatus(self, "INVISIBLE_DETECTED") then ExecuteAction("DISPLAY_TEXT", "INVISIBLE_DETECTED") end
	if ObjectHasStatus(self, "WORKER_REPAIRING") then ExecuteAction("DISPLAY_TEXT", "WORKER_REPAIRING") end
	if ObjectHasStatus(self, "ATTACHED") then ExecuteAction("DISPLAY_TEXT", "ATTACHED") end
	if ObjectHasStatus(self, "WONT_RIDE_WITH_YOU") then ExecuteAction("DISPLAY_TEXT", "WONT_RIDE_WITH_YOU") end
	if ObjectHasStatus(self, "COMMAND_BUTTON_TOGGLED") then ExecuteAction("DISPLAY_TEXT", "COMMAND_BUTTON_TOGGLED") end
	if ObjectHasStatus(self, "IGNORE_PARALYZE_NUGGET") then ExecuteAction("DISPLAY_TEXT", "IGNORE_PARALYZE_NUGGET") end
	if ObjectHasStatus(self, "SUMMONING_REPLACEMENT") then ExecuteAction("DISPLAY_TEXT", "SUMMONING_REPLACEMENT") end
	if ObjectHasStatus(self, "HOLDING_THE_SHARD") then ExecuteAction("DISPLAY_TEXT", "HOLDING_THE_SHARD") end
	if ObjectHasStatus(self, "USER_DEFINED_1") then ExecuteAction("DISPLAY_TEXT", "USER_DEFINED_1") end
	if ObjectHasStatus(self, "USER_DEFINED_2") then ExecuteAction("DISPLAY_TEXT", "USER_DEFINED_2") end
end

--  Usage example:
-- 	local player = GetScriptTeamName(self)
--	local hero_count = CountTeamsKindOf(player, "HERO")

function CountTeamsKindOf(player, kindof)
	for i=1,100,1 do	
		if not EvaluateCondition("TEAM_HAS_FEWER_THAN_X_UNITS_WITH_KINDOF", player, i, KindOfTable[kindof]) then
			return i
		end
	end
	return 0
end

function SetModelCondition(self, modelCondition, duration)
	-- a shorter version of the built in function, added for convenience
	-- Usage Example: SetModelCondition(self, "RIDER1", 1)
	ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, modelCondition, duration,100) 
end

---
-- GetScriptTeamName()
-- Converts a plain team name to the format used by map scripts and ExecuteAction
-- Example input: teamPlayer_1
-- Example output: Player_1/teamPlayer_1
--
function GetScriptTeamName(obj)
	return gsub(ObjectTeamName(obj),"team","") .. "/" .. ObjectTeamName(obj)
end

---
-- TransferObjectToOtherObjectTeam()
-- Transfers obj to the team of obj2
--
function TransferObjectToOtherObjectTeam(obj, obj2)
	if verbosity == 1 then 
		ExecuteAction("DISPLAY_TEXT", "Transferring shadow from " .. GetScriptTeamName(obj) .. " to " .. GetScriptTeamName(obj2)) 
	end

    ExecuteAction("UNIT_SET_TEAM", obj, GetScriptTeamName(obj2))
end

---
-- InitializeQueue() - AddToQueue() - QueuePop() - QueueIsEmpty()
-- Implements a simple FIFO queue (First-In-First-Out)
--
function InitializeQueue()
	return {first = 0, last = -1}
end
function AddToQueue(queue, value)
	local last = queue.last + 1
	queue.last = last
	queue[last] = value
end
function QueuePop(queue)
	if queue == nil or queue.first > queue.last then 
		return nil  -- Return nil if queue is uninitialized or empty
	end
	local first = queue.first
	local value = queue[first]
	queue[first] = nil        -- to allow garbage collection
	queue.first = first + 1
	if value == nil then
		return QueuePop(queue)
	end
	return value
end
function QueueIsEmpty(queue)
	if queue == nil then
		InitializeQueue(queue)
		return true
	end
	if queue.first > queue.last then 
		return true
	end
	return false
end

---
-- Cleans a queue of leading nil objectss
--
function CleanQueue(queue)
	if QueueIsEmpty(queue) then return end

	local howManyLeadingNils = 0
	for i = queue.first, queue.last do 
		if queue[i] == nil then
			howManyLeadingNils = howManyLeadingNils + 1
		else
			break
		end
	end
	queue.first = queue.first + howManyLeadingNils
end

function MakeVarLabel(prefix, suffix, obj)
	return prefix .. ObjectTeamName(obj) .. suffix
end

---
-- AddToGlobalQueue()
-- Wrapper that accesses a global queue,
-- and adds an element into it. 
--
function AddToGlobalQueue(queueLabel, obj)
	local queue = getglobal(queueLabel)

	if queue == nil then
		queue = InitializeQueue()
	end

	AddToQueue(queue, obj)
	setglobal(queueLabel, queue)
end

---
-- PopFromGlobalQueue()
-- Wrapper that accesses a global queue,
-- and retrieves + removes the oldest element from it. 
--
function PopFromGlobalQueue(fortFlagQueueLabel)
	local fortFlagQueue = getglobal(fortFlagQueueLabel)

	if fortFlagQueue ~= nil then
		local value = QueuePop(fortFlagQueue)
		setglobal(fortFlagQueueLabel, fortFlagQueue)
		return value
	end
	return nil
end

----------------------------------------------------------------------


-- define lua functions 
function NoOp(self, source)
end


function LuaTickerCreate(self)
	-- ObjectDoSpecialPower(self, "SpecialAbilityTickerTick")
end

function MarkTickerAsAI(self)
	if ObjectTestModelCondition(self, "USER_2") then
		ObjectGrantUpgrade(self, "Upgrade_IsPlayerAI")
	end
end

-- This function executes every so often in a MP game
-- You can add additional logic you wish to execute periodically here
function MinimizeTickers(self)
	-- ExecuteAction("DISPLAY_TEXT", "Inside Minimize tickers")

	local tickers = {}
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTemplateName(v) == "LuaTicker" then
			tinsert(tickers, v)
		end
	end

	local length = getn(tickers)
	if length == 0 then return end

	local keptOne = false
	for i = 1, length do
		if not keptOne then
			ExecuteAction("UNIT_SET_TEAM", tickers[i], "PlyrCivilian/teamPlyrCivilian")
			keptOne = true
		else
			ExecuteAction("NAMED_DELETE", tickers[i])
		end
	end
end

function EconomyStructuresTick(self)

	local length = getn(EcoStructuresTable)
	-- ExecuteAction("DISPLAY_TEXT", "Farms: " .. tostring(length))

	-- if length == 0 and getFrameNow() > 300 then
	-- 	RestoreEcoTrackingOnReload(self)
	-- end

	for i = length, 1, -1 do
		local structure = EcoStructuresTable[i].structure
		local entry = EcoStructuresTable[i]
		-- local desc = ObjectDescription(structure)
		-- ExecuteAction("DISPLAY_TEXT", "Desc: " .. tostring(desc))
		if strfind(ObjectDescription(structure), "<No Object>") then
			tremove(EcoStructuresTable, i)
		else
			local currentHP = GetHealth(structure)
			if entry.HP == nil then
				entry.HP = currentHP
			else
				if entry.HP > currentHP then
					OnEcoReceivedDamaged(structure)
				end
				entry.HP = currentHP 
				-- ExecuteAction("DISPLAY_TEXT", "HP: " .. tostring(entry.HP))
			end
			ApplyEcoStructureDamagedUpgrades(structure)
		end
	end
end

function RestoreEcoTrackingOnReload()
	
	local EcoList = {
		GondorFarm = true,
		ElvenMallornTree = true,
		HEElvenMallornTree = true, -- the High Elves faction
		DwarvenMineShaft = true,
		AngmarMill = true,
		IsengardFurnace = true,
		MordorSlaughterHouse = true,
		WildMineShaft = true,
	}

	for k, v in globals() do
		if strfind(k, "ObjID") then
			local name = ObjectTemplateName(v)
			if name and EcoList[name]
				and not ObjectTestModelCondition(v, "ACTIVELY_BEING_CONSTRUCTED") 
				and not ObjectTestModelCondition(v, "USER_66") then
					AddEcoStructureToTheTable(v)
			end
		end
	end
end

function TickerTock(self)
	FortressDiscountTick(self)
	TowerDiscountTick(self)
	EconomyStructuresTick(self)

end
function TickerFire(self)
	-- local team = ObjectTeamName(self)
	-- ExecuteAction("DISPLAY_TEXT", "Ticker Fired " .. tostring(team))
	if GameReloaded then ResumeTracking(); GameReloaded = false end
	FortressDiscountTick(self)
	TowerDiscountTick(self)
	IterateThroughWorkers()
	if beginFlierIteration then IterateThroughFliers() end

end

function IsPlayerAI(self)
	if ObjectHasUpgrade( self, "Upgrade_IsPlayerAI" ) == 1 then
		return true
	end
end

function kill(self) -- Kill unit self.
	ExecuteAction("NAMED_KILL", self)
end

function delete(self) -- delete self.
	ExecuteAction("NAMED_DELETE", self)
end

function deleteWorker(self) -- Delete unit self.
	if ObjectTestModelCondition(self, "ACTIVELY_CONSTRUCTING") or ObjectTestModelCondition(self, "MOVING") then
		ExecuteAction("NAMED_KILL", self)
	end
end

function deleteWorkerBackup(self)
	-- in case worker does not die when it is supposed due to some unforeseen transition
	if ObjectTestModelCondition(self, "RIDER8") and ObjectTestModelCondition(self, "ACTIVELY_CONSTRUCTING") then
		-- ExecuteAction("DISPLAY_TEXT", "Back up is called ")
		ExecuteAction("NAMED_KILL", self)
	end
end

function OnEcoReceivedDamaged(self)
	-- ExecuteAction("DISPLAY_TEXT", "Damage Received ")
	local no_repair_time = 20 -- seconds
	ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "RIDER8", no_repair_time,100) 
	ObjectGrantUpgrade( self, "Upgrade_StopRepair" )
end

function ReenableRepair(self)
	-- called when farm RIDER8 expires
	ObjectRemoveUpgrade( self, "Upgrade_StopRepair" )
end

function RadiatePhialFear( self )
	ObjectBroadcastEventToEnemies( self, "BeAfraidOfPhial", 75 )
end

function RadiateUncontrollableFear( self )
	ObjectBroadcastEventToEnemies( self, "BeUncontrollablyAfraid", 350 )
end

-- ;;,;;
function RadiateUncontrollableFearBoromir( self )
	ObjectBroadcastEventToEnemies( self, "BeUncontrollablyAfraid", 225 ) --300
end

function RadiateGateDamageFear(self)
	ObjectBroadcastEventToAllies(self, "BeAfraidOfGateDamaged", 200)
end

function RadiateBalrogFear(self)
	ObjectBroadcastEventToEnemies(self, "BeAfraidOfBalrog", 180)
end

function ForbidUnitCommands(self)
	ObjectForbidPlayerCommands( self, true )
end

function AllowUnitCommands(self)
	ObjectForbidPlayerCommands( self, false )
end

function OnPlayerDetectorCreated(self)
	playerCount = playerCount + 1
end

function OnPlayerDetectorDestroyed(self)

	if isNotLargeScaleFFA(self) then
		if playerCount > 7 then 
			ObjectGrantUpgrade( self, "Upgrade_is8Players" )
		elseif playerCount == 6 or playerCount == 7 then
			ObjectGrantUpgrade(self, "Upgrade_is6Players")
		end	
	end
end

function isNotLargeScaleFFA(self)
	return ObjectCountNearbyEnemies(self, 9999) <= 4
end

function OnDimmerCreated(self)
	-- 0,0,0 - almost no visible light, 0.5,0.5,0.5 - no change, anything over 0.5 adds more light --
	-- the last parameter is how fast it transitions to the terminal dim state. --
	-- if the dimmer is forced killed, the dimmerCount will briefly be "2", thus avoiding the need to undim and redim.--
	dimmerCount = dimmerCount + 1 -- 
	if dimmerCount == 1 then 
    	ExecuteAction("DIM_WORLD_LIGHTS",0.45,0.45,0.45,3)
	end	
end

function OnDimmerDestroyed(self)
   -- ExecuteAction("DIM_WORLD_LIGHTS",0.5,0.5,0.5,1) -- has a jarring abrupt transition --
   -- Runs with a 2s delay set by WeatherKiller. The dimmer count is 0 if the dimmer is allowed to time out naturally, --
   -- otherwise it will briefly be "2" when forced killed, then "1", thus skipping unnecessary lights restoration. --

   dimmerCount = dimmerCount - 1 --
	if dimmerCount == 0 then 
		ExecuteAction("RESTORE_WORLD_LIGHTS",3) -- the bigger the number the slower the transition
	end
end

function OnMumakilCreated(self)
	ObjectHideSubObjectPermanently( self, "Houda", true )
	ObjectHideSubObjectPermanently( self, "Houda01", true )
end

function OnTrollCreated(self)
	ObjectHideSubObjectPermanently( self, "Trunk01", true )
	-- ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" ) -- done via ini
end

function OnCreepTrollCreated(self)
	ObjectHideSubObjectPermanently( self, "Trunk01", true )
	ObjectHideSubObjectPermanently( self, "ROCK", true )
end

function OnCaptureFlagGenericEvent(self,data)
	local str = ObjectCapturingObjectPlayerSide(self)
	if str == nil then
		str = ObjectPlayerSide(self)
	end


	ObjectHideSubObjectPermanently( self, "FLAG_ISENGARD", true)
	ObjectHideSubObjectPermanently( self, "FLAG_MORDOR", true)
	ObjectHideSubObjectPermanently( self, "FLAG_WILD", true)
	ObjectHideSubObjectPermanently( self, "FLAG_MEN", true)
	ObjectHideSubObjectPermanently( self, "FLAG_ELVES", true)
	ObjectHideSubObjectPermanently( self, "FLAG_DWARVES", true)
	ObjectHideSubObjectPermanently( self, "FLAG_ANGMAR", true)

	if str == "Isengard" then
		ObjectHideSubObjectPermanently( self, "FLAG_ISENGARD", false)
	elseif str == "Mordor" then
		ObjectHideSubObjectPermanently( self, "FLAG_MORDOR", false)
	elseif str == "Men" then
		ObjectHideSubObjectPermanently( self, "FLAG_MEN", false)
	elseif str == "Arnor" then	-- Added for v2.3 ;;,;;
		ObjectHideSubObjectPermanently( self, "FLAG_MEN", false)
	elseif str == "Dwarves" then
		ObjectHideSubObjectPermanently( self, "FLAG_DWARVES", false)
	elseif str == "Elves" then
		ObjectHideSubObjectPermanently( self, "FLAG_ELVES", false)
	elseif str == "Wild" then
		ObjectHideSubObjectPermanently( self, "FLAG_WILD", false)
	elseif str == "Angmar" then
		ObjectHideSubObjectPermanently( self, "FLAG_ANGMAR", false)
	else
		ObjectHideSubObjectPermanently( self, "FLAG_NEUTRAL", false)
	end
end

function OnTrollGenericEvent(self,data)

	local str = tostring( data )

	if str == "show_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", false )
	elseif str == "hide_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", true )
	end
end

function OnEntCreated(self)
	--ObjectShowSubObjectPermanently( self, "ROCK", true )
	--ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" ) -- done via ini
end

function OnMountainGiantCreated(self)
	--ObjectHideSubObjectPermanently( self, "ROCK", true )
	--ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" ) -- done via ini
end

function OnMountainGiantGenericEvent(self, data)
	
	local str = tostring( data )

	if str == "show_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", false )
	elseif str == "hide_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", true )
	end
end

function GoIntoRampage(self)
	ObjectEnterRampageState(self)
		
	--Broadcast fear to surrounding unit(if we actually rampaged)
	if ObjectTestModelCondition(self, "WEAPONSET_RAMPAGE") then
		ObjectBroadcastEventToUnits(self, "BeAfraidOfRampage", 250)
	end
end

function MakeMeAlert(self)
	ObjectEnterAlertState(self)
end

function BeEnraged(self)
	--Broadcast enraged to surrounding units.
	ObjectBroadcastEventToAllies(self, "BeingEnraged", 500)
end

function BecomeEnraged(self)
	ObjectSetEnragedState(self, true)
end

function StopEnraged(self)
	ObjectSetEnragedState(self, false)
end

function BecomeUncontrollablyAfraid(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterUncontrollableCowerState(self, other)
end

function BecomeAfraidOfRampage(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self, other)
end

function BecomeAfraidOfBalrog(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self, other)
end

function RadiateTerror(self, other)
	ObjectBroadcastEventToEnemies(self, "BeTerrified", 180)
end
	
function RadiateTerrorEx(self, other, terrorRange)
	ObjectBroadcastEventToEnemies(self, "BeTerrified", terrorRange)
end

function BecomeTerrified(self, other)
	ObjectEnterRunAwayPanicState(self, other)
end

function BecomeAfraidOfGateDamaged(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self,other)
end


function ChantForUnit(self) -- Used by units to broadcast the chant event to their own side.
	ObjectBroadcastEventToAllies(self, "BeginChanting", 9999)
end

function StopChantForUnit(self) -- Used by units to stop the chant event to their own side.
	ObjectBroadcastEventToAllies(self, "StopChanting", 9999)
end

function BeginCheeringForGrond(self)
	ObjectSetChanting(self, true)
end

function StopCheeringForGrond(self)
	ObjectSetChanting(self, false)
end

function OnMordorArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "ARROWFIRE", true )
end

function OnMordorFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE2", true ) -- ;,;
	ObjectHideSubObjectPermanently( self, "FORGED_BLADES", true )
end

---
-- Every other newly created orc spawns a CP shadow.
-- That is, we distingiush between "odd" and "even" orcs.
-- odd orcs give 2CP and even orcs give 1CP -> resulting in 30CP per horde.
--
function OnMordorFighterCreatedMP(self)
	OnMordorFighterCreated(self)
	
	local oddEvenTrackerLabel = "OrcCreate202_" .. ObjectTeamName(self) .. "oddeven"
	local oddEvenTracker = getglobal(oddEvenTrackerLabel)

	if oddEvenTracker == nil then
		oddEvenTracker = 0
	end

	if oddEvenTracker == 1 then
		ObjectGrantUpgrade(self, "Upgrade_TriggerOrcCPShadow")
		setglobal(oddEvenTrackerLabel, 0)

		local orcListLabel = "OrcCreate202_" .. ObjectTeamName(self) .. "recorc"
		local orcList = getglobal(orcListLabel)
		if orcList == nil then
			orcList = InitializeQueue()
		end

		AddToQueue(orcList, self)
		setglobal(orcListLabel, orcList)
	else
		setglobal(oddEvenTrackerLabel, 1)
	end
end

---
-- When a CP shadow is created, it finds out which orc created it and attaches itself.
-- This allows the orc to command its shadow (if it exists) to perform actions, for instance self destruct.
--
function MordorFighterCPShadowCreated(self)
	local orcListLabel = "OrcCreate202_" .. ObjectTeamName(self) .. "recorc"
	local orcList = getglobal(orcListLabel)

	if orcList ~= nil then
		local value = QueuePop(orcList)

		local objstr = GetObjString(ObjectDescription(value))
		local foundobj = getglobal(objstr)

		if foundobj ~= nil then
			if verbosity == 1 then ExecuteAction("DISPLAY_TEXT", "Attached shadow to " .. ObjectDescription(foundobj)) end
			foundobj["cpShadow"] = self
			setglobal(objstr, foundobj)
		end

		setglobal(orcListLabel, orcList)
	end
end

function OrcConvertCpShadow(obj)
	local myCpShadow = obj["cpShadow"]
	if myCpShadow ~= nil then
		TransferObjectToOtherObjectTeam(myCpShadow, obj)
	end
end

function SarumanCastedDominate(self)
	-- also convert CP shadow for all allied orcs and goblins
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTeamName(self) == ObjectTeamName(v) and 
		   (ObjectTemplateName(v) == "MordorFighter" or ObjectTemplateName(v) == "GoblinFighter") then
			OrcConvertCpShadow(v)
		end
	end
end

function OnCreepLairEnemyNear(self)
	ObjectGrantUpgrade( self, "Upgrade_MiniHordeLvl2" )
end 

function OnCreepLairEnemyNotNear(self)
	ObjectRemoveUpgrade( self, "Upgrade_MiniHordeLvl2" )
end 

function ForceCaveTrollReturn(self)

    --evoked when the neutral cave troll lair is surrounded by enemies
    --check if the troll is moving, instead of attacking - an indication of abuse
    --randomize his ability to go back to the lair so it is not predictable when he'd go back
    --randomization occurs every 4 seconds. On a given 4-second period of time, he has 50% chance of coming back.
    --the return is conducted by making him weaponless for 2s and ordering him to stop briefly
	local chanceOfReturn = 50 
    local isMoving = ObjectTestModelCondition(self, "MOVING")
    local mayReturn = IsAllowedToReturn(self, chanceOfReturn)

    if isMoving and mayReturn then 
        ObjectGrantUpgrade( self, "Upgrade_MiniHordeLvl2" ) -- activates an ini module
        ExecuteAction("NAMED_STOP", self) -- reset aggro while weaponless
    end
end

function IsAllowedToReturn(self, chance)
-- check if Troll is close to the lair
-- if not too close, generate a number from 0 to 1
-- compare it to chance and return true or false
    local isCloseToLair = ObjectTestModelCondition(self, "USER_69")
    if ( not isCloseToLair )  then
        return GetRandomNumber() <= chance/100 
	end
	return false 
end

function ReEnableCaveTrollReturn(self)
	ObjectRemoveUpgrade( self, "Upgrade_MiniHordeLvl2" ) -- deactivates an ini module
end

function MordorFighterBecomeUncontrollablyAfraid(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "MordorFighterEntFear") 
	end
end

function MordorFighterBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)
	-- BecomeAfraidOfTroll(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
--		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
--			ObjectPlaySound(self, "MordorFighterEntFear") 
--		end
end

function OnMordorCorsairCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Forged_Blade01", true )
end

function WildInfantryBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")
	BecomeUncontrollablyAfraid(self,other)
end


function ShelobBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)
	-- BecomeAfraidOfTroll(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
--		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
--			ObjectPlaySound(self, "MordorFighterEntFear") 
--		end
end

function OnInfantryBannerCreated(self)
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnCavalryCreated(self)
	ObjectHideSubObjectPermanently( self, "Glow", true )
	ObjectHideSubObjectPermanently( self, "Glow1", true ) --;,;
end

function OnGondorFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Hammer1", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
	ObjectHideSubObjectPermanently( self, "Glow1", true )
end

function OnAragornCreated(self)
	OnGenericHeroCreated(self)
	ObjectHideSubObjectPermanently( self, "PLANE02", true )
end

function OnGondorArcherCreated(self)
	-- ObjectHideSubObjectPermanently( self, "arrow", true )		-- This gets hidden pending the art being fixed.  it is the pre-new-archer-firing-pattern arrow
	ObjectHideSubObjectPermanently( self, "FireArowTip", true ) -- This gets hidden because the Fire Arrow upgrade turns it on.
end

function DragonStrikeDragonCreated(self)
	ObjectForbidPlayerCommands( self, true )
end

function OnTreeBeardCreated(self)
	OnMiniHeroHordeCreated(self)
end

function SetAbilitiesTreebeardTime(self)
	SetModelCondition(self, "RIDER8", 1)
	SetAbilitiesTime(self)
end

function OnTreeBeardLeveled(self)
	SetAbilitiesTime(self)
	OnMiniHeroHordeLeveled(self)
end

function OnLegolasCreated(self)
	OnGenericHeroCreated(self)
	ManipulateAutoAttacks(self)
end

function OnLegolasWeaponToggle(self)
	OnWeaponToggle(self)
	ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end

function OffLegolasWeaponToggle(self)
	OffWeaponToggle(self)
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end

function OnHaldirCreated(self)
	OnGenericHeroCreated(self)
	OffHaldirWeaponToggle(self)
	ManipulateAutoAttacksHaldir(self)
end

function GetHeroName(self)
	-- Changes in mounted template equal new object name
	-- Fliers cannot call their own functions using model conditions
	-- Therefore, we need to standardize the name no matter what calls the functions
	local name = ObjectTemplateName(self)
	if name == "MordorWitchKingOnFellBeast" or name == "MordorWitchKing_DeathShadow" then
		return "MordorWitchKing"
	elseif name == "KhamulFellBeast" or name == "Khamul_DeathShadow" then
		return "KhamulMounted"
	elseif name == "MorgomirFellBeast" or name == "MordorMorgromir_DeathShadow" then
		return "MordorMorgromirMounted"
	elseif name == "Drogoth_DeathShadow" then
		return "Drogoth"
	end
	return name
end

function removeExpiredAbilities(self, frame)
	-- If a hero is alive and the current logic frame is higher than ability recharge frame,
	-- Delete the abilities, as you loop backwards to avoid undesirable shifts

    local length = getn(heroPowers)

    if length == 0 then return end

    for i = length, 1, -1 do -- Iterate backward
        local power = heroPowers[i]
        if power.finish_frame <= frame and power.isHeroAlive == true then
			-- ExecuteAction("DISPLAY_TEXT", "Clear: " .. tostring(power.abilityName))
            tremove(heroPowers, i) -- Use tremove to maintain sequence integrity
        end
    end
end

function StoreUsedAbility(self, ability, startTime, finishTime)

	local playerName = ObjectTeamName(self) -- "teamPlayer_3" -- 
	local heroName = GetHeroName(self) -- ObjectTemplateName(self)
	local current_frame = getFrameNow()
	local recharged_frame = current_frame + finishTime*5

	removeExpiredAbilities(self, current_frame)

	local length = getn(heroPowers) -- length
	-- ExecuteAction("DISPLAY_TEXT", "Number of Stored Abilities: " .. tostring(length))

	tinsert(heroPowers, {
		player = playerName,
		hero = heroName,
		isHeroAlive = true,
		abilityName = ability,
		start_frame = current_frame,
		finish_frame = recharged_frame,
		death_frame = nil,
		hero_reference = GetUnitReference(self),
	})

end

function OnDualWeaponHeroCreated(self)
	OnGenericHeroCreated(self)
	ManipulateAutoAttacks(self)
end

function OnFlierHeroCreated(self)
	OnGenericHeroCreated(self)
	ObjectGrantUpgrade(self, "Upgrade_ObjectLevel1") -- triggers a shadow the calls the needed lua functions

	tinsert(FlierTable, {
		flier = self,
	})

	if not beginFlierIteration then
    	beginFlierIteration = true
	end
end

function OnGenericHeroCreated(self)
	SetModelCondition(self, "RIDER8", 1) -- helps distinguish respawned heroes
	SetModelCondition(self, "RIDERLESS", 0.2) 
	-- Timer refresh (SetAbilitiesTime) is actually triggered by LEVELED model condiition which is granted by the RespawnBody
	-- AddToHeroTeamsTable(self) -- now added with a delay
    -- ExecuteAction("DISPLAY_TEXT", "Team: " .. tostring(ObjectTeamName(self)))
end

function IterateThroughFliers()
		for i = getn(FlierTable), 1, -1 do
		local flier = FlierTable[i].flier
		if strfind(ObjectDescription(flier), "<No Object>") then
			if FlierTable[i].name ~= "ElvenFortressEagle" then
				tremove(FlierTable, i)
			end
		else
			if ObjectTestModelCondition(flier, "LEVELED") then
				if FlierTable[i].name ~= "ElvenFortressEagle" then
					SetAbilitiesTime(flier)
				else
					if GetUnitReference(flier) == FlierTable[i].id then
						FlierTable[i].level = GetUnitLevel(flier)
					end
				end
			end
		end
	end	
end

function SetFlierAbilities(self)
	-- ExecuteAction("DISPLAY_TEXT", "Flier Helper Shadow Created")
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTeamName(self) == ObjectTeamName(v) and 
		(ObjectTemplateName(v) == "Drogoth" or strfind(ObjectTemplateName(v), "FellBeast")) then
		
			if ObjectTestModelCondition(v, "RIDER6") then
				OnAbilitiesRefreshed(v)
			else
				OnAbilityTriggered(v)
				SetAbilitiesTime(v) --
			end
		end
	end
end

function OnFlierCursed(self)
	-- local name = GetHeroName(self) -- ObjectTemplateName(v)
	-- ExecuteAction("DISPLAY_TEXT", "Cursed called ")
	-- ExecuteAction("DISPLAY_TEXT", "created")
	for k, v in globals() do

		if strfind(k, "ObjID") and ObjectTemplateName(v) == "Drogoth" then		
			if ObjectTestModelCondition(v, "RIDER7") then
				OnAbilitiesCursed(v)
			end
		end
		if strfind(k, "ObjID") and 
		(ObjectTemplateName(v) == "MordorWitchKingOnFellBeast" or 
		ObjectTemplateName(v) == "MorgomirFellBeast" or 
		ObjectTemplateName(v) == "KhamulFellBeast")  then
			if ObjectTestModelCondition(v, "RIDER7") then
				OnAbilitiesCursed(v)
			end
		end
	end
end

function OnNazgulDismounted(self)
	-- calls  SetAbilitiesTime(self) with a tiny delay to set timers
	ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "LEVELED",3,100)
end

function OnAbilityTriggered(self)
	-- This function is called via model conditions when any hero ability is triggered
	-- RIDER1-RIDER5 corresponds to the abilities having a specific order in heroAbilityList
	-- We loop through all abilities that a hero has and store the right one in heroPowers table 
	local name = GetHeroName(self) -- ObjectTemplateName(self)
	-- Only continue if the hero is in the list
	if heroAbilityList[name] then
		-- there are only up to 5 abilities per hero
		for rider = 1, 5 do
			-- Check if the hero has an ability for the current rider
			if heroAbilityList[name][rider] then
				if ObjectTestModelCondition(self, "RIDER" .. rider) then
					local ability = heroAbilityList[name][rider].ability
					local offset = RechargeFaster(self, name, rider) -- used for Gandalf the White
					local cooldown = heroAbilityList[name][rider].cooldown - offset
					-- ExecuteAction("DISPLAY_TEXT", "Rider " .. rider .. " Ability: " .. tostring(ability) .. " Cooldown: " .. tostring(cooldown))
					StoreUsedAbility(self, ability, 1, cooldown)
				end
			end
		end
	else
		-- ExecuteAction("DISPLAY_TEXT", "Hero not found:" .. tostring(name))
	end
end

function RechargeFaster(self, name, rider)
	--USER_2 = Gandalf is white, so we need to recharge abilities by 25% faster
	if name == "GondorGandalf" and ObjectTestModelCondition(self, "USER_2") then
		local reduce_by_seconds = heroAbilityList[name][rider].cooldown / 4
		return floor(reduce_by_seconds)
	end
	return 0
end

function OnRefreshShadowCreated(self)
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTeamName(self) == ObjectTeamName(v) and (ObjectTemplateName(v) == "ElvenElrond" or ObjectTemplateName(v) == "HEElvenElrond") then
			if ObjectTestModelCondition(v, "RIDER4") then
				local ElrondLevel = GetUnitLevel(v)
				if ElrondLevel >= 8 then
					ObjectGrantUpgrade(self, "Upgrade_ObjectLevel8")
				else
					ObjectGrantUpgrade(self, "Upgrade_ObjectLevel5")
				end
			end
		end
	end
end

function OnAbilitiesRefreshed(self)
	-- Elrond restored my abilities
	-- ExecuteAction("DISPLAY_TEXT", "Abilities refreshed ")
	local seconds_to_refresh = 60 -- How many seconds Elrond expedites ability refresh by
	if ObjectTestModelCondition(self, "DRILL0") then seconds_to_refresh = 120 end

	local tick_rate = 5 -- just a small buffer of 1 second
	local frames_to_refresh = seconds_to_refresh * tick_rate -- convert into logic frames
	local current_frame = getFrameNow()
	removeExpiredAbilities(self, current_frame)
	local length = getn(heroPowers)
	local heroName = GetHeroName(self) -- ObjectTemplateName(self)
	local playerName = ObjectTeamName(self)
	local isRefreshed = ObjectTestModelCondition(self, "RIDER6")
	local heroReference = GetUnitReference(self)

	if length > 0 then
		for i = 1, length do
			local power = heroPowers[i]
			if power.player == playerName and power.hero == heroName and power.hero_reference == heroReference then
				if isRefreshed then
					--heroPowers[i].finish_frame = getFrameNow()
					local frames_left = power.finish_frame - current_frame
					if frames_left > tick_rate then
						if frames_left < frames_to_refresh then
							heroPowers[i].finish_frame = heroPowers[i].finish_frame - frames_left + tick_rate -- 
						else
							heroPowers[i].finish_frame = heroPowers[i].finish_frame - frames_to_refresh + tick_rate -- 
						end
					end
					local powerName = power.abilityName
					-- ExecuteAction("DISPLAY_TEXT", "Refreshed: " .. tostring(powerName))
				end
			end
		end
	end
	SetAbilitiesTime(self)
end

function OnAbilitiesCursed(self)

	local name = GetHeroName(self) -- ObjectTemplateName(self)
	-- Only continue if the hero is in the list
	if heroAbilityList[name] then
		-- there are only up to 5 abilities per hero
		for i = 1, 5 do
			if heroAbilityList[name][i] then
				local ability = heroAbilityList[name][i].ability
				local cooldown = heroAbilityList[name][i].cooldown
				-- ExecuteAction("DISPLAY_TEXT", "Ability: " .. tostring(ability) .. " Cooldown: " .. tostring(cooldown))
				StoreUsedAbility(self, ability, 1, cooldown)
			end
		end
	else
		-- ExecuteAction("DISPLAY_TEXT", "Hero not found.")
	end
	-- ExecuteAction("UNIT_SET_TEAM", self, "Player_3/teamPlayer_3") -- for tests
end

function SetAbilitiesTime(self)
	-- used when hero is respawned
	-- used when hero levels up
	-- clears out the storage table from expired abilities
	-- standardizes fell beast references (cannot have multiple identical FBs like two Khamuls) 
	-- adds extra calculations to immitate a slower recharge speed for dead heroes
	-- rolls back the timers to the correct position

	local playerName = ObjectTeamName(self)
    local heroName = GetHeroName(self) -- ObjectTemplateName(self)
	local frame = getFrameNow()
	local heroReference = GetUnitReference(self)
	removeExpiredAbilities(self, frame)
	local length = getn(heroPowers) -- length after removal function is run before
	SynchFellBeastReferences(self, length, playerName, heroName, heroReference)
	SetCooldownSpeedWhileDead(self, length, frame, playerName, heroName, heroReference) -- only actually used when hero is respawned

	-- ExecuteAction("DISPLAY_TEXT", "Name: " .. tostring(heroName)) -- evaluates to nil, need a delay

	for i = 1, length do
		local power = heroPowers[i]
			if power ~= nil and power.player == playerName and power.hero == heroName and power.hero_reference == heroReference then
				local roll_back_by_seconds = (power.finish_frame - frame)/5
				if roll_back_by_seconds > 0 then
					roll_back_by_seconds = ceil(roll_back_by_seconds)
					ExecuteAction("NAMED_SET_SPECIAL_POWER_COUNTDOWN", self, power.abilityName, roll_back_by_seconds)
					-- ExecuteAction("DISPLAY_TEXT", "Rollback: " .. tostring(power.abilityName) .. " Cooldown: " .. tostring(roll_back_by_seconds))
				end
			end
	end
	-- ExecuteAction("DISPLAY_TEXT", "Leveled ")
end

function SynchFellBeastReferences(self, length, playerName, heroName, heroReference)
	-- Every time a Nazgul dismounts and mounts, he is a new object
	-- Thus, we change the references of the used abilities to the current one

	if heroName == "MordorWitchKing" or heroName == "KhamulMounted" or heroName == "MordorMorgromirMounted" then
		
		for i = 1, length do
			local power = heroPowers[i]
			if power ~= nil and power.player == playerName and power.hero == heroName then
				power.hero_reference = heroReference -- update references on mounting/dismounting
			end
		end
	end
end

function SetCooldownSpeedWhileDead(self, length, frame, playerName, heroName, heroReference)
	-- loop over all powers. 
	-- Identify my hero, make sure he has the correct level and is dead
	-- In case we have multiple identical dead heroes at the same level, 
	-- Get the first reference and manipulate values with the same reference.
	-- 0 is stopped, 50 is half as fast, 100 is normal. 
	-- Do not exceed 100 without handling accelerated cooldown case. 

	local recharge_speed_when_dead = 100 -- 0 -- 

	if ObjectTestModelCondition(self, "RIDER8") then
		local heroLevel = GetUnitLevel(self) 
		local firstHeroReference = nil
		-- Loop through all used powers
		for i = 1, length do
			local power = heroPowers[i]
			-- Check if the power corresponds to the current player and hero
			if power.player == playerName and power.hero == heroName and power.level == heroLevel and power.isHeroAlive == false then
				
				if firstHeroReference == nil then
                    firstHeroReference = power.hero_reference
                end

				if firstHeroReference == power.hero_reference then
					local recharged_before_death = power.death_frame - power.start_frame
					local frame_at_respawn = frame
					local recharged_after_death = (frame_at_respawn - power.death_frame) * (recharge_speed_when_dead / 100)
					local total_recharged = recharged_before_death + floor(recharged_after_death) 
					local left_to_recharge = power.finish_frame - power.start_frame - total_recharged 
					power.isHeroAlive = true
					power.death_frame = nil
					heroPowers[i].level = nil
					heroPowers[i].hero_reference = heroReference
					if left_to_recharge > 0 then 
						power.finish_frame = frame_at_respawn + left_to_recharge 
					end		
				end
			end
		end
	end
end

function OnFlierHeroDeath(self)
	
	local name = ObjectTemplateName(self)
	-- ExecuteAction("DISPLAY_TEXT", "Flier Death Helper Shadow: " .. tostring(name))
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTeamName(self) == ObjectTeamName(v) and 
		(ObjectTemplateName(v) == "Drogoth" or strfind(ObjectTemplateName(v), "FellBeast")) then
			if ObjectTestModelCondition(v, "DYING") then
				OnGenericHeroDeath(v)
			end
		end
	end
	-- OnGenericHeroDeath(self) -- need to pass a different argument to get the right bird instead of self
end

function OnGenericHeroDeath(self)

	-- check if the hero is inhereted and if so - return nothing immediately
	-- 80 = INHERITED_FROM_ALLY_TEAM == can never be revived
	local heroReference = GetUnitReference(self)
	if EvaluateCondition("UNIT_HAS_OBJECT_STATUS", heroReference, 80) then
		OnAbilitiesRefreshed(self)
        return
    end

	-- not used unless we need to implement timer "freeze"
	local heroLevel = GetUnitLevel(self)
    local playerName = ObjectTeamName(self)
    local heroName = GetHeroName(self) -- ObjectTemplateName(self)
    local length = getn(heroPowers)

    -- Loop through all used powers
    for i = 1, length do
        local power = heroPowers[i]

        -- Check if the power corresponds to the current player and hero
        if power.player == playerName and power.hero == heroName and power.hero_reference == heroReference then
            -- Mark the hero as dead
            heroPowers[i].isHeroAlive = false
			heroPowers[i].death_frame = getFrameNow()
			-- heroPowers[i].hero_reference = nil -- the reference will be different on respawn
			heroPowers[i].level = heroLevel -- to match levels instead of reference
            -- Optionally, display the hero's death status
            -- ExecuteAction("DISPLAY_TEXT", heroName .. " alive? " .. tostring(power.isHeroAlive))
			-- ExecuteAction("DISPLAY_TEXT", " Death frame: " .. tostring(power.death_frame))
        end
    end
	PopFromHeroTeamsTable(self)
end

function OnGimliSlayer(self)
	if ObjectTestModelCondition(self, "RIDER6") or ObjectHasStatus(self, "TEMPORARILY_DEFECTED") then
		-- if Elrond Restoration is Active then it'll prevent clashing
		return
	end

	local playerName = ObjectTeamName(self)
    local heroName = GetHeroName(self) -- ObjectTemplateName(self)
	local heroReference = GetUnitReference(self) 
	local frame = getFrameNow()
	local length = getn(heroPowers)
	local recharge_speed = 1 -- 1 extra second of cooldown per second

	for i = 1, length do
		local power = heroPowers[i]
		if power ~= nil and power.player == playerName and power.hero == heroName and power.hero_reference == heroReference then
			-- Exclude Gimli's Hero Mode from rollback
			if power.abilityName ~= "SpecialAbilityGimliHeroMode" then
				local roll_back_by_seconds = (power.finish_frame - frame) / 5
				if roll_back_by_seconds > 0 then
					power.finish_frame = power.finish_frame - (recharge_speed * 5) -- Expedite cooldown
					roll_back_by_seconds = (power.finish_frame - frame) / 5
					roll_back_by_seconds = floor(roll_back_by_seconds)
					ExecuteAction("NAMED_SET_SPECIAL_POWER_COUNTDOWN", self, power.abilityName, roll_back_by_seconds)
				end
			end
		end
	end
end

function EnforceAllAbilityCountdowns(self)

	local playerName = ObjectTeamName(self)
    local heroName = GetHeroName(self) -- ObjectTemplateName(self)
	local heroReference = GetUnitReference(self) 
	local frame = getFrameNow()
	local length = getn(heroPowers)

	for i = 1, length do
		local power = heroPowers[i]
		if power ~= nil and power.player == playerName and power.hero == heroName and power.hero_reference == heroReference then
				local roll_back_by_seconds = (power.finish_frame - frame) / 5
				if roll_back_by_seconds > 0 then
					roll_back_by_seconds = (power.finish_frame - frame) / 5
					roll_back_by_seconds = floor(roll_back_by_seconds)
					ExecuteAction("NAMED_SET_SPECIAL_POWER_COUNTDOWN", self, power.abilityName, roll_back_by_seconds)
				else
					ExecuteAction("NAMED_SET_SPECIAL_POWER_COUNTDOWN", self, power.abilityName, 0)
				end
		end
	end
end

function OffGimliSlayer(self)
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end

function OnCavalaryNearMarauders(self)
	HordeBroadcastEventToMembers(self, "InitiateShadows")
end

function OnCavalaryNotNearMarauders(self)
	HordeBroadcastEventToMembers(self, "SwitchOffShadows")
end

-- shadows_created = 0

function OnInitiateShadows(self)
	ObjectGrantUpgrade(self, "Upgrade_TriggerOrcCPShadow")
end

function TurnOffShadows(self)
	ObjectRemoveUpgrade(self, "Upgrade_TriggerOrcCPShadow")
end

-- function OnCrushableShadowCreated(self)
-- 	shadows_created = shadows_created + 1
-- 	ExecuteAction("DISPLAY_TEXT", "Created shadows so far: " .. tostring(shadows_created))
-- end

function OnRohanArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FireArowTip", true ) -- yes, it's a typo in the art.
	-- ObjectHideSubObjectPermanently( self, "ArrowNock", true )
	-- ObjectHideSubObjectPermanently( self, "arrow", true )

end

-- function resetArcherCounter() 
-- 	if archerCounter > 9 then
-- 		archerCounter = 0
-- 	end
-- end

-- function isAllowedToShoot()
-- 	resetArcherCounter() 
-- 	archerCounter = archerCounter + 1
-- 	local num = archerCounter

-- 	if num == 1 or num == 3 or num == 5 or num == 7 or num == 9 then
-- 		-- ExecuteAction("DISPLAY_TEXT", "Msg: " .. archerCounter)
-- 		return true
-- 	end
-- end

-- function OnTowerEntry(self)
	
-- 	local allowed = isAllowedToShoot()

-- 	if allowed then 
-- 		if verbosity == 1 then ExecuteAction("DISPLAY_TEXT", "Allowed to shoot ") end
-- 		ToggleObjectStatus(self, "NO_ATTACK", false)
-- 	else
-- 		if verbosity == 1 then ExecuteAction("DISPLAY_TEXT", "Not allowed to shoot") end
-- 		ToggleObjectStatus(self, "NO_ATTACK", true)
-- 	end
-- end

-- function OnTowerExit(self)
-- 	ToggleObjectStatus(self, "NO_ATTACK", false)
-- end

function GondorFighterBecomeAfraid(self, other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	-- An object has a 100% chance to become afraid.
	-- An object has a 66% chance to be feared, 33% chance to run away.
	if GetRandomNumber() <= 0.67 then 
		ObjectEnterFearState(self, other, false) -- become afraid of other.
	else --if GetRandomNumber() > 0.67 then
		ObjectEnterRunAwayPanicState(self, other) -- run away.

	end
	
	if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "GondorSoldierScream")	
	end
	
end


function GondorFighterBecomeAfraidOfGateDamaged(self, other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeAfraidOfGateDamaged(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfGateDamaged may fail, don't play sound if we didn't enter fear state
	
	if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "GondorSoldierScream")	
	end
end

function GondorFighterRecoverFromTerror(self)
	-- Add recovery sound
	ObjectPlaySound(self, "GondorSoldierRecoverFromTerror")
end

function SpyMoving(self, other)
	print(ObjectDescription(self).." spying movement of "..ObjectDescription(other));
end

--function GandalfConsiderUsingDefensePower(self, other, delay, amount)
--	-- Put up the shield if a big attack is coming and we have time to block it
--	if tonumber(delay) > 1 then
--		if tonumber(amount) >= 100 then
--			ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
--			return
--		end
--	end
--	
--	-- Or, if we are being hit and there are alot of guys arround, do our cool pushback power
--	if tonumber(ObjectCountNearbyEnemies(self, 50)) >= 4 then
--		ObjectDoSpecialPower(self, "SpecialPowerTelekeneticPush")
--		return
--	end
--end

-- Added for 2.0 from DC patch ;;,;; ;,; Removed
--function GandalfUseDefensePower(self, other, delay, amount)
--  ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
--end

function GandalfTriggerWizardBlast(self)
	ObjectCreateAndFireTempWeapon(self, "GandalfWizardBlast")
end

--function SarumanConsiderUsingDefensePower(self, other, delay, amount)
--	-- Put up the shield if a big attack is coming and we have time to block it
--E4	if tonumber(delay) > 1 then
--E4		if tonumber(amount) >= 25 then
--E4			ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
--E4			return
--E4		end
--E4	end
--	
--	-- Or, if we are being hit and there are alot of guys arround, do our cool pushback power
--	if tonumber(ObjectCountNearbyEnemies(self, 50)) >= 4 then
--		ObjectDoSpecialPower(self, "SpecialPowerTelekeneticPush")
--		return
--	end
--end

function BalrogTriggerBreatheFire(self)
	ObjectCreateAndFireTempWeapon(self, "MordorBalrogBreath")
end

function OnRohirrimCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "SHIELD", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnSummonedRohirrimCreated(self)
	--ObjectGrantUpgrade( self, "Upgrade_RohanHeavyArmorForRohirrim" ) -- ;,;
	ObjectGrantUpgrade( self, "Upgrade_GondorHeavyArmor" ) -- ;,;
	ObjectGrantUpgrade( self, "Upgrade_RohanHorseShield" )
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true ) -- ;,;
end

function OnSummonedMenofDaleCreated(self) -- ;,;
	ObjectGrantUpgrade( self, "Upgrade_DwarvenMithrilMail" )
	ObjectGrantUpgrade( self, "Upgrade_DwarvenFireArrows" )
end

-- function OnBattlewagonMenofDaleCreated(self) -- ;,;
--    ObjectGrantUpgrade( self, "Upgrade_DwarvenMithrilMail" )
--	-- ObjectGrantUpgrade( self, "Upgrade_DwarvenFireArrows" )  ;,; disabled fire arrows for v8.0.0
--	ObjectHideSubObjectPermanently( self, "FireArowTip", false ) -- ;,;
--	ObjectHideSubObjectPermanently( self, "ARMOR", false ) -- ;,;
-- end

function isDamagedDuringConstruction(self) 

-- when the structure is complete, check if I am damaged during construction
-- damaged states are displayed correctly for a moment
-- check if we are briefly damage or really damaged
-- set transitional model conditions user_69 or user_68 to emulate damaged and really damaged respectively 
-- set a timer (via User_65 expiration)
-- engine clears real damaged/really damaged states
-- when user_65 expires, FixDamagedModelConditions(self) is called. 

	if ObjectTestModelCondition(self, "DAMAGED") then
		ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "USER_69",2,100) -- transitional "damaged" state
	elseif ObjectTestModelCondition(self, "REALLYDAMAGED") then
		ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "USER_68",2,100) -- transitional "really damaged" state
	end
	SetModelCondition(self, "USER_65", 1) -- 1s delay to fix damage model condition
	SetModelCondition(self, "USER_66", 3) -- 3s delay to add the building to the table
end

function FixDamagedModelConditions(self) 
	
	if ObjectTestModelCondition(self, "USER_69") then
		ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "DAMAGED",0,100)
	elseif ObjectTestModelCondition(self, "USER_68") then
		ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "REALLYDAMAGED",0,100)
	end
end

function AddEcoStructureToTheTable(self)
	tinsert(EcoStructuresTable, {
		structure = self,
	})
end

function OnEcoStructureDelayedComplete(self)
	-- track all eco structures in a table to minimize global loops
	AddEcoStructureToTheTable(self)
end

function ApplyEcoStructureDamagedUpgrades(self) -- ;,;

	-- ExecuteAction("DISPLAY_TEXT", "Is Eco Structure Damaged? ")
	
	if ObjectTestModelCondition(self, "DAMAGED") then
		ObjectGrantUpgrade( self, "Upgrade_Damaged" )
		ObjectRemoveUpgrade( self, "Upgrade_ReallyDamaged" )
	elseif ObjectTestModelCondition(self, "REALLYDAMAGED") then
		ObjectGrantUpgrade( self, "Upgrade_ReallyDamaged" )
		ObjectRemoveUpgrade( self, "Upgrade_Damaged" )
	else 
		ObjectRemoveUpgrade( self, "Upgrade_Damaged" )
		ObjectRemoveUpgrade( self, "Upgrade_ReallyDamaged" )
	end
end

function OnGondorCavalryCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "sshield", true )
end

function OnDwarvenBattleWagonCreated(self)
	ObjectHideSubObjectPermanently( self, "dwarfHearth", true )
	ObjectHideSubObjectPermanently( self, "dwarfHearthFire", true )
	ObjectHideSubObjectPermanently( self, "Banner_L", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnEvilMenBlackRiderCreated(self)
	-- @todo place appropriate functionality here
end

function OnBallistaCreated(self)
	ObjectHideSubObjectPermanently( self, "MinedArrow", true )
end

function OnCatapultCreated(self)
	ObjectHideSubObjectPermanently( self, "PROJECTILEROCK", true )
	ObjectHideSubObjectPermanently( self, "FIREPLANE", true )
end

function OnTrebuchetCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREPLANE", true )
end

function OnTrollSlingCreated(self)
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
end

function OnPorterCreated(self)
	ObjectHideSubObjectPermanently( self, "ARROWS", true )
	ObjectHideSubObjectPermanently( self, "BRAZIER", true )
	ObjectHideSubObjectPermanently( self, "BOWS", true )
	ObjectHideSubObjectPermanently( self, "TREBUCHET_FIRE", true )
	ObjectHideSubObjectPermanently( self, "SWORDS", true )
	ObjectHideSubObjectPermanently( self, "SHIELDS", true )
	ObjectHideSubObjectPermanently( self, "ARMOR", true )
	ObjectHideSubObjectPermanently( self, "BANNERS", true )
	ToggleObjectStatus(self, "UNATTACKABLE", false)
	-- ban extinguisher for 15s
	if GameReloaded then SetModelCondition(self, "RIDERLESS", 15) end
end

function OnEvilPorterCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "ARROW_UPGRADE", true )
	ObjectHideSubObjectPermanently( self, "ARMOR_UPGRADE", true )
	ObjectHideSubObjectPermanently( self, "GOLD", true )
	ObjectHideSubObjectPermanently( self, "SWORD_UPGRADES", true )
	ToggleObjectStatus(self, "UNATTACKABLE", false)
	-- ban extinguisher for 15s
	if GameReloaded then SetModelCondition(self, "RIDERLESS", 15) end
end

function OnBuilderUnattackable(self)  --;,;
    -- ExecuteAction("DISPLAY_TEXT", "Builder began construction " )
	if ObjectHasStatus(self, "NO_AUTO_ACQUIRE") then
		ToggleObjectStatus(self, "IMMOBILE", true)
		-- local side = ObjectPlayerSide(self)
		-- ExecuteAction("DISPLAY_TEXT", "Extinguish abuse by " .. tostring(side) )
	end
end

function OnBuilderAttackable(self)  --;,;
    -- ExecuteAction("DISPLAY_TEXT", "Builder finished construction " )
	ToggleObjectStatus(self, "IMMOBILE", false)
end

function OnPeasantCreated(self)
	ObjectHideSubObjectPermanently( self, "HELMET", true )
	ObjectHideSubObjectPermanently( self, "SWORD", true )
	ObjectHideSubObjectPermanently( self, "HAMMER", false )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "SHIELD", true )
	ObjectHideSubObjectPermanently( self, "Broom", true )
end

function OnMordorSauronCreated(self)
	ObjectHideSubObjectPermanently( self, "SHARD01", true )
	ObjectHideSubObjectPermanently( self, "SHARD02", true )
	ObjectHideSubObjectPermanently( self, "SHARD03", true )
	ObjectHideSubObjectPermanently( self, "SHARD04", true )
	ObjectHideSubObjectPermanently( self, "SHARD05", true )
	ObjectHideSubObjectPermanently( self, "SHARD06", true )
	ObjectHideSubObjectPermanently( self, "SHARD07", true )
	ObjectHideSubObjectPermanently( self, "SHARD08", true )
	ObjectHideSubObjectPermanently( self, "SHARD09", true )
	ObjectHideSubObjectPermanently( self, "SHARD10", true )
	ObjectHideSubObjectPermanently( self, "SHARD11", true )
	ObjectHideSubObjectPermanently( self, "SHARD12", true )
	ObjectHideSubObjectPermanently( self, "SHARD13", true )
	ObjectHideSubObjectPermanently( self, "SHARD14", true )
	ObjectHideSubObjectPermanently( self, "SHARD15", true )
	ObjectHideSubObjectPermanently( self, "SHARD16", true )
	ObjectHideSubObjectPermanently( self, "SHARD17", true )
	ObjectHideSubObjectPermanently( self, "SHARD18", true )
	ObjectHideSubObjectPermanently( self, "SHARD19", true )
	ObjectHideSubObjectPermanently( self, "SHARD20", true )
	-- ObjectDoSpecialPower( self, "SpecialAbilitySauronDarkness" ) -- ;,;
end

function OnElvenWarriorCreated(self)
	ObjectHideSubObject( self, "ARROW", true )
	ObjectHideSubObject( self, "ARROWNOCK", true )
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnIsengardFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnIsengardWildmanCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Torch", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnAngmarHillmanCreated(self) --;,;
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
        ObjectHideSubObjectPermanently( self, "WEAPON01", true )
        ObjectHideSubObjectPermanently( self, "WEAPON02", true )
        ObjectHideSubObjectPermanently( self, "WEAPON03", true )

        local WEAPON = GetRandomNumber()

        if WEAPON <= 0.33 then
            ObjectHideSubObjectPermanently( self, "WEAPON01", false )
        elseif WEAPON <= 0.66 then
            ObjectHideSubObjectPermanently( self, "WEAPON02", false )
        else
            ObjectHideSubObjectPermanently( self, "WEAPON03", false )
        end
end

function OnWildSpiderRiderCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
	ObjectHideSubObject( self, "ARROWNOCK", true )
end

function OnHaradrimArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
	ObjectHideSubObject( self, "ArrowNock", true )
end

function OnIsengardArcherCreated(self)
	ObjectHideSubObject( self, "ARROWNOCK", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnWildGoblinArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnGarrisonableCreated(self)
	ObjectHideSubObjectPermanently( self, "GARRISON01", true )
	ObjectHideSubObjectPermanently( self, "GARRISON02", true )
end
function OnDwarvenGuardianCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Hammer1", true )
end

function CreateAHeroHideEverything(self)
	ObjectHideSubObjectPermanently( self, "SWORD", true )
	ObjectHideSubObjectPermanently( self, "BOW", true )
	ObjectHideSubObjectPermanently( self, "BOW_03", true )
	ObjectHideSubObjectPermanently( self, "BOW_04", true )
	ObjectHideSubObjectPermanently( self, "BOW_05", true )
	ObjectHideSubObjectPermanently( self, "TRUNK01", true )
	ObjectHideSubObjectPermanently( self, "STAFF_LIGHT", true )
	ObjectHideSubObjectPermanently( self, "OBJECT01", true )
	
	ObjectHideSubObjectPermanently( self, "SHIELD01", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_01", true )
	ObjectHideSubObjectPermanently( self, "SPEAR", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_B", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_C", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_D", true )
	ObjectHideSubObjectPermanently( self, "B_SHIELD", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_A", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_B", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_C", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_D", true )
	
	ObjectHideSubObjectPermanently( self, "AXE02", true )

	ObjectHideSubObjectPermanently( self, "AxeWeapon", true )
	ObjectHideSubObjectPermanently( self, "Belthronding", true )
	-- ObjectHideSubObjectPermanently( self, "Mithlondrecurve", true )
	ObjectHideSubObjectPermanently( self, "Dwarf_Axe01", true )
	ObjectHideSubObjectPermanently( self, "FireBrand", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_SM", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_FX01", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_FX02", true )
	ObjectHideSubObjectPermanently( self, "Gurthang", true )
	ObjectHideSubObjectPermanently( self, "Gurthang_SM", true )
	ObjectHideSubObjectPermanently( self, "HeroOfTheWestShield", true )
	ObjectHideSubObjectPermanently( self, "HeroOfTheWestShield_SM", true )
	ObjectHideSubObjectPermanently( self, "MithlondBow", true )
	ObjectHideSubObjectPermanently( self, "TrollBane", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_SM", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_FX01", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_FX02", true )
	ObjectHideSubObjectPermanently( self, "TrollMace", true )
	ObjectHideSubObjectPermanently( self, "TrollSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword_SM", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX2", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX3", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX4", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff02", true )
	ObjectHideSubObjectPermanently( self, "WizStaff02_FX1", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff03", true )
	ObjectHideSubObjectPermanently( self, "WizStaff03_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff03_FX02", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff04", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX02", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX03", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX04", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX05", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX06", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX07", true )
	ObjectHideSubObjectPermanently( self, "WizardSword", true )
	ObjectHideSubObjectPermanently( self, "CMSword01", true )
	ObjectHideSubObjectPermanently( self, "CMSword02", true )
	ObjectHideSubObjectPermanently( self, "CHEST_00", true )	
	ObjectHideSubObjectPermanently( self, "CHEST_01", true )	
	ObjectHideSubObjectPermanently( self, "CHEST_02", true )	
	ObjectHideSubObjectPermanently( self, "BOOT_00", true )
	ObjectHideSubObjectPermanently( self, "BOOT_01", true )
	ObjectHideSubObjectPermanently( self, "BOOT_02", true )
	ObjectHideSubObjectPermanently( self, "BOOT_03", true )
	ObjectHideSubObjectPermanently( self, "BOOT_04", true )
	ObjectHideSubObjectPermanently( self, "BOOT_05", true )
	ObjectHideSubObjectPermanently( self, "BOOT_06", true )
	ObjectHideSubObjectPermanently( self, "SHLD_00", true )
	ObjectHideSubObjectPermanently( self, "SHLD_01", true )
	ObjectHideSubObjectPermanently( self, "SHLD_02", true )
	ObjectHideSubObjectPermanently( self, "SHLD_03", true )
	ObjectHideSubObjectPermanently( self, "SHLD_04", true )
	ObjectHideSubObjectPermanently( self, "SLDR_00", true )
	ObjectHideSubObjectPermanently( self, "SLDR_01", true )
	ObjectHideSubObjectPermanently( self, "SLDR_02", true )
	ObjectHideSubObjectPermanently( self, "SLDR_03", true )
	ObjectHideSubObjectPermanently( self, "SLDR_04", true )
	ObjectHideSubObjectPermanently( self, "SLDR_05", true )
	ObjectHideSubObjectPermanently( self, "SLDR_06", true )
	ObjectHideSubObjectPermanently( self, "Shield_1OG", true )
	ObjectHideSubObjectPermanently( self, "Shield_2OG", true )
	ObjectHideSubObjectPermanently( self, "HAIR_00", true )
	ObjectHideSubObjectPermanently( self, "HAIR_01", true )
	ObjectHideSubObjectPermanently( self, "HLMT_00", true )
	ObjectHideSubObjectPermanently( self, "HLMT_01", true )
	ObjectHideSubObjectPermanently( self, "HLMT_02", true )
	ObjectHideSubObjectPermanently( self, "HLMT_03", true )
	ObjectHideSubObjectPermanently( self, "HLMT_04", true )
	ObjectHideSubObjectPermanently( self, "HLMT_05", true )
	ObjectHideSubObjectPermanently( self, "HLMT_06", true )
	ObjectHideSubObjectPermanently( self, "HLMT_07", true )
	ObjectHideSubObjectPermanently( self, "HLMT_07_LOD1", true )
	ObjectHideSubObjectPermanently( self, "HLMT_08", true )
	ObjectHideSubObjectPermanently( self, "HLMT_09", true )
	ObjectHideSubObjectPermanently( self, "GNLT_00", true )
	ObjectHideSubObjectPermanently( self, "GNLT_01", true )
	ObjectHideSubObjectPermanently( self, "GNLT_02", true )
	ObjectHideSubObjectPermanently( self, "GNLT_03", true )
	ObjectHideSubObjectPermanently( self, "GNLT_04", true )
	ObjectHideSubObjectPermanently( self, "GNLT_05", true )
	ObjectHideSubObjectPermanently( self, "GNLT_06", true )
	ObjectHideSubObjectPermanently( self, "GNLT_07", true )
	ObjectHideSubObjectPermanently( self, "GNLT_08", true )
	ObjectHideSubObjectPermanently( self, "GHLT_08", true )
	ObjectHideSubObjectPermanently( self, "GNLT_09", true )
	ObjectHideSubObjectPermanently( self, "GNLT_09_LOD1", true )
	ObjectHideSubObjectPermanently( self, "GNLT_10", true )
	ObjectHideSubObjectPermanently( self, "SPR_01", true )
	ObjectHideSubObjectPermanently( self, "PAXE_01", true )
	ObjectHideSubObjectPermanently( self, "PAXE_01_LOD1", true )
	ObjectHideSubObjectPermanently( self, "SWRD_01", true )
	ObjectHideSubObjectPermanently( self, "SWRD_02", true )
	ObjectHideSubObjectPermanently( self, "SWRD_03", true )
	ObjectHideSubObjectPermanently( self, "SWRD_04", true )
	ObjectHideSubObjectPermanently( self, "SWRD_05", true )
	ObjectHideSubObjectPermanently( self, "SWD_01", true )
	ObjectHideSubObjectPermanently( self, "SWD_02", true )
	ObjectHideSubObjectPermanently( self, "SWD_03", true )
	ObjectHideSubObjectPermanently( self, "SWD_04", true )
	ObjectHideSubObjectPermanently( self, "STFF_05", true )
	ObjectHideSubObjectPermanently( self, "STFF_06", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_01", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_02", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_03", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_01", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_02", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_03", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_04", true )	
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_01", true )
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_02", true )
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_03", true )
	ObjectHideSubObjectPermanently( self, "TrollTree", true )
	ObjectHideSubObjectPermanently( self, "TrollHammer", true )
	ObjectHideSubObjectPermanently( self, "CLUB_01", true )
	ObjectHideSubObjectPermanently( self, "CLUB_02", true )
	ObjectHideSubObjectPermanently( self, "CLUB_03", true )
	ObjectHideSubObjectPermanently( self, "HMR_01", true )
	ObjectHideSubObjectPermanently( self, "HMR_02", true )
	ObjectHideSubObjectPermanently( self, "HMR_03", true )
	ObjectHideSubObjectPermanently( self, "HMR_04", true )
	ObjectHideSubObjectPermanently( self, "AXE_01", true )
	ObjectHideSubObjectPermanently( self, "AXE_02", true )
	ObjectHideSubObjectPermanently( self, "AXE_03", true )
	ObjectHideSubObjectPermanently( self, "BARREL", true )
	ObjectHideSubObjectPermanently( self, "OBJECT02", true )	-- Barrel on the Orc Raider
	ObjectHideSubObjectPermanently( self, "ARROW", true )
	ObjectHideSubObjectPermanently( self, "PLANE02", true )	
end

function UARemoveUpgrade (self) -- ;,; --
    ObjectRemoveUpgrade( self, "Upgrade_UARebuild_and_Recruit" )
end

function AllowRecruiting (self) -- ;,; --
    ObjectRemoveUpgrade( self, "Upgrade_PreventSpawning" )
end

function DisallowRecruiting (self) -- ;,; --
    ObjectGrantUpgrade( self, "Upgrade_PreventSpawning" )
end

function OnCreateAHeroFunctions(self)
	CreateAHeroHideEverything(self)
end

function OnExplosiveMineDeath(self)
    ObjectHideSubObjectPermanently( self, "BOMB", true )
end

function OnEvilShipCreated(self)
	ObjectHideSubObjectPermanently( self, "CAULDRON", true )
	ObjectHideSubObjectPermanently( self, "CAULDRON_FIRE", true )
	ObjectHideSubObjectPermanently( self, "CAULDRON_TOP", true )
	ObjectHideSubObjectPermanently( self, "CROWSNEST", true )
	ObjectHideSubObjectPermanently( self, "FLAG", true )
	ObjectHideSubObjectPermanently( self, "BANNER", true )
end

function OnGoodShipCreated(self)
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_01", true )
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_02", true )
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_FIRE", true )
	ObjectHideSubObjectPermanently( self, "UG_ARMOR", true )
	ObjectHideSubObjectPermanently( self, "BANNER", true )
end

function OnShipWrightCreated(self)
	ObjectHideSubObjectPermanently( self, "GoodPart_A", true )
	ObjectHideSubObjectPermanently( self, "GoodPart_B", true )
	ObjectHideSubObjectPermanently( self, "EvilPart_A", true )
	ObjectHideSubObjectPermanently( self, "EvilPart_B", true )
end

function OnDormitoryBuildVariation(self,variation)

	local var = tonumber(variation)

	if var == 1 then
		ObjectSetGeometryActive( self, "VersionOne", true )
		ObjectSetGeometryActive( self, "VersionTwo", false )
	elseif var == 2 then
		ObjectSetGeometryActive( self, "VersionOne", false )
		ObjectSetGeometryActive( self, "VersionTwo", true )
	end

end

function OnBlightNearHeal(self) -- 
    ObjectGrantUpgrade( self, "Upgrade_BlightAntiBWBuff" )
end

function OnBlightNOTNearHeal(self) -- 
    ObjectRemoveUpgrade( self, "Upgrade_BlightAntiBWBuff" )
end

function OnElvenHordeNearBlight(self) -- Disable banner healing while the horde is in Blight.
    ObjectGrantUpgrade( self, "Upgrade_BlightAntiBWBuff" )
end

function OnElvenHordeNotNearBlight(self) -- Restore banner healing after Blight expires.
    ObjectRemoveUpgrade( self, "Upgrade_BlightAntiBWBuff" )
end

function OnBlightAntiCloudBreak(self) -- 
    ObjectGrantUpgrade( self, "Upgrade_BlightAntiCBBuff" )
end

function OnBlightNotAntiCloudBreak(self) -- 
    ObjectRemoveUpgrade( self, "Upgrade_BlightAntiCBBuff" )
end

function OnFortressCreated(self)
	ObjectHideSubObjectPermanently( self, "DBFBANNER", true )	
	ObjectSetGeometryActive( self, "HighTowerGeom", false )
	tinsert(Citadels, {
		obj = self,
		team = ObjectTeamName(self),
		side = ObjectPlayerSide(self),
	})
end

function OnPowerGranterCreated(self)
	ObjectGrantUpgrade(self, "Upgrade_IsWotr")
end

function OnFortressFlagCreated(self)
    ObjectHideSubObjectPermanently( self, "DBFBANNER", true )    
    ObjectSetGeometryActive( self, "HighTowerGeom", false )

    -- if IsPlayerAI(self) then return end
	tinsert(FortsTable.forts, {
		obj = self,
		team = ObjectTeamName(self),
	})
	SpawnInverseDiscounter(self)
end

function SpawnInverseDiscounter(self)
	ExecuteAction("CREATE_OBJECT", "FortressInverseDiscounter", GetScriptTeamName(self), "((0.00,0.00,0.00))", 0)
end

function OnFortressInverseDiscounterCreated(self)
	tinsert(FortsTable.shadows, {
		obj = self,
		team = ObjectTeamName(self),
	})
end

function OnFortDestroyed(self)
	FortressDiscountTick(self)
end

function FortressDiscountTick(self)
	local num_of_forts = getn(FortsTable.forts)
	local num_of_shadows = getn(FortsTable.shadows)
	local destroyed_fort_player = nil
	-- ExecuteAction("DISPLAY_TEXT", "Forts in the table: " .. tostring(num_of_forts))
	-- ExecuteAction("DISPLAY_TEXT", "Shadows in the table: " .. tostring(num_of_shadows))
	-- Step 1: Find and remove destroyed fort
	for i = num_of_forts, 1, -1 do
		local fort = FortsTable.forts[i]
		if strfind(ObjectDescription(fort.obj), "<No Object>") then
			destroyed_fort_player = fort.team
			tremove(FortsTable.forts, i)
			break
		end
	end

	-- Step 2: If we found a destroyed fort, clean up shadows for that team
	if destroyed_fort_player then
		for i = num_of_shadows, 1, -1 do
			local shadow = FortsTable.shadows[i]
			if shadow.team == destroyed_fort_player then
				kill(shadow.obj)
				tremove(FortsTable.shadows, i)
				break
			end
		end
	end

	-- Step 3: Fix mismatch if game was reloaded (forts < shadows)
	local fort_count = getn(FortsTable.forts)
	local shadow_count = getn(FortsTable.shadows)
	
	if fort_count < shadow_count then
		-- ExecuteAction("DISPLAY_TEXT", "Mismatch detected, clearing all shadows...")
	
		-- Wipe existing shadows
		for i = shadow_count, 1, -1 do
			local shadow = FortsTable.shadows[i]
			kill(shadow.obj)
			tremove(FortsTable.shadows, i)
		end
	
		-- Respawn shadows for all valid forts
		for i = 1, fort_count do
			local fort = FortsTable.forts[i]
			SpawnInverseDiscounter(fort.obj)
		end		
	end
end

function OnGateWatcherBuilt(self)
	ObjectDoSpecialPower(self, "SpecialAbilityGateWatchersFear")
end	

function DeselectOnDissent(self)
	-- forcefully deselect if Dissent is cast on the selected unit
    if ObjectTestModelCondition(self, "SELECTED") then
        ExecuteAction("DESELECT")
    end
end

function ToggleWeaponOnDissent(self)

	local isToggled = ObjectTestModelCondition(self, "WEAPONSET_TOGGLE_1") -- sword for foot units, bow for Rohirrim

	if not isToggled then
		if strfind(ObjectDescription(self),"NoldorWarrior") or strfind(ObjectDescription(self),"RohanElvenWarrior") then
			ObjectGrantUpgrade( self, "Upgrade_WeaponToggle" )
		end	
	else
		if strfind(ObjectDescription(self),"Rohirrim")  or strfind(ObjectDescription(self),"SpiderRider") or strfind(ObjectDescription(self),"Hobbit") then
			ObjectGrantUpgrade( self, "Upgrade_WeaponToggle" )
		end
	end
end

function OnDissentHacks(self) 
	ToggleWeaponOnDissent(self)
	DeselectOnDissent(self) 
	ExecuteAction("NAMED_STOP", self)
	ObjectForbidPlayerCommands( self, true )
	ObjectGrantUpgrade( self, "Upgrade_OnDissentTrigger" )
	ToggleObjectStatus(self, "UNSELECTABLE", true)
end

function OffDissentHacks(self) 
	ObjectForbidPlayerCommands( self, false )
	ObjectRemoveUpgrade( self, "Upgrade_OnDissentTrigger" )
	ObjectRemoveUpgrade( self, "Upgrade_HoldGroundStance" ) 
	ObjectRemoveUpgrade( self, "Upgrade_NeutralStance" ) 
	ObjectRemoveUpgrade( self, "Upgrade_AggressiveStance" )
	ObjectRemoveUpgrade( self, "Upgrade_WeaponToggle" )
	ToggleObjectStatus(self, "UNSELECTABLE", false)
end

function NeutralGollum_RingStealerDamaged(self,other)

	if ObjectHasUpgrade( other, "Upgrade_RingHero" ) == 0 then
		ObjectChangeAllegianceFromNonPlayablePlayer( self, other )
	end
	
end

function NeutralGollum_RingStealerSlaughtered(self,other)
	ObjectRemoveUpgrade( other, "Upgrade_RingHero" )
end

function OnNecromancerStatueCreated(self)
	ObjectDoSpecialPower(self, "SpecialAbilityGateWatchersFear")
end

function OnKennelWolfCreated(self) -- Added for 2.1, using this to show Dire Wolf Kennel Wolf Spiked Collars ;;,;;
	ObjectGrantUpgrade( self, "Upgrade_AngmarSpikedCollar" )
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function BecomeDismounted(self) -- Added for 2.1, Sûlherokhh AI ;;,;;
    ObjectRemoveUpgrade( self, "Upgrade_AITriggerMount" )
    ObjectGrantUpgrade( self, "Upgrade_AITriggerDismount" )
end

function BecomeMounted(self) -- Added for 2.1, Sûlherokhh AI ;;,;;
    ObjectRemoveUpgrade( self, "Upgrade_AITriggerDismount" )
    ObjectGrantUpgrade( self, "Upgrade_AITriggerMount" )
end

function RemoveHealUpgrades(self)
	ObjectRemoveUpgrade( self, "Upgrade_WellRespawnCountdown" )
	ObjectRemoveUpgrade( self, "Upgrade_WellRespawnStart" )
	ObjectRemoveUpgrade( self, "Upgrade_BWRespawnCountdown" )
	ObjectRemoveUpgrade( self, "Upgrade_BWRespawnStart" )
	ObjectRemoveUpgrade( self, "Upgrade_FortRespawnCountdown" )
	ObjectRemoveUpgrade( self, "Upgrade_FortRespawnStart" )
end

function HandleHordeRespawn(self)
	-- always clear all upgrades by default
	-- decide which upgrade to give: fort, well, bw or do nothing
	-- fort > well > bw
	RemoveHealUpgrades(self) 
	if IsPlayerAI(self) then return end
	
	local isNearWell = ObjectTestModelCondition(self, "USER_10")
	local isNearBW = ObjectTestModelCondition(self, "USER_11")
	local isNearFort = ObjectTestModelCondition(self, "USER_12")
	if isNearFort then
		ObjectGrantUpgrade( self, "Upgrade_FortRespawnCountdown" ) 
	--	ExecuteAction("DISPLAY_TEXT", "Near fort ")
	elseif isNearWell then
		ObjectGrantUpgrade( self, "Upgrade_WellRespawnCountdown" ) 
	--	ExecuteAction("DISPLAY_TEXT", "Near well ")
	elseif isNearBW then
		ObjectGrantUpgrade( self, "Upgrade_BWRespawnCountdown" )
	else
		-- ExecuteAction("DISPLAY_TEXT", "Not near anything ")
		return
	end
end

-- Corrode Allegiance is fucked
-- it has multiple CP bugs (fixed mostly via inis)
-- ObjectTeamName(self) is screwed up for AI: teams show like "ENEMY_STRUCTURE_SimpleAttack_30_0" 
-- The team objects belonging to AI changes its name depending on the task the unit has
-- HACKS: 

-- function OnPreDefected(self)

-- 	local ref = GetUnitReference(self)
-- 	local current_player
-- 	for i = getn(HeroTeamsTable), 1, -1 do -- Iterate backward
--         local hero = HeroTeamsTable[i]
--         if hero.reference == ref then
-- 			current_player = hero.original_team
-- 			break
-- 		end
-- 	end

-- 	-- ExecuteAction("DISPLAY_TEXT", "Transfer from: " .. tostring(current_player))
	
-- end

function OnTemporarilyDefected(self) -- ;;,;;
	-- local current_team = ObjectTeamName(self)
	-- ExecuteAction("DISPLAY_TEXT", "Transfer to: " .. tostring(current_team))
	ObjectGrantUpgrade( self, "Upgrade_CorrodeAllegianceCPHack" )
end

function OnCorroded(self) -- ;;,;;
	ObjectRemoveUpgrade( self, "Upgrade_CorrodeAllegianceCPHack" )
	ObjectRemoveUpgrade( self, "Upgrade_CorrodeAllegianceNegativeCPHack" )
end

function OffDefected(self)
	local heroReference = GetUnitReference(self)
    for i = getn(HeroTeamsTable), 1, -1 do -- Iterate backward
        local defectedHero = HeroTeamsTable[i]
        if defectedHero.reference == heroReference then
            local original_team = defectedHero.original_team
			local scripted_team = gsub(original_team, "team", "") .. "/" .. original_team
			-- ExecuteAction("DISPLAY_TEXT", "Transfer back to: " .. tostring(original_team))
            ExecuteAction("UNIT_SET_TEAM", self, scripted_team)
			
			for j = 1, getn(heroPowers) do
				local power = heroPowers[j]
				if power.hero_reference == heroReference and defectedHero.original_team ~= power.player then
					power.player = defectedHero.original_team
					-- ExecuteAction("DISPLAY_TEXT", "Reassigned: " .. tostring(power.abilityName))
				end
			end
            -- tremove(DefectedTable, i)
        end
    end
end

function OnReallyDamagedWhileCorroded(self)
	local isCorroded = ObjectHasStatus(self, "TEMPORARILY_DEFECTED")
	local isReallyDamaged = ObjectTestModelCondition(self, "REALLYDAMAGED")

	if isCorroded and isReallyDamaged then
		-- and IsPlayerAI(self)
		local hp = GetHealth(self)
        if hp < 25 then
			ToggleObjectStatus(self, "TEMPORARILY_DEFECTED", false)
		end
	end
end

function AddToHeroTeamsTable(self)
	-- used for corrode allegiance to return corroded hero to the original player
	-- ExecuteAction("DISPLAY_TEXT", "Team: " .. tostring(ObjectTeamName(self)))
	tinsert(HeroTeamsTable, {
		reference = GetUnitReference(self),
		original_team = ObjectTeamName(self),
	})
end

function PopFromHeroTeamsTable(self)
	local length = getn(HeroTeamsTable)
    if length == 0 then return end

	local ref = GetUnitReference(self)

    for i = length, 1, -1 do -- Iterate backward
        local hero = HeroTeamsTable[i]
    	if hero.reference == ref then
            tremove(HeroTeamsTable, i) -- Use tremove to maintain sequence integrity
        end
    end
end
-- ---------------------------------------------------------------------------

function OnStarlightActivated(self) -- Added for 2.1 ;;,;;
	ObjectBroadcastEventToEnemies( self, "BeUncontrollablyAfraid", 350 )
	OnAbilityTriggered(self)
end

function OnRohanEowynCreated(self) -- Added for v7, by Sûlherokhh. ;,;
	OnGenericHeroCreated(self)
    ObjectRemoveUpgrade( self, "Upgrade_EowynConditionDisguised" )
end

function OnRohanEowynDisguised(self) -- Added for v7, by Sûlherokhh. ;,;
    ObjectGrantUpgrade( self, "Upgrade_EowynConditionDisguised" )
end

function OnRohanEowynDisguiseCanceled(self) -- Added for v7, by Sûlherokhh. ;,;
    ObjectRemoveUpgrade( self, "Upgrade_EowynConditionDisguised" )
    end

function OnRohanEowynStealthed(self) -- Added for v7, by Sûlherokhh. ;,;
    ObjectRemoveUpgrade( self, "Upgrade_EowynConditionNotStealthed" )
    ObjectGrantUpgrade( self, "Upgrade_EowynConditionStealthed" )
end

function OnRohanEowynNotStealthed(self) -- Added for v7, by Sûlherokhh. ;,;
    ObjectRemoveUpgrade( self, "Upgrade_EowynConditionStealthed" )
    ObjectGrantUpgrade( self, "Upgrade_EowynConditionNotStealthed" )
end

function OnWeaponToggle(self) 
    ObjectGrantUpgrade( self, "Upgrade_WeaponToggle" )
	ManipulateAutoAttacks(self)
end

function OffWeaponToggle(self) 
    ObjectRemoveUpgrade( self, "Upgrade_WeaponToggle" )
	ManipulateAutoAttacks(self)
end

function ManipulateAutoAttacks(self)
	
	local isMelee = ObjectTestModelCondition(self, "WEAPONSET_TOGGLE_1")
	local isEnemyNear = ObjectTestModelCondition(self, "SPECIAL_ENEMY_NEAR")

	if isMelee then
		ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", false) -- allowed to auto acquire in melee
	else
		if isEnemyNear then
			ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", false) -- allowed to auto acquire in bow mode
		else
			-- ExecuteAction("UNIT_SET_MODELCONDITION_FOR_DURATION", self, "USER_65",1,100)
			-- ExecuteAction("UNIT_CHANGE_OBJECT_STATUS", self, 5, 1) -- no_attack = true
			ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", true) -- not allowed to auto acquire in bow mode if no enemies near
			if ObjectHasStatus(self, "IS_AIMING_WEAPON") then -- if still acquired a structure then forbid attacks for 1 frame (0.2s)
				ToggleObjectStatus(self, "NO_ATTACK", true)
				SetModelCondition(self, "USER_65", 0.2)
				-- CheckStatuses(self)
			end
		end
	end
end

function OnHaldirWeaponToggle(self) 
    ObjectRemoveUpgrade( self, "Upgrade_WeaponToggle" )
	ManipulateAutoAttacksHaldir(self)
end

function OffHaldirWeaponToggle(self) 
    ObjectGrantUpgrade( self, "Upgrade_WeaponToggle" )
	ManipulateAutoAttacksHaldir(self)
end

function ManipulateAutoAttacksHaldir(self) -- same as above but it works in reverse for haldir since sword is his default weapon
	
	local isBow = ObjectTestModelCondition(self, "WEAPONSET_TOGGLE_1")
	local isEnemyNear = ObjectTestModelCondition(self, "SPECIAL_ENEMY_NEAR")

	if isBow then
		if isEnemyNear then
			ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", false) -- allowed to auto acquire in melee
		else
			ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", true) -- not allowed to auto acquire in melee
			if ObjectHasStatus(self, "IS_AIMING_WEAPON") then -- if still acquired a structure then forbid attacks for 1 frame (0.2s)
				ToggleObjectStatus(self, "NO_ATTACK", true)
				SetModelCondition(self, "USER_65", 0.2)
				-- CheckStatuses(self)
			end
		end
	else
		ToggleObjectStatus(self, "NO_AUTO_ACQUIRE", false) -- allowed to auto acquire in bow mode
	end
end

function resetNoAttack(self)
	ToggleObjectStatus(self, "NO_ATTACK", false) -- resumes attacking
end

function WeaponToggleMelee(self) --;,;
    ObjectGrantUpgrade( self, "Upgrade_WeaponToggle" )
end
function WeaponToggleRange(self) --;,;
    ObjectRemoveUpgrade( self, "Upgrade_WeaponToggle" )
end

function OnMoving(self) 
    ObjectGrantUpgrade( self, "Upgrade_Moving" )
end

function OffMoving(self) 
    ObjectRemoveUpgrade( self, "Upgrade_Moving" )
end

function OnTrollEating(self) -- Added by Miraak. ;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOff" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end

function OnTrollNotEating(self)  -- Added by Miraak. ;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOff" )
end

function OnFortEagleCreated(self)
	
	if not beginFlierIteration then
    	beginFlierIteration = true
	end

	local playerName = ObjectTeamName(self)
    local IsEntryFound = false
    for i = getn(FlierTable), 1, -1 do
        local Eagle = FlierTable[i]
        if Eagle.player == playerName then
			if strfind(ObjectDescription(Eagle.obj),"<No Object>") then
				if Eagle.name == ObjectTemplateName(self) then
					IsEntryFound = true
					local IncreaseByLevels = ceil(Eagle.level/2) -- minus one is the horde adjustment
					-- GiveUnitExperienceLevel(self, IncreaseByLevels-1, "MordorBlackRider")
					Eagle.level = IncreaseByLevels
					Eagle.flier = self
					Eagle.id = GetUnitReference(self)
					GiveUnitExperienceLevel(self, IncreaseByLevels-1, "GondorGwaihir") -- for initial build for test purposes
					return
				end
			end
        end
    end
    if not IsEntryFound then
        tinsert(FlierTable, { flier = self, player = playerName, level = 1, id = GetUnitReference(self), name = ObjectTemplateName(self) })
    end

end

function OnMiniHeroHordeCreated(self)
	-- ExecuteAction("DISPLAY_TEXT", "Created")
    local playerName = ObjectTeamName(self)
    local IsEntryFound = false
    for i = getn(MHHSTable), 1, -1 do
        local MiniHeroHorde = MHHSTable[i]
        if MiniHeroHorde.player == playerName then
			if strfind(ObjectDescription(MiniHeroHorde.obj),"<No Object>") then
				if MiniHeroHorde.name == ObjectTemplateName(self) then
					IsEntryFound = true

					local LevelDiedOn = MiniHeroHorde.level
					local IncreaseByLevels = ceil(MiniHeroHorde.level/2) -- minus one is the horde adjustment
					-- GiveUnitExperienceLevel(self, IncreaseByLevels-1, "MordorBlackRider")
					MiniHeroHorde.level = IncreaseByLevels
					MiniHeroHorde.obj = self
					MiniHeroHorde.id = GetUnitReference(self)
					if ObjectTemplateName(self) == "WildFortressFireDrake" then
						GiveUnitExperienceLevel(self, IncreaseByLevels-1, "WildFortressFireDrake")
					elseif ObjectTemplateName(self) == "RohanTreeBerd" or ObjectTemplateName(self) == "HERohanTreeBerd" then -- the High Elves Treebeard shares the levels
						GiveUnitExperienceLevel(self, LevelDiedOn-1, "RohanTreebeard") -- watch the spelling of ExperienceLevel entry vs Object 
						MiniHeroHorde.level = LevelDiedOn
						return
					else
						local upgrade = "Upgrade_ObjectLevel" .. tostring(IncreaseByLevels)
						ObjectGrantUpgrade(self, upgrade)
					end
					SetFortUnitCost(self, IncreaseByLevels) -- uncomment for mechanic to work
					return
				end
			end
        end
    end
    if not IsEntryFound then
	-- GiveUnitExperienceLevel(self, 9, "RohanTreebeard") 
		tinsert(MHHSTable, { obj = self, player = playerName, level = 1, id = GetUnitReference(self), name = ObjectTemplateName(self) })
    end
end

function OnMiniHeroHordeLeveled(self)
    local playerName = ObjectTeamName(self)
    for i = getn(MHHSTable), 1, -1 do
        if MHHSTable[i].player == playerName then
			if GetUnitReference(self) == MHHSTable[i].id then
				MHHSTable[i].level = GetUnitLevel(self)
			end
			-- ExecuteAction("DISPLAY_TEXT", "Lvl: " .. tostring(MHHSTable[i].level))
			SetFortUnitCost(self, MHHSTable[i].level) -- uncomment for mechanic to work
        end
    end
end

function SetFortUnitCost(self, level)
	local revival_level = ceil(level/2)
	local upgrade = "Upgrade_MiniHordeLvl" .. tostring(revival_level)
	for i = getn(Citadels), 1, -1 do
		local cita = Citadels[i]
		if ObjectTeamName(self) == cita.team and ObjectPlayerSide(self) == cita.side then
			for k = 1, 5 do
				local upgr_to_remove = "Upgrade_MiniHordeLvl" .. tostring(k)
				ObjectRemoveUpgrade( cita.obj, upgr_to_remove )
			end
			if revival_level > 1 then ObjectGrantUpgrade( cita.obj, upgrade ) end
		end
	end
end

function OnDrakeDestroyed(self)
	ExecuteAction("DISPLAY_TEXT", "Drake destroyed")
end

function EndGrandHarvest(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GrandHarvestActivator" )
end

function BoromirCreated(self)  --;,;
	OnGenericHeroCreated(self)
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOff" )
end
function LastStandActivation(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOff" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOn" )
	OnReallyDamagedWhileCorroded(self)
end
function LastStandDeactivation(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end
function OnDisguiseCancelEffect(self) --;,;
    ObjectDoSpecialPower(self, "SpecialAbilityDisguiseCancel")
end
function UnlockLockedWeapon(self) --;,;
    ObjectDoSpecialPower(self, "SpecialAbilityUnlockLockedWeapon")
end
function BecomeFaster(self) --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_2" )
end

function NotBecomeFaster(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_2" )
end
function HiddenHunter(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOff" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOn" )
end
function NotHiddenHunter(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOff" )
end
function GiveUpgrade(self)  --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_1" )
end
function GiveUpgrade2(self)  --;,;
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_1" )
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_1" )
end

function BlockBuild(self)  --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_1" )
end
function RemoveBlockBuild(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_1" )
end
function GrantUpgradeType2(self)  --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_2" )
end
function RemoveUpgradeType2(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_2" )
end

function OnMountedBladeOfPurity(self)  --;,;
	-- SetModelCondition(self, "USER_4", 1) -- so blade of purity fx expires and not re-applied later
    ObjectGrantUpgrade( self, "Upgrade_User1" )
end
function OffMountedBladeOfPurity(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_User1" )
end

function OnTowerCreated(self)
	if IsPlayerAI(self) then return end
	tinsert(TowerTable, {
		obj = self,
		reference = GetUnitReference(self), 
		team = ObjectTeamName(self),
		shadow = nil,
	})
	ExecuteAction("CREATE_OBJECT", "TowerShadow", GetScriptTeamName(self), "((0.00,0.00,0.00))", 0)
end

function OnTowerInverseDiscounterCreated(self)
	local length = getn(TowerTable)
    if length == 0 then return end
	local player = ObjectTeamName(self)

    for i = length, 1, -1 do -- Iterate backward
        local tower = TowerTable[i]
        if tower.team == player then
			tower.shadow = self
			return
        end
    end
end

function DestroyTheShadowIfTowerGone(self)
	local length = getn(TowerTable)
	for i = length, 1, -1 do -- Iterate backward
        local tower = TowerTable[i]
        if tower.reference == GetUnitReference(self) then
			kill(tower.shadow)
			tremove(TowerTable, i)
			break
        end
    end
end

function OnTowerDestroyed(self)
	DestroyTheShadowIfTowerGone(self)
end

function TowerDiscountTick(self)
	local length = getn(TowerTable)

	for i = length, 1, -1 do -- Iterate backward
		local tower = TowerTable[i]
		if strfind(ObjectDescription(tower.obj),"<No Object>") then
			if tower.shadow then
				kill(tower.shadow)
			end
			tremove(TowerTable, i)
		end
	end
end

function OnSummonedDragonTakeOff(self)
	-- ExecuteAction("DISPLAY_TEXT", "Taking off ")
	SetModelCondition(self, "RIDER1", 1)
	OnAbilityTriggered(self)
	ToggleObjectStatus(self, "UNATTACKABLE", true)
end

function OnSummonedDragonLand(self)
	-- ExecuteAction("DISPLAY_TEXT", "Landing ")
	ToggleObjectStatus(self, "UNATTACKABLE", false)
end

function OnTorchLit(self)
	ObjectGrantUpgrade( self, "Upgrade_User1" )
end

function OnTorchExtinguished(self)
	ObjectRemoveUpgrade( self, "Upgrade_User1" )
end

function OnActivateGrimaStealth(self)  --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectTypeOn" )
	-- ExecuteAction("DISPLAY_TEXT", "Stealth Activated")
end

function OnGrimaEscape(self)

    if not ObjectTestModelCondition(self, "HIDDEN") then
        ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
        return
    end

    local ref = GetUnitReference(self)
    local exp = 1 -- given every 2 seconds
    ExecuteAction("UNIT_GIVE_EXPERIENCE_POINTS", ref, exp)
    -- ExecuteAction("DISPLAY_TEXT", "Escape experience boost")
end

function OnDeactivateGrimaStealth(self)
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectTypeOn" )
	-- ExecuteAction("DISPLAY_TEXT", "Stealth Deactivated")
end

function UndermineArmor(self)  --;,;
    ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_2" )
end
function UndermineNoArmor(self)  --;,;
    ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_2" )
end

function OnAggressiveStance(self)  --;,;
	ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_2" )
end
function OffAggressiveStance(self)  --;,;
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_2" )
end

function OnHoldGroundStance(self)  --;,;
	ObjectGrantUpgrade( self, "Upgrade_GenericObjectType_1" )
end
function OffHoldGroundStance(self)  --;,;
	ObjectRemoveUpgrade( self, "Upgrade_GenericObjectType_1" )
end

-- function OnWorkerInherited(self)
-- 	if ObjectHasUpgrade( self, "Upgrade_IsengardFaction" ) == 1 then
-- 		--in case we get dozens of workers inherited, 
-- 		--this will metabolize OnWorkerBeginHarvest over up to 10s
-- 		--so it's not triggered in the same frame
-- 		--OnWorkerBeginHarvest is triggered when RIDERLESS expires
-- 		local randomSeconds = 1 + GetRandomNumber() * 10 -- between 1s and 11s.
-- 		SetModelCondition(self, "RIDERLESS", randomSeconds) 
-- 	end
-- end

-- function OnWorkerCreated(self)
-- 	if ObjectHasUpgrade( self, "Upgrade_IsengardFaction" ) == 1 then
-- 		SetModelCondition(self, "RIDERLESS", 0.2) 
-- 	end
-- end

function OnWorkerBeginHarvest(self)
	tinsert(WorkerTable, {
		worker = self,
	})
	-- ObjectDoSpecialPower( self, "SpecialAbilityHarvest" )
end

function ResumeTracking()
	-- ExecuteAction("DISPLAY_TEXT", "Resume tracking... " )
	RestoreEcoTrackingOnReload()
    for k, v in globals() do
        if strfind(k, "ObjID") and ObjectHasUpgrade(v, "Upgrade_IsengardFaction") == 1 then
            if ObjectTemplateName(v) == "MordorWorker" 
            or ObjectTemplateName(v) == "MordorWorkerFuels" then
                tinsert(WorkerTable, {
                    worker = v,
                })
            end
        end
    end
end

function IterateThroughWorkers()
		local count = getn(WorkerTable)
		-- ExecuteAction("DISPLAY_TEXT", "Worker Count: " .. tostring(count))

		for i = count, 1, -1 do
		local worker = WorkerTable[i].worker
		if strfind(ObjectDescription(worker), "<No Object>") then
			tremove(WorkerTable, i)
		else
			local workerName = ObjectTemplateName(worker)
			if ObjectTestModelCondition(worker, "USER_2") then
				if workerName == "MordorWorker" then
					if ObjectTestModelCondition(worker, "MOVING") 
					-- and not ObjectTestModelCondition(worker, "HARVEST_PREPARATION") 
					and not ObjectTestModelCondition(worker, "CARRYING")
					and not ObjectTestModelCondition(worker, "HARVEST_ACTION")
					and not ObjectTestModelCondition(worker, "ATTACKING") then
						OnFueltheFires(worker)
					end
				end
			else
				if workerName == "MordorWorkerFuels" then
					if ObjectTestModelCondition(worker, "MOVING") 
					-- and not ObjectTestModelCondition(worker, "HARVEST_PREPARATION") 
					and not ObjectTestModelCondition(worker, "CARRYING")
					and not ObjectTestModelCondition(worker, "HARVEST_ACTION")
					and not ObjectTestModelCondition(worker, "ATTACKING") then
						OffFueltheFires(worker)
					end
				end
			end
		end
	end	
end

function OffFueltheFires(self)
	-- ExecuteAction("DISPLAY_TEXT", "Off Fuels ")
	ObjectDoSpecialPower( self, "SpecialAbilityActivateeDummy1" )
	delete(self)
end

function OnFueltheFires(self)
	-- ExecuteAction("DISPLAY_TEXT", "On Fuels ")
	ObjectDoSpecialPower( self, "SpecialAbilityActivateeDummy" )
	delete(self)
end

function GrantUpgrades(self)  --;,;
	ObjectGrantUpgrade( self, "Upgrade_GondorWorkshopLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_GondorArcheryRangeLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_GondorForgeLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_GondorForgeLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_EregionForgeLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_EregionForgeLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_DwarvenBarracksLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_DwarvenArcheryRangeLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_DwarvenForgeWorksLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_DwarvenForgeWorksLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_IsengardArmoryLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_IsengardArmoryLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_IsengardTavernLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_WildTreasureTroveLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_WildTreasureTroveLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_MordorOrcPitLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_MordorTavernLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_MordorTavernLevel3" )
	ObjectGrantUpgrade( self, "UpgradeAngmarBarracksLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_AngmarForgeWorksLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_AngmarForgeWorksLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_AngmarHallofTwilightLevel2" )
	ObjectGrantUpgrade( self, "Upgrade_AngmarHallofTwilightLevel3" )
	ObjectGrantUpgrade( self, "Upgrade_BattleWagonMenOfDale" )
	ObjectGrantUpgrade( self, "Upgrade_BattleWagonBannerCarrier" )
	ObjectGrantUpgrade( self, "Upgrade_BattleWagonAxeThrowers" )
end

function PowerPointsCooldown(self)
	ObjectGrantUpgrade( self, "Upgrade_CustomPowerPointCooldown" )
end


function AddGenericUpgradeOne(self)
	ObjectGrantUpgrade( self, "Upgrade_GenericOne" )
end

function RemoveGenericUpgradeOne(self)
	ObjectRemoveUpgrade( self, "Upgrade_GenericOne" )
end

function OnPalantirDestroyed(self)
	-- local c = 0
	for k, v in globals() do
		if strfind(k, "ObjID") and ObjectTeamName(self) == ObjectTeamName(v) and ObjectTemplateName(v) == "PalantirVisionTracker" then
			-- c = c + 1
			delete(v)
		end
	end
	-- ExecuteAction("DISPLAY_TEXT", "Count: " .. tostring(c))
end

function SelectBalrog(self)
	-- ExecuteAction("DESELECT")
	ForceSelectObject(self, "MordorBalrog", "0")
end
