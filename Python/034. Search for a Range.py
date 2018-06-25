# Given an array of integers nums sorted in ascending order, find the starting and ending
# position of a given target value.
# Your algorithm's runtime complexity must be in the order of O(log n).
# If the target is not found in the array, return [-1, -1].
# Example 1:
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# Example 2:
# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]
# https://leetcode.com/problems/search-for-a-range/description/
# 
# Author: Adam Yu Wen
# Date: June 25, 2018

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lenNums = len(nums)
        if lenNums == 0:
            return [-1, -1]
        
        l, r = 0, lenNums - 1
        while l < r:
            m = int(l + (r - l) / 2)
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                l = m
                r = m
        if nums[l] != target:
            return [-1, -1]
        while l > 0 and nums[l - 1] == target:
            l -= 1
        while r < lenNums - 1 and nums[r + 1] == target:
            r += 1
        return [l, r]
