/**
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Write a function to determine if a given target is in the array.
 * The array may contain duplicates.
 *
 * It is very similar with 033 Search in Rotated Sorted Array
 *
 * Author: Adam Yu Wen
 * Date: July 06, 2017
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // If size is 0 or 1
        if(nums.size() == 0) return false;
        if(nums.size() == 1 && nums.at(0) == target) return true;
        if(nums.size() == 1 && nums.at(0) != target) return false;

        int idx = 0;
        // If the first element is the target
        if(nums.at(idx) == target) return true;
        // If the target is larger than the first element
        else if(nums.at(idx) < target) {
            // Make sure the index is in the scope
            while((idx < signed(nums.size() - 1)) && (nums.at(idx) <= nums.at(idx + 1))) {
                if(nums.at(idx + 1) == target) return true;
                idx++;
            }
            return false;
        }
        // If the target is smaller than the first element
        else {
            // At the beginning, the idx points to the second from the last element
            if(signed(nums.size() - 2) > -1) {
                idx = nums.size() - 2;
            }
            // Make sure the index is in the scope
            while((idx > -1) && (nums.at(idx) <= nums.at(idx + 1))) {
                if(nums.at(idx + 1) == target) return true;
                idx--;
            }
            // For example, [3,4,5,1,2], the (idx + 1) is pointing to the third element
            if(nums.at(idx + 1) == target) return true;
            else return false;
        }
    }
};
