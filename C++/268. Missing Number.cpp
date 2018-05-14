/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * Note: Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 * https://leetcode.com/problems/missing-number/
 *
 * Author: Adam Yu Wen
 * Date: October 28, 2016
 */

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int maxNum = 0, sum = 0;
		bool includeZero = false;
		for (int i = 0; i < nums.size(); i++) {
			maxNum = maxNum > nums[i] ? maxNum : nums[i];
			sum += nums[i];
			if (nums[i] == 0) includeZero = true;
		}
		// if there is a zero and size matchs with the number of numbers, return the last missing number
		if (includeZero == true && (maxNum + 1) == nums.size()) return maxNum + 1;
		// if there is a zero and size does not match, there is a number from 0 to maxNum is missing
		else if (includeZero == true) return ((1 + maxNum) * maxNum / 2 - sum);
		// if there is no zero, the missing number is zero
		else return 0;
	}
};