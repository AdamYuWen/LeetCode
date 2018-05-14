/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * For example, given
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * Author: Adam Yu Wen
 * Date: April 16, 2018
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
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight,
	                    vector<int>& inorder, int inLeft, int inRight) {
		if (preLeft > preRight || inLeft > inRight) return NULL;
		TreeNode* root = new TreeNode(preorder[preLeft]);
		int inRoot;
		for (inRoot = inLeft; inRoot < inRight; inRoot++) {
			if (inorder[inRoot] == preorder[preLeft])
				break;
		}
		// preLeft + 1 ==> exclude the root
		// preLeft + inRoot - inLeft ==>
		// preLeft + inRoot - inLeft - 1 + 1:
		// inRoot - inLeft == the number of values to the left side
		// - 1 == change the number of values to index, which starts from 0
		// + 1 == exclude the root
		root->left = buildTree(preorder, preLeft + 1, preLeft + inRoot - inLeft,
		                       inorder, inLeft, inRoot - 1);
		// preLeft + inRoot - inLeft + 1 ==>
		// preLeft + inRoot - inLeft - 1 + 1 + 1:
		// inRoot - inLeft == the number of values to the left side
		// - 1 == change the number of values to index, which starts from 0
		// + 1 == if there are 2 values go to the left side, the index starts from the third
		// + 1 == exclude the root
		root->right = buildTree(preorder, preLeft + inRoot - inLeft + 1, preRight,
		                        inorder, inRoot + 1, inRight);
		return root;
	}
};