# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
# The robot can only move either down or right at any point in time. The robot is trying to reach
# the bottom-right corner of the grid (marked 'Finish' in the diagram below).
# How many possible unique paths are there?
# 
# Above is a 7 x 3 grid. How many possible unique paths are there?
# Note: m and n will be at most 100.
# Example 1:
# Input: m = 3, n = 2
# Output: 3
# Explanation:
# From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
# 1. Right -> Right -> Down
# 2. Right -> Down -> Right
# 3. Down -> Right -> Right
# Example 2:
# Input: m = 7, n = 3
# Output: 28
# https://leetcode.com/problems/unique-paths/description/
# 
# Author: Adam Yu Wen
# Date: May 30, 2018

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = [[0 for i in range(n)] for j in range(m)]
        res[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i > 0:
                    res[i][j] += res[i - 1][j]
                if j > 0:
                    res[i][j] += res[i][j - 1]
        return res[m - 1][n - 1]
