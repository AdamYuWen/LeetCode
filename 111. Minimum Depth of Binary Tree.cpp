/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * Author: Adam Yu Wen
 * Date: March 7, 2018
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
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else if (root->left != NULL && root->right == NULL)
			return 1 + minDepth(root->left);
		else if (root->left == NULL && root->right != NULL)
			return 1 + minDepth(root->right);
		else
			return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};