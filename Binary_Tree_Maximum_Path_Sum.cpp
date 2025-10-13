/*
 * PROBLEM: Binary Tree Maximum Path Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * * PROBLEM DESCRIPTION:
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
 * * APPROACH:
 * Solved using Dynamic Programming to optimize the approach.
 * Topics: Dynamic Programming, Tree, Depth-First Search, Binary Tree
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
    int fans=INT_MIN;
    int sum=0;
    int somefunc(TreeNode* root){
        if(root==NULL) return 0;
        int ls=somefunc(root->left);
        int rs=somefunc(root->right);
        if(ls<=0) ls=0;
        if(rs<=0) rs=0;
        int temp=ls+rs+root->val;
        fans=max(fans,temp);
        sum=max(ls,rs)+root->val;
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        somefunc(root);
        return fans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) (Recursive Stack)
