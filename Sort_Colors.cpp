/*
 * PROBLEM: Sort Colors
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/sort-colors/
 * * PROBLEM DESCRIPTION:
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Two Pointers, Sorting
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
