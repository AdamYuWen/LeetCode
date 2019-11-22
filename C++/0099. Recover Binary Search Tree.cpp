/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * Author: Adam Yu Wen
 * Date: April 12, 2018
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
	void recoverTree(TreeNode* root) {
		inorderTraversal(root);
		vector<int> sortedValues = values;
		sort(sortedValues.begin(), sortedValues.end());
		int firstIdx, secondIdx, cnt = 0;
		for (int idx = 0; idx < sortedValues.size(); idx++) {
			if (values[idx] != sortedValues[idx] && cnt == 0) {
				firstIdx = idx;
				cnt++;
			}
			else if (values[idx] != sortedValues[idx]) {
				secondIdx = idx;
			}
			else if (cnt > 1) {
				break;
			}
		}
		int tmp = mp[firstIdx]->val;
		mp[firstIdx]->val = mp[secondIdx]->val;
		mp[secondIdx]->val = tmp;
	}

	void inorderTraversal(TreeNode* root) {
		if (!root) return;
		inorderTraversal(root->left);
		mp[idx++] = root;
		values.push_back(root->val);
		inorderTraversal(root->right);
	}

private:
	unordered_map<int, TreeNode*> mp;
	vector<int> values;
	int idx = 0;
};