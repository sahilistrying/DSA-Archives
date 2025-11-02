/*
 * PROBLEM: Find the Number of Ways to Place People I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
 * * PROBLEM DESCRIPTION:
 * You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

	A is on the upper left side of B, and
	there are no other points in the rectangle (or line) they make (including the border), except for the points A and B.

Return the count.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Math, Geometry, Sorting, Enumeration
 */

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1]; 

                if (y2 > y1) { 
                    continue;
                }

                if (y2 > bestY) {
                    result++;
                    bestY = y2;
                }
            }
        }

        return result;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N^2)
