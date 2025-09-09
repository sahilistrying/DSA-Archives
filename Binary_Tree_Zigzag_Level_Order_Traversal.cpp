/*
 * PROBLEM: Binary Tree Zigzag Level Order Traversal
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * * PROBLEM DESCRIPTION:
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 * * APPROACH:
 * Solved using Tree to optimize the approach.
 * Topics: Tree, Breadth-First Search, Binary Tree
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(temp);
        }
        bool flag=true;
        for(auto &it:ans){
            if(flag){
                flag=false;
                continue;
            }
            reverse(it.begin(),it.end());
            flag=true;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
