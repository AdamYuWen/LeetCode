/**
 * You are given a binary tree in which each node contains an integer value.
 * Find the number of paths that sum to a given value.
 * The path does not need to start or end at the root or a leaf, but it must go downwards
 * (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 * Example:
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *       10
 *      /  \
 *     5   -3
 *    / \    \
 *   3   2   11
 *  / \   \
 * 3  -2   1
 * Return 3. The paths that sum to 8 are:
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * https://leetcode.com/problems/path-sum-iii/description/
 * Reference: http://www.cnblogs.com/grandyang/p/6007336.html
 *
 * Author: Adam Yu Wen
 * Date: March 28, 2018
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
	int pathSum(TreeNode* root, int sum) {
		int res = 0;
		vector<TreeNode*> out;
		helper(root, sum, 0, out, res);
		return res;
	}

	void helper(TreeNode* root, int sum, int currSum, vector<TreeNode*>& out, int& res) {
		if (!root) return;
		currSum += root->val;
		// all pointers in out are from one path
		out.push_back(root);
		if (currSum == sum) res++;
		int t = currSum;
		// have to have at least one value left
		for (int i = 0; i < out.size() - 1; i++) {
			// subtract each parent values one by one
			t -= out[i]->val;
			if (t == sum) res++;
		}
		helper(root->left, sum, currSum, out, res);
		helper(root->right, sum, currSum, out, res);
		// pop out the node that is not in the path
		out.pop_back();
	}
};