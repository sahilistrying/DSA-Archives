/*
 * PROBLEM: Rotate List
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/rotate-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL) return head;
        int size=0;
        ListNode *temp=head,*prev=NULL;
        while(temp){
            size++;
            prev=temp;
            temp=temp->next;
        }
        
        k=k%size;
        if(k==0) return head;
        int t=size-k;
        temp=head;
        while(temp){
            t--;
            if(t==0) break;
            temp=temp->next;
            
        }
        prev->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
