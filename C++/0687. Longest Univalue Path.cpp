/**
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the root.
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * Example 1:
 *	Input:
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 *	Output: 2
 * Example 2:
 *	Input:
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 *	Output: 2
 * Note: The given binary tree has not more than 10000 nodes. The height of
 * the tree is not more than 1000.
 * https://leetcode.com/problems/longest-univalue-path/description/
 * Reference: http://www.cnblogs.com/grandyang/p/7636259.html
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
	int longestUnivaluePath(TreeNode* root) {
		int res = 0;
		univaluePath(root, res);
		return res;
	}

	int univaluePath(TreeNode* root, int& res) {
		if (!root) return 0;
		int left = univaluePath(root->left, res);
		int right = univaluePath(root->right, res);
		if (root->left)
			left = root->left->val == root->val ? left + 1 : 0;
		if (root->right)
			right = root->right->val == root->val ? right + 1 : 0;
		// if the root is the root point in the path, add left and right
		res = max(res, left + right);
		// if the root is NOT the root in the path, choose the larger number
		return max(left, right);
	}
};