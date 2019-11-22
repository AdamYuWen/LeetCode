/* Given a sorted array and a target value, return the index if the target
 * is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * Here are few examples.
 * [1,3,5,6], 5 -> 2
 * [1,3,5,6], 2 -> 1
 * [1,3,5,6], 7 -> 4
 * [1,3,5,6], 0 -> 0
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * Author: Adam Yu Wen
 * Date: July 12, 2017
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int idx = 0; idx < nums.size(); idx++) {
            if(nums[idx] == target) return idx;
            // if it is not the last element
            if(idx + 1 < nums.size()) {
                if(nums[idx] > target) return idx;
                if(nums[idx] < target && nums[idx + 1] > target) return idx + 1;
            }
            else {
                // when idx == nums.size() - 1, which is the last element
                if(nums[idx] < target) return idx + 1;
                else return idx;
            }
        }
    }
};
