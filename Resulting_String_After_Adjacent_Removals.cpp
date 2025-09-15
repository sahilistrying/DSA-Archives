/*
 * PROBLEM: Resulting String After Adjacent Removals
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/resulting-string-after-adjacent-removals/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters.

You must repeatedly perform the following operation while the string s has at least two consecutive characters:

	Remove the leftmost pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
	Shift the remaining characters to the left to fill the gap.

Return the resulting string after no more operations can be performed.

Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Stack, Simulation
 */

class Solution {
public:
    string resultingString(string s) {
        stack<char> stk;
    
        for (char c : s) {
            if (!stk.empty()) {
                char top = stk.top();
                int diff = abs(c - top);
                if (diff == 1 || diff == 25) {
                    stk.pop(); 
                    continue;
                }
            }
            stk.push(c);
        }
    

        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




// Time Complexity: O(N)
// Space Complexity: O(1)
