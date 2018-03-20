/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its depth = 3.
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * Author: Adam Yu Wen
 * Date: March 20, 2018
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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && root->right) return maxDepth(root->right) + 1;
		if (root->left && !root->right) return maxDepth(root->left) + 1;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};