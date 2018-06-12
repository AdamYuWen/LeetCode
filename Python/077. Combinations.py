# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
# Example:
# Input: n = 4, k = 2
# Output:
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]
# https://leetcode.com/problems/combinations/description/
# 
# Author: Adam Yu Wen
# Date: June 12, 2018

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        res = []
        resTmp = itertools.combinations(range(1, n + 1), k)
        for i in list(resTmp):
            res.append(i)
        return res
