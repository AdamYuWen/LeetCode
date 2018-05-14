/* A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4261431.html
 *
 * Author: Adam Yu Wen
 * Date: May 8, 2018
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* copyCur = new RandomListNode(head->label);
        RandomListNode* copyHead = copyCur;
        RandomListNode* cur = head->next;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        mp[head] = copyHead;
        while (cur) {
            RandomListNode* newNode = new RandomListNode(cur->label);
            cout << newNode->label << endl;
            copyCur->next = newNode;
            mp[cur] = newNode;
            copyCur = copyCur->next;
            cur = cur->next;
        }
        
        cur = head;
        copyCur = copyHead;
        while (copyCur) {
            copyCur->random = mp[cur->random];
            copyCur = copyCur->next;
            cur = cur->next;
        }
        
        return copyHead;
    }
};
