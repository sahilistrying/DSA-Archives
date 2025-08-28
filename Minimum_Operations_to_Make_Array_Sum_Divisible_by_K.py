/*
 * PROBLEM: Minimum Operations to Make Array Sum Divisible by K
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums and an integer k. You can perform the following operation any number of times:

	Select an index i and replace nums[i] with nums[i] - 1.

Return the minimum number of operations required to make the sum of the array divisible by k.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math
 */

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        tot=sum(nums)
        if tot%k==0:
            return 0
        else:
            return tot%k

// Time Complexity: O(N)
// Space Complexity: O(1)
