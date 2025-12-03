/*
 * PROBLEM: 518. Coin Change II
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * URL: https://leetcode.com/problems/coin-change-ii/
 *
 * EXPLANATION:
 * Same as coin change 1, but we need total ways, not min coins.
 * So instead of min(), I just summed up take + nottake.
 * Used unsigned long long to be safe from overflows.
 */
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                unsigned long long nottake=dp[i-1][j];
                unsigned long long take=0;
                if(j>=coins[i]) take=dp[i][j-coins[i]];
                dp[i][j]=(unsigned long long)take+nottake;
            }
        }
        return (int)dp[n-1][amount];
    }
};
