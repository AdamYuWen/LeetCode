# Given a positive integer N, find and return the longest distance between two consecutive 1's
# in the binary representation of N.
# If there aren't two consecutive 1's, return 0.
# Example 1:
#   Input: 22
#   Output: 2
#   Explanation: 
#   22 in binary is 0b10110.
#   In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
#   The first consecutive pair of 1's have distance 2.
#   The second consecutive pair of 1's have distance 1.
#   The answer is the largest of these two distances, which is 2.
# Example 2:
#   Input: 5
#   Output: 2
#   Explanation: 
#   5 in binary is 0b101.
# Example 3:
#   Input: 6
#   Output: 1
#   Explanation: 
#   6 in binary is 0b110.
# Example 4:
#   Input: 8
#   Output: 0
#   Explanation: 
#   8 in binary is 0b1000.
#   There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
# Note:
# 1 <= N <= 10^9
# https://leetcode.com/contest/weekly-contest-93/problems/binary-gap/
# 
# Author: Adam Yu Wen
# Date: July 16, 2018


# Method 1:
class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        res = 0
        binary = bin(N)
        l, r = -1, 0
        for idx, num in enumerate(binary):
            if l == -1 and num == '1':
                l, r = idx, idx
            elif num == '1':
                r = idx
                res = max(res, r - l)
                l = r
        return res


# Method 2:
# Reference: https://leetcode.com/problems/binary-gap/discuss/149835/C++JavaPython-Dividing-by-2
class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        index = [i for i, v in enumerate(bin(N)) if v == '1']
        # If b - a create a empty list, return [0]
        return max([b - a for a, b in zip(index, index[1:])] or [0])
