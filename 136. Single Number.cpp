/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * https://leetcode.com/problems/single-number/
 *
 * Author: Adam Yu Wen
 * Date: October 6, 2016
 */

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> myMap;
		for (unsigned int i = 0; i < nums.size(); i++) {
			myMap[nums.at(i)]++;
			if (myMap[nums.at(i)] == 2) {
				myMap.erase(nums.at(i));
			}
		}
		return myMap.begin()->first;
	}
};