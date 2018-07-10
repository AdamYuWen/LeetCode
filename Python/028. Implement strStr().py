# Implement strStr().
# Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
# Example 1:
#      Input: haystack = "hello", needle = "ll"
#      Output: 2
# Example 2:
#      Input: haystack = "aaaaa", needle = "bba"
#      Output: -1
# https://leetcode.com/problems/implement-strstr/description/
# 
# Author: Adam Yu Wen
# Date: July 10, 2018

# Its runtime beats 100.00% of python submissions.
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        lenDiff = len(haystack) - len(needle) + 1
        for i in xrange(lenDiff):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1
