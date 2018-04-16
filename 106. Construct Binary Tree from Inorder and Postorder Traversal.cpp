/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * For example, given
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * Return the following binary tree:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4296193.html
 *
 * Author: Adam Yu Wen
 * Date: April 15, 1028
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
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1,
			postorder, 0, postorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& inorder, int inLeft, int inRight,
		vector<int>& postorder, int postLeft, int postRight) {
		if (inLeft > inRight || postLeft > postRight) return NULL;
		TreeNode* root = new TreeNode(postorder[postRight]);
		int inRoot;
		for (inRoot = inLeft; inRoot < inRight; inRoot++) {
			if (inorder[inRoot] == root->val)
				break;
		}
		// postLeft + inRoot - inLeft - 1 ==>
		// inRoot - inLeft == the number of values go to the left side
		// - 1 == change the number of values to idex, which starts from 0
		root->left = buildTree(inorder, inLeft, inRoot - 1,
			postorder, postLeft, postLeft + inRoot - inLeft - 1);
		// postLeft + inRoot - inLeft ==>
		// postLeft + inRoot - inLeft - 1 + 1:
		// inRoot - inLeft == the number of values go to the left side
		// - 1 == change the number of values to idex, which starts from 0
		// + 1 == if there are 2 values go to the left side, the index starts from the third
		// postRight - 1 ==> exclude the last one, which is the root
		root->right = buildTree(inorder, inRoot + 1, inRight,
			postorder, postLeft + inRoot - inLeft, postRight - 1);
		return root;
	}
};
