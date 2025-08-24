/*
 * PROBLEM: Number of Perfect Pairs
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/number-of-perfect-pairs/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums.

A pair of indices (i, j) is called perfect if the following conditions are satisfied:

	i < j
	Let a = nums[i], b = nums[j]. Then:

		min(|a - b|, |a + b|) <= min(|a|, |b|)
		max(|a - b|, |a + b|) >= max(|a|, |b|)

Return the number of distinct perfect pairs.

Note: The absolute value |x| refers to the non-negative value of x.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Two Pointers, Sorting
 */

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
       vector<int> jurnavalic = nums;
        int n = jurnavalic.size();
        vector<long long> lol(n);
        for (int i = 0; i < n; ++i) lol[i] = llabs((long long)jurnavalic[i]);
        sort(lol.begin(), lol.end());
        long long ans = 0;
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (r < i) r = i;
            while (r + 1 < n && lol[r + 1] <= 2 * lol[i]) ++r;
            ans += (r - i);
        }
        return ans;

    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
