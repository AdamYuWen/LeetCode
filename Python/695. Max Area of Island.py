# Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
# 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
# Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
# Example 1:
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],
#  [0,0,0,0,0,0,0,1,1,1,0,0,0],
#  [0,1,1,0,1,0,0,0,0,0,0,0,0],
#  [0,1,0,0,1,1,0,0,1,0,1,0,0],
#  [0,1,0,0,1,1,0,0,1,1,1,0,0],
#  [0,0,0,0,0,0,0,0,0,0,1,0,0],
#  [0,0,0,0,0,0,0,1,1,1,0,0,0],
#  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
# Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
# Example 2:
# [[0,0,0,0,0,0,0,0]]
# Given the above grid, return 0.
# Note: The length of each dimension in the given grid does not exceed 50.
# https://leetcode.com/problems/max-area-of-island/description/
# 
# Author: Adam Yu Wen
# Date: August 17, 2018

class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rowNum = len(grid)
        if rowNum == 0:
            return 0
        colNum = len(grid[0])
        
        visited = [[False for x in range(colNum)] for y in range(rowNum)]
        res = 0
        for i in xrange(rowNum):
            for j in xrange(colNum):
               res = max(res, self.countArea(grid, rowNum, colNum, visited, i, j))
        return res
        
    def countArea(self, grid, rowNum, colNum, visited, row, col):
        if row < 0 or row >= rowNum or col < 0 or col >= colNum or visited[row][col] or grid[row][col] == 0:
            return 0
        else:
            visited[row][col] = True
            return 1 + \
                   self.countArea(grid, rowNum, colNum, visited, row - 1, col) + \
                   self.countArea(grid, rowNum, colNum, visited, row + 1, col) + \
                   self.countArea(grid, rowNum, colNum, visited, row, col - 1) + \
                   self.countArea(grid, rowNum, colNum, visited, row, col + 1)
