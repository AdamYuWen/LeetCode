/* Given an array of integers nums sorted in ascending order, find the starting and ending
 * position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * https://leetcode.com/problems/search-for-a-range/description/
 * 
 * Author: Adam Yu Wen
 * Date: June 25, 2018
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // If the the nums is empty
        if (nums.size() == 0) {
            return vector<int> (2, -1);
        }
        // Find out a point equals to the target
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m;
                r = m;
            }
        }
        // If there is no target in nums
        if (nums[l] != target) {
            return vector<int> (2, -1);
        }
        // If the target is found in nums
        while (l > 0 && nums[l - 1] == target) {
            l--;
        }
        while (r < nums.size() - 1 && nums[r + 1] == target) {
            r++;
        }
        return vector<int> {l, r};
    }
};
