/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * Author: Adam Yu Wen
 * Date: March 15, 2018
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		vector<int> singleLevel;
		queue<TreeNode*> q;
		q.push(root);
		bool leftRight = true;
		while (!q.empty()) {
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* t = q.front();
				q.pop();
				if (leftRight)
					singleLevel.push_back(t->val);
				else
					singleLevel.insert(singleLevel.begin(), t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(singleLevel);
			singleLevel.erase(singleLevel.begin(), singleLevel.end());
			leftRight = leftRight ? false : true;
		}
		return res;
	}
};