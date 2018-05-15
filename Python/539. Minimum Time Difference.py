# Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum
# minutes difference between any two time points in the list.
# Example 1:
# Input: ["23:59","00:00"]
# Output: 1
# Note:
# The number of time points in the given list is at least 2 and won't exceed 20000.
# The input time is legal and ranges from 00:00 to 23:59.
# https://leetcode.com/problems/minimum-time-difference/description/
# Reference: https://leetcode.com/problems/minimum-time-difference/discuss/100637/Python-Straightforward-with-Explanation
# 
# Author: Adam Yu Wen
# Date: May 15, 2018

class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        def convertMin(time):
            return int(time[:2]) * 60 + int(time[-2:])
        minutes = map(convertMin, timePoints)
        minutes.sort()
        # In Python, -1439 % 1440 == 1       -1441 % 1440 == 1439
        # In C++,    -1439 % 1440 == -1439   -1441 % 1440 == -1
        # Add the last element to the second list
        return min((y - x) % 1440 for x, y in zip(minutes, minutes[1:] + minutes[:1]))
