/*
 * PROBLEM: Single Number
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/single-number/
 * * PROBLEM DESCRIPTION:
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Bit Manipulation
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long ans=0;
        for(int i:nums){
            ans=i^ans;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
