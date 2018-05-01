/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * Example:
 * 	Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * 	Output: 1->4->3->2->5->NULL
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        
        int idx = 1;
        ListNode* curr = head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* last;
        
        // prev points to the previous node of the starting node
        // curr points to the starting node for reverse
        while (idx < m) {
            prev = prev->next;
            curr = curr->next;
            idx++;
        }
        
        // put all node, which need to be reversed, into stack
        stack<ListNode*> s;
        while (idx < n) {
            s.push(curr);
            curr = curr->next;
            last = curr->next ? curr->next : NULL;
            idx++;
        }
        s.push(curr);   // push the last node
        
        // prev->next points to the nth node
        prev->next = curr;
        
        // reverse the linked nodes
        if (m == 1) head = s.top();
        while (!s.empty()) {
            ListNode* t = s.top();
            curr->next = t;
            curr = curr->next;
            s.pop();
        }
        
        // reconnect the rest of the list
        curr->next = last;
        
        return head;
    }
};