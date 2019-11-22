/**
 * Given a linked list and a value x, partition it such that all nodes
 * less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each
 * of the two partitions.
 * Example:
 * 	Input: head = 1->4->3->2->5->2, x = 3
 * 	Output: 1->2->2->4->3->5
 * https://leetcode.com/problems/partition-list/description/
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
    ListNode* partition(ListNode* head, int x) {
        // prev and curr are pointers for original list
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* curr = head;
        
        // smallCurr and smallHead are pointers for the list
        // with nodes that are smaller target
        ListNode* smallCurr = new ListNode(0);
        ListNode* smallHead = smallCurr;
        
        // If the flag is non-zero, it means that the head
        // pointer for original list is changed.
        int flag = 0;
        
        while (curr) {
            if (curr->val < x) {
                smallCurr->next = curr;
                smallCurr = smallCurr->next;
            
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                flag++;
                if (flag == 1) head = curr;
                prev = prev->next;
                curr = curr->next;
            }
        }
        if (flag != 0) smallCurr->next = head;
        return smallHead->next;
    }
};