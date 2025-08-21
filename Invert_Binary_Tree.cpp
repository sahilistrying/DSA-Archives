/*
 * PROBLEM: Invert Binary Tree
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/invert-binary-tree/
 * * PROBLEM DESCRIPTION:
 * Given the root of a binary tree, invert the tree, and return its root.
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
    void func(TreeNode* root){
        if(root==NULL) return;
        TreeNode* temp;
        if(root->left && root->right) {
            temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        else if(root->left==NULL){
            root->left=root->right;
            root->right=NULL;
        }
        else{
            root->right=root->left;
            root->left=NULL;
        }
        func(root->left);
        func(root->right);


    }
    TreeNode* invertTree(TreeNode* root) {
        func(root);
        return root;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
