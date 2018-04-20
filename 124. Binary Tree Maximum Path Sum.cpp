/**
 * Given a binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some starting
 * node to any node in the tree along the parent-child connections. The path must
 * contain at least one node and does not need to go through the root.
 * For example:
 * Given the below binary tree,
 *        1
 *       / \
 *      2   3
 * Return 6.
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * Author: Adam Yu Wen
 * Date: April 19, 2018
 */

// Method 1:
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
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;
	}

	int maxPathSum(TreeNode* root, int &res) {
		if (!root) return 0;
		int left = max(maxPathSum(root->left, res), 0);
		int right = max(maxPathSum(root->right, res), 0);
		res = max(res, left + right + root->val);
		return max(left, right) + root->val;
	}
};

// Method 2:
// The unordered_map won't make the program faster, because the sum of paths
// won't be calculated multiple times. On the contrary, it make the program
// slower.
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
	int maxPathSum(TreeNode* root) {
		unordered_map<TreeNode*, int> mp;
		int res = INT_MIN;
		maxPathSum(root, mp, res);
		return res;
	}

	int maxPathSum(TreeNode* root, unordered_map<TreeNode*, int> &mp, int &res) {
		if (!root) return 0;
		if (mp.count(root)) return mp[root];
		int left = max(maxPathSum(root->left, mp, res), 0);
		int right = max(maxPathSum(root->right, mp, res), 0);
		res = max(res, left + right + root->val);
		mp[root] = res;
		return max(left, right) + root->val;
	}
};