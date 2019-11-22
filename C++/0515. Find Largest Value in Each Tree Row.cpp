/**
 * You need to find the largest value in each row of a binary tree.
 * Example:
 * Input:
 *           1
 *          / \
 *         3   2
 *        / \   \
 *       5   3   9
 * Output: [1, 3, 9]
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			int temp = q.front()->val;
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* t = q.front();
				q.pop();
				temp = temp < t->val ? t->val : temp;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(temp);
		}
		return res;
	}
};