/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4231455.html
 *
 * Author: Adam Yu Wen
 * Date: April 16, 2018
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* res = s.top();
		TreeNode* t = s.top();
		s.pop();
		if (t->right) {
			t = t->right;
			while (t) {
				s.push(t);
				t = t->left;
			}
		}
		return res->val;
	}

private:
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */