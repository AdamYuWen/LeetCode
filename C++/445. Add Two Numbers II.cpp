/**
 * You are given two non-empty linked lists representing two non-negative integers. The most
 * significant digit comes first and each of their nodes contain a single digit. Add the two
 * numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 * Reference: http://www.cnblogs.com/grandyang/p/6216480.html
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
        stack<int> stackL1, stackL2;
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;
        while (currL1) {
            stackL1.push(currL1->val);
            currL1 = currL1->next;
        }
        while (currL2) {
            stackL2.push(currL2->val);
            currL2 = currL2->next;
        }
        
        int sum = 0;
        ListNode* res = new ListNode(0);
        while (!stackL1.empty() || !stackL2.empty()) {
            if (!stackL1.empty()) {sum += stackL1.top(); stackL1.pop();}
            if (!stackL2.empty()) {sum += stackL2.top(); stackL2.pop();}
            res->val = sum % 10;
            ListNode* head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};