/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 * Example 1:
 * 	Input: 4->2->1->3
 * 	Output: 1->2->3->4
 * Example 2:
 * 	Input: -1->5->3->4->0
 * 	Output: -1->0->3->4->5
 * https://leetcode.com/problems/sort-list/description/
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
    ListNode* sortList(ListNode* head) {
        vector<int> sortVector;
        ListNode* curr = head;
        while (curr) {
            sortVector.push_back(curr->val);
            curr = curr->next;
        }
        sort(sortVector.begin(), sortVector.end());
        int sortVectorSize = sortVector.size();
        ListNode* pre;
        for (int idx = 0; idx < sortVectorSize; idx++) {
            ListNode* curr = new ListNode(sortVector[idx]);
            curr->next = NULL;
            if (idx == 0) {
                head = curr;
                pre = curr;
            }
            else {
                pre->next = curr;
                pre = pre->next;
            }
        }
        return head;
    }
};