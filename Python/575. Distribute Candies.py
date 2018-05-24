# Given an integer array with even length, where different numbers in this array represent
# different kinds of candies. Each number means one candy of the corresponding kind. You need
# to distribute these candies equally in number to brother and sister. Return the maximum
# number of kinds of candies the sister could gain.
# Example 1:
# Input: candies = [1,1,2,2,3,3]
# Output: 3
# Explanation:
# There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
# Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
# The sister has three different kinds of candies. 
# Example 2:
# Input: candies = [1,1,2,3]
# Output: 2
# Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
# The sister has two different kinds of candies, the brother has only one kind of candies. 
# Note:
# The length of the given array is in range [2, 10,000], and will be even.
# The number in given array is in range [-100,000, 100,000].
# https://leetcode.com/problems/distribute-candies/description/
# 
# Author: Adam Yu Wen
# Date: May 24, 2018

# Method 1:
# It is slow, which takes 758 ms.
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        cnt = collections.Counter(candies)
        return min(len(candies) / 2, len(cnt.keys()))


# Method 2:
# It takes 171 ms, which is much faster than Method 1.
# Using set instead using Counter.
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        cnt = set(candies)
        return min(len(candies) / 2, len(cnt))
