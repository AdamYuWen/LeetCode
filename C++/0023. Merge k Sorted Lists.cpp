/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * Author: Adam Yu Wen
 * Date: May 2, 2018
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> allNodes;
        for (auto list : lists) {
            ListNode* curr = list;
            while (curr) {
                allNodes.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(allNodes.begin(), allNodes.end());
        
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        int allNodesSize = allNodes.size();
        for (int idx = 0; idx < allNodesSize; idx++) {
            ListNode* newNode = new ListNode(allNodes[idx]);
            curr->next = newNode;
            curr = curr->next;
        }
        return head->next;
    }
};