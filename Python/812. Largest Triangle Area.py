# You have a list of points in the plane. Return the area of the largest triangle that can be
# formed by any 3 of the points.
# Example:
# Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
# Output: 2
# Explanation: 
# The five points are show in the figure below. The red triangle is the largest.
# 
# Notes:
# 3 <= points.length <= 50.
# No points will be duplicated.
#  -50 <= points[i][j] <= 50.
# Answers within 10^-6 of the true value will be accepted as correct.
# 
# Author: Adam Yu Wen
# Date: June 21, 2018

# It takes 1012 ms, which should be improved.
class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        res = 0
        permutationsLists = itertools.permutations(points, 3)
        for permutationsList in permutationsLists:
            res = max(self.triangleArea(permutationsList[0],
                                        permutationsList[1],
                                        permutationsList[2]), res)
        return res
        
        
    def triangleArea(self, point1, point2, point3):
        """
        :type point1: List[int]
        :type point2: List[int]
        :type point3: List[int]
        :rtype: float
        """
        return abs((point1[0] * (point2[1] - point3[1]) +
                    point2[0] * (point3[1] - point1[1]) +
                    point3[0] * (point1[1] - point2[1])) / 2.0)
