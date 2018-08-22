# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
# For example, given the following triangle
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
# Note:
# Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
# https://leetcode.com/problems/triangle/description/
# 
# Author: Adam Yu Wen
# Date: August 22, 2018

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) == 0:
            return 0
        elif len(triangle) == 1:
            return triangle[0][0]
        
        for prev, curr in zip(triangle, triangle[1:]):
            for i, v in enumerate(curr):
                if i == 0:
                    curr[i] += prev[i]
                elif i == len(curr) - 1:
                    curr[i] += prev[i - 1]
                else:
                    curr[i] += min(prev[i - 1], prev[i])
        return min(triangle[-1])
