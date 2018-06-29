# A peak element is an element that is greater than its neighbors.
# Given an input array nums, where nums[i] != nums[i+1], find a peak element and return its index.
# The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
# You may imagine that nums[-1] = nums[n] = -Inf.
# Example 1:
# Input: nums = [1,2,3,1]
# Output: 2
# Explanation: 3 is a peak element and your function should return the index number 2.
# Example 2:
# Input: nums = [1,2,1,3,5,6,4]
# Output: 1 or 5 
# Explanation: Your function can return either index number 1 where the peak element is 2, 
#              or index number 5 where the peak element is 6.
# Note:
# Your solution should be in logarithmic complexity.
# https://leetcode.com/problems/find-peak-element/description/
# 
# Author: Adam Yu Wen
# Date: June 29, 2018

# Mehotd 1:
# It takes 54 ms.
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numsSize = len(nums)
        if numsSize == 0:
            return -1
        if numsSize == 1:
            return 0
        for i in xrange(numsSize):
            if i == 0:
                if nums[i] > nums[i + 1]:
                    return i
            elif i == numsSize - 1:
                if nums[i] > nums[i - 1]:
                    return i
            else:
                if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                    return i
        return -1


# Methode 2:
# It takes 30 ms.
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) / 2
            if nums[mid] >= nums[mid + 1]:
                r = mid
            else:
                l = mid+1
        return l
