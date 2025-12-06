/*
 * PROBLEM: 1312. Minimum Insertion Steps to Make a String Palindrome
 * PLATFORM: LeetCode
 * DIFFICULTY: Hard
 * URL: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 *
 * EXPLANATION:
 * Bro, this is basically just Longest Palindromic Subsequence (LPS).
 * Min Insertions = Length - LCS(s, reverse(s)).
 * Reuse the LCS logic.
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int func(string &s,int p1,string &t,int p2,vector<vector<int>> &dp){
        if(p1<0 || p2<0) return 0;
        if(dp[p1][p2]!=-1) return dp[p1][p2];
        int take=0,nottake=0;
        if(s[p1]==t[p2]) take=1+func(s,p1-1,t,p2-1,dp);
        else nottake=max(func(s,p1-1,t,p2,dp),func(s,p1,t,p2-1,dp));
        return dp[p1][p2]=max(take,nottake);
    }
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(t.begin(),t.end());
        return n-func(s,n-1,t,n-1,dp);
    }
};