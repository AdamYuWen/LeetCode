# Given a collection of intervals, merge all overlapping intervals.
# Example 1:
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
# Example 2:
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
# https://leetcode.com/problems/merge-intervals/description/
# 
# Author: Adam Yu Wen
# Date: June 13, 2018

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        res = []
        if not intervals:
            return intervals
        intervals.sort(key=lambda x: x.start)
        res.append(intervals[0])
        for i, interval in enumerate(intervals):
            if i == 0:
                continue
            if res[-1].end >= interval.start:
                res[-1].end = max(res[-1].end, interval.end)
            else:
                res.append(interval)
        return res
