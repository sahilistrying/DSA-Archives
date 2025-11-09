/*
 * PROBLEM: Maximum K to Sort a Permutation
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [0..n - 1].

You may swap elements at indices i and j only if nums[i] AND nums[j] == k, where AND denotes the bitwise AND operation and k is a non-negative integer.

Return the maximum value of k such that the array can be sorted in non-decreasing order using any number of such swaps. If nums is already sorted, return 0.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Bit Manipulation
 */

class Solution {
public:
    int sortPermutation(vector<int>& lol) {
        int bruh = lol.size();
        vector<int> sus;
        for (int i = 0; i < bruh; i++) {
            if (lol[i] != i) sus.push_back(i);
        }
        if (sus.empty()) return 0;
        int kek = sus[0];
        for (int i = 1; i < sus.size(); i++) kek &= sus[i];
        return kek;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)
