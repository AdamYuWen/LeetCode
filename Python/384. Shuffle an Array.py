# Shuffle a set of numbers without duplicates.
# Example:
# // Init an array with set 1, 2, and 3.
# int[] nums = {1,2,3};
# Solution solution = new Solution(nums);
# // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
# solution.shuffle();
# // Resets the array back to its original configuration [1,2,3].
# solution.reset();
# // Returns the random shuffling of array [1,2,3].
# solution.shuffle();
# https://leetcode.com/problems/shuffle-an-array/description/
# 
# Author: Adam Yu Wen
# Date: July 13, 2018

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.privateNums = nums

        
    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.privateNums
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        # temp = self.privateNums is doing deepcopy
        # temp = self.privateNums[:] is copying the list

        # Another method is using shallow copy
        # temp = copy.copy(self.privateNums)
        temp = self.privateNums[:]
        random.shuffle(temp)
        return temp
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
