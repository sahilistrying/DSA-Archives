/*
 * PROBLEM: Valid Parentheses
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/valid-parentheses/
 * * PROBLEM DESCRIPTION:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Every close bracket has a corresponding open bracket of the same type.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Stack
 */

class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' ){
                if(st.empty() || st.top()!='(') return false;
                st.pop();
            }
            else if( s[i]=='}' ){
                if(st.empty() || st.top()!='{') return false;
                st.pop();
            }
            else if(s[i]==']' ){
                if(st.empty() || st.top()!='[') return false;
                st.pop();
            }
            else st.push(s[i]);
        }
        if(st.empty()) return true;
        else return false;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
