/*
 * PROBLEM: Maximum Score After Binary Swaps
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/maximum-score-after-binary-swaps/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums of length n and a binary string s of the same length.

Initially, your score is 0. Each index i where s[i] = '1' contributes nums[i] to the score.

You may perform any number of operations (including zero). In one operation, you may choose an index i such that 0 <= i < n - 1, where s[i] = '0', and s[i + 1] = '1', and swap these two characters.

Return an integer denoting the maximum possible score you can achieve.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, String, Greedy, Heap (Priority Queue)
 */

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long scor=0;
        priority_queue<int>ppp;
        auto smtggg=nums;
        for(int i=0;i<nums.size();i++){
            ppp.push(nums[i]);
            if(s[i]=='1'){
                scor+=ppp.top();
                ppp.pop();
            }
        }
        return scor;
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(1)
