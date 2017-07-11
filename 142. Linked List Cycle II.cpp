/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
 *
 * Author: Adam Yu Wen
 * Date: July 11, 2017
 * Reference: http://www.cnblogs.com/hiddenfox/p/3408931.html
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;

        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while(fastPtr->next != NULL && fastPtr->next->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) {
                // Because a = c in the reference,
                // we let slowPtr start from the beginning again
                // and return the next point that they meet
                slowPtr = head;
                while(slowPtr != fastPtr) {
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return fastPtr;
            }
        }
        return NULL;
    }
};
