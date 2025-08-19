/*
 * PROBLEM: Split a String Into the Max Number of Unique Substrings
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
 * * PROBLEM DESCRIPTION:
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Backtracking
 */

class Solution {
public:
    int fans=INT_MIN;
    void counttot(string s,int pos,int n,int cnt,set<string> unique){
        if(pos==n){
            fans=max(cnt,fans);
            return;
        }

        for(int i=pos;i<n;i++){
            string temp=s.substr(pos,i-pos+1);
            if(unique.find(temp)!= unique.end()) continue;
            unique.insert(temp);
            counttot(s,i+1,n,cnt+1,unique);
            unique.erase(temp); 

        }

     

    }


    int maxUniqueSplit(string s) {  
        set<string> unique;
        counttot(s,0,s.size(),0,unique);
        return fans; 
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
