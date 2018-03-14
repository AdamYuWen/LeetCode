/**
 * Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * https://leetcode.com/problems/binary-tree-paths/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4738031.html
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root) allPaths(root, "", res);
		return res;
	}

	void allPaths(TreeNode* root, string out, vector<string> &res) {
		out += to_string(root->val);
		if (!root->left && !root->right) res.push_back(out);
		else {
			if (root->left) allPaths(root->left, out + "->", res);
			if (root->right) allPaths(root->right, out + "->", res);
		}
	}
};