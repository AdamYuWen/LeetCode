/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may
 * assume the returned list does not count as extra space.
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 *
 * Author: Adam Yu Wen
 * Date: July 12, 2017
 */

 /**
  * It is my solution.
  * There are some better solution on-line.
  * Reference: http://www.cnblogs.com/grandyang/p/6222149.html
  */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int numsSize = nums.size();

        vector<int>::iterator it;
        sort(nums.begin(), nums.end());
        // the unique function returns the element that follows
        // the last element not removed
        it = unique(nums.begin(), nums.end());
        // the size of nums will shrink
        nums.resize(distance(nums.begin(), it));

        int idx = 0;
        // ele contains the full list
        for(int ele = 1; ele < numsSize + 1; ele++) {
            if(ele == nums[idx]) idx++;
            else {
                res.push_back(ele);
            }
        }
        return res;
    }
};
