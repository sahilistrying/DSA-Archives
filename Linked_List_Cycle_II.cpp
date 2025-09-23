/*
 * PROBLEM: Linked List Cycle II
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/linked-list-cycle-ii/
 * * PROBLEM DESCRIPTION:
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=head;
        ListNode *p2=head;
        bool found=false;
        while(p2!=NULL && p2->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
            if(p1==p2){           
                
                found=true;
                break;
            }
        }
        if(!found) return NULL;
        else{
            ListNode *st=head;
            while(st!=p1){
                st=st->next;
                p1=p1->next;
            }
            return st;
        }
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
