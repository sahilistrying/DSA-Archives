/*
 * PROBLEM: Linked List Cycle
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/linked-list-cycle/
 * * PROBLEM DESCRIPTION:
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, Linked List, Two Pointers
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
    bool hasCycle(ListNode *head) {
        ListNode *p1=head,*p2=head;
        while(p2!=NULL && p2->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
            if(p1==p2) return true;

        }
        return false;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
