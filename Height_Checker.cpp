/*
 * PROBLEM: Height Checker
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/height-checker/
 * * PROBLEM DESCRIPTION:
 * A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Sorting, Counting Sort
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy=heights;
        sort(heights.begin(),heights.end());
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(heights[i]!=copy[i])ans++;
        }
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
