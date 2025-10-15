/*
 * PROBLEM: Find Most Frequent Vowel and Consonant
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters ('a' to 'z'). 

Your task is to:

	Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
	Find the consonant (all other letters excluding vowels) with the maximum frequency.

Return the sum of the two frequencies.

Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.

The frequency of a letter x is the number of times it occurs in the string.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Counting
 */

class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> cnt;
        for(char c:s){
            cnt[c]++;
        }
        int maxv=0,maxc=0;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ){
                if(cnt[c]>maxv) maxv=cnt[c];
            }
            else{
                if(cnt[c]>maxc) maxc=cnt[c];
            }
        }
        return maxv+maxc;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
