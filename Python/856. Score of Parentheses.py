# Given a balanced parentheses string S, compute the score of the string based on the following rule:
# () has score 1
# AB has score A + B, where A and B are balanced parentheses strings.
# (A) has score 2 * A, where A is a balanced parentheses string.
# Example 1:
#   Input: "()"
#   Output: 1
# Example 2:
#   Input: "(())"
#   Output: 2
# Example 3:
#   Input: "()()"
#   Output: 2
# Example 4:
#   Input: "(()(()))"
#   Output: 6
# Note:
#   S is a balanced parentheses string, containing only ( and ).
#   2 <= S.length <= 50
# https://leetcode.com/problems/score-of-parentheses/description/
# 
# Author: Adam Yu Wen
# Date: August 21, 2018

class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = [0]
        for i, s in enumerate(S):
            if s == '(':
                stack.append(0)
            else:
                temp = stack[-1]
                del stack[-1]
                if S[i - 1] == '(':
                    stack[-1] += 1
                else:
                    stack[-1] += temp * 2
        return stack[-1]
