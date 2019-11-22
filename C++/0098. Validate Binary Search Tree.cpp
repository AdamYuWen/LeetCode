/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *	    2
 *	   / \
 *	  1   3
 *	Binary tree [2,1,3], return true.
 * Example 2:
 *	    1
 *	   / \
 *	  2   3
 *	Binary tree [1,2,3], return false.
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4298435.html
 *
 * Author: Adam Yu Wen
 * Date: March 16, 2018
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

/**
 * An example for this solution
 *     Test Tree             Compared Values
 *                        p->val       pre->val
 *          10              11           NULL
 *         /  \             20           11 
 *        20  30            21           20       if the smallest num in the subtree is larger than the root
 *       /  \               22           21
 *      11  25              23           22
 *         /  \             24           23
 *        24  26            25           24
 *        /                 26           25
 *       22                 10           26       if the largest num in the subtree is smaller than the root
 *      /  \                False
 *     21  23
 */
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* p = root;
		TreeNode* pre = NULL;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if (pre && p->val <= pre->val) return false;
			pre = p;
			p = p->right;
		}
		return true;
	}
};