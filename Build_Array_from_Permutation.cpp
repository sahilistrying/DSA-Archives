/*
 * PROBLEM: Build Array from Permutation
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/build-array-from-permutation/
 * * PROBLEM DESCRIPTION:
 * Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Simulation
 */

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) ans.push_back(nums[nums[i]]);
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
