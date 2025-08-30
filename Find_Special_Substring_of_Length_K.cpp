/*
 * PROBLEM: Find Special Substring of Length K
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-special-substring-of-length-k/
 * * PROBLEM DESCRIPTION:
 * You are given a string s and an integer k.

Determine if there exists a substring of length exactly k in s that satisfies the following conditions:

	The substring consists of only one distinct character (e.g., "aaa" or "bbb").
	If there is a character immediately before the substring, it must be different from the character in the substring.
	If there is a character immediately after the substring, it must also be different from the character in the substring.

Return true if such a substring exists. Otherwise, return false.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String
 */

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int cnt=1;
        for(int i=0;i<s.size()-1;i++){
            
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                if(cnt==k) return true;
                cnt=1;
            }
        }
        if(cnt==k) return true;
        return false;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
