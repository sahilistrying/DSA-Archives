/*
 * PROBLEM: Minimum Add to Make Parentheses Valid
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * * PROBLEM DESCRIPTION:
 * A parentheses string is valid if and only if:

	It is the empty string,
	It can be written as AB (A concatenated with B), where A and B are valid strings, or
	It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

	For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Stack, Greedy
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char> st;
        for(auto it:s) {
            if(it=='(') st.push('(');
            else{
                if(!st.empty() && st.top()=='(') st.pop();
                else ans++;
            }
        }
        return ans+st.size();
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
