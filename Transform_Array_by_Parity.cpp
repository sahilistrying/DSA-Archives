/*
 * PROBLEM: Transform Array by Parity
 * PLATFORM: LeetCode
 * DIFFICULTY: Easy
 * LEETCODE URL: https://leetcode.com/problems/transform-array-by-parity/
 * * PROBLEM DESCRIPTION:
 * You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

	Replace each even number with 0.
	Replace each odd numbers with 1.
	Sort the modified array in non-decreasing order.

Return the resulting array after performing these operations.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Sorting, Counting
 */

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int oc=0;
        vector <int> ans;
        for(auto it:nums){
            if(it%2==0) {
                ans.push_back(0);
            }
            else oc++;
        }
        while(oc--) ans.push_back(1);
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
