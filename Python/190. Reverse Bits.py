# Reverse bits of a given 32 bits unsigned integer.
# Example:
# Input: 43261596
# Output: 964176192
# Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
#              return 964176192 represented in binary as 00111001011110000010100101000000.
# Follow up:
# If this function is called many times, how would you optimize it?
# https://leetcode.com/problems/reverse-bits/description/
# 
# Author: Adam Yu Wen
# Date: May 18, 2018

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        # Step 1:
        # >>> '{0:08b}'.format(6)
        # '00000110'
        #
        # Just to explain the parts of the formatting string:
        # {} places a variable into a string
        # 0 takes the variable at argument position 0
        # : adds formatting options for this variable (otherwise it would represent decimal 6)
        # 08 formats the number to eight digits zero-padded on the left
        # b converts the number to its binary representation
        
        # Step 2:
        # [::-1] ==> Reverse string
        
        # Step 3:
        # int(num, 2) ==> Convert a binary string to integer
        return int("{:032b}".format(n)[::-1], 2)
