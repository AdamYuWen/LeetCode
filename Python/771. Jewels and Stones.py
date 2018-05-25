# You're given strings J representing the types of stones that are jewels, and S
# representing the stones you have.  Each character in S is a type of stone you
# have.  You want to know how many of the stones you have are also jewels.
# The letters in J are guaranteed distinct, and all characters in J and S are
# letters. Letters are case sensitive, so "a" is considered a different type of
# stone from "A".
# Example 1:
# Input: J = "aA", S = "aAAbbbb"
# Output: 3
# Example 2:
# Input: J = "z", S = "ZZ"
# Output: 0
# Note:
# S and J will consist of letters and have length at most 50.
# The characters in J are distinct.
# https://leetcode.com/problems/jewels-and-stones/description/
# 
# Author: Adam Yu Wen
# Date: May 25, 2018

# Method 1:
# It takes 47 ms.
class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        res = 0
        Jcnt = collections.Counter(J)
        Scnt = collections.Counter(S)
        
        for key in Jcnt.keys():
            if key in Scnt.keys():
                res += Scnt[key]
        return res


# Method 2:
# It takes 35 ms and it comes from LeetCode.
class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        J = set(J)
        for i in S:
            if i in J:
                count += 1
        return count
