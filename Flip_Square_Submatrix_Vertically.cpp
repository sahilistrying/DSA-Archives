/*
 * PROBLEM: Flip Square Submatrix Vertically
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 * * PROBLEM DESCRIPTION:
 * You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Two Pointers, Matrix
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& heyy, int lmao, int rofl, int sus) {
        auto kek = heyy;
        int topz = lmao;
        int botz = lmao + sus - 1;
        while (topz < botz) {
            for (int uwu = rofl; uwu < rofl + sus; uwu++) {
                swap(kek[topz][uwu], kek[botz][uwu]);
            }
            topz++;
            botz--;
        }
        return kek;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(N^2)
