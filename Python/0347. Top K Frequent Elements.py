# Given a non-empty array of integers, return the k most frequent elements.
# For example,
# Given [1,1,1,2,2,3] and k = 2, return [1,2].
# Note: 
# You may assume k is always valid, 1 <= k <= number of unique elements.
# Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
# https://leetcode.com/problems/top-k-frequent-elements/description/
# 
# Author: Adam Yu Wen
#
#Date: June 6, 2018

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        cnt = collections.Counter(nums)
        return sorted(cnt, key=cnt.get, reverse=True)[:k]
