/**
 * Given a binary tree, flatten it to a linked list in-place.
 * For example,
 * Given
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * Author: Adam Yu Wen
 * Date: April 6, 2018
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
	void flatten(TreeNode* root) {
		vector<TreeNode*> vectorRes;
		preorderTraversal(root, vectorRes);
		int resSize = vectorRes.size();
		TreeNode* t = root;
		for (int idx = 1; idx < resSize; idx++) {
			t->left = NULL;
			t->right = vectorRes[idx];
			t = t->right;
		}
	}

	void preorderTraversal(TreeNode* root, vector<TreeNode*> &res) {
		if (!root) return;
		res.push_back(root);
		preorderTraversal(root->left, res);
		preorderTraversal(root->right, res);
	}
};