/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
 * https://leetcode.com/problems/two-sum/
 *
 * Author: Adam Yu Wen
 * Date: November 2, 2016
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (myMap.count(diff) && myMap[diff] != i) {
                res.push_back(i);
                res.push_back(myMap[diff]);
                break;
            }
        }
        return res;
    }
};
