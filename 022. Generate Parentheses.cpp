/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * https://leetcode.com/problems/generate-parentheses/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4444160.html
 *
 * Author: Adam Yu Wen
 * Date: May 14, 2018
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out = "";
        generateParenthesisHelp(n, n, out, res);
        return res;
    }
    
    void generateParenthesisHelp(int left, int right, string out, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(out);
        } else if (left <= right) {
            if (left > 0) generateParenthesisHelp(left - 1, right, out + "(", res);
            if (right > 0) generateParenthesisHelp(left, right - 1, out + ")", res);
        }
    }
};
