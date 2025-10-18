/*
 * PROBLEM: Alternating Groups II
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/alternating-groups-ii/
 * * PROBLEM DESCRIPTION:
 * There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

	colors[i] == 0 means that tile i is red.
	colors[i] == 1 means that tile i is blue.

An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Sliding Window
 */

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for (int i = 0; i < k - 1; i++) colors.push_back(colors[i]);
        
        int i = 0, j = 1, ans = 0;
        
        while (j < n + k - 1) {  
            if (colors[j - 1] == colors[j]) {
                i = j;
            } else {
                if (j - i == k - 1) {
                    ans++;
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)
