/*
 * PROBLEM: Reverse Linked List
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/reverse-linked-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List, Recursion
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head,*prev=NULL;
        while(temp){
            ListNode* n=temp->next;
            temp->next=prev;
            prev=temp;
            temp=n;
        }
        return prev;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
