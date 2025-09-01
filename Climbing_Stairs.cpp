/*
 * PROBLEM: Climbing Stairs
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/climbing-stairs/
 * * PROBLEM DESCRIPTION:
 * You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math, Dynamic Programming, Memoization
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
