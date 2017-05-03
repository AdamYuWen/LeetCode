/**
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 * Note:
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * https://leetcode.com/problems/max-consecutive-ones/#/description
 *
 * Author: Adam Yu Wen
 * Date: April 06, 2017
 */

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int res = 0;
		int max = 0;
		for (int index = 0; index < nums.size(); index++) {
			if (nums.at(index) == 1) {
				max++;
				if (index == nums.size() - 1) {
					res = (res > max ? res : max);
				}
			}
			else {
				res = (res > max ? res : max);
				max = 0;
			}
		}
		return res;
	}
};