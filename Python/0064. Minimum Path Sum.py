# Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
# right which minimizes the sum of all numbers along its path.
# Note: You can only move either down or right at any point in time.
# Example:
# Input:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1-3-1-1-1 minimizes the sum.
# https://leetcode.com/problems/minimum-path-sum/description/
# 
# Author: Adam Yu Wen
# Date: June 8, 2018

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rowNum = len(grid)
        colNum = len(grid[0])
        dp = [[0 for i in xrange(colNum)] for i in xrange(rowNum)]
        dp[0][0] = grid[0][0]
        for i in xrange(1, rowNum):
            dp[i][0] = grid[i][0] + dp[i - 1][0]
        for i in xrange(1, colNum):
            dp[0][i] = grid[0][i] + dp[0][i - 1]
        for i in xrange(1, rowNum):
            for j in xrange(1, colNum):
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]        
        
