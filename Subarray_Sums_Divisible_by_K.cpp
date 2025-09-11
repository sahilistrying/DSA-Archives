/*
 * PROBLEM: Subarray Sums Divisible by K
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * * PROBLEM DESCRIPTION:
 * Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Prefix Sum
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
{
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++) 
        {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            res += mp[rem];

            mp[rem]++;
        }

        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
