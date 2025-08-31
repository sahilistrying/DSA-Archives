/*
 * PROBLEM: Reverse Degree of a String
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/reverse-degree-of-a-string/
 * * PROBLEM DESCRIPTION:
 * Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

	For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
	Sum these products for all characters in the string.

Return the reverse degree of s.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Simulation
 */

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int val=1;
        for(char &ch: s) {
            ch= toupper(ch);
            sum+=('Z'-ch+1)*val;
            val++;
        } 
        return sum;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
