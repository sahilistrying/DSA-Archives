/*
 * PROBLEM: Delete Greatest Value in Each Row
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/delete-greatest-value-in-each-row/
 * * PROBLEM DESCRIPTION:
 * You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

	Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
	Add the maximum of deleted elements to the answer.

Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Sorting, Heap (Priority Queue), Matrix, Simulation
 */

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(vector<int> &i : grid)
            sort(i.begin(), i.end());

        int j = grid[0].size() - 1, ans = 0;

        while(j >= 0) {
            int temp = INT_MIN;

            
            for(int i = 0; i < grid.size(); i++)
                temp = max(temp, grid[i][j]);

            ans += temp;

            j--;
        }

        return ans; 
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N^2)
