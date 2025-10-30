/*
 * PROBLEM: Vertical Order Traversal of a Binary Tree
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * LEETCODE URL: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * * PROBLEM DESCRIPTION:
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree
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
    
    void func(TreeNode* root,map<int,map<int,vector<int>>> &mpp,int pos,int hor){
        if(root==NULL) return;
        mpp[pos][hor].push_back(root->val);
        func(root->left,mpp,pos-1,hor+1);
        func(root->right,mpp,pos+1,hor+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,vector<int>>> mpp;
        if(root==NULL) return ans;
        func(root,mpp,1000,0);
        for(auto &[k,it]:mpp){
            vector<int>temp;
            for(auto &[id,vec]:it){
                sort(vec.begin(),vec.end());
                for(auto vall:vec) temp.push_back(vall);

            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N) (Recursive Stack)
