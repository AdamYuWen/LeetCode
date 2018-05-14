 # Given an array of strings, group anagrams together.
 # Example:
 # Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 # Output:
 # [
 #   ["ate","eat","tea"],
 #   ["nat","tan"],
 #   ["bat"]
 # ]
 # Note:
 # All inputs will be in lowercase.
 # The order of your output does not matter.
 # https://leetcode.com/problems/group-anagrams/description/
 # 
 # Author: Adam Yu Wen
 # Date: May 14, 2018

 class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp = collections.defaultdict(list)
        res = []
        for str in strs:
            strTmp = "".join(sorted(str))
            mp[strTmp].append(str)
        for value in mp.itervalues():
            res.append(value)
        return res
