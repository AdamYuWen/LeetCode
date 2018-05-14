/**
 * Given an integer array, you need to find one continuous subarray
 * that if you only sort this subarray in ascending order, then the
 * whole array will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order
 * to make the whole array sorted in ascending order.
 * Note:
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=.
 *
 * Author: Adam Yu Wen
 * Date: July 12, 2017
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int first = 0, last = 0;
        vector<int> brenchmark = nums;
        sort(brenchmark.begin(), brenchmark.end());
        // find the first unmatched element
        for(int idx = 0; idx < nums.size(); idx++) {
            if(nums[idx] != brenchmark[idx]) {
                first = idx;
                break;
            }
        }
        // find the last unmatched element
        for(int idx = nums.size() - 1; idx > -1; idx--) {
            if(nums[idx] != brenchmark[idx]) {
                last = idx;
                break;
            }
        }
        if(first == 0 && last == 0) return 0;
        else return last - first + 1;
    }
};
