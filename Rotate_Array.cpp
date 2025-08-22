/*
 * PROBLEM: Rotate Array
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/rotate-array/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Two Pointers
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
