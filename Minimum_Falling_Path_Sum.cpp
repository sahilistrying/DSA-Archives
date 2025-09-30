/*
 * PROBLEM: Minimum Falling Path Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-falling-path-sum/
 * * PROBLEM DESCRIPTION:
 * Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming, Matrix
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            dp[1][i]=matrix[0][i-1];
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                int min1=INT_MAX;
                int min3=INT_MAX;
                int min2=INT_MAX;
                if(j>1) min1=dp[i-1][j-1];
                min2=dp[i-1][j];
                if(j<n) min3=dp[i-1][j+1];
                int mint=INT_MAX;
                mint=min(min1,min2);
                mint=min(mint,min3);
                dp[i][j]=matrix[i-1][j-1]+mint;
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++) ans=min(ans,dp[n][i]);
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
