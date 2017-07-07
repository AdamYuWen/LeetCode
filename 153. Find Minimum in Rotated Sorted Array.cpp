/**
 * Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 *
 * Author: Adam Yu Wen
 * Date: July 05, 2017
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res;
        int idx = 0;
        for (; idx < nums.size() - 1; idx++) {
            // If the next number is smaller, it is the smallest
            if (nums.at(idx) > nums.at(idx + 1)) {
                res = nums.at(idx + 1);
                break;
            }
        }
        if (idx == nums.size() - 1) return nums.at(0);
        else return res;
    }
};
