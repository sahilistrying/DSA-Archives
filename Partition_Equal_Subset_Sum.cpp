/*
 * PROBLEM: Partition Equal Subset Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/partition-equal-subset-sum/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming
 */

class Solution {
public:
    bool func(int n,int target,vector<int>&nums,vector<vector<int>> &dp){
        
        
        if(target==0) return true;
        if(n==0) return false;
        if(dp[n][target]!=-1) return dp[n][target];
        bool leave=func(n-1,target,nums,dp);
        bool take=false;
        if(target>=nums[n-1]) take=func(n-1,target-nums[n-1],nums,dp);

        return dp[n][target]=take||leave;

    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int ts=0;
        for(auto it:nums) ts+=it;
        if(ts%2!=0) return false;
        int target=ts/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return func(n,target,nums,dp);

    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
