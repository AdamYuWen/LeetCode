# Given a string, your task is to count how many palindromic substrings in this string.
# The substrings with different start indexes or end indexes are counted as different
# substrings even they consist of same characters.
# Example 1:
# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
# Example 2:
# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# Note:
# The input string length won't exceed 1000.
# https://leetcode.com/problems/palindromic-substrings/description/
# 
# Author: Adam Yu Wen
# Date: June 5, 2018

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        # The size of substrings
        for i in xrange(1, len(s) + 1):
            # Different substrings with the same size
            for j in xrange(len(s) - i + 1):
                if s[j:j + i] == s[j:j + i][::-1]:
                    res += 1
        return res
