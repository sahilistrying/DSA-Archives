/*
 * PROBLEM: Palindrome Linked List
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/palindrome-linked-list/
 * * PROBLEM DESCRIPTION:
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List, Two Pointers, Stack, Recursion
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
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->next;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nextt=curr->next;

            curr->next=prev;
            prev=curr;
            curr=nextt;


        }
        return prev;
    }
    bool checkpal(ListNode* one,ListNode* two){
        while(two){
            if(one->val!=two->val) return false;
            one=one->next;
            two=two->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid=findmid(head);
        if(mid==NULL) return true;
        mid=reverse(mid);
        return checkpal(head,mid);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
