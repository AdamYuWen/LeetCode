# Given a string S, we can transform every letter individually to be lowercase
# or uppercase to create another string.  Return a list of all possible strings
# we could create.
# Examples:
# Input: S = "a1b2"
# Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
# Input: S = "3z4"
# Output: ["3z4", "3Z4"]
# Input: S = "12345"
# Output: ["12345"]
# Note:
# S will be a string with length at most 12.
# S will consist only of letters or digits.
# https://leetcode.com/problems/letter-case-permutation/description/
# 
# Author: Adam Yu Wen
# Date: May 23, 2018

class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = []
        self.letterCasePermutationHelper(S, 0, res)
        res.append(S)
        return res
        
    def letterCasePermutationHelper(self, S, start, res):
        """
        :type S: str
        :type start: int
        :type res: List[str]
        :rtype: void
        """
        for i in range(start, len(S)):
            if ord(S[i]) >= ord('a') and ord(S[i]) <= ord('z'):
                STmp = S[:i] + S[i].upper() + S[i + 1:]
                res.append(STmp)
                self.letterCasePermutationHelper(STmp, i + 1, res)
            elif ord(S[i]) >= ord('A') and ord(S[i]) <= ord('Z'):
                STmp = S[:i] + S[i].lower() + S[i + 1:]
                res.append(STmp)
                self.letterCasePermutationHelper(STmp, i + 1, res)
