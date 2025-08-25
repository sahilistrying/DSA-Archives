/*
 * PROBLEM: Sort List
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/sort-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a linked list, return the list after sorting it in ascending order.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
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
    ListNode* findmid(ListNode* head){
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findmid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        head=mergesort(head);
        right=mergesort(right);
        return merge(head,right);

    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(left && right){
            if(left->val>right->val){
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
            else{
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }

        }
        while(left){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
