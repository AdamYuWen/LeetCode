/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 * https://leetcode.com/problems/path-sum-ii/description/
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res, allPaths;
		if (!root) return res;

		// get all paths in the BST
		vector<int> singlePath;
		getAllPaths(root, singlePath, allPaths);

		// only push_back valid paths
		int allPathsSize = allPaths.size();
		for (int i = 0; i < allPathsSize; i++) {
			int pathSum = 0;
			int singlePathSize = allPaths[i].size();
			for (int j = 0; j < singlePathSize; j++) {
				pathSum += allPaths[i][j];
			}
			if (pathSum == sum) res.push_back(allPaths[i]);
		}
		return res;
	}

	void getAllPaths(TreeNode* root, vector<int> singlePath, vector<vector<int>> &allPaths) {
		singlePath.push_back(root->val);
		if (!root->left && !root->right) allPaths.push_back(singlePath);
		else {
			if (root->left) getAllPaths(root->left, singlePath, allPaths);
			if (root->right) getAllPaths(root->right, singlePath, allPaths);
		}
	}
};
