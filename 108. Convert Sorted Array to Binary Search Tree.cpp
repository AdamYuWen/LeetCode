/**
 * Given an array where elements are sorted in ascending order, convert it
 * to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary
 * tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Example:
 * Given the sorted array: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4295245.html
 *
 * Author: Adam Yu Wen
 * Date: March 22, 2018
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
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		return sortedArrayToBST(nums, left, right);
	}

	// Without &, pass by value: the program is slow, which takes 75 ms.
	// With &, pass by reference: the program becomes much faster, 15 ms.
	TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;
		TreeNode* root = new TreeNode(nums[(left + right + 1) / 2]);
		root->left = sortedArrayToBST(nums, left, (left + right + 1) / 2 - 1);
		root->right = sortedArrayToBST(nums, (left + right + 1) / 2 + 1, right);
		return root;
	}
};