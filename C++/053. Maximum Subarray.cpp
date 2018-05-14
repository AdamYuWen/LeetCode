/**
 * Find the contiguous subarray within an array (containing at
 * least one number) which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * Author: Adam Yu Wen
 * Date: July 18, 2017
 * Reference: http://www.cnblogs.com/grandyang/p/4377150.html
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            // if the answer array need to be restarted
            // curSum > 0 && num > 0 ==> curSum
            // curSum > 0 && num < 0 ==> curSum
            // curSum < 0 && num > 0 ==> num (restart)
            // curSum < 0 && num < 0 ==> num (restart)
            curSum = max(curSum + nums[idx], nums[idx]);
            // save the largest curSum into res
            res = max(res, curSum);
        }
        return res;
    }
};
