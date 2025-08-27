/*
 * PROBLEM: Check if Array Is Sorted and Rotated
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 * * PROBLEM DESCRIPTION:
 * Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
    
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { 
                count++;
            }
            if (count > 1) return false;
        }
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
