/**
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently 
 * occurred element) in the given BST.
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * For example:
 * Given BST [1,null,2,2],
 *    1
 *     \
 *      2
 *     /
 *    2
 * return [2].
 * Note: If a tree has more than one mode, you can return them in any order.
 * Follow up: Could you do that without using any extra space? (Assume that the implicit stack
 * space incurred due to recursion does not count).
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * Author: Adam Yu Wen
 * March 16, 2018
 */

// Method 1:
// It is slow. It takes 59 ms.
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
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		vector<int> allValues = inorderTraversal(root);
		int maxCnt = 1, cnt = 1;
		int allValuesSize = allValues.size();
		// If the size is one, the result is the value.
		if (allValuesSize == 1) res.push_back(allValues[0]);
		else {
			for (int idx = 0; idx < allValuesSize - 1; idx++) {
				int curr = allValues[idx];
				int next = allValues[idx + 1];
				if (idx == 0) res.push_back(curr);
				if (curr == next) {
					cnt++;
					if (cnt == maxCnt) {
						res.push_back(next);
					}
					else if (cnt > maxCnt) {
						res.erase(res.begin(), res.end());
						res.push_back(next);
						maxCnt = cnt;
					}
				}
				else {
					cnt = 1;
					// example: [1, 2]
					if (cnt == maxCnt) {
						res.push_back(next);
					}
				}
			}
		}
		return res;
	}

	// The res will be sorted array.
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return res;
		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);
		return res;
	}
};


// Method 2:
// It takes 27 ms.
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
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		TreeNode* p = root;
		stack<TreeNode*> s;
		unordered_map<int, int> mp;
		int maxCnt = 0;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			mp[p->val]++;
			maxCnt = maxCnt > mp[p->val] ? maxCnt : mp[p->val];
			p = p->right;
		}

		for (auto x : mp) {
			if (x.second == maxCnt) res.push_back(x.first);
		}
		return res;
	}
};