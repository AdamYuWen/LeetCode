/* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * Example:
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 * https://leetcode.com/problems/permutations-ii/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 26, 2018
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> visited(nums.size(), 0);
        vector<int> out;
        sort(nums.begin(), nums.end());
        permuteUniqueHelper(nums, 0, visited, out, res);
        return res;
    }
    
    void permuteUniqueHelper(vector<int> &nums, int start, vector<int> &visited, vector<int> &out, vector<vector<int>> &res) {
        int numsSize = nums.size();
        if (start == numsSize) res.push_back(out);
        for (int i = 0; i < numsSize; i++) {
            if (visited[i] == 0) {
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
                visited[i] = 1;
                out.push_back(nums[i]);
                permuteUniqueHelper(nums, start + 1, visited, out, res);
                visited[i] = 0;
                out.pop_back();
            }
        }
    }
};
