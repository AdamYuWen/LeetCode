# Given a 2D integer matrix M representing the gray scale of an image, you need
# to design a smoother to make the gray scale of each cell becomes the average
# gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell
# has less than 8 surrounding cells, then use as many as you can.
# Example 1:
# Input:
# [[1,1,1],
#  [1,0,1],
#  [1,1,1]]
# Output:
# [[0, 0, 0],
#  [0, 0, 0],
#  [0, 0, 0]]
# Explanation:
# For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
# For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
# For the point (1,1): floor(8/9) = floor(0.88888889) = 0
# Note:
# The value in the given matrix is in the range of [0, 255].
# The length and width of the given matrix are in the range of [1, 150].
# https://leetcode.com/problems/image-smoother/description/
# 
# Author: Adam Yu Wen
# Date: May 31, 2018

class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        # In python, res = M doesn't work like C++
        # http://henry.precheur.org/python/copy_list
        res = [[0 for i in xrange(len(M[0]))] for j in xrange(len(M))]
        for i in xrange(len(M)):
            for j in xrange(len(M[0])):
                res[i][j] = self.averageGrayScale(i, j, M)
        return res
        
    def averageGrayScale(self, x, y, M):
        """
        :type x: int
        :type y: int
        :type M: List[List[int]]
        :rtype: int
        """
        curSum = 0
        cnt = 0
        for i in xrange(-1, 2):
            for j in xrange(-1, 2):
                if x + i > -1 and y + j > -1 and x + i < len(M) and y + j < len(M[0]):
                    curSum += M[x + i][y + j]
                    cnt += 1
        return curSum / cnt
