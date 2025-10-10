/*
 * PROBLEM: Array Partition
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/array-partition/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Greedy, Sorting, Counting Sort
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2) ans+=nums[i];
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
