/* Find all possible combinations of k numbers that add up to a number n, given that only
 * numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Note:
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Example 2:
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * https://leetcode.com/problems/combination-sum-iii/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 22, 2018
 */

// It takes 2 ms, which beats 100.00% of cpp submissions.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSum3Helper(k, n, 0, 1, out, res);
        return res;
    }
    
    void combinationSum3Helper(int k, int n, int level, int start, vector<int> &out, vector<vector<int>> &res) {
        if (n < 0) return;
        else if (n == 0 && level == k) res.push_back(out);
        else {
            if (level > k) return;
            else {
                for (int i = start; i < 10; i++) {
                    out.push_back(i);
                    combinationSum3Helper(k, n - i, level + 1, i + 1, out, res);
                    out.pop_back();
                }
            }
        }
    }
};
