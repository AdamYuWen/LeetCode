/**
 * Given an array consisting of n integers, find the contiguous
 * subarray of given length k that has the maximum average value.
 * And you need to output the maximum average value.
 * Example 1:
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * Note:
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 * Author: Adam Yu Wen
 * Date: July 18, 2017
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0.0;
        int curSum = 0, updateSum = 0;
        for(int idx = 0; idx < k; idx++) {
            curSum += nums[idx];
        }
        updateSum = curSum;
        for(int idx = k; idx < nums.size(); idx++) {
            curSum = curSum + nums[idx] - nums[idx - k];
            updateSum = max(curSum, updateSum);
        }
        res = updateSum / double(k);
        return res;
    }
};
