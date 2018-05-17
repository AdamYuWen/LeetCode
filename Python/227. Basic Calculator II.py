# Implement a basic calculator to evaluate a simple expression string.
# The expression string contains only non-negative integers, +, -, *, /
# operators and empty spaces . The integer division should truncate toward zero.
# Example 1:
# Input: "3+2*2"
# Output: 7
# Example 2:
# Input: " 3/2 "
# Output: 1
# Example 3:
# Input: " 3+5 / 2 "
# Output: 5
# Note:
# You may assume that the given expression is always valid.
# Do not use the eval built-in library function.
# https://leetcode.com/problems/basic-calculator-ii/description/
# 
# Author: Adam Yu Wen
# Date: May 17, 2018

class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, num, stack, op = 0, 0, [], '+'
        for i in range(len(s)):
            if s[i] >= '0':
                num = num * 10 + int(s[i]) - int('0')
            elif s[i] == ' ' and i != len(s) - 1:
                continue
                
            if s[i] < '0' or i == len(s) - 1:
                if op == '+':
                    stack.append(num)
                elif op == '-':
                    stack.append(-num)
                elif op == '*':
                    tmp = stack[-1]
                    stack.pop()
                    stack.append(tmp * num)
                elif op == '/':
                    tmp = stack[-1]
                    stack.pop()
                    # For -3/2 == -1
                    # In Python, it returns -2
                    if tmp > 0:
                        stack.append(tmp / num)
                    else:
                        stack.append((-tmp / num) * -1)
                op = s[i]
                num = 0
            
        for i in range(len(stack)):
            res += stack[-1]
            stack.pop()
        
        return res
