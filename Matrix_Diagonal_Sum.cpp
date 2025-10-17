/*
 * PROBLEM: Matrix Diagonal Sum
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/matrix-diagonal-sum/
 * * PROBLEM DESCRIPTION:
 * Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Matrix
 */

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int row = 0;
        auto lambda = [&](int sum, vector<int> vec) {
            sum += vec[row];
            if (row != n - row - 1) sum += vec[n - row - 1];
            row++;
            return sum;
        };
        int ans = accumulate(mat.begin(), mat.end(), 0, lambda);
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
