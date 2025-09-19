/*
 * PROBLEM: Rearrange Array Elements by Sign
 * PLATFORM: LeetCode
 * DIFFICULTY: Medium
 * LEETCODE URL: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * * PROBLEM DESCRIPTION:
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

	Every consecutive pair of integers have opposite signs.
	For all integers with the same sign, the order in which they were present in nums is preserved.
	The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
 * * APPROACH:
 * Solved using Array to optimize the approach.
 * Topics: Array, Two Pointers, Simulation
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int posi=0,negi=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)ans.push_back(pos[posi++]);
            else ans.push_back(neg[negi++]);
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
