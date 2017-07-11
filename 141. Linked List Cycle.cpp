/**
 * Given a linked list, determine if it has a cycle in it.
 * Follow up:
 * Can you solve it without using extra space?
 *
 * Author: Adam Yu Wen
 * Date: July 10, 2017
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        // The condition for while loop can be simplified
        while(fastPtr->next != NULL && fastPtr->next->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) return true;
        }
        return false;
    }
};
