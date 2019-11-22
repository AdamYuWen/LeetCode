/* Given a collection of distinct integers, return all possible permutations.
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 * https://leetcode.com/problems/permutations/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4358848.html
 * 
 * Author: Adam Yu Wen
 * Date: May 21, 2018
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<int> visited(nums.size(), 0);
        permuteDFS(nums, 0, visited, out, res);
        return res;
    }
    
    void permuteDFS(vector<int> &nums, int level, vector<int> &visited,
		    vector<int> &out, vector<vector<int>> &res) {
        if (level == nums.size()) {
            res.push_back(out);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    out.push_back(nums[i]);
                    permuteDFS(nums, level + 1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};
