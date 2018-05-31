# Given a sorted array consisting of only integers where every element
# appears twice except for one element which appears once. Find this
# single element that appears only once.
# Example 1:
# Input: [1,1,2,3,3,4,4,8,8]
# Output: 2
# Example 2:
# Input: [3,3,7,7,10,11,11]
# Output: 10
# Note: Your solution should run in O(log n) time and O(1) space.
# https://leetcode.com/problems/single-element-in-a-sorted-array/description/
# 
# Author: Adam Yu Wen
# Date: May 31, 2018

class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        while l < r:
            m = int(l + (r - l) / 2)
            if m > 0 and nums[m - 1] == nums[m]:
                if m % 2 == 1:
                    l = m + 1
                else:
                    r = m - 2
            elif m + 1 < len(nums) and nums[m] == nums[m + 1]:
                if m % 2 == 0:
                    l = m + 2
                else:
                    r = m - 1
            else:
                return nums[m]
        return nums[l]
