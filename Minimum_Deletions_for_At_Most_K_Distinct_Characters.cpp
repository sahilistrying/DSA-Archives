/*
 * PROBLEM: Minimum Deletions for At Most K Distinct Characters
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting of lowercase English letters, and an integer k.

Your task is to delete some (possibly none) of the characters in the string so that the number of distinct characters in the resulting string is at most k.

Return the minimum number of deletions required to achieve this.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Greedy, Sorting, Counting
 */

class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int> cnt;
        int dis=0;
        for(char c:s){
            if(cnt[c]==0) dis++;
            cnt[c]++;
        }
        if(k>=dis) return 0;
        int n=dis-k;
        vector<int> freq;
        for(auto [key,value]:cnt){
            freq.push_back(value);
        }
        sort(freq.begin(),freq.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=freq[i];
        }
        return ans;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N)
