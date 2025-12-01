/*
 * PROBLEM: 322. Coin Change
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * URL: https://leetcode.com/problems/coin-change/
 *
 * EXPLANATION:
 * Standard unbounded knapsack. I tried recursion first but obviously memoized it.
 * Then converted to tabulation for optimization.
 * Basically: dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coin]).
 * Used 1e9 as infinity cause INT_MAX overflows sometimes.
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        for(int i=1;i<=amount;i++) {
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j) take=1 + dp[i][j - coins[i]];
                dp[i][j]=min(take,nottake);
            }
        }
        int ans =dp[n-1][amount];
        if(ans>=1e9) return -1;
        else return ans;
    }
};