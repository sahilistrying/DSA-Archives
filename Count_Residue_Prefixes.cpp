/*
 * PROBLEM: Count Residue Prefixes
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/count-residue-prefixes/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters in the prefix is equal to len(prefix) % 3.

Return the count of residue prefixes in s.

A prefix of a string is a non-empty substring that starts from the beginning of the string and extends to any point within it.
 * * APPROACH:
 * Implemented an optimized solution.
 * Topics: Algorithms
 */

class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> sttt;
        int ressans=0;
        for(int i=0;i<s.size();i++){
            sttt.insert(s[i]);
            if(sttt.size()==(i+1)%3) ressans++;
        }
        return ressans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
