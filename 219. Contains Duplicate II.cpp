/**
 * Given an array of integers and an integer k, find out whether there are two distinct indices
 * i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j
 * is at most k.
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * Author: Adam Yu Wen
 * Date: February 28, 2018
 */

/* Time Limit Exceeded */
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int numSize = nums.size();
		for (unsigned int i = 0; i < numSize; i++) {
			for (unsigned int j = i + 1; j < i + k + 1 && j < numSize; j++) {
				if (nums[i] == nums[j]) return true;
			}
		}
		return false;
	}
};


class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		int numSize = nums.size();
		for (int idx = 0; idx < numSize; idx++) {
			if (mp.find(nums[idx]) != mp.end() && idx - mp.find(nums[idx])->second <= k) return true;
			else mp[nums[idx]] = idx;
		}
		return false;
	}
};