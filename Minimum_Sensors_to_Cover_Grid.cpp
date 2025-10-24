/*
 * PROBLEM: Minimum Sensors to Cover Grid
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-sensors-to-cover-grid/
 * * PROBLEM DESCRIPTION:
 * You are given n × m grid and an integer k.

A sensor placed on cell (r, c) covers all cells whose Chebyshev distance from (r, c) is at most k.

The Chebyshev distance between two cells (r1, c1) and (r2, c2) is max(|r1 − r2|,|c1 − c2|).

Your task is to return the minimum number of sensors required to cover every cell of the grid.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math
 */

class Solution {
public:
    int minSensors(int n, int m, int k) {
        long long sidididi = 2LL * k + 1;
        long long rowscouldbe = (n + sidididi - 1) / sidididi;
        long long cols = (m + sidididi - 1) / sidididi;
        return rowscouldbe * cols;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
