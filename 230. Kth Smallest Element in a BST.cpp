/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need
 * to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * Author: Adam Yu Wen
 * Date: March 14, 2018
 */

// Method 1:
// It is slow, which takes 59 ms,
// because it returns all values.
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
	int kthSmallest(TreeNode* root, int k) {
		vector<int> list;
		list = inorderTraversal(root);
		return list[k - 1];
	}

	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return res;
		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);
		return res;
	}
};