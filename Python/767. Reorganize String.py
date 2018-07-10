# Given a string S, check if the letters can be rearranged so that two characters that
# are adjacent to each other are not the same.
# If possible, output any possible result.  If not possible, return the empty string.
# Example 1:
# Input: S = "aab"
# Output: "aba"
# Example 2:
# Input: S = "aaab"
# Output: ""
# Note:
# S will consist of lowercase letters and have length in range [1, 500].
# 
# Author: Adam Yu Wen
# Date: July 10, 2018

from heapq import heappush, heappop
class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        res = ""
        cnt = collections.Counter(S)
        if cnt.most_common(1)[0][1] > (len(S) + 1) / 2:
            return res
        
        heap = []
        for i in cnt.keys():
            heappush(heap, (-1 * cnt[i], i))
        
        while (len(heap) > 1):
            h1 = heappop(heap)
            h2 = heappop(heap)
            res += h1[1]
            res += h2[1]
            if h1[0] + 1 < 0:
                heappush(heap, (h1[0] + 1, h1[1]))
            if h2[0] + 1 < 0:
                heappush(heap, (h2[0] + 1, h2[1]))
                
        if len(heap) == 1:
            res += heap[0][1]
        return res
