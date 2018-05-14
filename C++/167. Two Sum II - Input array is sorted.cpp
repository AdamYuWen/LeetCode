/**
 * Given an array of integers that is already sorted in ascending order, 
 * find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that
 * they add up to the target, where index1 must be less than index2. Please
 * note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Author: Adam Yu Wen
 * Date: November 2, 2016
 */

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> myMap;
		vector<int> res;
		for (int i = 0; i < numbers.size(); i++) {
			myMap[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++) {
			int diff = target - numbers[i];
			if (myMap.count(diff) && myMap[diff] != i) {
				res.push_back(i + 1);
				res.push_back(myMap[diff] + 1);
				break;
			}
		}
		return res;
	}
};