; The High Elves faction (openbfme-godot docs/HIGHELVES.md)

Science HESCIENCE_Farsight
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_ElvenGifts
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_Heal
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_RallyingCallMP
  PrerequisiteSciences = SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_EnshroudingMistSP
  PrerequisiteSciences = SCIENCE_GOOD
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_ElvenWood
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES HESCIENCE_Heal OR SCIENCE_DWARVES HESCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_Rebuild
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_Heal OR SCIENCE_GOOD HESCIENCE_ElvenWood OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science HESCIENCE_EnshroudingMistMP
  PrerequisiteSciences = SCIENCE_ELVES HESCIENCE_Farsight OR SCIENCE_DWARVES HESCIENCE_Farsight OR SCIENCE_MEN HESCIENCE_Farsight OR SCIENCE_ARNOR HESCIENCE_Farsight
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_ArrowVolleyGood
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_Farsight OR SCIENCE_ELVES HESCIENCE_Farsight OR SCIENCE_ELVES HESCIENCE_Rebuild OR SCIENCE_MEN HESCIENCE_RallyingCallMP OR SCIENCE_MEN HESCIENCE_ElvenGifts OR SCIENCE_ARNOR HESCIENCE_RallyingCallMP OR SCIENCE_ARNOR HESCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_TomBombadil
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_EnshroudingMistSP OR SCIENCE_GOOD HESCIENCE_ElvenGifts OR SCIENCE_ELVES HESCIENCE_Rebuild OR SCIENCE_ELVES HESCIENCE_ElvenGifts OR SCIENCE_MEN HESCIENCE_Heal OR SCIENCE_MEN HESCIENCE_Rebuild OR SCIENCE_ARNOR HESCIENCE_Heal OR SCIENCE_ARNOR HESCIENCE_Rebuild
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_SpawnLoneTower
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_ElvenWood OR SCIENCE_GOOD HESCIENCE_Farsight OR SCIENCE_ELVES HESCIENCE_ElvenGifts OR SCIENCE_ELVES HESCIENCE_RallyingCallMP OR SCIENCE_DWARVES HESCIENCE_Heal OR SCIENCE_DWARVES HESCIENCE_Rebuild OR SCIENCE_MEN HESCIENCE_Rebuild OR SCIENCE_MEN HESCIENCE_RallyingCallMP OR SCIENCE_ARNOR HESCIENCE_Rebuild OR SCIENCE_ARNOR HESCIENCE_RallyingCallMP
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_DwarvenRiches
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_ElvenGifts OR SCIENCE_GOOD HESCIENCE_Heal OR SCIENCE_DWARVES HESCIENCE_Rebuild OR SCIENCE_DWARVES HESCIENCE_ElvenGifts OR SCIENCE_MEN HESCIENCE_ElvenGifts OR SCIENCE_ARNOR HESCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_RingOfAdamant
  PrerequisiteSciences = SCIENCE_ELVES HESCIENCE_RallyingCallMP OR SCIENCE_ELVES HESCIENCE_Heal
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_HobbitAllies
  PrerequisiteSciences = SCIENCE_DWARVES HESCIENCE_RallyingCallMP OR SCIENCE_DWARVES HESCIENCE_Heal OR SCIENCE_MEN HESCIENCE_Farsight OR SCIENCE_MEN HESCIENCE_Heal OR SCIENCE_ARNOR HESCIENCE_Farsight OR SCIENCE_ARNOR HESCIENCE_Heal
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_RallyingCall
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_EnshroudingMistSP
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_Undermine
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_Rebuild OR SCIENCE_GOOD HESCIENCE_DwarvenRiches OR SCIENCE_DWARVES HESCIENCE_Farsight OR SCIENCE_DWARVES HESCIENCE_RallyingCallMP
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science HESCIENCE_EntAllies
  PrerequisiteSciences = SCIENCE_ELVES HESCIENCE_TomBombadil OR SCIENCE_ELVES HESCIENCE_ArrowVolleyGood
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_CloudBreak
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_DwarvenRiches OR SCIENCE_GOOD HESCIENCE_TomBombadil OR SCIENCE_ELVES HESCIENCE_ElvenWood OR SCIENCE_ELVES SCIENCE_RingOfAdamant OR SCIENCE_DWARVES HESCIENCE_HobbitAllies OR SCIENCE_DWARVES HESCIENCE_Undermine OR SCIENCE_MEN HESCIENCE_SpawnLoneTower OR SCIENCE_MEN HESCIENCE_TomBombadil OR SCIENCE_ARNOR HESCIENCE_SpawnLoneTower OR SCIENCE_ARNOR HESCIENCE_TomBombadil
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_Bombard
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_SpawnLoneTower OR SCIENCE_GOOD HESCIENCE_Rebuild OR SCIENCE_DWARVES HESCIENCE_SpawnLoneTower OR SCIENCE_DWARVES HESCIENCE_HobbitAllies
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_ElvenWaystone
  PrerequisiteSciences = SCIENCE_ELVES HESCIENCE_SpawnLoneTower OR SCIENCE_ELVES HESCIENCE_TomBombadil
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_LightOfTrees
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_RingOfAdamant OR SCIENCE_ELVES HESCIENCE_SpawnLoneTower
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_EagleAllies
  PrerequisiteSciences = SCIENCE_ELVES HESCIENCE_ArrowVolleyGood OR SCIENCE_ELVES HESCIENCE_EnshroudingMistMP OR SCIENCE_DWARVES HESCIENCE_ElvenWood OR SCIENCE_DWARVES HESCIENCE_DwarvenRiches OR SCIENCE_MEN HESCIENCE_DwarvenRiches OR SCIENCE_MEN HESCIENCE_ArrowVolleyGood OR SCIENCE_ARNOR HESCIENCE_DwarvenRiches OR SCIENCE_ARNOR HESCIENCE_ArrowVolleyGood
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_RohanAllies
  PrerequisiteSciences = SCIENCE_MEN HESCIENCE_ArrowVolleyGood OR SCIENCE_MEN HESCIENCE_SpawnLoneTower OR SCIENCE_ARNOR HESCIENCE_ArrowVolleyGood OR SCIENCE_ARNOR HESCIENCE_SpawnLoneTower
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_DunedainAllies
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_ArrowVolleyGood OR SCIENCE_GOOD HESCIENCE_SpawnLoneTower OR SCIENCE_DWARVES HESCIENCE_Undermine OR SCIENCE_DWARVES HESCIENCE_EnshroudingMistMP OR SCIENCE_MEN HESCIENCE_TomBombadil OR SCIENCE_MEN HESCIENCE_HobbitAllies OR SCIENCE_ARNOR HESCIENCE_TomBombadil OR SCIENCE_ARNOR HESCIENCE_HobbitAllies
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_MenOfDaleAllies
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_TomBombadil OR SCIENCE_GOOD HESCIENCE_RallyingCall OR SCIENCE_DWARVES HESCIENCE_DwarvenRiches OR SCIENCE_DWARVES HESCIENCE_SpawnLoneTower OR SCIENCE_MEN HESCIENCE_HobbitAllies OR SCIENCE_MEN HESCIENCE_EnshroudingMistMP OR SCIENCE_ARNOR HESCIENCE_HobbitAllies OR SCIENCE_ARNOR HESCIENCE_EnshroudingMistMP
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science HESCIENCE_Citadel
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_DunedainAllies OR SCIENCE_GOOD HESCIENCE_Bombard OR SCIENCE_ELVES HESCIENCE_CloudBreak OR SCIENCE_ELVES SCIENCE_LightOfTrees OR SCIENCE_DWARVES HESCIENCE_MenOfDaleAllies OR SCIENCE_DWARVES HESCIENCE_Bombard OR SCIENCE_MEN HESCIENCE_DunedainAllies OR SCIENCE_MEN HESCIENCE_MenOfDaleAllies OR SCIENCE_ARNOR HESCIENCE_DunedainAllies OR SCIENCE_ARNOR HESCIENCE_MenOfDaleAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science HESCIENCE_Flood
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_CloudBreak OR SCIENCE_GOOD HESCIENCE_MenOfDaleAllies OR SCIENCE_ELVES SCIENCE_LightOfTrees OR SCIENCE_ELVES SCIENCE_ElvenWaystone OR SCIENCE_DWARVES HESCIENCE_CloudBreak OR SCIENCE_DWARVES HESCIENCE_DunedainAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science HESCIENCE_Sunflare
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_Bombard OR SCIENCE_GOOD HESCIENCE_Undermine OR SCIENCE_ELVES SCIENCE_ElvenWaystone OR SCIENCE_ELVES HESCIENCE_EntAllies OR SCIENCE_DWARVES HESCIENCE_EagleAllies OR SCIENCE_DWARVES HESCIENCE_MenOfDaleAllies OR SCIENCE_MEN HESCIENCE_EagleAllies OR SCIENCE_MEN HESCIENCE_RohanAllies OR SCIENCE_ARNOR HESCIENCE_EagleAllies OR SCIENCE_ARNOR HESCIENCE_RohanAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science HESCIENCE_Earthquake
  PrerequisiteSciences = SCIENCE_GOOD HESCIENCE_Undermine OR SCIENCE_GOOD HESCIENCE_CloudBreak OR SCIENCE_ELVES HESCIENCE_EntAllies OR SCIENCE_ELVES HESCIENCE_EagleAllies OR SCIENCE_DWARVES HESCIENCE_Bombard OR SCIENCE_DWARVES HESCIENCE_CloudBreak OR SCIENCE_MEN HESCIENCE_RohanAllies OR SCIENCE_MEN HESCIENCE_CloudBreak OR SCIENCE_ARNOR HESCIENCE_RohanAllies OR SCIENCE_ARNOR HESCIENCE_CloudBreak
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science HESCIENCE_ArmyoftheDead
  PrerequisiteSciences = SCIENCE_MEN HESCIENCE_CloudBreak OR SCIENCE_MEN HESCIENCE_DunedainAllies OR SCIENCE_ARNOR HESCIENCE_CloudBreak OR SCIENCE_ARNOR HESCIENCE_DunedainAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End
