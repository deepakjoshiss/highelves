
const Alias = {
    SCIENCE_RebuildSP: 'SCIENCE_Rebuild',
    SCIENCE_UndermineSP: 'SCIENCE_Undermine',
    SCIENCE_ElvenWoodSP: 'SCIENCE_ElvenWood',
}
const Sciences = [
    'SCIENCE_Farsight',
    'SCIENCE_ElvenGifts',
    'SCIENCE_Heal',
    'SCIENCE_RallyingCallMP',
    'SCIENCE_EnshroudingMistSP',
    'SCIENCE_ElvenWood',
    'SCIENCE_Rebuild',
    'SCIENCE_EnshroudingMistMP',
    'SCIENCE_ArrowVolleyGood',
    'SCIENCE_TomBombadil',
    'SCIENCE_SpawnLoneTower',
    'SCIENCE_DwarvenRiches',
    'SCIENCE_HobbitAllies',
    'SCIENCE_RallyingCall',
    'SCIENCE_Undermine',
    'SCIENCE_EntAllies',
    'SCIENCE_CloudBreak',
    'SCIENCE_Bombard',
    'SCIENCE_LightOfTrees',
    'SCIENCE_EagleAllies',
    'SCIENCE_RohanAllies',
    'SCIENCE_DunedainAllies',
    'SCIENCE_MenOfDaleAllies',
    'SCIENCE_Citadel',
    'SCIENCE_Flood',
    'SCIENCE_Sunflare',
    'SCIENCE_Earthquake',
    'SCIENCE_ArmyoftheDead'
] as const;

type ScienceType = typeof Sciences[number];

type FactionType = {
    name: string,
    nameSet: string,
    sciences: ScienceType[][]
}
type SciencesArrType = FactionType[]

const ScienceElves = {
    name: 'SCIENCE_ELVES',
    nameSet: 'Elves',
    sciences: [
        [
            'SCIENCE_Farsight',
            'SCIENCE_Rebuild',
            'SCIENCE_ElvenGifts',
            'SCIENCE_RallyingCallMP',
            'SCIENCE_Heal',
        ],
        [
            'SCIENCE_EnshroudingMistMP',
            'SCIENCE_ArrowVolleyGood',
            'SCIENCE_TomBombadil',
            'SCIENCE_SpawnLoneTower',
            'SCIENCE_DwarvenRiches',
            'SCIENCE_ElvenWood',
        ],
        [
            'SCIENCE_EagleAllies',
            'SCIENCE_Bombard',
            'SCIENCE_CloudBreak',
            'SCIENCE_LightOfTrees',
            'SCIENCE_EntAllies',
        ],
        [
            'SCIENCE_Earthquake',
            'SCIENCE_Sunflare',
            'SCIENCE_Flood',
            'SCIENCE_Citadel',
        ]
    ]
} as FactionType;

const ScienceMen = {
    name: 'SCIENCE_MEN',
    nameSet: 'Men',
    sciences: [
        [
            'SCIENCE_Farsight',
            'SCIENCE_Heal',
            'SCIENCE_Rebuild',
            'SCIENCE_RallyingCallMP',
            'SCIENCE_ElvenGifts',
        ],
        [
            'SCIENCE_EnshroudingMistMP',
            'SCIENCE_HobbitAllies',
            'SCIENCE_TomBombadil',
            'SCIENCE_SpawnLoneTower',
            'SCIENCE_ArrowVolleyGood',
            'SCIENCE_DwarvenRiches',
        ],
        [
            'SCIENCE_MenOfDaleAllies',
            'SCIENCE_DunedainAllies',
            'SCIENCE_CloudBreak',
            'SCIENCE_RohanAllies',
            'SCIENCE_EagleAllies',
        ],
        [
            'SCIENCE_Citadel',
            'SCIENCE_ArmyoftheDead',
            'SCIENCE_Earthquake',
            'SCIENCE_Sunflare',
        ]
    ]
} as FactionType;

const ScienceDwarves = {
    name: 'SCIENCE_DWARVES',
    nameSet: 'Dwarves',
    sciences: [
        [
            'SCIENCE_Farsight',
            'SCIENCE_RallyingCallMP',
            'SCIENCE_Heal',
            'SCIENCE_Rebuild',
            'SCIENCE_ElvenGifts',
        ],
        [
            'SCIENCE_EnshroudingMistMP',
            'SCIENCE_Undermine',
            'SCIENCE_HobbitAllies',
            'SCIENCE_SpawnLoneTower',
            'SCIENCE_DwarvenRiches',
            'SCIENCE_ElvenWood',
        ],
        [
            'SCIENCE_DunedainAllies',
            'SCIENCE_CloudBreak',
            'SCIENCE_Bombard',
            'SCIENCE_MenOfDaleAllies',
            'SCIENCE_EagleAllies',
        ],
        [
            'SCIENCE_Flood',
            'SCIENCE_Earthquake',
            'SCIENCE_Citadel',
            'SCIENCE_Sunflare',
        ]
    ]
} as FactionType;

const ScienceGood = {
    name: 'SCIENCE_GOOD',
    nameSet: 'Good',
    sciences: [
        [
            'SCIENCE_EnshroudingMistSP',
            'SCIENCE_ElvenGifts',
            'SCIENCE_Heal',
            'SCIENCE_ElvenWood',
            'SCIENCE_Farsight',
        ],
        [
            'SCIENCE_RallyingCall',
            'SCIENCE_TomBombadil',
            'SCIENCE_DwarvenRiches',
            'SCIENCE_Rebuild',
            'SCIENCE_SpawnLoneTower',
            'SCIENCE_ArrowVolleyGood',
        ],
        [
            'SCIENCE_MenOfDaleAllies',
            'SCIENCE_CloudBreak',
            'SCIENCE_Undermine',
            'SCIENCE_Bombard',
            'SCIENCE_DunedainAllies',
        ],
        [
            'SCIENCE_Flood',
            'SCIENCE_Earthquake',
            'SCIENCE_Sunflare',
            'SCIENCE_Citadel',
        ]
    ]
} as FactionType;

const ScienceArnor = {
    name: 'SCIENCE_ARNOR',
    nameSet: 'Arnor',
    sciences: ScienceMen.sciences,
} as FactionType;

const AllSciences = [
    ScienceGood,
    ScienceElves,
    ScienceDwarves,
    ScienceMen,
    ScienceArnor
] as SciencesArrType

type ScienceObj = {
    requires: string[][],
    costSP?: string,
    costMP?: string,
}

const map = new Map<string, ScienceObj>();

const findDeps = (faction: FactionType, level, index) => {
    if (level <= 0) {
        return [];
    }
    const prevLevel = faction.sciences[level - 1];
    const isBigger = prevLevel.length < faction.sciences[level].length;
    const parity = isBigger ? -1 : 1;
    const deps = []
    if (index + parity >= 0 && index + parity < prevLevel.length) {
        deps.push(prevLevel[index + parity])
    }

    if (index >= 0 && index < prevLevel.length) {
        deps.push(prevLevel[index])
    }
    return deps;
}

const createReqString = (arr: string[][]) => {
    return arr.map(values => values.join(' ')).join(' OR ');
}

const setCost = (level: number, faction: FactionType, sObj?: ScienceObj) => {
    if (!sObj) return;
    if (faction === ScienceGood) {
        sObj.costSP = 'GOOD_RANK_' + (level + 1) + '_COST'
    } else {
        sObj.costMP = 'GOOD_RANK_' + (level + 1) + '_COST'
    }
}

const printScience = (science: string, sObj: ScienceObj) => {
    console.log('Science ' + science);
    console.log('  PrerequisiteSciences = ' + createReqString(sObj.requires));
    console.log('  SciencePurchasePointCost = ' + (sObj.costSP ?? sObj.costMP ?? 1))
    console.log('  SciencePurchasePointCostMP = ' + (sObj.costMP ?? sObj.costSP ?? 1))
    console.log('  IsGrantable = Yes')
    console.log('End');
    console.log('\n')
}

const genSciences = () => {
    let sObj = undefined as ScienceObj | undefined, lIndex = 0, sIndex = -1, deps = [], hasError = false;
    Sciences.forEach((science) => {
        if (!map.has(science)) {
            map.set(science, {
                requires: [],
                costSP: undefined,
                costMP: undefined,
            })
        }
        sObj = map.get(science);
        AllSciences.forEach((faction) => {
            sIndex = -1;
            deps = [];
            for (lIndex = 0; lIndex < faction.sciences.length; lIndex++) {
                sIndex = faction.sciences[lIndex].indexOf(science);
                if (sIndex >= 0) {
                    if (lIndex === 0) {
                        sObj?.requires.push([faction.name]);
                    } else {
                        deps = findDeps(faction, lIndex, sIndex);
                        deps.forEach((dep) => {
                            if (!map.has(dep)) {
                                console.error(dep + ' should be before ' + science)
                                hasError = true;
                            }
                            sObj?.requires.push([faction.name, dep]);
                        })
                    }
                    setCost(lIndex, faction, sObj);
                    break;
                }
            }
        });
    })

    if (!hasError) {
        map.forEach((a, b) => {
            printScience(b, a);
        })
        //  printCommandSet(true, ScienceDwarves)
    }
}

const getCommandAlias = (science: ScienceType, faction: FactionType, purchase: boolean) => {
    if (faction === ScienceMen) {
        if (science === 'SCIENCE_SpawnLoneTower') {
            return purchase ? 'LoneTowerMen' : 'LoneTower'
        }
    }
    if (science === 'SCIENCE_SpawnLoneTower') {
        return purchase ? 'LoneTower' : 'LoneTowerDwarf'
    }
    if (!purchase && science === 'SCIENCE_EnshroudingMistSP') {
        return 'EnshroudingMist'
    }
    if(purchase && faction === ScienceGood && science === 'SCIENCE_RallyingCall') {
        return 'RallyingCallSP'
    }
    if(!purchase && science === 'SCIENCE_RallyingCallMP') {
        return 'RallyingCall'
    }
    if(!purchase && (science === 'SCIENCE_EnshroudingMistMP' || science === 'SCIENCE_EnshroudingMistSP')) {
        return 'EnshroudingMist'
    }
    return science;
}

const printCommandSet = (purchase: boolean, faction: FactionType) => {
    let index = 0;
    const str = purchase ? 'Command_PurchaseSpell' : 'Command_SpellBook';
    const strSetName = 'CommandSet'
    console.log('CommandSet ' + faction.nameSet + 'Spell' + (purchase ? 'Store' : 'Book') + 'CommandSet')
    faction.sciences.forEach((level) => {
        level.forEach(science => {
            index++;
            console.log('    ' + index + ' = ' + str + getCommandAlias(science, faction, purchase).replace('SCIENCE_', ''))
        })
        console.log('\n')
    })
    console.log('End')
    console.log('\n')
}

const genCommandSet = () => {
    AllSciences.forEach((faction) => {
        printCommandSet(false, faction)
        printCommandSet(true, faction)
    })
}

//genSciences();
genCommandSet();