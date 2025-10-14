/*
 * PROBLEM: Minimum Adjacent Swaps to Alternate Parity
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/
 * * PROBLEM DESCRIPTION:
 * You are given an array nums of distinct integers.

In one operation, you can swap any two adjacent elements in the array.

An arrangement of the array is considered valid if the parity of adjacent elements alternates, meaning every pair of neighboring elements consists of one even and one odd number.

Return the minimum number of adjacent swaps required to transform nums into any valid arrangement.

If it is impossible to rearrange nums such that no two adjacent elements have the same parity, return -1.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Greedy
 */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> evens, odds;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0)
                evens.push_back(i);
            else
                odds.push_back(i);
        }

      
        if (abs((int)evens.size() - (int)odds.size()) > 1)
            return -1;

      
        auto calc_cost = [](const vector<int>& indices, bool start_with_even) -> int {
            int cost = 0;
            for (int i = 0; i < indices.size(); ++i) {
                cost += abs(indices[i] - 2 * i);
            }
            return cost;
        };

        
        if (evens.size() == odds.size()) {
            return min(calc_cost(evens, true), calc_cost(odds, false));
        } else if (evens.size() > odds.size()) {
            return calc_cost(evens, true);
        } else {
            return calc_cost(odds, false);
        }
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)
