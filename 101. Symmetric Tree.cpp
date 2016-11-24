/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * https://leetcode.com/problems/symmetric-tree/
 *
 * Author: Adam Yu Wen
 * Date: November 21, 2016
 * Reference: http://www.cnblogs.com/grandyang/p/4051715.html
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
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		// there are five situations
		// 1. left==NULL and right==NULL, return true
		// 2. left==NULL and right!=NULL, return false
		// 3. left!=NULL and right==NULL, return false
		// 4. left!=NULL and right!=NULL, values are the same, should keep going and not return anything
		//    the last point for this situation is going back to 1
		// 5. left!=NULL and right!=NULL, values are not the same, return false
		if (!left && !right) return true;
		if ((!left && right) || (left && !right) || (left->val != right->val)) return false;
		return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
	}
};