/*
 * PROBLEM: Add Two Numbers
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/add-two-numbers/
 * * PROBLEM DESCRIPTION:
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List, Math, Recursion
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool c=false;
        ListNode* dum=new ListNode(-1);
        ListNode* head=dum;
        while(l1 && l2){
            int vv=l1->val+l2->val;
            if(c){
                vv++;
                c=false;
            } 
            if(vv>9){
                vv=vv%10; 
                c=true;
            }
            dum->next=new ListNode(vv);
            dum=dum->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int vv=l1->val;
            if(c){
                vv++;
                c=false;
            }
             if(vv>9){
                vv=vv%10; 
                c=true;
            }
            dum->next=new ListNode(vv);
            dum=dum->next;
            l1=l1->next;
        }
        while(l2){
            int vv=l2->val;
            if(c){
                vv++;
                c=false;
            }
             if(vv>9){
                vv=vv%10; 
                c=true;
            }
            dum->next=new ListNode(vv);
            dum=dum->next;
            l2=l2->next;
        }
        if(c) dum->next=new ListNode(1);
        return head->next;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
