# Given two strings s1 and s2, write a function to return true if s2 contains
# the permutation of s1. In other words, one of the first string's permutations
# is the substring of the second string.
# Example 1:
# Input:s1 = "ab" s2 = "eidbaooo"
# Output:True
# Explanation: s2 contains one permutation of s1 ("ba").
# Example 2:
# Input:s1= "ab" s2 = "eidboaoo"
# Output: False
# Note:
# The input strings only contain lower case letters.
# The length of both given strings is in range [1, 10,000].
# https://leetcode.com/problems/permutation-in-string/description/
# 
# Author: Adam Yu Wen
# Date: May 22, 2018

# It beats 100.00% of python submissions.
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s1Size = len(s1)
        s2Size = len(s2)
        if s1Size > s2Size:
            return False
        
        s1Mp = collections.defaultdict(int)
        s2Mp = collections.defaultdict(int)
        for i in range(s1Size):
            s1Mp[s1[i]] += 1
            s2Mp[s2[i]] += 1
            
        if s1Mp == s2Mp:
            return True
        for i in range(s2Size - s1Size):
            if s2Mp[s2[i]] == 1:
                del s2Mp[s2[i]]
            else:
                s2Mp[s2[i]] -= 1
            s2Mp[s2[i + s1Size]] += 1
            if s1Mp == s2Mp:
                return True
        return False
