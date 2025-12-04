/*
 * PROBLEM: 1143. Longest Common Subsequence
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * URL: https://leetcode.com/problems/longest-common-subsequence/
 *
 * EXPLANATION:
 * Classic LCS. Matches add 1 to diag, mismatches take max(left, top).
 * Wrote the recursive helper first to verify logic then tabulation.
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        if(text1[0]==text2[0]) dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(text1[i]==text2[0] || dp[i-1][0]==1) dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            if(text2[i]==text1[0] || dp[0][i-1]==1) dp[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};