/*
 * PROBLEM: Minimum Operations to Convert All Elements to Zero
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
 * * PROBLEM DESCRIPTION:
 * You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Stack, Greedy, Monotonic Stack
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int o = 0;
        vector<int> s = {0};

        for (int x : nums) {
            while (!s.empty() && s.back() > x) {
                s.pop_back();
            }
            if (s.back() < x) {
                s.push_back(x);
                o++;
            }
        }

        return o;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)
