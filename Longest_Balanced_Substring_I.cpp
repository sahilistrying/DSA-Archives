/*
 * PROBLEM: Longest Balanced Substring I
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/longest-balanced-substring-i/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Counting, Enumeration
 */

class Solution {
public:
    int longestBalanced(string s) {
        int sizeuu= s.size(); 
        int ans= 0; 

        for(int i= 0; i< sizeuu; i++){
            unordered_map<int, int> telidhu; 

            for(int j= i; j< sizeuu; j++){
                telidhu[s[j]-'a']++; 
                int freq= 0; 
                bool avuna= true;

                for(int c= 0; c < 26; c++){
                    if(telidhu[c] == 0) continue;
                    if(freq == 0) freq=telidhu[c];
                    else if(telidhu[c]!= freq){
                        avuna= false;
                        break;
                    }
                }

                if(avuna) ans= max(ans, j-i+1);
            }
        }

        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
