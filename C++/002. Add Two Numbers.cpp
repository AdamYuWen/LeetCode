/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number
 * 0 itself.
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * Author: Adam Yu Wen
 * Date: April 27, 2018
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> qL1, qL2;
        while (l1) {
            qL1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            qL2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* curr = new ListNode(0);
        ListNode* res = curr;
        ListNode* pre = curr;
        while (!qL1.empty() || !qL2.empty()) {
            if (!qL1.empty()) {sum += qL1.front(); qL1.pop();}
            if (!qL2.empty()) {sum += qL2.front(); qL2.pop();}
            curr->val = sum % 10;
            ListNode* end = new ListNode(sum / 10);
            curr->next = end;
            pre = curr;
            curr = end;
            sum /= 10;
        }
        if (pre->next->val == 0) pre->next = NULL;
        return res;
    }
};