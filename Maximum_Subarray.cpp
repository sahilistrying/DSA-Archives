/*
 * PROBLEM: Maximum Subarray
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-subarray/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Divide and Conquer, Dynamic Programming
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int tot=0;
        for(auto it:nums){
            tot+=it;
            if(tot>ans) ans=tot;
            if(tot<0) tot=0;
            
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
