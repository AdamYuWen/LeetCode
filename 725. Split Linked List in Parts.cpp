/* Given a (singly) linked list with head node root, write a function to split the linked
 * list into k consecutive linked list "parts".
 * The length of each part should be as equal as possible: no two parts should have a size
 * differing by more than 1. This may lead to some parts being null.
 * The parts should be in order of occurrence in the input list, and parts occurring earlier
 * should always have a size greater than or equal parts occurring later.
 * Return a List of ListNode's representing the linked list parts that are formed.
 * Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
 * Example 1:
 *  Input: 
 *  root = [1, 2, 3], k = 5
 *  Output: [[1],[2],[3],[],[]]
 *  Explanation:
 *  The input and each element of the output are ListNodes, not arrays.
 *  For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3,
 *  and root.next.next.next = null.
 *  The first element output[0] has output[0].val = 1, output[0].next = null.
 *  The last element output[4] is null, but it's string representation as a ListNode is [].
 * Example 2:
 *  Input: 
 *  root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 *  Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 *  Explanation:
 *  The input has been split into consecutive parts with size difference at most 1, and
 *  earlier parts are a larger size than the later parts.
 * Note:
 *  The length of root will be in the range [0, 1000].
 *  Each value of a node in the input will be an integer in the range [0, 999].
 *  k will be an integer in the range [1, 50].
 * https://leetcode.com/problems/split-linked-list-in-parts/description/
 *
 * Author: Adam Yu Wen
 * Date: May 7, 2018
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k);
        
        // if root is NULL
        if (!root) return res;
        
        // if root is not NULL
        if (root) res[0] = root;
        int idx = 1;    // index for putting values in res
        
        // count the number of nodes
        ListNode* cur = root;
        int numNodes = 0;
        while (cur) {
            numNodes++;
            cur = cur->next;
        }
        
        // decide the number of nodes in each part
        int averageNodes = numNodes / k;
        int remainder = numNodes % k;
        
        // start to split
        cur = root;
        int averageNodesTmp = averageNodes;
        while (cur) {
            // move to the position that need to break
            int moveStep = averageNodesTmp + (remainder > 0) - 1;
            // moveStep < 0 ==> rest of the res should be blank
            if (moveStep < 0) {
                return res;
            }
            else {
                // move cur to the last node of each part
                while (cur && moveStep) {
                    cur = cur->next;
                    moveStep--;
                }
                
                // put the next node into res
                if (cur && cur->next) {
                    res[idx] = cur->next;
                    idx++;
                }
                
                // break the previous part
                if (cur) {
                    ListNode* setNull = cur;
                    cur = cur->next;
                    setNull->next = NULL;
                }
                remainder--;
            }
        }
        return res;
    }
};
