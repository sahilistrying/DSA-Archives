/*
 * PROBLEM: Minimum Swaps to Sort by Digit Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
 * * PROBLEM DESCRIPTION:
 * You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, Sorting
 */

class Solution {
public:

    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        for (int num : nums) {
            arr.push_back({digitSum(num), num});
        }

        vector<pair<int, int>> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < n; ++i) {
            valueToIndex[sortedArr[i].second] = i;
        }
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || valueToIndex[nums[i]] == i)
                continue;

            int cycle_len = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = valueToIndex[nums[j]];
                cycle_len++;
            }

            if (cycle_len > 1)
                swaps += (cycle_len - 1);
        }

        return swaps;
    }
};


// Time Complexity: O(N log N)
// Space Complexity: O(N)
