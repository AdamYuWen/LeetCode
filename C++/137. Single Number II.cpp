/**
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * https://leetcode.com/problems/single-number-ii/
 *
 * Author: Adam Yu Wen
 * Date: November 1, 2016
 */

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int index;
		unordered_map<int, int> myMap;
		for (int i = 0; i < nums.size(); i++) {
			myMap[nums[i]]++;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (myMap[nums[i]] == 1) {
				index = i;
				break;
			}
		}
		return nums[index];
	}
};