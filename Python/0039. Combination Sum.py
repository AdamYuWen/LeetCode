# Given a set of candidate numbers (candidates) (without duplicates) and a target
# number (target), find all unique combinations in candidates where the candidate
# numbers sums to target.
# The same repeated number may be chosen from candidates unlimited number of times.
# Note:
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# Example 1:
# Input: candidates = [2,3,6,7], target = 7,
# A solution set is:
# [
#   [7],
#   [2,2,3]
# ]
# Example 2:
# Input: candidates = [2,3,5], target = 8,
# A solution set is:
# [
#   [2,2,2,2],
#   [2,3,3],
#   [3,5]
# ]
# https://leetcode.com/problems/combination-sum/description/
# 
# Author: Adam Yu Wen
# Date: May 22, 2018

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        out, res = [], []
        self.combinationSumHelper(candidates, target, 0, out, res)
        return res
    
    def combinationSumHelper(self, candidates, target, start, out, res):
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
                out.append(candidates[i])
                self.combinationSumHelper(candidates, target - candidates[i], i, out, res)
                out.pop()
