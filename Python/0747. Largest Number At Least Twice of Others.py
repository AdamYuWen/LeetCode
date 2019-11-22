# In a given integer array nums, there is always exactly one largest element.
# Find whether the largest element in the array is at least twice as much as every other number in the array.
# If it is, return the index of the largest element, otherwise return -1.
# Example 1:
# Input: nums = [3, 6, 1, 0]
# Output: 1
# Explanation: 6 is the largest integer, and for every other number in the array x,
# 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
# Example 2:
# Input: nums = [1, 2, 3, 4]
# Output: -1
# Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
# Note:
# nums will have a length in the range [1, 50].
# Every nums[i] will be an integer in the range [0, 99].
# https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
# 
# Author: Adam Yu Wen
# Date: June 22, 2018

# Method 1:
# It takes 51 ms.
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        largest = max(nums)
        idx = nums.index(max(nums))
        largestHalf = largest / 2
        for i, num in enumerate(nums):
            if i == idx:
                continue
            else:
                if num > largestHalf:
                    return -1
        return idx


# Method 2:
# It takes 41 ms.
# Find out the largest and the second largest number.
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        largest1Idx, largest1Val = -1, -1
        largest2Val = -2
        for i, num in enumerate(nums):
            if num > largest1Val:
                largest2Val = largest1Val
                largest1Val = num
                largest1Idx = i
            elif num > largest2Val:
                largest2Val = num
        if largest2Val * 2 > largest1Val:
            return -1
        else:
            return largest1Idx
