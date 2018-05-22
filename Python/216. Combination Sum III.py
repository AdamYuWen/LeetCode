Find all possible combinations of k numbers that add up to a number n, given that only
numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
https://leetcode.com/problems/combination-sum-iii/description/

Author: Adam Yu Wen
Date: May 22, 2018

# Method 1:
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        out, res = [], []
        self.combinationSum3Helper(k, n, 0, 1, out, res)
        return res
        
    def combinationSum3Helper(self, k, n, level, start, out, res):
        """
        :type k: int
        :type n: int
        :type level: int
        :type start: int
        :type out: List[int]
        :type res: List[List[int]]
        :rtype: void
        """
        if n < 0:
            return
        elif n == 0 and k == level:
            res.append(out[:])
        else:
            if level > k:
                return
            for i in range(start, 10):
                out.append(i)
                self.combinationSum3Helper(k, n - i, level + 1, i + 1, out, res)
                out.pop()


# Method 2:
# It is a more faster solution from Leetcode.
class Solution(object):
    def combinationSum3(self, k, n):
        result=[]
        def dps(remain,Stack,start):
            if remain==0 and len(Stack)==k:
                result.append(Stack)
                return
            if len(Stack)>=k or remain==0: return
            for i in range(start,10):
                if i>remain: break
                dps(remain-i,Stack+[i],i+1)
        dps(n,[],1)
        return result
