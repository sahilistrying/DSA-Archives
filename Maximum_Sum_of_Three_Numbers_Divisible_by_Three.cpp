/*
 * PROBLEM: Maximum Sum of Three Numbers Divisible by Three
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

Your task is to choose exactly three integers from nums such that their sum is divisible by three.

Return the maximum possible sum of such a triplet. If no such triplet exists, return 0.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Greedy, Sorting, Heap (Priority Queue)
 */

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int nig=nums.size();
        vector<int>with0,with1,with2;
        for(auto it:nums){
            if(it%3==0) with0.push_back(it);
            if(it%3==1) with1.push_back(it);
            if(it%3==2) with2.push_back(it);
            
        }
        sort(with0.begin(),with0.end(),greater<int>());
        sort(with1.begin(),with1.end(),greater<int>());
        sort(with2.begin(),with2.end(),greater<int>());
        int ans=0;
        if(with0.size()>=3) ans=max(ans,with0[0]+with0[1]+with0[2]);
        if(with1.size()>=3) ans=max(ans,with1[0]+with1[1]+with1[2]);
        if(with2.size()>=3) ans=max(ans,with2[0]+with2[1]+with2[2]);

        if(!with0.empty() && !with1.empty() && !with2.empty() ) ans=max(ans,with0[0]+with1[0]+with2[0]);
        return ans;
    }
    
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
