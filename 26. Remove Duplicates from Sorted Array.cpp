/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1, 1, 2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length.
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Author: Adam Yu Wen
 * Date: October 23, 2016
 */

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int res = 0;
		if (nums.size() == 0) return res;
		for (int i = 0; i < nums.size(); i++) {
			if (nums.at(i) != nums.at(res)) {
				nums.at(res + 1) = nums.at(i);
				res++;
			}
		}
		// res doesn't count for the first element
		return res + 1;
	}
};
