/**
 * Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of this tree.
 * Example 1:
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *       6
 *     /   \
 *    3     5
 *     \    /
 *      2  0
 *        \
 *         1
 * Note:
 * The size of the given array will be in the range [1,1000].
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * Author: Adam Yu Wen
 * Date: April 6, 2018
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode * constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		int maxNum = nums[0], maxIdx = 0;
		int numsSize = nums.size();
		for (int idx = 1; idx < numsSize; idx++) {
			if (maxNum < nums[idx]) {
				maxNum = nums[idx];
				maxIdx = idx;
			}
		}
		TreeNode* res = new TreeNode(maxNum);
		vector<int> leftNums(nums.begin(), nums.begin() + maxIdx);
		res->left = constructMaximumBinaryTree(leftNums);
		vector<int> rightNums(nums.begin() + maxIdx + 1, nums.end());
		res->right = constructMaximumBinaryTree(rightNums);
		return res;
	}
};