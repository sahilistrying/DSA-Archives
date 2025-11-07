/*
 * PROBLEM: Number of Zero-Filled Subarrays
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/number-of-zero-filled-subarrays/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math
 */

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int s=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               s++;
               ans+=s; 
            }
            else{
                s=0;
            }
            
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
