/**
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [2,3]
 *
 * Author: Adam Yu Wen
 * Date: July 14, 2017
 */

/**
 * Method 1: using sort
 * It takes 152 ms.
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for(int idx = 1; idx < nums.size(); idx++) {
            if(nums[idx - 1] == nums[idx]) res.push_back(nums[idx - 1]);
        }
        return res;
    }
};

/**
 * Method 2: without extra space and in O(n) runtime
 * It takes 135 ms.
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int numsSize = nums.size();
        for(int idx = 0; idx < numsSize; idx++) {
            int arrIdx = abs(nums[idx]) - 1;
            if(nums[arrIdx] > 0) {
                nums[arrIdx] *= -1;
            }
            else {
                res.push_back(arrIdx + 1);
            }
        }
        return res;
    }
};
