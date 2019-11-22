# Given a string S and a character C, return an array of integers representing the shortest distance
# from the character C in the string.
# 
# Example 1:
# Input: S = "loveleetcode", C = 'e'
# Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
#  
# Note:
# S string length is in [1, 10000].
# C is a single character, and guaranteed to be in string S.
# All letters in S and C are lowercase.
# https://leetcode.com/problems/shortest-distance-to-a-character/
# 
# Author: Adam Yu Wen
# Date: December 13, 2018

class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        res = []
        for idx in range(len(S)):
            beforeIdx = S[:idx].rfind(C)
            afterIdx = S[idx:].find(C)
            
            if beforeIdx != -1 and afterIdx != -1:
                res.append(min(idx - beforeIdx, afterIdx))
            elif beforeIdx != -1:
                res.append(idx - beforeIdx)
            else:
                res.append(afterIdx)
        return res
