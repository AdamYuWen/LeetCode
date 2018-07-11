/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * Author: Adam Yu Wen
 * Date: July 06, 2017
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // If size is 0 or 1
        if(nums.size() == 0) return -1;
        if(nums.size() == 1 && nums.at(0) == target) return 0;
        if(nums.size() == 1 && nums.at(0) != target) return -1;

        int idx = 0;
        // If the first element is the target
        if(nums.at(idx) == target) return idx;
        // If the target is larger than the first element
        else if(nums.at(idx) < target) {
            // Make sure the index is in the scope
            while((idx < signed(nums.size() - 1)) && (nums.at(idx) < nums.at(idx + 1))) {
                if(nums.at(idx + 1) == target) return idx + 1;
                idx++;
            }
            return -1;
        }
        // If the target is smaller than the first element
        else {
            // At the beginning, the idx points to the second from the last element
            if(signed(nums.size() - 2) > -1) {
                idx = nums.size() - 2;
            }
            // Make sure the index is in the scope
            while((idx > -1) && (nums.at(idx) < nums.at(idx + 1))) {
                if(nums.at(idx + 1) == target) return idx + 1;
                idx--;
            }
            // For example, [3,4,5,1,2], the (idx + 1) is pointing to the third element
            if(nums.at(idx + 1) == target) return idx + 1;
            else return -1;
        }
    }
};
