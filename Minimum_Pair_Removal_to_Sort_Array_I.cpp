/*
 * PROBLEM: Minimum Pair Removal to Sort Array I
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
 * * PROBLEM DESCRIPTION:
 * Given an array nums, you can perform the following operation any number of times:

	Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
	Replace the pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (true) {
            bool sorted = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) return count;

            int min_sum = INT_MAX;
            int pos = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < min_sum) {
                    min_sum = sum;
                    pos = i;
                }
            }

            nums[pos] = min_sum;
            nums.erase(nums.begin() + pos + 1);
            count++;
        }
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
