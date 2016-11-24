/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Author: Adam Yu Wen
 * Date: November 07, 2016
 * Reference: http://www.cnblogs.com/grandyang/p/4086297.html
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0);
		ListNode *curr = res;

		while (l1 && l2) {
			// when both l1 and l2 are not NULL
			if (l1->val <= l2->val) {
				curr->next = l1;
				l1 = l1->next;
			}
			else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		// when one is NULL and the other one is not NULL
		if (l1) curr->next = l1;
		if (l2) curr->next = l2;

		return res->next;
	}
};