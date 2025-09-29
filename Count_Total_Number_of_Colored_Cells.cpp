/*
 * PROBLEM: Count Total Number of Colored Cells
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/count-total-number-of-colored-cells/
 * * PROBLEM DESCRIPTION:
 * There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

	At the first minute, color any arbitrary unit cell blue.
	Every minute thereafter, color blue every uncolored cell that touches a blue cell.

Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.

Return the number of colored cells at the end of n minutes.
 * * APPROACH:
 * Solved using Math to optimize the approach.
 * Topics: Math
 */

class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        for(int i=n-1;i>=1;i--){
            ans+=i*4;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
