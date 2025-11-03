/*
 * PROBLEM: Same Tree
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/same-tree/
 * * PROBLEM DESCRIPTION:
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * * APPROACH:
 * Solved using Tree to optimize the approach.
 * Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* one,TreeNode* two){
        if(one==NULL && two==NULL) return true;
        if(one==NULL || two==NULL) return false;
        if(one->val != two->val) return false;
        bool c1=check(one->left,two->left);
        if(!c1)return false;
        bool c2=check(one->right,two->right);
        if(!c2) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
