/*
 * PROBLEM: Remove Nth Node From End of List
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    int length(ListNode* head){
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int pos=1;
        int tod=len-n;
        if(tod==0) return head->next;
        ListNode* temp=head;

        while(pos!=tod){
            pos++;
            temp=temp->next;

        }
        temp->next=temp->next->next;
        return head;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
