/*
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * Example:
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        // Cannot use unordered_map,
        // because vector cannot be the key for unordered_map
        map<vector<int>, int> mp;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            int resSize = res.size();
            for (int j = 0; j < resSize; j++) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                if (!mp.count(temp)) {
                    res.push_back(temp);
                    mp[temp]++;
                }
                    
            }
        }
        return res;
    }
};
