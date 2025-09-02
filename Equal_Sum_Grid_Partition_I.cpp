/*
 * PROBLEM: Equal Sum Grid Partition I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/equal-sum-grid-partition-i/
 * * PROBLEM DESCRIPTION:
 * You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

	Each of the two resulting sections formed by the cut is non-empty.
	The sum of the elements in both sections is equal.

Return true if such a partition exists; otherwise return false.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Matrix, Enumeration, Prefix Sum
 */

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();     
        int n = grid[0].size(); 
        vector<int> rows;
        vector<int> cols;
        long long totrow=0,totcol=0;
        for (int i = 0; i < m; ++i) {
            long long rowsum=0;

            for (int j = 0; j < n; ++j) {
                rowsum+=grid[i][j];

            }
            totrow+=rowsum;

            rows.push_back(rowsum);

        }

        for (int i = 0; i < n; ++i) {
            long long colsum=0;
            for (int j = 0; j < m; ++j) {

                colsum+=grid[j][i];
            }

            totcol+=colsum;
            cols.push_back(colsum);
        }

        
        long long leftsum=0;
        long long rightsum=totrow;
        for(int i=0;i<rows.size();i++){
            leftsum+=rows[i];
            rightsum-=rows[i];

            if(leftsum==rightsum) return true;
        }
        leftsum=0;
        rightsum=totcol;
        for(int i=0;i<cols.size();i++){
            leftsum+=cols[i];
            rightsum-=cols[i];
            if(leftsum==rightsum) return true;
        }
        return false;
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
