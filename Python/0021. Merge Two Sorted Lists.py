# Merge two sorted linked lists and return it as a new list.
# The new list should be made by splicing together the nodes
# of the first two lists.
# https://leetcode.com/problems/merge-two-sorted-lists/description/
# 
# Author: Adam Yu Wen
# Date: June 28, 2018

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1
        res = cur = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if not l1:
            cur.next = l2
        else:
            cur.next = l1
        return res.next
        
