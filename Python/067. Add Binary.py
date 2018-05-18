# Given two binary strings, return their sum (also a binary string).
# The input strings are both non-empty and contains only characters 1 or 0.
# Example 1:
# Input: a = "11", b = "1"
# Output: "100"
# Example 2:
# Input: a = "1010", b = "1011"
# Output: "10101"
# https://leetcode.com/problems/add-binary/description/
# 
# Author: Adam Yu Wen
# Date: May 18, 2018

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        res = ""
        m = len(a) - 1
        n = len(b) - 1
        carry = 0
        while m >= 0 or n >= 0:
            if m >= 0:
                p = int(a[m]) - 0
                m  -= 1
            else:
                p = 0
            if n >= 0:
                q = int(b[n]) - 0
                n -= 1
            else:
                q = 0
            
            curSum = p + q + carry
            res = str(curSum % 2) + res
            carry = curSum / 2
        
        if carry == 1:
            return "1" + res
        else:
            return res
