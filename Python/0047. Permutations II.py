# Given a collection of numbers that might contain duplicates, return all possible unique permutations.
# Example:
# Input: [1,1,2]
# Output:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ]
# https://leetcode.com/problems/permutations-ii/description/
# 
# Author: Adam Yu Wen
# Date: May 31, 2018

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        visited = [0] * len(nums)
        out, res = [], []
        nums.sort()
        self.permuteUniqueHelper(nums, 0, visited, out, res)
        return res
        
    def permuteUniqueHelper(self, nums, start, visited, out, res):
        """
        :type nums: List[int]
        :type start: int
        :type visited: List[int]
        :type out: List[int]
        :type res: List[List[int]]
        """
        if len(nums) == start:
            res.append(out[:])
        for i in xrange(len(nums)):
            if visited[i] == 0:
                if i > 0 and nums[i] == nums[i - 1] and visited[i - 1] == 0:
                    continue
                visited[i] = 1
                out.append(nums[i])
                self.permuteUniqueHelper(nums, start + 1, visited, out, res)
                del out[-1]
                visited[i] = 0
