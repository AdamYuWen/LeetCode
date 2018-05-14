/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * Author: Adam Yu Wen
 * Date: April 20, 2018
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		vector<int> level;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(level);
			level.clear();
		}
		return res;
	}
};