/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving
 * only distinct numbers from the original list.
 * Example 1:
 * 	Input: 1->2->3->3->4->4->5
 * 	Output: 1->2->5
 * Example 2:
 * 	Input: 1->1->1->2->3
 * 	Output: 2->3
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4069003.html
 *
 * Author: Adam Yu Wen
 * Date: May 1, 2018
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* prev = start;
        while (prev->next) {
            ListNode* curr = prev->next;
            while (curr->next && curr->val == curr->next->val) curr = curr->next;
            // The following line: prev->next points to a new node
            // However, the prev pointer doesn't move
            if (prev->next != curr) prev->next = curr->next;
            else prev = prev->next;
        }
        return start->next;
    }
};