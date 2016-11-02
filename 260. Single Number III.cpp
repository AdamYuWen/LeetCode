/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 * For example:
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * https://leetcode.com/problems/single-number-iii/
 *
 * Author: Adam Yu Wen
 * Date: November 1, 2016
 */

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		unordered_map<int, int> myMap;
		for (int i = 0; i < nums.size(); i++) {
			myMap[nums[i]]++;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (myMap[nums[i]] == 1) res.push_back(nums[i]);
		}
		return res;
	}
};