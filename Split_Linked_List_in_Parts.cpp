/*
 * PROBLEM: Split Linked List in Parts
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/split-linked-list-in-parts/
 * * PROBLEM DESCRIPTION:
 * Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.
 * * APPROACH:
 * Solved using Linked List to optimize the approach.
 * Topics: Linked List
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
    int findSize(ListNode* head){
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=findSize(head);
        vector<ListNode*> arr;
        float div=float(size)/k;
        int co=(div);
        int divtill=0;
        
        
            divtill=size%k;
        
        for(int i = 0; i < k; i++){
            
            ListNode *push=new ListNode(-1);
            ListNode *topush=push;
            int to;
            if(i<divtill){
                to=co+1;
            }
            else to=co;
            for(int j=0;j<to;j++){
                if(head==NULL) break;
                topush->next=new ListNode(head->val);

                head=head->next;
             
                topush=topush->next;
                
           
               
            }
            arr.push_back(push->next);
        }
        
        return arr; 
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
