/**
 * Given a Binary Search Tree and a target number, return true if there
 * exist two elements in the BST such that their sum is equal to the given target.
 * Example 1:
 *	Input:
 *	    5
 *	   / \
 *	  3   6
 *	 / \   \
 *	2   4   7
 *	Target = 9
 *	Output: True
 * Example 2:
 *	Input:
 *	    5
 *	   / \
 *	  3   6
 *	 / \   \
 *	2   4   7
 *	Target = 28
 *	Output: False
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 * 
 * Author: Adam Yu Wen
 * Date: March 9, 2018
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
	// unordered_map should be outside of the findTarget function
	// because there should be only one map
	unordered_map<int, int> mp;
	int idx = 0;
	bool findTarget(TreeNode* root, int k) {
		if (root == NULL) return false;
		if (mp.find(k - root->val) != mp.end()) {
			return true;
		}
		else {
			mp[root->val] = idx++;
			return findTarget(root->left, k) || findTarget(root->right, k);
		}
	}
};