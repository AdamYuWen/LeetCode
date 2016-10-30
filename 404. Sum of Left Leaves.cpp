/**
 * Find the sum of all left leaves in a given binary tree.
 * Example:
 *		3
 *	   / \
 *	  9  20
 *		/  \
 *	   15   7
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 * https://leetcode.com/problems/sum-of-left-leaves/
 *
 * Author: Adam Yu Wen
 * Date: October 28, 2016
 * Reference: http://www.cnblogs.com/grandyang/p/5923559.html
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
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;
		else {
			if (root->left && !root->left->left && !root->left->right) {
				return root->left->val + sumOfLeftLeaves(root->right);
			}
			else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		}
	}
};