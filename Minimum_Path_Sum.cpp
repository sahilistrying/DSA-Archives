/*
 * PROBLEM: Minimum Path Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-path-sum/
 * * PROBLEM DESCRIPTION:
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming, Matrix
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[1][1]=grid[0][0];
        for(int i=2;i<=n;i++){
            dp[1][i]=grid[0][i-1]+dp[1][i-1];
        }
        for(int i=2;i<=m;i++){
            dp[i][1]=grid[i-1][0]+dp[i-1][1];
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
