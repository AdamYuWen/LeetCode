# Given a string containing digits from 2-9 inclusive, return all possible
# letter combinations that the number could represent.
# A mapping of digit to letters (just like on the telephone buttons) is
# given below. Note that 1 does not map to any letters.
# Example:
# Input: "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# Note:
# Although the above answer is in lexicographical order, your answer could
# be in any order you want.
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
# 
# Author: Adam Yu Wen
# Date: May 14, 2018

# The method takes 33 ms, which beats 98.00% of python submissions.
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        digitsLen = len(digits)
        if digitsLen == 0:
            return res
        elif digitsLen == 1:
            return self.numToLetter(digits)
        else:
            pre = self.letterCombinations(digits[:-1])
            for item in pre:
                appendStrs = self.numToLetter(digits[-1])
                for appendStr in appendStrs:
                    res.append(item)
                    res[-1] = res[-1] + appendStr
            return res
            
        
    def numToLetter(self, num):
        """
        :type num: str
        :rtype: List[str]
        """
        if num == "2":
            res = ["a", "b", "c"]
        elif num == "3":
            res = ["d", "e", "f"]
        elif num == "4":
            res = ["g", "h", "i"]
        elif num == "5":
            res = ["j", "k", "l"]
        elif num == "6":
            res = ["m", "n", "o"]
        elif num == "7":
            res = ["p", "q", "r", "s"]
        elif num == "8":
            res = ["t", "u", "v"]
        elif num == "9":
            res = ["w", "x", "y", "z"]
                
        return res
