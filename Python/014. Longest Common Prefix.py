# Write a function to find the longest common prefix string amongst an array of strings.
# https://leetcode.com/problems/longest-common-prefix/description/
# 
# Author: Adam Yu Wen
# Date: December 21, 2017

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        minLen = len(strs[0])
        for st in strs:
            minLen = min(minLen, len(st)) 
        for i in xrange(minLen, 0, -1):
            for j, st in enumerate(strs):
                if strs[0][:i] != st[:i]:
                    break
                if j == len(strs) - 1:
                    return strs[0][:i]
        return ""
