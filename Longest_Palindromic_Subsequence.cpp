/*
 * PROBLEM: 516. Longest Palindromic Subsequence
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * URL: https://leetcode.com/problems/longest-palindromic-subsequence/
 *
 * EXPLANATION:
 * LPS is just LCS of string S and Reverse(S).
 * So I reversed it and ran the same LCS logic. 
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        if(s[0]==t[0]) dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(dp[0][i-1]==1 || s[0]==t[i]) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            if(dp[i-1][0]==1 || s[i]==t[0]) dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(s[i]==t[j]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][n-1];
    }
};