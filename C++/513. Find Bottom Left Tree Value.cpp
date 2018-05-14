/**
 * Given a binary tree, find the leftmost value in the last row of the tree.
 * Example 1:
 *	Input:
 *	    2
 *	   / \
 *	  1   3
 *	Output: 1
 * Example 2:
 *	Input:
 *	        1
 *	       / \
 *	      2   3
 *	     /   / \
 *	    4   5   6
 *	       /
 *	      7
 *	Output: 7
 * Note: You may assume the tree (i.e., the given root node) is not NULL.
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * Author: Adam Yu Wen
 * Date: March 13, 2018
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
	int findBottomLeftValue(TreeNode* root) {
		int res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* t = q.front();
				q.pop();
				if (idx == 0) res = t->val;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return res;
	}
};