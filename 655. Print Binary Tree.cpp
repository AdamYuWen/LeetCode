/**
 * Print a binary tree in an m*n 2D string array following these rules:
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle of the
 * first row it can be put. The column and the row where the root node belongs will separate
 * the rest space into two parts (left-bottom part and right-bottom part). You should print 
 * the left subtree in the left-bottom part and print the right subtree in the right-bottom
 * part. The left-bottom part and the right-bottom part should have the same size. Even if
 * one subtree is none while the other is not, you don't need to print anything for the none
 * subtree but still need to leave the space as large as that for the other subtree. However,
 * if two subtrees are none, then you don't need to leave space for both of them.
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 * Example 1:
 *	Input:
 *	     1
 *	    /
 *	   2
 *	Output:
 *	[["", "1", ""],
 *	 ["2", "", ""]]
 * Example 2:
 *	Input:
 *	     1
 *	    / \
 *	   2   3
 *	    \
 *	     4
 *	Output:
 *	[["", "", "", "1", "", "", ""],
 *	 ["", "2", "", "", "", "3", ""],
 *	 ["", "", "4", "", "", "", ""]]
 * Example 3:
 *	Input:
 *	      1
 *	     / \
 *	    2   5
 *	   /
 *	  3
 *	 /
 *	4
 *	Output:
 *	[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 *	 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 *	 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 *	 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 * Note: The height of binary tree is in the range of [1, 10].
 * https://leetcode.com/problems/print-binary-tree/description/
 * Reference: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/print-binary-tree.cpp
 *
 * Author: Adam Yu Wen
 * Date: April 3, 2018
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
	vector<vector<string>> printTree(TreeNode* root) {
		int row = getRow(root);
		int col = getCol(root);
		vector<string> resTmp(col, "");
		vector<vector<string>> res(row, resTmp);
		preorderTraversal(root, 0, 0, col, res);
		return res;
	}

	int getRow(TreeNode* root) {
		if (!root) return 0;
		return max(getRow(root->left), getRow(root->right)) + 1;
	}

	int getCol(TreeNode* root) {
		if (!root) return 0;
		return 2 * max(getCol(root->left), getCol(root->right)) + 1;
	}

	void preorderTraversal(TreeNode* root, int row, int left, int right, vector<vector<string>> &res) {
		int mid = left + (right - left) / 2;
		res[row][mid] = to_string(root->val);
		if (root->left) preorderTraversal(root->left, row + 1, left, mid - 1, res);
		if (root->right) preorderTraversal(root->right, row + 1, mid + 1, right, res);
	}
};