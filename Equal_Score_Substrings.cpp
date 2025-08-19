/*
 * PROBLEM: Equal Score Substrings
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/equal-score-substrings/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters.

The score of a string is the sum of the positions of its characters in the alphabet, where 'a' = 1, 'b' = 2, ..., 'z' = 26.

Determine whether there exists an index i such that the string can be split into two non-empty substrings s[0..i] and s[(i + 1)..(n - 1)] that have equal scores.

Return true if such a split exists, otherwise return false.
 * * APPROACH:
 * Solved using String to optimize the approach.
 * Topics: String, Prefix Sum
 */

class Solution {
public:
    bool scoreBalance(string s) {
        int sizz= s.size(); 

        int motham= 0; 
        for(int i= 0; i< sizz; i++){
            motham+= (s[i] - 'a' + 1);
        }

        int pakka= 0; 
        for(int i= 0; i< sizz; i++){
            pakka+= (s[i]-'a'+1);
            int atupakka= motham-pakka; 
            if(atupakka == pakka){
                return true;
            }
        }
        return false;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
