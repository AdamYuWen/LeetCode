/**
 * Given an array of 2n integers, your task is to group these integers
 * into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which
 * makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * Example 1:
 * Input: [1,4,3,2]
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 * Note:
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 *
 * Author: Adam Yu Wen
 * Date: July 11, 2017
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        // Only if the adjacent ones become to a group
        // the larger one is not wasted
        for(int idx = 0; idx < nums.size(); idx += 2) {
            res += nums[idx];
        }
        return res;
    }
};
