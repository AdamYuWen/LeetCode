/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * https://leetcode.com/problems/combinations/description/
 *
 * Author: Adam Yu Wen
 * Date: June 12, 2018
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> visited(n, 0);
        vector<int> out;
        vector<vector<int>> res;
        int visitedNum = 0;
        combineHelper(n, k, visited, 0, visitedNum, out, res);
        return res;
    }
    
    void combineHelper(int n, int k, vector<int> &visited, int start, int &visitedNum, vector<int> &out, vector<vector<int>> &res) {
        if (k == visitedNum) res.push_back(out);
        for (int i = start; i < n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                visitedNum++;
                out.push_back(i + 1);
                combineHelper(n, k, visited, i + 1,  visitedNum, out, res);
                out.pop_back();
                visitedNum--;
                visited[i] = 0;
            }
        }
    }
};
