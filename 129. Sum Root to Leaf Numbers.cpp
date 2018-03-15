/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
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
	int sumNumbers(TreeNode* root) {
		int res = 0;
		if (!root) return res;

		vector<int> allPaths;
		getAllPaths(root, 0, allPaths);
		int numPaths = allPaths.size();
		for (int idx = 0; idx < numPaths; idx++) {
			res += allPaths[idx];
		}
		return res;
	}

	void getAllPaths(TreeNode* root, int singlePath, vector<int> &allPaths) {
		singlePath = singlePath * 10 + root->val;
		if (!root->left && !root->right) allPaths.push_back(singlePath);
		if (root->left) getAllPaths(root->left, singlePath, allPaths);
		if (root->right) getAllPaths(root->right, singlePath, allPaths);
	}
};