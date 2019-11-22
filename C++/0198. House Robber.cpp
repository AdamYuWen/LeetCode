/**
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have security
 * system connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each
 * house, determine the maximum amount of money you can rob tonight without alerting
 * the police.
 * https://leetcode.com/problems/house-robber/
 *
 * Author: Adam Yu Wen
 * Date: October 31, 2016
 */

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> res;
		if (nums.empty()) return 0;
		else if (nums.size() == 1) return nums[0];
		else if (nums.size() == 2) return max(nums[0], nums[1]);
		else {
			res.push_back(nums[0]);
			res.push_back(max(nums[0], nums[1]));
			// dynamic programming
			// choose from (current number + two element before in dp)
			// and (one element before in dp)
			for (int i = 2; i < nums.size(); i++) {
				res.push_back(max(nums[i] + res[i - 2], res[i - 1]));
			}
		}
		return res.back();
	}
};