/*
 * PROBLEM: Copy List with Random Pointer
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/copy-list-with-random-pointer/
 * * PROBLEM DESCRIPTION:
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

	val: an integer representing Node.val
	random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, Linked List
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        Node *clone=new Node(-1);
        Node *clonet=clone;
        map<Node*,Node*> mpp;

        while(temp!=NULL){
            clonet->next=new Node(temp->val);
            clonet=clonet->next;
            mpp[temp]=clonet;
            temp=temp->next;
        }
        temp=head;
        clonet=clone;
        clonet=clonet->next;
        while(temp!=nullptr){
            clonet->random=mpp[temp->random];
            clonet=clonet->next;
            temp=temp->next;
        }
        return clone->next;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
