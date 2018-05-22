# Given a collection of candidate numbers (candidates) and a target number (target),
# find all unique combinations in candidates where the candidate numbers sums to target.
# Each number in candidates may only be used once in the combination.
# Note:
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# Example 1:
# Input: candidates = [10,1,2,7,6,1,5], target = 8,
# A solution set is:
# [
#   [1, 7],
#   [1, 2, 5],
#   [2, 6],
#   [1, 1, 6]
# ]
# Example 2:
# Input: candidates = [2,5,2,1,2], target = 5,
# A solution set is:
# [
#   [1,2,2],
#   [5]
# ]
# https://leetcode.com/problems/combination-sum-ii/description/
# 
# Author: Adam Yu Wen
# Date: May 22, 2018

class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        out, res = [], []
        candidates.sort()
        self.combinationSum2Helper(candidates, target, 0, out, res)
        return res
        
    def combinationSum2Helper(self, candidates, target, start, out, res):
        """
        :type candidates: List[int]
        :type target: int
        :type start: int
        :type out: List[int]
        :type res: List[List[int]]
        :rtype: void
        """
        if target < 0:
            return
        elif target == 0:
            res.append(out[:])
        else:
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                out.append(candidates[i])
                self.combinationSum2Helper(candidates, target - candidates[i], i + 1, out, res)
                out.pop()
