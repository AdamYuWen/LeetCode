/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 * A:          a1 → a2
 *                    \
 *                      c1 → c2 → c3
 *                    /            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4128461.html
 *
 * Author: Adam Yu Wen
 * Date: April 25, 2018
 */

// Method 1:
// It is very slow, which takes 762 ms.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while (currA) {
            while (currB) {
                if (currA == currB) return currA;
                currB = currB->next;
            }
            currA = currA->next;
            currB = headB;
        }
        return NULL;
    }
};


// Method 2:
// It takes 36 ms.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	// The following line make the solution slower.
	// With it, the solution takes 44 ms.
        //if (!headA || !headB) return NULL;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while (currA != currB) {
	    // Notice: When a list is done, point to the other list.
            currA = currA ? currA->next : headB;
            currB = currB ? currB->next : headA;
        }
        return currA;
    }
};
