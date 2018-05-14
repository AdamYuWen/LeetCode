class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        out = ""
        self.generateParenthesisHelp(n, n, out, res)
        return res
        
    def generateParenthesisHelp(self, left, right, out, res):
        """
        :type left: int
              right: int
              out: str
              res: List[str]
        :rtype: List[str]
        """
        if left == 0 and right == 0:
            res.append(out)
        elif left <= right:
            if left > 0:
                self.generateParenthesisHelp(left - 1, right, out + "(", res)
            if right > 0:
                self.generateParenthesisHelp(left, right - 1, out + ")", res)
