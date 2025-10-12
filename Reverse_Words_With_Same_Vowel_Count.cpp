/*
 * PROBLEM: Reverse Words With Same Vowel Count
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/reverse-words-with-same-vowel-count/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English words, each separated by a single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.
 * * APPROACH:
 * Solved using Two Pointers to optimize the approach.
 * Topics: Two Pointers, String, Simulation
 */

class Solution {
public:
    string reverseWords(string s) {
        int cntt=0;
        stringstream ss(s);
        string word;
        string ans;
        ss>>word;
        for(auto it:word){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') cntt++;
        }
        ans+=word+" ";
     
        while(ss>>word){
            int che=0;
            for(auto it:word){
                if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') che++;       
            }
            if(che==cntt){
                reverse(word.begin(),word.end());
            }
            ans+=word+" ";
        }
        ans.pop_back();
        
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
