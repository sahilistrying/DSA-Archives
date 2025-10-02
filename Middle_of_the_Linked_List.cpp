/*
 * PROBLEM: Middle of the Linked List
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/middle-of-the-linked-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List, Two Pointers
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* sl=head,*fa=head;
        while(fa && fa->next){
            sl=sl->next;
            fa=fa->next->next;
        }
        return sl;

    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
