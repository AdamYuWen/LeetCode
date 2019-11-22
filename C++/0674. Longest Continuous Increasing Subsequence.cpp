/**
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 * Example 1:
 *	Input: [1,3,5,4,7]
 *	Output: 3
 *	Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 *	Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 * Example 2:
 *	Input: [2,2,2,2,2]
 *	Output: 1
 *	Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 * Note: Length of the array will not exceed 10,000.
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * Author: Adam Yu Wen
 * Date: April 18, 2018
 */

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int res = 1, curr = 1;
		int numsSize = nums.size();
		if (numsSize == 0) return 0;
		for (int idx = 0; idx < numsSize - 1; idx++) {
			if (nums[idx] < nums[idx + 1]) {
				curr++;
				res = res < curr ? curr : res;
			}
			else {
				curr = 1;
			}
		}
		return res;
	}
};