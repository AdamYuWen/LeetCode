# Given a collection of distinct integers, return all possible permutations.
# Example:
# Input: [1,2,3]
# Output:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]
# https://leetcode.com/problems/permutations/description/
# 
# Author: Adam Yu Wen
# Date: May 21, 2018

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        visit = [0] * len(nums)
        out, res = [], []
        self.permuteDFS(nums, 0, visit, out, res)
        return res
        
    def permuteDFS(self, nums, level, visit, out, res):
        """
        :type nums: List[int]
        :type level: int
        :type visit: List[int]
        :type out: List[int]
        :type res: List[List[int]]
        :rtype: void
        """
        if len(nums) == level:
            # it is import to have [:], which means appending the list
            res.append(out[:])
            return
        else:
            for i in range(len(nums)):
                if visit[i] == 0:
                    visit[i] = 1
                    out.append(nums[i])
                    self.permuteDFS(nums, level + 1, visit, out, res)
                    del(out[-1])
                    visit[i] = 0
