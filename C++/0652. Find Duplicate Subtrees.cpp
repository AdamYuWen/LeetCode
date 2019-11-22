/**
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate
 * subtrees, you only need to return the root node of any one of them.
 * Two trees are duplicate if they have the same structure with same node values.
 * Example 1:
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   2   4
 *        /
 *       4
 * The following are two duplicate subtrees:
 *       2
 *      /
 *     4
 * and
 *     4
 * Therefore, you need to return above trees' root in the form of a list.
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 * Reference: http://www.cnblogs.com/grandyang/p/7500082.html
 *
 * Author: Adam Yu Wen
 * Date: April 18, 2018
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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, int> mp;
		vector<TreeNode*> res;
		findDuplicateSubtrees(root, mp, res);
		return res;
	}

	string findDuplicateSubtrees(TreeNode* root,
		unordered_map<string, int> &mp,
		vector<TreeNode*> &res) {
		if (!root) return "#";
		string path = to_string(root->val) + "-" +
			findDuplicateSubtrees(root->left, mp, res) + "-" +
			findDuplicateSubtrees(root->right, mp, res);
		if (mp[path]++ == 1) res.push_back(root);
		return path;
	}
};

/*
 * Take the beginning example as a test case
 * All paths:
 * 4-#-#
 * 4-#-#
 * 2-4-#-#-#
 * 3-2-4-#-#-#-4-#-#
 * 4-#-#
 * 2-4-#-#-#
 * 1-2-4-#-#-#-3-2-4-#-#-#-4-#-#
 */