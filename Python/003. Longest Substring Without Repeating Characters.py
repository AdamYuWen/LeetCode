# Given a string, find the length of the longest substring without repeating characters.
# Examples:
# Given "abcabcbb", the answer is "abc", which the length is 3.
# Given "bbbbb", the answer is "b", with the length of 1.
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be
# a substring, "pwke" is a subsequence and not a substring.
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# 
# Author: Adam Yu Wen
# Date: June 26, 2018

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, left = 0, 0
        mp = [0] * 256
        for i, c in enumerate(s):
            if mp[ord(c)] == 0 or mp[ord(c)] < left:
                res = max(res, i - left + 1)
            else:
                left = mp[ord(c)]
            mp[ord(c)] = i + 1
        return res
