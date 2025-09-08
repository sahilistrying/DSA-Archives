/*
 * PROBLEM: Find Minimum Log Transportation Cost
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-minimum-log-transportation-cost/
 * * PROBLEM DESCRIPTION:
 * You are given integers n, m, and k.

There are two logs of lengths n and m units, which need to be transported in three trucks where each truck can carry one log with length at most k units.

You may cut the logs into smaller pieces, where the cost of cutting a log of length x into logs of length len1 and len2 is cost = len1 * len2 such that len1 + len2 = x.

Return the minimum total cost to distribute the logs onto the trucks. If the logs don't need to be cut, the total cost is 0.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math
 */

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans=0;
        if(n<=k && m<=k) return ans;
        else if(n>k){
            long long a=n-k;
            long long b=n-a;
            ans=a*b;
        }
        else{
            long long a=m-k;
            long long b=m-a;
            ans=a*b;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
