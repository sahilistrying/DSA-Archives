/*
 * PROBLEM: Jewels and Stones
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/jewels-and-stones/
 * * PROBLEM DESCRIPTION:
 * You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String
 */

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      unordered_map <char,int> mpp;
      for(char c:stones){
        mpp[c]++;
      }  
      int ans=0;
      for(char c:jewels){
        if(mpp[c]) ans+=mpp[c];
      }
      return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
