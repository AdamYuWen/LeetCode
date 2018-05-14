/**
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Author: Adam Yu Wen
 * Date: October 28, 2016
 */

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> listOne, listTwo, res;
		int vecSize = nums.size();
		for (int i = 0; i < vecSize; i++) {
			if (i == 0) {
				listOne.push_back(1);
			}
			else if (i == 1) {
				listOne.push_back(nums[i - 1]);
			}
			else {
				listOne.push_back(listOne[i - 1] * nums[i - 1]);
			}
		}
		for (int i = 0; i < vecSize; i++) {
			if (i == 0) {
				listTwo.push_back(1);
			}
			else if (i == 1) {
				listTwo.push_back(nums[vecSize - 1]);
			}
			else {
				listTwo.push_back(listTwo[i - 1] * nums[vecSize - i]);
			}
		}
		for (int i = 0; i < vecSize; i++) {
			res.push_back(listOne[i] * listTwo[vecSize - i - 1]);
		}
		return res;
	}
};