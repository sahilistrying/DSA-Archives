/*
 * PROBLEM: Balanced Binary Tree
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/balanced-binary-tree/
 * * PROBLEM DESCRIPTION:
 * Given a binary tree, determine if it is height-balanced.
 * * APPROACH:
 * Solved using Tree to optimize the approach.
 * Topics: Tree, Depth-First Search, Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int val=somefunc(root);
        if(val==-1) return false;
        return true;
    }
    int somefunc(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return 1;
        int left=0,right=0;
        if(root->left) left=somefunc(root->left);
        if(root->right)right=somefunc(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return-1;
        cout<<root->val<<"    "<<left<<" "<<right<<endl;
         return max(left,right)+1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
