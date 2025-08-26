/*
 * PROBLEM: Maximum Score of a Split
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-score-of-a-split/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of length n.

Choose an index i such that 0 <= i < n - 1.

For a chosen split index i:

	Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i].
	Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].

The score of a split at index i is defined as:

score(i) = prefixSum(i) - suffixMin(i)

Return an integer denoting the maximum score over all valid split indices.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Prefix Sum
 */

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int siz=nums.size();
        vector<long long>pfs(siz),sfm(siz),sco(siz);
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<siz;i++){
            sum+=nums[i];
            pfs[i]=sum;
            
        }
        for(int i=siz-1;i>=0;i--){
            mini=min(mini,nums[i]);
            sfm[i]=mini;
        }
        long long ans=INT_MIN;
        for(int i=0;i<siz-1;i++){
            sco[i]=pfs[i]-sfm[i+1];
            ans=max(ans,sco[i]);
        }
        // for(int i=0;i<siz-1;i++){
        //     if(sco[i]==ans) cout<<i<<"check "<<endl;
        // }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
