/*
 * PROBLEM: Find Valid Pair of Adjacent Digits in String
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/
 * * PROBLEM DESCRIPTION:
 * You are given a string s consisting only of digits. A valid pair is defined as two adjacent digits in s such that:

	The first digit is not equal to the second.
	Each digit in the pair appears in s exactly as many times as its numeric value.

Return the first valid pair found in the string s when traversing from left to right. If no valid pair exists, return an empty string.
 * * APPROACH:
 * Solved using Hash Table to optimize the approach.
 * Topics: Hash Table, String, Counting
 */

class Solution {
public:
    string findValidPair(string s) {
        map<char,int> hash;
        for(auto it:s){
            hash[it]++;
        }
        vector<int> tocheck;
        for(int i=0;i<s.size()-1;i++){
            int num1=s[i]-'0';
            int num2=s[i+1]-'0';
            if((num1==hash[s[i]] && num2==hash[s[i+1]]) && num1!=num2){
                string ans = string(1, s[i]) + string(1, s[i+1]);
                return ans;
            }
        }
        return "";
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
