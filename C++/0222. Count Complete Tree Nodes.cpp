/**
 * Given a complete binary tree, count the number of nodes.
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely
 * filled, and all nodes in the last level are as far left as possible. It can
 * have between 1 and 2h nodes inclusive at the last level h.
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4567827.html
 *
 * Author: Adam Yu Wen
 * Date: April 5, 2018
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
	int countNodes(TreeNode* root) {
		TreeNode* leftPtr = root;
		TreeNode* rightPtr = root;
		int leftLevel = 0, rightLevel = 0;
		while (leftPtr) {
			leftLevel++;
			leftPtr = leftPtr->left;
		}
		while (rightPtr) {
			rightLevel++;
			rightPtr = rightPtr->right;
		}
		if (leftLevel == rightLevel) return pow(2, leftLevel) - 1;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};