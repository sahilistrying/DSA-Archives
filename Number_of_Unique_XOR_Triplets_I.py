/*
 * PROBLEM: Number of Unique XOR Triplets I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [1, n].

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Bit Manipulation
 */

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return 1
        elif n==2:
            return 2
        m=n.bit_length()
        return 1<<m

// Time Complexity: O(N)
// Space Complexity: O(1)
