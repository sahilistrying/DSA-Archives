/*
 * PROBLEM: 494. Target Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * URL: https://leetcode.com/problems/target-sum/
 *
 * EXPLANATION:
 * Instead of recursion with + and -, I used the math trick:
 * P - N = Target
 * P + N = Sum
 * => 2P = Target + Sum => P = (Target + Sum)/2.
 * So just find count of subsets with sum P. Much faster.
 */
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ts=0;
        int n=nums.size();
        for(auto it:nums) ts+=it;
        int val=ts-target;
        if(ts<target || val%2!=0) return 0;
        int tar=val/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        
        // Base case handling
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0 && nums[0]<=tar) dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(j>=nums[i]) take=dp[i-1][j-nums[i]];
                dp[i][j]=take+nottake;
            }
        }
        return dp[n-1][tar];
    }
};