/*
 * PROBLEM: Triangle
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/triangle/
 * * PROBLEM DESCRIPTION:
 * Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Dynamic Programming
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        dp[1][1]=triangle[0][0];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                int min1=INT_MAX;
                int min2=INT_MAX;
                if(j>1) min1=dp[i-1][j-1];
                if(j<i) min2=dp[i-1][j];
               // cout<<"check "<<min1<<" "<<min2<<endl;
                dp[i][j]=triangle[i-1][j-1]+min(min1,min2);
            }
        }
        int minn=INT_MAX;
        for(int i=1;i<=n;i++) minn=min(minn,dp[n][i]);
        return minn;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
