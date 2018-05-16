# Given a non-empty array of non-negative integers nums, the degree of this
# array is defined as the maximum frequency of any one of its elements.
# Your task is to find the smallest possible length of a (contiguous) subarray
# of nums, that has the same degree as nums.
# Example 1:
# Input: [1, 2, 2, 3, 1]
# Output: 2
# Explanation: 
# The input array has a degree of 2 because both elements 1 and 2 appear twice.
# Of the subarrays that have the same degree:
# [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
# The shortest length is 2. So return 2.
# Example 2:
# Input: [1,2,2,3,1,4,2]
# Output: 6
# Note:
# nums.length will be between 1 and 50,000.
# nums[i] will be an integer between 0 and 49,999.
# https://leetcode.com/problems/degree-of-an-array/description/
# Reference: https://leetcode.com/problems/degree-of-an-array/discuss/108666/Python-easy-and-concise-solution
# 
# Author: Adam Yu Wen
# Date: May 16, 2018

class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.Counter(nums)
        degree = max(cnt.values())
        mp = collections.defaultdict(list)
        for i in range(len(nums)):
            mp[nums[i]].append(i)
        return min(mp[k][-1] - mp[k][0] + 1 for k in mp.keys() if cnt[k] == degree)
            
