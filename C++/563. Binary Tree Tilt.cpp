/**
 * Given a binary tree, return the tilt of the whole tree.
 * The tilt of a tree node is defined as the absolute difference between the sum of
 * all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 * Example:
 * Input:
 *    1
 *  /   \
 * 2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 * Note: The sum of node values in any subtree won't exceed the range of 32-bit integer.
 * All the tilt values won't exceed the range of 32-bit integer.
 * https://leetcode.com/problems/binary-tree-tilt/description/
 *
 * Author: Adam Yu Wen
 * Date: March 19, 2018
 */

// Method 1:
// Using Stack, inorder traversal
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
	int findTilt(TreeNode* root) {
		int res = 0;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			res += abs(subtreeSum(p->left) - subtreeSum(p->right));
			p = p->right;
		}
		return res;
	}

	int subtreeSum(TreeNode* root) {
		if (!root) return 0;
		int res = 0;
		res += root->val;
		res += subtreeSum(root->left);
		res += subtreeSum(root->right);
		return res;
	}
};


// Method 2:
// Using Queue, level by level
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
	int findTilt(TreeNode* root) {
		int res = 0;
		// Compare to the previous method
		// The IF function is need, otherwise the program will go
		// through the while function. There is no p->left or p->right
		// (NULL->NULL)
		// On the other hand, the root has to be pushed outside of
		// the while function
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			for (int i = 0; i < qSize; i++) {
				TreeNode* p = q.front();
				q.pop();
				res += abs(subtreeSum(p->left) - subtreeSum(p->right));
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		return res;
	}

	int subtreeSum(TreeNode* root) {
		if (!root) return 0;
		int res = 0;
		res += root->val;
		res += subtreeSum(root->left);
		res += subtreeSum(root->right);
		return res;
	}
};