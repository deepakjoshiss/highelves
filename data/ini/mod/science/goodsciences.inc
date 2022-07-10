;======================= Created by <D.J.> =========================
;=================== Generated from Sciencegen =====================

Science SCIENCE_Farsight
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_ElvenGifts
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_Heal
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_RallyingCallMP
  PrerequisiteSciences = SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_EnshroudingMistSP
  PrerequisiteSciences = SCIENCE_GOOD
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_ElvenWood
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_ELVES SCIENCE_Heal OR SCIENCE_DWARVES SCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_1_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_Rebuild
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_Heal OR SCIENCE_GOOD SCIENCE_ElvenWood OR SCIENCE_ELVES OR SCIENCE_DWARVES OR SCIENCE_MEN OR SCIENCE_ARNOR
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_1_COST
  IsGrantable = Yes
End

Science SCIENCE_EnshroudingMistMP
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_Farsight OR SCIENCE_DWARVES SCIENCE_Farsight OR SCIENCE_MEN SCIENCE_Farsight OR SCIENCE_ARNOR SCIENCE_Farsight
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_ArrowVolleyGood
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_Farsight OR SCIENCE_ELVES SCIENCE_Farsight OR SCIENCE_ELVES SCIENCE_Rebuild OR SCIENCE_MEN SCIENCE_RallyingCallMP OR SCIENCE_MEN SCIENCE_ElvenGifts OR SCIENCE_ARNOR SCIENCE_RallyingCallMP OR SCIENCE_ARNOR SCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_TomBombadil
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_EnshroudingMistSP OR SCIENCE_GOOD SCIENCE_ElvenGifts OR SCIENCE_ELVES SCIENCE_Rebuild OR SCIENCE_ELVES SCIENCE_ElvenGifts OR SCIENCE_MEN SCIENCE_Heal OR SCIENCE_MEN SCIENCE_Rebuild OR SCIENCE_ARNOR SCIENCE_Heal OR SCIENCE_ARNOR SCIENCE_Rebuild
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_SpawnLoneTower
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_ElvenWood OR SCIENCE_GOOD SCIENCE_Farsight OR SCIENCE_ELVES SCIENCE_ElvenGifts OR SCIENCE_ELVES SCIENCE_RallyingCallMP OR SCIENCE_DWARVES SCIENCE_Heal OR SCIENCE_DWARVES SCIENCE_Rebuild OR SCIENCE_MEN SCIENCE_Rebuild OR SCIENCE_MEN SCIENCE_RallyingCallMP OR SCIENCE_ARNOR SCIENCE_Rebuild OR SCIENCE_ARNOR SCIENCE_RallyingCallMP
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_DwarvenRiches
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_ElvenGifts OR SCIENCE_GOOD SCIENCE_Heal OR SCIENCE_DWARVES SCIENCE_Rebuild OR SCIENCE_DWARVES SCIENCE_ElvenGifts OR SCIENCE_MEN SCIENCE_ElvenGifts OR SCIENCE_ARNOR SCIENCE_ElvenGifts
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_RingOfAdamant
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_RallyingCallMP OR SCIENCE_ELVES SCIENCE_Heal
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_HobbitAllies
  PrerequisiteSciences = SCIENCE_DWARVES SCIENCE_RallyingCallMP OR SCIENCE_DWARVES SCIENCE_Heal OR SCIENCE_MEN SCIENCE_Farsight OR SCIENCE_MEN SCIENCE_Heal OR SCIENCE_ARNOR SCIENCE_Farsight OR SCIENCE_ARNOR SCIENCE_Heal
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_RallyingCall
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_EnshroudingMistSP
  SciencePurchasePointCost = GOOD_RANK_2_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_Undermine
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_Rebuild OR SCIENCE_GOOD SCIENCE_DwarvenRiches OR SCIENCE_DWARVES SCIENCE_Farsight OR SCIENCE_DWARVES SCIENCE_RallyingCallMP
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_2_COST
  IsGrantable = Yes
End

Science SCIENCE_EntAllies
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_TomBombadil OR SCIENCE_ELVES SCIENCE_ArrowVolleyGood
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_CloudBreak
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_DwarvenRiches OR SCIENCE_GOOD SCIENCE_TomBombadil OR SCIENCE_ELVES SCIENCE_ElvenWood OR SCIENCE_ELVES SCIENCE_RingOfAdamant OR SCIENCE_DWARVES SCIENCE_HobbitAllies OR SCIENCE_DWARVES SCIENCE_Undermine OR SCIENCE_MEN SCIENCE_SpawnLoneTower OR SCIENCE_MEN SCIENCE_TomBombadil OR SCIENCE_ARNOR SCIENCE_SpawnLoneTower OR SCIENCE_ARNOR SCIENCE_TomBombadil
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_Bombard
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_SpawnLoneTower OR SCIENCE_GOOD SCIENCE_Rebuild OR SCIENCE_DWARVES SCIENCE_SpawnLoneTower OR SCIENCE_DWARVES SCIENCE_HobbitAllies
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_ElvenWaystone
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_SpawnLoneTower OR SCIENCE_ELVES SCIENCE_TomBombadil
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_LightOfTrees
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_RingOfAdamant OR SCIENCE_ELVES SCIENCE_SpawnLoneTower
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_EagleAllies
  PrerequisiteSciences = SCIENCE_ELVES SCIENCE_ArrowVolleyGood OR SCIENCE_ELVES SCIENCE_EnshroudingMistMP OR SCIENCE_DWARVES SCIENCE_ElvenWood OR SCIENCE_DWARVES SCIENCE_DwarvenRiches OR SCIENCE_MEN SCIENCE_DwarvenRiches OR SCIENCE_MEN SCIENCE_ArrowVolleyGood OR SCIENCE_ARNOR SCIENCE_DwarvenRiches OR SCIENCE_ARNOR SCIENCE_ArrowVolleyGood
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_RohanAllies
  PrerequisiteSciences = SCIENCE_MEN SCIENCE_ArrowVolleyGood OR SCIENCE_MEN SCIENCE_SpawnLoneTower OR SCIENCE_ARNOR SCIENCE_ArrowVolleyGood OR SCIENCE_ARNOR SCIENCE_SpawnLoneTower
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_DunedainAllies
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_ArrowVolleyGood OR SCIENCE_GOOD SCIENCE_SpawnLoneTower OR SCIENCE_DWARVES SCIENCE_Undermine OR SCIENCE_DWARVES SCIENCE_EnshroudingMistMP OR SCIENCE_MEN SCIENCE_TomBombadil OR SCIENCE_MEN SCIENCE_HobbitAllies OR SCIENCE_ARNOR SCIENCE_TomBombadil OR SCIENCE_ARNOR SCIENCE_HobbitAllies
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_MenOfDaleAllies
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_TomBombadil OR SCIENCE_GOOD SCIENCE_RallyingCall OR SCIENCE_DWARVES SCIENCE_DwarvenRiches OR SCIENCE_DWARVES SCIENCE_SpawnLoneTower OR SCIENCE_MEN SCIENCE_HobbitAllies OR SCIENCE_MEN SCIENCE_EnshroudingMistMP OR SCIENCE_ARNOR SCIENCE_HobbitAllies OR SCIENCE_ARNOR SCIENCE_EnshroudingMistMP
  SciencePurchasePointCost = GOOD_RANK_3_COST
  SciencePurchasePointCostMP = GOOD_RANK_3_COST
  IsGrantable = Yes
End

Science SCIENCE_Citadel
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_DunedainAllies OR SCIENCE_GOOD SCIENCE_Bombard OR SCIENCE_ELVES SCIENCE_CloudBreak OR SCIENCE_ELVES SCIENCE_LightOfTrees OR SCIENCE_DWARVES SCIENCE_MenOfDaleAllies OR SCIENCE_DWARVES SCIENCE_Bombard OR SCIENCE_MEN SCIENCE_DunedainAllies OR SCIENCE_MEN SCIENCE_MenOfDaleAllies OR SCIENCE_ARNOR SCIENCE_DunedainAllies OR SCIENCE_ARNOR SCIENCE_MenOfDaleAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science SCIENCE_Flood
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_CloudBreak OR SCIENCE_GOOD SCIENCE_MenOfDaleAllies OR SCIENCE_ELVES SCIENCE_LightOfTrees OR SCIENCE_ELVES SCIENCE_ElvenWaystone OR SCIENCE_DWARVES SCIENCE_CloudBreak OR SCIENCE_DWARVES SCIENCE_DunedainAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science SCIENCE_Sunflare
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_Bombard OR SCIENCE_GOOD SCIENCE_Undermine OR SCIENCE_ELVES SCIENCE_ElvenWaystone OR SCIENCE_ELVES SCIENCE_EntAllies OR SCIENCE_DWARVES SCIENCE_EagleAllies OR SCIENCE_DWARVES SCIENCE_MenOfDaleAllies OR SCIENCE_MEN SCIENCE_EagleAllies OR SCIENCE_MEN SCIENCE_RohanAllies OR SCIENCE_ARNOR SCIENCE_EagleAllies OR SCIENCE_ARNOR SCIENCE_RohanAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science SCIENCE_Earthquake
  PrerequisiteSciences = SCIENCE_GOOD SCIENCE_Undermine OR SCIENCE_GOOD SCIENCE_CloudBreak OR SCIENCE_ELVES SCIENCE_EntAllies OR SCIENCE_ELVES SCIENCE_EagleAllies OR SCIENCE_DWARVES SCIENCE_Bombard OR SCIENCE_DWARVES SCIENCE_CloudBreak OR SCIENCE_MEN SCIENCE_RohanAllies OR SCIENCE_MEN SCIENCE_CloudBreak OR SCIENCE_ARNOR SCIENCE_RohanAllies OR SCIENCE_ARNOR SCIENCE_CloudBreak
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

Science SCIENCE_ArmyoftheDead
  PrerequisiteSciences = SCIENCE_MEN SCIENCE_CloudBreak OR SCIENCE_MEN SCIENCE_DunedainAllies OR SCIENCE_ARNOR SCIENCE_CloudBreak OR SCIENCE_ARNOR SCIENCE_DunedainAllies
  SciencePurchasePointCost = GOOD_RANK_4_COST
  SciencePurchasePointCostMP = GOOD_RANK_4_COST
  IsGrantable = Yes
End

