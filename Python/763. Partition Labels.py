# A string S of lowercase letters is given. We want to partition this string into as many parts as
# possible so that each letter appears in at most one part, and return a list of integers
# representing the size of these parts.
# Example 1:
# Input: S = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
# Note:
# S will have length in range [1, 500].
# S will consist of lowercase letters ('a' to 'z') only.
# https://leetcode.com/problems/partition-labels/description/
# 
# Author: Adam Yu Wen
# Date: May 24, 2018

class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        res = []
        lastIdx = [0] * 26
        for i in range(len(S)):
            lastIdx[ord(S[i]) - ord('a')] = i
        
        l, r = 0, 0
        for i in range(len(S)):
            if r < i:
                res.append(r - l + 1)
                l = r + 1
            r = max(r, lastIdx[ord(S[i]) - ord('a')])
        res.append(r - l + 1)
        return res
