# Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
# Example 1:
# Input: 
# [
#   [1,1,1],
#   [1,0,1],
#   [1,1,1]
# ]
# Output: 
# [
#   [1,0,1],
#   [0,0,0],
#   [1,0,1]
# ]
# Example 2:
# 
# Input: 
# [
#   [0,1,2,0],
#   [3,4,5,2],
#   [1,3,1,5]
# ]
# Output: 
# [
#   [0,0,0,0],
#   [0,4,5,0],
#   [0,3,1,0]
# ]
# Follow up:
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?
# https://leetcode.com/problems/set-matrix-zeroes/description/
# 
# Author: Adam Yu Wen
# Date: June 29, 2018

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        rowNum = len(matrix)
        colNum = len(matrix[0])
        zeroRows, zeroCols = [], []
        for i in xrange(rowNum):
            for j in xrange(colNum):
                if not matrix[i][j]:
                    zeroRows.append(i)
                    zeroCols.append(j)
        for i in zeroRows:
            for j in xrange(colNum):
                matrix[i][j] = 0
        for i in xrange(rowNum):
            for j in zeroCols:
                matrix[i][j] = 0
