/**
 * You need to construct a string consists of parenthesis and integers from a
 * binary tree with the preorder traversing way.
 * The null node needs to be represented by empty parenthesis pair "()". And
 * you need to omit all the empty parenthesis pairs that don't affect the
 * one-to-one mapping relationship between the string and the original binary tree.
 * Example 1:
 *	Input: Binary tree: [1,2,3,4]
 *	       1
 *	     /   \
 *	    2     3
 *	   /
 *	  4
 *	Output: "1(2(4))(3)"
 *	Explanation: Originallay it needs to be "1(2(4)())(3()())", 
 *	but you need to omit all the unnecessary empty parenthesis pairs.
 *	And it will be "1(2(4))(3)".
 * Example 2:
 *	Input: Binary tree: [1,2,3,null,4]
 *	       1
 *	     /   \
 *	    2     3
 *	     \
 *	      4
 *	Output: "1(2()(4))(3)"
 *	Explanation: Almost the same as the first example, 
 *	except we can't omit the first parenthesis pair to break the one-to-one mapping
 *	relationship between the input and the output.
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 * Reference: http://www.cnblogs.com/grandyang/p/7000040.html
 * 
 * Author: Adam Yu Wen
 * Date: March 19, 2018
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
	string tree2str(TreeNode* t) {
		string res = "";
		if (!t) return res;
		preorderTraversal(t, res);
		return string(res.begin() + 1, res.end() - 1);
	}

	void preorderTraversal(TreeNode* t, string &res) {
		if (!t) return;
		// The closing parenthesis should be at the end of the function.
		res += ("(" + to_string(t->val));
		// Because of the following code, there is no extra () added.
		if (!t->left && t->right) res += "()";
		preorderTraversal(t->left, res);
		preorderTraversal(t->right, res);
		res += ")";
	}
};