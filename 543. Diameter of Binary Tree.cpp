/**
 * Given a binary tree, you need to compute the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any two 
 * nodes in a tree. This path may or may not pass through the root.
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * Note: The length of path between two nodes is represented by the number of edges between them.
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * Author: Adam Yu Wen
 * Date: March 20, 2018
 */

// Methode 1:
// It takes 30 ms, which means it is slow.
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
	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			int diameter = longestPath(p->left) + longestPath(p->right);
			if (diameter > res) {
				res = diameter;
			}
			p = p->right;
		}
		return res;
	}

	int longestPath(TreeNode* root) {
		int length = 0;
		if (!root) return length;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* p = q.front();
				q.pop();
				if (idx == 0) {
					length++;
				}
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		return length;
	}
};