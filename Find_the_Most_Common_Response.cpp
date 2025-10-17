/*
 * PROBLEM: Find the Most Common Response
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/find-the-most-common-response/
 * * PROBLEM DESCRIPTION:
 * You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.

Return the most common response across all days after removing duplicate responses within each responses[i]. If there is a tie, return the lexicographically smallest response.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Hash Table, String, Counting
 */

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;
        for (auto& day : responses) {
            unordered_set<string> ur(day.begin(), day.end());
            for (auto& response : ur) {
                freq[response]++;
            }
        }

        string result;
        int maxFreq = 0;

        for (auto& [response, count] : freq) {
        if (count > maxFreq || (count == maxFreq && response < result)) {
            maxFreq = count;
            result = response;
        }
        }
        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N^2)
