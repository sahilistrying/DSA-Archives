/*
 * PROBLEM: Count Caesar Cipher Pairs
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/count-caesar-cipher-pairs/
 * * PROBLEM DESCRIPTION:
 * You are given an array words of n strings. Each string has length m and contains only lowercase English letters.

Two strings s and t are similar if we can apply the following operation any number of times (possibly zero times) so that s and t become equal.

	Choose either s or t.
	Replace every letter in the chosen string with the next letter in the alphabet cyclically. The next letter after 'z' is 'a'.

Count the number of pairs of indices (i, j) such that:

	i < j
	words[i] and words[j] are similar.

Return an integer denoting the number of such pairs.
 * * APPROACH:
 * Implemented an optimized solution.
 * Topics: Algorithms
 */

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int>freqmapp;
        long long cntot=0;
        for(string winL:words){
            int tochange=winL[0]-'a';
            string making="";
            for(char c:winL){
                int newsmtg=(c-'a'-tochange+26)%26;
                making+=(char)(newsmtg+'a');
            }
            if(freqmapp.count(making)) cntot+=freqmapp[making];
            freqmapp[making]++;
        }
        return cntot;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
