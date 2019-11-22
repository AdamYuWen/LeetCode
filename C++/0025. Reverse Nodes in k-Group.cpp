/* Given a linked list, reverse the nodes of a linked list k at a time and return its
 * modified list.
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should
 * remain as it is.
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * Author: Adam Yu Wen
 * Date: May 4, 2018
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* subHead = head;
        ListNode* subEnd;
        ListNode* prevSubEnd;
        ListNode* curr = head;
        int flag = 0;
        
        while (curr) {
            // Move curr pointer k - 1 times
            int kTemp = k - 1;
            while (curr && kTemp) {
                curr = curr->next;
                kTemp--;
            }
            
            // curr is NULL and kTemp is non-zero
            // ==> No sublist need to be reverse
            if (kTemp || !curr) return head;
            
            // Reverse a sublist
            subEnd = curr;
            if (curr) curr = curr->next;
            // Delink the rest of the list, so that the reverseList function can be used.
            subEnd->next = NULL;
            reverseList(subHead, subEnd);
            
            // If flag == 1, it is the first reverse.
            flag++;
            if (flag == 1) {
                head = subHead;
            }
            else {
                prevSubEnd->next = subHead;
            }
            
            // Relink the rest of the list.
            subEnd->next = curr;
            prevSubEnd = subEnd;
            subHead = curr;
        }
        return head;
    }
    
    void reverseList(ListNode* &head, ListNode* &end) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        
        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        end = head;
        head = prev;
    }
};
