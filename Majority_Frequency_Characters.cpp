/*
 * PROBLEM: Majority Frequency Characters
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/majority-frequency-characters/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters.

The frequency group for a value k is the set of characters that appear exactly k times in s.

The majority frequency group is the frequency group that contains the largest number of distinct characters.

Return a string containing all characters in the majority frequency group, in any order. If two or more frequency groups tie for that largest size, pick the group whose frequency k is larger.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Counting
 */

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int> mpp;
        int maxf=0;
        for(auto it:s) {
            mpp[it]++;

        }
        map<int,int,greater<int>> grp;
        for(auto &[keu,v]:mpp){
           grp[v]++;
        }
        for(auto &[key,val]:grp){
            maxf=max(maxf,val);
        }
        // cout<<maxf<<endl;
        int ans=0;
        for(auto &[key,val]:grp){
            if(val==maxf){
                ans=key;
                break;
            }
        }
        string a;
        for(auto &[key,val]:mpp) {
            if(val==ans){
                a.push_back(key);
            }
        }
        return a;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
