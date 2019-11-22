/**
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode* head) {
        vector<int> listNode;
        ListNode* curr = head;
        while (curr) {
            listNode.push_back(curr->val);
            curr = curr->next;
        }
        vector<int> reverseListNode = listNode;
        reverse(reverseListNode.begin(), reverseListNode.end());
        return listNode == reverseListNode;
    }
};