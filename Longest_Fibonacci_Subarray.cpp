/*
 * PROBLEM: Longest Fibonacci Subarray
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/longest-fibonacci-subarray/
 * * PROBLEM DESCRIPTION:
 * You are given an array of positive integers nums.

A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of the two preceding terms.

Return the length of the longest Fibonacci subarray in nums.

Note: Subarrays of length 1 or 2 are always Fibonacci.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size(); 
        }

        vector<int> ank= nums; 
        int pora= 2; 
        int porarey= 2;

        for(int i= 2; i< ank.size(); i++){
            if(ank[i-2]+ank[i-1]== ank[i]){
                porarey++; 
            } else {
                pora= max(pora, porarey); 
                porarey= 2; 
            }
        }

        return max(pora, porarey); 
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
