/**
* Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
* Example 1:
* Input:
*     3
*    / \
*   9  20
*     /  \
*    15   7
* Output: [3, 14.5, 11]
* Explanation:
* The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
* Note:
* The range of node's value is in the range of 32-bit signed integer.
* https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
*
* Author: Adam Yu Wen
* Date: March 12, 2018
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

// Method 1:
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			// the type should be long
			// int doesn't pass all tests
			long sum = 0;
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeNode* t = q.front();
				q.pop();
				sum += t->val;
				// checking if left or right is valid
				// if it is NULL, a zero will be pushed into q
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(sum / double(qSize));
		}
		return res;
	}
};


// Method 2:
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		vector<long> levelSum;
		vector<int> count;
		levelAndCount(root, 0, levelSum, count);
		int levelSize = levelSum.size();
		for (int idx = 0; idx < levelSize; idx++) {
			res.push_back(levelSum[idx] / double(count[idx]));
		}
		return res;
	}

	void levelAndCount(TreeNode* root, int level, vector<long> &levelSum, vector<int> &count) {
		if (root == NULL) return;
		if (level >= levelSum.size()) {
			levelSum.push_back(root->val);
			count.push_back(1);
		}
		else {
			levelSum[level] += root->val;
			count[level]++;
		}
		levelAndCount(root->left, level + 1, levelSum, count);
		levelAndCount(root->right, level + 1, levelSum, count);
	}
};