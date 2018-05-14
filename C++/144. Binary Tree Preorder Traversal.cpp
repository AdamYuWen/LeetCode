/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively?
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * Author: Adam Yu Wen
 * Date: March 14, 2018
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
	vector<int> res;
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root) return res;
		res.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		return res;
	}
};