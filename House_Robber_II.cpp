/*
 * PROBLEM: House Robber II
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/house-robber-ii/
 * * PROBLEM DESCRIPTION:
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> smtg(n);
        vector<int> dp0(n+1),dp1(n+2);
        for(int i=0;i<n-1;i++){
            smtg[i]=nums[i+1];
        }
        dp0[0]=0;
        dp1[0]=0;
        dp0[1]=nums[0];
        dp1[1]=smtg[0];
        for(int i=2;i<n;i++){
            dp0[i]=max(nums[i-1]+dp0[i-2], dp0[i-1]);

        }
        for(int i=2;i<=n;i++){
            dp1[i]=max(smtg[i-1]+dp1[i-2], dp1[i-1]);

        }
        
        return max(dp0[n-1],dp1[n]);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
