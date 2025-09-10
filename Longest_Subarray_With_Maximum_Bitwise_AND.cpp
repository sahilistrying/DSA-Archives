/*
 * PROBLEM: Longest Subarray With Maximum Bitwise AND
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

	In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.

Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Bit Manipulation, Brainteaser
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxe=*max_element(nums.begin(),nums.end());
        int c=0;
        int ans=INT_MIN;
        for(auto it:nums){
            if(it==maxe){
                c++;
                ans=max(ans,c);
            }
            else{
                c=0;
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
