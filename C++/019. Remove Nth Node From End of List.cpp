/* Given a linked list, remove the n-th node from the end of list and return its head.
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note: Given n will always be valid.
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * Author: Adam Yu Wen
 * Date: April 26, 2018
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        if (n == 0) return head;
        
        // The previous node of the n-th node
        int preIdx = numListNode(head) - n;
        
        // Delete the first node
        if (preIdx == 0) {
            head = head->next;
            return head;
        }
        // Delete any one from the rest
        int idx = 1;
        ListNode* curr = head;
        while (idx < preIdx) {
            curr = curr->next;
            idx++;
        }
        curr->next = curr->next->next;
        return head;
    }
    
    int numListNode(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
};