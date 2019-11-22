/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous solution still work?
 * Note:
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * Author: Adam Yu Wen
 * Date: March 14, 2018
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;

		queue<TreeLinkNode*> q;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			for (int idx = 0; idx < qSize; idx++) {
				TreeLinkNode* t = q.front();
				q.pop();
				if (idx == qSize - 1) {
					t->next = NULL;
				}
				else {
					t->next = q.front();
				}
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
	}
};