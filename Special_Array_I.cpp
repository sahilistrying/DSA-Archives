/*
 * PROBLEM: Special Array I
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/special-array-i/
 * * PROBLEM DESCRIPTION:
 * An array is considered special if the parity of every pair of adjacent elements is different. In other words, one element in each pair must be even, and the other must be odd.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2 == nums[i+1]%2) return false;
        }
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
